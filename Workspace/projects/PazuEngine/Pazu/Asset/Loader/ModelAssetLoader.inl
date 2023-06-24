namespace Pazu
{
	template <typename T>
	std::shared_ptr<IAsset> ModelAssetLoader<T>::Load(const std::string &file, const AssetManager &assetMgr) const
	{
		const ResourceHandle rh(file);
		if (!rh.isValid())
			return Log::Get().Print<LogMode::Error, std::nullptr_t>("Model dosyasi " + file + " bulunamadi.");
		Reset();
		if (const auto model = LoadModel(rh, PathStep(file).Backward().GetSource(), assetMgr))
			return model;
		return Log::Get().Print<LogMode::Error, std::nullptr_t>("Model dosyasi " + file + " yuklenemedi.");
	}

	template <typename T>
	void ModelAssetLoader<T>::Reset() const
	{
		boneNames.clear();
	}

	template <typename T>
	std::shared_ptr<IAsset> ModelAssetLoader<T>::LoadModel(const ResourceHandle &resourceHandle, const std::string &basePath, const AssetManager &assetMgr) const
	{
		Assimp::Importer importer;
		constexpr auto flags =
				aiProcess_FindDegenerates | aiProcess_FindInvalidData | aiProcess_FlipUVs | aiProcess_FlipWindingOrder |
				aiProcess_JoinIdenticalVertices | aiProcess_FlipUVs | aiProcess_FlipWindingOrder | aiProcess_JoinIdenticalVertices |
				aiProcess_ImproveCacheLocality | aiProcess_OptimizeMeshes | aiProcess_Triangulate;
		const auto aiScene = importer.ReadFileFromMemory(resourceHandle.c_str(), resourceHandle.size(), flags);
		if (!aiScene || aiScene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !aiScene->mRootNode)
			return Log::Get().Print<LogMode::Error, std::nullptr_t>({"Model verisi alinamadi. Assimp hata mesaji: ", importer.GetErrorString()});
		std::vector<std::reference_wrapper<const aiNode>> nodes;
		FindNodes(*aiScene->mRootNode, nodes);
		if constexpr (!std::is_same_v<T, SurfaceAnimatedModel>)
			return std::make_shared<ModelAsset<T>>(LoadSurfaces(*aiScene, nodes, basePath, assetMgr));
		else
			return std::make_shared<ModelAsset<T>>(LoadSurfaces(*aiScene, nodes, basePath, assetMgr), LoadAnimator(*aiScene), LoadSkeleton(*aiScene, nodes));
	}

	template <typename T>
	void ModelAssetLoader<T>::FindNodes(const aiNode &node, std::vector<std::reference_wrapper<const aiNode>> &nodes) const
	{
		nodes.emplace_back(std::cref(node));
		for (std::size_t x = 0; x < node.mNumChildren; ++x)
			FindNodes(*node.mChildren[x], nodes);
	}

	template <typename T>
	std::vector<T> ModelAssetLoader<T>::LoadSurfaces(const aiScene &aiScene, const std::vector<std::reference_wrapper<const aiNode>> &nodes, const std::string &basePath, const AssetManager &assetMgr) const
	{
		std::vector<T> surfaces;
		for (const auto assimpNode : nodes)
		{
			const auto &node = assimpNode.get();
			for (unsigned int x = 0; x < node.mNumMeshes; ++x)
			{
				const auto &assimpMesh = *aiScene.mMeshes[node.mMeshes[x]];
				const auto &assimpMaterial = *aiScene.mMaterials[assimpMesh.mMaterialIndex];
				surfaces.emplace_back(LoadSurface(assimpMesh, assimpMaterial, basePath, assetMgr));
			}
		}
		surfaces.shrink_to_fit();
		if (surfaces.empty())
			Log::Get().Print<LogMode::Error>("Model veri icerigi bos.");
		return surfaces;
	}

	template <typename T>
	T ModelAssetLoader<T>::LoadSurface(const aiMesh &aiMesh, const aiMaterial &aiMaterial, const std::string &basePath, const AssetManager &assetMgr) const
	{
		using namespace Graphics;
		const auto vertexBuffer = std::make_shared<VertexBuffer<typename T::Vertex>>(BufferUsage::Static);
		const auto indexBuffer = std::make_shared<IndexBuffer<typename T::Index>>(BufferUsage::Static);
		for (const auto &vertex : LoadVertices(aiMesh))
			vertexBuffer->Add(vertex);
		for (const auto &index : LoadIndices(aiMesh))
			indexBuffer->Add(index);
		assetMgr.GetGraphicsDevice()->CreateBuffer(*vertexBuffer);
		assetMgr.GetGraphicsDevice()->CreateBuffer(*indexBuffer);
		return {vertexBuffer, indexBuffer, LoadMaterial(aiMaterial, basePath, assetMgr)};
	}

	template <typename T>
	std::shared_ptr<Material> ModelAssetLoader<T>::LoadMaterial(const aiMaterial &aiMaterial, const std::string &basePath, const AssetManager &assetMgr) const
	{
		int twoSided = 0;
		if (aiMaterial.Get(AI_MATKEY_TWOSIDED, twoSided) != AI_SUCCESS)
		{
			if (aiString matName; aiMaterial.Get(AI_MATKEY_NAME, matName) == AI_SUCCESS)
				twoSided = std::string(matName.C_Str()).find("TwoSided") != std::string::npos;
		}
		return std::make_shared<Material>(LoadShader(assetMgr), LoadTextures(aiMaterial, basePath, assetMgr), LoadColors(aiMaterial), twoSided);
	}

	template <typename T>
	std::unique_ptr<Shader> ModelAssetLoader<T>::LoadShader(const AssetManager &assetMgr) const
	{
		using namespace Graphics;
		std::shared_ptr<ShaderAsset> shaderAsset;
		VertexInputLayout vertexInputLayout;
		vertexInputLayout.Add(VertexInput::Position);
		vertexInputLayout.Add(VertexInput::Normal);
		vertexInputLayout.Add(VertexInput::Color);
		vertexInputLayout.Add(VertexInput::Texture);
		if constexpr (!std::is_same_v<T, SurfaceAnimatedModel>)
			shaderAsset = assetMgr.Load<ShaderAsset>("Shaders/Model/default.shader");
		else
		{
			vertexInputLayout.Add(VertexInput::BlendIndices);
			vertexInputLayout.Add(VertexInput::BlendWeights);
			shaderAsset = assetMgr.Load<ShaderAsset>("Shaders/Model/Animated/default.shader");
		}
		shaderAsset->vertexInputLayout = std::move(vertexInputLayout);
		auto shader = std::make_unique<Pazu::Shader>(shaderAsset);
		if (const auto vertexShader = shader->Get<VertexShader>())
			assetMgr.GetGraphicsDevice()->CreateInputLayout(*vertexShader, shaderAsset->vertexInputLayout);
		return shader;
	}

	template <typename T>
	std::array<std::unique_ptr<Texture>, 3> ModelAssetLoader<T>::LoadTextures(const aiMaterial &aiMaterial, const std::string &basePath, const AssetManager &assetMgr) const
	{
		std::array<std::unique_ptr<Texture>, 3> textures;
		aiString textureName;
		const int diffCount = aiMaterial.GetTextureCount(aiTextureType_DIFFUSE);
		const int specCount = aiMaterial.GetTextureCount(aiTextureType_SPECULAR);
		const int normCount = aiMaterial.GetTextureCount(aiTextureType_NORMALS);
		for (int x = 0; x < diffCount; ++x)
		{
			aiMaterial.GetTexture(aiTextureType_DIFFUSE, x, &textureName);
			if (const auto textureAsset = assetMgr.Load<TextureAsset>(basePath + textureName.C_Str()))
			{
				textures[0] = std::make_unique<Texture>(textureAsset);
				break;
			}
		}
		for (int x = 0; x < specCount; ++x)
		{
			aiMaterial.GetTexture(aiTextureType_SPECULAR, x, &textureName);
			if (const auto textureAsset = assetMgr.Load<TextureAsset>(basePath + textureName.C_Str()))
			{
				textures[1] = std::make_unique<Texture>(textureAsset);
				break;
			}
		}
		for (int x = 0; x < normCount; ++x)
		{
			aiMaterial.GetTexture(aiTextureType_NORMALS, x, &textureName);
			if (const auto textureAsset = assetMgr.Load<TextureAsset>(basePath + textureName.C_Str()))
			{
				textures[2] = std::make_unique<Texture>(textureAsset);
				break;
			}
		}
		return textures;
	}

	template <typename T>
	std::array<Color, 3> ModelAssetLoader<T>::LoadColors(const aiMaterial &aiMaterial) const
	{
		std::array<Color, 3> colors = {Material::DefaultDiffuseColor, Material::DefaultSpecularColor, Material::DefaultAmbientColor};
		const auto colorNames = {std::string("$clr.diffuse"), std::string("$clr.specular"), std::string("$clr.ambient")};
		for (auto [colorPos, colorNamePos] = std::make_pair(colors.begin(), colorNames.begin()); colorPos != colors.cend(); ++colorPos, ++colorNamePos)
		{
			if (aiColor4D col; aiMaterial.Get(colorNamePos->c_str(), 0, 0, col) == AI_SUCCESS)
				(*colorPos) = Color(&col[0]);
			else
				Log::Get().Print<LogMode::Error>("Material " + colorNamePos->substr(5) + " renk bilgisi alinamadi.");
		}
		return colors;
	}

	template <typename T>
	std::vector<typename T::Vertex> ModelAssetLoader<T>::LoadVertices(const aiMesh &aiMesh) const
	{
		std::vector<typename T::Vertex> vertices(aiMesh.mNumVertices);
		for (std::size_t x = 0; x < aiMesh.mNumVertices; ++x)
			vertices[x] = LoadVertex(x, aiMesh);
		if constexpr (std::is_same_v<T, SurfaceAnimatedModel>)
		{
			for (unsigned int x = 0; x < aiMesh.mNumBones; x++)
			{
				const auto aiBone = aiMesh.mBones[x];
				const auto boneId = ToBoneId(aiBone->mName.C_Str());
				for (unsigned int y = 0; y < aiBone->mNumWeights; ++y)
				{
					const auto &weight = aiBone->mWeights[y];
					for (unsigned int z = 0; z < 4; ++z)
					{
						auto &vertex = vertices[weight.mVertexId];
						if (vertex.weights[z] == 0.f)
						{
							vertex.indices[z] = boneId;
							vertex.weights[z] = weight.mWeight;
							break;
						}
					}
				}
			}
		}
		return vertices;
	}

	template <typename T>
	typename T::Vertex ModelAssetLoader<T>::LoadVertex(const std::size_t index, const aiMesh &aiMesh) const
	{
		typename T::Vertex vertex;
		vertex.position = ToVector3(aiMesh.mVertices[index]);
		vertex.normal = aiMesh.HasNormals() ? ToVector3(aiMesh.mNormals[index]) : Vector3::Zero;
		vertex.color = aiMesh.HasVertexColors(0) ? ToColor(aiMesh.mColors[0][index]) : Color::White;
		vertex.texture = aiMesh.HasTextureCoords(0) ? ToVector2(aiMesh.mTextureCoords[0][index]) : Vector2::Zero;
		return vertex;
	}

	template <typename T>
	std::vector<std::array<typename T::Index, 3>> ModelAssetLoader<T>::LoadIndices(const aiMesh &aiMesh) const
	{
		std::vector<std::array<typename T::Index, 3>> indices(aiMesh.mNumFaces);
		for (std::size_t x = 0; x < aiMesh.mNumFaces; ++x)
			indices[x] = LoadIndex(aiMesh.mFaces[x]);
		return indices;
	}

	template <typename T>
	std::array<typename T::Index, 3> ModelAssetLoader<T>::LoadIndex(const aiFace &aiFace) const
	{
		return aiFace.mNumIndices == 3
							 ? std::array<typename T::Index, 3>{aiFace.mIndices[0], aiFace.mIndices[1], aiFace.mIndices[2]}
							 : Log::Get().Print<LogMode::Error, std::array<typename T::Index, 3>>("Model yuzeyinde hatali sayida index bulundu.");
	}

	template <typename T>
	Skeleton ModelAssetLoader<T>::LoadSkeleton(const aiScene &aiScene, const std::vector<std::reference_wrapper<const aiNode>> &nodes) const
	{
		Skeleton skeleton;
		for (const auto assimpNode : nodes)
		{
			const auto &node = assimpNode.get();
			for (unsigned int x = 0; x < node.mNumMeshes; ++x)
				skeleton.AddBones(LoadBones(*aiScene.mMeshes[node.mMeshes[x]]));
			auto boneOptRef = skeleton.FindBone(node.mName.C_Str());
			if (!boneOptRef)
				continue;
			auto &bone = boneOptRef->get();
			bone.SetTransform(ToTransform(node.mTransformation));
			if (node.mParent)
			{
				if (const auto parentBone = skeleton.FindBone(node.mParent->mName.C_Str()))
					bone.GetTransform().SetParent(parentBone->get().GetTransform());
			}
		}
		return skeleton;
	}

	template <typename T>
	std::vector<Bone> ModelAssetLoader<T>::LoadBones(const aiMesh &aiMesh) const
	{
		std::vector<Bone> bones(aiMesh.mNumBones);
		for (unsigned int x = 0; x < aiMesh.mNumBones; x++)
		{
			const auto aiBone = aiMesh.mBones[x];
			bones[x] = {aiBone->mName.C_Str(), ToBoneId(aiBone->mName.C_Str()), ToMatrix(aiBone->mOffsetMatrix)};
		}
		return bones;
	}

	template <typename T>
	unsigned int ModelAssetLoader<T>::ToBoneId(const std::string &name) const
	{
		if (boneNames.find(name) == boneNames.cend())
			boneNames[name] = boneNames.size();
		return boneNames[name];
	}

	template <typename T>
	Animator ModelAssetLoader<T>::LoadAnimator(const aiScene &aiScene) const
	{
		return {LoadAnimations(aiScene)};
	}

	template <typename T>
	std::vector<Animation> ModelAssetLoader<T>::LoadAnimations(const aiScene &aiScene) const
	{
		std::vector<Animation> animations(aiScene.mNumAnimations);
		for (unsigned int x = 0; x < aiScene.mNumAnimations; x++)
			animations[x] = Animation("Animation_" + std::to_string(x), LoadPerBoneFrames(*aiScene.mAnimations[x]));
		return animations;
	}

	template <typename T>
	std::unordered_map<std::string, std::vector<BoneFrame>> ModelAssetLoader<T>::LoadPerBoneFrames(const aiAnimation &aiAnimation) const
	{
		std::unordered_map<std::string, std::vector<BoneFrame>> boneFrames;
		for (unsigned int x = 0; x < aiAnimation.mNumChannels; ++x)
		{
			const auto &aiNodeAnim = *aiAnimation.mChannels[x];
			boneFrames.emplace(aiNodeAnim.mNodeName.C_Str(), LoadBoneFrames(aiNodeAnim));
		}
		return boneFrames;
	}

	template <typename T>
	std::vector<BoneFrame> ModelAssetLoader<T>::LoadBoneFrames(const aiNodeAnim &aiNodeAnim) const
	{
		std::vector<BoneFrame> boneFrames(std::max({aiNodeAnim.mNumPositionKeys, aiNodeAnim.mNumRotationKeys, aiNodeAnim.mNumScalingKeys}));
		for (unsigned int x = 0; x < aiNodeAnim.mNumPositionKeys; ++x)
			boneFrames[x].position = ToVector3(aiNodeAnim.mPositionKeys[x].mValue);
		for (unsigned int x = 0; x < aiNodeAnim.mNumRotationKeys; ++x)
			boneFrames[x].rotation = ToQuaternion(aiNodeAnim.mRotationKeys[x].mValue);
		for (unsigned int x = 0; x < aiNodeAnim.mNumScalingKeys; ++x)
			boneFrames[x].scale = ToVector3(aiNodeAnim.mScalingKeys[x].mValue);
		return boneFrames;
	}

	template <typename T>
	Transform ModelAssetLoader<T>::ToTransform(const aiMatrix4x4 &aiMatrix) const
	{
		aiVector3D aiPosition;
		aiVector3D aiRotationAxis;
		ai_real aiRotationAngle;
		aiVector3D aiScale;
		aiMatrix.Decompose(aiScale, aiRotationAxis, aiRotationAngle, aiPosition);
		Transform transform;
		transform.SetPosition(ToVector3(aiPosition), true);
		transform.SetRotation(ToVector3(aiRotationAxis), Mathf::ToDegrees(aiRotationAngle), true);
		transform.SetScale(ToVector3(aiScale));
		return transform;
	}

	template <typename T>
	Matrix ModelAssetLoader<T>::ToMatrix(const aiMatrix4x4 &aiMatrix) const
	{
		return {aiMatrix.a1, aiMatrix.b1, aiMatrix.c1, aiMatrix.d1,
						aiMatrix.a2, aiMatrix.b2, aiMatrix.c2, aiMatrix.d2,
						aiMatrix.a3, aiMatrix.b3, aiMatrix.c3, aiMatrix.d3,
						aiMatrix.a4, aiMatrix.b4, aiMatrix.c4, aiMatrix.d4};
	}

	template <typename T>
	Quaternion ModelAssetLoader<T>::ToQuaternion(const aiQuaternion &aiQuaternion) const
	{
		return {aiQuaternion.x, aiQuaternion.y, aiQuaternion.z, aiQuaternion.w};
	}

	template <typename T>
	Vector3 ModelAssetLoader<T>::ToVector3(const aiVector3D &aiVector3) const
	{
		return {aiVector3.x, aiVector3.y, aiVector3.z};
	}

	template <typename T>
	Vector2 ModelAssetLoader<T>::ToVector2(const aiVector3D &aiVector3) const
	{
		return {aiVector3.x, aiVector3.y};
	}

	template <typename T>
	Color ModelAssetLoader<T>::ToColor(const aiColor4D &aiColor) const
	{
		return {aiColor.r, aiColor.g, aiColor.b, aiColor.a};
	}
} // namespace Pazu

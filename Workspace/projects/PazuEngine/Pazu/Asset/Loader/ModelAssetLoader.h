// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <cmath>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/mesh.h>
#include <ResourceManager/ResourceHandle.h>
#include "../../Math/Quaternion.h"
#include "../../Math/Color.h"
#include "../../Component/Model/Surface/Material.h"
#include "../../Component/Model/Surface/Shader.h"
#include "../../Component/Model/Surface/Texture.h"
#include "../../Graphics/Shader/VertexShader.h"
#include "../../Graphics/InputLayout/VertexInputLayout.h"
#include "../../Graphics/Buffer/VertexBuffer.h"
#include "../../Graphics/Buffer/IndexBuffer.h"
#include "../../Graphics/Device.h"
#include "../AssetManager.h"
#include "../TextureAsset.h"
#include "../ModelAsset.h"
#include "IAssetLoader.h"

namespace Pazu
{
	template <typename T>
	class ModelAssetLoader : public IAssetLoader
	{
	public:
		std::shared_ptr<IAsset> Load(const std::string &file, const AssetManager &assetMgr) const final;

	private:
		void Reset() const;
		std::shared_ptr<IAsset> LoadModel(const ResourceHandle &resourceHandle, const std::string &basePath, const AssetManager &assetMgr) const;
		void FindNodes(const aiNode &node, std::vector<std::reference_wrapper<const aiNode>> &nodes) const;
		std::vector<T> LoadSurfaces(const aiScene &aiScene, const std::vector<std::reference_wrapper<const aiNode>> &nodes, const std::string &basePath, const AssetManager &assetMgr) const;
		T LoadSurface(const aiMesh &aiMesh, const aiMaterial &aiMaterial, const std::string &basePath, const AssetManager &assetMgr) const;
		std::shared_ptr<Material> LoadMaterial(const aiMaterial &aiMaterial, const std::string &basePath, const AssetManager &assetMgr) const;
		std::unique_ptr<Shader> LoadShader(const AssetManager &assetMgr) const;
		std::array<std::unique_ptr<Texture>, 3> LoadTextures(const aiMaterial &aiMaterial, const std::string &basePath, const AssetManager &assetMgr) const;
		std::array<Color, 3> LoadColors(const aiMaterial &aiMaterial) const;
		std::vector<typename T::Vertex> LoadVertices(const aiMesh &aiMesh) const;
		typename T::Vertex LoadVertex(const std::size_t index, const aiMesh &aiMesh) const;
		std::vector<std::array<typename T::Index, 3>> LoadIndices(const aiMesh &aiMesh) const;
		std::array<typename T::Index, 3> LoadIndex(const aiFace &aiFace) const;
		Skeleton LoadSkeleton(const aiScene &aiScene, const std::vector<std::reference_wrapper<const aiNode>> &nodes) const;
		std::vector<Bone> LoadBones(const aiMesh &aiMesh) const;
		unsigned int ToBoneId(const std::string &name) const;
		Animator LoadAnimator(const aiScene &aiScene) const;
		std::vector<Animation> LoadAnimations(const aiScene &aiScene) const;
		std::unordered_map<std::string, std::vector<BoneFrame>> LoadPerBoneFrames(const aiAnimation &aiAnimation) const;
		std::vector<BoneFrame> LoadBoneFrames(const aiNodeAnim &aiNodeAnim) const;
		Transform ToTransform(const aiMatrix4x4 &aiMatrix) const;
		Matrix ToMatrix(const aiMatrix4x4 &aiMatrix) const;
		Quaternion ToQuaternion(const aiQuaternion &aiQuaternion) const;
		Vector3 ToVector3(const aiVector3D &aiVector3) const;
		Vector2 ToVector2(const aiVector3D &aiVector3) const;
		Color ToColor(const aiColor4D &aiColor) const;

		mutable std::unordered_map<std::string, unsigned int> boneNames;
	};
} // namespace Pazu
#include "ModelAssetLoader.inl"

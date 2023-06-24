namespace Pazu
{
	template <typename T>
	void RendererSystem::CreateModel(std::shared_ptr<T> &model) const
	{
		using namespace Graphics;
		for (const auto &surface : model->GetSurfaces())
		{
			const auto &shader = surface->GetMaterial()->GetShader();
			if (!shader->GetConstantBuffers().empty())
				continue;
			auto cboProj = std::make_unique<ConstantBuffer>(ShaderFlag::Vertex, 0, BufferUsage::Static);
			cboProj->Set(m_proj);
			auto cboView = std::make_unique<ConstantBuffer>(ShaderFlag::Vertex, 1, BufferUsage::Static);
			cboView->Set(m_view);
			auto cboWorld = std::make_unique<ConstantBuffer>(ShaderFlag::Vertex, 2, BufferUsage::Static);
			cboWorld->Set(m_world);
			shader->AddConstantBuffer(std::move(cboProj));
			shader->AddConstantBuffer(std::move(cboView));
			shader->AddConstantBuffer(std::move(cboWorld));
			if constexpr (std::is_same_v<T, AnimatedModelComponent>)
			{
				auto cboSkinned = std::make_unique<ConstantBuffer>(ShaderFlag::Vertex, 3, BufferUsage::Static);
				cboSkinned->Set(m_boneTransforms);
				shader->AddConstantBuffer(std::move(cboSkinned));
			}
			for (const auto &cb : shader->GetConstantBuffers())
				m_graphicsDevice->CreateBuffer(*cb);
		}
	}

	template <typename T>
	void RendererSystem::DrawModel(const std::shared_ptr<T> &model)
	{
		using namespace Graphics;
		// if constexpr (std::is_same_v<T, AnimatedModelComponent>)
		// {
		// const auto &animation = model->GetAnimator()->GetCurrent();
		// if (animation)
		// animation->Play(true);
		// for (auto &bone : model->GetSkeleton().GetBones())
		// {
		// auto &transform = bone.transform;
		// if (animation)
		// {
		// 	const auto frameIndex = animation->GetTestIndex();
		// 	const auto &frameList = animation->GetBoneFrameList(bone->name);
		// 	if (frameList)
		// 	{
		// 		// transform.SetPosition(frameList->positions[frameIndex], true);
		// 		transform.SetQuaternion(frameList->rotations[static_cast<std::size_t>(Mathf::Clamp(frameIndex, 0.f, static_cast<float>(frameList->rotations.size() - 1)))]);
		// 		// transform.SetScale(frameList->scalings[frameIndex]);
		// 	}
		// }
		// if (transform.GetDirty())
		// {
		// transform.CalculateWorld();
		// transform.SetDirty(false);
		// }
		// m_boneTransforms[bone.id] = bone.offset * transform.GetMatrix();
		// }
		// }
		for (const auto &surface : model->GetSurfaces())
		{
			const auto &material = surface->GetMaterial();
			const auto &shader = material->GetShader();
			m_graphicsContext->SetShader(*shader->Get<VertexShader>());
			m_graphicsContext->SetShader(*shader->Get<PixelShader>());
			m_graphicsContext->SetInputLayout(shader->GetVertexInputLayout());
			if constexpr (std::is_same_v<T, AnimatedModelComponent>)
				m_graphicsContext->UpdateBuffer(*shader->GetConstantBuffers()[3]);
			m_graphicsContext->UpdateBuffer(*shader->GetConstantBuffers()[2]);
			if (m_cameraSystem->GetViewDirty<3>())
			{
				m_cameraSystem->CalculateView<3>();
				m_view = m_cameraSystem->GetView<3>();
				m_graphicsContext->UpdateBuffer(*shader->GetConstantBuffers()[1]);
			}
			if (m_cameraSystem->GetProjectionDirty<3>())
			{
				m_cameraSystem->CalculateProjection<3>();
				m_proj = m_cameraSystem->GetProjection<3>();
				m_graphicsContext->UpdateBuffer(*shader->GetConstantBuffers()[0]);
			}
			for (const auto &cb : shader->GetConstantBuffers())
				m_graphicsContext->SetBuffer(*cb);

			m_graphicsContext->SetBuffer(surface->GetVertexBuffer());
			m_graphicsContext->SetBuffer(surface->GetIndexBuffer());
			m_graphicsContext->SetDrawMode(material->GetDrawMode());
			m_graphicsContext->SetCullFace(!material->GetTwoSided());
			m_graphicsContext->SetSamplerState(m_samplerState);

			if (const auto diffuseTexture = surface->GetMaterial()->GetDiffuseTexture())
				m_graphicsContext->SetTexture(diffuseTexture->get()->Get());
			if (const auto specularTexture = surface->GetMaterial()->GetSpecularTexture())
				m_graphicsContext->SetTexture(specularTexture->get()->Get());
			if (const auto normalTexture = surface->GetMaterial()->GetNormalTexture())
				m_graphicsContext->SetTexture(normalTexture->get()->Get());

			if (material->GetDiffuseColor().w >= 1.f)
				m_graphicsContext->SetBlendState(m_blendStates[0]);
			else
			{
				const auto alphaFactor = 1.f - material->GetDiffuseColor().w;
				m_blendStates[1].SetFactor({alphaFactor, alphaFactor, alphaFactor, 1.f});
				m_graphicsContext->SetBlendState(m_blendStates[1]);
			}

			m_graphicsContext->Draw(surface->GetIndexBuffer());
		}
	}
}

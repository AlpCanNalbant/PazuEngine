// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <atomic>
#include "../Math/Matrix.h"
#include "../Graphics/SamplerState/SamplerState.h"
#include "../Graphics/BlendState/BlendState.h"
#include "../Graphics/Buffer/ConstantBuffer.h"
#include "../Graphics/InputLayout/VertexInputLayout.h"
#include "../Graphics/Shader/VertexShader.h"
#include "../Graphics/Shader/PixelShader.h"
#include "../Component/Model/StaticModelComponent.h"
#include "../Component/Model/AnimatedModelComponent.h"
#include "../Component/Model/Surface/Material.h"
#include "../Component/Model/Surface/Texture.h"
#include "../Component/Model/Surface/Shader.h"
#include "ISystem.h"
#include "IDrawableSystem.h"

namespace Pazu
{
	namespace Graphics
	{
		class Device;
		class Context;
	}
	class CameraSystem;
	class RendererSystem : public ISystem, public IDrawableSystem
	{
	public:
		RendererSystem(const std::shared_ptr<CameraSystem> &cameraSystem, const std::shared_ptr<Graphics::Device> &graphicsDevice, const std::shared_ptr<Graphics::Context> &graphicsContext);
		void Register(const std::shared_ptr<Entity> &entity) final;
		void Unregister(const std::shared_ptr<Entity> &entity) final;
		void Draw() final;
		const Graphics::SamplerState &GetSamplerState() const;
		Graphics::SamplerState &GetSamplerState();
		void SetSamplerState(Graphics::SamplerState samplerState);

	private:
		template <typename T>
		void CreateModel(std::shared_ptr<T> &model) const;
		template <typename T>
		void DrawModel(const std::shared_ptr<T> &model);

		std::vector<std::tuple<std::shared_ptr<Entity>, std::shared_ptr<StaticModelComponent>, std::shared_ptr<AnimatedModelComponent>>> m_components;
		const std::shared_ptr<CameraSystem> m_cameraSystem;
		const std::shared_ptr<Graphics::Device> m_graphicsDevice;
		const std::shared_ptr<Graphics::Context> m_graphicsContext;
		Graphics::SamplerState m_samplerState;
		std::array<Graphics::BlendState, 2> m_blendStates;
		Matrix m_view, m_proj, m_world;
		std::array<Matrix, 96> m_boneTransforms;
	};
}
#include "RendererSystem.inl"

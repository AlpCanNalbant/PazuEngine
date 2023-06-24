#include "../Graphics/Device.h"
#include "../Graphics/Context.h"
#include "../Component/Model/Surface/Surface.h"
#include "../Component/Model/Surface/Material.h"
#include "../Graphics/Texture/Texture2D.h"
#include "../Entity.h"
#include "CameraSystem.h"
#include "RendererSystem.h"

namespace Pazu
{
	using namespace Graphics;

	RendererSystem::RendererSystem(const std::shared_ptr<CameraSystem> &cameraSystem, const std::shared_ptr<Device> &graphicsDevice, const std::shared_ptr<Context> &graphicsContext)
			: m_cameraSystem(cameraSystem), m_graphicsDevice(graphicsDevice), m_graphicsContext(graphicsContext), m_blendStates{BlendState(false, Color::Black), BlendState(true, Color::White)}
	{
		switch (Engine::GetGraphicsApi())
		{
		case Api::Direct3D11:
			m_samplerState = {TextureFilter::Anisotropic, TextureWrap::Clamp, true};
			break;
		case Api::OpenGL:
			m_samplerState = {TextureFilter::Linear, TextureWrap::Clamp, true};
			break;
		default:
			break;
		}
		m_graphicsDevice->CreateSamplerState(m_samplerState);
		for (auto &bs : m_blendStates)
			m_graphicsDevice->CreateBlendState(bs);
	}

	void RendererSystem::Register(const std::shared_ptr<Entity> &entity)
	{
		auto staticModel = entity->Get<StaticModelComponent>();
		auto animatedModel = entity->Get<AnimatedModelComponent>();
		if (!staticModel && !animatedModel)
			return Log::Get().Print<LogMode::Error>("RendererSystem icin entity kaydi yapilamadi. Component icerigi eksik.");
		if (std::find_if(m_components.cbegin(), m_components.cend(), [&entity](const auto &c)
										 { return std::get<0>(c) == entity; }) != m_components.cend())
			return Log::Get().Print<LogMode::Info>("RendererSystem icin entity kaydi yapilamadi. Zaten kayitli.");
		m_components.emplace_back(std::make_tuple(entity, staticModel, animatedModel));
		if (staticModel)
			CreateModel(staticModel);
		if (animatedModel)
			CreateModel(animatedModel);
	}

	void RendererSystem::Unregister(const std::shared_ptr<Entity> &entity)
	{
		if (const auto pos = std::find_if(m_components.cbegin(), m_components.cend(), [&entity](const auto &c)
																			{ return std::get<0>(c) == entity; });
				pos != m_components.cend())
			m_components.erase(pos);
		else
			Log::Get().Print<LogMode::Info>("RendererSystem icin entity kayit iptali yapilamadi. Kayitli degil.");
	}

	void RendererSystem::Draw()
	{
		for (const auto &[entity, staticModel, animatedModel] : m_components)
		{
			auto &transform = entity->GetTransform();
			if (transform.GetDirty())
			{
				transform.CalculateWorld();
				transform.SetDirty(false);
			}
			m_world = transform.GetMatrix();

			if (staticModel)
				DrawModel(staticModel);
			else
				DrawModel(animatedModel);
		}
		if (m_cameraSystem->GetViewDirty<3>())
			m_cameraSystem->SetViewDirty<3>(false);
		if (m_cameraSystem->GetProjectionDirty<3>())
			m_cameraSystem->SetProjectionDirty<3>(false);
	}

	const SamplerState &RendererSystem::GetSamplerState() const
	{
		return m_samplerState;
	}

	SamplerState &RendererSystem::GetSamplerState()
	{
		return m_samplerState;
	}

	void RendererSystem::SetSamplerState(SamplerState samplerState)
	{
		m_samplerState = std::move(samplerState);
	}
}

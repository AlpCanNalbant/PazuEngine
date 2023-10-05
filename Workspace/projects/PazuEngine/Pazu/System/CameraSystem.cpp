// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "../Entity.h"
#include "CameraSystem.h"

namespace Pazu
{
	void CameraSystem::Register(const std::shared_ptr<Entity> &entity)
	{
		const auto camera3d = entity->Get<Camera3DComponent>();
		const auto camera2d = entity->Get<Camera2DComponent>();
		if (!camera3d && !camera2d)
			return Log::Get().Print<LogMode::Error>("CameraSystem icin entity kaydi yapilamadi. Component icerigi eksik.");

		if (camera3d && std::get<0>(m_3dComponent) != entity)
			m_3dComponent = std::make_tuple(entity, camera3d);
		// else
		// Log::Get().Print<LogMode::Info>("CameraSystem icin Camera3DComponent kaydi yapilamadi. Zaten gecerli kayit.");

		if (camera2d && std::get<0>(m_2dComponent) != entity)
			m_2dComponent = std::make_tuple(entity, camera2d);
		// else
		// Log::Get().Print<LogMode::Info>("CameraSystem icin Camera2DComponent kaydi yapilamadi. Zaten gecerli kayit.");
	}

	void CameraSystem::Unregister(const std::shared_ptr<Entity> &entity)
	{
		const auto camera3d = entity->Get<Camera3DComponent>();
		const auto camera2d = entity->Get<Camera2DComponent>();
		if (!camera3d && !camera2d)
			return Log::Get().Print<LogMode::Error>("CameraSystem icin entity kayit iptali yapilamadi. Component icerigi eksik.");

		if (camera3d && std::get<0>(m_3dComponent) == entity)
			m_3dComponent = std::make_tuple(nullptr, nullptr);
		// else
		// Log::Get().Print<LogMode::Info>("CameraSystem icin Camera3DComponent kayit iptali yapilamadi. Gecerli kayit degil.");

		if (camera2d && std::get<0>(m_2dComponent) == entity)
			m_2dComponent = std::make_tuple(nullptr, nullptr);
		// else
		// Log::Get().Print<LogMode::Info>("CameraSystem icin Camera2DComponent kayit iptali yapilamadi. Gecerli kayit degil.");
	}

	void CameraSystem::Resize(const Size &size)
	{
		if (std::get<0>(m_3dComponent))
			std::get<1>(m_3dComponent)->SetViewSize(size);
		if (std::get<0>(m_2dComponent))
			std::get<1>(m_2dComponent)->SetViewSize(size);
	}
}

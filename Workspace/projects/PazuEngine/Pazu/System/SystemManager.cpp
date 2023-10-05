// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include <future>
#include "SystemManager.h"

namespace Pazu
{
	void SystemManager::Update() const
	{
		for (const auto &system : m_updatableSystems)
			system->Update();
	}

	void SystemManager::Draw() const
	{
		for (const auto &system : m_drawableSystems)
			system->Draw();
	}

	void SystemManager::Resize(const Size &size) const
	{
		for (const auto &system : m_resizableSystems)
			system->Resize(size);
	}
}

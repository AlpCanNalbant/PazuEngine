#pragma once
#include <thread>
#include "ISystem.h"
#include "IUpdatableSystem.h"
#include "IDrawableSystem.h"
#include "IResizableSystem.h"

namespace Pazu
{
	class Entity;
	class SystemManager : public INonCopyable
	{
	public:
		void Update() const;
		void Draw() const;
		template <typename T, typename... Args>
		void Add(Args &&...args);
		template <typename T>
		void Remove();
		template <typename T>
		void Register(const std::shared_ptr<Entity> &entity) const;
		template <typename T>
		void Unregister(const std::shared_ptr<Entity> &entity) const;
		void Resize(const Size &size) const;
		template <typename T>
		std::shared_ptr<T> Get() const;

	private:
		std::vector<std::shared_ptr<IUpdatableSystem>> m_updatableSystems;
		std::vector<std::shared_ptr<IDrawableSystem>> m_drawableSystems;
		std::vector<std::shared_ptr<IResizableSystem>> m_resizableSystems;
		std::unordered_map<std::type_index, std::shared_ptr<ISystem>> m_avaibleSystems;
	};
}
#include "SystemManager.inl"

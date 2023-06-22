#pragma once
#include "Math/Transform.h"
#include "Component/IComponent.h"

namespace Pazu
{
	class Entity
	{
	public:
		template <typename T, typename... Args>
		void Add(Args &&...args);
		template <typename T>
		void Remove();
		template <typename T>
		std::shared_ptr<T> Get() const;
		template <typename T>
		bool GetHas() const;
		const Transform &GetTransform() const;
		Transform &GetTransform();
		void SetTransform(const Transform &transform);

	private:
		Transform m_transform;
		std::unordered_map<std::type_index, std::shared_ptr<IComponent>> m_components;
	};
}
#include "Entity.inl"

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../Component/Transform/TransformComponent.h"
#include "../Component/Transform/TTransformHolder.h"
#include "../Entity.h"
#include "ISystem.h"

namespace Pazu
{
	class TransformSystem : public ISystem
	{
	public:
		void Register(const std::shared_ptr<Entity> &entity) noexcept final;
		void Unregister(const std::shared_ptr<Entity> &entity) noexcept final;
		template <typename T>
		void SetParent(const std::shared_ptr<Entity> &parent, const std::shared_ptr<Entity> &child) noexcept;
		template <typename T>
		const std::shared_ptr<T> &GetParent(const std::shared_ptr<Entity> &child) const noexcept;
		template <typename T>
		const std::vector<std::shared_ptr<T>> &GetChilds(const std::shared_ptr<Entity> &parent) const noexcept;
		// template <typename T>
		// bool GetHas(const std::shared_ptr<Entity> &entity) const noexcept;

	private:
		std::unordered_map<std::shared_ptr<Entity>, std::unique_ptr<TTransformPositionHolder>> m_posComponents;
		std::unordered_map<std::shared_ptr<Entity>, std::unique_ptr<TTransformRotationHolder>> m_rotComponents;
		std::unordered_map<std::shared_ptr<Entity>, std::unique_ptr<TTransformScaleHolder>> m_scaleComponents;
		std::unordered_map<std::shared_ptr<Entity>, std::unique_ptr<TTransformPositionRotationHolder>> m_posRotComponents;
		std::unordered_map<std::shared_ptr<Entity>, std::unique_ptr<TTransformPositionScaleHolder>> m_posScaleComponents;
		std::unordered_map<std::shared_ptr<Entity>, std::unique_ptr<TTransformPositionRotationScaleHolder>> m_posRotScaleComponents;
		std::unordered_map<std::shared_ptr<Entity>, std::unique_ptr<TTransformRotationScaleHolder>> m_rotScaleComponents;
	};
}
#include "TransformSystem.inl"

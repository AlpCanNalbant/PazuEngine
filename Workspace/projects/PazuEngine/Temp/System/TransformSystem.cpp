#include "TransformSystem.h"

namespace Pazu
{
	void TransformSystem::Register(const std::shared_ptr<Entity> &entity) noexcept
	{
		bool has = false, notContains = false;
		if (has = entity->GetHas<TransformPositionComponent>())
		{
			if (notContains = !m_posComponents.contains(entity))
				m_posComponents[entity] = std::make_unique<TTransformPositionHolder>(entity->Get<TransformPositionComponent>());
		}
		else if (has = entity->GetHas<TransformRotationComponent>())
		{
			if (notContains = !m_rotComponents.contains(entity))
				m_rotComponents[entity] = std::make_unique<TTransformRotationHolder>(entity->Get<TransformRotationComponent>());
		}
		else if (has = entity->GetHas<TransformScaleComponent>())
		{
			if (notContains = !m_scaleComponents.contains(entity))
				m_scaleComponents[entity] = std::make_unique<TTransformScaleHolder>(entity->Get<TransformScaleComponent>());
		}
		else if (has = entity->GetHas<TransformPositionRotationComponent>())
		{
			if (notContains = !m_posRotComponents.contains(entity))
				m_posRotComponents[entity] = std::make_unique<TTransformPositionRotationHolder>(entity->Get<TransformPositionRotationComponent>());
		}
		else if (has = entity->GetHas<TransformPositionScaleComponent>())
		{
			if (notContains = !m_posScaleComponents.contains(entity))
				m_posScaleComponents[entity] = std::make_unique<TTransformPositionScaleHolder>(entity->Get<TransformPositionScaleComponent>());
		}
		else if (has = entity->GetHas<TransformPositionRotationScaleComponent>())
		{
			if (notContains = !m_posRotScaleComponents.contains(entity))
				m_posRotScaleComponents[entity] = std::make_unique<TTransformPositionRotationScaleHolder>(entity->Get<TransformPositionRotationScaleComponent>());
		}
		else if (has = entity->GetHas<TransformRotationScaleComponent>())
		{
			if (notContains = !m_rotScaleComponents.contains(entity))
				m_rotScaleComponents[entity] = std::make_unique<TTransformRotationScaleHolder>(entity->Get<TransformRotationScaleComponent>());
		}
		if (!has)
			return TLog::Get().Print<LogMode::Error>("TransformSystem icin entity kaydi yapilamadi. Component icerigi eksik.");
		if (!notContains)
			return TLog::Get().Print<LogMode::Error>("TransformSystem icin entity kaydi yapilamadi. Zaten kayitli.");
	}

	void TransformSystem::Unregister(const std::shared_ptr<Entity> &entity) noexcept
	{
		bool contains = false;
		if (contains = m_posComponents.contains(entity))
			m_posComponents.erase(entity);
		else if (contains = m_rotComponents.contains(entity))
			m_rotComponents.erase(entity);
		else if (contains = m_scaleComponents.contains(entity))
			m_scaleComponents.erase(entity);
		else if (contains = m_posRotComponents.contains(entity))
			m_posRotComponents.erase(entity);
		else if (contains = m_posScaleComponents.contains(entity))
			m_posScaleComponents.erase(entity);
		else if (contains = m_posRotScaleComponents.contains(entity))
			m_posRotScaleComponents.erase(entity);
		else if (contains = m_rotScaleComponents.contains(entity))
			m_rotScaleComponents.erase(entity);
		if (!contains)
			return TLog::Get().Print<LogMode::Error>("TransformSystem icin entity kayit iptali yapilamadi. Kayitli degil.");
	}
}

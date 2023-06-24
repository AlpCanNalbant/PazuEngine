namespace Pazu
{
	template <typename T>
	void TransformSystem::SetParent(const std::shared_ptr<Entity> &parent, const std::shared_ptr<Entity> &child) noexcept
	{
		if constexpr (std::is_same_v<T, TransformPositionComponent>)
		{
			if (!m_posComponents.contains(parent) || !m_posComponents.contains(child))
				return TLog::Get().Print<LogMode::Error>("TransformSystem parent atanamadi. Entity kayitli degil.");
			m_posComponents[parent]->AddChild(child->Get<T>());
			m_posComponents[child]->SetParent(parent->Get<T>());
		}
		else if constexpr (std::is_same_v<T, TransformRotationComponent>)
		{
			if (!m_rotComponents.contains(parent) || !m_rotComponents.contains(child))
				return TLog::Get().Print<LogMode::Error>("TransformSystem parent atanamadi. Entity kayitli degil.");
			m_rotComponents[parent]->AddChild(child->Get<T>());
			m_rotComponents[child]->SetParent(parent->Get<T>());
		}
		else if constexpr (std::is_same_v<T, TransformScaleComponent>)
		{
			if (!m_scaleComponents.contains(parent) || !m_scaleComponents.contains(child))
				return TLog::Get().Print<LogMode::Error>("TransformSystem parent atanamadi. Entity kayitli degil.");
			m_scaleComponents[parent]->AddChild(child->Get<T>());
			m_scaleComponents[child]->SetParent(parent->Get<T>());
		}
		else if constexpr (std::is_same_v<T, TransformPositionRotationComponent>)
		{
			if (!m_posRotComponents.contains(parent) || !m_posRotComponents.contains(child))
				return TLog::Get().Print<LogMode::Error>("TransformSystem parent atanamadi. Entity kayitli degil.");
			m_posRotComponents[parent]->AddChild(child->Get<T>());
			m_posRotComponents[child]->SetParent(parent->Get<T>());
		}
		else if constexpr (std::is_same_v<T, TransformPositionScaleComponent>)
		{
			if (!m_posScaleComponents.contains(parent) || !m_posScaleComponents.contains(child))
				return TLog::Get().Print<LogMode::Error>("TransformSystem parent atanamadi. Entity kayitli degil.");
			m_posScaleComponents[parent]->AddChild(child->Get<T>());
			m_posScaleComponents[child]->SetParent(parent->Get<T>());
		}
		else if constexpr (std::is_same_v<T, TransformPositionRotationScaleComponent>)
		{
			if (!m_posRotScaleComponents.contains(parent) || !m_posRotScaleComponents.contains(child))
				return TLog::Get().Print<LogMode::Error>("TransformSystem parent atanamadi. Entity kayitli degil.");
			m_posRotScaleComponents[parent]->AddChild(child->Get<T>());
			m_posRotScaleComponents[child]->SetParent(parent->Get<T>());
		}
		else if constexpr (std::is_same_v<T, TransformRotationScaleComponent>)
		{
			if (!m_rotScaleComponents.contains(parent) || !m_rotScaleComponents.contains(child))
				return TLog::Get().Print<LogMode::Error>("TransformSystem parent atanamadi. Entity kayitli degil.");
			m_rotScaleComponents[parent]->AddChild(child->Get<T>());
			m_rotScaleComponents[child]->SetParent(parent->Get<T>());
		}
	}

	template <typename T>
	const std::shared_ptr<T> &TransformSystem::GetParent(const std::shared_ptr<Entity> &child) const noexcept
	{
		static const std::shared_ptr<T> errorResult = {}; // TODO: Belki bunlardan vazgecilebilir sonucta GetHas() var
		if constexpr (std::is_same_v<T, TransformPositionComponent>)
		{
			if (!m_posComponents.contains(child))
				return errorResult; //TLog::Get().Print<LogMode::Error>("TransformSystem parent alinamadi. Entity kayitli degil.", errorResult);
			return m_posComponents.at(child)->GetParent();
		}
		else if constexpr (std::is_same_v<T, TransformRotationComponent>)
		{
			if (!m_rotComponents.contains(child))
				return errorResult; //TLog::Get().Print<LogMode::Error>("TransformSystem parent alinamadi. Entity kayitli degil.", errorResult);
			return m_rotComponents.at(child)->GetParent();
		}
		else if constexpr (std::is_same_v<T, TransformScaleComponent>)
		{
			if (!m_scaleComponents.contains(child))
				return errorResult; //TLog::Get().Print<LogMode::Error>("TransformSystem parent alinamadi. Entity kayitli degil.", errorResult);
			return m_scaleComponents.at(child)->GetParent();
		}
		else if constexpr (std::is_same_v<T, TransformPositionRotationComponent>)
		{
			if (!m_posRotComponents.contains(child))
				return errorResult; //TLog::Get().Print<LogMode::Error>("TransformSystem parent alinamadi. Entity kayitli degil.", errorResult);
			return m_posRotComponents.at(child)->GetParent();
		}
		else if constexpr (std::is_same_v<T, TransformPositionScaleComponent>)
		{
			if (!m_posScaleComponents.contains(child))
				return errorResult; //TLog::Get().Print<LogMode::Error>("TransformSystem parent alinamadi. Entity kayitli degil.", errorResult);
			return m_posScaleComponents.at(child)->GetParent();
		}
		else if constexpr (std::is_same_v<T, TransformPositionRotationScaleComponent>)
		{
			if (!m_posRotScaleComponents.contains(child))
				return errorResult; //TLog::Get().Print<LogMode::Error>("TransformSystem parent alinamadi. Entity kayitli degil.", errorResult);
			return m_posRotScaleComponents.at(child)->GetParent();
		}
		else if constexpr (std::is_same_v<T, TransformRotationScaleComponent>)
		{
			if (!m_rotScaleComponents.contains(child))
				return errorResult; //TLog::Get().Print<LogMode::Error>("TransformSystem parent alinamadi. Entity kayitli degil.", errorResult);
			return m_rotScaleComponents.at(child)->GetParent();
		}
	}

	template <typename T>
	const std::vector<std::shared_ptr<T>> &TransformSystem::GetChilds(const std::shared_ptr<Entity> &parent) const noexcept
	{
		static const std::vector<std::shared_ptr<T>> errorResult = {}; // TODO: Belki bunlardan vazgecilebilir sonucta GetHas() var
		if constexpr (std::is_same_v<T, TransformPositionComponent>)
		{
			if (!m_posComponents.contains(parent))
				return errorResult; //TLog::Get().Print<LogMode::Error>("TransformSystem childs alinamadi. Entity kayitli degil.", errorResult);
			return m_posComponents.at(parent)->GetChilds();
		}
		else if constexpr (std::is_same_v<T, TransformRotationComponent>)
		{
			if (!m_rotComponents.contains(parent))
				return errorResult; //TLog::Get().Print<LogMode::Error>("TransformSystem childs alinamadi. Entity kayitli degil.", errorResult);
			return m_rotComponents.at(parent)->GetChilds();
		}
		else if constexpr (std::is_same_v<T, TransformScaleComponent>)
		{
			if (!m_scaleComponents.contains(parent))
				return errorResult; //TLog::Get().Print<LogMode::Error>("TransformSystem childs alinamadi. Entity kayitli degil.", errorResult);
			return m_scaleComponents.at(parent)->GetChilds();
		}
		else if constexpr (std::is_same_v<T, TransformPositionRotationComponent>)
		{
			if (!m_posRotComponents.contains(parent))
				return errorResult; //TLog::Get().Print<LogMode::Error>("TransformSystem childs alinamadi. Entity kayitli degil.", errorResult);
			return m_posRotComponents.at(parent)->GetChilds();
		}
		else if constexpr (std::is_same_v<T, TransformPositionScaleComponent>)
		{
			if (!m_posScaleComponents.contains(parent))
				return errorResult; //TLog::Get().Print<LogMode::Error>("TransformSystem childs alinamadi. Entity kayitli degil.", errorResult);
			return m_posScaleComponents.at(parent)->GetChilds();
		}
		else if constexpr (std::is_same_v<T, TransformPositionRotationScaleComponent>)
		{
			if (!m_posRotScaleComponents.contains(parent))
				return errorResult; //TLog::Get().Print<LogMode::Error>("TransformSystem childs alinamadi. Entity kayitli degil.", errorResult);
			return m_posRotScaleComponents.at(parent)->GetChilds();
		}
		else if constexpr (std::is_same_v<T, TransformRotationScaleComponent>)
		{
			if (!m_rotScaleComponents.contains(parent))
				return errorResult; //TLog::Get().Print<LogMode::Error>("TransformSystem childs alinamadi. Entity kayitli degil.", errorResult);
			return m_rotScaleComponents.at(parent)->GetChilds();
		}
	}

	// template <typename T>
	// bool TransformSystem::GetHas(const std::shared_ptr<Entity> &entity) const noexcept
	// {
	// 	if constexpr (std::is_same_v<T, TransformPositionComponent>)
	// 		return m_posComponents.contains(entity);
	// 	else if constexpr (std::is_same_v<T, TransformRotationComponent>)
	// 		return m_rotComponents.contains(entity);
	// 	else if constexpr (std::is_same_v<T, TransformScaleComponent>)
	// 		return m_scaleComponents.contains(entity);
	// 	else if constexpr (std::is_same_v<T, TransformPositionRotationComponent>)
	// 		return m_posRotComponents.contains(entity);
	// 	else if constexpr (std::is_same_v<T, TransformPositionScaleComponent>)
	// 		return m_posScaleComponents.contains(entity);
	// 	else if constexpr (std::is_same_v<T, TransformPositionRotationScaleComponent>)
	// 		return m_posRotScaleComponents.contains(entity);
	// 	else if constexpr (std::is_same_v<T, TransformRotationScaleComponent>)
	// 		return m_rotScaleComponents.contains(entity);
	// }
}

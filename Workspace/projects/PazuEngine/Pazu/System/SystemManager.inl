namespace Pazu
{
	template <typename T, typename... Args>
	void SystemManager::Add(Args &&...args)
	{
		if (const auto &typeInfo = typeid(T); !m_avaibleSystems.contains(typeInfo))
		{
			const auto system = std::make_shared<T>(std::forward<Args>(args)...);
			if constexpr (std::is_base_of_v<IUpdatableSystem, T>)
				m_updatableSystems.emplace_back(system);
			if constexpr (std::is_base_of_v<IDrawableSystem, T>)
				m_drawableSystems.emplace_back(system);
			if constexpr (std::is_base_of_v<IResizableSystem, T>)
				m_resizableSystems.emplace_back(system);
			m_avaibleSystems[typeInfo] = system;
		}
		else
			Log::Get().Print<LogMode::Error>("System eklenemedi. Zaten mevcut.");
	}

	template <typename T>
	void SystemManager::Remove()
	{
		if (const auto &typeInfo = typeid(T); m_avaibleSystems.contains(typeInfo))
		{
			const auto &system = std::static_pointer_cast<T>(m_avaibleSystems[typeInfo]);
			if constexpr (std::is_base_of_v<IUpdatableSystem, T>)
				m_updatableSystems.erase(std::find(m_updatableSystems.cbegin(), m_updatableSystems.cend(), system));
			if constexpr (std::is_base_of_v<IDrawableSystem, T>)
				m_drawableSystems.erase(std::find(m_drawableSystems.cbegin(), m_drawableSystems.cend(), system));
			if constexpr (std::is_base_of_v<IResizableSystem, T>)
				m_resizableSystems.erase(std::find(m_resizableSystems.cbegin(), m_resizableSystems.cend(), system));
			m_avaibleSystems.erase(typeInfo);
		}
		else
			Log::Get().Print<LogMode::Error>("System silinemedi. Mevcut degil.");
	}

	template <typename T>
	void SystemManager::Register(const std::shared_ptr<Entity> &entity) const
	{
		if (m_avaibleSystems.contains(typeid(T)))
			m_avaibleSystems.at(typeid(T))->Register(entity);
		else
			Log::Get().Print<LogMode::Error>("System icin Entity kaydi yapilamadi. System kayitli degil.");
	}

	template <typename T>
	void SystemManager::Unregister(const std::shared_ptr<Entity> &entity) const
	{
		if (m_avaibleSystems.contains(typeid(T)))
			m_avaibleSystems.at(typeid(T))->Unregister(entity);
		else
			Log::Get().Print<LogMode::Error>("System icin Entity kayit iptali yapilamadi. System kayitli degil.");
	}

	template <typename T>
	std::shared_ptr<T> SystemManager::Get() const
	{
		if (const auto pos = m_avaibleSystems.find(typeid(T)); pos != m_avaibleSystems.cend())
			return std::static_pointer_cast<T>(pos->second);
		return nullptr;
	}
}

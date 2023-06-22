namespace Pazu
{
	template <typename T, typename... Args>
	void Entity::Add(Args &&...args)
	{
		m_components[typeid(T)] = std::make_shared<T>(std::forward<Args>(args)...);
	}

	template <typename T>
	void Entity::Remove()
	{
		if (!m_components.erase(typeid(T)))
			Log::Get().Print<LogMode::Error>("Entity component silinemedi. Sahip degil.");
	}

	template <typename T>
	std::shared_ptr<T> Entity::Get() const
	{
		if (const auto pos = m_components.find(typeid(T)); pos != m_components.cend())
		{
			if constexpr (!std::is_same_v<T, IComponent>)
			{
				if constexpr (StaticCastable<IComponent *, T *>)
					return std::static_pointer_cast<T>(pos->second);
				else
					return std::dynamic_pointer_cast<T>(pos->second);
			}
			else
				return pos->second;
		}
		return nullptr;
	}

	template <typename T>
	bool Entity::GetHas() const
	{
		return m_components.contains(typeid(T));
	}
}

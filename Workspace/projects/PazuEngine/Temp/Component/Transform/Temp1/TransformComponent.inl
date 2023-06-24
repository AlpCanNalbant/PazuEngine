namespace Pazu
{
	template <typename T>
	T *TransformComponent::GetParent() const noexcept
	{
		if (m_parent)
		{
			if constexpr (!std::is_same_v<T, TransformComponent>)
				return dynamic_cast<T *>(m_parent);
			else
				return m_parent;
		}
		else
			return nullptr;
	}
}

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	TransformHolder<T>::TransformHolder(const std::shared_ptr<T> &transform) noexcept
		: m_transform(transform) {}

	template <typename T>
	void TransformHolder<T>::AddChild(const std::shared_ptr<T> &child) noexcept
	{
		if (std::find(m_childs.cbegin(), m_childs.cend(), child) == m_childs.cend())
			m_childs.emplace_back(child);
		else
			TLog::Get().Print<LogMode::Error>("Transform child sahiplenemedi. Zaten sahip.");
	}

	template <typename T>
	void TransformHolder<T>::AddChilds(const std::vector<std::shared_ptr<T>> &childs) noexcept
	{
		for (const auto &child : childs)
			AddChild(child);
	}

	template <typename T>
	void TransformHolder<T>::RemoveChild(const std::shared_ptr<T> &transform) noexcept
	{
		if (const auto pos = std::find(m_childs.cbegin(), m_childs.cend(), transform); pos != m_childs.cend())
			m_childs.erase(pos);
		else
			TLog::Get().Print<LogMode::Error>("Transform child silinemedi. Sahip degil.");
	}

	template <typename T>
	const std::shared_ptr<T> &TransformHolder<T>::Get() const noexcept
	{
		return m_transform;
	}

	template <typename T>
	const std::vector<std::shared_ptr<T>> &TransformHolder<T>::GetChilds() const noexcept
	{
		return m_childs;
	}

	template <typename T>
	const std::shared_ptr<T> &TransformHolder<T>::GetParent() const noexcept
	{
		return m_parent;
	}

	template <typename T>
	void TransformHolder<T>::SetParent(const std::shared_ptr<T> &parent) noexcept
	{
		m_parent = parent;
	}
}

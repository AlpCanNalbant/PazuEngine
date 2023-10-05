// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

namespace Pazu
{
	template <typename T>
	Hierarchy<T>::Hierarchy(T *owner, Transform *transform) noexcept
		: m_owner(owner), m_transform(transform) {}

	template <typename T>
	Hierarchy<T>::~Hierarchy() noexcept
	{
		if (m_parent)
			m_parent->GetHierarchy().RemoveChild(*m_owner);
		RemoveChildren();
	}

	template <typename T>
	void Hierarchy<T>::RemoveParent(T &parent) noexcept
	{
		if (m_parent == &parent)
		{
			m_parent = nullptr;
			if (m_transform)
				m_transform->m_parent = nullptr;
		}
		else
			Log::Get().Print<LogMode::Error>("Parent silinemedi. Gecerli degil.");
	}

	template <typename T>
	void Hierarchy<T>::AddChild(T &child) noexcept
	{
		if (std::find(m_children.cbegin(), m_children.cend(), &child) == m_children.cend())
		{
			child.GetHierarchy().SetParent(*m_owner);
			m_children.emplace_back(&child);
		}
		else
			Log::Get().Print<LogMode::Error>("Child eklenemedi. Zaten mevcut.");
	}

	template <typename T>
	void Hierarchy<T>::RemoveChild(T &child) noexcept
	{
		if (const auto pos = std::find(m_children.cbegin(), m_children.cend(), &child); pos != m_children.cend())
		{
			child.GetHierarchy().RemoveParent(*m_owner);
			m_children.erase(pos);
		}
		else
			Log::Get().Print<LogMode::Error>("Child silinemedi. Mevcut degil.");
	}

	template <typename T>
	void Hierarchy<T>::RemoveChildren() noexcept
	{
		for (const auto child : m_children)
			child->GetHierarchy().RemoveParent(*m_owner);
		m_children.clear();
	}

	template <typename T>
	T *Hierarchy<T>::GetParent() const noexcept
	{
		return m_parent;
	}

	template <typename T>
	const std::vector<T *> &Hierarchy<T>::GetChildren() const noexcept
	{
		return m_children;
	}

	template <typename T>
	T *Hierarchy<T>::GetOwner() const noexcept
	{
		return m_owner;
	}

	template <typename T>
	void Hierarchy<T>::SetParent(T &parent) noexcept
	{
		if (m_parent)
			m_parent->GetHierarchy().RemoveChild(*m_owner);
		parent.GetHierarchy().AddChild(*m_owner);
		m_parent = &parent;
		if (m_transform)
			m_transform->m_parent = parent->GetHierarchy().m_transform;
	}

	template <typename T>
	void Hierarchy<T>::SetTransform(Transform &transform) noexcept
	{
		m_transform = &transform;
	}
}

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "../Math/Transform/Transform.h"

namespace Pazu
{
	template <typename T>
	class Hierarchy
	{
	public:
		Hierarchy(T *owner, Transform *transform = nullptr) noexcept;
		virtual ~Hierarchy() noexcept;
		Hierarchy(const Hierarchy &other) = delete;
		Hierarchy(Hierarchy &&other) = delete;
		Hierarchy &operator=(const Hierarchy &other) = delete;
		Hierarchy &operator=(Hierarchy &&other) = delete;
		void RemoveParent(T &parent) noexcept;
		void AddChild(T &child) noexcept;
		void RemoveChild(T &child) noexcept;
		void RemoveChildren() noexcept;
		T *GetParent() const noexcept;
		const std::vector<T *> &GetChildren() const noexcept;
		T *GetOwner() const noexcept;
		void SetParent(T &parent) noexcept;
		void SetTransform(Transform &transform) noexcept;

	protected:
		std::vector<T *> m_children;
		T *m_parent{nullptr};

	private:
		T *m_owner;
		Transform *m_transform{nullptr};
	};
}
#include "Hierarchy.inl"

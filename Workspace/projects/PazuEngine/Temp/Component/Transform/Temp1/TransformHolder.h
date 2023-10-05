// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu
{
	template <typename T>
	class TransformHolder
	{
	public:
		TransformHolder(const std::shared_ptr<T> &transform) noexcept;
		void AddChild(const std::shared_ptr<T> &child) noexcept;
		void AddChilds(const std::vector<std::shared_ptr<T>> &childs) noexcept;
		void RemoveChild(const std::shared_ptr<T> &transform) noexcept;
		const std::shared_ptr<T> &Get() const noexcept;
		const std::vector<std::shared_ptr<T>> &GetChilds() const noexcept;
		const std::shared_ptr<T> &GetParent() const noexcept;
		void SetParent(const std::shared_ptr<T> &parent) noexcept;
		void SetChilds(const std::vector<std::shared_ptr<T>> &childs) noexcept;

	private:
		std::shared_ptr<T> m_transform;
		std::shared_ptr<T> m_parent;
		std::vector<std::shared_ptr<T>> m_childs;
	};
}
#include "TransformHolder.inl"

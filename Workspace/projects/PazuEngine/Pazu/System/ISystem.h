// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once

namespace Pazu
{
	class Entity;
	class ISystem
	{
	public:
		virtual ~ISystem() = default;
		virtual void Register(const std::shared_ptr<Entity> &entity) = 0;
		virtual void Unregister(const std::shared_ptr<Entity> &entity) = 0;
	};
}

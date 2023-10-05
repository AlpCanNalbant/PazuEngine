// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "InitFlag.h"
#include "DeviceConfig.h"

namespace Pazu::Sdl
{
	class Device
	{
	public:
		Device(const InitFlag flags, const DeviceConfig &config);
		Device(const Device &other) = delete;
		Device(Device &&other) = delete;
		~Device();
		Device &operator=(const Device &other) = delete;
		Device &operator=(Device &&other) = delete;
		InfoTitleVersion GetInfo() const;

		DeviceConfig config;
	};
} // namespace Pazu

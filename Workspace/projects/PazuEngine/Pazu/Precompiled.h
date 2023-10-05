// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <memory>
#include <vector>
#include <typeindex>
#include <unordered_map>
#include <SDL2/SDL.h>
#include <magic_enum/magic_enum.hpp>
#include "Tools/INons/INonCopyable.h"
#include "Tools/INons/INonMovable.h"
#include "Tools/INons/INonCreatable.h"
#if defined(_WIN32)
#include <winsdkver.h>
#define _WIN32_WINNT 0x0A00
#include <sdkddkver.h>
#define NOMINMAX
#define NODRAWTEXT
#define NOGDI
#define NOBITMAP
#define NOMCX
#define NOSERVICE
#define NOHELP
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
// #include <DirectXHelper/d3dx12.h>
#include <d3d11_1.h>
#include <dxgi1_5.h>
// #include <dxgi1_6.h>
#include <comdef.h>
#include "Tools/UniqueComPtr.h"
#endif
#include "File.h"
#include "Log.h"
#include "Tools/PathStep.h"
#include "Tools/InfoTitleVersion.h"
#include "Tools/ToInitializerList.h"
#include "Engine.h"
#include "Math/Mathf.h"
#include "Math/Point.h"
#include "Math/Size.h"
#include "Globals/Concepts.h"
using namespace magic_enum::flags::bitwise_operators;

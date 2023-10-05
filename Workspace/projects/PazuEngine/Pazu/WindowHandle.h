// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include <SDL2/SDL_syswm.h>
#include "WindowFlag.h"

namespace Pazu
{
	namespace Graphics
	{
		class IContextHandle;
	}
	class WindowHandle
	{
	public:
		WindowHandle();
		WindowHandle(const std::string &title, const Point &position, const Size &size, const WindowFlag flags);
		void CenterToScreen() const;
		void Minimize() const;
		void Maximize() const;
		void Restore() const;
		void Focus() const;
		void Hide() const;
		void Show() const;
		const std::unique_ptr<SDL_Window, void (*)(SDL_Window *)> &Get() const;
		unsigned int GetId() const;
		const auto &GetInfo() const;
		std::string GetTitle() const;
		Point GetPosition() const;
		Size GetSize() const;
		Size GetMinimumSize() const;
		Size GetMaximumSize() const;
		bool GetFullscreen() const;
		bool GetFullscreenWindowed() const;
		bool GetResizable() const;
		bool GetBorderless() const;
		WindowFlag GetFlags() const;
		void SetTitle(const std::string &title) const;
		void SetPosition(const Point &position) const;
		void SetSize(const Size &size) const;
		void SetMinimumSize(const Size &minSize) const;
		void SetMaximumSize(const Size &maxSize) const;
		void SetFullscreen(const bool fullscreen) const;
		void SetFullscreenWindowed(const bool fullscreenWindowed) const;
		void SetResizable(const bool resizable) const;
		void SetBorderless(const bool bordered) const;
		void SetGraphicsContext(const std::weak_ptr<Graphics::IContextHandle> &graphicsContext);

	private:
		void SetFullscreenFlag(const unsigned int flag) const;

		std::unique_ptr<SDL_Window, void (*)(SDL_Window *)> m_window{nullptr, nullptr};
		std::weak_ptr<Graphics::IContextHandle> m_graphicsContext;
		unsigned int m_id;
		SDL_SysWMinfo m_wmInfo;
	};
} // namespace Pazu
#include "WindowHandle.inl"

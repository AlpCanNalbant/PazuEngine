// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#pragma once
#include "WindowFlag.h"

namespace Pazu
{
	class WindowHandle;
	class Window
	{
	public:
		Window();
		Window(const std::string &title, const Point &position = DefaultPosition, const Size &size = DefaultSize, const WindowFlag flags = DefaultFlags);
		void CenterToScreen() const;
		void Minimize() const;
		void Maximize() const;
		void Restore() const;
		void Focus() const;
		void Hide() const;
		void Show() const;
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
		const std::shared_ptr<WindowHandle> &GetHandle() const;
		void SetTitle(const std::string &title) const;
		void SetPosition(const Point &position) const;
		void SetSize(const Size &size) const;
		void SetMinimumSize(const Size &minSize) const;
		void SetMaximumSize(const Size &maxSize) const;
		void SetFullscreen(const bool fullscreen) const;
		void SetFullscreenWindowed(const bool fullscreenWindowed) const;
		void SetResizable(const bool resizable) const;
		void SetBorderless(const bool bordered) const;

		static constexpr char DefaultTitle[] = "Window Title";
		static constexpr Point DefaultPosition = Point(SDL_WINDOWPOS_UNDEFINED);
		static constexpr Size DefaultSize = Size(800, 600);
		static constexpr WindowFlag DefaultFlags = WindowFlag::Shown;

	private:
		std::shared_ptr<WindowHandle> m_handle;
	};
} // namespace Pazu

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "Graphics/IContextHandle.h"
#include "Window.h"
#include "WindowHandle.h"
using namespace magic_enum::flags;

namespace Pazu
{
	WindowHandle::WindowHandle()
		: WindowHandle(Window::DefaultTitle, Window::DefaultPosition, Window::DefaultSize, Window::DefaultFlags) {}

	WindowHandle::WindowHandle(const std::string &title, const Point &position, const Size &size, const WindowFlag flags)
	{
		auto sdlFlags = enum_integer(flags);
		if (Engine::GetGraphicsApi() == Graphics::Api::OpenGL)
			sdlFlags |= SDL_WINDOW_OPENGL;
		if (auto rawSdlWindow = SDL_CreateWindow(title.c_str(), position.x, position.y, size.x, size.y, sdlFlags))
		{
			m_window = {rawSdlWindow, SDL_DestroyWindow};
			m_id = SDL_GetWindowID(rawSdlWindow);
			SDL_VERSION(&m_wmInfo.version);
			SDL_GetWindowWMInfo(rawSdlWindow, &m_wmInfo);
		}
		else
			Log::Get().Print<LogMode::Error>({"Pencere olusturulamadi. SDL hata mesaji: ", SDL_GetError()});
	}

	void WindowHandle::Minimize() const
	{
		SDL_MinimizeWindow(m_window.get());
	}

	void WindowHandle::Maximize() const
	{
		SDL_MaximizeWindow(m_window.get());
	}

	void WindowHandle::Restore() const
	{
		SDL_RestoreWindow(m_window.get());
	}

	void WindowHandle::Focus() const
	{
		SDL_RaiseWindow(m_window.get());
	}

	void WindowHandle::Hide() const
	{
		SDL_HideWindow(m_window.get());
	}

	void WindowHandle::Show() const
	{
		SDL_ShowWindow(m_window.get());
	}

	const std::unique_ptr<SDL_Window, void (*)(SDL_Window *)> &WindowHandle::Get() const
	{
		return m_window;
	}

	unsigned int WindowHandle::GetId() const
	{
		return m_id;
	}

	void WindowHandle::CenterToScreen() const
	{
		SDL_SetWindowPosition(m_window.get(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	}

	std::string WindowHandle::GetTitle() const
	{
		return SDL_GetWindowTitle(m_window.get());
	}

	Point WindowHandle::GetPosition() const
	{
		Point result;
		SDL_GetWindowPosition(m_window.get(), &result.x, &result.y);
		return result;
	}

	Size WindowHandle::GetSize() const
	{
		if (!GetFullscreen() && !GetFullscreenWindowed())
		{
			int w, h;
			SDL_GetWindowSize(m_window.get(), &w, &h);
			return {static_cast<unsigned int>(w), static_cast<unsigned int>(h)};
		}
		else
		{
			SDL_DisplayMode displayMode;
			SDL_GetWindowDisplayMode(m_window.get(), &displayMode);
			return {static_cast<unsigned int>(displayMode.w), static_cast<unsigned int>(displayMode.h)};
		}
	}

	Size WindowHandle::GetMinimumSize() const
	{
		int w, h;
		SDL_GetWindowMinimumSize(m_window.get(), &w, &h);
		return {static_cast<unsigned int>(w), static_cast<unsigned int>(h)};
	}

	Size WindowHandle::GetMaximumSize() const
	{
		int w, h;
		SDL_GetWindowMaximumSize(m_window.get(), &w, &h);
		return {static_cast<unsigned int>(w), static_cast<unsigned int>(h)};
	}

	bool WindowHandle::GetFullscreen() const
	{
		return static_cast<bool>(enum_integer(GetFlags()) & SDL_WINDOW_FULLSCREEN);
	}

	bool WindowHandle::GetFullscreenWindowed() const
	{
		return static_cast<bool>(enum_integer(GetFlags()) & SDL_WINDOW_FULLSCREEN_DESKTOP);
	}

	bool WindowHandle::GetResizable() const
	{
		return static_cast<bool>(enum_integer(GetFlags()) & SDL_WINDOW_RESIZABLE);
	}

	bool WindowHandle::GetBorderless() const
	{
		return static_cast<bool>(enum_integer(GetFlags()) & SDL_WINDOW_BORDERLESS);
	}

	WindowFlag WindowHandle::GetFlags() const
	{
		return enum_cast<WindowFlag>(
				   SDL_GetWindowFlags(m_window.get()) &
				   (SDL_WINDOW_SHOWN | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIDDEN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_RESIZABLE |
					SDL_WINDOW_MINIMIZED | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_FULLSCREEN))
			.value_or(WindowFlag::FullscreenBorderless);
	}

	void WindowHandle::SetTitle(const std::string &title) const
	{
		SDL_SetWindowTitle(m_window.get(), title.c_str());
	}

	void WindowHandle::SetPosition(const Point &position) const
	{
		SDL_SetWindowPosition(m_window.get(), position.x, position.y);
	}

	void WindowHandle::SetSize(const Size &size) const
	{
		if (!GetFullscreen() && !GetFullscreenWindowed())
		{
			SDL_SetWindowSize(m_window.get(), size.x, size.y);
			if (const auto context = m_graphicsContext.lock();
				context && Engine::GetGraphicsApi() == Graphics::Api::Direct3D11)
				context->Resize(size);
		}
		else
		{
			SDL_DisplayMode displayMode;
			SDL_GetWindowDisplayMode(m_window.get(), &displayMode);
			displayMode.w = static_cast<int>(size.Width());
			displayMode.h = static_cast<int>(size.Height());
			SDL_SetWindowDisplayMode(m_window.get(), &displayMode);
			if (Engine::GetGraphicsApi() == Graphics::Api::Direct3D11)
				SetFullscreen(true);
		}
	}

	void WindowHandle::SetMinimumSize(const Size &minSize) const
	{
		SDL_SetWindowMinimumSize(m_window.get(), minSize.x, minSize.y);
	}

	void WindowHandle::SetMaximumSize(const Size &maxSize) const
	{
		SDL_SetWindowMaximumSize(m_window.get(), maxSize.x, maxSize.y);
	}

	void WindowHandle::SetFullscreen(const bool fullscreen) const
	{
		if (fullscreen)
			Maximize();
		SetFullscreenFlag(fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
		if (!fullscreen)
		{
			Restore();
			SetSize(Window::DefaultSize);
			CenterToScreen();
		}
		if (const auto context = m_graphicsContext.lock();
			context && Engine::GetGraphicsApi() == Graphics::Api::Direct3D11)
		{
			const auto size = GetSize();
			context->Resize(size);
			context->SetFullscreen(fullscreen);
			context->Resize(size);
		}
	}

	void WindowHandle::SetFullscreenWindowed(const bool fullscreenWindowed) const
	{
		SetFullscreenFlag(fullscreenWindowed ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
	}

	void WindowHandle::SetResizable(const bool resizable) const
	{
		SDL_SetWindowResizable(m_window.get(), static_cast<SDL_bool>(resizable));
	}

	void WindowHandle::SetBorderless(const bool borderless) const
	{
		SDL_SetWindowBordered(m_window.get(), static_cast<SDL_bool>(!borderless));
	}

	void WindowHandle::SetGraphicsContext(const std::weak_ptr<Graphics::IContextHandle> &graphicsContext)
	{
		m_graphicsContext = graphicsContext;
	}

	void WindowHandle::SetFullscreenFlag(const unsigned int flag) const
	{
		if (SDL_SetWindowFullscreen(m_window.get(), flag) != 0)
			Log::Get().Print<LogMode::Error>({"Window Fullscreen durumu ayarlanamadi. SDL hata mesaji: ", SDL_GetError()});
	}
} // namespace Pazu

// Copyright (c) Alp Can Nalbant. Licensed under the MIT License.

#include "Display.h"
#include "Graphics/Context.h"
#include "Graphics/IContextHandle.h"
#include "WindowHandle.h"
#include "Window.h"
using namespace magic_enum::flags;

namespace Pazu
{
	Window::Window()
		: m_handle(std::make_shared<WindowHandle>(DefaultTitle, DefaultPosition, DefaultSize, DefaultFlags)) {}

	Window::Window(const std::string &title, const Point &position, const Size &size, const WindowFlag flags)
		: m_handle(std::make_shared<WindowHandle>(title, position, size, flags))
	{
		SetSize(size);
		SetMinimumSize({512, 256});
	}

	void Window::CenterToScreen() const
	{
		m_handle->CenterToScreen();
	}

	void Window::Minimize() const
	{
		m_handle->Minimize();
	}

	void Window::Maximize() const
	{
		m_handle->Maximize();
	}

	void Window::Restore() const
	{
		m_handle->Restore();
	}

	void Window::Focus() const
	{
		m_handle->Focus();
	}

	void Window::Hide() const
	{
		m_handle->Hide();
	}

	void Window::Show() const
	{
		m_handle->Show();
	}

	std::string Window::GetTitle() const
	{
		return m_handle->GetTitle();
	}

	Point Window::GetPosition() const
	{
		return m_handle->GetPosition();
	}

	Size Window::GetSize() const
	{
		return m_handle->GetSize();
	}

	Size Window::GetMinimumSize() const
	{
		return m_handle->GetMinimumSize();
	}

	Size Window::GetMaximumSize() const
	{
		return m_handle->GetMaximumSize();
	}

	bool Window::GetFullscreen() const
	{
		return m_handle->GetFullscreen();
	}

	bool Window::GetFullscreenWindowed() const
	{
		return m_handle->GetFullscreenWindowed();
	}

	bool Window::GetResizable() const
	{
		return m_handle->GetResizable();
	}

	bool Window::GetBorderless() const
	{
		return m_handle->GetBorderless();
	}

	WindowFlag Window::GetFlags() const
	{
		return m_handle->GetFlags();
	}

	const std::shared_ptr<WindowHandle> &Window::GetHandle() const
	{
		return m_handle;
	}

	void Window::SetTitle(const std::string &title) const
	{
		m_handle->SetTitle(title);
	}

	void Window::SetPosition(const Point &position) const
	{
		m_handle->SetPosition(position);
	}

	void Window::SetSize(const Size &size) const
	{
		m_handle->SetSize(size);
	}

	void Window::SetMinimumSize(const Size &minSize) const
	{
		m_handle->SetMinimumSize(minSize);
	}

	void Window::SetMaximumSize(const Size &maxSize) const
	{
		m_handle->SetMaximumSize(maxSize);
	}

	void Window::SetFullscreen(const bool fullscreen) const
	{
		m_handle->SetFullscreen(fullscreen);
	}

	void Window::SetFullscreenWindowed(const bool fullscreenWindowed) const
	{
		m_handle->SetFullscreenWindowed(fullscreenWindowed);
	}

	void Window::SetResizable(const bool resizable) const
	{
		m_handle->SetResizable(resizable);
	}

	void Window::SetBorderless(const bool borderless) const
	{
		m_handle->SetBorderless(borderless);
	}
} // namespace Pazu

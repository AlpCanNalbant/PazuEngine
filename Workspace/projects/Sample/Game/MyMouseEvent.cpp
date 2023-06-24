#include <Pazu/Event/MouseEventData.h>
#include <Pazu/Entity.h>
#include "MyMouseEvent.h"
using namespace Pazu;

MyMouseEvent::MyMouseEvent(const std::shared_ptr<Entity> &camera) noexcept
		: m_camera(camera) {}

void MyMouseEvent::OnEvent(const MouseEventData &data) noexcept
{
	switch (data.GetState())
	{
	case MouseEventState::Moved:
		if (m_camera && GetRelativeMode())
		{
			auto &transform = m_camera->GetTransform();
			transform.Rotate(Vector3::Right, static_cast<float>(data.relativeY) * -0.1f, true);
			transform.Rotate(Vector3::Up, static_cast<float>(data.relativeX) * -0.1f, true);
			// transform.Rotate(static_cast<float>(data.relativeY) * -0.1f, static_cast<float>(data.relativeX) * -0.1f, 0.f, true);
			transform.SetPitch(Mathf::Clamp(transform.GetPitch(), -90.f, 90.f), true);
		}
		break;
	default:
		break;
	}
}

void MyMouseEvent::SetCamera(const std::shared_ptr<Entity> &camera) noexcept
{
	m_camera = camera;
}

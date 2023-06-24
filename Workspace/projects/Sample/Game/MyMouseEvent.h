#pragma once
#include <Pazu/Event/MouseEvent.h>

namespace Pazu
{
	class Entity;
}
class MyMouseEvent : public Pazu::MouseEvent
{
public:
	MyMouseEvent() noexcept = default;
	MyMouseEvent(const std::shared_ptr<Pazu::Entity> &camera) noexcept;
	void OnEvent(const Pazu::MouseEventData &data) noexcept final;
	void SetCamera(const std::shared_ptr<Pazu::Entity> &camera) noexcept;

private:
	std::shared_ptr<Pazu::Entity> m_camera;
};

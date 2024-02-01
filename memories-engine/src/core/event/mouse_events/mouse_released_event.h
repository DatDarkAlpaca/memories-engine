#pragma once
#include "mouse_event.h"

namespace mem
{
	struct MouseReleasedEvent : public Event
	{
		DEFINE_EVENT(EventType::MOUSE_RELEASED);

	public:
		MouseReleasedEvent(MouseButton button)
			: button(button)
		{

		}

	public:
		MouseButton button;
	};
}
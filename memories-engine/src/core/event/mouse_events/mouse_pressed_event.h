#pragma once
#include "mouse_event.h"

namespace mem
{
	struct MousePressedEvent : public Event
	{
		DEFINE_EVENT(EventType::MOUSE_PRESSED);

	public:
		MousePressedEvent(MouseButton button)
			: button(button)
		{

		}

	public:
		MouseButton button;
	};
}
#pragma once
#include "mouse_event.h"

namespace mem
{
	struct MouseMovedEvent : public Event
	{
		DEFINE_EVENT(EventType::MOUSE_MOVE);

	public:
		MouseMovedEvent(double x, double y)
			: x(x)
			, y(y)
		{

		}

	public:
		double x = 0, y = 0;
	};
}
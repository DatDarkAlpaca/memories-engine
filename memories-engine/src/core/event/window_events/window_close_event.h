#pragma once
#include "core/event/event.h"

namespace mem
{
	class WindowCloseEvent : public Event
	{
		DEFINE_EVENT(EventType::WINDOW_CLOSE);
	};
}
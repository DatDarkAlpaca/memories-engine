#pragma once
#include "keyboard_event.h"

namespace mem
{
	struct KeyRepeatEvent : public Event
	{
		DEFINE_EVENT(EventType::KEY_REPEAT);

	public:
		KeyRepeatEvent(Key key, KeyboardMods mods)
			: key(key)
			, mods(mods)
		{

		}

	public:
		Key key;
		KeyboardMods mods;
	};
}
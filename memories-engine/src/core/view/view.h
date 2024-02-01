#pragma once
#include "core/defines.h"
#include "core/event/event.h"

namespace mem
{
	class ViewSystem;

	class View
	{
	public:
		explicit View(ViewSystem* handler = nullptr)
			: handler(handler)
		{

		}

		virtual ~View() = default;

	public:
		virtual void onEngineInitialize() { };

		virtual void onInstantiated() { };

		virtual void onRender() { };

		virtual void onUpdate() { };

		virtual void onEvent(Event& event) { };

		virtual void onRemoved() { };

	public:
		void setHandler(ViewSystem* handler) { this->handler = handler; }

	protected:
		NON_OWNING ViewSystem* handler = nullptr;
	};
}
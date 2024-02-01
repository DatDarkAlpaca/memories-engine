#pragma once
#include "core/event/event.h"
#include "core/view/view_system.h"

#include "graphics/graphics_system.h"

namespace mem
{
	class MemoriesEngine
	{
	public:
		MemoriesEngine(const WindowProperties& properties, const APIVersion& api = {});

	public:
		void run();

	private:
		void onEngineInitialize();

		void onRender();

		void onRenderGUI();

		void onUpdate();

		void onEvent(Event& event);

	public:
		mem::ViewSystem& GetViewSystem() { return m_ViewSystem; }

	public:
		mem::ViewSystem m_ViewSystem;
		mem::GraphicsSystem m_GraphicsSystem;
	};
}
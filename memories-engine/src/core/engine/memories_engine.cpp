#include "pch.h"
#include "memories_engine.h"

namespace mem
{
	MemoriesEngine::MemoriesEngine(const WindowProperties& properties, const APIVersion& api)
	{
		LoggerSystem::Initialize();

		m_GraphicsSystem.initialize(properties, api);
		m_GraphicsSystem.setEventCallback(BIND(&MemoriesEngine::onEvent, this));
	}

	void MemoriesEngine::run()
	{
		onEngineInitialize();

		auto& window = m_GraphicsSystem.GetWindow();
		
		// 57, 24, 38 
		while(window->isOpen())
		{
			window->pollEvents();

			onUpdate();

			onRender();

			window->swapBuffers();
		}
	}

	void MemoriesEngine::onEngineInitialize()
	{
		for (const auto& view : m_ViewSystem)
			view->onEngineInitialize();
	}

	void MemoriesEngine::onRender()
	{
		for (const auto& view : m_ViewSystem)
			view->onRender();
	}

	void MemoriesEngine::onUpdate()
	{
		for (const auto& view : m_ViewSystem)
			view->onUpdate();
	}

	void MemoriesEngine::onEvent(Event& event)
	{
		for (const auto& view : m_ViewSystem)
			view->onEvent(event);
	}
}
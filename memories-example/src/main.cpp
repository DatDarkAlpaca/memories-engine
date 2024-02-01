#include <memories_engine.h>
#include <entry.h>

using namespace mem;

class MainGameView : public View
{
public:
	void onEngineInitialize() override
	{
		MEM_LOG_INFO("Engine initialized");
	}

	void onEvent(Event& event) override
	{
		Subscriber subscriber(event);

		subscriber.subscribe<WindowCloseEvent>([](WindowCloseEvent& closeEvent) -> bool {
			MEM_LOG_INFO("Engine shutdown");
			return true;
		});
	}

	void onRender() override
	{
		// renderer.setClearColor();

		// renderer.begin();

		// renderer.submit(transform);

		// renderer.end()
	}
};

class Engine : public MemoriesEngine
{
public:
	Engine()
		: MemoriesEngine({{ 800, 600 }, "MemoriesEngine v1.0" }, { 4,5 })
	{
		m_ViewSystem.Add(mem::make_unique<MainGameView>());
	}
};

extern mem_unique<MemoriesEngine> CreateApplication()
{
	return make_unique<Engine>();
}
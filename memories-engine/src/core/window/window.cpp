#include "pch.h"
#include "window.h"

#include "core/event/events.h"
#include "core/logger/logger.h"
#include "core/event/converters.h"

namespace mem
{
	Window::Window(const WindowProperties& properties)
	{
		initialize(properties);
	}

	void Window::initialize(const WindowProperties& properties)
	{
		auto* glfwWindow = glfwCreateWindow(
			properties.dimensions.x,
			properties.dimensions.y,
			properties.title.c_str(),
			nullptr, nullptr
		);

		m_Window.reset(glfwWindow);
		
		setWindowCallbacks();
		setWindowDataPointer();
	}

	void Window::setCallback(const FnEventCallback& callback)
	{
		m_WindowData.eventCallback = callback;
	}

	void Window::pollEvents()
	{
		glfwPollEvents();
	}

	void Window::swapBuffers()
	{
		glfwSwapBuffers(*this);
	}

	void Window::setContextCurrent()
	{
		glfwMakeContextCurrent(*this);
	}

	bool Window::isOpen() const
	{
		return !glfwWindowShouldClose(m_Window.get());
	}

	void Window::setWindowDataPointer()
	{
		glfwSetWindowUserPointer(m_Window.get(), &m_WindowData);
	}

	void Window::setWindowCallbacks()
	{
		// Status:
		glfwSetWindowCloseCallback(m_Window.get(), [](GLFWwindow* window) {
			auto* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			WindowCloseEvent event;
			data->eventCallback(event);
		});

		glfwSetWindowMaximizeCallback(m_Window.get(), [](GLFWwindow* window, int maximized) {
			auto* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			WindowMaximizedEvent event(maximized);
			data->eventCallback(event);
		});

		glfwSetWindowFocusCallback(m_Window.get(), [](GLFWwindow* window, int focus) {
			auto* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			WindowFocusEvent event(focus);
			data->eventCallback(event);
		});

		// Size:
		glfwSetWindowSizeCallback(m_Window.get(), [](GLFWwindow* window, int width, int height) {
			auto* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			WindowResizeEvent event(width, height);
			data->eventCallback(event);
		});

		glfwSetFramebufferSizeCallback(m_Window.get(), [](GLFWwindow* window, int width, int height) {
			auto* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			WindowFramebufferEvent event(width, height);
			data->eventCallback(event);
		});

		glfwSetWindowContentScaleCallback(m_Window.get(), [](GLFWwindow* window, float xScale, float yScale) {
			auto* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			WindowContentScaleEvent event(xScale, yScale);
			data->eventCallback(event);
		});

		// Position:
		glfwSetWindowPosCallback(m_Window.get(), [](GLFWwindow* window, int xPos, int yPos) {
			auto* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			WindowMovedEvent event(xPos, yPos);
			data->eventCallback(event);
		});

		// Keyboard:
		glfwSetKeyCallback(m_Window.get(), [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			auto* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			switch (action)
			{
				case GLFW_PRESS:
				{
					Key convertedKey = TranslateKey(key);
					KeyboardMods convertedMods = TranslateKeyMods(mods);

					KeyPressedEvent event(convertedKey, convertedMods);
					data->eventCallback(event);
				} break;

				case GLFW_RELEASE:
				{
					Key convertedKey = TranslateKey(key);
					KeyboardMods convertedMods = TranslateKeyMods(mods);

					KeyReleasedEvent event(convertedKey, convertedMods);
					data->eventCallback(event);
				} break;

				case GLFW_REPEAT:
				{
					Key convertedKey = TranslateKey(key);
					KeyboardMods convertedMods = TranslateKeyMods(mods);

					KeyRepeatEvent event(convertedKey, convertedMods);
					data->eventCallback(event);
				} break;

				default:
				{
					MEM_LOG_WARN("Invalid keyboard action passed to window callback: {}", action);
				} break;
			}
		});

		// Mouse:
		glfwSetCursorPosCallback(m_Window.get(), [](GLFWwindow* window, double x, double y) {
			auto* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			MouseMovedEvent event(x, y);
			data->eventCallback(event);
		});

		glfwSetMouseButtonCallback(m_Window.get(), [](GLFWwindow* window, int button, int action, int mods) {
			auto* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButton convertedButton = TranslateMouseButton(button);
					MousePressedEvent event(convertedButton);
					data->eventCallback(event);
				} break;

				case GLFW_RELEASE:
				{
					MouseButton convertedButton = TranslateMouseButton(button);
					MouseReleasedEvent event(convertedButton);
					data->eventCallback(event);
				} break;

				default:
				{
					MEM_LOG_WARN("Invalid keyboard action passed to window callback: {}", action);
				} break;
			}
		});

		glfwSetScrollCallback(m_Window.get(), [](GLFWwindow* window, double xOffset, double yOffset) {
			auto* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			MouseScrollEvent event(xOffset, yOffset);
			data->eventCallback(event);
		});
	}
}
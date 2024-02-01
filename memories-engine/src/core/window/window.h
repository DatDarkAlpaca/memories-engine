#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <memory>

#include "window_properties.h"
#include "core/event/events.h"

namespace mem
{
	struct GLFWWindowDeleter
	{
	public:
		void operator () (GLFWwindow* window)
		{
			glfwDestroyWindow(window);
		}
	};

	class Window
	{
	public:
		explicit Window() = default;

		Window(const WindowProperties& properties);

	public:
		void initialize(const WindowProperties& properties);

		void setCallback(const FnEventCallback& callback);

	public:
		void pollEvents();

		void swapBuffers();

		void setContextCurrent();

	public:
		bool isOpen() const;

	private:
		void setWindowDataPointer();

		void setWindowCallbacks();

	public:
		operator GLFWwindow* () { return m_Window.get(); }

	private:
		struct WindowData
		{
			FnEventCallback eventCallback;
		} m_WindowData;

		std::unique_ptr<GLFWwindow, GLFWWindowDeleter> m_Window;
	};
}
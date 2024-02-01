#pragma once
#include <memory>
#include <glad/glad.h>

#include "core/window/window.h"
#include "core/logger/logger.h"
#include "graphics/api_version.h"

#include "shader/shader.h"

namespace mem
{
	class GraphicsSystem
	{
	public:
		explicit GraphicsSystem()
		{
			m_Window = std::make_unique<Window>();
		}

	public:
		void initialize(const WindowProperties& properties, const APIVersion& api = {})
		{
			if (!glfwInit())
				MEM_LOG_CRITICAL("GLFW failed to initialize");

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, api.versionMajor);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, api.versionMinor);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			m_Window->initialize(properties);

			initialize_api(api);
		}

		void setEventCallback(const FnEventCallback& callback)
		{
			m_Window->setCallback(callback);
		}

	public:
		

	private:
		void initialize_api(const APIVersion& api)
		{
			m_Window->setContextCurrent();
			
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
				MEM_LOG_CRITICAL("GLAD failed to initialize");
		}

	public:
		std::unique_ptr<Window>& GetWindow() { return m_Window; }

	private:
		std::unique_ptr<Window> m_Window;
	};
}
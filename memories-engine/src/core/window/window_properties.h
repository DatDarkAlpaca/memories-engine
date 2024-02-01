#pragma once
#include <glm/glm.hpp>
#include <string>

namespace mem
{
	struct WindowProperties
	{
		glm::vec2 dimensions;
		std::string title;
	};
}
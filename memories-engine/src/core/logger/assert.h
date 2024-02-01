#pragma once
#include "core/logger/logger.h"

namespace mem
{
	inline void __mem_assert(const char* condition, const char* message, const char* file, uint64_t line)
	{
		MEM_LOG_CRITICAL("[Assert]: '{}' failed. [{}]\nFile: {} [{}]", condition, message, file, line);
	}

#define MEM_ASSERT(condition, message)										\
	{																		\
		if(condition) { }													\
		else																\
		{																	\
			mem::__mem_assert(#condition, message, __FILE__, __LINE__);		\
		}																	\
	}

#define MEM_ASS(condition)																\
	{																						\
		if(condition) { }																	\
		else																				\
		{																					\
			mem::__mem_assert(#condition, "No message provided", __FILE__, __LINE__);		\
		}																					\
	}
}
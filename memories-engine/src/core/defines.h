#pragma once
#include "core/memory/memory.h"
#include "core/logger/logger.h"

#define NON_OWNING

#define BIND(function, argument) std::bind(function, argument, std::placeholders::_1)

#if defined(_DEBUG) && !defined(MEM_DEBUG)
	#define MEM_DEBUG
#elif defined(NDEBUG) && !defined(MEM_RELEASE)
	#define MEM_RELEASE
#endif

#ifdef _WIN32
	#define MEM_BREAKPOINT() __debugbreak()
#elif defined(__linux__)
	#define MEM_PLATFORM_LINUX
	#define MEM_BREAKPOINT() __builtin_trap()
#elif defined(__APPLE__)
	#define MEM_PLATFORM_APPLE
	#define MEM_BREAKPOINT() __builtin_trap()
#elif defined(__ANDROID__)
	#define MEM_PLATFORM_ANDROID
	#define MEM_BREAKPOINT() __builtin_trap()
#else
	#error Unsupported platform
#endif
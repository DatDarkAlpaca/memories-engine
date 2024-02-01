#pragma once
#include "core/defines.h"

#pragma warning(push, 0)
	#include <spdlog/spdlog.h>
#pragma warning(pop)

namespace mem
{
	class LoggerSystem
	{
	public:
		static void Initialize();

	public:
		inline static mem_shared<spdlog::logger>& GetLogger() { return m_Logger; }
		inline static mem_shared<spdlog::logger>& GetInfoLogger() { return m_InfoLogger; }

	private:
		static inline mem_shared<spdlog::logger> m_Logger;
		static inline mem_shared<spdlog::logger> m_InfoLogger;
	};
}

#ifdef MEM_DEBUG
	#define MEM_LOG_CRITICAL(...)	{ ::mem::LoggerSystem::GetLogger()->critical(__VA_ARGS__); MEM_BREAKPOINT(); }
	#define MEM_LOG_ERROR(...)		::mem::LoggerSystem::GetLogger()->error(__VA_ARGS__)
	#define MEM_LOG_WARN(...)		::mem::LoggerSystem::GetLogger()->warn(__VA_ARGS__)
	#define MEM_LOG_TRACE(...)		::mem::LoggerSystem::GetInfoLogger()->trace(__VA_ARGS__)
	#define MEM_LOG_DEBUG(...)		::mem::LoggerSystem::GetLogger()->debug(__VA_ARGS__)
	#define MEM_LOG_INFO(...)		::mem::LoggerSystem::GetInfoLogger()->info(__VA_ARGS__)

#else
	#define MEM_LOG_CRITICAL(...)	{ ::mem::LoggerSystem::GetLogger()->critical(__VA_ARGS__); MEM_BREAKPOINT(); }
	#define MEM_LOG_ERROR(...)		::mem::LoggerSystem::GetLogger()->error(__VA_ARGS__)
	#define MEM_LOG_WARN(...)		{ }
	#define MEM_LOG_DEBUG(...)		{ }
	#define MEM_LOG_TRACE(...)		{ }
	#define MEM_LOG_INFO(...)		{ }
#endif
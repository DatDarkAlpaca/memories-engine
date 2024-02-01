#pragma once
#include <memory>

// Raw pointer purpose identifier
#define NON_OWNING

namespace mem
{
	template<typename T, typename Deleter = std::default_delete<T>>
	using mem_unique = std::unique_ptr<T, Deleter>;

	template<typename T, typename ... Args>
	constexpr mem_unique<T> make_unique(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using mem_shared = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr mem_shared<T> make_shared(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using mem_weak = std::weak_ptr<T>;
}
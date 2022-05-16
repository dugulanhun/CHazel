#pragma once

#include <memory>

#ifdef CHZ_PLATFORM_WINDOWS
#if CHZ_DYNAMIC_LINK
	#ifdef CHZ_BUILD_DLL
		#define CHAZEL_API __declspec(dllexport)
	#else
		#define CHAZEL_API __declspec(dllimport)
	#endif
#else
	#define CHAZEL_API
#endif
#else
	#error CHazel only support Window!
#endif

#ifdef CHZ_DEBUG
#ifndef CHZ_ENABLE_ASSERTS
	#define CHZ_ENABLE_ASSERTS
#endif
#endif

#ifdef CHZ_ENABLE_ASSERTS
	#define CHZ_ASSERT(x, ...) { if(!(x)) { CHZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define CHZ_CORE_ASSERT(x, ...) { if(!(x)) { CHZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define CHZ_ASSERT(x, ...)
	#define CHZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define CHZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace CHazel {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}
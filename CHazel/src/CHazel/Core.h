#pragma once

#ifdef CHZ_PLATFORM_WINDOWS
	#ifdef CHZ_BUILD_DLL
		#define CHAZEL_API __declspec(dllexport)
	#else
		#define CHAZEL_API __declspec(dllimport)
	#endif
#else
	#error CHazel only support Window!
#endif

#ifdef CHZ_ENABLE_ASSERTS
	#define CHZ_ASSERT(x, ...) { if(!(X)) { CHZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define CHZ_CORE_ASSERT(x, ...) { if(!(X)) { CHZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define CHZ_ASSERT(x, ...)
	#define CHZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
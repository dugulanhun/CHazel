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
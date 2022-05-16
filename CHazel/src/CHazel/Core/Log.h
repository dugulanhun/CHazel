#pragma once

#include "CHazel/Core/Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace CHazel {
	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros
#define CHZ_CORE_TRACE(...)		::CHazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CHZ_CORE_INFO(...)		::CHazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CHZ_CORE_WARN(...)		::CHazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CHZ_CORE_ERROR(...)		::CHazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CHZ_CORE_FATAL(...)		::CHazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CHZ_TRACE(...)			::CHazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CHZ_INFO(...)			::CHazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define CHZ_WARN(...)			::CHazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CHZ_ERROR(...)			::CHazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define CHZ_FATAL(...)			::CHazel::Log::GetClientLogger()->fatal(__VA_ARGS__)


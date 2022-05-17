#pragma once

#include "CHazel/Core/Core.h"

#ifdef CHZ_PLATFORM_WINDOWS

extern CHazel::Application* CHazel::CreateApplication();

int main(int argc, char** argv)
{
	CHazel::Log::Init();
	
	CHZ_PROFILE_BEGIN_SESSION("Startup", "CHazelProfile-Startup.json");
	auto app = CHazel::CreateApplication();
	CHZ_PROFILE_END_SESSION();

	CHZ_PROFILE_BEGIN_SESSION("Startup", "CHazelProfile-Runtime.json");
	app->run();
	CHZ_PROFILE_END_SESSION();

	CHZ_PROFILE_BEGIN_SESSION("Startup", "CHazelProfile-Shutdown.json");
	delete(app);
	CHZ_PROFILE_END_SESSION();
}
#endif
#pragma once

#ifdef CHZ_PLATFORM_WINDOWS

extern CHazel::Application* CHazel::CreateApplication();

int main(int argc, char** argv)
{
	CHazel::Log::Init();
	CHZ_CORE_WARN("Initialized Log!");
	int a = 5;
	CHZ_CORE_INFO("Hello! var={0}", a);

	auto app = CHazel::CreateApplication();
	app->run();
	delete(app);
}
#endif
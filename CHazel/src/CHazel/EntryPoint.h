#pragma once

#ifdef CHZ_PLATFORM__WINDOWS

extern CHazel::Application* CHazel::CreateApplication();

int main(int argc, char** argv)
{
	auto app = CHazel::CreateApplication();
	app->run();
	delete(app);
}
#endif
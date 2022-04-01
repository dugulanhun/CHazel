#include "Application.h"

#include "Log.h"
#include "CHazel/Events/ApplicationEvent.h"

namespace CHazel{

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		WindowResizeEvent e(1280, 720);

		if (e.IsInCategory(EventCategoryApplication))
		{
			CHZ_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			CHZ_TRACE(e);
		}
		
		while (true);
	}

}
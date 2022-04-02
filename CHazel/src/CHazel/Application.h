#pragma once

#include "Core.h"
#include "Window.h"

namespace CHazel {
	
	class CHAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be define in CLIENT
	Application* CreateApplication();
}



#pragma once

#include "Core.h"
//#include "CHazel/Events/Event.h"

namespace CHazel {
	
	class CHAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// To be define in CLIENT
	Application* CreateApplication();
}



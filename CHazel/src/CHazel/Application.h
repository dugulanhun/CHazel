#pragma once

#include "Core.h"
#include "Window.h"
#include "CHazel/Layer.h"
#include "CHazel/LayerStack.h"
#include "CHazel/Events/ApplicationEvent.h"

namespace CHazel {
	
	class CHAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be define in CLIENT
	Application* CreateApplication();
}



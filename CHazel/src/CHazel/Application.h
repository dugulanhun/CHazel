#pragma once

#include "Core.h"
#include "Window.h"
#include "CHazel/Layer.h"
#include "CHazel/LayerStack.h"
#include "CHazel/Events/ApplicationEvent.h"

#include "CHazel/ImGui/ImGuiLayer.h"

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

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
	private:
		static Application* s_Instance;
	};

	// To be define in CLIENT
	Application* CreateApplication();
}



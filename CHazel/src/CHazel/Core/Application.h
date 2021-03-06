#pragma once

#include "CHazel/Core/Core.h"
#include "CHazel/Core/Window.h"
#include "CHazel/Core/Layer.h"
#include "CHazel/Core/LayerStack.h"
#include "CHazel/Events/ApplicationEvent.h"

#include "CHazel/Core/Timestep.h"

#include "CHazel/ImGui/ImGuiLayer.h"

namespace CHazel {
	
	class Application
	{
	public:
		Application(const std::string& name = "CHazel App");
		virtual ~Application();

		void run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;

		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be define in CLIENT
	Application* CreateApplication();
}



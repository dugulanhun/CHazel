#pragma once

#include "Core.h"
#include "Window.h"
#include "CHazel/Layer.h"
#include "CHazel/LayerStack.h"
#include "CHazel/Events/ApplicationEvent.h"

#include "CHazel/ImGui/ImGuiLayer.h"

#include "CHazel/Renderer/Shader.h"
#include "CHazel/Renderer/Buffer.h"
#include "CHazel/Renderer/VertexArray.h"

#include "CHazel/Renderer/OrthographicCameca.h"

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

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVertexArray;

		OrthographicCameca m_Camera;
	private:
		static Application* s_Instance;
	};

	// To be define in CLIENT
	Application* CreateApplication();
}



#include <CHazel.h>
#include "CHazel/Core/EntryPoint.h"

#include "Platform/OpenGL/OpenGLShader.h"

#include "Sandbox2D.h"

#include "ExampleLayer.h"

class Sandbox : public CHazel::Application
{
public:
	Sandbox()
	{
		// PushLayer(new ExampleLayer());
		// PushLayer(new CHazel::ImGuiLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}

};

CHazel::Application* CHazel::CreateApplication()
{
	return new Sandbox();
}


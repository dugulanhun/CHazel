#include <CHazel.h>

class ExampleLayer: public CHazel::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
	}

	void OnUpdate() override
	{
		// CHZ_INFO("ExampleLayer::Update");
		if (CHazel::Input::IsKeyPressed(CHZ_KEY_TAB))
			CHZ_TRACE("Tab key is pressed (poll)!");
	}


	void OnEvent(CHazel::Event& event) override
	{
		// CHZ_TRACE("{0}", event);
		if (event.GetEvenType() == CHazel::EventType::KeyPressed)
		{
			CHazel::KeyPressedEvent& e = (CHazel::KeyPressedEvent&)event;
			if (CHazel::Input::IsKeyPressed(CHZ_KEY_TAB))
				CHZ_TRACE("Tab key is pressed (event)!");
			CHZ_TRACE("{0}", e.GetKeyCode());
		}
	}

};


class Sandbox : public CHazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushLayer(new CHazel::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

CHazel::Application* CHazel::CreateApplication()
{
	return new Sandbox();
}


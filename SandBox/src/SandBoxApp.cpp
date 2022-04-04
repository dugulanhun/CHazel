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
		CHZ_INFO("ExampleLayer::Update");
	}


	void OnEvent(CHazel::Event& event) override
	{
		CHZ_TRACE("{0}", event);
	}

};


class Sandbox : public CHazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

CHazel::Application* CHazel::CreateApplication()
{
	return new Sandbox();
}


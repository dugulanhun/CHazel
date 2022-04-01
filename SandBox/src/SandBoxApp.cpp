#include <CHazel.h>

class Sandbox : public CHazel::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

CHazel::Application* CHazel::CreateApplication()
{
	return new Sandbox();
}


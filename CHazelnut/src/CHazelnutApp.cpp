#include <CHazel.h>
#include <CHazel/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace CHazel {

	class CHazelnutApp : public Application
	{
	public:
		CHazelnutApp()
			: Application("CHazelnut App")
		{
			PushLayer(new EditorLayer());
		}

		~CHazelnutApp()
		{
		}
	};

	Application* CreateApplication()
	{
		return new CHazelnutApp();
	}

}
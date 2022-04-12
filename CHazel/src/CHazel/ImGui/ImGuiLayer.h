#pragma once
#include "CHazel/Layer.h"

#include "CHazel/Events/ApplicationEvent.h"
#include "CHazel/Events/KeyEvent.h"
#include "CHazel/Events/MouseEvent.h"

namespace CHazel{

	class CHAZEL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();


		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};

}
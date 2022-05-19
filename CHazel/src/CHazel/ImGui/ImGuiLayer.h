#pragma once
#include "CHazel/Core/Layer.h"

#include "CHazel/Events/ApplicationEvent.h"
#include "CHazel/Events/KeyEvent.h"
#include "CHazel/Events/MouseEvent.h"

namespace CHazel{

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();


		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};

}
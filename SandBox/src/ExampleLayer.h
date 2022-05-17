#pragma once

#include "CHazel.h"

#include <imgui/imgui.h>



class ExampleLayer : public CHazel::Layer
{
public:
	ExampleLayer();

	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(CHazel::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(CHazel::Event & e) override;
private:
	CHazel::ShaderLibrary m_ShaderLibrary;
	CHazel::Ref<CHazel::Shader> m_Shader;
	CHazel::Ref<CHazel::VertexArray> m_VertexArray;

	CHazel::Ref<CHazel::Shader> m_FlatColorShader;
	CHazel::Ref<CHazel::VertexArray> m_SquareVertexArray;

	CHazel::Ref<CHazel::Texture2D> m_Texture, m_LogoTexture;

	CHazel::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };

};

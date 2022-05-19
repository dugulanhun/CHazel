#pragma once

#include "CHazel.h"

class Sandbox2D : public CHazel::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(CHazel::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(CHazel::Event& e) override;
private:
	CHazel::OrthographicCameraController m_CameraController;

	// Temp
	CHazel::Ref<CHazel::VertexArray> m_SquareVA;
	CHazel::Ref<CHazel::Shader> m_FlatColorShader;
	CHazel::Ref<CHazel::Framebuffer> m_Framebuffer;

	CHazel::Ref<CHazel::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};
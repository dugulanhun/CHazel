#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	CHZ_PROFILE_FUNCTION();

	m_CheckerboardTexture = CHazel::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	CHZ_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(CHazel::Timestep ts)
{
	CHZ_PROFILE_FUNCTION();

	m_CameraController.OnUpdate(ts);

	// Render
	CHazel::Renderer2D::ResetStats();
	{
		CHZ_PROFILE_SCOPE("Renderer Prep");

		CHazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		CHazel::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;


		CHZ_PROFILE_SCOPE("Renderer Draw");
		CHazel::Renderer2D::BeginScene(m_CameraController.GetCamera());
		CHazel::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		CHazel::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		CHazel::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.8f, 0.8f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		// CHazel::Renderer2D::DrawQuad({ -5.0f, -5.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f);
		// CHazel::Renderer2D::DrawQuad({ -0.5f, -0.5f, 0.0f }, { 1.0f, 1.0f }, m_CheckerboardTexture, 20.0f);
		CHazel::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f);
		CHazel::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, 20.0f);
		CHazel::Renderer2D::EndScene();

		CHazel::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.f, 0.7f };
				CHazel::Renderer2D::DrawQuad({ x,y }, { 0.45f, 0.45f }, color);
			}
		}		
		CHazel::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	CHZ_PROFILE_FUNCTION();

	ImGui::Begin("Settings");

	auto stats = CHazel::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

	ImGui::End();
}

void Sandbox2D::OnEvent(CHazel::Event& e)
{
	m_CameraController.OnEvent(e);
}
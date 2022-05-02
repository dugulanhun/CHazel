#pragma once

#include "CHazel/Renderer/OrthographicCameca.h"
#include "CHazel/Core/Timestep.h"

#include "CHazel/Events/ApplicationEvent.h"
#include "CHazel/Events/MouseEvent.h"

namespace CHazel {

	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRatio, bool isAllowedRotion = false);

		void OnUpdate(Timestep ts);
		void OnEvent(Event& e);

		OrthographicCameca& GetCamera() { return m_Camera; }
		const OrthographicCameca& GetCamera() const { return m_Camera; }

		float GetZoomLevel() const { return m_ZoomLevel; }
		void SetZoomLevel(float level) { m_ZoomLevel = level; }
	private:
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		OrthographicCameca m_Camera;

		bool m_IsAllowRotation;

		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
		float m_CameraRotation = 0.0f;
		float m_CameraTranslationSpeed = 5.0f, m_CameraRotationSpeed = 180.0f;
	};
}
#pragma once

#include "RendererCommand.h"

#include "OrthographicCameca.h"
#include "Shader.h"


namespace CHazel {
		
	class Renderer
	{
	public:
		static void Init();
		static void OnWindowResize(uint32_t width, uint32_t height);

		static void BeginScene(OrthographicCameca& camera);
		static void EndScene();
		static void Submit(const CHazel::Ref <Shader>& shader, const CHazel::Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;
	};
}
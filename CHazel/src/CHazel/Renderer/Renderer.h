#pragma once

#include "RendererCommand.h"

#include "OrthographicCameca.h"
#include "Shader.h"


namespace CHazel {
		
	class Renderer
	{
	public:
		static void BeginScene(OrthographicCameca& camera);
		static void EndScene();
		static void Submit(const std::shared_ptr <Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;
	};
}
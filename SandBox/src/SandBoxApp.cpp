#include <CHazel.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>

#include <glm/gtc/type_ptr.hpp>

class ExampleLayer: public CHazel::Layer
{
public:
	ExampleLayer()
		:Layer("Example"), m_CameraController(1280.0f / 720.0f)
	{
		m_VertexArray.reset(CHazel::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		CHazel::Ref<CHazel::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(CHazel::VertexBuffer::Create(vertices, sizeof(vertices)));
		CHazel::BufferLayout layout = {
			{CHazel::ShaderDataType::Float3, "a_Position"},
			{CHazel::ShaderDataType::Float4, "a_Color"}
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		CHazel::Ref<CHazel::IndexBuffer> indexBuffer;
		indexBuffer.reset(CHazel::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVertexArray.reset(CHazel::VertexArray::Create());

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f,	1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f,	1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f,	0.0f, 1.0f
		};

		CHazel::Ref<CHazel::VertexBuffer> squareVB;
		squareVB.reset(CHazel::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ CHazel::ShaderDataType::Float3, "a_Position" },
			{ CHazel::ShaderDataType::Float2, "a_TexCoord" }
			});
		m_SquareVertexArray->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		CHazel::Ref<CHazel::IndexBuffer> squareIB;
		squareIB.reset(CHazel::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVertexArray->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
			}
		)";
		m_Shader = CHazel::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;

			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

		m_FlatColorShader = CHazel::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = CHazel::Texture2D::Create("assets/textures/Checkerboard.png");
		m_LogoTexture = CHazel::Texture2D::Create("assets/textures/ChernoLogo.png");

		std::dynamic_pointer_cast<CHazel::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<CHazel::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(CHazel::Timestep ts) override
	{
		m_CameraController.OnUpdate(ts);

		CHazel::RendererCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		CHazel::RendererCommand::Clear();

		CHazel::Renderer::BeginScene(m_CameraController.GetCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<CHazel::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<CHazel::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11, y * 0.11, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				CHazel::Renderer::Submit(m_FlatColorShader, m_SquareVertexArray, transform);
			}
		}

		auto textureShader = m_ShaderLibrary.Get("Texture");

		m_Texture->Bind();
		CHazel::Renderer::Submit(textureShader, m_SquareVertexArray, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_LogoTexture->Bind();
		CHazel::Renderer::Submit(textureShader, m_SquareVertexArray, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));


		// Triangle
		// CHazel::Renderer::Submit(m_Shader, m_VertexArray);

		CHazel::Renderer::EndScene();


	}

	void OnImGuiRender() override
	{ 	
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}
	
	void OnEvent(CHazel::Event& e) override
	{		
		m_CameraController.OnEvent(e);
	}
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


class Sandbox : public CHazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		// PushLayer(new CHazel::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

CHazel::Application* CHazel::CreateApplication()
{
	return new Sandbox();
}


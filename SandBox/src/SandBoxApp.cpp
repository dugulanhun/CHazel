#include <CHazel.h>

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>

class ExampleLayer: public CHazel::Layer
{
public:
	ExampleLayer()
		:Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(CHazel::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		std::shared_ptr<CHazel::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(CHazel::VertexBuffer::Create(vertices, sizeof(vertices)));
		CHazel::BufferLayout layout = {
			{CHazel::ShaderDataType::Float3, "a_Position"},
			{CHazel::ShaderDataType::Float4, "a_Color"}
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<CHazel::IndexBuffer> indexBuffer;
		indexBuffer.reset(CHazel::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVertexArray.reset(CHazel::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		std::shared_ptr<CHazel::VertexBuffer> squareVB;
		squareVB.reset(CHazel::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ CHazel::ShaderDataType::Float3, "a_Position" }
			});
		m_SquareVertexArray->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<CHazel::IndexBuffer> squareIB;
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
		m_Shader.reset(new CHazel::Shader(vertexSrc, fragmentSrc));

		std::string blueShaderVertexSrc = R"(
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

		std::string blueShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			void main()
			{
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

		m_BlueShader.reset(new CHazel::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));

	}

	void OnUpdate(CHazel::Timestep ts) override
	{
		if (CHazel::Input::IsKeyPressed(CHZ_KEY_LEFT))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;
		else if (CHazel::Input::IsKeyPressed(CHZ_KEY_RIGHT))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;

		if (CHazel::Input::IsKeyPressed(CHZ_KEY_DOWN))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;
		else if (CHazel::Input::IsKeyPressed(CHZ_KEY_UP))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;

		if (CHazel::Input::IsKeyPressed(CHZ_KEY_A))
			m_CameraRotation += m_CameraRotationSpeed * ts;
		else if (CHazel::Input::IsKeyPressed(CHZ_KEY_D))
			m_CameraRotation -= m_CameraRotationSpeed * ts;

		CHazel::RendererCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		CHazel::RendererCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		CHazel::Renderer::BeginScene(m_Camera);

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11, y * 0.11, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				CHazel::Renderer::Submit(m_BlueShader, m_SquareVertexArray, transform);
			}
		}

		CHazel::Renderer::Submit(m_Shader, m_VertexArray);

		CHazel::Renderer::EndScene();


	}

	void OnImGuiRender() override
	{ 	
	}
	
	void OnEvent(CHazel::Event& event) override
	{		
	}
private:
	std::shared_ptr<CHazel::Shader> m_Shader;
	std::shared_ptr<CHazel::VertexArray> m_VertexArray;

	std::shared_ptr<CHazel::Shader> m_BlueShader;
	std::shared_ptr<CHazel::VertexArray> m_SquareVertexArray;

	CHazel::OrthographicCameca m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;

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


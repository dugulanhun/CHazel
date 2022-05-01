#include "chzpch.h"
#include "Shader.h"

#include "RendererAPI.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace CHazel {

	CHazel::Shader* Shader::Create(const std::string& filepath)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: CHZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLShader(filepath);
		}

		CHZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Shader* Shader::Create(const std::string& vertexSource, const std::string& fragmentSource)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: CHZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLShader(vertexSource, fragmentSource);
		}

		CHZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
	
}
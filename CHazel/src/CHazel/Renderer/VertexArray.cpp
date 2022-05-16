#include "chzpch.h"
#include "CHazel/Renderer/VertexArray.h"

#include "CHazel/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace CHazel
{


	Ref<VertexArray> VertexArray::Create()
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: CHZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexArray>();
		}

		CHZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
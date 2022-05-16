#include "chzpch.h"
#include "CHazel/Renderer/Buffer.h"

#include "CHazel/Renderer/RendererAPI.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace CHazel
{
	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: CHZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexBuffer>(vertices, size);
		}

		CHZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
	
	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: CHZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLIndexBuffer>(indices, size);
		}

		CHZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}

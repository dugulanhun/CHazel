#include "chzpch.h"
#include "CHazel/Renderer/GraphicsContext.h"

#include "CHazel/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace CHazel {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    CHZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		CHZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
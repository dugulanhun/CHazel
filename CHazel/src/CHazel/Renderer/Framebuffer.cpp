#include "chzpch.h"
#include "Framebuffer.h"

#include "CHazel/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLFramebuffer.h"


namespace CHazel {


	CHazel::Ref<CHazel::Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: CHZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLFramebuffer>(spec);
		}

		CHZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
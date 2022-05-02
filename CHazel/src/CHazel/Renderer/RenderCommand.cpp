#include "chzpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace CHazel
{

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}
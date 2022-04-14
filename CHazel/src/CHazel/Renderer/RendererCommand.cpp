#include "chzpch.h"
#include "RendererCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace CHazel
{

	RendererAPI* RendererCommand::s_RendererAPI = new OpenGLRendererAPI;

}
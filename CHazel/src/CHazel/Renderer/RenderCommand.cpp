#include "chzpch.h"
#include "CHazel/Renderer/RenderCommand.h"

namespace CHazel
{

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}
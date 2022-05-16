#include "chzpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace CHazel {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		CHZ_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CHZ_CORE_ASSERT(status, "Failed to initialize Glad!");

		CHZ_CORE_INFO("OpenGL Info:");
		CHZ_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		CHZ_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		CHZ_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}
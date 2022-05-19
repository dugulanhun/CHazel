#include "chzpch.h"
#include "Platform/Windows/WindowsWindow.h"

#include "CHazel/Core/Core.h"

#include "CHazel/Events/ApplicationEvent.h"
#include "CHazel/Events/MouseEvent.h"
#include "CHazel/Events/KeyEvent.h"

#include "CHazel/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLContext.h"


namespace CHazel {

	static uint8_t s_GLFWWindowCount = 0;

	static void GLFWErrorCallback(int error, const char* description)
	{
		CHZ_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	Scope<Window> Window::Create(const WindowProps& props)
	{
		return CreateScope<WindowsWindow>(props);
	}

	
	CHazel::WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		CHZ_PROFILE_FUNCTION();

		Init(props);
	}

	CHazel::WindowsWindow::~WindowsWindow()
	{
		CHZ_PROFILE_FUNCTION();

		Shutdown();
	}

	void CHazel::WindowsWindow::Init(const WindowProps& props)
	{
		CHZ_PROFILE_FUNCTION();

		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		CHZ_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (s_GLFWWindowCount == 0)
		{
			CHZ_PROFILE_SCOPE("glfwInit");

			int success = glfwInit();
			CHZ_CORE_ASSERT(success, "Could not initialize GLFW!");

			glfwSetErrorCallback(GLFWErrorCallback);
		}

		{
			CHZ_PROFILE_FUNCTION();

			#if defined(CHZ_DEBUG)
				if (Renderer::GetAPI() == RendererAPI::API::OpenGL)
					glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
			#endif

			m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
			++s_GLFWWindowCount;
		}

		m_Context = GraphicsContext::Create(m_Window);
		m_Context->Init();
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW callback
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 0);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(key);
						data.EventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, 1);
						data.EventCallback(event);
						break;
					}
				}
			});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				KeyTypedEvent event(keycode);
				data.EventCallback(event);
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(button);
						data.EventCallback(event);
						break;

					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event(button);
						data.EventCallback(event);
						break;
					}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)xoffset, (float)yoffset);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xpos, (float)ypos);
				data.EventCallback(event);
			});
	}

	void CHazel::WindowsWindow::Shutdown()
	{
		CHZ_PROFILE_FUNCTION();

		glfwDestroyWindow(m_Window);
		--s_GLFWWindowCount;

		if (s_GLFWWindowCount == 0)
		{
			glfwTerminate();
		}
	}

	void CHazel::WindowsWindow::OnUpdate()
	{
		CHZ_PROFILE_FUNCTION();

		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void CHazel::WindowsWindow::SetVSync(bool enable)
	{
		CHZ_PROFILE_FUNCTION();

		// If w/out brace, only 1 closest line will be executed
		// �����1/0�����ǿ�/�ص���˼��������һ֡Swap֮��Ҫ�ȶ��ٴ�Screen Update������
		// ����glfwSwapInterval�ڲ���װ�˶�Ӧƽ̨��vsync���������Ի����Ͼ��ǿ��ص���˼������
		// Ҫע����ǣ����ǿ��԰����interval����10��Ȼ���Ӵ���������޿�������ȻVSync on
		// �ɼ���VSync��ʵ����Ⱦ��֡��û���κι�ϵ��VSync������60ֻ֡����Ϊ�󲿷���ʾ��ˢ����60HZ������Sync����
		if (enable)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enable;
	}

	bool CHazel::WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}


}


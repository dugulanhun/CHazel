#include "chzpch.h"
#include "WindowsWindow.h"

namespace CHazel {

	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	
	CHazel::WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	CHazel::WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void CHazel::WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		CHZ_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			//CHZ_ASSERT(success, "Could not intialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void CHazel::WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void CHazel::WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void CHazel::WindowsWindow::SetVSync(bool enable)
	{
		// If w/out brace, only 1 closest line will be executed
		// 这里的1/0并不是开/关的意思，而是下一帧Swap之间要等多少次Screen Update。。。
		// 但是glfwSwapInterval内部封装了对应平台的vsync函数，所以基本上就是开关的意思。。。
		// 要注意的是，我们可以把这个interval开成10，然后视窗看起来会巨卡，但依然VSync on
		// 可见，VSync跟实际渲染的帧数没有任何关系，VSync看似锁60帧只是因为大部分显示器刷新率60HZ，被“Sync”了
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


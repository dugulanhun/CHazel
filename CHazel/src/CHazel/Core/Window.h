#pragma once

#include "chzpch.h"

#include "CHazel/Core/Core.h"
#include "CHazel/Events/Event.h"

namespace CHazel {

	struct WindowProps 
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(std::string title = "CHazel Engine",
						unsigned int width = 1280,
						unsigned int height = 720)
			:Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	class CHAZEL_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {};

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enable) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		// implement in children class
		static Window* Create(const WindowProps& props = WindowProps());


	};

}
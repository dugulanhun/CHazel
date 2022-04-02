#pragma once

#include "CHazel/Core.h"

namespace CHazel {

	// Events in CHazel are currently blocking, meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right then an there.
	// For the future, a better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage.

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonRealeased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
									virtual EventType GetEvenType() const override{ return GetStaticType(); }\
									virtual const char* GetName() const override { return #type; }
	
	
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class CHAZEL_API Event
	{
		friend class EventDispatcher;
	public:
		// =0 (Pure Virtual) here means it has to be implemented elsewhere (Prob. in inherited class)
		// const means the function itself will not change the member property
		virtual EventType GetEvenType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	// class Event Dispatcher
	class EventDispatcher
	{
		//Define EventFunc() Template
		//with T& input and return bool
		template <typename T>
		using EventFn = std::function<bool>(T&);
	public:
		EventDispatcher(Event& event)
			:m_Event(event)
		{
		}

		// Make a template function to Dispatch the event
		// The input parameter is a Function
		template <typename T>
		bool Dispatch(EventFn<T> func)
		{
			// Check if the Event Type of the Event bond to this dispatcher
			// matches with the function we are using.
			// Because if they are not the same type, then we cannot guarantee
			// that the function is actually valid.
			if (m_Event.GetEvenType() == T::GetStaticType())
			{
				// Whatever it is, this certain function of this Event will be called,
				// And the function will decide whether to consume the event or not.
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}
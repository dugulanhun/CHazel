#pragma once

namespace CHazel
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define CHZ_MOUSE_BUTTON_0      ::CHazel::Mouse::Button0
#define CHZ_MOUSE_BUTTON_1      ::CHazel::Mouse::Button1
#define CHZ_MOUSE_BUTTON_2      ::CHazel::Mouse::Button2
#define CHZ_MOUSE_BUTTON_3      ::CHazel::Mouse::Button3
#define CHZ_MOUSE_BUTTON_4      ::CHazel::Mouse::Button4
#define CHZ_MOUSE_BUTTON_5      ::CHazel::Mouse::Button5
#define CHZ_MOUSE_BUTTON_6      ::CHazel::Mouse::Button6
#define CHZ_MOUSE_BUTTON_7      ::CHazel::Mouse::Button7
#define CHZ_MOUSE_BUTTON_LAST   ::CHazel::Mouse::ButtonLast
#define CHZ_MOUSE_BUTTON_LEFT   ::CHazel::Mouse::ButtonLeft
#define CHZ_MOUSE_BUTTON_RIGHT  ::CHazel::Mouse::ButtonRight
#define CHZ_MOUSE_BUTTON_MIDDLE ::CHazel::Mouse::ButtonMiddle
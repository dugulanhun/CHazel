#pragma once

namespace CHazel
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define CHZ_KEY_SPACE           ::CHazel::Key::Space
#define CHZ_KEY_APOSTROPHE      ::CHazel::Key::Apostrophe    /* ' */
#define CHZ_KEY_COMMA           ::CHazel::Key::Comma         /* , */
#define CHZ_KEY_MINUS           ::CHazel::Key::Minus         /* - */
#define CHZ_KEY_PERIOD          ::CHazel::Key::Period        /* . */
#define CHZ_KEY_SLASH           ::CHazel::Key::Slash         /* / */
#define CHZ_KEY_0               ::CHazel::Key::D0
#define CHZ_KEY_1               ::CHazel::Key::D1
#define CHZ_KEY_2               ::CHazel::Key::D2
#define CHZ_KEY_3               ::CHazel::Key::D3
#define CHZ_KEY_4               ::CHazel::Key::D4
#define CHZ_KEY_5               ::CHazel::Key::D5
#define CHZ_KEY_6               ::CHazel::Key::D6
#define CHZ_KEY_7               ::CHazel::Key::D7
#define CHZ_KEY_8               ::CHazel::Key::D8
#define CHZ_KEY_9               ::CHazel::Key::D9
#define CHZ_KEY_SEMICOLON       ::CHazel::Key::Semicolon     /* ; */
#define CHZ_KEY_EQUAL           ::CHazel::Key::Equal         /* = */
#define CHZ_KEY_A               ::CHazel::Key::A
#define CHZ_KEY_B               ::CHazel::Key::B
#define CHZ_KEY_C               ::CHazel::Key::C
#define CHZ_KEY_D               ::CHazel::Key::D
#define CHZ_KEY_E               ::CHazel::Key::E
#define CHZ_KEY_F               ::CHazel::Key::F
#define CHZ_KEY_G               ::CHazel::Key::G
#define CHZ_KEY_H               ::CHazel::Key::H
#define CHZ_KEY_I               ::CHazel::Key::I
#define CHZ_KEY_J               ::CHazel::Key::J
#define CHZ_KEY_K               ::CHazel::Key::K
#define CHZ_KEY_L               ::CHazel::Key::L
#define CHZ_KEY_M               ::CHazel::Key::M
#define CHZ_KEY_N               ::CHazel::Key::N
#define CHZ_KEY_O               ::CHazel::Key::O
#define CHZ_KEY_P               ::CHazel::Key::P
#define CHZ_KEY_Q               ::CHazel::Key::Q
#define CHZ_KEY_R               ::CHazel::Key::R
#define CHZ_KEY_S               ::CHazel::Key::S
#define CHZ_KEY_T               ::CHazel::Key::T
#define CHZ_KEY_U               ::CHazel::Key::U
#define CHZ_KEY_V               ::CHazel::Key::V
#define CHZ_KEY_W               ::CHazel::Key::W
#define CHZ_KEY_X               ::CHazel::Key::X
#define CHZ_KEY_Y               ::CHazel::Key::Y
#define CHZ_KEY_Z               ::CHazel::Key::Z
#define CHZ_KEY_LEFT_BRACKET    ::CHazel::Key::LeftBracket   /* [ */
#define CHZ_KEY_BACKSLASH       ::CHazel::Key::Backslash     /* \ */
#define CHZ_KEY_RIGHT_BRACKET   ::CHazel::Key::RightBracket  /* ] */
#define CHZ_KEY_GRAVE_ACCENT    ::CHazel::Key::GraveAccent   /* ` */
#define CHZ_KEY_WORLD_1         ::CHazel::Key::World1        /* non-US #1 */
#define CHZ_KEY_WORLD_2         ::CHazel::Key::World2        /* non-US #2 */

/* Function keys */
#define CHZ_KEY_ESCAPE          ::CHazel::Key::Escape
#define CHZ_KEY_ENTER           ::CHazel::Key::Enter
#define CHZ_KEY_TAB             ::CHazel::Key::Tab
#define CHZ_KEY_BACKSPACE       ::CHazel::Key::Backspace
#define CHZ_KEY_INSERT          ::CHazel::Key::Insert
#define CHZ_KEY_DELETE          ::CHazel::Key::Delete
#define CHZ_KEY_RIGHT           ::CHazel::Key::Right
#define CHZ_KEY_LEFT            ::CHazel::Key::Left
#define CHZ_KEY_DOWN            ::CHazel::Key::Down
#define CHZ_KEY_UP              ::CHazel::Key::Up
#define CHZ_KEY_PAGE_UP         ::CHazel::Key::PageUp
#define CHZ_KEY_PAGE_DOWN       ::CHazel::Key::PageDown
#define CHZ_KEY_HOME            ::CHazel::Key::Home
#define CHZ_KEY_END             ::CHazel::Key::End
#define CHZ_KEY_CAPS_LOCK       ::CHazel::Key::CapsLock
#define CHZ_KEY_SCROLL_LOCK     ::CHazel::Key::ScrollLock
#define CHZ_KEY_NUM_LOCK        ::CHazel::Key::NumLock
#define CHZ_KEY_PRINT_SCREEN    ::CHazel::Key::PrintScreen
#define CHZ_KEY_PAUSE           ::CHazel::Key::Pause
#define CHZ_KEY_F1              ::CHazel::Key::F1
#define CHZ_KEY_F2              ::CHazel::Key::F2
#define CHZ_KEY_F3              ::CHazel::Key::F3
#define CHZ_KEY_F4              ::CHazel::Key::F4
#define CHZ_KEY_F5              ::CHazel::Key::F5
#define CHZ_KEY_F6              ::CHazel::Key::F6
#define CHZ_KEY_F7              ::CHazel::Key::F7
#define CHZ_KEY_F8              ::CHazel::Key::F8
#define CHZ_KEY_F9              ::CHazel::Key::F9
#define CHZ_KEY_F10             ::CHazel::Key::F10
#define CHZ_KEY_F11             ::CHazel::Key::F11
#define CHZ_KEY_F12             ::CHazel::Key::F12
#define CHZ_KEY_F13             ::CHazel::Key::F13
#define CHZ_KEY_F14             ::CHazel::Key::F14
#define CHZ_KEY_F15             ::CHazel::Key::F15
#define CHZ_KEY_F16             ::CHazel::Key::F16
#define CHZ_KEY_F17             ::CHazel::Key::F17
#define CHZ_KEY_F18             ::CHazel::Key::F18
#define CHZ_KEY_F19             ::CHazel::Key::F19
#define CHZ_KEY_F20             ::CHazel::Key::F20
#define CHZ_KEY_F21             ::CHazel::Key::F21
#define CHZ_KEY_F22             ::CHazel::Key::F22
#define CHZ_KEY_F23             ::CHazel::Key::F23
#define CHZ_KEY_F24             ::CHazel::Key::F24
#define CHZ_KEY_F25             ::CHazel::Key::F25

/* Keypad */
#define CHZ_KEY_KP_0            ::CHazel::Key::KP0
#define CHZ_KEY_KP_1            ::CHazel::Key::KP1
#define CHZ_KEY_KP_2            ::CHazel::Key::KP2
#define CHZ_KEY_KP_3            ::CHazel::Key::KP3
#define CHZ_KEY_KP_4            ::CHazel::Key::KP4
#define CHZ_KEY_KP_5            ::CHazel::Key::KP5
#define CHZ_KEY_KP_6            ::CHazel::Key::KP6
#define CHZ_KEY_KP_7            ::CHazel::Key::KP7
#define CHZ_KEY_KP_8            ::CHazel::Key::KP8
#define CHZ_KEY_KP_9            ::CHazel::Key::KP9
#define CHZ_KEY_KP_DECIMAL      ::CHazel::Key::KPDecimal
#define CHZ_KEY_KP_DIVIDE       ::CHazel::Key::KPDivide
#define CHZ_KEY_KP_MULTIPLY     ::CHazel::Key::KPMultiply
#define CHZ_KEY_KP_SUBTRACT     ::CHazel::Key::KPSubtract
#define CHZ_KEY_KP_ADD          ::CHazel::Key::KPAdd
#define CHZ_KEY_KP_ENTER        ::CHazel::Key::KPEnter
#define CHZ_KEY_KP_EQUAL        ::CHazel::Key::KPEqual

#define CHZ_KEY_LEFT_SHIFT      ::CHazel::Key::LeftShift
#define CHZ_KEY_LEFT_CONTROL    ::CHazel::Key::LeftControl
#define CHZ_KEY_LEFT_ALT        ::CHazel::Key::LeftAlt
#define CHZ_KEY_LEFT_SUPER      ::CHazel::Key::LeftSuper
#define CHZ_KEY_RIGHT_SHIFT     ::CHazel::Key::RightShift
#define CHZ_KEY_RIGHT_CONTROL   ::CHazel::Key::RightControl
#define CHZ_KEY_RIGHT_ALT       ::CHazel::Key::RightAlt
#define CHZ_KEY_RIGHT_SUPER     ::CHazel::Key::RightSuper
#define CHZ_KEY_MENU            ::CHazel::Key::Menu
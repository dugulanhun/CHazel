#pragma once

#include "chzpch.h"

#include "CHazel/Core/Core.h"
#include "CHazel/Core/KeyCodes.h"
#include "CHazel/Core/MouseCodes.h"

namespace CHazel {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);
		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}
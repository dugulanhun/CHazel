workspace "CHazel"
	architecture "x64"
	startproject "SandBox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


IncludeDir = {}
IncludeDir["GLFW"] = "CHazel/vendor/GLFW/include"
IncludeDir["Glad"] = "CHazel/vendor/Glad/include"
IncludeDir["ImGui"] = "CHazel/vendor/imgui"

include "CHazel/vendor/GLFW"
include "CHazel/vendor/Glad"
include "CHazel/vendor/imgui"

project "CHazel"
	location "CHazel"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "chzpch.h"
	pchsource "CHazel/src/chzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"CHZ_PLATFORM_WINDOWS",
			"CHZ_BUILD_DLL",
			"CHZ_ENABLE_ASSERTS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/SandBox/\"")
		}

	filter "configurations:Debug"
		defines "CHZ_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "CHZ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "CHZ_DIST"
		runtime "Release"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"CHazel/vendor/spdlog/include",
		"CHazel/src"
	}

	links
	{
		"CHazel"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"CHZ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CHZ_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "CHZ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "CHZ_DIST"
		runtime "Release"
		optimize "On"
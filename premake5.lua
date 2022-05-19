workspace "CHazel"
	architecture "x64"
	startproject "CHazelnut"

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
IncludeDir["glm"] = "CHazel/vendor/glm"
IncludeDir["stb_image"] = "CHazel/vendor/stb_image"

include "CHazel/vendor/GLFW"
include "CHazel/vendor/Glad"
include "CHazel/vendor/imgui"

project "CHazel"
	location "CHazel"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "chzpch.h"
	pchsource "CHazel/src/chzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
	    "_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CHZ_PLATFORM_WINDOWS",
			"CHZ_BUILD_DLL",
			"CHZ_ENABLE_ASSERTS"
		}

	filter "configurations:Debug"
		defines "CHZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CHZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CHZ_DIST"
		runtime "Release"
		optimize "on"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"CHazel/src",
		"CHazel/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"CHazel"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CHZ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CHZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CHZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CHZ_DIST"
		runtime "Release"
		optimize "on"


project "CHazelnut"
	location "CHazelnut"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"CHazel/src",
		"CHazel/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"CHazel"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CHZ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CHZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CHZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CHZ_DIST"
		runtime "Release"
		optimize "on"
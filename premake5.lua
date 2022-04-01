workspace "CHazel"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CHazel"
	location "CHazel"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"CHZ_PLATFORM_WINDOWS",
			"CHZ_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}

	filter "configurations:Debug"
		defines "CHZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CHZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CHZ_DIST"
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
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"CHZ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CHZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CHZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CHZ_DIST"
		optimize "On"
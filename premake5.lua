workspace "Engine"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Engine/vendor/GLFW/include"
IncludeDir["Glad"] = "Engine/vendor/Glad/include"
IncludeDir["ImGui"] = "Engine/vendor/imgui"
IncludeDir["glm"] = "Engine/vendor/glm"

include "Engine/vendor/GLFW"
include "Engine/vendor/Glad"
include "Engine/vendor/imgui"

project "Engine"
    location "Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "engnpch.h"
    pchsource "Engine/src/engnpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
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
		"%{IncludeDir.glm}"
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
            "ENGN_PLATFORM_WINDOWS",
            "ENGN_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines "ENGN_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "ENGN_RELEASE"
        runtime "Release"
        symbols "on"

    filter "configurations:Dist"
        defines "ENGN_DIST"
        runtime "Release"
        symbols "on"

project "Sandbox"
    location "Sandbox"
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
        "Engine/vendor/spdlog/include",
        "Engine/src",
        "Engine/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "Engine"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "ENGN_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "ENGN_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "ENGN_RELEASE"
        runtime "Release"
        symbols "on"

    filter "configurations:Dist"
        defines "ENGN_DIST"
        runtime "Release"
        symbols "on"

workspace "cautious-octo-enigma"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

  startproject "sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "cautious-octo-enigma"
  location "cautious-octo-enigma"
  kind "SharedLib"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-tmp/" .. outputdir .. "/%{prj.name}")

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
    staticruntime "on"
    systemversion "latest"

    defines
    {
      "OCTO_PLATFORM_WINDOWS",
      "OCTO_BUILD_DLL"
    }

    postbuildcommands
    {
      ( "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox" )
    }

  filter "configurations:Debug"
    defines "OCTO_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "OCTO_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "OCTO_DIST"
    optimize "On"

project "sandbox"
  location "sandbox"
  kind "ConsoleApp"
  language "C++"
	cppdialect "C++17"
  staticruntime "on"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-tmp/" .. outputdir .. "/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "cautious-octo-enigma/vendor/spdlog/include",
    "cautious-octo-enigma/src"
  }

   links
  {
    "cautious-octo-enigma"
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "on"
    systemversion "latest"

    defines
    {
      "OCTO_PLATFORM_WINDOWS"
    }

  filter "configurations:Debug"
    defines "OCTO_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "OCTO_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "OCTO_DIST"
    optimize "On"

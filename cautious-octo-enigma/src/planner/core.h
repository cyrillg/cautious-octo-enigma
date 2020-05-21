#pragma once

#ifdef OCTO_PLATFORM_WINDOWS
#ifdef OCTO_BUILD_DLL
#define OCTO_API _declspec(dllexport)
#else
#define OCTO_API _declspec(dllimport)
#endif // OCTO_BUILD_DLL
#else
#error Octo only supports Windows 
#endif // OCTO_PLATFORM_WINDOWS

#pragma once

#ifdef ENGN_PLATFORM_WINDOWS
#if ENGN_DYNAMIC_LINK
    #ifdef ENGN_BUILD_DLL
        #define ENGN_API __declspec(dllexport)
    #else
        #define ENGN_API __declspec(dllimport)
    #endif
#else
    #define ENGN_API
#endif
#else
    #error OS not supported!
#endif

#ifdef ENGN_DEBUG
    #define ENGN_ENABLE_ASSERTS
#endif

#ifdef ENGN_ENABLE_ASSERTS
#define ENGN_ASSERT(x, ...) { if(!(x)) { ENGN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define ENGN_CORE_ASSERT(x, ...) { if(!(x)) { ENGN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define ENGN_ASSERT(x, ...)
#define ENGN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x) 

#define ENGN_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

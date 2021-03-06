#pragma once

#ifdef RN_PLATFORM_WINDOWS
	#ifdef RN_BUILD_DLL
		#define RONIN_API __declspec(dllexport)
	#else
		#define RONIN_API __declspec(dllimport)
	#endif
#else
#error Ronin only supports Windows!
#endif

#ifdef RN_ENABLE_ASSERTS
#define RN_ASSERT(x, ...)		{ if(!(x)) { RN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define RN_CORE_ASSERT(x, ...)	{ if(!(x)) { RN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define RN_ASSERT(x, ...)
#define RN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
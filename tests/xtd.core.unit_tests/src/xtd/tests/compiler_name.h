#pragma once
#if defined(_MSC_VER)
#  define __compiler_name__ "Microsoft Visual Studio"
#elif defined(__clang__)
#  define __compiler_name__ "clang"
#elif defined(__GNUC__)
#  define __compiler_name__ "gcc"
#else
#  define __compiler_name__ "unknown"
#endif


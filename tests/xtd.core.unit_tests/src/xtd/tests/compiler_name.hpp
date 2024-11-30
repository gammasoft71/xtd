#pragma once
#if defined(_MSC_VER)
#  define __compiler_name__ "MSVC"
#elif defined(__APPLE__) && defined(__clang__)
#  define __compiler_name__ "Apple Clang"
#elif defined(__clang__)
#  define __compiler_name__ "Clang"
#elif defined(__GNUC__)
#  define __compiler_name__ "GCC"
#else
#  define __compiler_name__ "unknown"
#endif


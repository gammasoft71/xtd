#pragma once
#if defined(_MSC_VER)
#  define __compiler_version__ xtd::version {_MSC_FULL_VER / 10000000, _MSC_FULL_VER % 10000000 / 100000, _MSC_FULL_VER % 100000}
#elif defined(__clang__)
#  define __compiler_version__ xtd::version {__clang_major__, __clang_minor__, __clang_patchlevel__}
#elif defined(__GNUC__)
#  define __compiler_version__ xtd::version {__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__}
#else
#  define __compiler_version__ xtd::version {}
#endif

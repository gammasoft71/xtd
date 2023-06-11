#pragma once
#if defined(NDEBUG)
#  define __build_type__ xtd::build_type::release
#else
#  define __build_type__ xtd::build_type::debug
#endif


/// @file
/// @brief Contains xtd::u8string alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__string_definitions.h"
#undef __XTD_CORE_INTERNAL__
#include "basic_string.h"

#if defined(__xtd__cpp_lib_char8_t)
/// @todo To be removed when inheriting xtd::object.
template<>
inline std::string xtd::to_string(const xtd::u8string& value, const std::string& fmt, const std::locale& loc) {return value.to_string();}
#endif

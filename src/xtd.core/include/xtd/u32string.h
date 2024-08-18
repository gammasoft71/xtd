/// @file
/// @brief Contains xtd::u32string alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__string_definitions.h"
#undef __XTD_CORE_INTERNAL__
#include "basic_string.h"

/// @todo To be removed when inheriting xtd::object.
template<>
inline std::string xtd::to_string(const xtd::u32string& value, const std::string& fmt, const std::locale& loc) {return value.to_string();}

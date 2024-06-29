/// @file
/// @brief Contains __iformatable_formatter method.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__enum_formatter.h"
#include "../iformatable.h"

/// @cond
template<typename value_t>
static std::string __to_string_polymorphic(const value_t& value, const std::string& fmt, const std::locale& loc, std::true_type) {
  if (dynamic_cast<const xtd::iformatable*>(&value)) return dynamic_cast<const xtd::iformatable&>(value).__opague_internal_formatable__(reinterpret_cast<intptr_t>(&fmt), reinterpret_cast<intptr_t>(&loc), 0, INTPTR_MAX);
  __format_exception("to_string specialisation not found"); return {};
}

template<typename value_t>
static std::string __to_string_polymorphic(const value_t& value, const std::string& fmt, const std::locale& loc, std::false_type) {
  return __to_string_enum(value, fmt, loc, std::is_enum<value_t>());
}
/// @endcond

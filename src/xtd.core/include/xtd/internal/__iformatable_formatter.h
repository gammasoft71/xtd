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
#include "../istringable.h"

/// @cond
namespace xtd {
  class object;
}

std::string __to_string_object_to_string(const xtd::object* obj);
std::string __to_string_istringable_to_string(const xtd::istringable* obj);

template<typename value_t>
static std::string __to_string_polymorphic(const value_t& value, const std::string& fmt, const std::locale& loc, std::true_type) {
  auto value_ptr = &value;
  if (dynamic_cast<const std::exception*>(value_ptr)) return std::string {"exception: "} + dynamic_cast<const std::exception&>(value).what();
  if (dynamic_cast<const xtd::iformatable*>(value_ptr)) return dynamic_cast<const xtd::iformatable&>(value).__opague_internal_formatable__(reinterpret_cast<intptr_t>(&fmt), reinterpret_cast<intptr_t>(&loc), 0, INTPTR_MAX);
  if (dynamic_cast<const xtd::istringable*>(value_ptr)) return __to_string_istringable_to_string(dynamic_cast<const xtd::istringable*>(&value));
  if (dynamic_cast<const xtd::object*>(value_ptr)) return __to_string_object_to_string(dynamic_cast<const xtd::object*>(value_ptr));
  __format_exception(typeid(value)); return {};
}

template<typename value_t>
static std::string __to_string_polymorphic(const value_t& value, const std::string& fmt, const std::locale& loc, std::false_type) {
  return __to_string_enum(value, fmt, loc, std::is_enum<value_t>());
}
/// @endcond

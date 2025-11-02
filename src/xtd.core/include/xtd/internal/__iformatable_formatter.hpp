/// @file
/// @brief Contains __iformatable_formatter method.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__enum_formatter.hpp"
#include "../helpers/throw_helper.hpp"
#include "../iformatable.hpp"
#include "../istringable.hpp"

/// @cond
namespace xtd {
  class object;
}

std::string __to_string_iformatable_to_string(const xtd::iformatable* obj, const std::string& fmt, const std::locale& loc);
std::string __to_string_istringable_to_string(const xtd::istringable* obj);
std::string __to_string_object_to_string(const xtd::object* obj);

template<class value_t>
inline static std::string __to_string_polymorphic(const value_t& value, const std::string& fmt, const std::locale& loc, std::true_type) {
  auto value_ptr = &value;
  if (dynamic_cast<const xtd::iformatable*>(value_ptr)) return __to_string_iformatable_to_string(dynamic_cast<const xtd::iformatable*>(&value), fmt, loc);
  if (dynamic_cast<const xtd::istringable*>(value_ptr)) return __to_string_istringable_to_string(dynamic_cast<const xtd::istringable*>(&value));
  if (dynamic_cast<const xtd::object*>(value_ptr)) return __to_string_object_to_string(dynamic_cast<const xtd::object*>(value_ptr));
  if (dynamic_cast<const std::exception*>(value_ptr)) return std::string {"exception: "} + dynamic_cast<const std::exception&>(value).what();
  xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format_not_iformatable, typeid(value));
}

template<class value_t>
inline static std::string __to_string_polymorphic(const value_t& value, const std::string& fmt, const std::locale& loc, std::false_type) {
  return __to_string_enum(value, fmt, loc, std::is_enum<value_t>());
}
/// @endcond

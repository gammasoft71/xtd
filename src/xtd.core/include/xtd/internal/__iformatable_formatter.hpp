/// @file
/// @brief Contains __iformatable_formatter method.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../helpers/throw_helper.hpp"
#include "../iformatable.hpp"
#include "../istringable.hpp"
#include <type_traits>

/// @cond
namespace xtd {
  class object;
}

std::string __to_string_iformatable_to_string(const xtd::iformatable* obj, const std::string& fmt, const std::locale& loc);
std::string __to_string_istringable_to_string(const xtd::istringable* obj);
std::string __to_string_object_to_string(const xtd::object* obj);

template<class value_t>
inline static std::string __to_string_polymorphic(const value_t& value, const std::string& fmt, const std::locale& loc) {
  if constexpr(std::is_base_of_v<xtd::iformatable, value_t>) return __to_string_iformatable_to_string(static_cast<const xtd::iformatable*>(&value), fmt, loc);
  else if constexpr(std::is_base_of_v<xtd::istringable, value_t>) return __to_string_istringable_to_string(static_cast<const xtd::istringable*>(&value));
  else if constexpr(std::is_base_of_v<xtd::object, value_t>) return __to_string_object_to_string(static_cast<const xtd::object*>(&value));
  else if constexpr(std::is_base_of_v<std::exception, value_t>) return std::string {"exception: "} + static_cast<const std::exception&>(value).what();
  else xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format_not_iformatable, typeid(value));
}
/// @endcond

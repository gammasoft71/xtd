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
#include "../textual.hpp"
#include "../raw_type.hpp"
#include <type_traits>

/// @cond
namespace xtd {
  class object;
}

[[nodiscard]] auto __to_string_iformatable_to_string(const xtd::iformatable* obj, const std::string& fmt, const std::locale& loc) -> std::string;
template<typename type_t>
[[nodiscard]] auto __to_string_istringable_to_string(const xtd::istringable<type_t>* obj) -> std::string;
[[nodiscard]] auto __to_string_object_to_string(const xtd::object* obj) -> std::string;

template<typename value_t>
[[nodiscard]] inline static auto __to_string_polymorphic(const value_t& value, const std::string& fmt, const std::locale& loc) -> std::string {
  if constexpr(std::derived_from<xtd::raw_type<value_t>, xtd::iformatable>) return __to_string_iformatable_to_string(static_cast<const xtd::iformatable*>(&value), fmt, loc);
  else if constexpr(std::derived_from<xtd::raw_type<value_t>, xtd::istringable<xtd::raw_type<value_t>>>) return __to_string_istringable_to_string(static_cast<const xtd::istringable<value_t>*>(&value));
  else if constexpr(std::derived_from<xtd::raw_type<value_t>, xtd::object>) return __to_string_object_to_string(static_cast<const xtd::object*>(&value));
  else if constexpr(std::derived_from<xtd::raw_type<value_t>, std::exception>) return std::string {"exception: "} + static_cast<const std::exception&>(value).what();
  else if constexpr(requires(const xtd::raw_type<value_t>& value, const xtd::string& _fmt) {{value.to_string(_fmt)} -> xtd::textual;}) return value.to_string(fmt);
  else if constexpr(requires(const xtd::raw_type<value_t>& value) {{value.to_string()} -> xtd::textual;}) return value.to_string();
  else xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format_not_iformatable, typeid(value));
}
/// @endcond

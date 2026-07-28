/// @file
/// @brief Contains [C++ Standard format](https://cppreference.com/cpp/utility/format).
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#  include "../raw_type.hpp"
#  include "../string.hpp"
#  include "../textual.hpp"

/// @cond
#include <version>
#if (defined(__cpp_lib_format) && defined(_MSC_VER) && _MSC_VER >= 1932) || (defined(__apple_build_version__) && __apple_build_version__ >= 15000300) || (!defined(__APPLE__) && defined(__GNUC__) && __GNUC__ >= 13) || (!defined(__APPLE__) && defined(__clang_major__) && __clang_major__ >= 15)
#  include <format>
template <class type_t>
requires (std::derived_from<xtd::raw_type<type_t>, xtd::object> ||
          std::derived_from<xtd::raw_type<type_t>, xtd::istringable<xtd::raw_type<type_t>>> ||
          std::derived_from<xtd::raw_type<type_t>, xtd::iformatable> ||
          requires (const xtd::raw_type<type_t>& value) {{value.to_string()} -> xtd::textual;} ||
          requires (const xtd::raw_type<type_t>& value, const xtd::string& fmt) {{value.to_string(fmt)} -> xtd::textual;} ||
          std::derived_from<xtd::raw_type<type_t>, std::exception> ||
          std::is_enum_v<xtd::raw_type<type_t>>
          )
struct std::formatter<type_t> : std::formatter<std::string> {
  template<typename format_context_t>
  constexpr auto parse(format_context_t& ctx) {
    auto iterator = ctx.begin();
    for (; iterator != ctx.end() && *iterator != '}'; ++iterator)
      format_value += *iterator;
    return iterator;
  }
  
  template<typename object_t, typename format_context_t>
  requires (requires (const xtd::raw_type<object_t>& value, const xtd::string& fmt) {{value.to_string(fmt)} -> xtd::textual;})
  constexpr auto format(const object_t& obj, format_context_t& ctx) const {
    return std::format_to(ctx.out(), "{}", obj.to_string(format_value).c_str());
  }
  
  template<typename object_t, typename format_context_t>
  requires (!requires (const xtd::raw_type<object_t>& value, const xtd::string& fmt) {{value.to_string(fmt)} -> xtd::textual;} && requires (const xtd::raw_type<object_t>& value) {{value.to_string()} -> xtd::textual;})
  constexpr auto format(const object_t& obj, format_context_t& ctx) const {
    return std::format_to(ctx.out(), "{}", obj.to_string().c_str());
  }
  
private:
  std::string format_value;
};
#endif
/// @endcond

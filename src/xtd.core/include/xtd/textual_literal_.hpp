/// @file
/// @brief Contains xtd::textual_literal concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/textual_literal> or <xtd/textual_literal.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the textual literal concept.
  /// @par Definition
  /// ```cpp
  /// template<class type_t>
  /// concept xtd::textual_literal = std::same_as<type_t, const xtd::char_*> || std::same_as<type_t, const xtd::wchar*> || std::same_as<type_t, const xtd::char8*> || std::same_as<type_t, const xtd::char16*> || std::same_as<type_t, const xtd::char32*>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/textual_literal>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::textual_literal concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_textual_literal(auto value) noexcept {
  ///   println("{} ({}) {} textual_literal", value, type_of(value), textual_literal<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_textual_literal(42_s8);
  ///   print_is_textual_literal(42_s16);
  ///   print_is_textual_literal(42_s32);
  ///   print_is_textual_literal(42_s64);
  ///   print_is_textual_literal(42_u8);
  ///   print_is_textual_literal(42_u16);
  ///   print_is_textual_literal(42_u32);
  ///   print_is_textual_literal(42_u64);
  ///   print_is_textual_literal(42_z);
  ///   print_is_textual_literal(42.84f);
  ///   print_is_textual_literal(42.84);
  ///   print_is_textual_literal(42.84l);
  ///   print_is_textual_literal('a');
  ///   print_is_textual_literal(true);
  ///   print_is_textual_literal("string"_s);
  ///   print_is_textual_literal("string");
  ///   print_is_textual_literal(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_textual_literal(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not textual_literal
  /// // 42 (short) is not textual_literal
  /// // 42 (int) is not textual_literal
  /// // 42 (long long) is not textual_literal
  /// // 42 (unsigned char) is not textual_literal
  /// // 42 (unsigned short) is not textual_literal
  /// // 42 (unsigned int) is not textual_literal
  /// // 42 (unsigned long long) is not textual_literal
  /// // 42 (unsigned long) is not textual_literal
  /// // 42.84 (float) is not textual_literal
  /// // 42.84 (double) is not textual_literal
  /// // 42.84 (long double) is not textual_literal
  /// // true (bool) is not textual_literal
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not textual_literal
  /// // string (char const*) is textual_literal
  /// // 01:12:24.0480000 (xtd::time_span) is not textual_literal
  /// // wednesday (xtd::day_of_week) is not textual_literal
  /// ```
  template<class type_t>
  struct textual_literal;
}

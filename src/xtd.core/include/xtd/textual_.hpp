/// @file
/// @brief Contains xtd::textual concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/textual> or <xtd/textual.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the textual concept.
  /// @par Definition
  /// ```cpp
  /// template<class value_t>
  /// concept xtd::textual = std::same_as<xtd::raw_type<type_t>, std::string> || std::same_as<xtd::raw_type<type_t>, std::u16string> || std::same_as<xtd::raw_type<type_t>, std::u32string> || std::same_as<xtd::raw_type<type_t>, std::u8string> || std::same_as<xtd::raw_type<type_t>, std::wstring> || std::same_as<xtd::raw_type<type_t>, xtd::string> || std::same_as<xtd::raw_type<type_t>, xtd::u16string> || std::same_as<xtd::raw_type<type_t>, xtd::u32string> || std::same_as<xtd::raw_type<type_t>, xtd::u8string> || std::same_as<xtd::raw_type<type_t>, xtd::wstring> || xtd::textual_literal<type_t>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/textual>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::textual concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_textual(auto value) noexcept {
  ///   println("{} ({}) {} textual", value, type_of(value), textual<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_textual(42_s8);
  ///   print_is_textual(42_s16);
  ///   print_is_textual(42_s32);
  ///   print_is_textual(42_s64);
  ///   print_is_textual(42_u8);
  ///   print_is_textual(42_u16);
  ///   print_is_textual(42_u32);
  ///   print_is_textual(42_u64);
  ///   print_is_textual(42_z);
  ///   print_is_textual(42.84f);
  ///   print_is_textual(42.84);
  ///   print_is_textual(42.84l);
  ///   print_is_textual('a');
  ///   print_is_textual(true);
  ///   print_is_textual("string"_s);
  ///   print_is_textual("string");
  ///   print_is_textual(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_textual(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not textual
  /// // 42 (short) is not textual
  /// // 42 (int) is not textual
  /// // 42 (long long) is not textual
  /// // 42 (unsigned char) is not textual
  /// // 42 (unsigned short) is not textual
  /// // 42 (unsigned int) is not textual
  /// // 42 (unsigned long long) is not textual
  /// // 42 (unsigned long) is not textual
  /// // 42.84 (float) is not textual
  /// // 42.84 (double) is not textual
  /// // 42.84 (long double) is not textual
  /// // true (bool) is not textual
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is textual
  /// // string (char const*) is textual
  /// // 01:12:24.0480000 (xtd::time_span) is not textual
  /// // wednesday (xtd::day_of_week) is not textual
  /// ```
  template<class type_t>
  struct textual;
}

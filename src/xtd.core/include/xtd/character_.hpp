/// @file
/// @brief Contains xtd::character concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/character> or <xtd/character.hpp> instead."

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the character concept.
  /// @par Definition
  /// ```cpp
  /// template<class type_t>
  /// concept xtd::character = std::same_as<xtd::raw_type<type_t>, xtd::char_> || std::same_as<xtd::raw_type<type_t>, xtd::char8> || std::same_as<xtd::raw_type<type_t>, xtd::char16> || std::same_as<xtd::raw_type<type_t>, xtd::char32> || std::same_as<xtd::raw_type<type_t>, xtd::wchar>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/character>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  /// @par Examples
  /// The following code shows how to use xtd::character concept
  /// ```cpp
  /// #include <xtd/xtd>
  ///
  /// auto print_is_character(auto value) noexcept {
  ///   println("{} ({}) {} character", value, type_of(value), character<decltype(value)> ? "is" : "is not");
  /// }
  ///
  /// auto main() -> int {
  ///   print_is_character(42_s8);
  ///   print_is_character(42_s16);
  ///   print_is_character(42_s32);
  ///   print_is_character(42_s64);
  ///   print_is_character(42_u8);
  ///   print_is_character(42_u16);
  ///   print_is_character(42_u32);
  ///   print_is_character(42_u64);
  ///   print_is_character(42_z);
  ///   print_is_character(42.84f);
  ///   print_is_character(42.84);
  ///   print_is_character(42.84l);
  ///   print_is_character('a');
  ///   print_is_character(u'a');
  ///   print_is_character(U'a');
  ///   print_is_character(u8'a');
  ///   print_is_character(L'a');
  ///   print_is_character(true);
  ///   print_is_character("string"_s);
  ///   print_is_character("string");
  ///   print_is_character(1_h + 12_min + 24_s + 48_ms);
  ///   print_is_character(day_of_week::wednesday);
  /// }
  ///
  /// // This code produces the following output :
  /// //
  /// // 42 (signed char) is not character
  /// // 42 (short) is not character
  /// // 42 (int) is not character
  /// // 42 (long long) is not character
  /// // 42 (unsigned char) is not character
  /// // 42 (unsigned short) is not character
  /// // 42 (unsigned int) is not character
  /// // 42 (unsigned long long) is not character
  /// // 42 (unsigned long) is not character
  /// // 42.84 (float) is not character
  /// // 42.84 (double) is not character
  /// // 42.84 (long double) is not character
  /// // a (char) is character
  /// // a (char16_t) is character
  /// // a (char32_t) is character
  /// // a (char8_t) is character
  /// // a (wchar_t) is character
  /// // true (bool) is not character
  /// // string (xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>) is not character
  /// // string (char const*) is not character
  /// // 01:12:24.0480000 (xtd::time_span) is not character
  /// // wednesday (xtd::day_of_week) is not character
  /// ```
  template<class type_t>
  struct character;
}

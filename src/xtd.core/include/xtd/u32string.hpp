/// @file
/// @brief Contains xtd::u32string alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__string_definitions.hpp"
#undef __XTD_CORE_INTERNAL__
#include "basic_string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents text as a sequence of UTF-32 code units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::u32string object is a sequential collection of xtd::char32 that represent a string; a xtd::char32 corresponds to a UTF-32 code unit. The value of the xtd::u32string object is the content of the sequential collection of xtd::char32, and unlike [std::basic_string<char16_t>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::u32string_builder class.
  /// @remarks xtd::u32string implements xtd::basic_string and therefore offers the full (immutable) API of [std::u32string](https://en.cppreference.com/w/cpp/string).
  using u32string = xtd::basic_string<xtd::char32>;
}

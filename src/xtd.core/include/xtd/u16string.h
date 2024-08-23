/// @file
/// @brief Contains xtd::u16string alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__string_definitions.h"
#undef __XTD_CORE_INTERNAL__
#include "basic_string.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents text as a sequence of UTF-16 code units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::u16string object is a sequential collection of xtd::char16 that represent a string; a xtd::char16 corresponds to a UTF-16 code unit. The value of the xtd::u16string object is the content of the sequential collection of xtd::char16, and unlike [std::basic_string<char16_t>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::u16string_builder class.
  /// @remarks xtd::u16string implements xtd::basic_string and therefore offers the full (immutable) API of [std::u16string](https://en.cppreference.com/w/cpp/string).
  using u16string = xtd::basic_string<xtd::char16>;
}

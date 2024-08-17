/// @file
/// @brief Contains xtd::u16string alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
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
  /// @remarks xtd::string implements [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) and therefore offers the full (immutable) API of std::string.
  using u16string = xtd::basic_string<xtd::char16>;
}

/// @todo To be removed when inheriting xtd::object.
template<>
inline std::string xtd::to_string(const xtd::u16string& value, const std::string& fmt, const std::locale& loc) {return value.to_string();}

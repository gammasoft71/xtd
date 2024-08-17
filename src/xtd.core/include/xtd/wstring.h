/// @file
/// @brief Contains xtd::wstring alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "basic_string.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents text as a sequence of UTF-16 code unit on Windows or UTF-32 code unit on non-Windows systems.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::wstring object is a sequential collection of xtd::wchar that represent a string; a xtd::wchar corresponds to a UTF-16 code unit on Windows or UTF-32 code unit on non-Windows systems. The value of the xtd::wstring object is the content of the sequential collection of xtd::wchar, and unlike [std::basic_string<wchar_t>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::wstring_builder class.
  /// @remarks xtd::string implements [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) and therefore offers the full (immutable) API of std::string.
  using wstring = xtd::basic_string<xtd::wchar>;
}

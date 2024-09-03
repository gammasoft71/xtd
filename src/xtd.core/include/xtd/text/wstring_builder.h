/// @file
/// @brief Contains xtd::wstring_builder alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "basic_string_builder.h"
#include "../wchar.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains classes that represent ASCII and Unicode character encodings; abstract base classes for converting blocks of characters to and from blocks of bytes; and a helper class that manipulates and formats xtd::string objects without creating intermediate instances of xtd::string.
  namespace text {
    /// @brief Represents text as a sequence of UTF-16 code unit on Windows or UTF-32 code unit on non-Windows systems.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core system strings
    /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::u32string object is a sequential collection of xtd::char32 that represent a string; a xtd::char32 corresponds to a UTF-32 code unit. The value of the xtd::u32string object is the content of the sequential collection of xtd::char32, and unlike [std::basic_string<char16_t>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
    /// @remarks If you want the same mutable string class, you can use xtd::text::wstring_builder class.
    /// @remarks xtd::u32string implements xtd::basic_string and therefore offers the full (immutable) API of [std::u32string](https://en.cppreference.com/w/cpp/string).
    using wstring_builder = xtd::text::basic_string_builder<xtd::wchar>;
  }
}

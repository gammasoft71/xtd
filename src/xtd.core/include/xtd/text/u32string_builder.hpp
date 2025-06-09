/// @file
/// @brief Contains xtd::text::u32string_builder alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "basic_string_builder.hpp"
#include "../char32.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains classes that represent ASCII and Unicode character encodings; abstract base classes for converting blocks of characters to and from blocks of bytes; and a helper class that manipulates and formats xtd::string objects without creating intermediate instances of xtd::string.
  namespace text {
    /// @brief Represents a mutable string of characters of UTF-32 code units. This class cannot be inherited.
    /// @par Namespace
    /// xtd::text
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core system text strings
    /// @remarks xtd::text::u32string_builder class represents a string-like object whose value is a mutable sequence of characters.
    /// @remarks xtd::text::u32string_builder implements [std::u32string](https://en.cppreference.com/w/cpp/string/basic_string) and therefore offers the full API of [std::u32string](https://en.cppreference.com/w/cpp/string/basic_string).
    using u32string_builder = xtd::text::basic_string_builder<xtd::char32>;
  }
}

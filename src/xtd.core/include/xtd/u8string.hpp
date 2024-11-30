/// @file
/// @brief Contains xtd::u8string alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__string_definitions.hpp"
#undef __XTD_CORE_INTERNAL__
#include "basic_string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Represents text as a sequence of UTF-8 code units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::u8string object is a sequential collection of xtd::char8 that represent a string; a xtd::char8 corresponds to a UTF-8 code unit. The value of the xtd::u8string object is the content of the sequential collection of xtd::char8, and unlike [std::basic_string<char8_t>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::u8string_builder class.
  /// @remarks xtd::u8string implements xtd::basic_string and therefore offers the full (immutable) API of [std::u8string](https://en.cppreference.com/w/cpp/string).
  using u8string = xtd::basic_string<xtd::char8>;
#endif
}

/// @file
/// @brief Contains xtd::ustring class.
#pragma once
/// @cond
#if defined(_MSC_VER) && __cplusplus < 202302L
#  pragma message("Deprecated : Replaced by #include <xtd/ustring.h> - Will be removed in version 0.4.0")
#else
#  warning "Deprecated : Replaced by #include <xtd/ustring.h> - Will be removed in version 0.4.0"
#endif
#include "string.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents text as a sequence of UTF-8 code units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::ustring object is a sequential collection of char that represent a string; a char corresponds to a UTF-8 code unit. The value of the xtd::ustring object is the content of the sequential collection of char, and unlike [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::ustring_builder class.
  /// @remarks xtd::ustring is inherited from [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) and therefore offers the full (immutable) API of std::string.
  /// @remarks xtd::ustring cannot inherit from xtd::iequatable <xtd::ustring> because [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) defines the [== and != operators](https://en.cppreference.com/w/cpp/string/basic_string/operator_cmp).
  /// @todo replace all `class::ustring;` definitions by `class xtd::string;` when switching class `xtd::ustring` an alias `xtd::string` to class `xtd::string` and alias `xtd::ustring`
  /// @deprecated Replaced by xtd::string - Will be removed in version 0.4.0
  //using ustring [[deprecated("Replaced by xtd::string - Will be removed in version 0.4.0")]] = xtd::string;
}

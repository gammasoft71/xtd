/// @file
/// @brief Contains xtd::forms::dot_matrix_style enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent dot matrix style used by dot_matrix_display control.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
  enum class dot_matrix_style {
    /// @brief Round dot matrix style.
    round,
    /// @brief Square dot matrix style.
    square,
    /// @brief Standard (or round) dot matrix style.
    standard = round,
  };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, dot_matrix_style value) {return os << to_string(value, {{dot_matrix_style::standard, "standard"}, {dot_matrix_style::square, "square"}});}
    inline std::wostream& operator<<(std::wostream& os, dot_matrix_style value) {return os << to_string(value, {{dot_matrix_style::standard, L"standard"}, {dot_matrix_style::square, L"square"}});}
    /// @endcond
  }
}

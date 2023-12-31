/// @file
/// @brief Contains xtd::forms::dot_matrix_style enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent dot matrix style used by dot_matrix_display control.
    /// @par Header
    /// @code #include <xtd/forms/dot_matrix_style> @endcode
    /// @par Namespace
    /// xtd::forms
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
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::dot_matrix_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::dot_matrix_style> {{xtd::forms::dot_matrix_style::standard, "standard"}, {xtd::forms::dot_matrix_style::square, "square"}};}
};
/// @endcond

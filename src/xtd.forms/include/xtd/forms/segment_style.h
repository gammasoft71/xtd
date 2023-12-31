/// @file
/// @brief Contains xtd::forms::segment_style enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent segment style used by seven_segment_display, fourteen_segment_display, nine_segment_display and sixteen_segment_display controls.
    /// @par Header
    /// @code #include <xtd/forms/segment_style> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class segment_style {
      /// @brief Standard segment style.
      standard,
      /// @brief Modern segment style.
      modern,
      /// @brief Mixed (mix between standard and modern) segment style.
      mixed,
      /// @brief Expanded segment style.
      expanded,
      /// @brief Design segment style.
      design,
      /// @brief Stick segment style.
      stick,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::segment_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::segment_style> {{xtd::forms::segment_style::standard, "standard"}, {xtd::forms::segment_style::modern, "modern"}, {xtd::forms::segment_style::mixed, "mixed"}, {xtd::forms::segment_style::expanded, "expanded"}, {xtd::forms::segment_style::design, "design"}, {xtd::forms::segment_style::stick, "stick"}};}
};
/// @endcond

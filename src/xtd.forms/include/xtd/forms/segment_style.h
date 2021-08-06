/// @file
/// @brief Contains xtd::forms::segment_style enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent segment style used by seven_segment_display, fortheen_segment_display, nine_segment_display and sixtheen_segment_display controls.
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

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, segment_style value) {return os << to_string(value, {{segment_style::standard, "standard"}, {segment_style::modern, "modern"}, {segment_style::mixed, "mixed"}, {segment_style::expanded, "expanded"}, {segment_style::design, "design"}, {segment_style::stick, "stick"}});}
    inline std::wostream& operator<<(std::wostream& os, segment_style value) {return os << to_string(value, {{segment_style::standard, L"standard"}, {segment_style::modern, L"modern"}, {segment_style::mixed, L"mixed"}, {segment_style::expanded, L"expanded"}, {segment_style::design, L"design"}, {segment_style::stick, L"stick"}});}
    /// @endcond
  }
}

/// @file
/// @brief Contains xtd::forms::tab_alignment enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the locations of the tabs in a tab control.
    /// @par Header
    /// @code #include <xtd/forms/tab_alignment> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by members such as tab_control::alignment.
    enum class tab_alignment {
      /// @brief The tabs are located across the top of the control.
      top = 0,
      /// @brief The tabs are located across the bottom of the control.
      bottom = 1,
      /// @brief The tabs are located along the left edge of the control.
      left = 2,
      /// @brief The tabs are located along the right edge of the control.
      right = 3,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::tab_alignment> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::tab_alignment> {{xtd::forms::tab_alignment::top, "top"}, {xtd::forms::tab_alignment::bottom, "bottom"}, {xtd::forms::tab_alignment::left, "left"}, {xtd::forms::tab_alignment::right, "right"}};}
};
/// @endcond

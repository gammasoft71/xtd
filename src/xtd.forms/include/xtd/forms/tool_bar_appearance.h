/// @file
/// @brief Contains xtd::forms::tool_bar_appearance enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the type of toolbar to display.
    /// @par Header
    /// @code #include <xtd/forms/tool_bar_appearance> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by members such as xtd::forms:tool_bar::appearance.
    /// @remarks Set the xtd::forms:tool_bar::appearance property of the toolbar to xtd::forms:tool_bar_appearance::flat to give the toolbar and its buttons a flat appearance. As the mouse pointer moves over the buttons, their appearance changes to three-dimensional. Button separators appear as lines rather than spaces between the buttons when the toolbar has a flat appearance.
    enum class tool_bar_appearance {
      /// @brief The toolbar and buttons appear flat, but the buttons change to three-dimensional as the mouse pointer moves over them.
      normal = 0,
      /// @brief The toolbar and buttons appear as standard three-dimensional controls.
      flat = 1,
      /// @brief The toolbar and buttons appear as system controls.
      system = 2,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::tool_bar_appearance> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::tool_bar_appearance> {{xtd::forms::tool_bar_appearance::normal, "normal"}, {xtd::forms::tool_bar_appearance::flat, "flat"}, {xtd::forms::tool_bar_appearance::system, "system"}};}
};
/// @endcond

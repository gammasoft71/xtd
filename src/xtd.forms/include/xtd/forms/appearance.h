/// @file
/// @brief Contains xtd::forms::appearance enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the appearance of a control.
    /// @par Header
    /// @code #include <xtd/forms/appearance> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration in controls that provide the Appearance property to set its value.
    enum class appearance {
      /// @brief The default appearance defined by the control class.
      normal = 0,
      /// @brief The appearance of a button.
      button = 1,
      /// @brief The appearance of a switch button.
      switch_button = 2,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::appearance> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::appearance> {{xtd::forms::appearance::normal, "normal"}, {xtd::forms::appearance::button, "button"}, {xtd::forms::appearance::switch_button, "switch_button"}};}
};
/// @endcond

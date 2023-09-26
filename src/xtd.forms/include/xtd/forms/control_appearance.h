/// @file
/// @brief Contains xtd::forms::control_appearance enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the appearance of a control.
    /// @par Header
    /// @code #include <xtd/forms/control_appearance> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class control_appearance {
      /// @brief The appearance of the control is determined by current theme of xtd.
      standard = 0,
      /// @brief The appearance of the control is determined by the user's operating system.
      system,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::control_appearance> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::control_appearance> {{xtd::forms::control_appearance::standard, "standard"}, {xtd::forms::control_appearance::system, "system"}};}
};
/// @endcond

/// @file
/// @brief Contains xtd::forms::link_behavior enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the behaviors of a link in a xtd::forms::link_label.
    /// @par Header
    /// @code #include <xtd/forms/link_behavior> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration to set the value of the xtd::forms::link_label::link_behavior property of the xtd::forms::link_label.
    enum class link_behavior {
      /// @brief The behavior of this setting depends on the options set using the Internet Options dialog box in Control Panel or Internet Explorer.
      system_default,
      /// @brief The link always displays with underlined text.
      always_underline,
      /// @brief The link displays underlined text only when the mouse is hovered over the link text.
      hover_underline,
      /// @brief The link text is never underlined. The link can still be distinguished from other text by use of the xtd::forms::link_label::link_color property of the xtd::forms::link_label control.
      never_underline,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::link_behavior> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::link_behavior> {{xtd::forms::link_behavior::system_default, "system_default"}, {xtd::forms::link_behavior::always_underline, "always_underline"}, {xtd::forms::link_behavior::hover_underline, "hover_underline"}, {xtd::forms::link_behavior::never_underline, "never_underline"}};}
};
/// @endcond

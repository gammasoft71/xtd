/// @file
/// @brief Contains xtd::forms::message_dialog_default_button enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants defining the default button on a message_box.
    /// @par Header
    /// @code #include <xtd/forms/message_dialog_default_button> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the message_box class.
    enum class message_dialog_default_button {
      /// @brief The first button on the message box is the default button.
      button1 = 0,
      /// @brief The second button on the message box is the default button.
      button2 = 0x00000100L,
      /// @brief The third button on the message box is the default button.
      button3 = 0x00000200L
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::message_dialog_default_button> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::message_dialog_default_button> {{xtd::forms::message_dialog_default_button::button1, "button1"}, {xtd::forms::message_dialog_default_button::button2, "button2"}, {xtd::forms::message_dialog_default_button::button3, "button3"}};}
};
/// @endcond

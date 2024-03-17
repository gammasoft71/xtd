/// @file
/// @brief Contains xtd::forms::message_dialog_icon enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants defining which information to display.
    /// @par Header
    /// @code #include <xtd/forms/message_dialog_icon> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the message_box class. The description of each member of this enumeration contains a typical representation of the symbol. The actual graphic displayed is a function of the operating system constants. In current implementations there are four unique symbols with multiple values assigned to them.
    enum class message_dialog_icon {
      /// @brief The message box contain no symbols.
      none = 0,
      /// @brief The message box contains a symbol consisting of white X in a circle with a red background.
      error = 0x00000010L,
      /// @brief The message box contains a symbol consisting of a question mark in a circle. The question-mark message icon is no longer recommended because it does not clearly represent a specific type of message and because the phrasing of a message as a question could apply to any message type. In addition, users can confuse the message symbol question mark with Help information. Therefore, do not use this question mark message symbol in your message boxes. The system continues to support its inclusion only for backward compatibility.
      question = 0x00000020L,
      /// @brief The message box contains a symbol consisting of an exclamation point in a triangle with a yellow background.
      warning = 0x00000030L,
      /// @brief The message box contains a symbol consisting of a lowercase letter i in a circle.
      information = 0x00000040L,
      /// @brief The message box contains a symbol consisting of a white X in a circle with a red background.
      hand = error,
      /// @brief The message box contains a symbol consisting of white X in a circle with a red background.
      stop = error,
      /// @brief The message box contains a symbol consisting of an exclamation point in a triangle with a yellow background.
      exclamation = warning,
      /// @brief The message box contains a symbol consisting of a lowercase letter i in a circle.
      asterisk = information,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::message_dialog_icon> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::message_dialog_icon> {{xtd::forms::message_dialog_icon::none, "none"}, {xtd::forms::message_dialog_icon::error, "error"}, {xtd::forms::message_dialog_icon::question, "question"}, {xtd::forms::message_dialog_icon::warning, "warning"}, {xtd::forms::message_dialog_icon::information, "information"}, {xtd::forms::message_dialog_icon::hand, "hand"}, {xtd::forms::message_dialog_icon::stop, "stop"}, {xtd::forms::message_dialog_icon::exclamation, "exclamation"}, {xtd::forms::message_dialog_icon::asterisk, "asterisk"}};}};
/// @endcond

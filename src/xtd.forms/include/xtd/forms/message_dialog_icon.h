/// @file
/// @brief Contains xtd::forms::message_dialog_icon enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants defining which information to display.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the message_box class. The description of each member of this enumeration contains a typical representation of the symbol. The actual graphic displayed is a function of the operating system constants. In current implementations there are four unique symbols with multiple values assigned to them.
    enum class message_dialog_icon {
      /// @brief The message box contain no symbols.
      none = 0,
      /// @brief The message box contains a symbol consisting of a white X in a circle with a red background.
      hand = 0x00000010L,
      /// @brief The message box contains a symbol consisting of white X in a circle with a red background.
      stop = 0x00000010L,
      /// @brief The message box contains a symbol consisting of white X in a circle with a red background.
      error = 0x00000010L,
      /// @brief The message box contains a symbol consisting of a question mark in a circle. The question-mark message icon is no longer recommended because it does not clearly represent a specific type of message and because the phrasing of a message as a question could apply to any message type. In addition, users can confuse the message symbol question mark with Help information. Therefore, do not use this question mark message symbol in your message boxes. The system continues to support its inclusion only for backward compatibility.
      question = 0x00000020L,
      /// @brief The message box contains a symbol consisting of an exclamation point in a triangle with a yellow background.
      exclamation = 0x00000030L,
      /// @brief The message box contains a symbol consisting of an exclamation point in a triangle with a yellow background.
      warning = 0x00000030L,
      /// @brief The message box contains a symbol consisting of a lowercase letter i in a circle.
      asterisk = 0x00000040L,
      /// @brief The message box contains a symbol consisting of a lowercase letter i in a circle.
      information = 0x00000040L,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, message_dialog_icon value) {return os << to_string(value, {{message_dialog_icon::none, "none"}, {message_dialog_icon::hand, "hand"}, {message_dialog_icon::stop, "stop"}, {message_dialog_icon::error, "error"}, {message_dialog_icon::question, "question"}, {message_dialog_icon::exclamation, "exclamation"}, {message_dialog_icon::warning, "warning"}, {message_dialog_icon::asterisk, "asterisk"}, {message_dialog_icon::information, "information"}});}
    inline std::wostream& operator<<(std::wostream& os, message_dialog_icon value) {return os << to_string(value, {{message_dialog_icon::none, L"none"}, {message_dialog_icon::hand, L"hand"}, {message_dialog_icon::stop, L"stop"}, {message_dialog_icon::error, L"error"}, {message_dialog_icon::question, L"question"}, {message_dialog_icon::exclamation, L"exclamation"}, {message_dialog_icon::warning, L"warning"}, {message_dialog_icon::asterisk, L"asterisk"}, {message_dialog_icon::information, L"information"}});}
    /// @endcond
  }
}

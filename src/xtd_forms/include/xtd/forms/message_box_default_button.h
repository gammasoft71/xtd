#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants defining the default button on a message_box.
    /// @remarks This enumeration is used by the message_box class.
    enum class message_box_default_button {
      /// @brief The first button on the message box is the default button.
      button1 = 0,
      /// @brief The second button on the message box is the default button.
      button2 = 0x00000100L,
      /// @brief The third button on the message box is the default button.
      button3 = 0x00000200L
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, message_box_default_button value) {return os << to_string(value, {{message_box_default_button::button1, "button1"}, {message_box_default_button::button2, "button2"}, {message_box_default_button::button3, "button3"}});}
    inline std::wostream& operator<<(std::wostream& os, message_box_default_button value) {return os << to_string(value, {{message_box_default_button::button1, L"button1"}, {message_box_default_button::button2, L"button2"}, {message_box_default_button::button3, L"button3"}});}
    /// @endcond
  }
}

/// @file
/// @brief Contains xtd::forms::message_dialog_options enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies options on a message_box.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
    /// @remarks This enumeration is used by the MessageBox class.
    /// @remarks If you do not want to specify this parameter when calling methods on MessageBox, you can pass in 0 instead.
    enum class message_dialog_options {
      /// @brief The message box is displayed on the active desktop.
      default_desktop_only = 0x00020000L,
      /// @brief The message box text is right-aligned.
      right_align = 0x00080000L,
      /// @brief Specifies that the message box text is displayed with right to left reading order.
      rtl_reading = 0x00100000L,
      /// @brief The message box is displayed on the active desktop.
      service_notification = 0x00200000L
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, message_dialog_options value) {return os << to_string(value, {{message_dialog_options::default_desktop_only, "default_desktop_only"}, {message_dialog_options::right_align, "right_align"}, {message_dialog_options::rtl_reading, "rtl_reading"}, {message_dialog_options::service_notification, "service_notification"}});}
    inline std::wostream& operator<<(std::wostream& os, message_dialog_options value) {return os << to_string(value, {{message_dialog_options::default_desktop_only, L"default_desktop_only"}, {message_dialog_options::right_align, L"right_align"}, {message_dialog_options::rtl_reading, L"rtl_reading"}, {message_dialog_options::service_notification, L"service_notification"}});}
    /// @endcond
  }
}

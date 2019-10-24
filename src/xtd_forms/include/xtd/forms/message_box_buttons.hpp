#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants defining which buttons to display on a message_box.
    /// @remarks This enumeration is used by the message_box class.
    enum class message_box_buttons {
      /// @brief The message box contains an OK button.
      ok = 0,
      /// @brief The message box contains OK and Cancel buttons.
      ok_cancel = 1,
      /// &brief The message box contains Abort, Retry, and Ignore buttons
      abort_retry_ignore = 2,
      /// @brief The message box contains Yes, No, and Cancel buttons.
      yes_no_cancel = 3,
      /// @brief The message box contains Yes and No buttons.
      yes_no = 4,
      /// @brief The message box contains Retry and Cancel buttons.
      retry_cancel = 5
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, message_box_buttons value) {return os << to_string(value, {{message_box_buttons::ok, "ok"}, {message_box_buttons::ok_cancel, "ok_cancel"}, {message_box_buttons::abort_retry_ignore, "abort_retry_ignore"}, {message_box_buttons::yes_no_cancel, "yes_no_cancel"}, {message_box_buttons::yes_no, "yes_no"}, {message_box_buttons::retry_cancel, "retry_cancel"}});}
    inline std::wostream& operator<<(std::wostream& os, message_box_buttons value) {return os << to_string(value, {{message_box_buttons::ok, L"ok"}, {message_box_buttons::ok_cancel, L"ok_cancel"}, {message_box_buttons::abort_retry_ignore, L"abort_retry_ignore"}, {message_box_buttons::yes_no_cancel, L"yes_no_cancel"}, {message_box_buttons::yes_no, L"yes_no"}, {message_box_buttons::retry_cancel, L"retry_cancel"}});}
    /// @endcond
  }
}

/// @file
/// @brief Contains xtd::forms::message_dialog_buttons enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants defining which buttons to display on a message_box.
    /// @par Header
    /// @code #include <xtd/forms/message_dialog_buttons> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the message_box class.
    enum class message_dialog_buttons {
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
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::message_dialog_buttons> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::message_dialog_buttons> {{xtd::forms::message_dialog_buttons::ok, "ok"}, {xtd::forms::message_dialog_buttons::ok_cancel, "ok_cancel"}, {xtd::forms::message_dialog_buttons::abort_retry_ignore, "abort_retry_ignore"}, {xtd::forms::message_dialog_buttons::yes_no_cancel, "yes_no_cancel"}, {xtd::forms::message_dialog_buttons::yes_no, "yes_no"}, {xtd::forms::message_dialog_buttons::retry_cancel, "retry_cancel"}};}
};
/// @endcond

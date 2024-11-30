/// @file
/// @brief Contains xtd::forms::close_reason enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the reason that a form was closed.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/close_reason>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks The form_closing and form_closed events are raised when a form is closed, either through user action or programmatically. Handlers for these events receive parameters of type form_closing_event_args and form_closed_event_args, respectively. Both of these event argument classes use the close_reason enumeration.
    enum class close_reason {
      /// @brief The cause of the closure was not defined or could not be determined.
      none = 0,
      /// @brief The operating system is closing all applications before shutting down.
      windows_shut_down = 1,
      /// @brief The parent form of this multiple document interface (MDI) form is closing.
      mdi_form_closing = 2,
      /// @brief The user is closing the form through the user interface (UI), for example by clicking the Close button on the form window, selecting Close from the window's control menu, or pressing ALT+F4.
      user_closing = 3,
      /// @brief The Microsoft Windows Task Manager is closing the application.
      task_manager_closing = 4,
      /// @brief The owner form is closing.
      form_owner_closing = 5,
      /// @brief The Exit method of the Application class was invoked.
      application_exit_call = 6
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::close_reason> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::close_reason> {{xtd::forms::close_reason::none, "none"}, {xtd::forms::close_reason::windows_shut_down, "windows_shut_down"}, {xtd::forms::close_reason::mdi_form_closing, "mdi_form_closing"}, {xtd::forms::close_reason::user_closing, "user_closing"}, {xtd::forms::close_reason::task_manager_closing, "task_manager_closing"}, {xtd::forms::close_reason::form_owner_closing, "form_owner_closing"}, {xtd::forms::close_reason::application_exit_call, "application_exit_call"}};}
};
/// @endcond

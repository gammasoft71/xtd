#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the reason that a form was closed.
    /// @remarks The FormClosing and FormClosed events are raised when a Form is closed, either through user action or programmatically. Handlers for these events receive parameters of type FormClosingEventArgs and FormClosedEventArgs, respectively. Both of these event argument classes use the CloseReason enumeration.
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

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, close_reason value) {return os << to_string(value, {{close_reason::none, "none"}, {close_reason::windows_shut_down, "windows_shut_down"}, {close_reason::mdi_form_closing, "mdi_form_closing"}, {close_reason::user_closing, "user_closing"}, {close_reason::task_manager_closing, "task_manager_closing"}, {close_reason::form_owner_closing, "form_owner_closing"}, {close_reason::application_exit_call, "application_exit_call"}});}
    inline std::wostream& operator<<(std::wostream& os, close_reason value) {return os << to_string(value, {{close_reason::none, L"none"}, {close_reason::windows_shut_down, L"windows_shut_down"}, {close_reason::mdi_form_closing, L"mdi_form_closing"}, {close_reason::user_closing, L"user_closing"}, {close_reason::task_manager_closing, L"task_manager_closing"}, {close_reason::form_owner_closing, L"form_owner_closing"}, {close_reason::application_exit_call, L"application_exit_call"}});}
    /// @endcond
  }
}

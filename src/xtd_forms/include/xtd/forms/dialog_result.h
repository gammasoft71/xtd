#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies identifiers to indicate the return value of a dialog box.
    /// @remarks The Button.DialogResult property and the form.show_dialog method use this enumeration.
    /// @par Examples
    /// The following code example demonstrates how to display a MessageBox with the options supported by this overload of Show. After verifying that a string variable, ServerName, is empty, the example displays a MessageBox, offering the user the option to cancel the operation. If the Show method's return value evaluates to Yes, the form that displayed the MessageBox is closed.
    /// @code
    /// void validate_user_entry() {
    ///   // Checks the value of the text.
    ///   if (server_name.text().size() == 0) {
    ///     // Initializes the variables to pass to the MessageBox.Show method.
    ///     string message = "You did not enter a server name. Cancel this operation?";
    ///     string caption = "No Server Name Specified";
    ///     message_box_buttons buttons = message_box_buttons::yes_no;
    ///     dialog_result result;
    ///
    ///     // Displays the MessageBox.
    ///     result = message_box::show(*this, message, caption, buttons);
    ///     if (result == dialog_result::yes) {
    ///       // Closes the parent form.
    ///       this->close();
    ///     }
    ///   }
    /// }
    /// @endcode
    enum class dialog_result {
      /// @brief Nothing is returned from the dialog box. This means that the modal dialog continues running.
      none = 0,
      /// @brief The dialog box return value is OK (usually sent from a button labeled OK).
      ok = 1,
      /// @brief The dialog box return value is Cancel (usually sent from a button labeled Cancel).
      cancel = 2,
      /// @brief The dialog box return value is Abort (usually sent from a button labeled Abort).
      abort = 3,
      /// @brief The dialog box return value is Retry (usually sent from a button labeled Retry).
      retry = 4,
      /// @brief The dialog box return value is Ignore (usually sent from a button labeled Ignore).
      ignore = 5,
      /// @brief The dialog box return value is Yes (usually sent from a button labeled Yes).
      yes = 6,
      /// @brief The dialog box return value is No (usually sent from a button labeled No).
      no = 7
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, dialog_result value) {return os << to_string(value, {{dialog_result::none, "none"}, {dialog_result::ok, "ok"}, {dialog_result::cancel, "cancel"}, {dialog_result::abort, "abort"}, {dialog_result::retry, "retry"}, {dialog_result::ignore, "ignore"}, {dialog_result::yes, "yes"}, {dialog_result::no, "no"}});}
    inline std::wostream& operator<<(std::wostream& os, dialog_result value) {return os << to_string(value, {{dialog_result::none, L"none"}, {dialog_result::ok, L"ok"}, {dialog_result::cancel, L"cancel"}, {dialog_result::abort, L"abort"}, {dialog_result::retry, L"retry"}, {dialog_result::ignore, L"ignore"}, {dialog_result::yes, L"yes"}, {dialog_result::no, L"no"}});}
    /// @endcond
  }
}

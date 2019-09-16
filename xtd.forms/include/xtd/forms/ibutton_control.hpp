#pragma once
#include "control.hpp"
#include "dialog_result.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Allows a control to act like a button on a form.
    /// @remarks An example of where this interface might be implemented is default and cancel button processing. Default buttons are notified when an unprocessed ENTER key is entered for a form, just like a dialog box would be closed. Similarly, cancel buttons are notified whenever an unprocessed ESC key is entered on a form, much like a dialog box would be dismissed.
    class ibutton_control  {
    public:
      /// @brief Gets the value returned to the parent form when the button is clicked.
      /// @return One of the DialogResult values.
      /// @remarks When a form is shown as a dialog box using the show_dialog method and one of its buttons is clicked, the button's dialog_result value is assigned to the form's dialog_result property.
      virtual forms::dialog_result dialog_result() const = 0;
      /// @brief Sets the value returned to the parent form when the button is clicked.
      /// @param dialog_result One of the DialogResult values.
      /// @remarks When a form is shown as a dialog box using the show_dialog method and one of its buttons is clicked, the button's dialog_result value is assigned to the form's dialog_result property.
      virtual ibutton_control& dialog_result(forms::dialog_result dialog_result) = 0;

      /// @cond
      virtual ~ibutton_control() = default;
      /// @endcond
    };
  }
}

/// @file
/// @brief Contains xtd::forms::ibutton_control interface.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/interface.h>
#include "control.h"
#include "dialog_result.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Allows a control to act like a button on a form.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms interfaces
    /// @remarks An example of where this interface might be implemented is default and cancel button processing. Default buttons are notified when an unprocessed ENTER key is entered for a form, just like a dialog box would be closed. Similarly, cancel buttons are notified whenever an unprocessed ESC key is entered on a form, much like a dialog box would be dismissed.
    /// @par Notes to implementers
    /// Implement this interface in classes that act as button controls. The members of this interface will provide basic button functionality, such as providing a dialog_result to the parent form or the ability to perform a click event, or acting as the default button of a form.
    class ibutton_control interface_  {
    public:
      /// @brief Gets the value returned to the parent form when the button is clicked.
      /// @return One of the DialogResult values.
      /// @remarks When a form is shown as a dialog box using the show_dialog method and one of its buttons is clicked, the button's dialog_result value is assigned to the form's dialog_result property.
      virtual forms::dialog_result dialog_result() const = 0;
      /// @brief Sets the value returned to the parent form when the button is clicked.
      /// @param dialog_result One of the DialogResult values.
      /// @remarks When a form is shown as a dialog box using the show_dialog method and one of its buttons is clicked, the button's dialog_result value is assigned to the form's dialog_result property.
      virtual control& dialog_result(forms::dialog_result dialog_result) = 0;

      /// @brief Notifies a control that it is the default button so that its appearance and behavior is adjusted accordingly.
      /// @param value true if the control should behave as a default button; otherwise false.
      /// @remarks This method is called by a parent form to make a control the default button. Default buttons are set to have an extra thick border.
      virtual void notify_default(bool value) = 0;

      /// @brief Generates a click event for the control.
      /// @remarks This method is called for the button that has focus, or for the default button (if no other button has focus) when the user presses the ENTER key. This method is also called when the user presses the ESC key if the button is set as the cancel button.
      virtual void perform_click() = 0;
    };
  }
}

#pragma once
#include "button_base.hpp"
#include "dialog_result.hpp"
#include "ibutton_control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows button control.
    /// @remarks A Button can be clicked by using the mouse, ENTER key, or SPACEBAR if the button has focus.
    /// @remarks Set the accept_button or cancel_button property of a form to allow users to click a button by pressing the ENTER or ESC keys even if the button does not have focus. This gives the form the behavior of a dialog box.
    /// @remarks When you display a form using the show_dialog method, you can use the dialog_result property of a button to specify the return value of show_dialog.
    /// @remarks You can change the button's appearance. For example, to make it appear flat for a Web look, set the flat_style property to flat_style::flat. The flat_style property can also be set to flat_style::popup, which appears flat until the mouse pointer passes over the button; then the button takes on the standard Windows button appearance.
    /// @note If the control that has focus accepts and processes the ENTER key press, the button does not process it. For example, if a multiline text_box or another button has focus, that control processes the ENTER key press instead of the accept button.
    /// @par Example
    /// The following code example demonstrate the use of button control.
    /// @include button.cpp
    class button : public ibutton_control, public button_base {
    public:
      /// @brief Initializes a new instance of the Button class.
      /// @remarks By default the button displays no caption. To specify the caption text, set the text property.
      button() = default;

      /// @brief Gets the mode by which the button automatically resizes itself.
      /// @return One of the AutoSizeMode values. The default value is grow_only.
      virtual forms::auto_size_mode auto_size_mode() const {return this->auto_size_mode_;}
      /// @brief Sets the mode by which the button automatically resizes itself.
      /// @param value One of the AutoSizeMode values. The default value is growonly.
      virtual button& auto_size_mode(forms::auto_size_mode value);

      /// @brief Gets the value returned to the parent form when the button is clicked.
      /// @return One of the DialogResult values.
      /// @remarks When a form is shown as a dialog box using the show_dialog method and one of its buttons is clicked, the button's dialog_result value is assigned to the form's dialog_result property.
      forms::dialog_result dialog_result() const override {return this->dialog_result_;}
      /// @brief Sets the value returned to the parent form when the button is clicked.
      /// @param dialog_result One of the DialogResult values.
      /// @remarks When a form is shown as a dialog box using the show_dialog method and one of its buttons is clicked, the button's dialog_result value is assigned to the form's dialog_result property.
      control& dialog_result(forms::dialog_result dialog_result) override;

      /// @brief Notifies a control that it is the default button so that its appearance and behavior is adjusted accordingly.
      /// @param value true if the control should behave as a default button; otherwise false.
      /// @remarks This method is called by a parent form to make a control the default button. Default buttons are set to have an extra thick border.
      void notify_default(bool value) override;

      /// @brief Generates a click event for the control.
      /// @remarks This method is called for the button that has focus, or for the default button (if no other button has focus) when the user presses the ENTER key. This method is also called when the user presses the ESC key if the button is set as the cancel button.
      void perform_click() override;

    protected:
      /// @brief Gets a create_params on the base class when creating a window.
      /// @return A create_params object on the base class when creating a window.
      /// @remarks Inheriting classes can override this property to add extra functionality, but must first call the create_params constructor on the base class to verify that the control continues to work correctly.
      forms::create_params create_params() const override;
      
      /// @brief Raises the Click event.
      /// @param e An event_args that contains the event data.
      void on_click(const event_args& e) override;

      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd°proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;
      
      /// @cond
      forms::dialog_result dialog_result_ = forms::dialog_result::none;
      /// @endcond

    private:
      void wm_click(message& message);
      void wm_mouse_up(message& message);
   };
  }
}

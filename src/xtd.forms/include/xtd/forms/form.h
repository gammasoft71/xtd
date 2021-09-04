/// @file
/// @brief Contains xtd::forms::form container.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>
#include <xtd/drawing/icon.h>
#include <xtd/io/path.h>
#include "form_border_style.h"
#include "form_closed_event_handler.h"
#include "form_closing_event_handler.h"
#include "form_start_position.h"
#include "form_window_state.h"
#include "container_control.h"
#include "dialog_result.h"
#include "ibutton_control.h"
#include "main_menu.h"
#include "screen.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class application;
    class application_context;
    /// @endcond
    
    /// @brief Represents a window or dialog box that makes up an application's user interface.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms forms
    /// @remarks A form is a representation of any window displayed in your application. The Form class can be used to create standard, tool, borderless, and floating windows. You can also use the form class to create modal windows such as a dialog box. A special kind of form, the multiple-document interface (MDI) form, can contain other forms called MDI child forms. An MDI form is created by setting the is_mdi_container property to true. MDI child forms are created by setting the mdi_parent property to the MDI parent form that will contain the child form.
    /// @remarks Using the properties available in the form class, you can determine the appearance, size, color, and window management features of the window or dialog box you are creating. The text property allows you to specify the caption of the window in the title bar. The size and desktop_location properties allow you to define the size and position of the window when it is displayed. You can use the fore_color color property to change the default foreground color of all controls placed on the form. The form_border_style, minimize_box, and maximize_box properties allow you to control whether the form can be minimized, maximized, or resized at run time.
    /// @remarks In addition to properties, you can use the methods of the class to manipulate a form. For example, you can use the show_dialog method to show a form as a modal dialog box. You can use the set_desktop_location method to position the form on the desktop.
    /// @par Examples
    /// The following code example demonstrate the use of form control.
    /// @include form.cpp
    class forms_export_ form : public container_control {
    public:
      /// @brief Initializes a new instance of the Form class.
      /// @remarks The default size of a form is 300 pixels in height and 300 pixels in width.
      form();

      /// @brief Gets the button on the form that is clicked when the user presses the ENTER key.
      /// @return An ibutton_control that represents the button to use as the accept button for the form.
      std::optional<std::reference_wrapper<ibutton_control>> accept_button() const {return accept_button_;}
      /// @brief Sets the button on the form that is clicked when the user presses the ENTER key.
      /// @param value An ibutton_control that represents the button to use as the accept button for the form.
      /// @return Current form.
      form& accept_button(const ibutton_control& value);
      /// @brief Sets the button on the form that is clicked when the user presses the ENTER key.
      /// @param value An ibutton_control that represents the button to use as the accept button for the form.
      /// @return Current form.
      form& accept_button(nullptr_t);
      
      /// @brief Gets the currently active form for this application.
      /// @return A form that represents the currently active form, or std::optional with no vallue if there is no active form.
      static std::optional<std::reference_wrapper<form>> active_form() {return active_form_;}
      
      /// @brief Gets the mode by which the form automatically resizes itself.
      /// @return An auto_size_mode enumerated value. The default is grow_only.
      virtual forms::auto_size_mode auto_size_mode() const {return auto_size_mode_;}
      /// @brief Sets the mode by which the form automatically resizes itself.
      /// @param value An auto_size_mode enumerated value. The default is grow_only.
      /// @return Current form.
      virtual form& auto_size_mode(forms::auto_size_mode value);
      
      /// @brief Gets the button control that is clicked when the user presses the ESC key.
      /// @return An ibutton_control that represents the cancel button for the form.
      std::optional<std::reference_wrapper<ibutton_control>> cancel_button() const {return cancel_button_;}
      /// @brief Gets the button control that is clicked when the user presses the ESC key.
      /// @param value  An ibutton_control that represents the cancel button for the form.
      /// @return Current form.
      form& cancel_button(const ibutton_control& value);
      /// @brief Gets the button control that is clicked when the user presses the ESC key.
      /// @param value  An ibutton_control that represents the cancel button for the form.
      /// @return Current form.
      form& cancel_button(nullptr_t);

      /// @brief Gets a value indicating whether a close box is displayed in the caption bar of the form.
      /// @return true if the form displays a close box in the upper-left corner of the form; otherwise, false. The default is true.
      virtual bool close_box() const {return close_box_;}
      /// @brief Sets a value indicating whether a close box is displayed in the caption bar of the form.
      /// @param value true if the form displays a close box in the upper-left corner of the form; otherwise, false. The default is true.
      /// @return Current form.
      virtual form& close_box(bool value);
      
      /// @brief Gets a value indicating whether a control box is displayed in the caption bar of the form.
      /// @return true if the form displays a control box in the upper-right corner of the form; otherwise, false. The default is true.
      virtual bool control_box() const {return control_box_;}
      /// @brief Sets a value indicating whether a control box is displayed in the caption bar of the form.
      /// @param value true if the form displays a control box in the upper-right corner of the form; otherwise, false. The default is true.
      /// @return Current form.
      virtual form& control_box(bool value);

      drawing::size default_size() const override {return {300, 300};}
      
      /// @brief Gets the dialog result for the form.
      /// @return A dialog_result that represents the result of the form when used as a dialog box.
      virtual forms::dialog_result dialog_result() const {return dialog_result_;}
      /// @brief Sets the dialog result for the form.
      /// @param value A dialog_result that represents the result of the form when used as a dialog box.
      /// @return Current form.
      virtual form& dialog_result(forms::dialog_result value);
      
      /// @brief Gets the border style of the form.
      /// @return A form_border_style that represents the style of border to display for the form. The default is form_border_style::sizable.
      virtual forms::form_border_style form_border_style() const {return form_border_style_;}
      /// @brief Gets the border style of the form.
      /// @param value A form_border_style that represents the style of border to display for the form. The default is form_border_style::sizable.
      /// @return Current form.
      virtual form& form_border_style(forms::form_border_style value);
      
      /// @brief Gets the icon for the form.
      /// @return An icon that represents the icon for the form.
      virtual const xtd::drawing::icon& icon() const {return icon_;}
      /// @brief Sets the icon for the form.
      /// @param value An icon that represents the icon for the form.
      /// @return Current form.
      virtual form& icon(const xtd::drawing::icon& value);

      /// @brief Gets a value indicating whether a Help button should be displayed in the caption box of the form.
      /// @return true to display a Help button in the form's caption bar; otherwise, false. The default is false.
      virtual bool help_button() const {return help_button_;}
      /// @brief Sets a value indicating whether a Help button should be displayed in the caption box of the form.
      /// @param value true to display a Help button in the form's caption bar; otherwise, false. The default is false.
      /// @return Current form.
      virtual form& help_button(bool value);
      
      /// @brief Gets a value indicating whether the Maximize button is displayed in the caption bar of the form.
      /// @return true to display a Maximize button for the form; otherwise, false. The default is true.
      virtual bool maximize_box() const {return maximize_box_;}
      /// @brief Sets a value indicating whether the Maximize button is displayed in the caption bar of the form.
      /// @param value true to display a Maximize button for the form; otherwise, false. The default is true.
      /// @return Current form.
      virtual form& maximize_box(bool value);
      
      /// @brief Gets the main_menu that is displayed in the form.
      /// @return A main_menu that represents the menu to display in the form.
      virtual std::optional<forms::main_menu> menu() const {return menu_;}
      /// @brief Sets the main_menu that is displayed in the form.
      /// @param value A main_menu that represents the menu to display in the form.
      /// @return Current form.
      virtual form& menu(const forms::main_menu& value);
      /// @brief Sets the main_menu that is displayed in the form.
      /// @param value A main_menu that represents the menu to display in the form.
      /// @return Current form.
      virtual form& menu(nullptr_t);

      /// @brief Gets a value indicating whether the Minimize button is displayed in the caption bar of the form.
      /// @return true to display a Minimize button for the form; otherwise, false. The default is true.
      virtual bool minimize_box() const {return minimize_box_;}
      /// @brief Sets a value indicating whether the Minimize button is displayed in the caption bar of the form.
      /// @param value true to display a Minimize button for the form; otherwise, false. The default is true.
      /// @return Current form.
      virtual form& minimize_box(bool value);

      /// @brief Gets a value indicating whether this form is displayed modally.
      /// @return true if the form is displayed modally; otherwise, false.
      bool modal() const {return get_state(state::modal);}
      
      /// @brief Gets the form that owns this form.
      /// @return A form that represents the form that is the owner of this form.
      virtual std::optional<control_ref> owner() const {return from_handle(owner_);}
      /// @brief Sets the form that owns this form.
      /// @param value A form that represents the form that is the owner of this form.
      /// @return Current form.
      virtual form& owner(const control& value);

      using container_control::parent;
      /// @brief Sets the parent container of the control.
      /// @param parent A control that represents the parent or container control of the control  or nullptr for none.
      control& parent(const control& value) override;

      /// @brief Gets a value indicating whether an icon is displayed in the caption bar of the form.
      /// @return true if the form displays an icon in the caption bar; otherwise, false. The default is true.
      virtual bool show_icon() const {return show_icon_;}
      /// @brief Sets a value indicating whether an icon is displayed in the caption bar of the form.
      /// @param value true if the form displays an icon in the caption bar; otherwise, false. The default is true.
      /// @return Current form.
      virtual form& show_icon(bool value);

      /// @brief Gets the starting position of the form at run time.
      /// @return A form_start_position that represents the starting position of the form.
      virtual form_start_position start_position() const {return start_position_;}
      /// @brief Sets the starting position of the form at run time.
      /// @param value A form_start_position that represents the starting position of the form.
      /// @return Current form.
      virtual form& start_position(form_start_position value);

      /// @brief Gets a value indicating whether to display the form as a top-level window.
      /// @return true to display the form as a top-level window; otherwise, false. The default is true.
      /// @remarks A Multiple-document interface (MDI) parent form must be a top-level window. So set to false has no effect.
      /// @remarks A top-level form is a window that has no parent form, or whose parent form is the desktop window. Top-level windows are typically used as the main form in an application.
      virtual bool top_level() const {return get_state(state::top_level);}
      /// @brief Sets a value indicating whether to display the form as a top-level window.
      /// @return true to display the form as a top-level window; otherwise, false. The default is true.
      /// @remarks A Multiple-document interface (MDI) parent form must be a top-level window. So set to false has no effect.
      /// @remarks A top-level form is a window that has no parent form, or whose parent form is the desktop window. Top-level windows are typically used as the main form in an application.
      virtual form& top_level(bool top_level);

      /// @brief Gets a value indicating whether the form should be displayed as a topmost form.
      /// @return true to display the form as a topmost form; otherwise, false. The default is false.
      virtual bool top_most() const {return top_most_;}
      /// @brief Sets a value indicating whether the form should be displayed as a topmost form.
      /// @param value true to display the form as a topmost form; otherwise, false. The default is false.
      /// @return Current form.
      virtual form& top_most(bool value);
      
      /// @brief Gets form opacity.
      /// @return A double-precision value between 0.0 and 1.0 that represent the form opacity.
      virtual double opacity() const {return opacity_;}
      /// @brief Sets form opacity.
      /// @param opacity A double-precision value between 0.0 and 1.0 that represent the form opacity.
      virtual form& opacity(double opacity);

      using container_control::visible;
      /// @brief Sets a value indicating whether the control and all its child controls are displayed.
      /// @param visible true if the control and all its child controls are displayed; otherwise, false. The default is true.
      /// @return Current control.
      control& visible(bool visible) override;
      
      /// @brief Gets a value that indicates whether form is minimized, maximized, or normal.
      /// @return A form_window_state that represents whether form is minimized, maximized, full_screen, or normal. The default is form_window_state::normal.
      virtual form_window_state window_state() const {return window_state_;}
      /// @brief Sets a value that indicates whether form is minimized, maximized, or normal.
      /// @param value A form_window_state that represents whether form is minimized, maximized, full_screen, or normal. The default is form_window_state::normal.
      /// @return Current form.
      virtual form& window_state(form_window_state value);
      
      /// @brief Activates the form and gives it focus.
      /// @remarks Activating a form brings it to the front if this is the active application, or it flashes the window caption if this is not the active application. The form must be visible for this method to have any effect. To determine the active form in an application, use the active_form property or the active_mdi_child property if your forms are in a Multiple-document interface (MDI) application.
      void activate();
      
      void bring_to_front() override;

      /// @brief Centers the position of the form within the bounds of the parent form.
      /// @remarks Do not call the center_to_screen method directly from your code. Instead, set the start_position property to center_parent.
      /// @remarks If the form or dialog is top-level, then center_to_parent centers the form with respect to the screen or desktop.
      void center_to_screen();
      
      /// @brief Closes the form.
      /// @remarks When a form is closed, all resources created within the object are closed and the form is disposed. You can prevent the closing of a form at run time by handling the closing event and setting the cancel property of the cancel_event_args passed as a parameter to your event handler. If the form you are closing is the startup form of your application, your application ends.
      void close();
      
      bool pre_process_message(xtd::forms::message& message) override; 
      
      /// @brief Shows the form as a modal dialog box.
      /// @return One of the dialog_result values.
      virtual forms::dialog_result show_dialog();
      /// @brief Shows the form as a modal dialog box with the specified owner.
      /// @parm owner Any object that implements iwin32_window that represents the top-level window that will own the modal dialog box.
      /// @return One of the dialog_result values.
      virtual forms::dialog_result show_dialog(const iwin32_window& owner);
      
      /// @brief Shows the form as a sheet dialog box.
      /// @remarks dialog_result property contains the rresult when the form will closed.
      /// @remarks Sheet mode is only avaible on macOS. For other platform show_dialog is underlying called.
      virtual void show_sheet(const iwin32_window& owner);
      
      /// @brief Shows the form as a modal sheet dialog box.
      /// @return One of the dialog_result values.
      /// @remarks Sheet mode is only avaible on macOS. For other platform show_dialog is underlying called.
      virtual forms::dialog_result show_sheet_dialog(const iwin32_window& owner);
      
      /// @brief Occurs when the form is activated in code or by the user.
      /// @ingroup events
      event<form, event_handler> activated;
      
      /// @brief Occurs when the form loses focus and is no longer the active form.
      /// @ingroup events
      event<form, event_handler> deactivate;

      /// @brief Occurs after the form is closed.
      /// @ingroup events
      event<form, form_closed_event_handler> form_closed;
      
      /// @brief Occurs before the form is closed.
      /// @ingroup events
      event<form, form_closing_event_handler> form_closing;

    protected:
      friend class application;
      
      forms::create_params create_params() const override;
   
      /// @brief Raises the form::activated event.
      /// @param e An event_args that contains the event data.
      virtual void on_activated(const event_args& e) {activated(*this, e);}
      
      /// @brief Raises the form::deactivate event.
      /// @param e An event_args that contains the event data.
      virtual void on_deactivate(const event_args& e) {deactivate(*this, e);}
      
      void on_handle_created(const event_args &e) override;
      void on_handle_destroyed(const event_args &e) override;
      
      /// @brief Raises the form::form_closed event.
      /// @param e A form_closed_event_args that contains the event data.
      virtual void on_form_closed(const form_closed_event_args& e) {form_closed(*this, e);}
      
      /// @brief Raises the form::form_closing event.
      /// @param e A form_closing_event_args that contains the event data.
      virtual void on_form_closing(form_closing_event_args& e) {form_closing(*this, e);}

      void on_layout(const event_args& e) override;
      void on_location_changed(const event_args& e) override;
      void on_resize(const event_args& e) override;
      void wnd_proc(message& message) override;
      
      /// @brief Processes the active message the form control receives as the top-level window.
      /// @param message The message sent to the top-level window.
      virtual void wm_activate(message& message);
      
      /// @brief Processes the close message the form control receives as the top-level window.
      /// @param message The message sent to the top-level window.
      virtual void wm_close(message& message);
      
      /// @cond
      std::optional<std::reference_wrapper<ibutton_control>> accept_button_;
      std::optional<std::reference_wrapper<ibutton_control>> cancel_button_;
      static std::optional<std::reference_wrapper<form>> active_form_;
      bool close_box_ = true;
      bool control_box_ = true;
      forms::dialog_result dialog_result_ = forms::dialog_result::none;
      forms::form_border_style form_border_style_ = form_border_style::sizable;
      bool help_button_ = true;
      xtd::drawing::icon icon_ = xtd::drawing::icon::empty;
      bool maximize_box_ = true;
      std::optional<forms::main_menu> menu_;
      bool minimize_box_ = true;
      std::shared_ptr<screen> previous_screeen_;
      bool show_icon_ = true;
      bool show_in_taskbar_ = true;
      form_start_position start_position_ = form_start_position::windows_default_location;
      form_window_state window_state_ = form_window_state::normal;
      /// @endcond
      
    private:
      friend class application_context;
      bool can_close_ = false;
      bool top_most_ = false;
      intptr_t owner_ = 0;
      void internal_set_window_state();
      intptr_t parent_before_show_dialog_ = 0;
      double opacity_ = 1.0;
    };
  }
}

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
    /// @endcond
    
    /// @brief Represents a window or dialog box that makes up an application's user interface.
    /// @remarks A form is a representation of any window displayed in your application. The Form class can be used to create standard, tool, borderless, and floating windows. You can also use the form class to create modal windows such as a dialog box. A special kind of form, the multiple-document interface (MDI) form, can contain other forms called MDI child forms. An MDI form is created by setting the is_mdi_container property to true. MDI child forms are created by setting the mdi_parent property to the MDI parent form that will contain the child form.
    /// @remarks Using the properties available in the form class, you can determine the appearance, size, color, and window management features of the window or dialog box you are creating. The text property allows you to specify the caption of the window in the title bar. The size and desktop_location properties allow you to define the size and position of the window when it is displayed. You can use the fore_color color property to change the default foreground color of all controls placed on the form. The form_border_style, minimize_box, and maximize_box properties allow you to control whether the form can be minimized, maximized, or resized at run time.
    /// @remarks In addition to properties, you can use the methods of the class to manipulate a form. For example, you can use the show_dialog method to show a form as a modal dialog box. You can use the set_desktop_location method to position the form on the desktop.
    /// @par Example
    /// The following code example demonstrate the use of form control.
    /// @include form.cpp
    class form : public container_control {
    public:
      /// @brief Initializes a new instance of the Form class.
      /// @remarks The default size of a form is 300 pixels in height and 300 pixels in width.
      form();

      std::optional<std::reference_wrapper<ibutton_control>> accept_button() const {return accept_button_;}
      form& accept_button(const ibutton_control& value);
      form& accept_button(nullptr_t);
      
      std::optional<std::reference_wrapper<ibutton_control>> cancel_button() const {return cancel_button_;}
      form& cancel_button(const ibutton_control& value);
      form& cancel_button(nullptr_t);
      
      static std::optional<std::reference_wrapper<form>> active_form() {return active_form_;}
      
      virtual forms::auto_size_mode auto_size_mode() const {return this->auto_size_mode_;}
      virtual form& auto_size_mode(forms::auto_size_mode value);
      
      virtual bool close_box() const {return this->close_box_;}
      virtual form& close_box(bool value);
      
      virtual bool control_box() const {return this->control_box_;}
      virtual form& control_box(bool value);

      drawing::size default_size() const override {return{300, 300};}
      
      virtual forms::dialog_result dialog_result() const {return this->dialog_result_;}
      virtual form& dialog_result(forms::dialog_result value);
      
      virtual const xtd::drawing::icon& icon() const {return icon_;}
      virtual form& icon(const xtd::drawing::icon& value);
      
      virtual forms::form_border_style form_border_style() const {return this->form_border_style_;}
      virtual form& form_border_style(forms::form_border_style value);

      virtual bool help_button() const {return this->help_button_;}
      virtual form& help_button(bool value);
      
      virtual bool maximize_box() const {return this->maximize_box_;}
      virtual form& maximize_box(bool value);
      
      virtual std::optional<forms::main_menu> menu() const {return menu_;}
      virtual form& menu(const forms::main_menu& value);
      virtual form& menu(nullptr_t);

      virtual bool minimize_box() const {return this->minimize_box_;}
      virtual form& minimize_box(bool value);

      bool modal() const {return this->get_state(state::modal);}
      
      using container_control::parent;
      control& parent(const control& value) override;
      
      virtual form_start_position start_position() const {return this->start_position_;}
      virtual form& start_position(form_start_position value);

      /// @brief Gets a value indicating whether to display the form as a top-level window.
      /// @return true to display the form as a top-level window; otherwise, false. The default is true.
      /// @remarks A Multiple-document interface (MDI) parent form must be a top-level window. So set to false has no effect.
      /// @remarks A top-level form is a window that has no parent form, or whose parent form is the desktop window. Top-level windows are typically used as the main form in an application.
      virtual bool top_level() const {return this->get_state(state::top_level);}
      /// @brief Sets a value indicating whether to display the form as a top-level window.
      /// @return true to display the form as a top-level window; otherwise, false. The default is true.
      /// @remarks A Multiple-document interface (MDI) parent form must be a top-level window. So set to false has no effect.
      /// @remarks A top-level form is a window that has no parent form, or whose parent form is the desktop window. Top-level windows are typically used as the main form in an application.
      virtual form& top_level(bool top_level);
      
      using container_control::visible;
      control& visible(bool visible) override;
      
      virtual form_window_state window_state() const {return this->window_state_;}
      virtual form& window_state(form_window_state value);
      
      void activate();
      
      void center_to_screen();
      
      void close();
      
      virtual forms::dialog_result show_dialog();
      
      virtual forms::dialog_result show_dialog(const iwin32_window& owner);
      
      event<form, event_handler<control&>> activated;
      event<form, event_handler<control&>> deactivate;

      event<form, form_closed_event_handler<control&>> form_closed;
      
      event<form, form_closing_event_handler<control&>> form_closing;

    protected:
      friend class application;
      forms::create_params create_params() const override;
   
      virtual void on_activated(const event_args& e) {this->activated(*this, e);}
      
      virtual void on_deactivate(const event_args& e) {this->deactivate(*this, e);}
      
      void on_handle_created(const event_args &e) override;
      
      void on_handle_destroyed(const event_args &e) override;
      
      void on_form_closed(const form_closed_event_args& e) {this->form_closed(*this, e);}
      
      void on_form_closing(form_closing_event_args& e) {this->form_closing(*this, e);}
      
      void on_layout(const event_args& e) override;
      
      void on_resize(const event_args& e) override;

      void wnd_proc(message& message) override;
      
      virtual void wm_activate(message& message);
      
      virtual void wm_close(message& message);
      
      virtual void wm_key_up(message& message);
      
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
      
    private:
      void internal_set_window_state();
    };
  }
}

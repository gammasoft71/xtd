#pragma once
#include "form_closed_event_handler.hpp"
#include "form_closing_event_handler.hpp"
#include "form_start_position.hpp"
#include "container_control.hpp"
#include "dialog_result.hpp"
#include "ibutton_control.hpp"
#include "screen.hpp"

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

      static std::optional<std::reference_wrapper<form>> active_form() {return active_form_;}
      
      virtual forms::auto_size_mode auto_size_mode() const {return this->auto_size_mode_;}
      virtual form& auto_size_mode(forms::auto_size_mode value);
      
      drawing::size default_size() const override {return{300, 300};}
      
      virtual forms::dialog_result dialog_result() const {return this->dialog_result_;}
      virtual form& dialog_result(forms::dialog_result dialog_result);

      bool modal() const {return this->get_state(state::modal);}
      
      using container_control::parent;
      control& parent(const control& parent) override;
      
      virtual form_start_position start_position() const {return this->start_position_;}
      virtual form& start_position(form_start_position start_position);

      using container_control::visible;
      control& visible(bool visible) override;
      
      void activate();
      
      void close();
      
      forms::dialog_result show_dialog();
      
      forms::dialog_result show_dialog(const iwin32_window& owner);
      
      event<form, event_handler<control>> activated;
      event<form, event_handler<control>> deactivate;

      event<form, form_closed_event_handler<control>> form_closed;
      
      event<form, form_closing_event_handler<control>> form_closing;

    protected:
      friend class application;
      forms::create_params create_params() const override;
   
      drawing::size measure_control() const override;

      virtual void on_activated(const event_args& e) {this->activated(*this, e);}
      
      virtual void on_deactivate(const event_args& e) {this->deactivate(*this, e);}
      
      void on_handle_created(const event_args &e) override;

      void on_form_closed(const form_closed_event_args& e) {this->form_closed(*this, e);}
      
      void on_form_closing(form_closing_event_args& e) {this->form_closing(*this, e);}
      
      void wnd_proc(message& message) override;
      
      virtual void wm_activate(message& message);
      
      virtual void wm_close(message& message);
      
      static std::optional<std::reference_wrapper<form>> active_form_;
      forms::dialog_result dialog_result_ = forms::dialog_result::none;
      std::shared_ptr<screen> previous_screeen_;
      form_start_position start_position_ = form_start_position::windows_default_location;
    };
  }
}

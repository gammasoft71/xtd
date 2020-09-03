#pragma once
#include <xtd/environment.h>
#include "button_base.h"
#include "dialog_result.h"
#include "ibutton_control.h"
#include "timer.h"
#include "visual_styles/push_button_state.h"

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
      /// @brief Initializes a new instance of the button class.
      /// @remarks By default the button displays no caption. To specify the caption text, set the text property.
      button() {
        auto_repeat_timer_.tick += [&] {
          auto_repeat_timer_.enabled(false);
          if (enabled()) {
            perform_click();
            auto_repeat_timer_.interval(auto_repeat_interval_);
            auto_repeat_timer_.enabled(auto_repeat_);
          }
        };
      }
      
      bool auto_repeat() const {return auto_repeat_;}
      button& auto_repeat(bool auto_repeat) {
        if (auto_repeat_ != auto_repeat) {
          auto_repeat_ = auto_repeat;
          if (!auto_repeat_) auto_repeat_timer_.enabled(false);
        }
        return *this;
      }
      
      int32_t auto_repeat_delay() const {return auto_repeat_delay_;}
      button& auto_repeat_delay(int32_t auto_repeat_delay) {
        if (auto_repeat_delay_ != auto_repeat_delay)
          auto_repeat_delay_ = auto_repeat_delay;
        return *this;
      }
      
      int32_t auto_repeat_interval() const {return auto_repeat_interval_;}
      button& auto_repeat_interval(int32_t auto_repeat_interval) {
        if (auto_repeat_interval_ != auto_repeat_interval)
          auto_repeat_interval_ = auto_repeat_interval;
        return *this;
      }

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

      using button_base::image;
      button_base& image(const drawing::image& value) override;
      
      /// @brief Generates a click event for the control.
      /// @remarks This method is called for the button that has focus, or for the default button (if no other button has focus) when the user presses the ENTER key. This method is also called when the user presses the ESC key if the button is set as the cancel button.
      void perform_click() override;

      /// @brief Measure this control.
      /// @return The drawing::size size of this control.
      /// @remarks This method is used when auto_size is true.
      drawing::size measure_control() const override;
      
    protected:
      /// @brief Gets a create_params on the base class when creating a window.
      /// @return A create_params object on the base class when creating a window.
      /// @remarks Inheriting classes can override this property to add extra functionality, but must first call the create_params constructor on the base class to verify that the control continues to work correctly.
      forms::create_params create_params() const override;
      
      void on_back_color_changed(const event_args& e) override {
        if (flat_style_ != xtd::forms::flat_style::system) invalidate();
        button_base::on_parent_back_color_changed(e);
      }

      /// @brief Raises the Click event.
      /// @param e An event_args that contains the event data.
      void on_click(const event_args& e) override;

      void on_enabled_changed(const event_args& e) override {
        if (flat_style_ != xtd::forms::flat_style::system) {
          state_ = enabled() ? xtd::forms::visual_styles::push_button_state::normal : xtd::forms::visual_styles::push_button_state::disabled;
          invalidate();
        }
        button_base::on_enabled_changed(e);
      }
      
      void on_fore_color_changed(const event_args& e) override {
        if (flat_style_ != xtd::forms::flat_style::system) invalidate();
        button_base::on_fore_color_changed(e);
      }
      
      void on_handle_created(const event_args& e) override;

      void on_mouse_down(const mouse_event_args& e) override {
        auto_repeat_timer_.interval(auto_repeat_delay_);
        auto_repeat_timer_.enabled(auto_repeat_);
        if (flat_style_ != xtd::forms::flat_style::system) {
          state_ = xtd::forms::visual_styles::push_button_state::pressed;
          invalidate();
        }
        button_base::on_mouse_down(e);
      }

      void on_mouse_enter(const event_args& e) override {
        if (flat_style_ != xtd::forms::flat_style::system) {
          state_ = xtd::forms::visual_styles::push_button_state::hot;
          invalidate();
        }
        button_base::on_mouse_enter(e);
      }

      void on_mouse_leave(const event_args& e) override {
        if (flat_style_ != xtd::forms::flat_style::system) {
          state_ = xtd::forms::visual_styles::push_button_state::normal;
          invalidate();
          button_base::on_mouse_leave(e);
        }
      }

      void on_mouse_move(const mouse_event_args& e) override {
        if (flat_style_ != xtd::forms::flat_style::system && (e.button() & mouse_buttons::left) == mouse_buttons::left && !client_rectangle().contains(e.location()) && state_ == xtd::forms::visual_styles::push_button_state::pressed) {
          state_ = xtd::forms::visual_styles::push_button_state::hot;
          invalidate();
        }
        button_base::on_mouse_move(e);
      }
      
      void on_mouse_up(const mouse_event_args& e) override {
        auto_repeat_timer_.enabled(false);
        if (flat_style_ != xtd::forms::flat_style::system && state_ == xtd::forms::visual_styles::push_button_state::pressed) {
          state_ = xtd::forms::visual_styles::push_button_state::hot;
          invalidate();
        }
        button_base::on_mouse_up(e);
      }

      void on_text_changed(const event_args& e) override {
        if (flat_style_ != xtd::forms::flat_style::system) invalidate();
        button_base::on_text_changed(e);
      }
      
      void on_paint(paint_event_args& e) override;

      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      //void wnd_proc(message& message) override;

      /// @cond
      forms::dialog_result dialog_result_ = forms::dialog_result::none;
      /// @endcond

    private:
      //void wm_click(message& message);
      //void wm_mouse_up(message& message);
      bool auto_repeat_ = false;
      timer auto_repeat_timer_;
      int32_t auto_repeat_delay_ = 300;
      int32_t auto_repeat_interval_ = 100;
      xtd::forms::visual_styles::push_button_state state_ = xtd::forms::visual_styles::push_button_state::normal;
   };
  }
}

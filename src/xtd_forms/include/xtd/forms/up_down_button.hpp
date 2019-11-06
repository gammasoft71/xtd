#pragma once
#include "button_base.hpp"
#include "orientation.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class up_down_button : public button_base {
    public:      
      up_down_button();

      virtual int32_t maximum() {return maximum_;}
      virtual up_down_button& maximum(int32_t value);
      
      virtual int32_t minimum() {return minimum_;}
      virtual up_down_button& minimum(int32_t value);
      
      /// @brief Gets a value indicating the horizontal or vertical orientation of the up down button.
      /// @return One of the orientation values.
      virtual forms::orientation orientation() const {return this->orientation_;}
      /// @brief Sets a value indicating the horizontal or vertical orientation of the up down button
      /// @param orientation One of the orientation values.
      /// @param When the orientation property is set to orientation::horizontal, the scroll box moves from left to right as the value increases. When the orientation property is set to orientation::vertical, the scroll box moves from bottom to top as the Value increases.
      virtual up_down_button& orientation(forms::orientation orientation);

      virtual int32_t value() {return value_;}
      virtual up_down_button& value(int32_t value);

      virtual bool wrapped() {return wrapped_;}
      virtual up_down_button& wrapped(bool value);
      
      /// @brief Occurs when either a mouse or keyboard action moves the scroll box.
      event<up_down_button, event_handler<control&>> scroll;

      event<up_down_button, event_handler<control&>> value_changed;
      
    protected:
      
      drawing::size default_size() const override {return {18, 34};}

      forms::create_params create_params() const override;
      
      /// @brief Overrides control::on_handle_created(const event_args&)
      /// @param e A EventArgs that contains the event data.
      void on_handle_created(const event_args& e) override;

      virtual void on_scroll(const event_args& e);

      virtual void on_value_changed(const event_args& e);
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd°proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;

      /// @cond
      bool wrapped_ = false;
      int32_t maximum_ = 100;
      int32_t minimum_ = 0;
      forms::orientation orientation_ = forms::orientation::vertical;
      int32_t value_ = 0;
      /// @endcond

      private:
        void wm_scroll(message& message);
    };
  }
}

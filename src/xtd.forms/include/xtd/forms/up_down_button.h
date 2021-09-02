/// @file
/// @brief Contains xtd::forms::up_down_button control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "button_base.h"
#include "orientation.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows up down button.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of up down button control.
    /// @include up_down_button.cpp
    /// @par Windows
    /// @image html up_down_button_w.png
    /// <br>
    /// @image html up_down_button_wd.png
    /// @par macOS
    /// @image html up_down_button_m.png
    /// <br>
    /// @image html up_down_button_md.png
    /// @par Gnome
    /// @image html up_down_button_g.png
    /// <br>
    /// @image html up_down_button_gd.png
    class forms_export_ up_down_button : public button_base {
    public:
      /// @brief Initializes a new instance of up_down_button class.
      up_down_button();

      /// @brief Gets the maximum value for the up_down_button control.
      /// @return The maximum value for the up down button. The default value is 100.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      virtual int32_t maximum() {return maximum_;}
      /// @brief Sets the maximum value for the up_down_button control.
      /// @param value The maximum value for the up down button. The default value is 100.
      /// @return Current numeric_up_down.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      virtual up_down_button& maximum(int32_t value);
      
      /// @brief Gets the minimum allowed value for the up_down_button control.
      /// @return The minimum allowed value for the up down button. The default value is 0.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      virtual int32_t minimum() {return minimum_;}
      /// @brief Sets the minimum allowed value for the up_down_button control.
      /// @param value The minimum allowed value for the up down button. The default value is 0.
      /// @return Current numeric_up_down.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      virtual up_down_button& minimum(int32_t value);
      
      /// @brief Gets a value indicating the horizontal or vertical orientation of the up down button.
      /// @return One of the orientation values.
      virtual forms::orientation orientation() const {return orientation_;}
      /// @brief Sets a value indicating the horizontal or vertical orientation of the up down button
      /// @param orientation One of the orientation values.
      /// @param When the orientation property is set to orientation::horizontal, the scroll box moves from left to right as the value increases. When the orientation property is set to orientation::vertical, the scroll box moves from bottom to top as the Value increases.
      virtual up_down_button& orientation(forms::orientation orientation);

      /// @brief Gets the value assigned to the up_down_button control.
      /// @return The numeric value of the up down button control.
      /// @remarks When the value property is set, the new value is validated to be between the minimum and maximum values. Following this, the update_edit_text method is called to update the spin box's display with the new value in the appropriate format.
      virtual int32_t value() {return value_;}
      /// @brief Sets the value assigned to the up_down_button control.
      /// @param value The numeric value of the up down button control.
      /// @return Current numeric_up_down.
      /// @remarks When the value property is set, the new value is validated to be between the minimum and maximum values. Following this, the update_edit_text method is called to update the spin box's display with the new value in the appropriate format.
      virtual up_down_button& value(int32_t value);

      /// @brief Get a value indicate if value can be wrapped.
      /// @return true if value can be wrapped; otherwise false. The default is false.
      virtual bool wrapped() {return wrapped_;}
      /// @brief Set a value indicate if value can be wrapped.
      /// @param value true if value can be wrapped; otherwise false. The default is false.
      /// @return Current numeric_up_down.
      virtual up_down_button& wrapped(bool value);
      
      /// @brief Sets the minimum and maximum values for a track_bar.
      /// @param min_value The lower limit of the range of the track bar.
      /// @param max_value The upper limit of the range of the track bar.
      /// @remarks You can use this method to set the entire range for the track_bar at the same time. To set the minimum or maximum values individually, use the minimum and maximum properties. If the min_value parameter is greater than the max_value parameter, max_value is set equal to min_value.
      void set_range(int min_value, int max_value) {
        minimum(min_value);
        maximum(min_value > max_value ? min_value : max_value);
      }
      
      /// @brief Returns a string that represents the track_bar control.
      /// @return A string that represents the current progress_bar.
      /// @remarks The return string includes the type and the values for the minimum, maximum, and value properties.
      xtd::ustring to_string() const noexcept override {return ustring::format("{}, minimum: {}, maximum: {}, value: {}", ustring::full_class_name(*this), minimum_, maximum_, value_);}

      /// @brief Occurs when either a mouse or keyboard action moves the scroll box.
      /// @ingroup events
      event<up_down_button, event_handler> scroll;

      /// @brief Occurs when the value of the value property changes.
      /// @ingroup events
      event<up_down_button, event_handler> value_changed;
      
    protected:
      
      drawing::size default_size() const override {return {18, 34};}

      forms::create_params create_params() const override;
      
      /// @brief Overrides control::on_handle_created(const event_args&)
      /// @param e A EventArgs that contains the event data.
      void on_handle_created(const event_args& e) override;

      /// @brief Raises the up_down_button::scroll event.
      /// @param e An event_args that contains the event data.
      /// @remarks You can use the OnScroll event to update other controls as the position of the scroll box changes.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_scroll method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inheritors
      /// @remarks When overriding on_scroll(const event_args&) in a derived class, be sure to call the base class' on_scroll(const event_args&) method so that registered delegates receive the event.
      virtual void on_scroll(const event_args& e);

      /// @brief Raises the up_down_button::value_changed event.
      /// @param e An event_args that contains the event data.
      virtual void on_value_changed(const event_args& e);
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
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

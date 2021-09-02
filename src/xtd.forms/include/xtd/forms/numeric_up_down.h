/// @file
/// @brief Contains xtd::forms::numeric_up_down control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "up_down_base.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows numeric up down.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks A numeric_up_down control contains a single numeric value that can be incremented or decremented by clicking the up or down buttons of the control. The user can also enter in a value, unless the read_only property is set to true.
    /// @remarks The numeric display can be formatted by setting the decimal_places, hexadecimal, or thousands_separator properties. To display hexadecimal values in the control, set the hexadecimal property to true. To display a thousands separator in decimal numbers when appropriate, set the thousands_separator property to true. To specify the number of digits displayed after the decimal symbol, set the ddecimal_places property to the number of decimal places to display.
    /// @remarks To specify the allowable range of values for the control, set the minimum and maximum properties. Set the increment value to specify the value to be incremented or decremented to the value property when the user clicks the up or down arrow buttons. You can increase the speed that the control moves through numbers when the user continuously presses the up or down arrow by setting the accelerations property.
    /// @remarks When the up_button or down_button methods are called, either in code or by the click of the up or down buttons, the new value is validated and the control is updated with the new value in the appropriate format. Specifically, if the user_edit property is set to true, the parse_edit_text method is called prior to validating or updating the value. The value is then verified to be between the minimum and maximum values, and the update_edit_text method is called.
    /// @par Examples
    /// The following code example demonstrate the use of numeric up down control.
    /// @include numeric_up_down.cpp
    /// @par Windows
    /// @image html numeric_up_down_w.png
    /// <br>
    /// @image html numeric_up_down_wd.png
    /// @par macOS
    /// @image html numeric_up_down_m.png
    /// <br>
    /// @image html numeric_up_down_md.png
    /// @par Gnome
    /// @image html numeric_up_down_g.png
    /// <br>
    /// @image html numeric_up_down_gd.png
    class forms_export_ numeric_up_down : public up_down_base {
    public:
      /// @brief Initializes a new instance of the numeric_up_down class.
      numeric_up_down();

      /// @brief Gets the number of decimal places to display in the spin box (also known as an up-down control). This property doesn't affect the value property.
      /// @return The number of decimal places to display in the spin box. The default is 0.
      /// @remarks When the decimal_places property is set, the update_edit_text method is called to update the spin box's display to the new format.
      virtual double decimal_place() {return decimal_place_;}
      /// @brief Sets the number of decimal places to display in the spin box (also known as an up-down control). This property doesn't affect the value property.
      /// @param value The number of decimal places to display in the spin box. The default is 0.
      /// @return Current numeric_up_down.
      /// @remarks When the decimal_places property is set, the update_edit_text method is called to update the spin box's display to the new format.
      virtual numeric_up_down& decimal_place(int32_t value);

      /// @brief Gets the value to increment or decrement the spin box (also known as an up-down control) when the up or down buttons are clicked.
      /// @return The value to increment or decrement the Value property when the up or down buttons are clicked on the spin box. The default value is 1.
      /// @remarks Clicking the up button causes the value property to increment by the amount specified by the increment property and approach the maximum property. Clicking the down button causes the value property to be decremented by the amount specified by the increment property and approach the minimum property.
      virtual double increment() {return increment_;}
      /// @brief Sets the value to increment or decrement the spin box (also known as an up-down control) when the up or down buttons are clicked.
      /// @param value The value to increment or decrement the Value property when the up or down buttons are clicked on the spin box. The default value is 1.
      /// @return Current numeric_up_down.
      /// @remarks Clicking the up button causes the value property to increment by the amount specified by the increment property and approach the maximum property. Clicking the down button causes the value property to be decremented by the amount specified by the increment property and approach the minimum property.
      virtual numeric_up_down& increment(double value);
      
      /// @brief Gets the maximum value for the spin box (also known as an up-down control).
      /// @return The maximum value for the spin box. The default value is 100.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      virtual double maximum() {return maximum_;}
      /// @brief Sets the maximum value for the spin box (also known as an up-down control).
      /// @param value The maximum value for the spin box. The default value is 100.
      /// @return Current numeric_up_down.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      virtual numeric_up_down& maximum(double value);
      
      /// @brief Gets the minimum allowed value for the spin box (also known as an up-down control).
      /// @return The minimum allowed value for the spin box. The default value is 0.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      virtual double minimum() {return minimum_;}
      /// @brief Sets the minimum allowed value for the spin box (also known as an up-down control).
      /// @param value The minimum allowed value for the spin box. The default value is 0.
      /// @return Current numeric_up_down.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      virtual numeric_up_down& minimum(double value);

      /// @brief Gets the value assigned to the spin box (also known as an up-down control).
      /// @return The numeric value of the numeric_up_down control.
      /// @remarks When the value property is set, the new value is validated to be between the minimum and maximum values. Following this, the update_edit_text method is called to update the spin box's display with the new value in the appropriate format.
      virtual double value() {return value_;}
      /// @brief Sets the value assigned to the spin box (also known as an up-down control).
      /// @param value The numeric value of the numeric_up_down control.
      /// @return Current numeric_up_down.
      /// @remarks When the value property is set, the new value is validated to be between the minimum and maximum values. Following this, the update_edit_text method is called to update the spin box's display with the new value in the appropriate format.
      virtual numeric_up_down& value(double value);
      
      /// @brief Get a value indicate if value can be wrapped.
      /// @return true if value can be wrapped; otherwise false. The default is false.
      virtual bool wrapped() {return wrapped_;}
      /// @brief Set a value indicate if value can be wrapped.
      /// @param value true if value can be wrapped; otherwise false. The default is false.
      /// @return Current numeric_up_down.
      virtual numeric_up_down& wrapped(bool value);
      
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

      /// @brief Occurs when the value property has been changed in some way.
      /// @ingroup events
      event<numeric_up_down, event_handler> value_changed;
      
    protected:
      drawing::color default_back_color() const override {return xtd::forms::theme_colors::current_theme().window();}
      
      drawing::color default_fore_color() const override {return xtd::forms::theme_colors::current_theme().window_text();}
      
      drawing::size default_size() const override {return {120, 21};}

      forms::create_params create_params() const override;
      
      /// @brief Overrides control::on_handle_created(const event_args&)
      /// @param e A EventArgs that contains the event data.
      void on_handle_created(const event_args& e) override;

      /// @brief Raises the numeric_up_down::value_changed event.
      /// @param e An event_args that contains the event data.
      virtual void on_value_changed(const event_args& e);

      void wnd_proc(message& message) override;

      /// @cond
      void wm_command(message& message);
      /// @endcond

      int32_t decimal_place_ = 0;
      double increment_ = 1.0;
      double maximum_ = 100.0;
      double minimum_ = 0.0;
      double value_ = 0.0;
      bool wrapped_ = false;
    };
  }
}

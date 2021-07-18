/// @file
/// @brief Contains xtd::forms::progress_bar control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "orientation.h"
#include "progress_bar_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows progress bar control.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks A ProgressBar control visually indicates the progress of a lengthy operation in one of three styles:
    ///  * Segmented blocks that increase in steps from left to right.
    ///  * A continuous bar that fills in from left to right.
    ///  * A block that scrolls across a ProgressBar in a marquee fashion.
    /// @remarks The style property determines the style of progress_bar that is displayed. Note that the progress_bar control can oriented horizontally or verticaly. The progress_bar control is typically used when an application performs tasks such as copying files or printing documents. Users of an application might consider an application unresponsive if there is no visual cue. By using the progress_bar in your application, you alert the user that the application is performing a lengthy task and that the application is still responding.
    /// @remarks The maximum and minimum properties define the range of values to represent the progress of a task. The minimum property is typically set to a value of 0, and the maximum property is typically set to a value indicating the completion of a task. For example, to properly display the progress when copying a group of files, the maximum property could be set to the total number of files to be copied.
    /// @remarks The value property represents the progress that the application has made toward completing the operation. The value displayed by the progress_bar only approximates the current value of the value property. Based on the size of the progress_bar, the value property determines when to display the next block or increase the size of the bar.
    /// @remarks There are a number of ways to modify the value displayed by the progress_bar other than changing the value property directly. You can use the step property to specify a specific value to increment the Value property by, and then call the perform_step method to increment the value. To vary the increment value, you can use the increment method and specify a value with which to increment the value property.
    /// @note fore_color and back_color changes for the progress_bar will not be honored.
    /// @par Examples
    /// The following code example demonstrate the use of progress_bar control.
    /// @include progress_bar.cpp
    /// @par Windows
    /// @image html progress_bar_w.png
    /// <br>
    /// @image html progress_bar_wd.png
    /// @par macOS
    /// @image html progress_bar_m.png
    /// <br>
    /// @image html progress_bar_md.png
    /// @par Gnome
    /// @image html progress_bar_g.png
    /// <br>
    /// @image html progress_bar_gd.png
    class forms_export_ progress_bar : public control {
    public:
      /// @brief Initializes a new instance of the progress_bar class.
      /// @remarks By default, the minimum property is set to 0, the maximum property is set to 100, and the step property is set to 10.
      progress_bar();

      /// @brief Gets the default size of the control.
      /// @return A size that represents the default size of the control.
      drawing::size default_size() const override {return {100, 23};}
      
      /// @brief Gets he time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @return The time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @remarks A marquee-style progress indicator does not display progress; instead it indicates that an operation is occurring by moving the progress block across the progress bar.
      /// @remarks Since the marquee animation speed is a time period, setting the value to a higher number results in a slower speed and a lower number results in a faster speed.
      virtual size_t marquee_animation_speed() {return marquee_animation_speed_;}
      /// @brief Sets the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param marquee_animation_speed The time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @remarks A marquee-style progress indicator does not display progress; instead it indicates that an operation is occurring by moving the progress block across the progress bar.
      /// @remarks Since the marquee animation speed is a time period, setting the value to a higher number results in a slower speed and a lower number results in a faster speed.
      virtual progress_bar& marquee_animation_speed(size_t marquee_animation_speed);
      
      /// @brief Gets the maximum value of the range of the control.
      /// @return The maximum value of the range. The default is 100.
      /// @remarks This property specifies the upper limit of the value property. When the value of the maximum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the maximum property, the progress bar is completely filled.
      /// @remarks You can use this property to specify a value to which the value property must be set (by setting the value property or using the increment or perform_step methods) to indicate that an operation is complete. For example, you can set the value of the maximum property to the total number of files in a file copy operation. Each time a file is copied, the value property can be increased by 1 until the total number of files is copied. At that point, the progress bar would be completely filled.
      virtual int32_t maximum() {return maximum_;}
      /// @brief Sets the maximum value of the range of the control.
      /// @param maximum The maximum value of the range. The default is 100.
      /// @remarks This property specifies the upper limit of the value property. When the value of the maximum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the maximum property, the progress bar is completely filled.
      /// @remarks You can use this property to specify a value to which the value property must be set (by setting the value property or using the increment or perform_step methods) to indicate that an operation is complete. For example, you can set the value of the maximum property to the total number of files in a file copy operation. Each time a file is copied, the value property can be increased by 1 until the total number of files is copied. At that point, the progress bar would be completely filled.
      virtual progress_bar& maximum(int32_t maximum);
      
      /// @brief Gets the minimum value of the range of the control.
      /// @return The minimum value of the range. The default is 0.
      /// @remarks This property specifies the lower limit of the value property. When the value of the minimum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the minimum property, the progress bar is empty. To change the value of the progress bar, use the step property with the perform_step method, use the increment method, or set the value of the value property directly.
      virtual int32_t minimum() {return minimum_;}
      /// @brief Sets the minimum value of the range of the control.
      /// @param minimum The minimum value of the range. The default is 0.
      /// @remarks This property specifies the lower limit of the value property. When the value of the minimum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the minimum property, the progress bar is empty. To change the value of the progress bar, use the step property with the perform_step method, use the increment method, or set the value of the value property directly.
      virtual progress_bar& minimum(int32_t minimum);
      
      /// @brief Gets a value indicating the horizontal or vertical orientation of the progress bar.
      /// @return One of the orientation values.
      /// @remarks When the orientation property is set to orientation::horizontal, the progress moves from left to right as the value increases. When the orientation property is set to orientation::vertical, the progress moves from bottom to top as the value increases.
      virtual forms::orientation orientation() const {return orientation_;}
      /// @brief Sets a value indicating the horizontal or vertical orientation of the progress bar.
      /// @param orientation One of the orientation values.
      /// @remarks When the orientation property is set to orientation::horizontal, the progress moves from left to right as the value increases. When the orientation property is set to orientation::vertical, the progress moves from bottom to top as the value increases.
      virtual progress_bar& orientation(forms::orientation orientation);
      
      /// @brief Gets the amount by which a call to the PerformStep() method increases the current position of the progress bar.
      /// @return The amount by which to increment the progress bar with each call to the perform_step() method. The default is 10.
      /// @remarks You can use the step property to specify the amount that each completed task in an operation changes the value of the progress bar. For example, if you are copying a group of files, you might want to set the value of the step property to 1 and the value of the maximum property to the total number of files to copy. When each file is copied, you can call the perform_step method to increment the progress bar by the value of the step property. If you want to have more flexible control of the value of the progress bar, you can use the increment method or set the value of the value property directly.
      virtual int32_t step() {return step_;}
      /// @brief Sets the amount by which a call to the PerformStep() method increases the current position of the progress bar.
      /// @param step The amount by which to increment the progress bar with each call to the perform_step() method. The default is 10.
      /// @remarks You can use the step property to specify the amount that each completed task in an operation changes the value of the progress bar. For example, if you are copying a group of files, you might want to set the value of the step property to 1 and the value of the maximum property to the total number of files to copy. When each file is copied, you can call the perform_step method to increment the progress bar by the value of the step property. If you want to have more flexible control of the value of the progress bar, you can use the increment method or set the value of the value property directly.
      virtual progress_bar& step(int32_t step);
      
      /// @brief Gets the manner in which progress should be indicated on the progress bar.
      /// @return One of the progress_bar_style values. The default is blocks
      /// @remarks You can use the marquee style when you need to indicate progress is being made, without indicating the quantity of progress. The marquee style is honored only when visual styles are enabled. The continuous style is honored when visual styles are not enabled.
      virtual progress_bar_style style() const {return style_;}
      /// @brief Sets the manner in which progress should be indicated on the progress bar.
      /// @param style One of the progress_bar_style values. The default is blocks
      /// @remarks You can use the marquee style when you need to indicate progress is being made, without indicating the quantity of progress. The marquee style is honored only when visual styles are enabled. The continuous style is honored when visual styles are not enabled.
      virtual progress_bar& style(progress_bar_style style);
      
      /// @brief Gets the current position of the progress bar.
      /// @return The position within the range of the progress bar. The default is 0.
      /// @remarks If the value specified is greater than the value of the maximum property, the value property is set to maximum.
      /// @remarks If the value specified is less than the value of the minimum property, the value property is set to minimum.
      /// @remarks The minimum and maximum values of the value property are specified by the minimum and maximum properties. This property enables you to increment or decrement the value of the progress bar directly. To perform consistent increases in the value of the progress_bar control you can use the step property with the perform_step method. To increase the progress bar value by varying amounts, use the increment method.
      virtual int32_t value() {return value_;}
      /// @brief Sets the current position of the progress bar.
      /// @param value The position within the range of the progress bar. The default is 0.
      /// @remarks If the value specified is greater than the value of the maximum property, the value property is set to maximum.
      /// @remarks If the value specified is less than the value of the minimum property, the value property is set to minimum.
      /// @remarks The minimum and maximum values of the value property are specified by the minimum and maximum properties. This property enables you to increment or decrement the value of the progress bar directly. To perform consistent increases in the value of the progress_bar control you can use the step property with the perform_step method. To increase the progress bar value by varying amounts, use the increment method.
      virtual progress_bar& value(int32_t value);

      /// @brief Advances the current position of the progress bar by the specified amount.
      /// @param value The amount by which to increment the progress bar's current position.
      /// @remarks The increment method enables you to increment the value of the progress bar by a specific amount. This method of incrementing the progress bar is similar to using the step property with the perform_step method. The value property specifies the current position of the progress_bar. If, after calling the increment method, the value property is greater than the value of the maximum property, the value property remains at the value of the maximum property. If, after calling the increment method with a negative value specified in the value parameter, the Value property is less than the value of the minimum property, the value property remains at the value of the minimum property.
      /// @remarks Because a progress_bar object whose style is set to marquee displays a continuously scrolling bar instead of its value, calling increment is unnecessary and will do nothing.
      void increment(int32_t value) {
        if (value_ + value < minimum_)
          this->value(minimum_);
        if (value_ + value > maximum_)
          this->value(maximum_);
        else
          this->value(value_ + value);
      }
      
      /// @brief Advances the current position of the progress bar by the amount of the Step property.
      /// @remarks The perform_step method increments the value of the progress bar by the amount specified by the step property. You can use the Step property to specify the amount that each completed task in an operation changes the value of the progress bar. For example, if you are copying a group of files, you might want to set the value of the step property to 1 and the value of the maximum property to the total number of files to copy. When each file is copied, you can call the perform_step method to increment the progress bar by the value of the step property. If you want to have more flexible control of the value of the progress bar, you can use the increment method or set the value of the value property directly.
      void perform_step() {increment(step());}

      /// @brief Sets the minimum and maximum values for a xtd::forms::progress_bar.
      /// @param min_value The lower limit of the range of the progress bar.
      /// @param max_value The upper limit of the range of the progress bar.
      /// @remarks You can use this method to set the entire range for the xtd::forms::progress_bar at the same time. To set the minimum or maximum values individually, use the xtd::forms::progress_bar::minimum and xtd::forms::progress_bar::maximum properties. If the min_value parameter is greater than the max_value parameter, max_value is set equal to min_value.
      void set_range(int min_value, int max_value) {
        minimum(min_value);
        maximum(min_value > max_value ? min_value : max_value);
      }

      /// @brief Returns a string that represents the progress_bar control.
      /// @return A string that represents the current progress_bar.
      /// @remarks The return string includes the type and the values for the minimum, maximum, and value properties.
      std::string to_string() const noexcept override {return strings::format("{}, minimum: {}, maximum: {}, value: {}", strings::full_class_name(*this), minimum_, maximum_, value_);}
      
    protected:
      /// @brief Gets the required creation parameters when the control handle is created.
      /// @return A create_params that contains the required creation parameters when the handle to the control is created.
      forms::create_params create_params() const override;
      
      /// @brief Overrides control::on_handle_created(const event_args&)
      /// @param e A EventArgs that contains the event data.
      void on_handle_created(const event_args& e) override;
      
      /// @cond
      size_t marquee_animation_speed_ = 100;
      int32_t maximum_ = 100;
      int32_t minimum_ = 0;
      forms::orientation orientation_ = forms::orientation::horizontal;
      int32_t step_ = 10;
      progress_bar_style style_ = progress_bar_style::blocks;
      int32_t value_ = 0;
      /// @endcond
    };
  }
}

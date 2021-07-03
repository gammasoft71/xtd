/// @file
/// @brief Contains xtd::forms::track_bar control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "orientation.h"
#include "tick_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows track bar.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks The track_bar is a scrollable control similar to the scroll_bar control. You can configure ranges through which the value of the value property of a track bar scrolls by setting the minimum property to specify the lower end of the range and the maximum property to specify the upper end of the range.
    /// @remarks The large_change property defines the increment to add or subtract from the value property when clicks occur on either side of the scroll box. The track bar can be displayed horizontally or vertically.
    /// @remarks You can use this control to input numeric data obtained through the value property. You can display this numeric data in a control or use it in code.
    /// @par Examples
    /// The following code example demonstrate the use of track_bar control.
    /// @include track_bar.cpp
    /// @par Windows
    /// @image html track_bar_w.png
    /// <br>
    /// @image html track_bar_wd.png
    /// @par macOS
    /// @image html track_bar_m.png
    /// <br>
    /// @image html track_bar_md.png
    /// @par Gnome
    /// @image html track_bar_g.png
    /// <br>
    /// @image html track_bar_gd.png
    class forms_export_ track_bar : public control {
    public:
      /// @brief Initializes a new instance of the track_bar class.
      /// @remarks The track_bar is created with a default horizontal orientation and a range of 0 to 10, with a tick mark shown for every value.
      track_bar();

      /// @brief Gets the default size of the control.
      /// @return A size that represents the default size of the control.
      drawing::size default_size() const override {return {104, 45};}
      
      /// @brief Gets a value to be added to or subtracted from the value property when the scroll box is moved a large distance.
      /// @return A numeric value. The default is 5.
      /// @remarks When the user presses the PAGE UP or PAGE DOWN key or clicks the track bar on either side of the scroll box, the value property changes according to the value set in the large_change property. You might consider setting the large_change value to a percentage of the height (for a vertically oriented track bar) or width (for a horizontally oriented track bar) value. This keeps the distance your track bar moves proportionate to its size.
      virtual int32_t large_change() {return large_change_;}
      /// @brief Sets a value to be added to or subtracted from the value property when the scroll box is moved a large distance.
      /// @param large_change A numeric value. The default is 5.
      /// @return Current track_bar instance.
      /// @remarks When the user presses the PAGE UP or PAGE DOWN key or clicks the track bar on either side of the scroll box, the value property changes according to the value set in the large_change property. You might consider setting the large_change value to a percentage of the height (for a vertically oriented track bar) or width (for a horizontally oriented track bar) value. This keeps the distance your track bar moves proportionate to its size.
      virtual track_bar& large_change(int32_t large_change);
      
      /// @brief Gets the upper limit of the range this track_bar is working with.
      /// @return The maximum value for the track_bar. The default is 10.
      virtual int32_t maximum() {return maximum_;}
      /// @brief sets the upper limit of the range this track_bar is working with.
      /// @param maximum The maximum value for the track_bar. The default is 10.
      /// @return Current track_bar instance.
      /// @remarks You can use the set_range method to set both the maximum and minimum properties at the same time.
      virtual track_bar& maximum(int32_t maximum);
      
      /// @brief Gets the lower limit of the range this track_bar is working with.
      /// @return The minimum value for the track_bar. The default is 0.
      virtual int32_t minimum() {return minimum_;}
      /// @brief Sets the lower limit of the range this track_bar is working with.
      /// @param minimum The minimum value for the track_bar. The default is 0.
      /// @return Current track_bar instance.
      /// @remarks You can use the set_range method to set both the maximum and minimum properties at the same time.
      virtual track_bar& minimum(int32_t minimum);
      
      /// @brief Gets a value indicating the horizontal or vertical orientation of the track bar.
      /// @return One of the orientation values.
      virtual forms::orientation orientation() const {return orientation_;}
      /// @brief Sets a value indicating the horizontal or vertical orientation of the track bar.
      /// @param orientation One of the orientation values.
      /// @return Current track_bar instance.
      /// @remarks When the orientation property is set to orientation::horizontal, the scroll box moves from left to right as the value increases. When the orientation property is set to orientation::vertical, the scroll box moves from bottom to top as the Value increases.
      virtual track_bar& orientation(forms::orientation orientation);

      /// @brief Gets he value added to or subtracted from the Value property when the scroll box is moved a small distance.
      /// @return A numeric value. The default value is 1.
      /// @remarks When the user presses one of the arrow keys, the value property changes according to the value set in the small_change property.
      /// @remarks You might consider setting the value of small_change to a percentage of the value of the height (for a vertically oriented track bar) or width (for a horizontally oriented track bar) property. This sets the distance your track bar moves proportionate to its size.
      virtual int32_t small_change() {return small_change_;}
      /// @brief Sets the value added to or subtracted from the Value property when the scroll box is moved a small distance.
      /// @param small_change A numeric value. The default value is 1.
      /// @return Current track_bar instance.
      /// @remarks When the user presses one of the arrow keys, the value property changes according to the value set in the small_change property.
      /// @remarks You might consider setting the value of small_change to a percentage of the value of the height (for a vertically oriented track bar) or width (for a horizontally oriented track bar) property. This sets the distance your track bar moves proportionate to its size.
      virtual track_bar& small_change(int32_t small_change);
      
      /// @brief Gets a value that specifies the delta between ticks drawn on the control.
      /// @return The numeric value representing the delta between ticks. The default is 1.
      /// @remarks For a track_bar with a large range of values between the minimum and the maximum properties, it might be impractical to draw all the ticks for values on the control. For example, if you have a control with a range of 100, passing in a value of 5 here causes the control to draw 20 ticks. In this case, each tick represents five units in the range of values.
      virtual int32_t tick_frequency() {return tick_frequency_;}
      /// @brief Sets a value that specifies the delta between ticks drawn on the control.
      /// @param tick_frequency The numeric value representing the delta between ticks. The default is 1.
      /// @return Current track_bar instance.
      /// @remarks For a track_bar with a large range of values between the minimum and the maximum properties, it might be impractical to draw all the ticks for values on the control. For example, if you have a control with a range of 100, passing in a value of 5 here causes the control to draw 20 ticks. In this case, each tick represents five units in the range of values.
      virtual track_bar& tick_frequency(int32_t tick_frequency);
      
      /// @brief Gets a value indicating how to display the tick marks on the track bar.
      /// @return One of the Ttick_style values. The default is bottom_right.
      /// @remarks You can use the tick_style property to modify the manner in which the tick marks are displayed on the track bar.
      virtual forms::tick_style tick_style() {return tick_style_;}
      /// @brief Sets a value indicating how to display the tick marks on the track bar.
      /// @param tick_style One of the tick_style values. The default is bottom_right.
      /// @return Current track_bar instance.
      /// @remarks You can use the tick_style property to modify the manner in which the tick marks are displayed on the track bar.
      virtual track_bar& tick_style(forms::tick_style tick_style);

      /// @brief Gets a numeric value that represents the current position of the scroll box on the track bar.
      /// @return A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @remarks The Value property contains the number that represents the current position of the scroll box on the track bar.
      virtual int32_t value() {return value_;}
      /// @brief Sets a numeric value that represents the current position of the scroll box on the track bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @return Current track_bar instance.
      /// @remarks The Value property contains the number that represents the current position of the scroll box on the track bar.
      virtual track_bar& value(int32_t value);

      /// @brief Sets the minimum and maximum values for a xtd::forms::track_bar.
      /// @param min_value The lower limit of the range of the track bar.
      /// @param max_value The upper limit of the range of the track bar.
      /// @remarks You can use this method to set the entire range for the xtd::forms::track_bar at the same time. To set the minimum or maximum values individually, use the xtd::forms::track_bar::minimum and xtd::forms::track_bar::maximum properties. If the min_value parameter is greater than the max_value parameter, max_value is set equal to min_value.
      void set_range(int min_value, int max_value) {
        minimum(min_value);
        maximum(min_value > max_value ? min_value : max_value);
      }
      
      /// @brief Returns a string that represents the track_bar control.
      /// @return A string that represents the current progress_bar.
      /// @remarks The return string includes the type and the values for the minimum, maximum, and value properties.
      std::string to_string() const override {return strings::format("{}, minimum: {}, maximum: {}, value: {}", strings::full_class_name(*this), minimum_, maximum_, value_);}
      
      /// @brief Occurs when either a mouse or keyboard action moves the scroll box.
      /// @ingroup events
      event<track_bar, event_handler<control&>> scroll;

      /// @brief Occurs when the value property of a track bar changes, either by movement of the scroll box or by manipulation in code.
      /// @ingroup events
      event<track_bar, event_handler<control&>> value_changed;
      
    protected:
      /// @brief Gets the required creation parameters when the control handle is created.
      /// @return A create_params that contains the required creation parameters when the handle to the control is created.
      forms::create_params create_params() const override;
      
      drawing::size measure_control() const override;
      
      /// @brief Overrides control::on_handle_created(const event_args&)
      /// @param e A EventArgs that contains the event data.
      void on_handle_created(const event_args& e) override;

      /// @brief Raises the track_bar::scroll event.
      /// @param e An event_args that contains the event data.
      /// @remarks You can use the OnScroll event to update other controls as the position of the scroll box changes.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_scroll method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inheritors
      /// @remarks When overriding on_scroll(const event_args&) in a derived class, be sure to call the base class' on_scroll(const event_args&) method so that registered delegates receive the event.
      virtual void on_scroll(const event_args& e);
      
      /// @brief Raises the track_bar::value_changed event.
      /// @param e The event_args that contains the event data.
      virtual void on_value_changed(const event_args& e);
  
      /// @brief Performs the work of setting the specified bounds of this control.
      /// @param x The new left property value of the control.
      /// @param y The new top property value of the control.
      /// @param width The new width property value of the control.
      /// @param height The new height property value of the control.
      /// @param specified A bitwise combination of the bounds_specified values.
      void set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) override {
        control::set_bounds_core(x, y, width, height, specified);
        if ((specified & bounds_specified::width) == bounds_specified::width || (specified & bounds_specified::height) == bounds_specified::height)
          recreate_handle();
      }
      
      /// @brief Sets the size of the client area of the control.
      /// @param width The client area width, in pixels.
      /// @param height The client area height, in pixels.
      void set_client_size_core(int32_t width, int32_t height) override {
        control::set_client_size_core(width, height);
        recreate_handle();
      }

      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;

      /// @cond
      int32_t large_change_ = 5;
      int32_t maximum_ = 10;
      int32_t minimum_ = 0;
      forms::orientation orientation_ = forms::orientation::horizontal;
      int32_t small_change_ = 1;
      int32_t tick_frequency_ = 1;
      forms::tick_style tick_style_ = forms::tick_style::bottom_right;
      int32_t value_ = 0;
      /// @endcond

    private:
      void wm_scroll(message& message);
    };
  }
}

/// @file
/// @brief Contains xtd::forms::track_bar control.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "control.hpp"
#include "orientation.hpp"
#include "tick_style.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows track bar.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/track_bar>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks The track_bar is a scrollable control similar to the scroll_bar control. You can configure ranges through which the value of the value property of a track bar scrolls by setting the minimum property to specify the lower end of the range and the maximum property to specify the upper end of the range.
    /// @remarks The large_change property defines the increment to add or subtract from the value property when clicks occur on either side of the scroll box. The track bar can be displayed horizontally or vertically.
    /// @remarks You can use this control to input numeric data obtained through the value property. You can display this numeric data in a control or use it in code.
    /// @par Appearance
    /// |       | Windows                                | macOS                                  | Gnome                                  |
    /// | ----- | -------------------------------------- | -------------------------------------- | -------------------------------------- |
    /// | Light |  @image html control_track_bar_w.png   |  @image html control_track_bar_m.png   |  @image html control_track_bar_g.png   |
    /// | Dark  |  @image html control_track_bar_wd.png  |  @image html control_track_bar_md.png  |  @image html control_track_bar_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of track_bar control.
    /// @include track_bar.cpp
    class forms_export_ track_bar : public control {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the track_bar class.
      /// @remarks The track_bar is created with a default horizontal orientation and a range of 0 to 10, with a tick mark shown for every value.
      track_bar();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value to be added to or subtracted from the value property when the scroll box is moved a large distance.
      /// @return A numeric value. The default is 5.
      /// @remarks When the user presses the PAGE UP or PAGE DOWN key or clicks the track bar on either side of the scroll box, the value property changes according to the value set in the large_change property. You might consider setting the large_change value to a percentage of the height (for a vertically oriented track bar) or width (for a horizontally oriented track bar) value. This keeps the distance your track bar moves proportionate to its size.
      virtual int32 large_change() const noexcept;
      /// @brief Sets a value to be added to or subtracted from the value property when the scroll box is moved a large distance.
      /// @param large_change A numeric value. The default is 5.
      /// @return Current track_bar instance.
      /// @remarks When the user presses the PAGE UP or PAGE DOWN key or clicks the track bar on either side of the scroll box, the value property changes according to the value set in the large_change property. You might consider setting the large_change value to a percentage of the height (for a vertically oriented track bar) or width (for a horizontally oriented track bar) value. This keeps the distance your track bar moves proportionate to its size.
      virtual track_bar& large_change(int32 large_change);
      
      /// @brief Gets the upper limit of the range this track_bar is working with.
      /// @return The maximum value for the track_bar. The default is 10.
      virtual int32 maximum() const noexcept;
      /// @brief sets the upper limit of the range this track_bar is working with.
      /// @param maximum The maximum value for the track_bar. The default is 10.
      /// @return Current track_bar instance.
      /// @remarks You can use the set_range method to set both the maximum and minimum properties at the same time.
      virtual track_bar& maximum(int32 maximum);
      
      /// @brief Gets the lower limit of the range this track_bar is working with.
      /// @return The minimum value for the track_bar. The default is 0.
      virtual int32 minimum() const noexcept;
      /// @brief Sets the lower limit of the range this track_bar is working with.
      /// @param minimum The minimum value for the track_bar. The default is 0.
      /// @return Current track_bar instance.
      /// @remarks You can use the set_range method to set both the maximum and minimum properties at the same time.
      virtual track_bar& minimum(int32 minimum);
      
      /// @brief Gets a value indicating the horizontal or vertical orientation of the track bar.
      /// @return One of the orientation values.
      virtual forms::orientation orientation() const noexcept;
      /// @brief Sets a value indicating the horizontal or vertical orientation of the track bar.
      /// @param orientation One of the orientation values.
      /// @return Current track_bar instance.
      /// @remarks When the orientation property is set to orientation::horizontal, the scroll box moves from left to right as the value increases. When the orientation property is set to orientation::vertical, the scroll box moves from bottom to top as the Value increases.
      virtual track_bar& orientation(forms::orientation orientation);
      
      /// @brief Gets he value added to or subtracted from the Value property when the scroll box is moved a small distance.
      /// @return A numeric value. The default value is 1.
      /// @remarks When the user presses one of the arrow keys, the value property changes according to the value set in the small_change property.
      /// @remarks You might consider setting the value of small_change to a percentage of the value of the height (for a vertically oriented track bar) or width (for a horizontally oriented track bar) property. This sets the distance your track bar moves proportionate to its size.
      virtual int32 small_change() const noexcept;
      /// @brief Sets the value added to or subtracted from the Value property when the scroll box is moved a small distance.
      /// @param small_change A numeric value. The default value is 1.
      /// @return Current track_bar instance.
      /// @remarks When the user presses one of the arrow keys, the value property changes according to the value set in the small_change property.
      /// @remarks You might consider setting the value of small_change to a percentage of the value of the height (for a vertically oriented track bar) or width (for a horizontally oriented track bar) property. This sets the distance your track bar moves proportionate to its size.
      virtual track_bar& small_change(int32 small_change);
      
      /// @brief Gets a value that specifies the delta between ticks drawn on the control.
      /// @return The numeric value representing the delta between ticks. The default is 1.
      /// @remarks For a track_bar with a large range of values between the minimum and the maximum properties, it might be impractical to draw all the ticks for values on the control. For example, if you have a control with a range of 100, passing in a value of 5 here causes the control to draw 20 ticks. In this case, each tick represents five units in the range of values.
      virtual int32 tick_frequency() const noexcept;
      /// @brief Sets a value that specifies the delta between ticks drawn on the control.
      /// @param tick_frequency The numeric value representing the delta between ticks. The default is 1.
      /// @return Current track_bar instance.
      /// @remarks For a track_bar with a large range of values between the minimum and the maximum properties, it might be impractical to draw all the ticks for values on the control. For example, if you have a control with a range of 100, passing in a value of 5 here causes the control to draw 20 ticks. In this case, each tick represents five units in the range of values.
      virtual track_bar& tick_frequency(int32 tick_frequency);
      
      /// @brief Gets a value indicating how to display the tick marks on the track bar.
      /// @return One of the Tick_style values. The default is bottom_right.
      /// @remarks You can use the tick_style property to modify the manner in which the tick marks are displayed on the track bar.
      virtual forms::tick_style tick_style() const noexcept;
      /// @brief Sets a value indicating how to display the tick marks on the track bar.
      /// @param tick_style One of the tick_style values. The default is bottom_right.
      /// @return Current track_bar instance.
      /// @remarks You can use the tick_style property to modify the manner in which the tick marks are displayed on the track bar.
      virtual track_bar& tick_style(forms::tick_style tick_style);
      
      /// @brief Gets a numeric value that represents the current position of the scroll box on the track bar.
      /// @return A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @remarks The Value property contains the number that represents the current position of the scroll box on the track bar.
      virtual int32 value() const noexcept;
      /// @brief Sets a numeric value that represents the current position of the scroll box on the track bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @return Current track_bar instance.
      /// @remarks The Value property contains the number that represents the current position of the scroll box on the track bar.
      virtual track_bar& value(int32 value);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Sets the minimum and maximum values for a xtd::forms::track_bar.
      /// @param min_value The lower limit of the range of the track bar.
      /// @param max_value The upper limit of the range of the track bar.
      /// @remarks You can use this method to set the entire range for the xtd::forms::track_bar at the same time. To set the minimum or maximum values individually, use the xtd::forms::track_bar::minimum and xtd::forms::track_bar::maximum properties. If the min_value parameter is greater than the max_value parameter, max_value is set equal to min_value.
      void set_range(int32 min_value, int32 max_value);
      
      /// @brief Returns a string that represents the track_bar control.
      /// @return A string that represents the current progress_bar.
      /// @remarks The return string includes the type and the values for the minimum, maximum, and value properties.
      xtd::string to_string() const noexcept override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create();
      /// @brief A factory to create an xtd::forms::track_bar with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::track_bar with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::track_bar with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @param name The name of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @brief A factory to create an xtd::forms::track_bar with specified value.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(int32 value);
      /// @brief A factory to create an xtd::forms::track_bar with specified value, and location.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(int32 value, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::track_bar with specified value, location, and size.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(int32 value, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::track_bar with specified value, location, size, and name.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @param name The name of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(int32 value, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @brief A factory to create an xtd::forms::track_bar with specified value, and maximum.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(int32 value, int32 maximum);
      /// @brief A factory to create an xtd::forms::track_bar with specified value, minimum, maximum, and location.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(int32 value, int32 maximum, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::track_bar with specified value, maximum, location, and size.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(int32 value, int32 maximum, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::track_bar with specified value, maximum, location, size, and name.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @param name The name of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(int32 value, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @brief A factory to create an xtd::forms::track_bar with specified value, minimum, and maximum.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(int32 value, int32 minimum, int32 maximum);
      /// @brief A factory to create an xtd::forms::track_bar with specified value, minimum, maximum, and location.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(int32 value, int32 minimum, int32 maximum, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::track_bar with specified value, minimum, maximum, location, and size.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::track_bar with specified value, minimum, maximum, location, size, and name.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @param name The name of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @param name The name of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, and value.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, int32 value);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, value, and location.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, int32 value, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, value, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, int32 value, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, value, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @param name The name of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, int32 value, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, value, and maximum.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, int32 value, int32 maximum);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, value, maximum, and location.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, int32 value, int32 maximum, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, value, maximum, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, int32 value, int32 maximum, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, value, maximum, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @param name The name of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, int32 value, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, value, minimum, and maximum.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, int32 value, int32 minimum, int32 maximum);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, value, minimum, maximum, and location.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, value, minimum, maximum, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::track_bar with specified parent, value, minimum, maximum, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::track_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::track_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::track_bar.
      /// @param name The name of the xtd::forms::track_bar.
      /// @return New xtd::forms::track_bar created.
      static track_bar create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::string& name);
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when either a mouse or keyboard action moves the scroll box.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      event<track_bar, event_handler> scroll;
      
      /// @brief Occurs when the value property of a track bar changes, either by movement of the scroll box or by manipulation in code.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      event<track_bar, event_handler> value_changed;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      /// @brief Gets the required creation parameters when the control handle is created.
      /// @return A create_params that contains the required creation parameters when the handle to the control is created.
      forms::create_params create_params() const noexcept override;
      
      drawing::size default_size() const noexcept override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return A new object that is a copy of this instance.
      /// @par Notes to Implementers
      /// All controls must be override the clone method.
      xtd::uptr<xtd::object> clone() const override;
      
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
      void set_bounds_core(int32 x, int32 y, int32 width, int32 height, bounds_specified specified) override;
      
      /// @brief Sets the size of the client area of the control.
      /// @param width The client area width, in pixels.
      /// @param height The client area height, in pixels.
      void set_client_size_core(int32 width, int32 height) override;
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_scroll_control(message& message);
      
      xtd::sptr<data> data_;
    };
  }
}

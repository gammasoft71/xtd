/// @file
/// @brief Contains xtd::forms::numeric_up_down control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "application.hpp"
#include "up_down_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows numeric up down.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/numeric_up_down>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks A numeric_up_down control contains a single numeric value that can be incremented or decremented by clicking the up or down buttons of the control. The user can also enter in a value, unless the read_only property is set to `true`.
    /// @remarks The numeric display can be formatted by setting the decimal_places, hexadecimal, or thousands_separator properties. To display hexadecimal values in the control, set the hexadecimal property to `true`. To display a thousands separator in decimal numbers when appropriate, set the thousands_separator property to `true`. To specify the number of digits displayed after the decimal symbol, set the decimal_places property to the number of decimal places to display.
    /// @remarks To specify the allowable range of values for the control, set the minimum and maximum properties. Set the increment value to specify the value to be incremented or decremented to the value property when the user clicks the up or down arrow buttons. You can increase the speed that the control moves through numbers when the user continuously presses the up or down arrow by setting the accelerations property.
    /// @remarks When the up_button or down_button methods are called, either in code or by the click of the up or down buttons, the new value is validated and the control is updated with the new value in the appropriate format. Specifically, if the user_edit property is set to `true`, the parse_edit_text method is called prior to validating or updating the value. The value is then verified to be between the minimum and maximum values, and the update_edit_text method is called.
    /// @par Appearance
    /// |       | Windows                                      | macOS                                        | Gnome                                        |
    /// | ----- | -------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
    /// | Light |  @image html control_numeric_up_down_w.png   |  @image html control_numeric_up_down_m.png   |  @image html control_numeric_up_down_g.png   |
    /// | Dark  |  @image html control_numeric_up_down_wd.png  |  @image html control_numeric_up_down_md.png  |  @image html control_numeric_up_down_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of numeric up down control.
    /// @include numeric_up_down.cpp
    class forms_export_ numeric_up_down : public xtd::forms::up_down_base {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the numeric_up_down class.
      numeric_up_down();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the number of decimal places to display in the spin box (also known as an up-down control). This property doesn't affect the value property.
      /// @return The number of decimal places to display in the spin box. The default is 0.
      /// @remarks When the decimal_places property is set, the update_edit_text method is called to update the spin box's display to the new format.
      [[nodiscard]] virtual auto decimal_place() const noexcept -> xtd::uint32;
      /// @brief Sets the number of decimal places to display in the spin box (also known as an up-down control). This property doesn't affect the value property.
      /// @param value The number of decimal places to display in the spin box. The default is 0.
      /// @return Current numeric_up_down.
      /// @remarks When the decimal_places property is set, the update_edit_text method is called to update the spin box's display to the new format.
      virtual auto decimal_place(xtd::uint32 value) -> numeric_up_down&;
      
      /// @brief Gets the value to increment or decrement the spin box (also known as an up-down control) when the up or down buttons are clicked.
      /// @return The value to increment or decrement the Value property when the up or down buttons are clicked on the spin box. The default value is 1.
      /// @remarks Clicking the up button causes the value property to increment by the amount specified by the increment property and approach the maximum property. Clicking the down button causes the value property to be decremented by the amount specified by the increment property and approach the minimum property.
      [[nodiscard]] virtual auto increment() const noexcept -> double;
      /// @brief Sets the value to increment or decrement the spin box (also known as an up-down control) when the up or down buttons are clicked.
      /// @param value The value to increment or decrement the Value property when the up or down buttons are clicked on the spin box. The default value is 1.
      /// @return Current numeric_up_down.
      /// @remarks Clicking the up button causes the value property to increment by the amount specified by the increment property and approach the maximum property. Clicking the down button causes the value property to be decremented by the amount specified by the increment property and approach the minimum property.
      virtual auto increment(double value) -> numeric_up_down&;
      
      /// @brief Gets the maximum value for the spin box (also known as an up-down control).
      /// @return The maximum value for the spin box. The default value is 100.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      [[nodiscard]] virtual auto maximum() const noexcept -> double;
      /// @brief Sets the maximum value for the spin box (also known as an up-down control).
      /// @param value The maximum value for the spin box. The default value is 100.
      /// @return Current numeric_up_down.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      virtual auto maximum(double value) -> numeric_up_down&;
      
      /// @brief Gets the minimum allowed value for the spin box (also known as an up-down control).
      /// @return The minimum allowed value for the spin box. The default value is 0.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      [[nodiscard]] virtual auto minimum() const noexcept -> double;
      /// @brief Sets the minimum allowed value for the spin box (also known as an up-down control).
      /// @param value The minimum allowed value for the spin box. The default value is 0.
      /// @return Current numeric_up_down.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      virtual auto minimum(double value) -> numeric_up_down&;
      
      /// @brief Gets the value assigned to the spin box (also known as an up-down control).
      /// @return The numeric value of the numeric_up_down control.
      /// @remarks When the value property is set, the new value is validated to be between the minimum and maximum values. Following this, the update_edit_text method is called to update the spin box's display with the new value in the appropriate format.
      [[nodiscard]] virtual auto value() const noexcept -> double;
      /// @brief Sets the value assigned to the spin box (also known as an up-down control).
      /// @param value The numeric value of the numeric_up_down control.
      /// @return Current numeric_up_down.
      /// @remarks When the value property is set, the new value is validated to be between the minimum and maximum values. Following this, the update_edit_text method is called to update the spin box's display with the new value in the appropriate format.
      virtual auto value(double value) -> numeric_up_down&;
      
      /// @brief Gets a value indicate if value can be wrapped.
      /// @return `true` if value can be wrapped; otherwise `false`. The default is `false`.
      [[nodiscard]] virtual auto wrapped() const noexcept -> bool;
      /// @brief Sets a value indicate if value can be wrapped.
      /// @param value `true` if value can be wrapped; otherwise `false`. The default is `false`.
      /// @return Current numeric_up_down.
      virtual auto wrapped(bool value) -> numeric_up_down&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Sets the minimum and maximum values for a track_bar.
      /// @param min_value The lower limit of the range of the track bar.
      /// @param max_value The upper limit of the range of the track bar.
      /// @remarks You can use this method to set the entire range for the track_bar at the same time. To set the minimum or maximum values individually, use the minimum and maximum properties. If the min_value parameter is greater than the max_value parameter, max_value is set equal to min_value.
      auto set_range(double min_value, double max_value) -> void;
      
      /// @brief Returns a string that represents the track_bar control.
      /// @return A string that represents the current numeric_up_down.
      /// @remarks The return string includes the type and the values for the minimum, maximum, and value properties.
      [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create() -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @param name The name of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified value.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(double value) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified value, and location.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(double value, const xtd::drawing::point& location) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified value, location, and size.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(double value, const xtd::drawing::point& location, const xtd::drawing::size& size) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified value, location, size, and name.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @param name The name of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(double value, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified value, and maximum.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(double value, double maximum) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified value, minimum, maximum, and location.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(double value, double maximum, const xtd::drawing::point& location) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified value, maximum, location, and size.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(double value, double maximum, const xtd::drawing::point& location, const xtd::drawing::size& size) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified value, maximum, location, size, and name.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @param name The name of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(double value, double maximum, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified value, minimum, and maximum.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(double value, double minimum, double maximum) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified value, minimum, maximum, and location.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(double value, double minimum, double maximum, const xtd::drawing::point& location) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified value, minimum, maximum, location, and size.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(double value, double minimum, double maximum, const xtd::drawing::point& location, const xtd::drawing::size& size) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified value, minimum, maximum, location, size, and name.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @param name The name of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(double value, double minimum, double maximum, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @param name The name of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, and value.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, double value) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, value, and location.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, double value, const xtd::drawing::point& location) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, value, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, double value, const xtd::drawing::point& location, const xtd::drawing::size& size) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, value, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @param name The name of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, double value, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, value, and maximum.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, double value, double maximum) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, value, maximum, and location.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, double value, double maximum, const xtd::drawing::point& location) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, value, maximum, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, double value, double maximum, const xtd::drawing::point& location, const xtd::drawing::size& size) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, value, maximum, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @param name The name of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, double value, double maximum, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, value, minimum, and maximum.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, double value, double minimum, double maximum) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, value, minimum, maximum, and location.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, double value, double minimum, double maximum, const xtd::drawing::point& location) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, value, minimum, maximum, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, double value, double minimum, double maximum, const xtd::drawing::point& location, const xtd::drawing::size& size) -> numeric_up_down;
      /// @brief A factory to create an xtd::forms::numeric_up_down with specified parent, value, minimum, maximum, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::numeric_up_down.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::numeric_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::numeric_up_down.
      /// @param name The name of the xtd::forms::numeric_up_down.
      /// @return New xtd::forms::numeric_up_down created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, double value, double minimum, double maximum, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> numeric_up_down;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the value property has been changed in some way.
      xtd::event<numeric_up_down, xtd::event_handler> value_changed;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      auto create_params() const noexcept -> xtd::forms::create_params override;
      auto default_back_color() const noexcept -> xtd::drawing::color override;
      auto default_fore_color() const noexcept -> xtd::drawing::color override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Overrides control::on_handle_created(const event_args&)
      /// @param e A EventArgs that contains the event data.
      auto on_handle_created(const event_args& e) -> void override;
      
      /// @brief Raises the numeric_up_down::value_changed event.
      /// @param e An event_args that contains the event data.
      virtual auto on_value_changed(const event_args& e) -> void;
      
      auto on_lost_focus(const event_args& e) -> void override;
      
      auto wnd_proc(message& message) -> void override;
      /// @}
      
      /// @cond
      auto wm_command_control(message& message) -> void;
      /// @endcond
      
    private:
      xtd::sptr<data> data_;
    };
  }
}

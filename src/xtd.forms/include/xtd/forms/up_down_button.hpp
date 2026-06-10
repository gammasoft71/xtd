/// @file
/// @brief Contains xtd::forms::up_down_button control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "button_base.hpp"
#include "orientation.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows up down button.
    /// ```cpp
    /// class forms_export_ up_down_button : public xtd::forms::button_base
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::button_base → xtd::forms::up_down_button
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/up_down_button>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                     | macOS                                       | Gnome                                       |
    /// | ----- | ------------------------------------------- | ------------------------------------------- | ------------------------------------------- |
    /// | Light |  @image html control_up_down_button_w.png   |  @image html control_up_down_button_m.png   |  @image html control_up_down_button_g.png   |
    /// | Dark  |  @image html control_up_down_button_wd.png  |  @image html control_up_down_button_md.png  |  @image html control_up_down_button_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of up down button control.
    /// @include up_down_button.cpp
    class forms_export_ up_down_button : public xtd::forms::button_base {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of up_down_button class.
      up_down_button();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the maximum value for the up_down_button control.
      /// @return The maximum value for the up down button. The default value is 100.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      [[nodiscard]] virtual auto maximum() const noexcept -> xtd::int32;
      /// @brief Sets the maximum value for the up_down_button control.
      /// @param value The maximum value for the up down button. The default value is 100.
      /// @return Current numeric_up_down.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      virtual auto maximum(xtd::int32 value) -> up_down_button&;
      
      /// @brief Gets the minimum allowed value for the up_down_button control.
      /// @return The minimum allowed value for the up down button. The default value is 0.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      [[nodiscard]] virtual auto minimum() const noexcept -> xtd::int32;
      /// @brief Sets the minimum allowed value for the up_down_button control.
      /// @param value The minimum allowed value for the up down button. The default value is 0.
      /// @return Current numeric_up_down.
      /// @remarks When the maximum property is set, the minimum property is evaluated and the update_edit_text method is called. If the minimum property is greater than the new maximum property, the minimum property value is set equal to the maximum value. If the current Value is greater than the new Maximum value. the value property value is set equal to the maximum value.
      virtual auto minimum(xtd::int32 value) -> up_down_button&;
      
      /// @brief Gets a value indicating the horizontal or vertical orientation of the up down button.
      /// @return One of the orientation values.
      [[nodiscard]] virtual auto orientation() const noexcept -> xtd::forms::orientation;
      /// @brief Sets a value indicating the horizontal or vertical orientation of the up down button
      /// @param value One of the orientation values.
      /// @param When the orientation property is set to orientation::horizontal, the scroll box moves from left to right as the value increases. When the orientation property is set to orientation::vertical, the scroll box moves from bottom to top as the Value increases.
      virtual auto orientation(xtd::forms::orientation value) -> up_down_button&;
      
      /// @brief Gets the value assigned to the up_down_button control.
      /// @return The numeric value of the up down button control.
      /// @remarks When the value property is set, the new value is validated to be between the minimum and maximum values. Following this, the update_edit_text method is called to update the spin box's display with the new value in the appropriate format.
      [[nodiscard]] virtual auto value() const noexcept -> xtd::int32;
      /// @brief Sets the value assigned to the up_down_button control.
      /// @param value The numeric value of the up down button control.
      /// @return Current numeric_up_down.
      /// @remarks When the value property is set, the new value is validated to be between the minimum and maximum values. Following this, the update_edit_text method is called to update the spin box's display with the new value in the appropriate format.
      virtual auto value(xtd::int32 value) -> up_down_button&;
      
      /// @brief Gets a value indicate if value can be wrapped.
      /// @return `true` if value can be wrapped; otherwise `false`. The default is `false`.
      [[nodiscard]] virtual auto wrapped() const noexcept -> bool;
      /// @brief Sets a value indicate if value can be wrapped.
      /// @param value `true` if value can be wrapped; otherwise `false`. The default is `false`.
      /// @return Current numeric_up_down.
      virtual auto wrapped(bool value) -> up_down_button&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Sets the minimum and maximum values for a up_down_button.
      /// @param min_value The lower limit of the range of the track bar.
      /// @param max_value The upper limit of the range of the track bar.
      /// @remarks You can use this method to set the entire range for the up_down_button at the same time. To set the minimum or maximum values individually, use the minimum and maximum properties. If the min_value parameter is greater than the max_value parameter, max_value is set equal to min_value.
      auto set_range(xtd::int32 min_value, xtd::int32 max_value) -> void;
      
      /// @brief Returns a string that represents the up_down_button control.
      /// @return A string that represents the current progress_bar.
      /// @remarks The return string includes the type and the values for the minimum, maximum, and value properties.
      [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create() -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @param name The name of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified value.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(xtd::int32 value) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified value, and location.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(xtd::int32 value, const xtd::drawing::point& location) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified value, location, and size.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(xtd::int32 value, const xtd::drawing::point& location, const xtd::drawing::size& size) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified value, location, size, and name.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @param name The name of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(xtd::int32 value, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified value, and maximum.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(xtd::int32 value, xtd::int32 maximum) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified value, minimum, maximum, and location.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(xtd::int32 value, xtd::int32 maximum, const xtd::drawing::point& location) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified value, maximum, location, and size.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(xtd::int32 value, xtd::int32 maximum, const xtd::drawing::point& location, const xtd::drawing::size& size) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified value, maximum, location, size, and name.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @param name The name of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(xtd::int32 value, xtd::int32 maximum, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified value, minimum, and maximum.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(xtd::int32 value, xtd::int32 minimum, xtd::int32 maximum) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified value, minimum, maximum, and location.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(xtd::int32 value, xtd::int32 minimum, xtd::int32 maximum, const xtd::drawing::point& location) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified value, minimum, maximum, location, and size.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(xtd::int32 value, xtd::int32 minimum, xtd::int32 maximum, const xtd::drawing::point& location, const xtd::drawing::size& size) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified value, minimum, maximum, location, size, and name.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @param name The name of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(xtd::int32 value, xtd::int32 minimum, xtd::int32 maximum, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @param name The name of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, and value.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::int32 value) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, value, and location.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::int32 value, const xtd::drawing::point& location) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, value, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::int32 value, const xtd::drawing::point& location, const xtd::drawing::size& size) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, value, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @param name The name of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::int32 value, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, value, and maximum.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::int32 value, xtd::int32 maximum) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, value, maximum, and location.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::int32 value, xtd::int32 maximum, const xtd::drawing::point& location) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, value, maximum, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::int32 value, xtd::int32 maximum, const xtd::drawing::point& location, const xtd::drawing::size& size) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, value, maximum, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @param name The name of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::int32 value, xtd::int32 maximum, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, value, minimum, and maximum.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::int32 value, xtd::int32 minimum, xtd::int32 maximum) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, value, minimum, maximum, and location.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::int32 value, xtd::int32 minimum, xtd::int32 maximum, const xtd::drawing::point& location) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, value, minimum, maximum, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::int32 value, xtd::int32 minimum, xtd::int32 maximum, const xtd::drawing::point& location, const xtd::drawing::size& size) -> up_down_button;
      /// @brief A factory to create an xtd::forms::up_down_button with specified parent, value, minimum, maximum, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::up_down_button.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::up_down_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::up_down_button.
      /// @param name The name of the xtd::forms::up_down_button.
      /// @return New xtd::forms::up_down_button created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, xtd::int32 value, xtd::int32 minimum, xtd::int32 maximum, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> up_down_button;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when either a mouse or keyboard action moves the scroll box.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<up_down_button, xtd::event_handler> scroll;
      
      /// @brief Occurs when the value of the value property changes.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<up_down_button, xtd::event_handler> value_changed;
      /// @}
      
    protected:
    
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Overrides control::on_handle_created(const event_args&)
      /// @param e A EventArgs that contains the event data.
      auto on_handle_created(const xtd::event_args& e) -> void override;
      
      /// @brief Raises the up_down_button::scroll event.
      /// @param e An event_args that contains the event data.
      /// @remarks You can use the OnScroll event to update other controls as the position of the scroll box changes.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_scroll method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      /// @par Notes to Inheritors
      /// @remarks When overriding on_scroll(const event_args&) in a derived class, be sure to call the base class' on_scroll(const event_args&) method so that registered delegates receive the event.
      virtual auto on_scroll(const xtd::event_args& e) -> void;
      
      /// @brief Raises the up_down_button::value_changed event.
      /// @param e An event_args that contains the event data.
      virtual auto on_value_changed(const xtd::event_args& e) -> void;
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      auto wnd_proc(xtd::forms::message& message) -> void override;
      /// @}
      
    private:
      auto wm_scroll_control(xtd::forms::message& message) -> void;
      
      xtd::sptr<data> data_;
    };
  }
}

/// @file
/// @brief Contains xtd::forms::light_button control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "visual_styles/check_box_state.hpp"
#include "appearance.hpp"
#include "button_base.hpp"
#include "check_state.hpp"
#include <xtd/drawing/system_colors>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows light_button.
    /// ```cpp
    /// class forms_export_ light_button : public xtd::forms::button_base
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::button_base → xtd::forms::light_button
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/light_button>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks Use a light_button to give the user an option, such as true/false or yes/no. The light_button control can display an image or text or both.
    /// @remarks light_button and radio_button controls have a similar function: they allow the user to choose from a list of options. light_button controls let the user pick a combination of options. In contrast, radio_button controls allow a user to choose from mutually exclusive options.
    /// @remarks The appearance property determines whether the light_button appears as a typical light_button or as a button.
    /// @remarks The three_state property determines whether the control supports two or three states. Use the checked property to get or set the value of a two-state light_button control and use the check_state property to get or set the value of a three-state light_button control.
    /// @note If the three_state property is set to `true`, the checked property will return `true` for either a checked or indeterminate state.
    /// @remarks The flat_style property determines the style and appearance of the control. If the flat_style property is set to flat_style::system, the user's operating system determines the appearance of the control.
    /// @note When the flat_style property is set to flat_style::system, the check_align property is ignored and the control is displayed using the content_alignment::middle_left or content_alignment::middle_right alignment. If the check_align property is set to one of the right alignments, the control is displayed using the content_alignment::middle_right alignment; otherwise, it is displayed using the content_alignment::middle_left alignment.
    /// @par Appearance
    /// |       | Windows                                   | macOS                                     | Gnome                                     |
    /// | ----- | ----------------------------------------- | ----------------------------------------- | ----------------------------------------- |
    /// | Light |  @image html control_light_button_w.png   |  @image html control_light_button_m.png   |  @image html control_light_button_g.png   |
    /// | Dark  |  @image html control_light_button_wd.png  |  @image html control_light_button_md.png  |  @image html control_light_button_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of light_button control with bitmap.
    /// @include light_button.cpp
    class forms_export_ light_button : public xtd::forms::button_base {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the light_button class.
      /// @remarks By default the light_button displays no caption. To specify the caption text, set the text property.
      light_button();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether the checked or check_state values and the light_button's appearance are automatically changed when the light_button is clicked.
      /// @return `true` if the checked value or check_state value and the appearance of the control are automatically changed on the click event; otherwise, `false`. The default value is `true`.
      /// @remarks If auto_check is set to `false`, you will need to add code to update the checked or check_state values in the click event handler.
      /// @par Examples
      /// The following code example demonstrates the use of light_button auto_check.
      /// @include light_button.cpp
      [[nodiscard]] virtual auto auto_check() const noexcept -> bool;
      /// @brief Sets a value indicating whether the checked or check_state values and the light_button's appearance are automatically changed when the light_button is clicked.
      /// @param value `true` if the checked value or check_state value and the appearance of the control are automatically changed on the click event; otherwise, `false`. The default value is `true`.
      /// @remarks If auto_check is set to `false`, you will need to add code to update the checked or check_state values in the click event handler.
      virtual auto auto_check(bool value) -> light_button&;
      
      /// @brief Gets a value indicating whether the light_button is in the checked state.
      /// @return `true` if the light_button is in the checked state; otherwise, `false`. The default value is `false`. If the three_state property is set to `true`, the checked property will return `true` for either a checked or indeterminate check_state.
      /// @remarks When the value is `true`, the light_button portion of the control displays a check mark. If the appearance property is set to button, the control will appear sunken when checked is `true` and raised like a standard button when `false`.
      /// @par Examples
      /// The following code example demonstrates the use of light_button checked.
      /// @include light_button.cpp
      [[nodiscard]] virtual auto checked() const noexcept -> bool;
      /// @brief Sets a value indicating whether the light_button is in the checked state.
      /// @param value `true` if the light_button is in the checked state; otherwise, `false`. The default value is `false`.
      /// @remarks When the value is `true`, the light_button portion of the control displays a check mark. If the appearance property is set to button, the control will appear sunken when checked is `true` and raised like a standard button when `false`.
      virtual auto checked(bool value) -> light_button&;
      
      /// @brief Gets the state of the light_button.
      /// @return One of the check_state enumeration values. The default value is unchecked.
      /// @remarks If the three_state property is set to `false`, the check_state property value can only be set to check_state::indeterminate in code and not by u ser interaction.
      /// @remarks The following table describes the xtd::forms::appearance of the light_button control in its different states for the normal and button style control light_button::appearance.
      /// | Check_state   |  appearance::normal                                 | appearance::button          |
      /// | ------------- | --------------------------------------------------- | --------------------------- |
      /// | checked       | The light_button displays a light on.               | The control appears sunken. |
      /// | unchecked     | The light_button displays a light off.              | The control appears raised. |
      /// | indeterminate | The light_button displays a light on and is shaded. | The control appears flat.   |
      /// @par Examples
      /// The following code example demonstrates the use of light_button check_state.
      /// @include light_button.cpp
      [[nodiscard]] virtual auto check_state() const noexcept -> xtd::forms::check_state;
      /// @brief Sets the state of the light_button.
      /// @param value One of the check_state enumeration values. The default value is unchecked.
      /// @remarks The following table describes the xtd::forms::appearance of the light_button control in its different states for the normal and button style control light_button::appearance.
      /// | check_state   |  appearance::normal                                 | appearance::button          |
      /// | ------------- | --------------------------------------------------- | --------------------------- |
      /// | checked       | The light_button displays a light on.               | The control appears sunken. |
      /// | unchecked     | The light_button displays a light off.              | The control appears raised. |
      /// | indeterminate | The light_button displays a light on and is shaded. | The control appears flat.   |
      /// @par Examples
      /// The following code example demonstrates the use of light_button check_state.
      /// @include light_button.cpp
      virtual auto check_state(xtd::forms::check_state value) -> light_button&;
      
      /// @brief Gets the default light off color of the light_button.
      /// @return The default light off color of the light_button.
      [[nodiscard]] virtual auto default_light_off_color() const noexcept -> xtd::drawing::color;
      
      /// @brief Gets the default light on color of the light_button.
      /// @return The default light on color of the light_button.
      [[nodiscard]] virtual auto default_light_on_color() const noexcept -> xtd::drawing::color;
      
      /// @brief Gets the horizontal and vertical alignment of the check mark on a light_button control.
      /// @return One of the content_alignment values. The default value is middle_left.
      [[nodiscard]] virtual auto light_align() const noexcept -> xtd::forms::content_alignment;
      /// @brief Sets the horizontal and vertical alignment of the check mark on a light_button control.
      /// @param value One of the content_alignment values. The default value is middle_left.
      virtual auto light_align(xtd::forms::content_alignment value) -> light_button&;
      
      /// @brief Gets the light off color for the light_button.
      /// @return A xtd::drawing::color that represents the light off color of the light_button. The default is the value of the default_light_off_color property.
      [[nodiscard]] virtual auto light_off_color() const noexcept -> xtd::drawing::color;
      /// @brief Sets the light off color for the light_button.
      /// @param value A xtd::drawing::color that represents the light off color of the light_button. The default is the value of the default_light_off_color property.
      virtual auto light_off_color(const xtd::drawing::color& value) -> light_button&;
      /// @brief Resets the light off color for the light_button.
      /// @param xtd::null.
      virtual auto light_off_color(xtd::null_ptr) -> light_button&;
      
      /// @brief Gets the light on color for the light_button.
      /// @return A xtd::drawing::color that represents the light on color of the light_button. The default is the value of the default_light_on_color property.
      [[nodiscard]] virtual auto light_on_color() const noexcept -> xtd::drawing::color;
      /// @brief Sets the light on color for the light_button.
      /// @param value A xtd::drawing::color that represents the light on color of the light_button. The default is the value of the default_light_on_color property.
      virtual auto light_on_color(const xtd::drawing::color& value) -> light_button&;
      /// @brief Resets the light on color for the light_button.
      /// @param xtd::null.
      virtual auto light_on_color(xtd::null_ptr) -> light_button&;
      
      /// @brief Gets a value indicating whether the light_button will allow three check states rather than two.
      /// @return `true` if the light_button is able to display three check states; otherwise, `false`. The default value is `false`.
      /// @remarks If the three_state property is set to `false`, the check_state property value can only be set to the indeterminate value of xtd.forms.check_state in code and not by user interaction.
      /// @par Examples
      /// The following code example demonstrates the use of light_button three_state.
      /// @include light_button.cpp
      [[nodiscard]] virtual auto three_state() const noexcept -> bool;
      /// @brief Gets a value indicating whether the light_button will allow three check states rather than two.
      /// @param value `true` if the light_button is able to display three check states; otherwise, `false`. The default value is `false`.
      /// @remarks If the three_state property is set to `false`, the check_state property value can only be set to the indeterminate value of xtd.forms.check_state in code and not by user interaction.
      virtual auto three_state(bool value) -> light_button&;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create() -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::drawing::point& location) -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @param name The name of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified text.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::string& text) -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified text, and location.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::string& tex, const xtd::drawing::point& location) -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified text, location, and size.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size) -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @param name The name of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified text, and check_state.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param check_state One of the check_state enumeration values.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::string& text, xtd::forms::check_state check_state) -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified text, check_state, and location.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param check_state One of the check_state enumeration values.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::string& text, xtd::forms::check_state check_state, const xtd::drawing::point& location) -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified text, check_state, location, and size.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param check_state One of the check_state enumeration values.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::string& text, xtd::forms::check_state check_state, const xtd::drawing::point& location, const xtd::drawing::size& size) -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified text, check_state, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param check_state One of the check_state enumeration values.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @param name The name of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::string& text, xtd::forms::check_state check_state, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified text, three_state, and check_state.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param three_state `true` if the check_box is able to display three check states; otherwise, `false`.
      /// @param check_state One of the check_state enumeration values.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::string& text, bool three_state, xtd::forms::check_state check_state) -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified text, three_state, check_state, and location.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param three_state `true` if the check_box is able to display three check states; otherwise, `false`.
      /// @param check_state One of the check_state enumeration values.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::string& text, bool three_state, xtd::forms::check_state check_state, const xtd::drawing::point& location) -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified text, three_state, check_state, location, and size.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param three_state `true` if the check_box is able to display three check states; otherwise, `false`.
      /// @param check_state One of the check_state enumeration values.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::string& text, bool three_state, xtd::forms::check_state check_state, const xtd::drawing::point& location, const xtd::drawing::size& size) -> light_button;
      /// @brief A factory to create an xtd::forms::light_button with specified text, three_state, check_state, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param three_state `true` if the check_box is able to display three check states; otherwise, `false`.
      /// @param check_state One of the check_state enumeration values.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @param name The name of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::string& text, bool three_state, xtd::forms::check_state check_state, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @param name The name of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, and text.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::string& text) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, text, and location.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::string& text, const xtd::drawing::point& location) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, text, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, text, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @param name The name of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, text, and check_state,.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param check_state One of the check_state enumeration values.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::string& text, xtd::forms::check_state check_state) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, text, check_state, and location.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param check_state One of the check_state enumeration values.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::string& text, xtd::forms::check_state check_state, const xtd::drawing::point& location) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, text, check_state, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param check_state One of the check_state enumeration values.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::string& text, xtd::forms::check_state check_state, const xtd::drawing::point& location, const xtd::drawing::size& size) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, text, check_state, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param check_state One of the check_state enumeration values.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @param name The name of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::string& text, xtd::forms::check_state check_state, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, text, three_state, and check_state.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param three_state `true` if the check_box is able to display three check states; otherwise, `false`.
      /// @param check_state One of the check_state enumeration values.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::string& text, bool three_state, xtd::forms::check_state check_state) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, text, three_state, check_state, and location.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param three_state `true` if the check_box is able to display three check states; otherwise, `false`.
      /// @param check_state One of the check_state enumeration values.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::string& text, bool three_state, xtd::forms::check_state check_state, const xtd::drawing::point& location) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, text, three_state, check_state, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param three_state `true` if the check_box is able to display three check states; otherwise, `false`.
      /// @param check_state One of the check_state enumeration values.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::string& text, bool three_state, xtd::forms::check_state check_state, const xtd::drawing::point& location, const xtd::drawing::size& size) -> light_button;
      /// @brief A factory to create a xtd::forms::light_button with specified parent, text, three_state, check_state, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param three_state `true` if the check_box is able to display three check states; otherwise, `false`.
      /// @param check_state One of the check_state enumeration values.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @param name The name of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static auto create(const xtd::forms::control& parent, const xtd::string& text, bool three_state, xtd::forms::check_state check_state, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> light_button;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the value of the checked property changes.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<light_button, xtd::event_handler> checked_changed;
      
      /// @brief Occurs when the value of the check_state property changes.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<light_button, xtd::event_handler> check_state_changed;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      
      /// @brief Gets state.
      /// @return One of xtd::forms::visual_styles::push_button_state values.
      [[nodiscard]] auto state() const noexcept -> xtd::forms::visual_styles::check_box_state;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      [[nodiscard]] auto measure_control() const noexcept -> xtd::drawing::size override;
      
      /// @brief Raises the light_button::checked_changed event.
      /// @param e An event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_checked_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual auto on_checked_changed(const event_args& e) -> void;
      
      /// @brief Raises the light_button::check_state_changed event.
      /// @param e An event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_check_state_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual auto on_check_state_changed(const event_args& e) -> void;
      
      auto on_enabled_changed(const event_args& e) -> void override;
      auto on_handle_created(const event_args& e) -> void override;
      auto on_image_changed(const xtd::event_args& e) -> void override;
      auto on_mouse_down(const mouse_event_args& e) -> void override;
      auto on_mouse_enter(const event_args& e) -> void override;
      auto on_mouse_leave(const event_args& e) -> void override;
      auto on_mouse_up(const mouse_event_args& e) -> void override;
      auto on_paint(paint_event_args& e) -> void override;
      auto wnd_proc(message& message) -> void override;
      /// @}
      
    private:
      auto wm_mouse_double_click(message& message) -> void;
      auto wm_mouse_down(message& message) -> void;
      auto wm_mouse_up(message& message) -> void;
      
      xtd::sptr<data> data_;
    };
  }
}

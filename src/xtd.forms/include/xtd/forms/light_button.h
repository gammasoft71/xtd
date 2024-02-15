/// @file
/// @brief Contains xtd::forms::light_button control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "visual_styles/check_box_state.h"
#include "appearance.h"
#include "button_base.h"
#include "check_state.h"
#include <xtd/drawing/system_colors>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows light_button.
    /// @code
    /// class forms_export_ light_button : public xtd::forms::button_base
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::button_base → xtd::forms::light_button
    /// @par Header
    /// @code #include <xtd/forms/light_button> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks Use a light_button to give the user an option, such as true/false or yes/no. The light_button control can display an image or text or both.
    /// @remarks light_button and radio_button controls have a similar function: they allow the user to choose from a list of options. light_button controls let the user pick a combination of options. In contrast, radio_button controls allow a user to choose from mutually exclusive options.
    /// @remarks The appearance property determines whether the light_button appears as a typical light_button or as a button.
    /// @remarks The three_state property determines whether the control supports two or three states. Use the checked property to get or set the value of a two-state light_button control and use the check_state property to get or set the value of a three-state light_button control.
    /// @note If the three_state property is set to true, the checked property will return true for either a checked or indeterminate state.
    /// @remarks The flat_style property determines the style and appearance of the control. If the flat_style property is set to flat_style::system, the user's operating system determines the appearance of the control.
    /// @note When the flat_style property is set to flat_style::system, the check_align property is ignored and the control is displayed using the content_alignment::middle_left or content_alignment::middle_right alignment. If the check_align property is set to one of the right alignments, the control is displayed using the content_alignment::middle_right alignment; otherwise, it is displayed using the content_alignment::middle_left alignment.
    /// @par Appearance
    /// |       | Windows                                   | macOS                                     | Gnome                                     |
    /// | ----- | ----------------------------------------- | ----------------------------------------- | ----------------------------------------- |
    /// | Light |  @image html control_light_button_w.png   |  @image html control_light_button_m.png   |  @image html control_light_button_g.png   |
    /// | Dark  |  @image html control_light_button_wd.png  |  @image html control_light_button_md.png  |  @image html control_light_button_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of light_button control with bitmap.
    /// @include light_button.cpp
    class forms_export_ light_button : public xtd::forms::button_base {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the light_button class.
      /// @remarks By default the light_button displays no caption. To specify the caption text, set the text property.
      light_button();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a value indicating whether the checked or check_state values and the light_button's appearance are automatically changed when the light_button is clicked.
      /// @return true if the checked value or check_state value and the appearance of the control are automatically changed on the click event; otherwise, false. The default value is true.
      /// @remarks If auto_check is set to false, you will need to add code to update the checked or check_state values in the click event handler.
      /// @par Examples
      /// The following code example demonstrates the use of light_button auto_check.
      /// @include light_button.cpp
      virtual bool auto_check() const noexcept;
      /// @brief Sets a value indicating whether the checked or check_state values and the light_button's appearance are automatically changed when the light_button is clicked.
      /// @param auto_check true if the checked value or check_state value and the appearance of the control are automatically changed on the click event; otherwise, false. The default value is true.
      /// @remarks If auto_check is set to false, you will need to add code to update the checked or check_state values in the click event handler.
      virtual light_button& auto_check(bool auto_check);
      
      /// @brief Gets a value indicating whether the light_button is in the checked state.
      /// @return true if the light_button is in the checked state; otherwise, false. The default value is false. If the three_state property is set to true, the checked property will return true for either a checked or indeterminate check_state.
      /// @remarks When the value is true, the light_button portion of the control displays a check mark. If the appearance property is set to button, the control will appear sunken when checked is true and raised like a standard button when false.
      /// @par Examples
      /// The following code example demonstrates the use of light_button checked.
      /// @include light_button.cpp
      virtual bool checked() const noexcept;
      /// @brief Sets a value indicating whether the light_button is in the checked state.
      /// @param checked true if the light_button is in the checked state; otherwise, false. The default value is false.
      /// @remarks When the value is true, the light_button portion of the control displays a check mark. If the appearance property is set to button, the control will appear sunken when checked is true and raised like a standard button when false.
      virtual light_button& checked(bool checked);
      
      /// @brief Gets the state of the light_button.
      /// @return One of the check_state enumeration values. The default value is unchecked.
      /// @remarks If the three_state property is set to false, the check_state property value can only be set to check_state::indeterminate in code and not by u ser interaction.
      /// @remarks The following table describes the xtd::forms::appearance of the light_button control in its different states for the normal and button style control light_button::appearance.
      /// | Check_state   |  appearance::normal                                 | appearance::button          |
      /// | ------------- | --------------------------------------------------- | --------------------------- |
      /// | checked       | The light_button displays a light on.               | The control appears sunken. |
      /// | unchecked     | The light_button displays a light off.              | The control appears raised. |
      /// | indeterminate | The light_button displays a light on and is shaded. | The control appears flat.   |
      /// @par Examples
      /// The following code example demonstrates the use of light_button check_state.
      /// @include light_button.cpp
      virtual forms::check_state check_state() const noexcept;
      /// @brief Sets the state of the light_button.
      /// @param check_state One of the check_state enumeration values. The default value is unchecked.
      /// @remarks The following table describes the xtd::forms::appearance of the light_button control in its different states for the normal and button style control light_button::appearance.
      /// | Check_state   |  appearance::normal                                 | appearance::button          |
      /// | ------------- | --------------------------------------------------- | --------------------------- |
      /// | checked       | The light_button displays a light on.               | The control appears sunken. |
      /// | unchecked     | The light_button displays a light off.              | The control appears raised. |
      /// | indeterminate | The light_button displays a light on and is shaded. | The control appears flat.   |
      /// @par Examples
      /// The following code example demonstrates the use of light_button check_state.
      /// @include light_button.cpp
      virtual light_button& check_state(forms::check_state check_state);
      
      /// @brief Gets the default light off color of the light_button.
      /// @return The default light off color of the light_button.
      virtual drawing::color default_light_off_color() const noexcept;
      
      /// @brief Gets the default light on color of the light_button.
      /// @return The default light on color of the light_button.
      virtual drawing::color default_light_on_color() const noexcept;
      
      /// @brief Gets the horizontal and vertical alignment of the check mark on a light_button control.
      /// @return One of the content_alignment values. The default value is middle_left.
      virtual content_alignment light_align() const noexcept;
      /// @brief Sets the horizontal and vertical alignment of the check mark on a light_button control.
      /// @param check_align One of the content_alignment values. The default value is middle_left.
      virtual light_button& light_align(content_alignment light_align);
      
      /// @brief Gets the light off color for the light_button.
      /// @return A xtd::drawing::color that represents the light off color of the light_button. The default is the value of the default_light_off_color property.
      virtual drawing::color light_off_color() const noexcept;
      /// @brief Sets the light off color for the light_button.
      /// @param value A xtd::drawing::color that represents the light off color of the light_button. The default is the value of the default_light_off_color property.
      virtual light_button& light_off_color(const drawing::color& value);
      /// @cond
      virtual light_button& light_off_color(std::nullptr_t);
      /// @endcond
      
      /// @brief Gets the light on color for the light_button.
      /// @return A xtd::drawing::color that represents the light on color of the light_button. The default is the value of the default_light_on_color property.
      virtual drawing::color light_on_color() const noexcept;
      /// @brief Sets the light on color for the light_button.
      /// @param value A xtd::drawing::color that represents the light on color of the light_button. The default is the value of the default_light_on_color property.
      virtual light_button& light_on_color(const drawing::color& value);
      /// @cond
      virtual light_button& light_on_color(std::nullptr_t);
      /// @endcond
      
      /// @brief Gets a value indicating whether the light_button will allow three check states rather than two.
      /// @return true if the light_button is able to display three check states; otherwise, false. The default value is false.
      /// @remarks If the three_state property is set to false, the check_state property value can only be set to the indeterminate value of xtd.forms.check_state in code and not by user interaction.
      /// @par Examples
      /// The following code example demonstrates the use of light_button three_state.
      /// @include light_button.cpp
      virtual bool three_state() const noexcept;
      /// @brief Gets a value indicating whether the light_button will allow three check states rather than two.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false. The default value is false.
      /// @remarks If the three_state property is set to false, the check_state property value can only be set to the indeterminate value of xtd.forms.check_state in code and not by user interaction.
      virtual light_button& three_state(bool three_state);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::light_button with specified text, three_state, check_state, location ,size, and name.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @param name The name of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static light_button create(const xtd::ustring& text, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create a xtd::forms::light_button with specified parent, text, three_state, check_state, location ,size, and name.
      /// @param parent The parent that contains the new created xtd::forms::light_button.
      /// @param text A string that represent text of the xtd::forms::light_button.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::light_button.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::light_button.
      /// @param name The name of the xtd::forms::light_button.
      /// @return New xtd::forms::light_button created.
      static light_button create(const control& parent, const xtd::ustring& text, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the value of the checked property changes.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<light_button, event_handler> checked_changed;
      
      /// @brief Occurs when the value of the check_state property changes.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<light_button, event_handler> check_state_changed;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      
      /// @brief Gets state.
      /// @return One of xtd::forms::visual_styles::push_button_state values.
      xtd::forms::visual_styles::check_box_state state() const noexcept;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      drawing::size measure_control() const noexcept override;
      
      /// @brief Raises the light_button::checked_changed event.
      /// @param e An event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_checked_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual void on_checked_changed(const event_args& e);
      
      /// @brief Raises the light_button::check_state_changed event.
      /// @param e An event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @remarks The on_check_state_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual void on_check_state_changed(const event_args& e);
      
      void on_enabled_changed(const event_args& e) override;
      void on_handle_created(const event_args& e) override;
      void on_image_changed(const xtd::event_args& e) override;
      void on_mouse_down(const mouse_event_args& e) override;
      void on_mouse_enter(const event_args& e) override;
      void on_mouse_leave(const event_args& e) override;
      void on_mouse_up(const mouse_event_args& e) override;
      void on_paint(paint_event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_mouse_double_click(message& message);
      void wm_mouse_down(message& message);
      void wm_mouse_up(message& message);
      
      std::shared_ptr<data> data_;
    };
  }
}

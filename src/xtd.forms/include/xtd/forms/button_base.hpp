/// @file
/// @brief Contains xtd::forms::button_base class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "control.hpp"
#include "content_alignment.hpp"
#include "image_list.hpp"
#include "flat_button_appearance.hpp"
#include "flat_style.hpp"
#include "text_format_flags.hpp"
#include <xtd/drawing/image>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality common to button controls.
    /// ```cpp
    /// class forms_export_ button_base : public xtd::forms::control
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::forms::component → xtd::forms::control → xtd::forms::button_base
    /// @par Derived
    /// xtd::forms::button, xtd::forms::check_box, xtd::forms::command_link_button, xtd::forms::light_button, xtd::forms::radio_button, xtd::forms::switch_button, xtd::forms::toggle_button, xtd::forms::up_down_button
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/button_base>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks You do not typically inherit from button_base. To create your own button class, inherit from the button, check_box, or radio_button class.
    /// @remarks To have the derived button control display an image, set the Image property or the image_list and image_index properties. The image can be aligned on the button control by setting the image_align property. Likewise, to align the text displayed on the button control, set the text_align property.
    /// @remarks The flat_style property determines the style and appearance of the control. If the flat_style property is set to flat_style::system, the user's operating system determines the appearance of the control.
    class forms_export_ button_base : public xtd::forms::control {
      struct data;
      
    public:
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether the ellipsis character (...) appears at the right edge of the control, denoting that the control text extends beyond the specified length of the control.
      /// @return `true` if the additional label text is to be indicated by an ellipsis; otherwise, `false`. The default is `true`.
      /// @remarks Set auto_ellipsis to `true` to display text that extends beyond the width of the control when the user passes over the control with the mouse. You must set the control's auto_size property to `false` if you want AutoEllipsis to be `true`. If AutoSize is `true`, the control will grow to fit the text and an ellipsis will not appear.
      [[nodiscard]] virtual auto auto_ellipsis() const noexcept -> bool;
      /// @brief Sets a value indicating whether the ellipsis character (...) appears at the right edge of the control, denoting that the control text extends beyond the specified length of the control.
      /// @param auto_ellipse `true` if the additional label text is to be indicated by an ellipsis; otherwise, `false`. The default is `true`.
      /// @remarks Set auto_ellipsis to `true` to display text that extends beyond the width of the control when the user passes over the control with the mouse. You must set the control's auto_size property to `false` if you want AutoEllipsis to be `true`. If AutoSize is `true`, the control will grow to fit the text and an ellipsis will not appear.
      virtual auto auto_ellipsis(bool auto_ellipsis) -> button_base&;
      
      [[nodiscard]] bool auto_size() const noexcept override;
      auto auto_size(bool auto_size) -> control& override;
      
      using control::control_appearance;
      auto control_appearance(xtd::forms::control_appearance value) -> control& override;
      
      /// @brief Gets the appearance of the border and the colors used to indicate check state and mouse state.
      /// @return The xtd::forms::flat_button_appearance appearance.
      [[nodiscard]] virtual auto flat_appearance() const noexcept -> const xtd::forms::flat_button_appearance&;
      /// @brief Sets the appearance of the border and the colors used to indicate check state and mouse state.
      /// @param value The xtd::forms::flat_button_appearance appearance.
      virtual auto flat_appearance(const xtd::forms::flat_button_appearance& value) -> button_base&;
      
      /// @brief Gets the flat style appearance of the button control.
      /// @return One of the xtd::forms::flat_style values. The default value is xtd::forms::flat_style::standard.
      [[nodiscard]] virtual auto flat_style() const noexcept -> xtd::forms::flat_style;
      /// @brief Sets the flat style appearance of the button control.
      /// @param value One of the xtd::forms::flat_style values. The default value is xtd::forms::flat_style::standard.
      virtual auto flat_style(xtd::forms::flat_style value) -> button_base&;
      
      /// @brief Gets the image that is displayed on a button control.
      /// @return The Image displayed on the button control. The default value is xtd::drawing::image::empty.
      /// @remarks When the image property is set, the image_list property will be set to xtd::forms::image_list::empty, and the image_index property will be set to its default, -1.
      /// @note If the flat_style property is set to xtd::forms::flat_style::system, any images assigned to the image property are not displayed.
      [[nodiscard]] virtual auto image() const noexcept -> const xtd::drawing::image&;
      /// @brief Sets the image that is displayed on a button control.
      /// @param value The Image displayed on the button control. The default value is xtd::drawing::image::empty.
      /// @remarks When the image property is set, the image_list property will be set to xtd::forms::image_list::empty, and the image_index property will be set to its default, -1.
      /// @note If the flat_style property is set to xtd::forms::flat_style::system, any images assigned to the image property are not displayed.
      virtual auto image(const xtd::drawing::image& value) -> button_base&;
      
      /// @brief Gets the alignment of the image on the button control.
      /// @return One of the content_alignment values. The default is middle_center.
      [[nodiscard]] virtual auto image_align() const noexcept -> xtd::forms::content_alignment;
      /// @brief Sets the alignment of the image on the button control.
      /// @param value One of the content_alignment values. The default is middle_center.
      virtual auto image_align(xtd::forms::content_alignment value) -> button_base&;
      
      /// @brief Gets the image list index value of the image displayed on the button control.
      /// @return A zero-based index, which represents the image position in an image_list. The default is -1.
      /// @remarks When the image_index or image_list properties are set, the Image property is set to its default value, xtd::drawing::image::empty.
      /// @remarks image_key and image_index are mutually exclusive, meaning if one is set, the other is set to an invalid value and ignored. If you set the image_key property, the image_index property is automatically set to -1. Alternatively, if you set the image_index property, the image_key is automatically set to an empty string ("").
      /// @remarks If the image_list property value is changed to xtd::forms::image_list::empty, the image_index property returns its default value, -1. However, the assigned image_index value is retained internally and used when another image_list object is assigned to the image_list property. If the new image_list assigned to the image_list property has an imageList::_image_collection::size property value that is less than or equal to the value assigned to the image_index property minus one (to account for the collection being a zero-based index), the image_index property value is adjusted to one less than the size property value. For example, consider a button control whose image_list has three images and whose image_index property is set to 2. If a new image_list that has only two images is assigned to the button, the image_index value changes to 1.
      [[nodiscard]] virtual auto image_index() const noexcept -> xtd::int32;
      /// @brief Sets the image list index value of the image displayed on the button control.
      /// @return A zero-based index, which represents the image position in an image_list. The default is -1.
      /// @remarks When the image_index or image_list properties are set, the Image property is set to its default value, xtd::drawing::image::empty.
      /// @remarks image_key and image_index are mutually exclusive, meaning if one is set, the other is set to an invalid value and ignored. If you set the image_key property, the image_index property is automatically set to -1. Alternatively, if you set the image_index property, the image_key is automatically set to an empty string ("").
      /// @remarks If the image_list property value is changed to xtd::forms::image_list::empty, the image_index property returns its default value, -1. However, the assigned image_index value is retained internally and used when another image_list object is assigned to the image_list property. If the new image_list assigned to the image_list property has an imageList::_image_collection::size property value that is less than or equal to the value assigned to the image_index property minus one (to account for the collection being a zero-based index), the image_index property value is adjusted to one less than the size property value. For example, consider a button control whose image_list has three images and whose image_index property is set to 2. If a new image_list that has only two images is assigned to the button, the image_index value changes to 1.
      virtual auto image_index(xtd::int32 value) -> button_base&;
      
      /// @brief Gets the image_list that contains the image displayed on a button control.
      /// @return An xtd::drawing::image_list. The default value is xtd::drawing::image_list::empty.
      [[nodiscard]] virtual auto image_list() const noexcept -> const xtd::forms::image_list&;
      /// @brief Gets the image_list that contains the image displayed on a button control.
      /// @return An xtd::drawing::image_list. The default value is xtd::drawing::image_list::empty.
      [[nodiscard]] virtual auto image_list() noexcept -> xtd::forms::image_list&;
      /// @brief Sets the image_list that contains the image displayed on a button control.
      /// @return An xtd::drawing::image_list. The default value is xtd::drawing::image_list::empty.
      virtual auto image_list(const xtd::forms::image_list& value) -> button_base&;
      
      /// @brief Gets the alignment of the text on the button control.
      /// @return One of the content_alignment values. The default is middle_center.
      [[nodiscard]] virtual auto text_align() const noexcept -> xtd::forms::content_alignment;
      /// @brief Gets the alignment of the text on the button control.
      /// @param value One of the content_alignment values. The default is middle_center.
      virtual auto text_align(xtd::forms::content_alignment value) -> button_base&;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the value of the image property changes.
      /// @remarks This event is raised if the image property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      event<button_base, event_handler> image_changed;
      /// @}
      
    protected:
      /// @name Protected constructor
      
      /// @{
      /// @brief Initializes a new instance of the ButtonBase class.
      button_base() noexcept;
      /// @}
      
      /// @name Protected Properties
      
      /// @{
      /// @brief Gets the required creation parameters when the control handle is created.
      /// @return A create_params that contains the required creation parameters when the handle to the control is created.
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      
      /// @brief Gets a value indicating whether the button control is the default button.
      /// @return `true` if the button control is the default button; otherwise, `false`.
      /// @remarks When the xtd::forms::button_base::is_default property is set to `true`, the button is the default button for the xtd::forms::form. This means that the button is clicked when the ENTER key is pressed if no other button or any other control that captures the ENTER key has focus.
      /// @remarks To specify the default button of a form, set the xtd::forms::form::accept_button property of the form to the desired button.
      [[nodiscard]] auto is_default() const noexcept -> bool;
      /// @brief Sets a value indicating whether the button control is the default button.
      /// @param value `true` if the button control is the default button; otherwise, `false`.
      /// @remarks When the xtd::forms::button_base::is_default property is set to `true`, the button is the default button for the xtd::forms::form. This means that the button is clicked when the ENTER key is pressed if no other button or any other control that captures the ENTER key has focus.
      /// @remarks To specify the default button of a form, set the xtd::forms::form::accept_button property of the form to the desired button.
      auto is_default(bool value) -> button_base&;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Measure this control.
      /// @return The drawing::size size of this control.
      /// @remarks This method is used when auto_size is `true`.
      [[nodiscard]] auto measure_control() const noexcept -> xtd::drawing::size override;
      
      auto on_back_color_changed(const event_args& e) -> void override;
      auto on_enabled_changed(const event_args& e) -> void override;
      auto on_font_changed(const xtd::event_args& e) -> void override;
      auto on_fore_color_changed(const event_args& e) -> void override;
      
      /// @brief Raises the button_base::image_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual auto on_image_changed(const xtd::event_args& e) -> void;
      
      auto on_mouse_down(const mouse_event_args& e) -> void override;
      auto on_mouse_enter(const event_args& e) -> void override;
      auto on_mouse_leave(const event_args& e) -> void override;
      auto on_mouse_up(const mouse_event_args& e) -> void override;
      auto on_parent_back_color_changed(const event_args& e) -> void override;
      auto on_parent_fore_color_changed(const event_args& e) -> void override;
      auto on_resize(const xtd::event_args& e) -> void override;
      auto on_text_changed(const xtd::event_args& e) -> void override;
      /// @}
      
      /// @cond
      [[nodiscard]] auto compute_image_bounds() -> xtd::drawing::rectangle;
      [[nodiscard]] auto compute_image_bounds(const xtd::drawing::rectangle& rectangle) -> xtd::drawing::rectangle;
      [[nodiscard]] auto to_text_format_flags(xtd::forms::content_alignment text_align) -> xtd::forms::text_format_flags;
      /// @endcond
      
    private:
      xtd::sptr<data> data_;
    };
  }
}

/// @file
/// @brief Contains xtd::forms::style_sheets::control class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "ibox_model.hpp"
#include "iimage_model.hpp"
#include "itext_model.hpp"
#include <xtd/iequatable>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The control selector allows you to specify the box and color of a control.
      /// ```cpp
      /// class forms_export_ control : public xtd::forms::style_sheets::ibox_model, public xtd::forms::style_sheets::itext_model, public xtd::iequatable<control>, public xtd::object
      /// ```
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::ibox_model → xtd::forms::style_sheets::control
      /// @par Implements
      /// xtd::forms::style_sheets::ibox_model, xtd::forms::style_sheets::itext_model, xtd::iequatable <>
      /// @par Header
      /// ```cpp
      /// #include <xtd/forms/style_sheets/control>
      /// ```
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks You need to know how the box model works.
      /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
      class forms_export_ control : public xtd::forms::style_sheets::ibox_model, public xtd::forms::style_sheets::itext_model, public xtd::forms::style_sheets::iimage_model, public xtd::iequatable<control>, public xtd::object {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::control class.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        control() = default;
        /// @}
        
        /// @name Public Properties
        
        /// @{
        [[nodiscard]] auto auto_ellipsis() const noexcept -> bool override;
        /// @brief Sets a value indicating whether the ellipsis character (...) appears at the right edge of the control, denoting that the control text extends beyond the specified length of the control.
        /// @param value `true` if the additional control text is to be indicated by an ellipsis; otherwise, `false`.
        /// @return This current instance.
        auto auto_ellipsis(bool value) noexcept -> control&;
        
        [[nodiscard]] auto background_color() const noexcept -> const xtd::drawing::color& override;
        /// @brief Sets the background color is used to add background effects to the box.
        /// @param value The background color is used to add background effects to the box.
        /// @return This current instance.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto background_color(const xtd::drawing::color& value) noexcept -> control&;
        
        [[nodiscard]] auto background_image() const noexcept -> const xtd::forms::style_sheets::background_image& override;
        /// @brief Sets the background image is used to add background effects to the box.
        /// @param value The background image is used to add background effects to the box.
        /// @return This current instance.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto background_image(const xtd::forms::style_sheets::background_image& value) noexcept -> control&;
        
        [[nodiscard]] auto border_color() const noexcept -> const xtd::forms::style_sheets::border_color& override;
        /// @brief Sets the color is used to set the color of the borders.
        /// @param value The color is used to set the color of the borders.
        /// @return This current instance.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto border_color(const xtd::forms::style_sheets::border_color& value) noexcept -> control&;
        
        [[nodiscard]] auto border_radius() const noexcept -> xtd::forms::style_sheets::border_radius override;
        /// @brief Sets the radius is used to add rounded borders to an element.
        /// @param value The radius is used to add rounded borders to an element.
        /// @return This current instance.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto border_radius(const xtd::forms::style_sheets::border_radius& value) noexcept -> control&;
        
        [[nodiscard]] auto border_style() const noexcept -> xtd::forms::style_sheets::border_style override;
        /// @brief Sets the style specifies what kind of borders to display.
        /// @param value The style specifies what kind of borders to display.
        /// @return This current instance.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto border_style(xtd::forms::style_sheets::border_style value) noexcept -> control&;
        
        [[nodiscard]] auto border_width() const noexcept -> xtd::forms::style_sheets::border_width override;
        /// @brief Sets the width specifies the width of the border.
        /// @param value The width specifies the width of the borders.
        /// @return This current instance.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto border_width(xtd::forms::style_sheets::border_width value) noexcept -> control&;
        
        [[nodiscard]] auto color() const noexcept -> const xtd::drawing::color& override;
        /// @brief Sets the color is used to add foreground effects to the text.
        /// @param value The color is used to add foreground effects to the text.
        auto color(const xtd::drawing::color& value) noexcept -> control&;
        
        [[nodiscard]] auto decoration() const noexcept -> xtd::forms::style_sheets::text_decoration override;
        /// @brief Sets the decoration of the text.
        /// @param value One of xtd::forms::style_sheets::text_decoration values.
        /// @return This current instance.
        auto decoration(xtd::forms::style_sheets::text_decoration value) noexcept -> control&;
        
        [[nodiscard]] auto font() const noexcept -> const xtd::drawing::font& override;
        /// @brief Sets the font of the text.
        /// @return This current instance.
        /// @param value The font of the text.
        auto font(const xtd::drawing::font& value) noexcept -> control&;
        
        [[nodiscard]] auto height() const noexcept -> std::optional<xtd::forms::style_sheets::length> override;
        /// @brief Sets the height of the box.
        /// @return The height of the box.
        /// @return This current instance.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto height(const std::optional<xtd::forms::style_sheets::length>& value) noexcept -> control&;
        
        [[nodiscard]] auto image_alignment() const noexcept -> xtd::forms::content_alignment override;
        /// @brief Sets the alignment of the image.
        /// @param value A combination of xtd::forms::content_alignment values.
        /// @return This current instance.
        auto image_alignment(xtd::forms::content_alignment value) noexcept -> control&;
        
        [[nodiscard]] auto margin() const noexcept -> const xtd::forms::style_sheets::margin& override;
        /// @brief Sets the area outside the border.
        /// @param value The area outside the border.
        /// @return This current instance.
        /// @remarks The margin is transparent.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto margin(const xtd::forms::style_sheets::margin& value) noexcept -> control&;
        
        [[nodiscard]] auto outline_color() const noexcept -> const xtd::forms::style_sheets::outline_color& override;
        /// @brief Sets the color is used to set the color of the outlines.
        /// @param value The color is used to set the color of the outlines.
        /// @return This current instance.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto outline_color(const xtd::forms::style_sheets::outline_color& value) noexcept -> control&;
        
        [[nodiscard]] auto outline_offset() const noexcept -> xtd::forms::style_sheets::outline_offset override;
        /// @brief Sets the width specifies the offset of the outlines.
        /// @param value The width specifies the offset of the outlines.
        /// @return This current instance.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto outline_offset(xtd::forms::style_sheets::outline_offset value) noexcept -> control&;
        
        [[nodiscard]] auto outline_radius() const noexcept -> xtd::forms::style_sheets::outline_radius override;
        /// @brief Sets the radius is used to add rounded outlines to an element.
        /// @param value The radius is used to add rounded outlines to an element.
        /// @return This current instance.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto outline_radius(xtd::forms::style_sheets::outline_radius value) noexcept -> control&;
        
        [[nodiscard]] auto outline_style() const noexcept -> xtd::forms::style_sheets::outline_style override;
        /// @brief Sets the style specifies what kind of outlines to display.
        /// @param value The style specifies what kind of outlines to display.
        /// @return This current instance.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto outline_style(xtd::forms::style_sheets::outline_style value) noexcept -> control&;
        
        [[nodiscard]] auto outline_width() const noexcept -> xtd::forms::style_sheets::outline_width override;
        /// @brief Sets the width specifies the width of the outlines.
        /// @param value The width specifies the width of the outlines.
        /// @return This current instance.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto outline_width(xtd::forms::style_sheets::outline_width value) noexcept -> control&;
        
        [[nodiscard]] auto padding() const noexcept -> const xtd::forms::style_sheets::padding& override;
        /// @brief Sets the area area around the content.
        /// @param value The area around the content.
        /// @return This current instance.
        /// @remarks The padding is transparent.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto padding(const xtd::forms::style_sheets::padding& value) noexcept -> control&;
        
        /// @brief Gets an xtd::forms::style_sheets::shadow array used to draw shadows under the text.
        /// @return The xtd::forms::style_sheets::shadow array used to draw shadows under the text.
        [[nodiscard]] auto shadows() const noexcept -> xtd::forms::style_sheets::shadows override;
        /// @brief Sets an xtd::forms::style_sheets::shadow array used to draw shadows under the text.
        /// @param value The xtd::forms::style_sheets::shadow array used to draw shadows under the text.
        /// @return This current instance.
        auto shadows(const xtd::forms::style_sheets::shadows& value) noexcept -> control&;
        
        [[nodiscard]] auto text_alignment() const noexcept -> xtd::forms::content_alignment override;
        /// @brief Sets the alignment of the text.
        /// @param value A combination of xtd::forms::content_alignment values.
        /// @return This current instance.
        auto text_alignment(xtd::forms::content_alignment value) noexcept -> control&;
        
        [[nodiscard]] auto transformation() const noexcept -> xtd::forms::style_sheets::text_transformation override;
        /// @brief Sets the transformation of the text.
        /// @param value One of xtd::forms::style_sheets::text_transformation values.
        /// @return This current instance.
        auto transformation(xtd::forms::style_sheets::text_transformation value) noexcept -> control&;
        
        [[nodiscard]] auto width() const noexcept -> std::optional<xtd::forms::style_sheets::length> override;
        /// @brief Sets the width of the box.
        /// @param value The width of the box.
        /// @return This current instance.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_box_model).
        auto width(std::optional<xtd::forms::style_sheets::length> value) noexcept -> control&;
        
        [[nodiscard]] auto white_space() const noexcept -> xtd::forms::style_sheets::white_space override;
        /// @brief Sets how white-space inside an element is handled.
        /// @param value One of xtd::forms::style_sheets::white_space values.
        /// @return This current instance.
        auto white_space(xtd::forms::style_sheets::white_space value) noexcept -> control&;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param obj The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param other The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        [[nodiscard]] auto equals(const control& other) const noexcept -> bool override;
        
        /// @brief Serves as a hash function for a particular type.
        /// @return A hash code for the current object.
        [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
        
        /// @brief Gets solid background color.
        /// @return The solid background color.
        [[nodiscard]] auto get_solid_background_color() const noexcept -> xtd::drawing::color;
        /// @brief Gets the border rectangle from the specified rectangle.
        /// @return The border rectangle.
        [[nodiscard]] auto get_border_rectangle(const xtd::drawing::rectangle& bounds) const noexcept -> xtd::drawing::rectangle override;
        /// @brief Gets the fill rectangle from the specified rectangle.
        /// @return The fill rectangle.
        [[nodiscard]] auto get_fill_rectangle(const xtd::drawing::rectangle& bounds) const noexcept -> xtd::drawing::rectangle override;
        /// @brief Gets the outline rectangle from the specified rectangle.
        /// @return The outline rectangle.
        [[nodiscard]] auto get_outline_rectangle(const xtd::drawing::rectangle& bounds) const noexcept -> xtd::drawing::rectangle override;
        /// @brief Gets the content rectangle from the specified rectangle.
        /// @return The content rectangle.
        [[nodiscard]] auto get_content_rectangle(const xtd::drawing::rectangle& bounds) const noexcept -> xtd::drawing::rectangle override;
        /// @brief Makes string format.
        /// @return The string format.
        [[nodiscard]] auto make_string_format() const noexcept -> xtd::drawing::string_format override;
        /// @}
        
        /// @name Public Static Methods
        
        /// @{
        /// @brief A factory to create control.
        /// @return New control created.
        [[nodiscard]] static auto create_control() -> control {return control();}
        /// @}
        
      private:
        bool auto_ellipsis_ = false;
        xtd::forms::style_sheets::margin margin_ {length(0)};
        xtd::forms::style_sheets::border_color border_color_ {xtd::drawing::color::black};
        xtd::forms::style_sheets::border_radius border_radius_ {length(0)};
        xtd::forms::style_sheets::border_style border_style_ {border_type::none};
        xtd::forms::style_sheets::border_width border_width_ {length(3)};
        xtd::forms::style_sheets::outline_color outline_color_ {xtd::drawing::color::black};
        xtd::forms::style_sheets::outline_offset outline_offset_ {length(0)};
        xtd::forms::style_sheets::outline_radius outline_radius_ {length(0)};
        xtd::forms::style_sheets::outline_style outline_style_ {border_type::none};
        xtd::forms::style_sheets::outline_width outline_width_ {length(1)};
        xtd::forms::style_sheets::padding padding_ {length(0)};
        xtd::drawing::color background_color_ = xtd::drawing::color::transparent;
        xtd::forms::style_sheets::background_image background_image_ ;
        std::optional<xtd::forms::style_sheets::length> width_;
        std::optional<xtd::forms::style_sheets::length> height_;
        xtd::drawing::color color_ = xtd::drawing::color::black;
        xtd::forms::content_alignment text_alignment_ = xtd::forms::content_alignment::middle_center;
        xtd::drawing::font font_ = xtd::drawing::system_fonts::default_font();
        xtd::forms::style_sheets::text_decoration decoration_ = xtd::forms::style_sheets::text_decoration::none;
        xtd::forms::style_sheets::shadows shadows_;
        xtd::forms::style_sheets::text_transformation transformation_ = xtd::forms::style_sheets::text_transformation::none;
        xtd::forms::content_alignment image_alignment_ = xtd::forms::content_alignment::middle_center;
        xtd::forms::style_sheets::white_space white_space_ = xtd::forms::style_sheets::white_space::normal;
      };
    }
  }
}

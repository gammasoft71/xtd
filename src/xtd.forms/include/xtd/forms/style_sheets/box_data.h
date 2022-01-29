/// @file
/// @brief Contains xtd::forms::style_sheets::box_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <array>
#include "border_color.h"
#include "border_radius.h"
#include "border_style.h"
#include "border_width.h"
#include "background_image.h"
#include "../padding.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The box data allows you to specify the margin, borders, padding, background color, width and height of a box.
      /// @code
      /// class forms_export_ box_data : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::box_data
      /// @par Implement
      /// xtd::object → xtd::forms::style_sheets::box_data
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks This class is used by xtd::forms::style_sheets::box_renderer.
      /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
      class box_data : public xtd::object {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::box_data class.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                              | Default value                                                         |
        /// |-------------------------------------------------------|-----------------------------------------------------------------------|
        /// | xtd::forms::style_sheets::box_data::margin            | 0                                                                     |
        /// | xtd::forms::style_sheets::box_data::border_style      | xtd::forms::style_sheets::border_type::none                           |
        /// | xtd::forms::style_sheets::box_data::border_color      | xtd::forms::style_sheets::color_datte(xtd::drawing::color::black)     |
        /// | xtd::forms::style_sheets::box_data::border_width      | 3                                                                     |
        /// | xtd::forms::style_sheets::box_data::border_radius     | 0                                                                     |
        /// | xtd::forms::style_sheets::box_data::padding           | 0                                                                     |
        /// | xtd::forms::style_sheets::box_data::background_color  | xtd::forms::style_sheets::color_data(xtd::drawing::color::trasparent) |
        /// | xtd::forms::style_sheets::box_data::background_imzage | xtd::forms::style_sheets::image_data::empty                           |
        /// | xtd::forms::style_sheets::box_data::width             | std::nullopt                                                          |
        /// | xtd::forms::style_sheets::box_data::height            | std::nullopt                                                          |
        box_data() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::box_data class with specified margin, borders, padding, background color, width and height.
        /// @param margin The area outside the border.
        /// @param borders A border that goes around the padding and content.
        /// @param padding The area around the content.
        /// @param background_color The background color is used to add background effects to the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                              | Default value                                                         |
        /// |-------------------------------------------------------|-----------------------------------------------------------------------|
        /// | xtd::forms::style_sheets::box_data::background_imzage | xtd::forms::style_sheets::image_data::empty                           |
        /// | xtd::forms::style_sheets::box_data::width             | std::nullopt                                                          |
        /// | xtd::forms::style_sheets::box_data::height            | std::nullopt                                                          |
        box_data(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::padding& padding, const xtd::drawing::color& background_color);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::box_data class with specified margin, borders, padding, background color, width and height.
        /// @param margin The area outside the border.
        /// @param borders A border that goes around the padding and content.
        /// @param padding The area around the content.
        /// @param background_image The background image is used to add background effects to the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                              | Default value                                                         |
        /// |-------------------------------------------------------|-----------------------------------------------------------------------|
        /// | xtd::forms::style_sheets::box_data::background_color  | xtd::forms::style_sheets::color_data(xtd::drawing::color::trasparent) |
        /// | xtd::forms::style_sheets::box_data::width             | std::nullopt                                                          |
        /// | xtd::forms::style_sheets::box_data::height            | std::nullopt                                                          |
        box_data(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::padding& padding, const xtd::forms::style_sheets::background_image& background_image);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::box_data class with specified margin, borders, padding, background color, width and height.
        /// @param margin The area outside the border.
        /// @param borders A border that goes around the padding and content.
        /// @param padding The area around the content.
        /// @param background_color The background color is used to add background effects to the box.
        /// @param background_image The background image is used to add background effects to the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                              | Default value                                                         |
        /// |-------------------------------------------------------|-----------------------------------------------------------------------|
        /// | xtd::forms::style_sheets::box_data::width             | std::nullopt                                                          |
        /// | xtd::forms::style_sheets::box_data::height            | std::nullopt                                                          |
        box_data(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::padding& padding, const xtd::drawing::color& background_color, const xtd::forms::style_sheets::background_image& background_image);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::box_data class with specified margin, borders, padding, background color, width and height.
        /// @param margin The area outside the border.
        /// @param borders The borders that goes around the padding and content.
        /// @param padding The area around the content.
        /// @param background_color The background color is used to add background effects to the box.
        /// @param width The width of the box.
        /// @param height The height of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                              | Default value                                                         |
        /// |-------------------------------------------------------|-----------------------------------------------------------------------|
        /// | xtd::forms::style_sheets::box_data::background_imzage | xtd::forms::style_sheets::image_data::empty                           |
        box_data(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::padding& padding, const xtd::drawing::color& background_color, std::optional<int32_t> width, std::optional<int32_t> height);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::box_data class with specified margin, borders, padding, background color, width and height.
        /// @param margin The area outside the border.
        /// @param borders The borders that goes around the padding and content.
        /// @param padding The area around the content.
        /// @param background_image The background image is used to add background effects to the box.
        /// @param width The width of the box.
        /// @param height The height of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                              | Default value                                                         |
        /// |-------------------------------------------------------|-----------------------------------------------------------------------|
        /// | xtd::forms::style_sheets::box_data::background_color  | xtd::forms::style_sheets::color_data(xtd::drawing::color::trasparent) |
        box_data(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::padding& padding, const xtd::forms::style_sheets::background_image& background_image, std::optional<int32_t> width, std::optional<int32_t> height);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::box_data class with specified margin, borders, padding, background color, width and height.
        /// @param margin The area outside the border.
        /// @param borders The borders that goes around the padding and content.
        /// @param padding The area around the content.
        /// @param background_color The background color is used to add background effects to the box.
        /// @param background_image The background image is used to add background effects to the box.
        /// @param width The width of the box.
        /// @param height The height of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        box_data(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_style& border_style, const xtd::forms::style_sheets::border_color& border_color, const xtd::forms::style_sheets::border_width& border_width, const xtd::forms::style_sheets::border_radius& border_radius, const xtd::forms::padding& padding, const xtd::drawing::color& background_color, const xtd::forms::style_sheets::background_image& background_image, std::optional<int32_t> width, std::optional<int32_t> height);
        /// @}

        /// @cond
        box_data(const box_data&) = default;
        box_data(box_data&&) = default;
        box_data& operator=(const box_data&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the background color is used to add background effects to the box.
        /// @return The background color is used to add background effects to the box.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        const xtd::drawing::color& background_color() const noexcept;
        /// @brief Sets the background color is used to add background effects to the box.
        /// @param value The background color is used to add background effects to the box.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        void background_color(const xtd::drawing::color& value) noexcept;

        /// @brief Gets the background image is used to add background effects to the box.
        /// @return The background image is used to add background effects to the box.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        const xtd::forms::style_sheets::background_image& background_image() const noexcept;
        /// @brief Sets the background image is used to add background effects to the box.
        /// @param value The background image is used to add background effects to the box.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        void background_image(const xtd::forms::style_sheets::background_image& value) noexcept;
        
        /// @{
        /// @brief Gets the color is used to set the color of the borders.
        /// @return The color is used to set the color of the borders.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        const xtd::forms::style_sheets::border_color& border_color() const noexcept;
        /// @brief Sets the color is used to set the color of the borders.
        /// @param value The color is used to set the color of the borders.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        void border_color(const xtd::forms::style_sheets::border_color& value) noexcept;
        
        /// @brief Gets the radius is used to add rounded borders to an element.
        /// @return The radius is used to add rounded borders to an element.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        xtd::forms::style_sheets::border_radius border_radius() const noexcept;
        /// @brief Sets the radius is used to add rounded borders to an element.
        /// @param value The radius is used to add rounded borders to an element.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        void border_radius(xtd::forms::style_sheets::border_radius value) noexcept;
        
        /// @brief Gets the style specifies what kind of borders to display.
        /// @return The style specifies what kind of borders to display.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        xtd::forms::style_sheets::border_style border_style() const noexcept;
        /// @brief Sets the style specifies what kind of borders to display.
        /// @param value The style specifies what kind of borders to display.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        void border_style(xtd::forms::style_sheets::border_style value) noexcept;
        
        /// @brief Gets the width specifies the width of the borders.
        /// @return The width specifies the width of the borders.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        xtd::forms::style_sheets::border_width border_width() const noexcept;
        /// @brief Sets the width specifies the width of the border.
        /// @param value The width specifies the width of the border.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        void border_width(xtd::forms::style_sheets::border_width value) noexcept;

        /// @brief Gets the height of the box.
        /// @return The height of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        std::optional<int32_t> height() const noexcept;
        /// @brief Sets the height of the box.
        /// @return The height of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        void height(const std::optional<int32_t>& value) noexcept;

        /// @brief Gets the area outside the border.
        /// @return The area outside the border.
        /// @remarks The margin is transparent.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        const xtd::forms::padding& margin() const noexcept;
        
        /// @brief Gets the area area around the content.
        /// @return The area around the content.
        /// @remarks The padding is transparent.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        const xtd::forms::padding& padding() const noexcept;
        
        /// @brief The width of the box.
        /// @return The width of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        std::optional<int32_t> width() const noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        /// @brief Creates a xtd::forms::style_sheets::box_data object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::box_data object.
        /// @param result The xtd::forms::style_sheets::box_data class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool from_css(const xtd::ustring& css_text, box_data& result);

        /// @brief Gets the computed boder rectangle from specified bounds.
        /// @param bounds The bounds use to compute the borfder rectangle with this box instance.
        /// @return The computed boder rectangle from specified bounds.
        /// @remarks The border rectangle is euqual to bounds rectangle minus margin.
        xtd::drawing::rectangle get_border_rectangle(const xtd::drawing::rectangle& bounds) const noexcept;

        /// @brief Gets the computed fill rectangle from specified bounds.
        /// @param bounds The bounds use to compute the fill rectangle with this box instance.
        /// @return The computed boder rectangle from specified bounds.
        /// @remarks The fill rectangle is euqual to border rectangle minus border width.
        /// @remarks The fill rectangle is euqual to content rectangle plus padding.
        xtd::drawing::rectangle get_fill_rectangle(const xtd::drawing::rectangle& bounds) const noexcept;

        /// @brief Gets the computed content rectangle from specified bounds.
        /// @param bounds The bounds use to compute the content rectangle with this box instance.
        /// @return The content boder rectangle from specified bounds.
        /// @remarks The content rectangle is euqual to fill rectangle minus padding.
        /// @remarks The content rectangle is euqual to border rectangle minux border width minus padding.
        xtd::drawing::rectangle get_content_rectangle(const xtd::drawing::rectangle& bounds) const noexcept;

        /// @brief Return a xtd::string that represents the css format of the current xtd::forms::style_sheets::box_data object.
        /// @return A xtd::string that represents the css format of the current xtd::forms::style_sheets::box_data object.
        xtd::ustring to_css() const noexcept;
        /// @}

      private:
        static std::vector<xtd::ustring> split_border_colors(const xtd::ustring& value);
        static bool try_parse_border_radius(const ustring& text, xtd::forms::style_sheets::border_radius& border_radius);
        static bool try_parse_border_style(const ustring& text, xtd::forms::style_sheets::border_style& border_style);
        static bool try_parse_border_width(const ustring& text, xtd::forms::style_sheets::border_width& border_width);
        static bool try_parse_padding(const ustring& text, xtd::forms::padding& padding);

        xtd::forms::padding margin_;
        xtd::forms::style_sheets::border_style border_style_;
        xtd::forms::style_sheets::border_color border_color_;
        xtd::forms::style_sheets::border_width border_width_;
        xtd::forms::style_sheets::border_radius border_radius_;
        xtd::forms::padding padding_;
        xtd::drawing::color background_color_ = xtd::drawing::color::transparent;
        xtd::forms::style_sheets::background_image background_image_;
        std::optional<int32_t> width_;
        std::optional<int32_t> height_;
      };
    }
  }
}

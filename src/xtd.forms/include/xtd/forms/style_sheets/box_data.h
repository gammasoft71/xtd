/// @file
/// @brief Contains xtd::forms::style_sheets::box_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <array>
#include "border_data.h"
#include "../padding.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The box data allow you to specify the margin, borders, padding, background color, width and height of a box.
      /// @code
      /// class forms_export_ box_data : public xtd::object
      /// @endcode
      /// @par Inheritance
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
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::box_data class.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                             | Default value                                                                   |
        /// |------------------------------------------------------|---------------------------------------------------------------------------------|
        /// | xtd::forms::style_sheets::box_data::margin           | 0                                                                               |
        /// | xtd::forms::style_sheets::box_data::borders          | An array with four xtd::forms::style_sheets::border_data initialized by default |
        /// | xtd::forms::style_sheets::box_data::padding          | 0                                                                               |
        /// | xtd::forms::style_sheets::box_data::background_color | xtd::forms::style_sheets::color_data(xtd::drawing::color::white)                |
        /// | xtd::forms::style_sheets::box_data::width            | std::nullopt                                                                    |
        /// | xtd::forms::style_sheets::box_data::height           | std::nullopt                                                                    |
        box_data() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::box_data class with specified margin, borders, padding, background color, width and height.
        /// @param margin The area outside the border.
        /// @param borders A border that goes around the padding and content.
        /// @param padding The area around the content.
        /// @param background_color The background color is used to add background effects to the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        box_data(const xtd::forms::padding& margin, const std::array<xtd::forms::style_sheets::border_data, 4>& borders, const xtd::forms::padding& padding, const xtd::forms::style_sheets::color_data& background_color);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::box_data class with specified margin, borders, padding, background color, width and height.
        /// @param margin The area outside the border.
        /// @param borders The borders that goes around the padding and content.
        /// @param padding The area around the content.
        /// @param background_color The background color is used to add background effects to the box.
        /// @param width The width of the box.
        /// @param height The height of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        box_data(const xtd::forms::padding& margin, const std::array<xtd::forms::style_sheets::border_data, 4>& borders, const xtd::forms::padding& padding, const xtd::forms::style_sheets::color_data& background_color, std::optional<int32_t> width, std::optional<int32_t> height);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::box_data class with specified margin, border, padding, background color, width and height.
        /// @param margin The area outside the border.
        /// @param border A border that goes around the padding and content (same data for the four borders.
        /// @param padding The area around the content.
        /// @param background_color The background color is used to add background effects to the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        box_data(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_data& border, const xtd::forms::padding& padding, const xtd::forms::style_sheets::color_data& background_color);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::box_data class with specified margin, border, padding, background color, width and height.
        /// @param margin The area outside the border.
        /// @param border The borders that goes around the padding and content (same data for the four borders).
        /// @param padding The area around the content.
        /// @param background_color The background color is used to add background effects to the box.
        /// @param width The width of the box.
        /// @param height The height of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        box_data(const xtd::forms::padding& margin, const xtd::forms::style_sheets::border_data& border, const xtd::forms::padding& padding, const xtd::forms::style_sheets::color_data& background_color, std::optional<int32_t> width, std::optional<int32_t> height);

        /// @cond
        box_data(const box_data&) = default;
        box_data(box_data&&) = default;
        box_data& operator=(const box_data&) = default;
        /// @endcond
        
        /// @brief Gets the background color is used to add background effects to the box.
        /// @return The background color is used to add background effects to the box.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        const xtd::forms::style_sheets::color_data& background_color() const noexcept;
        
        /// @brief Gets the borders that goes around the padding and content.
        /// @return The borders that goes around the padding and content.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        const std::array<xtd::forms::style_sheets::border_data, 4>& borders() const noexcept;
        
        /// @brief The height of the box.
        /// @return The height of the box.
        /// @remarks You need to know how the box model works.
        /// @remarks For more information, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_style_sheets_box_model.md">Box Model</a>.
        std::optional<int32_t> height() const noexcept;
        
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
        
        xtd::drawing::rectangle get_border_rectangle(const xtd::drawing::rectangle& bounds) const noexcept;
        xtd::drawing::rectangle get_fill_rectangle(const xtd::drawing::rectangle& bounds) const noexcept;
        xtd::drawing::rectangle get_content_rectangle(const xtd::drawing::rectangle& bounds) const noexcept;

      private:
        xtd::forms::padding margin_;
        std::array<xtd::forms::style_sheets::border_data, 4> borders_;
        xtd::forms::padding padding_;
        xtd::forms::style_sheets::color_data background_color_ {xtd::drawing::color::white};
        std::optional<int32_t> width_;
        std::optional<int32_t> height_;
      };
    }
  }
}

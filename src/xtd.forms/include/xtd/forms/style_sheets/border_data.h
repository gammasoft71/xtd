/// @file
/// @brief Contains xtd::forms::style_sheets::border_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "border_style.h"
#include "color_data.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The border data allow you to specify the style, width, and color of an element's border.
      /// @code
      /// class forms_export_ border_data : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::border_data
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks This class is used by xtd::forms::style_sheets::border_renderer.
      class forms_export_ border_data : public xtd::object {
      public:
        /// @name Constructors

        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_data class.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                      | Default value                                                      |
        /// |-----------------------------------------------|--------------------------------------------------------------------|
        /// | xtd::forms::style_sheets::border_data::color  | xtd::forms::style_sheets::color_datte(xtd::drawing::color::black)  |
        /// | xtd::forms::style_sheets::border_data::style  | xtd::forms::style_sheets::border_style::none                       |
        /// | xtd::forms::style_sheets::border_data::width  | 3                                                                  |
        /// | xtd::forms::style_sheets::border_data::radius | 0                                                                  |
        border_data() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_data class with specified color, style, width and radius.
        /// @param color The color is used to set the color of the border.
        /// @param style The style specifies what kind of border to display.
        /// @param width The width specifies the width of the border.
        /// @param radius The radius is used to add rounded borders to an element.
        border_data(const xtd::forms::style_sheets::color_data& color, xtd::forms::style_sheets::border_style style, int32_t width, int32_t radius);
        /// @}
        
        /// @cond
        border_data(const border_data&) = default;
        border_data(border_data&&) = default;
        border_data& operator=(const border_data&) = default;
        /// @endcond

        /// @name Proeprties
        
        /// @{
        /// @brief Gets the color is used to set the color of the border.
        /// @return The color is used to set the color of the border.
        const xtd::forms::style_sheets::color_data& color() const noexcept;
        /// @brief Sets the color is used to set the color of the border.
        /// @param value The color is used to set the color of the border.
        void color(const xtd::forms::style_sheets::color_data& value) noexcept;

        /// @brief Gets the radius is used to add rounded borders to an element.
        /// @return The radius is used to add rounded borders to an element.
        int32_t radius() const noexcept;
        /// @brief Sets the radius is used to add rounded borders to an element.
        /// @param value The radius is used to add rounded borders to an element.
        void radius(int32_t value) noexcept;

        /// @brief Gets the style specifies what kind of border to display.
        /// @return The style specifies what kind of border to display.
        xtd::forms::style_sheets::border_style style() const noexcept;
        /// @brief Sets the style specifies what kind of border to display.
        /// @param value The style specifies what kind of border to display.
        void style(xtd::forms::style_sheets::border_style value) noexcept;

        /// @brief Gets the width specifies the width of the border.
        /// @return The width specifies the width of the border.
        int32_t width() const noexcept;
        /// @brief Sets the width specifies the width of the border.
        /// @param value The width specifies the width of the border.
        void width(int32_t value) noexcept;
        /// @}
        
        /// @method
        
        /// @}
        xtd::ustring to_string() const noexcept override;
        /// @brief Return a xtd::string that represents the css format of the current xtd::forms::style_sheets::border_data object.
        /// @return A xtd::string that represents the css format of the current xtd::forms::style_sheets::border_data object.
        xtd::ustring to_css() const noexcept;
        /// @}

      private:
        xtd::forms::style_sheets::color_data color_;
        xtd::forms::style_sheets::border_style style_ = xtd::forms::style_sheets::border_style::none;
        int32_t width_ = 3;
        int32_t radius_ = 0;
      };
    }
  }
}

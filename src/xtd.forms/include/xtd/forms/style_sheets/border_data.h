/// @file
/// @brief Contains xtd::forms::style_sheets::border_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <xtd/object.h>
#include <xtd/drawing/solid_brush.h>
#include "../../forms_export.h"
#include "border_style.h"

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
      class forms_export_ border_data : public xtd::object {
      public:
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_data class.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                      | Default value                                        |
        /// |-----------------------------------------------|------------------------------------------------------|
        /// | xtd::forms::style_sheets::border_data::color  | xtd::draing::solid_brush(xtd::drawing::color::black) |
        /// | xtd::forms::style_sheets::border_data::style  | xtd::forms::style_sheets::border_style::none         |
        /// | xtd::forms::style_sheets::border_data::width  | 3                                                    |
        /// | xtd::forms::style_sheets::border_data::radius | 0                                                    |
        border_data() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_data class with specified color, style, width and radius.
        /// @param color The color is used to set the color of the border.
        /// @param style The style specifies what kind of border to display.
        /// @param width The width specifies the width of the border.
        /// @param radius The radius is used to add rounded borders to an element.
        border_data(const std::shared_ptr<xtd::drawing::brush>& color, xtd::forms::style_sheets::border_style style, int32_t width, int32_t radius);

        /// @cond
        border_data(const border_data&) = default;
        border_data(border_data&&) = default;
        border_data& operator=(const border_data&) = default;
        /// @endcond
        
        /// @brief Gets the color is used to set the color of the border.
        /// @return The color is used to set the color of the border.
        const std::shared_ptr<xtd::drawing::brush>& color() const noexcept;
        
        /// @brief Gets the radius is used to add rounded borders to an element.
        /// @return The radius is used to add rounded borders to an element.
        int32_t radius() const noexcept;

        /// @brief Gets the style specifies what kind of border to display.
        /// @return The style specifies what kind of border to display.
        xtd::forms::style_sheets::border_style style() const noexcept;
        
        /// @brief Gets the width specifies the width of the border.
        /// @return The width specifies the width of the border.
        int32_t width() const noexcept;

      private:
        std::shared_ptr<xtd::drawing::brush> color_ = std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::color::black);
        xtd::forms::style_sheets::border_style style_ = xtd::forms::style_sheets::border_style::none;
        int32_t width_ = 3;
        int32_t radius_ = 0;
      };
    }
  }
}

/// @file
/// @brief Contains xtd::forms::style_sheets::color_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <xtd/object.h>
#include <xtd/drawing/brush.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/rectangle.h>
#include "../../forms_export.h"
#include "color_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The color data allow you to specify the style, colors and gradient mode.
      /// @code
      /// class forms_export_ color_data : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::color_data
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks This class is used by xtd::forms::style_sheets::color_renderer.
      class forms_export_ color_data : public xtd::object {
      public:
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::color_data class.
        /// @remarks The following table shows the default values for the properties :
        /// | Property                                     | Default value                                         |
        /// |----------------------------------------------|-------------------------------------------------------|
        /// | xtd::forms::style_sheets::color_data::style  | xtd::forms::style_sheets::color_style::solid          |
        /// | xtd::forms::style_sheets::color_data::colors | An array with one color : xtd::drawing::color::black) |
        /// | xtd::forms::style_sheets::color_data::angle  | 90                                                    |
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        color_data() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::color_data class with specified color.
        /// @param color The colors specifies what colors to display.
        /// | Property                                     | Default value                                         |
        /// |----------------------------------------------|-------------------------------------------------------|
        /// | xtd::forms::style_sheets::color_data::style  | xtd::forms::style_sheets::color_style::solid          |
        /// | xtd::forms::style_sheets::color_data::angle  | 90                                                    |
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        /// @remarks For xtd::forms::style_sheets::color_style::color, only the first color is used.
        color_data(const xtd::drawing::color& color);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::color_data class with specified style and colors.
        /// @param style The style specifies what kind of color to display.
        /// @param colors The colors specifies what colors to display.
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        /// @remarks For xtd::forms::style_sheets::color_style::color, only the first color is used.
        /// @exception xtd::argument_exception colors is empty.
        /// @exception xtd::not_supported_exception xtd::forms::style_sheets::color_data::style is not of xtd::forms::style_sheets::color_style::solid and not xtd::forms::style_sheets::color_style::linear_gradient.
        color_data(xtd::forms::style_sheets::color_style style, const std::vector<xtd::drawing::color>& colors);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::color_data class with specified style, colors and angle.
        /// @param style The style specifies what kind of color to display.
        /// @param colors The colors specifies what colors to display.
        /// @param angle The angle specifies the gradient direction.
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        /// @remarks For xtd::forms::style_sheets::color_style::color, only the first color is used.
        /// @exception xtd::argument_exception colors is empty.
        /// @exception xtd::not_supported_exception if xtd::forms::style_sheets::color_data::style is not of xtd::forms::style_sheets::color_style::solid and not xtd::forms::style_sheets::color_style::linear_gradient.
        color_data(xtd::forms::style_sheets::color_style style, const std::vector<xtd::drawing::color>& colors, int32_t angle);

        /// @cond
        color_data(const color_data&) = default;
        color_data(color_data&&) = default;
        color_data& operator=(const color_data&) = default;
        /// @endcond
        
        /// @brief Gets the style specifies what kind of color to display.
        /// @return The style specifies what kind of color to display.
        xtd::forms::style_sheets::color_style style() const noexcept;
        
        /// @brief Gets the colors specifies what colors to display.
        /// @return The colors specifies what colors to display.
        /// @remarks For xtd::forms::style_sheets::color_style::color, only the first color is used.
        const std::vector<xtd::drawing::color>& colors() const noexcept;
        
        /// @brief Gets the angle specifies the gradient direction.
        /// @return The angle specifies the gradient direction.
        /// @remarks A value of 0 for angle is equivalent to "to top", a value of 90 for rangle is equivalent to "to right". a value of 180 for angle is equivalent to "to bottom", ...
        int32_t angle() const noexcept;
        
        /// @brief Creates a xtd::drawing::brush from specified color data and rectangle.
        /// @param color Contains color data.
        /// @param rect The xtd::drawing::rectangle neeed for linear gradient brush
        /// @return New instance of brush.
        static std::unique_ptr<xtd::drawing::brush> make_brush(const xtd::forms::style_sheets::color_data& color, const xtd::drawing::rectangle& rect);

      private:
        color_style style_ = color_style::solid;
        std::vector<xtd::drawing::color> colors_ = {xtd::drawing::color::black};
        int32_t angle_ = 90;
      };
    }
  }
}

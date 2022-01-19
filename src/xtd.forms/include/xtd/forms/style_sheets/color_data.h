/// @file
/// @brief Contains xtd::forms::style_sheets::color_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <xtd/object.h>
#include <xtd/drawing/solid_brush.h>
#include "../../forms_export.h"
#include "color_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The color data allow you to specify the style, width, and color of an element's color.
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
        /// | Property                                      | Default value                                        |
        /// |-----------------------------------------------|------------------------------------------------------|
        /// | xtd::forms::style_sheets::color_data::color  | xtd::drawing::solid_brush(xtd::drawing::color::black) |
        /// | xtd::forms::style_sheets::color_data::style  | xtd::forms::style_sheets::color_style::none         |
        /// | xtd::forms::style_sheets::color_data::width  | 3                                                    |
        /// | xtd::forms::style_sheets::color_data::radius | 0                                                    |
        color_data() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::color_data class with specified color, style, width and radius.
        /// @param style The style specifies what kind of color to display.
        color_data(xtd::forms::style_sheets::color_style style);
        
        /// @cond
        color_data(const color_data&) = default;
        color_data(color_data&&) = default;
        color_data& operator=(const color_data&) = default;
        /// @endcond
        
        /// @brief Gets the style specifies what kind of color to display.
        /// @return The style specifies what kind of color to display.
        xtd::forms::style_sheets::color_style style() const noexcept;
        
      private:
        color_style style_ = color_style::solid;
      };
    }
  }
}

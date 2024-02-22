/// @file
/// @brief Contains xtd::drawing::drawing_2d::hatch_brush class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../../drawing_export.h"
#include "../brush.h"
#include "../color.h"
#include "../image.h"
#include "../point.h"
#include "../rectangle.h"
#include "drawing2d.h"
#include "hatch_style.h"
#include <xtd/iequatable>
#include <array>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing_2d/ namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief Defines a rectangular xtd::drawing::brush with a hatch style, a foreground color, and a background color. This class cannot be inherited.
      /// @par Namespace
      /// xtd::drawing::drawing_2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing brushes
      /// @remarks The following illustration shows a rectangle filled with the xtd::drawing::drawing_2d::hatch_style::diagonal_brick hatch pattern.
      /// @image html hatch_brush.png
      /// @par Examples
      /// The following code example demonstrates the use of hatch_brush class.
      /// @include fill_rectangle.cpp
      class drawing_export_ hatch_brush final : public brush, public xtd::iequatable<hatch_brush> {
        struct data;
        
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::hatch_brush class with the specified xtd::drawing::drawing_2d::hatch_style enumeration and foreground color.
        /// @param hatch_style One of the xtd::drawing::drawing_2d::hatch_style values that represents the pattern drawn by this xtd::drawing::drawing_2d::hatch_brush.
        /// @param fore_color The xtd::drawing::color structure that represents the color of lines drawn by this xtd::drawing::drawing_2d::hatch_brush.
        /// @remarks The background color is initialized to black.
        hatch_brush(xtd::drawing::drawing_2d::hatch_style hatch_style, const xtd::drawing::color& fore_color);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::hatch_brush class with the specified xtd::drawing::drawing_2d::hatch_style enumeration, foreground color and background color.
        /// @param hatch_style One of the xtd::drawing::drawing_2d::hatch_style values that represents the pattern drawn by this xtd::drawing::drawing_2d::hatch_brush.
        /// @param fore_color The xtd::drawing::color structure that represents the color of lines drawn by this xtd::drawing::drawing_2d::hatch_brush.
        /// @param back_color The xtd::drawing::color structure that represents the color of spaces between the lines drawn by this xtd::drawing::drawing_2d::hatch_brush.
        hatch_brush(xtd::drawing::drawing_2d::hatch_style hatch_style, const xtd::drawing::color& fore_color, const xtd::drawing::color& back_color);
        /// @}
        
        /// @cond
        hatch_brush(const hatch_brush& value);
        hatch_brush& operator =(const hatch_brush& value);
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the color of spaces between the hatch lines drawn by this hatch_brush object.
        /// @return A xtd::drawing::color structure that represents the background color for this hatch_brush.
        xtd::drawing::color background_color() const noexcept;
        
        /// @brief Gets the color of hatch lines drawn by this hatch_brush object.
        /// @return A xtd::drawing::color structure that represents the foreground color for this hatch_brush.
        xtd::drawing::color foreground_color() const noexcept;
        
        /// @brief Gets the hatch style of this hatch_brush object.
        /// @return One of the xtd::drawing::drawing_2d::hatch_style values that represents the pattern of this hatch_brush.
        xtd::drawing::drawing_2d::hatch_style hatch_style() const noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        using brush::equals;
        bool equals(const hatch_brush& value) const noexcept override;
        /// @}
        
      private:
        hatch_brush();
        void recreate_handle();
        
        std::shared_ptr<data> data_;
      };
    }
  }
}


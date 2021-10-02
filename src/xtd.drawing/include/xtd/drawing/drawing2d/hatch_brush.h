/// @file
/// @brief Contains xtd::drawing::drawing2d::hatch_brush class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <array>
#include "../../drawing_export.h"
#include "../brush.h"
#include "../color.h"
#include "../image.h"
#include "../point.h"
#include "../rectangle.h"
#include "hatch_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::.drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Defines a rectangular brush with a hatch style, a foreground color, and a background color. This class cannot be inherited.
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing drawing
      /// @remarks The following illustration shows an ellipse filled with a horizontal hatch pattern.
      /// @image html hatch1.png
      /// @par Examples
      /// The following code example demonstrate the use of hatch_brush class.
      /// @include fill_rectangle.cpp
      class drawing_export_ hatch_brush final : public brush {
      public:
        /// @brief Initializes a new instance of the hatch_brush class.
        hatch_brush();
        /// @brief Initializes a new instance of the xtd::drawing::drawing2d::hatch_brush class with the specified xtd::drawing::drawing2d::hatch_style enumeration and foreground color.
        /// @param hatch_style One of the xtd::drawing::drawing2d::hatch_style values that represents the pattern drawn by this xtd::drawing::drawing2d::hatch_brush.
        /// @param fore_color The xtd::drawing::color structure that represents the color of lines drawn by this xtd::drawing::drawing2d::hatch_brush.
        /// @remarks The background color is initialized to black.
        hatch_brush(xtd::drawing::drawing2d::hatch_style hatch_style, const xtd::drawing::color& fore_color) : hatch_brush(hatch_style, fore_color, xtd::drawing::color::black) {}
        /// @brief Initializes a new instance of the xtd::drawing::drawing2d::hatch_brush class with the specified xtd::drawing::drawing2d::hatch_style enumeration, foreground color and background color.
        /// @param hatch_style One of the xtd::drawing::drawing2d::hatch_style values that represents the pattern drawn by this xtd::drawing::drawing2d::hatch_brush.
        /// @param fore_color The xtd::drawing::color structure that represents the color of lines drawn by this xtd::drawing::drawing2d::hatch_brush.
        /// @param back_color The xtd::drawing::color structure that represents the color of spaces between the lines drawn by this xtd::drawing::drawing2d::hatch_brush.
        hatch_brush(xtd::drawing::drawing2d::hatch_style hatch_style, const xtd::drawing::color& fore_color, const xtd::drawing::color& back_color);

        /// @cond
        hatch_brush(const hatch_brush& value);
        hatch_brush& operator=(const hatch_brush& value);
        bool operator==(const hatch_brush& value) const {return data_->hatch_style_ == value.data_->hatch_style_ && data_->fore_color_ == value.data_->fore_color_ && data_->back_color_ == value.data_->back_color_;}
        bool operator!=(const hatch_brush& value) const {return !operator==(value);}
        /// @endcond
        
        /// @brief Gets the color of spaces between the hatch lines drawn by this hatch_brush object.
        /// @return A xtd::drawing::color structure that represents the background color for this hatch_brush.
        xtd::drawing::color background_color() const {return data_->back_color_;}
        
        /// @brief Gets the color of hatch lines drawn by this hatch_brush object.
        /// @return A xtd::drawing::color structure that represents the foreground color for this hatch_brush.
        xtd::drawing::color foreground_color() const {return data_->fore_color_;}
        
        /// @brief Gets the hatch style of this hatch_brush object.
        /// @return One of the xtd::drawing::drawing2d::hatch_style values that represents the pattern of this hatch_brush.
        xtd::drawing::drawing2d::hatch_style hatch_style() const {return data_->hatch_style_;}

        private:
        void recreate_handle();
        struct data {
          xtd::drawing::drawing2d::hatch_style hatch_style_ = xtd::drawing::drawing2d::hatch_style::horizontal;
          xtd::drawing::color fore_color_;
          xtd::drawing::color back_color_;
        };
        std::shared_ptr<data> data_ = std::make_shared<data>();
      };
    }
  }
}

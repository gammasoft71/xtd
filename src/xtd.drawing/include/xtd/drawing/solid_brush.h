/// @file
/// @brief Contains xtd::drawing::solid_brush class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "brush.h"
#include "color.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Defines a xtd::drawing::brush of a single color. Brushes are used to fill graphics shapes, such as rectangles, ellipses, pies, polygons, and paths. This class cannot be inherited.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @par Examples
    /// The following code example demonstrate the use of solid_brush class.
    /// @include fill_rectangle.cpp
    /// @par Windows
    /// @image html fill_rectangle_w.png
    /// <br>
    /// @image html fill_rectangle_wd.png
    /// @par macOS
    /// @image html fill_rectangle_m.png
    /// <br>
    /// @image html fill_rectangle_md.png
    /// @par Gnome
    /// @image html fill_rectangle_g.png
    /// <br>
    /// @image html fill_rectangle_gd.png
    class drawing_export_ solid_brush final : public brush {
    public:
      solid_brush();
      solid_brush(const drawing::color& color) {this->color(color);}

      /// @cond
      solid_brush(const solid_brush& value);
      solid_brush& operator=(const solid_brush& value);
      bool operator==(const solid_brush& value) const {return data_->color_ == value.data_->color_;}
      bool operator!=(const solid_brush& value) const {return !operator==(value);}
      /// @endcond
      
      const drawing::color& color() const {return data_->color_;}
      solid_brush& color(const drawing::color& color);
      
    private:
      struct data {
        drawing::color color_;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}

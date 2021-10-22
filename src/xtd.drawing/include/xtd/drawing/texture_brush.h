/// @file
/// @brief Contains xtd::drawing::texture_brush class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "brush.h"
#include "image.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::texture_brush class is a xtd::drawing::brush object that uses an image to fill the interior of a shape. This class cannot be inherited.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @par Examples
    /// The following code example demonstrate the use of texture_brush class.
    /// @include fill_rectangle.cpp
    class drawing_export_ texture_brush final : public brush {
    public:
      texture_brush(const drawing::image& image) {this->image(image);}

      /// @cond
      texture_brush(const texture_brush& value);
      texture_brush& operator=(const texture_brush& value);
      bool operator==(const texture_brush& value) const {return data_->image_ == value.data_->image_;}
      bool operator!=(const texture_brush& value) const {return !operator==(value);}
      /// @endcond
      
      const drawing::image& image() const {return data_->image_;}
      texture_brush& image(const drawing::image& image);
      
    private:
      texture_brush();
      struct data {
        drawing::image image_;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}

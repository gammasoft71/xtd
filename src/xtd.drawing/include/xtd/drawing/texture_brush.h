/// @file
/// @brief Contains xtd::drawing::texture_brush class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "brush.h"
#include "image.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::texture_brush class is a xtd::drawing::brush object that uses an image to fill the interior of a shape. This class cannot be inherited.
    /// @code
    /// class drawing_export_ texture_brush : public xtd::drawing::brush
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::brush → xtd::drawing::texture_brush
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @image html texture_brush1.png
    /// @par Examples
    /// The following code example demonstrates the use of texture_brush class.
    /// @include fill_rectangle.cpp
    class drawing_export_ texture_brush final : public brush {
    public:
      /// @name Constructors
      
      /// @{
      explicit texture_brush(const drawing::image& image) {this->image(image);}
      /// @}
      
      /// @cond
      texture_brush(const texture_brush& value);
      texture_brush& operator =(const texture_brush& value);
      bool operator ==(const texture_brush& value) const noexcept;
      bool operator !=(const texture_brush& value) const noexcept;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      const drawing::image& image() const noexcept;
      texture_brush& image(const drawing::image& image);
      /// @}
      
    private:
      texture_brush();
      struct data {
        drawing::image image_;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}

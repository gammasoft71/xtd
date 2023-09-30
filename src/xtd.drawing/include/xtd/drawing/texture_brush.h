/// @file
/// @brief Contains xtd::drawing::texture_brush class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "brush.h"
#include "image.h"
#include <xtd/iequatable>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
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
    class drawing_export_ texture_brush final : public brush, public xtd::iequatable<texture_brush> {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new xtd::drawing::texture_brush object that uses the specified image.
      /// @param image The xtd::drawing::image object with which this xtd::drawing::texture_brush object fills interiors.
      explicit texture_brush(const drawing::image& image);
      /// @}
      
      /// @cond
      texture_brush(const texture_brush& value);
      texture_brush& operator =(const texture_brush& value);
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the xtd::drawing::image object associated with this xtd::drawing::texture_brush object.
      /// @return An xtd::drawing::image object that represents the image with which this xtd::drawing::texture_brush object fills shapes.
      const drawing::image& image() const noexcept;
      /// @brief Sets the xtd::drawing::image object associated with this xtd::drawing::texture_brush object.
      /// @param image An xtd::drawing::image object that represents the image with which this xtd::drawing::texture_brush object fills shapes.
      texture_brush& image(const drawing::image& image);
      /// @}
      
      /// @name Methods
      
      /// @{
      using brush::equals;
      bool equals(const texture_brush& value) const noexcept override;
      /// @}
      
    private:
      texture_brush();
      
      std::shared_ptr<data> data_;
    };
  }
}

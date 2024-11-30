/// @file
/// @brief Contains xtd::drawing::brush class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/string>
#include <cstdint>
#include <memory>
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Defines objects used to fill the interiors of graphical shapes such as rectangles, ellipses, pies, polygons, and paths.
    /// ```cpp
    /// class drawing_export_ brush : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::drawing::brush
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing brushes
    /// @remarks This is an abstract base class and cannot be instantiated. To create a brush object, use classes derived from xtd::drawing::brush, such as xtd::drawing::solid_brush, xtd::drawing::texture_brush, xtd::drawing::drawing_2d::hatch_brush, xtd::drawing::drawing_2d::conical_gradient_brush, xtd::drawing::drawing_2d::linear_gradient_brush, and xtd::drawing::drawing_2d::radial_gradient_brush.<br>
    /// |                                                                                             |                                                                                           |                                                                                           |
    /// | ------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------- |
    /// | xtd::drawing::solid_brush<br> @image html solid_brush.png                                   | xtd::drawing::texture_brush<br> @image html texture_brush1.png                            | xtd::drawing::drawing_2d::hatch_brush<br> @image html hatch_brush.png                     |
    /// | xtd::drawing::drawing_2d::conical_gradient_brush<br> @image html conical_gradient_brush.png | xtd::drawing::drawing_2d::linear_gradient_brush<br> @image html linear_gradient_brush.png | xtd::drawing::drawing_2d::radial_gradient_brush<br> @image html radial_gradient_brush.png |
    class drawing_export_ brush : public xtd::object, public xtd::iequatable<brush> {
      struct data;
      
    public:
      /// @cond
      brush(const brush& value);
      brush& operator =(const brush& value);
      ~brush();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the handle of the brush.
      /// @return An intptr that contains the handle of the brush.
      intptr handle() const noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      using object::equals;
      bool equals(const brush& value) const noexcept override;
      
      /// @brief Converts this brush object to a human-readable string.
      /// @return A string that represents this brush object.
      xtd::string to_string() const noexcept override;
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initialize a new instance of brush class.
      brush();
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief In a derived class, sets a reference to a GDI+ brush object.
      /// @param brush A pointer to the GDI+ brush object.
      void set_native_brush(intptr brush);
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}

/// @file
/// @brief Contains xtd::drawing::rectangle class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cmath>
#include <cstdint>
#include <ostream>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../drawing_export.h"
#include "point.h"
#include "size.h"
#include "rectangle_f.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Stores a set of four integers that represent the location and size of a rectangle.
    /// @code
    /// class drawing_export_ rectangle : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::rectangle
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @par Examples
    /// The following example draws a rectangle with its upper-left corner at (10, 10). The rectangle has a width of 100 and a height of 50. The second argument passed to the Pen constructor indicates that the pen width is 5 pixels.<br><br>
    /// When the rectangle is drawn, the pen is centered on the rectangle's boundary. Because the pen width is 5, the sides of the rectangle are drawn 5 pixels wide, such that 1 pixel is drawn on the boundary itself, 2 pixels are drawn on the inside, and 2 pixels are drawn on the outside. For more details on pen alignment, see How to: Set Pen Width and Alignment.<br><br>
    /// The following illustration shows the resulting rectangle. The dotted lines show where the rectangle would have been drawn if the pen width had been one pixel. The enlarged view of the upper-left corner of the rectangle shows that the thick black lines are centered on those dotted lines.<br><br>
    /// @image html rectangle_pens.png
    /// <br>The example is designed for use with xtd.forms, and it requires xtd::forms::paint_event_ergs e, which is a parameter of the xtd::control::paint event handler.
    /// @code
    /// pen black_pen(color::from_argb(255, 0, 0, 0), 5);
    /// e.graphics().draw_rectangle(black_pen, 10, 10, 100, 50);
    /// @endcode
    /// @remarks A rectangle is defined by its xtd::drawing::rectangle::width, xtd::drawing::rectangle::height, and upper-left corner represented by the xtd::drawing::rectangle::location property.
    /// @remarks To draw rectangles, you need a xtd::drawing::graphics object and a xtd::drawing::pen object. The xtd::drawing::graphics object provides the xtd::drawing::graphics::draw_rectangle method, and the xtd::drawing::pen object stores features of the line, such as color and width. The units the rectangle is drawn in is determined by the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale properties of the graphics object used for drawing. The default unit is pixels.
    /// @remarks To draw a xtd::drawing::rectangle filled with color, you need a xtd::drawing::graphics object and an object derived from xtd::drawing::brush such as xtd::drawing::solid_brush or xtd::drawing::texture_brush or xtd::drawing::drawing2d::conical_gradient_brush or xtd::drawing::drawing2d::hatch_gradient_brush or xtd::drawing::drawing2d::linear_gradient_brush or xtd::drawing::drawing2d::radial_gradient_brush. The xtd::drawing::graphics object provides the xtd::drawing::graphics::fill_rectangle method and the xtd::drawing::brush object provides the color and fill information.
    /// @remarks For more advanced shapes, use a xtd::drawing::region object.
    class drawing_export_ rectangle : public xtd::object {
    public:
      /// @name Fields
      
      /// @{
      /// @brief Represents a xtd::drawing::rectangle that has xtd::drawing::rectagle::x, xtd::drawing::rectangle::y, xtd::drawing::rectangle::width and xtd::drawing::rectangle::height values set to zero.
      static const rectangle empty;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::drawing::rectangle class
      /// @remarks xtd::drawing::rectagle::x, xtd::drawing::rectangle::y, xtd::drawing::rectangle::width and xtd::drawing::rectangle::height values are set to zero.
      rectangle() noexcept = default;
      /// @brief Initializes a new instance of the xtd::drawing::rectangle class with the specified location and size.
      /// @param x The x-coordinate of the upper-left corner of the rectangle.
      /// @param y The y-coordinate of the upper-left corner of the rectangle.
      /// @param width The width of the rectangle.
      /// @param height The height of the rectangle.
      rectangle(int32_t x, int32_t y, int32_t width, int32_t height) noexcept;
      /// @brief Initializes a new instance of the xtd::drawing::rectangle class with the specified location and size.
      /// @param location A xtd::drawing::point that represents the upper-left corner of the rectangular region.
      /// @param size A xtd::drawing::size that represents the width and height of the rectangular region.
      rectangle(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @}
      
      /// @cond
      rectangle(const rectangle&) noexcept = default;
      rectangle& operator=(const rectangle&) noexcept = default;
      operator rectangle_f() const noexcept;
      bool operator==(const rectangle& value) const noexcept;
      bool operator!=(const rectangle& value) const noexcept;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the y-coordinate that is the sum of the Y and Height property values of this Rectangle structure.
      /// @return The y-coordinate that is the sum of xtd::drawing::rectangle::y and xtd::drawing::rectangle::height of this xtd::drawing::rectangle.
      /// @remarks The value of the xtd::drawing::rectangle::bottom property represents the y-coordinate of the first point at the bottom edge of the xtd::drawing::rectangle that is not contained in the xtd::drawing::rectangle.
      int32_t bottom() const noexcept;
      
      /// @brief Gets the height of this xtd::drawing::rectangle structure.
      /// @return The height of this Rectangle structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle::height property will also cause a change in the xtd::drawing::rectangle::bottom property of the xtd::drawing::rectangle. The units the rectangle is drawn in is determined by the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale properties of the graphics object used for drawing. The default unit is pixels.
      int32_t height() const noexcept;
      /// @brief Sets the height of this xtd::drawing::rectangle structure.
      /// @param value The height of this Rectangle structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle::height property will also cause a change in the xtd::drawing::rectangle::bottom property of the xtd::drawing::rectangle. The units the rectangle is drawn in is determined by the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale properties of the graphics object used for drawing. The default unit is pixels.
      void height(int32_t value) noexcept;
      
      /// @brief Tests whether all numeric properties of this xtd::drawing::rectangle have values of zero.
      /// @return This property returns true if the xtd::drawing::rectangle::width, xtd::drawing::rectangle::height, xtd::drawing::rectangle::x, and xtd::drawing::rectangle::y properties of this xtd::drawing::rectangle all have values of zero; otherwise, false.
      bool is_empty() const noexcept;
      
      /// @brief Gets the x-coordinate of the left edge of this xtd::drawing::rectangle structure.
      /// @return The x-coordinate of the left edge of this xtd::drawing::rectangle structure.
      int32_t left() const noexcept;
      
      /// @brief Gets the coordinates of the upper-left corner of this xtd::drawing::rectangle structure.
      /// @return A xtd::drawing::point that represents the upper-left corner of this xtd::drawing::rectangle structure.
      xtd::drawing::point location() const noexcept;
      /// @brief Sets the coordinates of the upper-left corner of this xtd::drawing::rectangle structure.
      /// @param value A xtd::drawing::point that represents the upper-left corner of this xtd::drawing::rectangle structure.
      void location(const xtd::drawing::point& value) noexcept;
      
      /// @brief Gets the x-coordinate that is the sum of xtd::drawing::rectangle::x and xtd::drawing::rectangle::width property values of this xtd::drawing::rectangle structure.
      /// @return The x-coordinate that is the sum of xtd::drawing::rectangle::x and xtd::drawing::rectangle::width of this xtd::drawing::rectangle.
      int32_t right() const noexcept;
      
      /// @brief Gets the size of this xtd::drawing::rectangle.
      /// @return A xtd::drawing::size that represents the width and height of this xtd::drawing::rectangle structure.
      xtd::drawing::size size() const noexcept;
      /// @brief Sets the size of this xtd::drawing::rectangle.
      /// @param value A xtd::drawing::size that represents the width and height of this xtd::drawing::rectangle structure.
      void size(const xtd::drawing::size& value) noexcept;
      
      /// @brief Gets the y-coordinate of the top edge of this xtd::drawing::rectangle structure.
      /// @return The y-coordinate of the top edge of this xtd::drawing::rectangle structure.
      int32_t top() const noexcept;
      
      /// @brief Gets the width of this xtd::drawing::rectangle structure.
      /// @return The width of this xtd::drawing::rectangle structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle::width property will also cause a change in the xtd::drawing::rectangle::bottom property of the xtd::drawing::rectangle. The units the rectangle is drawn in is determined by the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale properties of the graphics object used for drawing. The default unit is pixels.
      int32_t width() const noexcept;
      /// @brief Sets the width of this xtd::drawing::rectangle structure.
      /// @param value The width of this xtd::drawing::rectangle structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle::width property will also cause a change in the xtd::drawing::rectangle::bottom property of the xtd::drawing::rectangle. The units the rectangle is drawn in is determined by the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale properties of the graphics object used for drawing. The default unit is pixels.
      void width(int32_t value) noexcept;

      /// @brief Gets the x-coordinate of the upper-left corner of this xtd::drawing::rectangle structure.
      /// @return The x-coordinate of the upper-left corner of this xtd::drawing::rectangle structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle::x property will also cause a change in the xtd::drawing::rectangle::right property of the xtd::drawing::rectangle.
      int32_t x() const noexcept;
      /// @brief Sets the x-coordinate of the upper-left corner of this xtd::drawing::rectangle structure.
      /// @param value The x-coordinate of the upper-left corner of this xtd::drawing::rectangle structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle::x property will also cause a change in the xtd::drawing::rectangle::right property of the xtd::drawing::rectangle.
      void x(int32_t value) noexcept;
      
      /// @brief Gets the y-coordinate of the upper-left corner of this xtd::drawing::rectangle structure.
      /// @return The y-coordinate of the upper-left corner of this xtd::drawing::rectangle structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle::y property will also cause a change in the xtd::drawing::rectangle::bottom property of the xtd::drawing::rectangle.
      int32_t y() const noexcept;
      /// @brief Sets the y-coordinate of the upper-left corner of this xtd::drawing::rectangle structure.
      /// @param value The y-coordinate of the upper-left corner of this xtd::drawing::rectangle structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle::y property will also cause a change in the xtd::drawing::rectangle::bottom property of the xtd::drawing::rectangle.
      void y(int32_t value) noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Converts the specified xtd::drawing::rectangle_f structure to a xtd::drawing::rectangle structure by rounding the xtd::drawing::rectangle_f values to the next higher integer values.
      /// @param rect The xtd::drawing::rectangle_f structure to be converted.
      /// @return Returns a xtd::drawing::rectangle.
      static rectangle ceiling(const xtd::drawing::rectangle_f& rect) noexcept;
      
      bool contains(const xtd::drawing::point& pt) const noexcept;
      bool contains(const xtd::drawing::rectangle& rect) const noexcept;
      bool contains(int32_t x, int32_t y) const noexcept;
      
      static rectangle from_ltrb(int32_t left, int32_t top, int32_t right, int32_t bottom) noexcept;
      
      void inflate(const drawing::size& sz) noexcept;
      void inflate(int width, int height) noexcept;
      static rectangle inflate(const rectangle& rect, const drawing::size& sz) noexcept;
      static rectangle inflate(const rectangle& rect, int width, int height) noexcept;
      
      bool intersects_with(const rectangle& rect) const noexcept;
      
      static rectangle make_intersect(const rectangle& a, const rectangle& b) noexcept;
      void make_intersect(const rectangle& rect) noexcept;
      
      static rectangle make_union(const rectangle& a, const rectangle& b) noexcept;
      void make_union(const rectangle& rect) noexcept;
      
      void offset(const point& pt) noexcept;
      void offset(int32_t dx, int32_t dy) noexcept;
      static rectangle offset(const rectangle& rect, const point& pt) noexcept;
      static rectangle offset(const rectangle& rect, int x, int y) noexcept;
      
      static rectangle round(const rectangle_f& rect) noexcept;
      
      static rectangle trunc(const rectangle_f& rect) noexcept;
      
      xtd::ustring to_string() const noexcept override;
      /// @}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::rectangle& rectangle) noexcept {return os << rectangle.to_string();}
      /// @endcond
      
    private:
      int32_t x_ = 0;
      int32_t y_ = 0;
      int32_t width_ = 0;
      int32_t height_ = 0;
    };
  }
}

/// @file
/// @brief Contains xtd::drawing::rectangle_f class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "point_f.h"
#include "size_f.h"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/ustring>
#include <cstdint>
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class rectangle;
    /// @endcond
    
    /// @brief Stores a set of four floating-point numbers that represent the location and size of a rectangle. For more advanced region functions, use a xtd::drawing::region object.
    /// @code
    /// class drawing_export_ rectangle_f : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::rectangle_f
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks A rectangle is defined by its width, height, and upper-left corner.
    class drawing_export_ rectangle_f : public xtd::object, public xtd::iequatable<rectangle_f> {
    public:
      /// @name Fields
      
      /// @{
      /// @brief Represents a xtd::drawing::rectangle_F that has xtd::drawing::rectagle_f::x, xtd::drawing::rectangle_f::y, xtd::drawing::rectangle_f::width and xtd::drawing::rectangle_f::height values set to zero.
      static const rectangle_f empty;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::drawing::rectagle_f class
      /// @remarks xtd::drawing::rectagle_f::x, xtd::drawing::rectagle_f::y, xtd::drawing::rectagle_f::width and xtd::drawing::rectagle_f::height values are set to zero.
      rectangle_f() noexcept = default;
      /// @brief Initializes a new instance of the xtd::drawing::rectagle_f class with the specified location and size.
      /// @param x The x-coordinate of the upper-left corner of the rectangle.
      /// @param y The y-coordinate of the upper-left corner of the rectangle.
      /// @param width The width of the rectangle.
      /// @param height The height of the rectangle.
      rectangle_f(float x, float y, float width, float height) noexcept;
      /// @brief Initializes a new instance of the xtd::drawing::rectagle_f class with the specified location and size.
      /// @param location A xtd::drawing::point_f that represents the upper-left corner of the rectangular region.
      /// @param size A xtd::drawing::size_f that represents the width and height of the rectangular region.
      rectangle_f(const point_f& location, const size_f& size) noexcept;
      /// @}
      
      /// @cond
      rectangle_f(const rectangle_f&) noexcept = default;
      rectangle_f& operator =(const rectangle_f&) noexcept = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the y-coordinate that is the sum of the xtd::drawing::rectangle_f::y and xtd::drawing::rectangle_f::height property values of this xtd::drawing::rectangle_f structure.
      /// @return The y-coordinate that is the sum of xtd::drawing::rectangle_f::y and xtd::drawing::rectangle_f::height of this xtd::drawing::rectangle_f.
      /// @remarks The value of the xtd::drawing::rectangle_f::bottom property represents the y-coordinate of the first point at the bottom edge of the xtd::drawing::rectangle_f that is not contained in the xtd::drawing::rectangle_f.
      float bottom() const noexcept;
      
      /// @brief Gets the center property values of this xtd::drawing::rectangle structure.
      /// @return The center of this xtd::drawing::rectangle.
      point_f center() const noexcept;

      /// @brief Gets the height of this xtd::drawing::rectangle_f structure.
      /// @return The height of this Rectangle structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle_f::height property will also cause a change in the xtd::drawing::rectangle_f::bottom property of the xtd::drawing::rectangle_f. The units the rectangle is drawn in is determined by the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale properties of the graphics object used for drawing. The default unit is pixels.
      float height() const noexcept;
      /// @brief Sets the height of this xtd::drawing::rectangle_f structure.
      /// @param value The height of this Rectangle structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle_f::height property will also cause a change in the xtd::drawing::rectangle_f::bottom property of the xtd::drawing::rectangle_f. The units the rectangle is drawn in is determined by the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale properties of the graphics object used for drawing. The default unit is pixels.
      void height(float height) noexcept;
      
      /// @brief Tests whether all numeric properties of this xtd::drawing::rectangle_f have values of zero.
      /// @return This property returns true if the xtd::drawing::rectangle_f::width, xtd::drawing::rectangle_f::height, xtd::drawing::rectangle_f::x, and xtd::drawing::rectangle_f::y properties of this xtd::drawing::rectangle_f all have values of zero; otherwise, false.
      bool is_empty() const noexcept;
      
      /// @brief Gets the x-coordinate of the left edge of this xtd::drawing::rectangle_f structure.
      /// @return The x-coordinate of the left edge of this xtd::drawing::rectangle_f structure.
      float left() const noexcept;
      
      /// @brief Gets the coordinates of the upper-left corner of this xtd::drawing::rectangle_f structure.
      /// @return A xtd::drawing::point_f that represents the upper-left corner of this xtd::drawing::rectangle_f structure.
      point_f location() const noexcept;
      /// @brief Sets the coordinates of the upper-left corner of this xtd::drawing::rectangle_f structure.
      /// @param value A xtd::drawing::point_f that represents the upper-left corner of this xtd::drawing::rectangle_f structure.
      void location(const point_f& location);
      
      /// @brief Gets the x-coordinate that is the sum of xtd::drawing::rectangle_f::x and xtd::drawing::rectangle_f::width property values of this xtd::drawing::rectangle_f structure.
      /// @return The x-coordinate that is the sum of xtd::drawing::rectangle_f::x and xtd::drawing::rectangle_f::width of this xtd::drawing::rectangle_f.
      float right() const noexcept;
      
      /// @brief Gets the size of this xtd::drawing::rectangle_f.
      /// @return A xtd::drawing::size_f that represents the width and height of this xtd::drawing::rectangle_f structure.
      size_f size() const noexcept;
      /// @brief Sets the size of this xtd::drawing::rectangle_f.
      /// @param value A xtd::drawing::size_f that represents the width and height of this xtd::drawing::rectangle_f structure.
      void size(const size_f& size) noexcept;
      
      /// @brief Gets the y-coordinate of the top edge of this xtd::drawing::rectangle_f structure.
      /// @return The y-coordinate of the top edge of this xtd::drawing::rectangle_f structure.
      float top() const noexcept;
      
      /// @brief Gets the width of this xtd::drawing::rectangle_f structure.
      /// @return The width of this xtd::drawing::rectangle_f structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle_f::width property will also cause a change in the xtd::drawing::rectangle_f::bottom property of the xtd::drawing::rectangle_f. The units the rectangle is drawn in is determined by the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale properties of the graphics object used for drawing. The default unit is pixels.
      float width() const noexcept;
      /// @brief Sets the width of this xtd::drawing::rectangle_f structure.
      /// @param value The width of this xtd::drawing::rectangle_f structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle_f::width property will also cause a change in the xtd::drawing::rectangle_f::bottom property of the xtd::drawing::rectangle_f. The units the rectangle is drawn in is determined by the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale properties of the graphics object used for drawing. The default unit is pixels.
      void width(float width) noexcept;
      
      /// @brief Gets the x-coordinate of the upper-left corner of this xtd::drawing::rectangle_f structure.
      /// @return The x-coordinate of the upper-left corner of this xtd::drawing::rectangle_f structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle_f::x property will also cause a change in the xtd::drawing::rectangle_f::right property of the xtd::drawing::rectangle_f.
      float x() const noexcept;
      /// @brief Sets the x-coordinate of the upper-left corner of this xtd::drawing::rectangle_f structure.
      /// @param value The x-coordinate of the upper-left corner of this xtd::drawing::rectangle_f structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle_f::x property will also cause a change in the xtd::drawing::rectangle_f::right property of the xtd::drawing::rectangle_f.
      void x(float x) noexcept;
      
      /// @brief Gets the y-coordinate of the upper-left corner of this xtd::drawing::rectangle_f structure.
      /// @return The y-coordinate of the upper-left corner of this xtd::drawing::rectangle_f structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle_f::y property will also cause a change in the xtd::drawing::rectangle_f::bottom property of the xtd::drawing::rectangle_f.
      float y() const noexcept;
      /// @brief Sets the y-coordinate of the upper-left corner of this xtd::drawing::rectangle_f structure.
      /// @param value The y-coordinate of the upper-left corner of this xtd::drawing::rectangle_f structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle_f::y property will also cause a change in the xtd::drawing::rectangle_f::bottom property of the xtd::drawing::rectangle_f.
      void y(float y) noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Adds this xtd::drawing::rectangle_f by the specified amount.
      /// @param sz The amount to add this rectangle.
      /// @remarks This method adds this rectangle, not a copy of it.
      void add(const drawing::size_f& sz) noexcept;
      /// @brief Adds this xtd::drawing::rectangle_f by the specified amount.
      /// @param width The amount to add this xtd::drawing::rectangle_f horizontally.
      /// @param height The amount to add this xtd::drawing::rectangle_f verticaly.
      /// @remarks This method adds this rectangle, not a copy of it.
      void add(float width, float height) noexcept;
      /// @brief Creates and returns an added copy of the specified xtd::drawing::rectangle_f structure. The copy is added by the specified amount. The original xtd::drawing::rectangle_f structure remains unmodified.
      /// @param rect The xtd::drawing::rectangle_f with which to start. This rectangle is not modified.
      /// @param x The amount to add the specified rectangle horizontally.
      /// @param y The amount to add the specified rectangle vertically.
      /// @return The added xtd::drawing::rectangle_f.
      /// @remarks This method makes a copy of rect, adds the copy, and then returns the added copy.
      static rectangle_f add(const rectangle_f& rect, float x, float y) noexcept;
      /// @brief Creates and returns an added copy of the specified xtd::drawing::rectangle_f structure. The copy is added by the specified amount. The original xtd::drawing::rectangle_f structure remains unmodified.
      /// @param rect The xtd::drawing::rectangle_f with which to start. This rectangle is not modified.
      /// @param sz The amount to add the specified rectangle.
      /// @return The added xtd::drawing::rectangle_f.
      /// @remarks This method makes a copy of rect, adds the copy, and then returns the added copy.
      static rectangle_f add(const rectangle_f& rect, const drawing::size_f& sz) noexcept;
      
      /// @brief Determines if the specified point is contained within this xtd::drawing::rectangle_f structure.
      /// @param pt The xtd::drawing::point_f to test.
      /// @return This method returns true if the point represented by pt is contained within this xtd::drawing::rectangle_f structure; otherwise false.
      /// @remarks The containing rectangle must be normalized for this method to return accurate results.
      bool contains(const point_f& pt) const noexcept;
      /// @brief Determines if the rectangular region represented by rect is entirely contained within this xtd::drawing::rectangle_f structure.
      /// @param rect The xtd::drawing::rectangle_f to test.
      /// @return This method returns true if the rectangular region represented by rect is entirely contained within this xtd::drawing::rectangle_f structure; otherwise false.
      /// @remarks The containing rectangle must be normalized for this method to return accurate results.
      bool contains(const rectangle_f& rect) const noexcept;
      /// @brief Determines if the specified point is contained within this xtd::drawing::rectangle_f structure.
      /// @param x The x-coordinate of the point to test.
      /// @param y The y-coordinate of the point to test.
      /// @return This method returns true if the point defined by x and y is contained within this xtd::drawing::rectangle_f structure; otherwise false.
      /// @remarks The containing rectangle must be normalized for this method to return accurate results.
      bool contains(float x, float y) const noexcept;
      
      bool equals(const rectangle_f& value) const noexcept override;
      
      /// @brief Creates a xtd::drawing::rectangle_f structure with the specified edge locations.
      /// @param left The x-coordinate of the upper-left corner of this xtd::drawing::rectangle_f structure.
      /// @param top The y-coordinate of the upper-left corner of this xtd::drawing::rectangle_f structure.
      /// @param right The x-coordinate of the lower-right corner of this xtd::drawing::rectangle_f structure.
      /// @param bottom The y-coordinate of the lower-right corner of this xtd::drawing::rectangle_f structure.
      /// @return The new xtd::drawing::rectangle_f that this method creates.
      /// @remarks This method creates a xtd::drawing::rectangle_f with the specified upper-left and lower-right corners.
      static rectangle_f from_ltrb(float left, float top, float right, float bottom) noexcept;
      
      /// @brief Enlarges this xtd::drawing::rectangle_f by the specified amount.
      /// @param sz The amount to inflate this rectangle.
      /// @remarks This method enlarges this rectangle, not a copy of it. The rectangle is enlarged in both directions along an axis. For example, if a 50 by 50 rectangle is enlarged by 50 in the x-axis, the resultant rectangle will be 150 units long (the original 50, the 50 in the minus direction, and the 50 in the plus direction) maintaining the rectangle's geometric center.
      void inflate(const drawing::size_f& sz) noexcept;
      /// @brief Enlarges this xtd::drawing::rectangle_f by the specified amount.
      /// @param width The amount to inflate this xtd::drawing::rectangle_f horizontally.
      /// @param height The amount to inflate this xtd::drawing::rectangle_f verticaly.
      /// @remarks This method enlarges this rectangle, not a copy of it. The rectangle is enlarged in both directions along an axis. For example, if a 50 by 50 rectangle is enlarged by 50 in the x-axis, the resultant rectangle will be 150 units long (the original 50, the 50 in the minus direction, and the 50 in the plus direction) maintaining the rectangle's geometric center.
      /// @remarks If either x or y is negative, the xtd::drawing::rectangle_f structure is deflated in the corresponding direction.
      void inflate(float width, float height) noexcept;
      /// @brief Creates and returns an enlarged copy of the specified xtd::drawing::rectangle_f structure. The copy is enlarged by the specified amount. The original xtd::drawing::rectangle_f structure remains unmodified.
      /// @param rect The xtd::drawing::rectangle_f with which to start. This rectangle is not modified.
      /// @param x The amount to inflate the specified rectangle horizontally.
      /// @param y The amount to inflate the specified rectangle vertically.
      /// @return The enlarged xtd::drawing::rectangle_f.
      /// @remarks This method makes a copy of rect, enlarges the copy, and then returns the enlarged copy. The rectangle is enlarged in both directions along an axis. For example, if a 50 by 50 rectangle is enlarged by 50 in the x-axis, the resultant rectangle will be 150 units long (the original 50, the 50 in the minus direction, and the 50 in the plus direction) maintaining the rectangle's geometric center.
      static rectangle_f inflate(const rectangle_f& rect, const drawing::size_f& sz) noexcept;
      /// @brief Creates and returns an enlarged copy of the specified xtd::drawing::rectangle_f structure. The copy is enlarged by the specified amount. The original xtd::drawing::rectangle_f structure remains unmodified.
      /// @param rect The xtd::drawing::rectangle_f with which to start. This rectangle is not modified.
      /// @param sz The amount to inflate the specified rectangle.
      /// @return The enlarged xtd::drawing::rectangle_f.
      /// @remarks This method makes a copy of rect, enlarges the copy, and then returns the enlarged copy. The rectangle is enlarged in both directions along an axis. For example, if a 50 by 50 rectangle is enlarged by 50 in the x-axis, the resultant rectangle will be 150 units long (the original 50, the 50 in the minus direction, and the 50 in the plus direction) maintaining the rectangle's geometric center.
      static rectangle_f inflate(const rectangle_f& rect, float width, float height) noexcept;
      
      /// @brief Determines if this rectangle intersects with rect.
      /// @param rect The rectangle to test.
      /// @return This method returns true if there is any intersection, otherwise false.
      bool intersects_with(const rectangle_f& rect) const noexcept;
      
      /// @brief Returns a third xtd::drawing::rectangle_f structure that represents the intersection of two other xtd::drawing::rectangle_f structures. If there is no intersection, an empty xtd::drawing::rectangle_f is returned.
      /// @param a A rectangle to intersect.
      /// @param b A rectangle to intersect.
      /// @return A xtd::drawing::rectangle_f that represents the intersection of a and b.
      static rectangle_f make_intersect(const rectangle_f& a, const rectangle_f& b) noexcept;
      /// @brief Replaces this xtd::drawing::rectangle_f with the intersection of itself and the specified xtd::drawing::rectangle_f.
      /// @param rect The xtd::drawing::rectangle_f with which to intersect.
      void make_intersect(const rectangle_f& rect) noexcept;
      
      /// @brief Gets a xtd::drawing::rectangle_f structure that contains the union of two xtd::drawing::rectangle_f structures.
      /// @param a A rectangle to union.
      /// @param b A rectangle to union.
      /// @return A xtd::drawing::rectangle_f structure that bounds the union of the two xtd::drawing::rectangle_f structures.
      static rectangle_f make_union(const rectangle_f& a, const rectangle_f& b) noexcept;
      /// @brief Replaces this xtd::drawing::rectangle_f with the union of itself and the specified xtd::drawing::rectangle_f.
      /// @param rect The xtd::drawing::rectangle_f with which to union.
      void make_union(const rectangle_f& rect) noexcept;
      
      /// @brief Adjusts the location of this rectangle by the specified amount.
      /// @param pos Amount to offset the location.
      /// @remarks This method adjusts the location of the upper-left corner horizontally by the x-coordinate of the specified point, and vertically by the y-coordinate of the specified point.
      void offset(const point_f& pos) noexcept;
      /// @brief Adjusts the location of this rectangle by the specified amount.
      /// @param x The horizontal offset.
      /// @param y The vertical offset.
      void offset(float x, float y) noexcept;
      /// @brief Creates and returns an offsetted copy of the specified xtd::drawing::rectangle_f structure. The copy is offsetted by the specified amount. The original xtd::drawing::rectangle_f structure remains unmodified.
      /// @param rect The xtd::drawing::rectangle_f with which to start. This rectangle is not modified.
      /// @param pos The amount to offset the specified rectangle.
      /// @return The offsetted xtd::drawing::rectangle_f.
      /// @remarks This method makes a copy of rect, offsets the copy, and then returns the offsetted copy.
      static rectangle_f offset(const rectangle_f& rect, const point_f& pos) noexcept;
      /// @brief Creates and returns an offsetted copy of the specified xtd::drawing::rectangle_f structure. The copy is offsetted by the specified amount. The original xtd::drawing::rectangle_f structure remains unmodified.
      /// @param rect The xtd::drawing::rectangle_f with which to start. This rectangle is not modified.
      /// @param x The amount to offset the specified rectangle horizontally.
      /// @param y The amount to offset the specified rectangle vertically.
      /// @return The offsetted xtd::drawing::rectangle_f.
      /// @remarks This method makes a copy of rect, offsets the copy, and then returns the offsetted copy.
      static rectangle_f offset(const rectangle_f& rect, float x, float y) noexcept;
      
      /// @brief Converts the attributes of this xtd::drawing::rectangle_f to a human-readable string.
      /// @return A string that contains the position, width, and height of this Rectangle structure ¾ for example, {x=20, y=20, width=100, height=50}.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      float x_ = 0;
      float y_ = 0;
      float width_ = 0;
      float height_ = 0;
    };
  }
}

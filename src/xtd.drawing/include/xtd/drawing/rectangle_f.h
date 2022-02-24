/// @file
/// @brief Contains xtd::drawing::rectangle_f class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <ostream>
#include <string>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../drawing_export.h"
#include "point_f.h"
#include "size_f.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class rectangle;
    /// @endcond
    
    /// @brief Stores a set of four floating-points that represent the location and size of a rectangle.
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
    class drawing_export_ rectangle_f : public xtd::object {
    public:
      /// @name Fields
      
      /// @{
      static const rectangle_f empty;
      /// @}
      
      /// @name Constructors
      
      /// @{
      rectangle_f() noexcept = default;
      rectangle_f(float x, float y, float width, float height) noexcept;
      rectangle_f(const point_f& location, const size_f& size) noexcept;
      /// @}
      
      /// @cond
      rectangle_f(const rectangle_f&) noexcept = default;
      rectangle_f& operator=(const rectangle_f&) noexcept = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      float bottom() const noexcept;
      
      float height() const noexcept;
      void height(float height) noexcept;
      
      bool is_empty() const noexcept;
      
      float left() const noexcept;
      
      point_f location() const noexcept;
      void location(const point_f& location);
      
      float right() const noexcept;
      
      size_f size() const noexcept;
      void size(const size_f& size) noexcept;
      
      float top() const noexcept;
      
      float x() const noexcept;
      void x(float x) noexcept;
      
      float y() const noexcept;
      void y(float y) noexcept;
      
      float width() const noexcept;
      void width(float width) noexcept;
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
      /// @return A string that contains the position, width, and height of this Rectangle structure ¾ for example, {X=20, Y=20, Width=100, Height=50}.
      xtd::ustring to_string() const noexcept override;
      /// @}

      /// @name Operators
      
      /// @{
      /// @brief Tests whether two xtd::drawing::rectangle_f structures have equal location and size.
      /// @param value The xtd::drawing::rectangle_f structure that is to the right of the equality operator.
      /// @return This operator returns true if the two xtd::drawing::rectangle_f structures have equal xtd::drawing::rectangle_f::x, xtd::drawing::rectangle_f::y, xtd::drawing::rectangle_f::width, and xtd::drawing::rectangle_f::height properties.
      bool operator==(const rectangle_f& value) const noexcept;
      /// @brief Tests whether two xtd::drawing::rectangle_f structures differ in location or size.
      /// @param value The xtd::drawing::rectangle_f structure that is to the right of the inequality operator.
      /// @return This operator returns true if any of the xtd::drawing::rectangle_f::x, xtd::drawing::rectangle_f::y, xtd::drawing::rectangle_f::width or xtd::drawing::rectangle_f::height properties of the two xtd::drawing::rectangle_f structures are unequal; otherwise false.
      bool operator!=(const rectangle_f& value) const noexcept;
      /// @}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::rectangle_f& rectangle) noexcept {return os << rectangle.to_string();}
      /// @endcond
      
    private:
      float x_ = 0;
      float y_ = 0;
      float width_ = 0;
      float height_ = 0;
    };
  }
}

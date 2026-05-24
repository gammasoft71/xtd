/// @file
/// @brief Contains xtd::drawing::rectangle struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "point.hpp"
#include "size.hpp"
#include "rectangle_f.hpp"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/string>
#include <cstdint>
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Stores a set of four integers that represent the location and size of a rectangle.
    /// ```cpp
    /// class drawing_export_ rectangle : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::drawing::rectangle
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing coordinates
    /// @par Examples
    /// The following example draws a rectangle with its upper-left corner at (10, 10). The rectangle has a width of 100 and a height of 50. The second argument passed to the Pen constructor indicates that the pen width is 5 pixels.<br><br>
    /// When the rectangle is drawn, the pen is centered on the rectangle's boundary. Because the pen width is 5, the sides of the rectangle are drawn 5 pixels wide, such that 1 pixel is drawn on the boundary itself, 2 pixels are drawn on the inside, and 2 pixels are drawn on the outside. For more details on pen alignment, see How to: Set Pen Width and Alignment.<br><br>
    /// The following illustration shows the resulting rectangle. The dotted lines show where the rectangle would have been drawn if the pen width had been one pixel. The enlarged view of the upper-left corner of the rectangle shows that the thick black lines are centered on those dotted lines.<br><br>
    /// @image html rectangle_pens.png
    /// <br>The example is designed for use with xtd.forms, and it requires xtd::forms::paint_event_args e, which is a parameter of the xtd::forms::control::paint event handler.<br><br>
    /// ```cpp
    /// pen black_pen(color::from_argb(255, 0, 0, 0), 5);
    /// e.graphics().draw_rectangle(black_pen, 10, 10, 100, 50);
    /// ```
    /// @remarks A rectangle is defined by its xtd::drawing::rectangle::width, xtd::drawing::rectangle::height, and upper-left corner represented by the xtd::drawing::rectangle::location property.
    /// @remarks To draw rectangles, you need a xtd::drawing::graphics object and a xtd::drawing::pen object. The xtd::drawing::graphics object provides the xtd::drawing::graphics::draw_rectangle method, and the xtd::drawing::pen object stores features of the line, such as color and width. The units the rectangle is drawn in is determined by the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale properties of the graphics object used for drawing. The default unit is pixels.
    /// @remarks To draw a xtd::drawing::rectangle filled with color, you need a xtd::drawing::graphics object and an object derived from xtd::drawing::brush such as xtd::drawing::solid_brush or xtd::drawing::texture_brush or xtd::drawing::drawing_2d::conical_gradient_brush or xtd::drawing::drawing_2d::hatch_gradient_brush or xtd::drawing::drawing_2d::linear_gradient_brush or xtd::drawing::drawing_2d::radial_gradient_brush. The xtd::drawing::graphics object provides the xtd::drawing::graphics::fill_rectangle method and the xtd::drawing::brush object provides the color and fill information.
    /// @remarks For more advanced shapes, use a xtd::drawing::region object.
    struct drawing_export_ rectangle : xtd::object, xtd::iequatable<rectangle> {
      /// @name Public Fields
      
      /// @{
      /// @brief Represents a xtd::drawing::rectangle that has xtd::drawing::rectagle::x, xtd::drawing::rectangle::y, xtd::drawing::rectangle::width and xtd::drawing::rectangle::height values set to zero.
      static const rectangle empty;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::drawing::rectangle class
      /// @remarks xtd::drawing::rectagle::x, xtd::drawing::rectangle::y, xtd::drawing::rectangle::width and xtd::drawing::rectangle::height values are set to zero.
      rectangle() noexcept = default;
      /// @brief Initializes a new instance of the xtd::drawing::rectangle class with the specified location and size.
      /// @param x The x-coordinate of the upper-left corner of the rectangle.
      /// @param y The y-coordinate of the upper-left corner of the rectangle.
      /// @param width The width of the rectangle.
      /// @param height The height of the rectangle.
      rectangle(xtd::int32 x, xtd::int32 y, xtd::int32 width, xtd::int32 height) noexcept;
      /// @brief Initializes a new instance of the xtd::drawing::rectangle class with the specified location and size.
      /// @param location A xtd::drawing::point that represents the upper-left corner of the rectangular region.
      /// @param size A xtd::drawing::size that represents the width and height of the rectangular region.
      rectangle(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @}
      
      /// @cond
      operator xtd::drawing::rectangle_f() const noexcept;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets or sets the x-coordinate of the upper-left corner of this xtd::drawing::rectangle structure.
      /// @para mx The x-coordinate of the upper-left corner of this xtd::drawing::rectangle structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle::x property will also cause a change in the xtd::drawing::rectangle::right property of the xtd::drawing::rectangle.
      xtd::int32 x = 0;
      
      /// @brief Gets or sets the y-coordinate of the upper-left corner of this xtd::drawing::rectangle structure.
      /// @param y The y-coordinate of the upper-left corner of this xtd::drawing::rectangle structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle::y property will also cause a change in the xtd::drawing::rectangle::bottom property of the xtd::drawing::rectangle.
      xtd::int32 y = 0;
      
      /// @brief Gets or sets the width of this xtd::drawing::rectangle structure.
      /// @param width The width of this xtd::drawing::rectangle structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle::width property will also cause a change in the xtd::drawing::rectangle::bottom property of the xtd::drawing::rectangle. The units the rectangle is drawn in is determined by the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale properties of the graphics object used for drawing. The default unit is pixels.
      xtd::int32 width = 0;
      
      /// @brief Gets or sets the height of this xtd::drawing::rectangle structure.
      /// @param height The height of this Rectangle structure. The default is 0.
      /// @remarks Changing the xtd::drawing::rectangle::height property will also cause a change in the xtd::drawing::rectangle::bottom property of the xtd::drawing::rectangle. The units the rectangle is drawn in is determined by the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale properties of the graphics object used for drawing. The default unit is pixels.
      xtd::int32 height = 0;
      
      /// @brief Gets the y-coordinate that is the sum of the xtd::drawing::rectangle::y and xtd::drawing::rectangle::height property values of this xtd::drawing::rectangle structure.
      /// @return The y-coordinate that is the sum of xtd::drawing::rectangle::y and xtd::drawing::rectangle::height of this xtd::drawing::rectangle.
      /// @remarks The value of the xtd::drawing::rectangle::bottom property represents the y-coordinate of the first point at the bottom edge of the xtd::drawing::rectangle that is not contained in the xtd::drawing::rectangle.
      [[nodiscard]] auto bottom() const noexcept -> xtd::int32;
      
      /// @brief Gets the center property values of this xtd::drawing::rectangle structure.
      /// @return The center of this xtd::drawing::rectangle.
      [[nodiscard]] auto center() const noexcept -> xtd::drawing::point;
      
      /// @brief Tests whether all numeric properties of this xtd::drawing::rectangle have values of zero.
      /// @return This property returns `true` if the xtd::drawing::rectangle::width, xtd::drawing::rectangle::height, xtd::drawing::rectangle::x, and xtd::drawing::rectangle::y properties of this xtd::drawing::rectangle all have values of zero; otherwise, `false`.
      [[nodiscard]] bool is_empty() const noexcept;
      
      /// @brief Gets the x-coordinate of the left edge of this xtd::drawing::rectangle structure.
      /// @return The x-coordinate of the left edge of this xtd::drawing::rectangle structure.
      [[nodiscard]] auto left() const noexcept -> xtd::int32;
      
      /// @brief Gets the coordinates of the upper-left corner of this xtd::drawing::rectangle structure.
      /// @return A xtd::drawing::point that represents the upper-left corner of this xtd::drawing::rectangle structure.
      [[nodiscard]] auto location() const noexcept -> xtd::drawing::point;
      /// @brief Sets the coordinates of the upper-left corner of this xtd::drawing::rectangle structure.
      /// @param value A xtd::drawing::point that represents the upper-left corner of this xtd::drawing::rectangle structure.
      auto location(const xtd::drawing::point& value) noexcept -> void;
      
      /// @brief Gets the x-coordinate that is the sum of xtd::drawing::rectangle::x and xtd::drawing::rectangle::width property values of this xtd::drawing::rectangle structure.
      /// @return The x-coordinate that is the sum of xtd::drawing::rectangle::x and xtd::drawing::rectangle::width of this xtd::drawing::rectangle.
      [[nodiscard]] auto right() const noexcept -> xtd::int32;
      
      /// @brief Gets the size of this xtd::drawing::rectangle.
      /// @return A xtd::drawing::size that represents the width and height of this xtd::drawing::rectangle structure.
      auto size() const noexcept -> xtd::drawing::size;
      /// @brief Sets the size of this xtd::drawing::rectangle.
      /// @param value A xtd::drawing::size that represents the width and height of this xtd::drawing::rectangle structure.
      auto size(const xtd::drawing::size& value) noexcept -> void;
      
      /// @brief Gets the y-coordinate of the top edge of this xtd::drawing::rectangle structure.
      /// @return The y-coordinate of the top edge of this xtd::drawing::rectangle structure.
      [[nodiscard]] auto top() const noexcept -> xtd::int32;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Adds this xtd::drawing::rectangle by the specified amount.
      /// @param sz The amount to add this rectangle.
      /// @remarks This method adds this rectangle, not a copy of it.
      auto add(const xtd::drawing::size& sz) noexcept -> void;
      /// @brief Adds this xtd::drawing::rectangle by the specified amount.
      /// @param width The amount to add this xtd::drawing::rectangle horizontally.
      /// @param height The amount to add this xtd::drawing::rectangle verticaly.
      /// @remarks This method adds this rectangle, not a copy of it.
      auto add(xtd::int32 width, xtd::int32 height) noexcept -> void;
      
      /// @brief Determines if the specified point is contained within this xtd::drawing::rectangle structure.
      /// @param pt The xtd::drawing::point to test.
      /// @return This method returns `true` if the point represented by pt is contained within this xtd::drawing::rectangle structure; otherwise `false`.
      /// @remarks The containing rectangle must be normalized for this method to return accurate results.
      [[nodiscard]] auto contains(const xtd::drawing::point& pt) const noexcept -> bool;
      /// @brief Determines if the rectangular region represented by rect is entirely contained within this xtd::drawing::rectangle structure.
      /// @param rect The xtd::drawing::rectangle to test.
      /// @return This method returns `true` if the rectangular region represented by rect is entirely contained within this xtd::drawing::rectangle structure; otherwise `false`.
      /// @remarks The containing rectangle must be normalized for this method to return accurate results.
      [[nodiscard]] auto contains(const xtd::drawing::rectangle& rect) const noexcept -> bool;
      /// @brief Determines if the specified point is contained within this xtd::drawing::rectangle structure.
      /// @param x The x-coordinate of the point to test.
      /// @param y The y-coordinate of the point to test.
      /// @return This method returns `true` if the point defined by x and y is contained within this xtd::drawing::rectangle structure; otherwise `false`.
      /// @remarks The containing rectangle must be normalized for this method to return accurate results.
      [[nodiscard]] auto contains(xtd::int32 x, xtd::int32 y) const noexcept -> bool;
      
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const rectangle& other) const noexcept -> bool override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
      
      /// @brief Enlarges this xtd::drawing::rectangle by the specified amount.
      /// @param sz The amount to inflate this rectangle.
      /// @remarks This method enlarges this rectangle, not a copy of it. The rectangle is enlarged in both directions along an axis. For example, if a 50 by 50 rectangle is enlarged by 50 in the x-axis, the resultant rectangle will be 150 units long (the original 50, the 50 in the minus direction, and the 50 in the plus direction) maintaining the rectangle's geometric center.
      auto inflate(const xtd::drawing::size& sz) noexcept -> void;
      /// @brief Enlarges this xtd::drawing::rectangle by the specified amount.
      /// @param width The amount to inflate this xtd::drawing::rectangle horizontally.
      /// @param height The amount to inflate this xtd::drawing::rectangle verticaly.
      /// @remarks This method enlarges this rectangle, not a copy of it. The rectangle is enlarged in both directions along an axis. For example, if a 50 by 50 rectangle is enlarged by 50 in the x-axis, the resultant rectangle will be 150 units long (the original 50, the 50 in the minus direction, and the 50 in the plus direction) maintaining the rectangle's geometric center.
      /// @remarks If either x or y is negative, the xtd::drawing::rectangle structure is deflated in the corresponding direction.
      auto inflate(xtd::int32 width, xtd::int32 height) noexcept -> void;
      
      /// @brief Determines if this rectangle intersects with rect.
      /// @param rect The rectangle to test.
      /// @return This method returns `true` if there is any intersection, otherwise `false`.
      [[nodiscard]] auto intersects_with(const rectangle& rect) const noexcept -> bool;
      
      /// @brief Replaces this xtd::drawing::rectangle with the intersection of itself and the specified xtd::drawing::rectangle.
      /// @param rect The xtd::drawing::rectangle with which to intersect.
      auto make_intersect(const rectangle& rect) noexcept -> void;
      
      /// @brief Replaces this xtd::drawing::rectangle with the union of itself and the specified xtd::drawing::rectangle.
      /// @param rect The xtd::drawing::rectangle with which to union.
      auto make_union(const rectangle& rect) noexcept -> void;
      
      /// @brief Adjusts the location of this rectangle by the specified amount.
      /// @param pos Amount to offset the location.
      /// @remarks This method adjusts the location of the upper-left corner horizontally by the x-coordinate of the specified point, and vertically by the y-coordinate of the specified point.
      auto offset(const xtd::drawing::point& pos) noexcept -> void;
      /// @brief Adjusts the location of this rectangle by the specified amount.
      /// @param dx The horizontal offset.
      /// @param dy The vertical offset.
      auto offset(xtd::int32 dx, xtd::int32 dy) noexcept -> void;
      
      /// @brief Converts the attributes of this xtd::drawing::rectangle to a human-readable string.
      /// @return A string that contains the position, width, and height of this Rectangle structure ¾ for example, {x=20, y=20, width=100, height=50}.
      [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates and returns an added copy of the specified xtd::drawing::rectangle structure. The copy is added by the specified amount. The original xtd::drawing::rectangle structure remains unmodified.
      /// @param rect The xtd::drawing::rectangle with which to start. This rectangle is not modified.
      /// @param x The amount to add the specified rectangle horizontally.
      /// @param y The amount to add the specified rectangle vertically.
      /// @return The added xtd::drawing::rectangle.
      /// @remarks This method makes a copy of rect, adds the copy, and then returns the added copy.
      [[nodiscard]] static auto add(const rectangle& rect, xtd::int32 x, xtd::int32 y) noexcept -> rectangle;
      /// @brief Creates and returns an added copy of the specified xtd::drawing::rectangle structure. The copy is added by the specified amount. The original xtd::drawing::rectangle structure remains unmodified.
      /// @param rect The xtd::drawing::rectangle with which to start. This rectangle is not modified.
      /// @param sz The amount to add the specified rectangle.
      /// @return The added xtd::drawing::rectangle.
      /// @remarks This method makes a copy of rect, adds the copy, and then returns the added copy.
      [[nodiscard]] static auto add(const rectangle& rect, const xtd::drawing::size& sz) noexcept -> rectangle;
      
      /// @brief Converts the specified xtd::drawing::rectangle_f structure to a xtd::drawing::rectangle structure by rounding the xtd::drawing::rectangle_f values to the next higher integer values.
      /// @param rect The xtd::drawing::rectangle_f structure to be converted.
      /// @return Returns a xtd::drawing::rectangle.
      [[nodiscard]] static auto ceiling(const xtd::drawing::rectangle_f& rect) noexcept -> rectangle;
      
      /// @brief Creates a xtd::drawing::rectangle structure with the specified edge locations.
      /// @param left The x-coordinate of the upper-left corner of this xtd::drawing::rectangle structure.
      /// @param top The y-coordinate of the upper-left corner of this xtd::drawing::rectangle structure.
      /// @param right The x-coordinate of the lower-right corner of this xtd::drawing::rectangle structure.
      /// @param bottom The y-coordinate of the lower-right corner of this xtd::drawing::rectangle structure.
      /// @return The new xtd::drawing::rectangle that this method creates.
      /// @remarks This method creates a xtd::drawing::rectangle with the specified upper-left and lower-right corners.
      [[nodiscard]] static auto from_ltrb(xtd::int32 left, xtd::int32 top, xtd::int32 right, xtd::int32 bottom) noexcept -> rectangle;
      
      /// @brief Creates and returns an enlarged copy of the specified xtd::drawing::rectangle structure. The copy is enlarged by the specified amount. The original xtd::drawing::rectangle structure remains unmodified.
      /// @param rect The xtd::drawing::rectangle with which to start. This rectangle is not modified.
      /// @param x The amount to inflate the specified rectangle horizontally.
      /// @param y The amount to inflate the specified rectangle vertically.
      /// @return The enlarged xtd::drawing::rectangle.
      /// @remarks This method makes a copy of rect, enlarges the copy, and then returns the enlarged copy. The rectangle is enlarged in both directions along an axis. For example, if a 50 by 50 rectangle is enlarged by 50 in the x-axis, the resultant rectangle will be 150 units long (the original 50, the 50 in the minus direction, and the 50 in the plus direction) maintaining the rectangle's geometric center.
      [[nodiscard]] static auto inflate(const rectangle& rect, xtd::int32 x, xtd::int32 y) noexcept -> rectangle;
      /// @brief Creates and returns an enlarged copy of the specified xtd::drawing::rectangle structure. The copy is enlarged by the specified amount. The original xtd::drawing::rectangle structure remains unmodified.
      /// @param rect The xtd::drawing::rectangle with which to start. This rectangle is not modified.
      /// @param sz The amount to inflate the specified rectangle.
      /// @return The enlarged xtd::drawing::rectangle.
      /// @remarks This method makes a copy of rect, enlarges the copy, and then returns the enlarged copy. The rectangle is enlarged in both directions along an axis. For example, if a 50 by 50 rectangle is enlarged by 50 in the x-axis, the resultant rectangle will be 150 units long (the original 50, the 50 in the minus direction, and the 50 in the plus direction) maintaining the rectangle's geometric center.
      [[nodiscard]] static auto inflate(const rectangle& rect, const xtd::drawing::size& sz) noexcept -> rectangle;
      
      /// @brief Returns a third xtd::drawing::rectangle structure that represents the intersection of two other xtd::drawing::rectangle structures. If there is no intersection, an empty xtd::drawing::rectangle is returned.
      /// @param a A rectangle to intersect.
      /// @param b A rectangle to intersect.
      /// @return A xtd::drawing::rectangle that represents the intersection of a and b.
      [[nodiscard]] static auto make_intersect(const rectangle& a, const rectangle& b) noexcept -> rectangle;
      
      /// @brief Gets a xtd::drawing::rectangle structure that contains the union of two xtd::drawing::rectangle structures.
      /// @param a A rectangle to union.
      /// @param b A rectangle to union.
      /// @return A xtd::drawing::rectangle structure that bounds the union of the two xtd::drawing::rectangle structures.
      [[nodiscard]] static auto make_union(const rectangle& a, const rectangle& b) noexcept -> rectangle;
      
      /// @brief Creates and returns an offsetted copy of the specified xtd::drawing::rectangle structure. The copy is offsetted by the specified amount. The original xtd::drawing::rectangle structure remains unmodified.
      /// @param rect The xtd::drawing::rectangle with which to start. This rectangle is not modified.
      /// @param pos The amount to offset the specified rectangle.
      /// @return The offsetted xtd::drawing::rectangle.
      /// @remarks This method makes a copy of rect, offsets the copy, and then returns the offsetted copy.
      [[nodiscard]] static auto offset(const rectangle& rect, const xtd::drawing::point& pos) noexcept -> rectangle;
      /// @brief Creates and returns an offsetted copy of the specified xtd::drawing::rectangle structure. The copy is offsetted by the specified amount. The original xtd::drawing::rectangle structure remains unmodified.
      /// @param rect The xtd::drawing::rectangle with which to start. This rectangle is not modified.
      /// @param x The amount to offset the specified rectangle horizontally.
      /// @param y The amount to offset the specified rectangle vertically.
      /// @return The offsetted xtd::drawing::rectangle.
      /// @remarks This method makes a copy of rect, offsets the copy, and then returns the offsetted copy.
      [[nodiscard]] static auto offset(const rectangle& rect, xtd::int32 x, xtd::int32 y) noexcept -> rectangle;
      
      /// @brief Converts the specified xtd::drawing::rectangle_f to a xtd::drawing::rectangle by rounding the xtd::drawing::rectangle_f values to the nearest integer values.
      /// @param rect The xtd::drawing::rectangle_f to be converted.
      /// @return The rounded integer value of the xtd::drawing::rectangle.
      [[nodiscard]] static auto round(const rectangle_f& rect) noexcept -> rectangle;
      
      /// @brief Converts the specified xtd::drawing::rectangle_f to a xtd::drawing::rectangle by truncating the xtd::drawing::rectangle_f values.
      /// @param rect The xtd::drawing::rectangle_f to be converted.
      /// @return The truncated value of the xtd::drawing::rectangle.
      [[nodiscard]] static auto truncate(const xtd::drawing::rectangle_f& rect) noexcept -> rectangle;
      /// @}
    };
  }
}

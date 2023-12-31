/// @file
/// @brief Contains xtd::drawing::point class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "point_f.h"
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
    class size;
    /// @endcond
    
    /// @brief Represents an ordered pair of integer x- and y-coordinates that defines a point in a two-dimensional plane.
    /// @code
    /// class drawing_export_ point : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::point
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks To convert a point to a point_f, use Implicit cast operator.
    /// @par Examples
    ///
    /// @code
    /// void create_points_and_sizes(paint_event_args& e) {
    ///   // Create the starting point.
    ///   point start_point = subtract_button.size();
    ///
    ///   // Use the addition operator to get the end point.
    ///   point end_point = start_point + size(140, 150);
    ///
    ///   // Draw a line between the points.
    ///   e.graphics().draw_line(system_pens::highlight, start_point, end_point);
    ///
    ///   // Convert the starting point to a size and compare it to the subtractButton size.
    ///   size button_size(start_point);
    ///   if (button_size == subtract_button.size()) {
    ///     // If the sizes are equal, tell the user.
    ///     e.graphics().draw_string("The sizes are equal.", font(font, font_style.italic), brushes::indigo, 10.0F, 65.0F);
    ///   }
    /// }
    /// @endcode
    class drawing_export_ point : public xtd::object, public xtd::iequatable<point> {
    public:
      /// @name Fields
      
      /// @{
      /// @brief Represents a xtd::drawing::point that has xtd::drawing::point::x and xtd::drawing::point::y values set to zero.
      static const point empty;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::drawing::point class
      /// @remarks xtd::drawing::point::x and xtd::drawing::point::y values are set to zero.
      point() noexcept = default;
      
      /// @brief Initializes a new instance of the xtd::drawing::point class using coordinates specified by an integer value.
      /// @param dx A 32-bit integer that specifies the coordinates for the new xtd::drawing::point.
      /// @remarks The low-order 16 bits of the dw parameter specify the horizontal x-coordinate and the higher 16 bits specify the vertical y-coordinate for the new point.
      /// @par Examples
      /// The following code example demonstrates how to use the point and size. size constructors and the xtd::drawing::content_alignment enumeration. To run this example, paste this code into a Windows Form (xtd::forms) that contains a label named label1, and call the initialize_label1 method in the form's constructor.
      /// @code
      /// void initialize_label1() {
      ///   // Set a border.
      ///   label1.border_style = border_style::fixed_single;
      ///
      ///   // Set the size, constructing a size from two integers.
      ///   label1.size(drawing::size(100, 50));
      ///
      ///   // Set the location, constructing a point from a 32-bit integer
      ///   // (using hexadecimal).
      ///   label1.location(point(0x280028));
      ///
      ///   // Set and align the text on the lower-right side of the label.
      ///   label1.text_align = content_alignment::bottom_right;
      ///   label1.text = "Bottom Right Alignment";
      /// }
      /// @endcode
      explicit point(int32 dw) noexcept;
      
      /// @brief Initializes a new instance of the xtd::drawing::point class with the specified coordinates.
      /// @param x The horizontal position of the point.
      /// @param y The vertical position of the point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// void button1_click(object& sender, const event_args& e) {
      ///   // Construct a new point with integers.
      ///   point point1(100, 100);
      ///
      ///   // Create a Graphics object.
      ///   graphics form_graphics = create_graphics();
      ///
      ///   // Construct another point, this time using a xtd::drawing::size.
      ///   point point2(size(100, 100));
      ///
      ///   // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///   if (point1 == point2) {
      ///     form_graphics.draw_string(ustring::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), font(), brushes::black, point_f(10, 70));
      ///   }
      /// }
      /// @endcode
      point(int32 x, int32 y) noexcept;
      
      /// @brief Initializes a new instance of the xtd::drawing::point class from a xtd::drawing::size.
      /// @param sz A size that specifies the coordinates for the new point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// void button1_click(object& sender, const event_args& e) {
      ///   // Construct a new point with integers.
      ///   point point1(100, 100);
      ///
      ///   // Create a Graphics object.
      ///   graphics form_graphics = create_graphics();
      ///
      ///   // Construct another point, this time using a xtd::drawing::size.
      ///   point point2(size(100, 100));
      ///
      ///   // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///   if (point1 == point2) {
      ///     form_graphics.draw_string(ustring::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), font(), brushes::black, point_f(10, 70));
      ///   }
      /// }
      /// @endcode
      explicit point(const size& sz) noexcept;
      /// @}
      
      /// @cond
      point(const point&) noexcept = default;
      point& operator =(const point&) noexcept = default;
      operator point_f() const noexcept;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a value indicating whether this xtd::drawing::point is empty.
      /// @return true if both xtd::drawing::point::x and xtd::drawing::point::y are 0; otherwise, false.
      bool is_empty() const noexcept;
      
      /// @brief Gets the x-coordinate of this xtd::drawing::point.
      /// @return The x-coordinate of this xtd::drawing::point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// void button1_click(object& sender, const event_args& e) {
      ///   // Construct a new point with integers.
      ///   point point1(100, 100);
      ///
      ///   // Create a Graphics object.
      ///   graphics form_graphics = create_graphics();
      ///
      ///   // Construct another point, this time using a xtd::drawing::size.
      ///   point point2(size(100, 100));
      ///
      ///   // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///   if (point1 == point2) {
      ///     form_graphics.draw_string(ustring::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), font(), brushes::black, point_f(10, 70));
      ///   }
      /// }
      /// @endcode
      int32 x() const noexcept;
      
      /// @brief Sets the x-coordinate of this xtd::drawing::point.
      /// @param x The x-coordinate of this xtd::drawing::point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// void button1_click(object& sender, const event_args& e) {
      ///   // Construct a new point with integers.
      ///   point point1(100, 100);
      ///
      ///   // Create a Graphics object.
      ///   graphics form_graphics = create_graphics();
      ///
      ///   // Construct another point, this time using a xtd::drawing::size.
      ///   point point2(size(100, 100));
      ///
      ///   // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///   if (point1 == point2) {
      ///     form_graphics.draw_string(ustring::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), font(), brushes::black, point_f(10, 70));
      ///   }
      /// }
      /// @endcode
      void x(int32 x) noexcept;
      
      /// @brief Gets the y-coordinate of this xtd::drawing::point.
      /// @return The y-coordinate of this xtd::drawing::point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// void button1_Click(object& sender, const event_args& e) {
      ///   // Construct a new point with integers.
      ///   point point1(100, 100);
      ///
      ///   // Create a Graphics object.
      ///   graphics form_graphics = create_graphics();
      ///
      ///   // Construct another point, this time using a xtd::drawing::size.
      ///   point point2(size(100, 100));
      ///
      ///   // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///   if (point1 == point2) {
      ///     form_graphics.draw_string(ustring::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), font(), brushes::black, point_f(10, 70));
      ///   }
      /// }
      /// @endcode
      int32 y() const noexcept;
      
      /// @brief Sets the y-coordinate of this xtd::drawing::point.
      /// @param y The x-coordinate of this xtd::drawing::point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// void button1_Click(object& sender, const event_args& e) {
      ///   // Construct a new point with integers.
      ///   point point1(100, 100);
      ///
      ///   // Create a Graphics object.
      ///   graphics form_graphics = create_graphics();
      ///
      ///   // Construct another point, this time using a xtd::drawing::size.
      ///   point point2(size(100, 100));
      ///
      ///   // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///   if (point1 == point2) {
      ///     form_graphics.draw_string(ustring::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), font(), brushes::black, point_f(10, 70));
      ///   }
      /// }
      /// @endcode
      void y(int32 y) noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Adds the specified xtd::drawing::size to the specified xtd::drawing::point.
      /// @param pt The xtd::drawing::point to add.
      /// @param sz The xtd::drawing::size to add.
      /// @return The xtd::drawing::point that is the result of the addition operation.
      /// @remarks The xtd::drawing::point::add adds the xtd::drawing::size::width and xtd::drawing::size::height of the specified size to the xtd::drawing::point::x and xtd::drawing::point::y values of the specified xtd::drawing::point.
      /// @par Examples
      /// The following example shows how to use the add method. To run this example, paste it into a Windows Form (xtd::forms. Handle the form's xtd::forms::control::paint event and call the add_point method from the paint event-handling method, passing e as paint_event_args.
      /// @code
      /// void add_point(paint_event_args& e) {
      ///   point point1(10, 10);
      ///   point point2 = point::add(point1, drawing::size(250,0));
      ///   e.graphics().draw_line(pens::red, point1, point2);
      /// }
      /// @endcode
      static point add(const point& pt, const size& sz) noexcept;
      /// @brief Adds the specified xtd::drawing::point to the specified xtd::drawing::point.
      /// @param pt1 The xtd::drawing::point to add.
      /// @param pt2 The xtd::drawing::point to add.
      /// @return The xtd::drawing::point that is the result of the addition operation.
      static point add(const point& pt1, const point& pt2) noexcept;
      
      /// @brief Converts the specified xtd::drawing::point_f to a point by rounding the values of the xtd::drawing::point_f to the next higher integer values.
      /// @param value The xtd::drawing::point_f to convert.
      /// @return The xtd::drawing::point this method converts to.
      static point ceiling(const point_f& value) noexcept;
      
      bool equals(const point& value) const noexcept override;
      
      /// @brief Translates this xtd::drawing::point by the specified amount.
      /// @param dx The amount to offset the x-coordinate.
      /// @param dy The amount to offset the y-coordinate.
      void offset(int32 dx, int32 dy) noexcept;
      
      /// @brief Translates this xtd::drawing::point by the specified xtd::drawing::point.
      /// @param p The xtd::drawing::point used offset this xtd::drawing::point.
      /// @remarks This method adjusts the xtd::drawing::point::x and xtd::drawing::point::y values of this xtd::drawing::point to the sum of the xtd::drawing::point::x and xtd::drawing::point::y values of this xtd::drawing::point and p.
      /// @par Examples
      /// The following example shows how to use the Offset method. To run this example, paste it into a Windows Form. Handle the form's xtd::forms::control::paint event and call the Offsetpoint method from the xtd::forms::control::paint event-handling method, passing e as xtd::forms::paint_event_args.
      /// @code
      /// void offset_point(paint_event_args& e) {
      ///   point point1(10, 10);
      ///   point1.offset(50, 0);
      ///   point point2(250, 10);
      ///   e.graphics().draw_line(pens::red, point1, point2);
      /// }
      /// @endcode
      void offset(const point& p) noexcept;
      
      /// @brief Converts the specified xtd::drawing::point_f to a point object by rounding the xtd::drawing::point_f values to the nearest integer.
      /// @param value The xtd::drawing::point_f to convert.
      /// @return The xtd::drawing::point this method converts to.
      static point round(const point_f& value) noexcept;
      
      /// @brief Returns the result of subtracting specified xtd::drawing::size from the specified xtd::drawing::point.
      /// @param pt The xtd::drawing::point to be subtracted from.
      /// @param sz The xtd::drawing::size to subtract from the xtd::drawing::point.
      /// @return The xtd::drawing::point that is the result of the subtraction operation.
      /// @remarks The xtd::drawing::point::subtract subtracts the xtd::drawing::size::width and xtd::drawing::size::height of the specified xtd::drawing::size from the xtd::drawing::point::x and xtd::drawing::point::y values of the specified xtd::drawing::point.
      static point subtract(const point& pt, const size& sz) noexcept;
      /// @brief Returns the result of subtracting specified xtd::drawing::point from the specified xtd::drawing::point.
      /// @param pt1 The xtd::drawing::point to be subtracted from.
      /// @param pt2 The xtd::drawing::point to subtract from the xtd::drawing::point.
      /// @return The xtd::drawing::point that is the result of the subtraction operation.
      static point subtract(const point& pt1, const point& pt2) noexcept;
      
      /// @brief Converts this point to a human-readable string.
      /// @return An xtd::ustring that represents this xtd::drawing::point.
      xtd::ustring to_string() const noexcept override;
      
      /// @brief Converts the specified xtd::drawing::point_f to a point by truncating the values of the xtd::drawing::point_f.
      /// @param value The xtd::drawing::point_f to convert.
      /// @return The xtd::drawing::point this method converts to.
      static point truncate(const point_f& value) noexcept;
      /// @}
      
      /// @name Operators
      
      /// @{
      /// @brief Translates a xtd::drawing::point by a given xtd::drawing::size.
      /// @param sz A xtd::drawing::size that specifies the pair of numbers to add to the coordinates of this xtd::drawing::point.
      /// @return The translated xtd::drawing::point.
      point operator +(const size& sz) const noexcept;
      /// @brief Translates a xtd::drawing::point by a given xtd::drawing::point.
      /// @param pt A xtd::drawing::point that specifies the pair of numbers to add to the coordinates of this xtd::drawing::point.
      /// @return The translated xtd::drawing::point.
      point operator +(const point& pt) const noexcept;
      
      /// @brief Translates a xtd::drawing::point by a given xtd::drawing::size.
      /// @param sz A xtd::drawing::size that specifies the pair of numbers to add to the coordinates of this xtd::drawing::point.
      /// @return The translated xtd::drawing::point.
      point& operator +=(const size& sz) noexcept;
      /// @brief Translates a xtd::drawing::point by a given xtd::drawing::point.
      /// @param pt A xtd::drawing::point that specifies the pair of numbers to add to the coordinates of this xtd::drawing::point.
      /// @return The translated xtd::drawing::point.
      point& operator +=(const point& pt) noexcept;
      
      /// @brief Translates a xtd::drawing::point by the negative of a given xtd::drawing::size.
      /// @param sz A xtd::drawing::size that specifies the pair of numbers to subtract from the coordinates of this xtd::drawing::point.
      /// @return A xtd::drawing::point structure that is translated by the negative of a given xtd::drawing::size structure.
      point operator -(const size& sz) const noexcept;
      /// @brief Translates a xtd::drawing::point by the negative of a given xtd::drawing::point.
      /// @param pt A xtd::drawing::point that specifies the pair of numbers to subtract from the coordinates of this xtd::drawing::point.
      /// @return A xtd::drawing::point structure that is translated by the negative of a given xtd::drawing::size structure.
      point operator -(const point& pt) const noexcept;
      
      /// @brief Translates a xtd::drawing::point by the negative of a given xtd::drawing::size.
      /// @param sz A xtd::drawing::size that specifies the pair of numbers to subtract from the coordinates of this xtd::drawing::point.
      /// @return The translated xtd::drawing::point.
      point& operator -=(const size& sz) noexcept;
      /// @brief Translates a xtd::drawing::point by the negative of a given xtd::drawing::point.
      /// @param pt A xtd::drawing::point that specifies the pair of numbers to subtract from the coordinates of this xtd::drawing::point.
      /// @return The translated xtd::drawing::point.
      point& operator -=(const point& pt) noexcept;
      /// @}
      
    private:
      int32 x_ = 0;
      int32 y_ = 0;
    };
  }
  
  template<>
  inline drawing::point parse<drawing::point>(const std::string& str) {
    auto values = xtd::ustring(str).replace("}", "").replace(" y=", "").replace("{x=", "").split({','});
    return {xtd::parse<int32>(values[0]), xtd::parse<int32>(values[1])};
  }
}

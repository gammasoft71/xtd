/// @file
/// @brief Contains xtd::drawing::point class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <ostream>
#include <xtd/object.h>
#include <xtd/strings.h>
#include "../drawing_export.h"
#include "point_f.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class size;
    /// @endcond

    /// @brief Represents an ordered pair of integer x- and y-coordinates that defines a point in a two-dimensional plane.
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
    class drawing_export_ point : public object {
    public:
      /// @brief Represents a point that has x and y values set to zero.
      static const point empty;
      
      /// @brief Initializes a new instance of the point class
      /// @remarks x and y values are set to zero.
      point() = default;
      
      /// @brief nitializes a new instance of the point class using coordinates specified by an integer value.
      /// @param dx A 32-bit integer that specifies the coordinates for the new point.
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
      explicit point(int32_t dw) : x_(dw & 0x0000FFFF), y_((dw & 0xFFFF0000)>>16) {}

      /// @brief Initializes a new instance of the point class with the specified coordinates.
      /// @param x The horizontal position of the point.
      /// @param y The vertical position of the point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// void button1_Click(const control& sender, const event_args& e) {
      ///   // Construct a new point with integers.
      ///   point point1(100, 100);
      ///
      ///   // Create a Graphics object.
      ///   graphics form_graphics = create_graphics();
      ///
      ///   // Construct another point, this time using a Size.
      ///   point point2(size(100, 100));
      ///
      ///   // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///   if (point1 == point2) {
      ///     form_graphics.draw_string(strings::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), font(), brushes::black, point_f(10, 70));
      ///   }
      /// }
      /// @endcode
      point(int32_t x, int32_t y) : x_(x), y_(y) {}
      
      /// @brief Initializes a new instance of the point class from a size.
      /// @param sz A size that specifies the coordinates for the new point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// void button1_Click(const control& sender, const event_args& e) {
      ///   // Construct a new point with integers.
      ///   point point1(100, 100);
      ///
      ///   // Create a Graphics object.
      ///   graphics form_graphics = create_graphics();
      ///
      ///   // Construct another point, this time using a Size.
      ///   point point2(size(100, 100));
      ///
      ///   // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///   if (point1 == point2) {
      ///     form_graphics.draw_string(strings::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), font(), brushes::black, point_f(10, 70));
      ///   }
      /// }
      /// @endcode
      point (const size& sz);

      /// @cond
      point(const point&) = default;
      point& operator=(const point&) = default;
      operator point_f() const {return point_f(static_cast<float>(x_), static_cast<float>(y_));}
      /// @endcond
      
      /// @brief Gets a value indicating whether this point is empty.
      /// @return true if both X and Y are 0; otherwise, false.
      bool is_empty() const {return *this == point::empty;}

      /// @brief Gets the x-coordinate of this point.
      /// @return The x-coordinate of this point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// void button1_Click(const control& sender, const event_args& e) {
      ///   // Construct a new point with integers.
      ///   point point1(100, 100);
      ///
      ///   // Create a Graphics object.
      ///   graphics form_graphics = create_graphics();
      ///
      ///   // Construct another point, this time using a Size.
      ///   point point2(size(100, 100));
      ///
      ///   // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///   if (point1 == point2) {
      ///     form_graphics.draw_string(strings::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), font(), brushes::black, point_f(10, 70));
      ///   }
      /// }
      /// @endcode
      int32_t x() const {return x_;}
      
      /// @brief Sets the x-coordinate of this point.
      /// @param x The x-coordinate of this point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// void button1_Click(const control& sender, const event_args& e) {
      ///   // Construct a new point with integers.
      ///   point point1(100, 100);
      ///
      ///   // Create a Graphics object.
      ///   graphics form_graphics = create_graphics();
      ///
      ///   // Construct another point, this time using a Size.
      ///   point point2(size(100, 100));
      ///
      ///   // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///   if (point1 == point2) {
      ///     form_graphics.draw_string(strings::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), font(), brushes::black, point_f(10, 70));
      ///   }
      /// }
      /// @endcode
      void x(int32_t x) {x_ = x;}
      
      /// @brief Gets the y-coordinate of this point.
      /// @return The y-coordinate of this point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// void button1_Click(const control& sender, const event_args& e) {
      ///   // Construct a new point with integers.
      ///   point point1(100, 100);
      ///
      ///   // Create a Graphics object.
      ///   graphics form_graphics = create_graphics();
      ///
      ///   // Construct another point, this time using a Size.
      ///   point point2(size(100, 100));
      ///
      ///   // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///   if (point1 == point2) {
      ///     form_graphics.draw_string(strings::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), font(), brushes::black, point_f(10, 70));
      ///   }
      /// }
      /// @endcode
      int32_t y() const {return y_;}
      
      /// @brief Sets the y-coordinate of this point.
      /// @param y The x-coordinate of this point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// void button1_Click(const control& sender, const event_args& e) {
      ///   // Construct a new point with integers.
      ///   point point1(100, 100);
      ///
      ///   // Create a Graphics object.
      ///   graphics form_graphics = create_graphics();
      ///
      ///   // Construct another point, this time using a Size.
      ///   point point2(size(100, 100));
      ///
      ///   // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///   if (point1 == point2) {
      ///     form_graphics.draw_string(strings::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), font(), brushes::black, point_f(10, 70));
      ///   }
      /// }
      /// @endcode
      void y(int32_t y) {y_ = y;}

      /// @brief Adds the specified size to the specified point.
      /// @param pt The point to add.
      /// @param sz The size to add.
      /// @return The point that is the result of the addition operation.
      /// @remarks The add adds the width and height of the specified size to the y and y values of the specified point.
      /// @par Examples
      /// The following example shows how to use the add method. To run this example, paste it into a Windows Form (xtd::formsà. Handle the form's paint event and call the add_point method from the paint event-handling method, passing e as paint_event_args.
      /// @code
      /// void add_point(paint_event_args& e) {
      ///   point point1(10, 10);
      ///   point point2 = point::add(point1, drawing::size(250,0));
      ///   e.graphics().draw_line(pens::red, point1, point2);
      /// }
      /// @endcode
      static point add(const point& pt, const size& sz);
      /// @cond
      static point add(const point& pt1, const point& pt2);
      /// @endcond

      /// @brief Converts the specified point_f to a point by rounding the values of the point_f to the next higher integer values.
      /// @param value The point_f to convert.
      /// @return The point this method converts to.
      static point ceiling(const point_f& value);
      
      /// @brief Translates this point by the specified amount.
      /// @param dx The amount to offset the x-coordinate.
      /// @param dy The amount to offset the y-coordinate.
      void offset(int dx, int dy) {
        x_ += dx;
        y_ += dy;
      }
      
      /// @brief Translates this point by the specified point.
      /// @param p The point used offset this point.
      /// @remarks This method adjusts the x and y values of this point to the sum of the x and y values of this point and p.
      /// @par Examples
      /// The following example shows how to use the Offset method. To run this example, paste it into a Windows Form. Handle the form's Paint event and call the Offsetpoint method from the Paint event-handling method, passing e as PaintEventArgs.
      /// @code
      /// void offset_point(paint_event_args& e) {
      ///   point point1(10, 10);
      ///   point1.offset(50, 0);
      ///   point point2(250, 10);
      ///   e.eraphics().draw_line(pens::red, point1, point2);
      /// }
      /// @endcode
      void offset(const point& p) {offset(p.x_, p.y_);}

      /// @brief Converts the specified point_f to a point object by rounding the point_f values to the nearest integer.
      /// @param value The point_f to convert.
      /// @return The point this method converts to.
      static point round(const point_f& value);

      /// @brief Returns the result of subtracting specified Size from the specified point.
      /// @param pt The point to be subtracted from.
      /// @param sz The size to subtract from the point.
      /// @return The point that is the result of the subtraction operation.
      /// @remarks The subtract subtracts the width and height of the specified size from the x and y values of the specified point.
      static point subtract(const point& pt, const size& sz);
      /// @cond
      static point subtract(const point& pt1, const point& pt2);
      /// @endcond

      /// @brief Converts this point to a human-readable string.
      /// @return A string that represents this point.
      std::string to_string() const noexcept override {return  strings::format("{{x={}, y={}}}", x_, y_);}

      /// @brief Converts the specified point_f to a point by truncating the values of the point_f.
      /// @param value The point_f to convert.
      /// @return The point this method converts to.
      static point truncate(const point_f& value);

      /// @cond
      bool operator==(const point& value) const {return x_ == value.x_ && y_ == value.y_;}
      bool operator!=(const point& value) const {return !operator==(value);}

      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::point& point) noexcept {
        return os << point.to_string();
      }
      
      point operator+(const size& sz) const;
      point operator+(const point& pt) const;
      point& operator+=(const size& sz);
      point& operator+=(const point& pt);
      point operator-(const size& sz) const;
      point operator-(const point& pt) const;
      point& operator-=(const size& sz);
      point& operator-=(const point& pt);
      /// @endcond
      
    private:
      int32_t x_ = 0;
      int32_t y_ = 0;
    };
  }

  template<>
  inline drawing::point parse<drawing::point>(const std::string& str) {
    auto values = xtd::strings::split(xtd::strings::replace(xtd::strings::replace(xtd::strings::replace(str, "}", ""), " y=", ""), "{x=", ""), {','});
    return {xtd::parse<int32_t>(values[0]), xtd::parse<int32_t>(values[1])};
  }
}

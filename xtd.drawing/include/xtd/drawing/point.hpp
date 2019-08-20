#pragma once
#include <cstdint>
#include <ostream>
#include <string>
#include "point_f.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    struct size;
    /// @endcond

    /// @brief Represents an ordered pair of integer x- and y-coordinates that defines a point in a two-dimensional plane.
    /// @remarks To convert a Point to a PointF, use Implicit cast operator.
    /// @par Examples
    ///
    /// @code
    /// private:
    ///   void create_points_and_sizes(paint_event_args& e) {
    ///     // Create the starting point.
    ///     point start_point = subtract_button.size();
    ///
    ///     // Use the addition operator to get the end point.
    ///     point end_point = start_point + size(140, 150);
    ///
    ///     // Draw a line between the points.
    ///     e.graphics().draw_line(system_pens::highlight, start_point, end_point);
    ///
    ///     // Convert the starting point to a size and compare it to the subtractButton size.
    ///     size button_size(start_point);
    ///     if (button_size == subtract_button.size()) {
    ///       // If the sizes are equal, tell the user.
    ///       e.graphics().draw_string("The sizes are equal.", font(this->font, font_style.italic), brushes::indigo, 10.0F, 65.0F);
    ///     }
    ///   }
    /// @endcode
    struct point {
    public:
      /// @brief Represents a point that has x and y values set to zero.
      static const point empty;
      
      /// @brief Initializes a new instance of the Point class
      /// @remarks x and y values are set to zero.
      point() = default;
      
      /// @brief nitializes a new instance of the Point class using coordinates specified by an integer value.
      /// @param dx A 32-bit integer that specifies the coordinates for the new point.
      /// @remarks The low-order 16 bits of the dw parameter specify the horizontal x-coordinate and the higher 16 bits specify the vertical y-coordinate for the new point.
      /// @par Examples
      /// The following code example demonstrates how to use the point and size. size constructors and the xtd::drawing::content_alignment enumeration. To run this example, paste this code into a Windows Form (xtd::forms) that contains a label named label1, and call the initialize_label1 method in the form's constructor.
      /// @code
      /// private:
      ///   void initialize_label1() {
      ///     // Set a border.
      ///     label1.border_style = border_style::fixed_single;
      ///
      ///     // Set the size, constructing a size from two integers.
      ///     label1.size(drawing::size(100, 50));
      ///
      ///     // Set the location, constructing a point from a 32-bit integer
      ///     // (using hexadecimal).
      ///     label1.location(point(0x280028));
      ///
      ///     // Set and align the text on the lower-right side of the label.
      ///     label1.text_align = content_alignment::bottom_right;
      ///     label1.text = "Bottom Right Alignment";
      ///   }
      /// @endcode
      explicit point(int32_t dw) : x_(dw & 0x0000FFFF), y_((dw & 0xFFFF0000)>>16) {}

      /// @brief Initializes a new instance of the Point class with the specified coordinates.
      /// @param x The horizontal position of the point.
      /// @param y The vertical position of the point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// private:
      ///   void button1_Click(const control& sender, const event_args& e) {
      ///     // Construct a new Point with integers.
      ///     point point1(100, 100);
      ///
      ///     // Create a Graphics object.
      ///     graphics form_graphics = this->create_graphics();
      ///
      ///     // Construct another Point, this time using a Size.
      ///     point point2(size(100, 100));
      ///
      ///     // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///     if (point1 == point2) {
      ///       form_graphics.draw_string(strings::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), this->font(), brushes::black, point_f(10, 70));
      ///     }
      ///   }
      /// @endcode
      point(int32_t x, int32_t y) : x_(x), y_(y) {}
      
      /// @brief Initializes a new instance of the point class from a size.
      /// @param sz A size that specifies the coordinates for the new point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// private:
      ///   void button1_Click(const control& sender, const event_args& e) {
      ///     // Construct a new Point with integers.
      ///     point point1(100, 100);
      ///
      ///     // Create a Graphics object.
      ///     graphics form_graphics = this->create_graphics();
      ///
      ///     // Construct another Point, this time using a Size.
      ///     point point2(size(100, 100));
      ///
      ///     // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///     if (point1 == point2) {
      ///       form_graphics.draw_string(strings::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), this->font(), brushes::black, point_f(10, 70));
      ///     }
      ///   }
      /// @endcode
      point (const size& sz);

      /// @cond
      point(const point&) = default;
      point& operator=(const point&) = default;
      operator point_f() {return point_f(this->x_, this->y_);}
      /// @endcond
      
      /// @brief Gets a value indicating whether this Point is empty.
      /// @return true if both X and Y are 0; otherwise, false.
      bool is_empty() const {return *this == point::empty;}

      /// @brief Gets the x-coordinate of this point.
      /// @return The x-coordinate of this point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// private:
      ///   void button1_Click(const control& sender, const event_args& e) {
      ///     // Construct a new Point with integers.
      ///     point point1(100, 100);
      ///
      ///     // Create a Graphics object.
      ///     graphics form_graphics = this->create_graphics();
      ///
      ///     // Construct another Point, this time using a Size.
      ///     point point2(size(100, 100));
      ///
      ///     // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///     if (point1 == point2) {
      ///       form_graphics.draw_string(strings::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), this->font(), brushes::black, point_f(10, 70));
      ///     }
      ///   }
      /// @endcode
      int32_t x() const {return x_;}
      
      /// @brief Sets the x-coordinate of this point.
      /// @param x The x-coordinate of this point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// private:
      ///   void button1_Click(const control& sender, const event_args& e) {
      ///     // Construct a new Point with integers.
      ///     point point1(100, 100);
      ///
      ///     // Create a Graphics object.
      ///     graphics form_graphics = this->create_graphics();
      ///
      ///     // Construct another Point, this time using a Size.
      ///     point point2(size(100, 100));
      ///
      ///     // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///     if (point1 == point2) {
      ///       form_graphics.draw_string(strings::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), this->font(), brushes::black, point_f(10, 70));
      ///     }
      ///   }
      /// @endcode
      void x(int32_t x) {this->x_ = x;}
      
      /// @brief Gets the y-coordinate of this point.
      /// @return The y-coordinate of this point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// private:
      ///   void button1_Click(const control& sender, const event_args& e) {
      ///     // Construct a new Point with integers.
      ///     point point1(100, 100);
      ///
      ///     // Create a Graphics object.
      ///     graphics form_graphics = this->create_graphics();
      ///
      ///     // Construct another Point, this time using a Size.
      ///     point point2(size(100, 100));
      ///
      ///     // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///     if (point1 == point2) {
      ///       form_graphics.draw_string(strings::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), this->font(), brushes::black, point_f(10, 70));
      ///     }
      ///   }
      /// @endcode
      int32_t y() const {return y_;}
      
      /// @brief Sets the y-coordinate of this point.
      /// @param y The x-coordinate of this point.
      /// @par Examples
      /// The following code example demonstrates how to use the Equality operator and how to construct a point from a size or two integers. It also demonstrates how to use the x and y properties. This example is designed to be used with Windows Forms (xtd.forms). Paste the code into a form that contains a button named button1, and associate the button1_click method with the button's click event.
      /// @code
      /// private:
      ///   void button1_Click(const control& sender, const event_args& e) {
      ///     // Construct a new Point with integers.
      ///     point point1(100, 100);
      ///
      ///     // Create a Graphics object.
      ///     graphics form_graphics = this->create_graphics();
      ///
      ///     // Construct another Point, this time using a Size.
      ///     point point2(size(100, 100));
      ///
      ///     // Call the equality operator to see if the points are equal, and if so print out their x and y values.
      ///     if (point1 == point2) {
      ///       form_graphics.draw_string(strings::format("point1.x: {}, point2.x: {}, point1.y: {}, point2.y {}", point1.x(), point2.x(), point1.y(), point2.y()), this->font(), brushes::black, point_f(10, 70));
      ///     }
      ///   }
      /// @endcode
      void y(int32_t y) {this->y_ = y;}
      
      void offset(const point& pt) {this->offset(pt.x_, pt.y_);}

      void offset(int dx, int dy) {
        this->x_ += dx;
        this->y_ += dy;
      }

      std::string to_string() const {return "{x=" + std::to_string(this->x_) + ", y=" + std::to_string(this->y_) + "}";}

      bool operator==(const point& value) const {return this->x_ == value.x_ && this->y_ == value.y_;}
      bool operator!=(const point& value) const {return !this->operator==(value);}

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::point& point) noexcept {
        return os << point.to_string();
      }
      /// @endcond
      
    private:
      int32_t x_ = 0;
      int32_t y_ = 0;
    };
  }
}

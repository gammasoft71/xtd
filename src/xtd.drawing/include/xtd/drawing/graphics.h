/// @file
/// @brief Contains xtd::drawing::graphics class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <limits>
#include <ostream>
#include <xtd/strings.h>
#include "../drawing_export.h"
#include "brush.h"
#include "solid_brush.h"
#include "color.h"
#include "font.h"
#include "pen.h"
#include "point.h"
#include "point_f.h"
#include "rectangle.h"
#include "rectangle_f.h"
#include "size.h"
#include "string_format.h"
#include "size_f.h"

/// @cond
namespace xtd {
  namespace forms {
    class control;
    class control_paint;
    class paint_event_args;
    class screen;
  }
}
/// @endcond
  
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class image;
    /// @endcond
    /// @brief Defines an object used to draw lines and curves. This class cannot be inherited.
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ graphics {
    public:
      /// @cond
      graphics(const graphics& value);
      graphics& operator=(const graphics& value);
      ~graphics();
      /// @endcond
      
      /// @brief Gets the handle device context that the graphics is bound to.
      /// @return An intptr_t that contains the handle device context of the graphics.
      intptr_t handle() const {return data_->handle_;}
      
      /// @brief Clears the entire drawing surface and fills it with the specified background color.
      /// @param color xtd::drawing::color structure that represents the background color of the drawing surface.
      void clear(const color& color);
      
      /// @brief Draws an arc representing a portion of an ellipse specified by a Rectangle structure.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the arc.
      /// @param rect xtd::drawing::rectangle structure that defines the boundaries of the ellipse.
      /// @param start_angle Angle in degrees measured clockwise from the x-axis to the starting point of the arc.
      /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to ending point of the arc.
      /// @remarks This method draws an arc that is a portion of the perimeter of an ellipse. The ellipse is defined by the boundaries of a rectangle. The arc is the portion of the perimeter of the ellipse between the start_angle parameter and the start_angle + sweep_angle parameters.
      void draw_arc(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle) {draw_arc(pen, rect.x(), rect.y(), rect.width(), rect.height(), static_cast<int32_t>(start_angle), static_cast<int32_t>(sweep_angle));}
      /// @brief Draws an arc representing a portion of an ellipse specified by a Rectangle structure.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the arc.
      /// @param rect xtd::drawing::rectangle_f structure that defines the boundaries of the ellipse.
      /// @param start_angle Angle in degrees measured clockwise from the x-axis to the starting point of the arc.
      /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to ending point of the arc.
      /// @remarks This method draws an arc that is a portion of the perimeter of an ellipse. The ellipse is defined by the boundaries of a rectangle. The arc is the portion of the perimeter of the ellipse between the start_angle parameter and the start_angle + sweep_angle parameters.
      void draw_arc(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle) {draw_arc(pen, rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);}
      /// @brief Draws an arc representing a portion of an ellipse specified by a pair of coordinates, a width, and a height.
      /// @param x The x-coordinate of the upper-left corner of the rectangle that defines the ellipse.
      /// @param y The y-coordinate of the upper-left corner of the rectangle that defines the ellipse.
      /// @param width Width of the rectangle that defines the ellipse.
      /// @param height Height of the rectangle that defines the ellipse.
      /// @param start_angle Angle in degrees measured clockwise from the x-axis to the starting point of the arc.
      /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to ending point of the arc.
      /// @remarks This method draws an arc that is a portion of the perimeter of an ellipse. The ellipse is defined by the boundaries of a rectangle. The arc is the portion of the perimeter of the ellipse between the start_angle parameter and the start_angle + sweep_angle parameters.
      void draw_arc(const xtd::drawing::pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle);
      /// @brief Draws an arc representing a portion of an ellipse specified by a pair of coordinates, a width, and a height.
      /// @param x The x-coordinate of the upper-left corner of the rectangle that defines the ellipse.
      /// @param y The y-coordinate of the upper-left corner of the rectangle that defines the ellipse.
      /// @param width Width of the rectangle that defines the ellipse.
      /// @param height Height of the rectangle that defines the ellipse.
      /// @param start_angle Angle in degrees measured clockwise from the x-axis to the starting point of the arc.
      /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to ending point of the arc.
      /// @remarks This method draws an arc that is a portion of the perimeter of an ellipse. The ellipse is defined by the boundaries of a rectangle. The arc is the portion of the perimeter of the ellipse between the start_angle parameter and the start_angle + sweep_angle parameters.
      void draw_arc(const xtd::drawing::pen& pen, float x, float y, float width, float height, float start_angle, float sweep_angle) {draw_arc(pen, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height), static_cast<int32_t>(start_angle), static_cast<int32_t>(sweep_angle));}

      /// @brief Draws a Bézier spline defined by four Point structures.
      /// @param pen xtd::drawing::pen structure that determines the color, width, and style of the curve.
      /// @param pt1 xtd::drawing::point structure that represents the starting point of the curve.
      /// @param pt2 xtd::drawing::point structure that represents the first control point for the curve.
      /// @param pt3 xtd::drawing::point structure that represents the second control point for the curve.
      /// @param pt4 xtd::drawing::point structure that represents the ending point of the curve.
      /// @remarks The Bézier curve is drawn from the first point to the fourth point. The second and third points are control points that determine the shape of the curve.
      void draw_bezier(const xtd::drawing::pen& pen, const xtd::drawing::point& pt1, const xtd::drawing::point& pt2, const xtd::drawing::point& pt3, const xtd::drawing::point& pt4) {draw_bezier(pen, pt1.x(), pt1.y(), pt2.x(), pt2.y(), pt3.x(), pt3.y(), pt4.x(), pt4.y());}
      /// @brief Draws a Bézier spline defined by four Point structures.
      /// @param pen xtd::drawing::pen structure that determines the color, width, and style of the curve.
      /// @param pt1 xtd::drawing::point structure that represents the starting point of the curve.
      /// @param pt2 xtd::drawing::point structure that represents the first control point for the curve.
      /// @param pt3 xtd::drawing::point structure that represents the second control point for the curve.
      /// @param pt4 xtd::drawing::point structure that represents the ending point of the curve.
      /// @remarks The Bézier curve is drawn from the first point to the fourth point. The second and third points are control points that determine the shape of the curve.
      void draw_bezier(const xtd::drawing::pen& pen, const xtd::drawing::point_f& pt1, const xtd::drawing::point_f& pt2, const xtd::drawing::point_f& pt3, const xtd::drawing::point_f& pt4) {draw_bezier(pen, pt1.x(), pt1.y(), pt2.x(), pt2.y(), pt3.x(), pt3.y(), pt4.x(), pt4.y());}
      /// @brief Draws a Bézier spline defined by four ordered pairs of coordinates that represent points.
      /// @param pen xtd::drawing::pen structure that determines the color, width, and style of the curve.
      /// @param x1 The x-coordinate of the starting point of the curve.
      /// @param y1 The y-coordinate of the starting point of the curve.
      /// @param x2 The x-coordinate of the first control point of the curve.
      /// @param y2 The y-coordinate of the first control point of the curve.
      /// @param x3 The x-coordinate of the second control point of the curve.
      /// @param y3 The y-coordinate of the second control point of the curve.
      /// @param x4 The x-coordinate of the ending point of the curve.
      /// @param y4 The y-coordinate of the ending point of the curve.
      /// @remarks The Bézier curve is drawn from the first point to the fourth point. The second and third points are control points that determine the shape of the curve.
      void draw_bezier(const pen& pen, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {draw_bezier(pen, static_cast<int32_t>(x1), static_cast<int32_t>(y1), static_cast<int32_t>(x2), static_cast<int32_t>(y2), static_cast<int32_t>(x3), static_cast<int32_t>(y3), static_cast<int32_t>(x4), static_cast<int32_t>(y4));}
      /// @brief Draws a Bézier spline defined by four ordered pairs of coordinates that represent points.
      /// @param pen xtd::drawing::pen structure that determines the color, width, and style of the curve.
      /// @param x1 The x-coordinate of the starting point of the curve.
      /// @param y1 The y-coordinate of the starting point of the curve.
      /// @param x2 The x-coordinate of the first control point of the curve.
      /// @param y2 The y-coordinate of the first control point of the curve.
      /// @param x3 The x-coordinate of the second control point of the curve.
      /// @param y3 The y-coordinate of the second control point of the curve.
      /// @param x4 The x-coordinate of the ending point of the curve.
      /// @param y4 The y-coordinate of the ending point of the curve.
      /// @remarks The Bézier curve is drawn from the first point to the fourth point. The second and third points are control points that determine the shape of the curve.
      void draw_bezier(const pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4);

      /// @brief Draws an ellipse specified by a bounding xtd::drawing::rectangle structure.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the ellipse.
      /// @param rect xtd::drawing::rectangle structure that defines the boundaries of the ellipse.
      /// @remarks This method draws an ellipse that is defined by the bounding rectangle specified by the rect parameter.
      void draw_ellipse(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect) {draw_ellipse(pen, rect.x(), rect.y(), rect.width(), rect.height());}
      /// @brief Draws an ellipse specified by a bounding xtd::drawing::rectangle_f structure.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the ellipse.
      /// @param rect xtd::drawing::rectangle_f structure that defines the boundaries of the ellipse.
      /// @remarks This method draws an ellipse that is defined by the bounding rectangle specified by the rect parameter.
      void draw_ellipse(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect) {draw_ellipse(pen, rect.x(), rect.y(), rect.width(), rect.height());}
      /// @brief Draws an ellipse defined by a bounding rectangle specified by coordinates for the upper-left corner of the rectangle, a height, and a width.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the ellipse.
      /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
      /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
      /// @param width Width of the bounding rectangle that defines the ellipse.
      /// @param height Height of the bounding rectangle that defines the ellipse.
      /// @remarks This method draws an ellipse that is defined by the bounding rectangle described by the x, y, width, and height parameters.
      void draw_ellipse(const xtd::drawing::pen& pen, int32_t x, int32_t y, int32_t width, int32_t height);
      /// @brief Draws an ellipse defined by a bounding rectangle specified by coordinates for the upper-left corner of the rectangle, a height, and a width.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the ellipse.
      /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
      /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
      /// @param width Width of the bounding rectangle that defines the ellipse.
      /// @param height Height of the bounding rectangle that defines the ellipse.
      /// @remarks This method draws an ellipse that is defined by the bounding rectangle described by the x, y, width, and height parameters.
      void draw_ellipse(const xtd::drawing::pen& pen, float x, float y, float width, float height) {draw_ellipse(pen, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height));}
      
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle& rect) {draw_image(image, rect.x(), rect.y(), rect.width(), rect.height());}
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle_f& rect) {draw_image(image, rect.x(), rect.y(), rect.width(), rect.height());}
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::point& point) {draw_image(image, point.x(), point.y());}
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::point_f& point) {draw_image(image, point.x(), point.y());}
      void draw_image(const xtd::drawing::image& image, int32_t x, int32_t y, int32_t width, int32_t height);
      void draw_image(const xtd::drawing::image& image, float x, float y, float width, float height) {draw_image(image, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height));}
      void draw_image(const xtd::drawing::image& image, int32_t x, int32_t y);
      void draw_image(const xtd::drawing::image& image, float x, float y) {draw_image(image, static_cast<int32_t>(x), static_cast<int32_t>(y));}

      void draw_line(const xtd::drawing::pen& pen, const xtd::drawing::point& p1, const point& p2) {draw_line(pen, p1.x(), p1.y(), p2.x(), p2.y());}
      void draw_line(const xtd::drawing::pen& pen, const xtd::drawing::point_f& p1, const point_f& p2) {draw_line(pen, p1.x(), p1.y(), p2.x(), p2.y());}
      void draw_line(const xtd::drawing::pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2);
      void draw_line(const xtd::drawing::pen& pen, float x1, float y1, float x2, float y2) {draw_line(pen, static_cast<int32_t>(x1), static_cast<int32_t>(y1), static_cast<int32_t>(x2), static_cast<int32_t>(y2));}
      
      void draw_point(const xtd::drawing::pen& pen, const xtd::drawing::point& p) {draw_point(pen, p.x(), p.y());}
      void draw_point(const xtd::drawing::pen& pen, const xtd::drawing::point_f& p) {draw_point(pen, p.x(), p.y());}
      void draw_point(const xtd::drawing::pen& pen, int32_t x, int32_t y) {draw_point(pen, static_cast<float>(x), static_cast<float>(y));}
      void draw_point(const xtd::drawing::pen& pen, float x, float y) {fill_ellipse(solid_brush(pen.color()), x, y, pen.width(), pen.width());}
      
      void draw_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect) {draw_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height());}
      void draw_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect) {draw_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height());}
      void draw_rectangle(const xtd::drawing::pen& pen, int32_t x, int32_t y, int32_t width, int32_t height);
      void draw_rectangle(const xtd::drawing::pen& pen, float x, float y, float width, float height) {draw_rectangle(pen, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height));}
      
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, int32_t radius) {draw_rounded_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height(), radius);}
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float radius) {draw_rounded_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height(), radius);}
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius);
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, float x, float y, float width, float height, float radius) {draw_rounded_rectangle(pen, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height), static_cast<int32_t>(radius));}

      void draw_string(const std::string& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& layout_rectangle, const string_format& format);
      void draw_string(const std::string& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& layout_rectangle) {draw_string(text, font, brush, layout_rectangle, string_format());}
      void draw_string(const std::string& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point, const string_format& format) {draw_string(text, font, brush, point.x(), point.y(), format);}
      void draw_string(const std::string& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point) {draw_string(text, font, brush, point.x(), point.y(), string_format());}
      void draw_string(const std::string& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, float x, float y, const string_format& format);
      void draw_string(const std::string& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, float x, float y) {draw_string(text, font, brush, x, y, string_format());}

      void fill_ellipse(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect) {fill_ellipse(brush, rect.x(), rect.y(), rect.width(), rect.height());}
      void fill_ellipse(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect) {fill_ellipse(brush, rect.x(), rect.y(), rect.width(), rect.height());}
      void fill_ellipse(const xtd::drawing::brush& brush, int32_t x, int32_t y, int32_t width, int32_t height);
      void fill_ellipse(const xtd::drawing::brush& brush, float x, float y, float width, float height) {fill_ellipse(brush, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height));}
      
      void fill_pie(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle) {fill_pie(brush, rect.x(), rect.y(), rect.width(), rect.height(), static_cast<int32_t>(start_angle), static_cast<int32_t>(sweep_angle));}
      void fill_pie(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle) {fill_pie(brush, rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);}
      void fill_pie(const xtd::drawing::brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle);
      void fill_pie(const xtd::drawing::brush& brush, float x, float y, float width, float height, float start_angle, float sweep_angle) {fill_pie(brush, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height), static_cast<int32_t>(start_angle), static_cast<int32_t>(sweep_angle));}

      void fill_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect) {fill_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height());}
      void fill_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect) {fill_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height());}
      void fill_rectangle(const xtd::drawing::brush& brush, int32_t x, int32_t y, int32_t width, int32_t height);
      void fill_rectangle(const xtd::drawing::brush& brush, float x, float y, float width, float height) {fill_rectangle(brush, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height));}

      void fill_rounded_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect, int32_t radius) {fill_rounded_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height(), radius);}
      void fill_rounded_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect, float radius) {fill_rounded_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height(), radius);}
      void fill_rounded_rectangle(const xtd::drawing::brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius);
      void fill_rounded_rectangle(const xtd::drawing::brush& brush, float x, float y, float width, float height, float radius) {fill_rounded_rectangle(brush, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height), static_cast<int32_t>(radius));}

      static graphics from_image(const xtd::drawing::image& image);
      
      size_f measure_string(const std::string& text, const xtd::drawing::font& font);
      
      void rotate_transform(float angle);

      void translate_clip(int32_t dx, int32_t dy);

      void translate_clip(float dx, float dy) {translate_clip(static_cast<int32_t>(dx), static_cast<int32_t>(dy));}

      std::string to_string() const {return strings::full_class_name(*this);}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::graphics& graphics) noexcept {
        return os << graphics.to_string();
      }
      /// @endcond
      
    private:
      friend xtd::drawing::font;
      friend xtd::forms::control;
      friend xtd::forms::control_paint;
      friend xtd::forms::paint_event_args;
      friend xtd::forms::screen;

      graphics(intptr_t handle) {data_->handle_ = handle;}
      void draw_image_disabled(const xtd::drawing::image& image, int32_t x, int32_t y, float brightness);
      
      struct data {
        intptr_t handle_ = 0;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}

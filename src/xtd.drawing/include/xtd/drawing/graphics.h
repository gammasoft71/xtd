/// @file
/// @brief Contains xtd::drawing::graphics class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <limits>
#include <ostream>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../drawing_export.h"
#include "brush.h"
#include "solid_brush.h"
#include "color.h"
#include "font.h"
#include "graphics_unit.h"
#include "pen.h"
#include "point.h"
#include "point_f.h"
#include "rectangle.h"
#include "rectangle_f.h"
#include "region.h"
#include "size.h"
#include "string_format.h"
#include "size_f.h"
#include "drawing2d/interpolation_mode.h"
#include "drawing2d/graphics_path.h"
#include "drawing2d/pixel_offset_mode.h"
#include "drawing2d/smoothing_mode.h"

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
    class icon;
    class image;
    /// @endcond
    /// @brief Defines an object used to draw lines and curves. This class cannot be inherited.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ graphics : public object {
    public:
      /// @cond
      graphics(const graphics& value);
      graphics& operator=(const graphics& value);
      ~graphics();
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a xtd::drawing::region that limits the drawing region of this xtd::drawing::graphics.
      /// @return A xtd::drawing::region that limits the portion of this Graphics that is currently available for drawing.
      /// @remarks Modifying the xtd::drawing::region object returned by the xtd::drawing::graphics::clip property does not affect subsequent drawing with the xtd::drawing::graphics object. To change the clip region, replace the xtd::drawing::graphics::clip property value with a new xtd::drawing::region object. To determine whether the clipping region is infinite, retrieve the xtd::drawing::graphics::clip property and call its xtd::drawing::region::is_infinite method.
      xtd::drawing::region clip() const;
      /// @brief Sets a xtd::drawing::region that limits the drawing region of this xtd::drawing::graphics.
      /// @param value A xtd::drawing::region that limits the portion of this Graphics that is currently available for drawing.
      /// @return This current instance.
      /// @remarks Modifying the xtd::drawing::region object returned by the xtd::drawing::graphics::clip property does not affect subsequent drawing with the xtd::drawing::graphics object. To change the clip region, replace the xtd::drawing::graphics::clip property value with a new xtd::drawing::region object. To determine whether the clipping region is infinite, retrieve the xtd::drawing::graphics::clip property and call its xtd::drawing::region::is_infinite method.
      graphics& clip(const xtd::drawing::region value);

      /// @brief Gets a xtd::drawing::rectangle_f structure that bounds the clipping region of this xtd::drawing::graphics.
      /// @return A xtd::drawing::rectangle_f structure that represents a bounding rectangle for the clipping region of this xtd::drawing::graphics.
      /// @remarks The unit for resulting rectangle is designated by the xtd::drawing::graphics::page_unit property. The default unit is pixels. A xtd::drawing::graphics is typically associated with a control and the origin of the rectangle will be relative to the client area of that control.
      /// @remarks If the clipping region is infinite, the xtd::drawing::graphics::clip_bounds property returns a meaningless large rectangle. To determine whether the clipping region is infinite, retrieve the xtd::drawing::graphics::clip property and call its xtd::drawing::region::is_infinite method.
      xtd::drawing::rectangle_f clip_bounds() const;
      
      /// @brief Gets the horizontal resolution of this xtd::drawing::graphics.
      /// @return The value, in dots per inch, for the horizontal resolution supported by this xtd::drawing::graphics.
      float dpi_x() const;
    
      /// @brief Gets the vertical resolution of this xtd::drawing::graphics.
      /// @return The value, in dots per inch, for the vertical resolution supported by this xtd::drawing::graphics.
      float dpi_y() const;

      /// @brief Gets the handle device context that the graphics is bound to.
      /// @return An intptr_t that contains the handle device context of the graphics.
      intptr_t handle() const;
      
      /// @brief Gets the interpolation mode associated with this xtd::drawing::graphics.
      /// @return One of the xtd::drawing::drawing2d::interpolation_mode values.
      /// @remarks The interpolation mode determines how intermediate values between two endpoints are calculated.
      xtd::drawing::drawing2d::interpolation_mode interpolation_mode() const;
      /// @brief Sets the interpolation mode associated with this xtd::drawing::graphics.
      /// @param value One of the xtd::drawing::drawing2d::interpolation_mode values.
      /// @return This current instance.
      /// @remarks The interpolation mode determines how intermediate values between two endpoints are calculated.
      graphics& interpolation_mode(xtd::drawing::drawing2d::interpolation_mode value);

      /// @brief Gets the scaling between world units and page units for this xtd::drawing::graphics.
      /// @return This property specifies a value for the scaling between world units and page units for this xtd::drawing::graphics.
      float page_scale() const;
      /// @brief Sets the scaling between world units and page units for this xtd::drawing::graphics.
      /// @param value This property specifies a value for the scaling between world units and page units for this xtd::drawing::graphics.
      /// @return This current instance.
      graphics& page_scale(float value);

      /// @brief Gets or sets the unit of measure used for page coordinates in this xtd::drawing::graphics.
      /// @return One of the xtd::drawing::graphics_unit values other than xtd::drawing::graphics_unit::world.
      /// @remarks The graphics unit is the unit of measure used for page coordinates in this xtd::drawing::graphics.
      xtd::drawing::graphics_unit page_unit() const;
      /// @brief Sets or sets the unit of measure used for page coordinates in this xtd::drawing::graphics.
      /// @param value One of the xtd::drawing::graphics_unit values other than xtd::drawing::graphics_unit::world.
      /// @return This current instance.
      /// @exception xtd::argument_exception xtd::drawing::graphics::page_unit is set to xtd::drawing::graphics_unit::world, which is not a physical unit.
      /// @remarks The graphics unit is the unit of measure used for page coordinates in this xtd::drawing::graphics.
      graphics& page_unit(xtd::drawing::graphics_unit value);
      
      /// @brief Gets a value specifying how pixels are offset during rendering of this xtd::drawing::graphics.
      /// @return This property specifies a member of the xtd::drawing::drawing2d::pixel_offset_mode enumeration.
      /// @remarks Use this property to specify either higher quality, slower rendering, or lower quality, faster rendering of the contents of this xtd::drawing::graphics object.
      xtd::drawing::drawing2d::pixel_offset_mode pixel_offset_mode() const;
      /// @brief Sets a value specifying how pixels are offset during rendering of this xtd::drawing::graphics.
      /// @param value This property specifies a member of the xtd::drawing::drawing2d::pixel_offset_mode enumeration.
      /// @return This current instance.
      /// @remarks Use this property to specify either higher quality, slower rendering, or lower quality, faster rendering of the contents of this xtd::drawing::graphics object.
      graphics& pixel_offset_mode(xtd::drawing::drawing2d::pixel_offset_mode value);
      
      /// @brief Gets the rendering quality for this xtd::drawing::graphics.
      /// @return One of the xtd::drawing::drawing2d::smoothing_mode values.
      /// @remarks The smoothing mode specifies whether lines, curves, and the edges of filled areas use smoothing (also called antialiasing). One exception is that path gradient brushes do not obey the smoothing mode. Areas filled using a xtd::drawing::drawing2d::path_gradient_brush are rendered the same way (aliased) regardless of the xtd::drawing::graphics::smoothing_mode property.
      xtd::drawing::drawing2d::smoothing_mode smoothing_mode() const;
      /// @brief Sets the rendering quality for this xtd::drawing::graphics.
      /// @param value One of the xtd::drawing::drawing2d::smoothing_mode values.
      /// @return This current instance.
      /// @remarks The smoothing mode specifies whether lines, curves, and the edges of filled areas use smoothing (also called antialiasing). One exception is that path gradient brushes do not obey the smoothing mode. Areas filled using a xtd::drawing::drawing2d::path_gradient_brush are rendered the same way (aliased) regardless of the xtd::drawing::graphics::smoothing_mode property.
      graphics& smoothing_mode(xtd::drawing::drawing2d::smoothing_mode value);
      
      int text_contrast() const;
      graphics& text_contrast(int value);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Clears the entire drawing surface and fills it with the specified background color.
      /// @param color xtd::drawing::color structure that represents the background color of the drawing surface.
      void clear(const color& color);
      
      /// @brief Draws an arc representing a portion of an ellipse specified by a Rectangle structure.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the arc.
      /// @param rect xtd::drawing::rectangle structure that defines the boundaries of the ellipse.
      /// @param start_angle Angle in degrees measured clockwise from the x-axis to the starting point of the arc.
      /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to ending point of the arc.
      /// @remarks This method draws an arc that is a portion of the perimeter of an ellipse. The ellipse is defined by the boundaries of a rectangle. The arc is the portion of the perimeter of the ellipse between the start_angle parameter and the start_angle + sweep_angle parameters.
      void draw_arc(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle);
      /// @brief Draws an arc representing a portion of an ellipse specified by a Rectangle structure.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the arc.
      /// @param rect xtd::drawing::rectangle_f structure that defines the boundaries of the ellipse.
      /// @param start_angle Angle in degrees measured clockwise from the x-axis to the starting point of the arc.
      /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to ending point of the arc.
      /// @remarks This method draws an arc that is a portion of the perimeter of an ellipse. The ellipse is defined by the boundaries of a rectangle. The arc is the portion of the perimeter of the ellipse between the start_angle parameter and the start_angle + sweep_angle parameters.
      void draw_arc(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle);
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
      void draw_arc(const xtd::drawing::pen& pen, float x, float y, float width, float height, float start_angle, float sweep_angle);
      
      /// @brief Draws a Bézier spline defined by four Point structures.
      /// @param pen xtd::drawing::pen structure that determines the color, width, and style of the curve.
      /// @param pt1 xtd::drawing::point structure that represents the starting point of the curve.
      /// @param pt2 xtd::drawing::point structure that represents the first control point for the curve.
      /// @param pt3 xtd::drawing::point structure that represents the second control point for the curve.
      /// @param pt4 xtd::drawing::point structure that represents the ending point of the curve.
      /// @remarks The Bézier curve is drawn from the first point to the fourth point. The second and third points are control points that determine the shape of the curve.
      void draw_bezier(const xtd::drawing::pen& pen, const xtd::drawing::point& pt1, const xtd::drawing::point& pt2, const xtd::drawing::point& pt3, const xtd::drawing::point& pt4);
      /// @brief Draws a Bézier spline defined by four Point structures.
      /// @param pen xtd::drawing::pen structure that determines the color, width, and style of the curve.
      /// @param pt1 xtd::drawing::point structure that represents the starting point of the curve.
      /// @param pt2 xtd::drawing::point structure that represents the first control point for the curve.
      /// @param pt3 xtd::drawing::point structure that represents the second control point for the curve.
      /// @param pt4 xtd::drawing::point structure that represents the ending point of the curve.
      /// @remarks The Bézier curve is drawn from the first point to the fourth point. The second and third points are control points that determine the shape of the curve.
      void draw_bezier(const xtd::drawing::pen& pen, const xtd::drawing::point_f& pt1, const xtd::drawing::point_f& pt2, const xtd::drawing::point_f& pt3, const xtd::drawing::point_f& pt4);
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
      void draw_bezier(const pen& pen, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
      
      /// @brief Draws an ellipse specified by a bounding xtd::drawing::rectangle structure.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the ellipse.
      /// @param rect xtd::drawing::rectangle structure that defines the boundaries of the ellipse.
      /// @remarks This method draws an ellipse that is defined by the bounding rectangle specified by the rect parameter.
      void draw_ellipse(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect);
      /// @brief Draws an ellipse specified by a bounding xtd::drawing::rectangle_f structure.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the ellipse.
      /// @param rect xtd::drawing::rectangle_f structure that defines the boundaries of the ellipse.
      /// @remarks This method draws an ellipse that is defined by the bounding rectangle specified by the rect parameter.
      void draw_ellipse(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect);
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
      void draw_ellipse(const xtd::drawing::pen& pen, float x, float y, float width, float height);

      /// @brief Draws the image represented by the specified xtd::drawing::icon at the specified coordinates.
      /// @param icon xtd::drawing::icon to draw.
      /// @param x The x-coordinate of the upper-left corner of the drawn image.
      /// @param y The y-coordinate of the upper-left corner of the drawn image.
      void draw_icon(const xtd::drawing::icon& icon, int32_t x, int32_t y);
      /// @brief Draws the image represented by the specified xtd::drawing::icon within the area specified by a xtd::drawing::rectangle structure.
      /// @param icon xtd::drawing::icon to draw.
      /// @param rect xtd::drawing::rectangle structure that specifies the location and size of the resulting image on the display surface. The image contained in the icon parameter is scaled to the dimensions of this rectangular area.
      void draw_icon(const xtd::drawing::icon& icon, const xtd::drawing::rectangle& rect);

      /// @brief Draws the image represented by the specified Icon without scaling the image.
      /// @param icon xtd::drawing::icon to draw.
      /// @param rect xtd::drawing::rectangle structure that specifies the location and size of the resulting image. The image is not scaled to fit this rectangle, but retains its original size. If the image is larger than the rectangle, it is clipped to fit inside it.
      void draw_icon_unstretched(const xtd::drawing::icon& icon, const xtd::drawing::rectangle& rect);

      void draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle& rect);
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle_f& rect);
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::point& point);
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::point_f& point);
      void draw_image(const xtd::drawing::image& image, int32_t x, int32_t y, int32_t width, int32_t height);
      void draw_image(const xtd::drawing::image& image, float x, float y, float width, float height);
      void draw_image(const xtd::drawing::image& image, int32_t x, int32_t y);
      void draw_image(const xtd::drawing::image& image, float x, float y);
      
      void draw_line(const xtd::drawing::pen& pen, const xtd::drawing::point& p1, const point& p2);
      void draw_line(const xtd::drawing::pen& pen, const xtd::drawing::point_f& p1, const point_f& p2);
      void draw_line(const xtd::drawing::pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2);
      void draw_line(const xtd::drawing::pen& pen, float x1, float y1, float x2, float y2);

      void draw_path(const xtd::drawing::pen& pen, const xtd::drawing::drawing2d::graphics_path& graphics_path);

      void draw_point(const xtd::drawing::pen& pen, const xtd::drawing::point& p);
      void draw_point(const xtd::drawing::pen& pen, const xtd::drawing::point_f& p);
      void draw_point(const xtd::drawing::pen& pen, int32_t x, int32_t y);
      void draw_point(const xtd::drawing::pen& pen, float x, float y);
      
      void draw_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect);
      void draw_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect);
      void draw_rectangle(const xtd::drawing::pen& pen, int32_t x, int32_t y, int32_t width, int32_t height);
      void draw_rectangle(const xtd::drawing::pen& pen, float x, float y, float width, float height);
      
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, int32_t radius);
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float radius);
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius);
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, float x, float y, float width, float height, float radius);
      
      void draw_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& layout_rectangle, const string_format& format);
      void draw_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& layout_rectangle);
      void draw_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point, const string_format& format);
      void draw_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point);
      void draw_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, float x, float y, const string_format& format);
      void draw_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, float x, float y);
      
      void fill_ellipse(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect);
      void fill_ellipse(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect);
      void fill_ellipse(const xtd::drawing::brush& brush, int32_t x, int32_t y, int32_t width, int32_t height);
      void fill_ellipse(const xtd::drawing::brush& brush, float x, float y, float width, float height);
      
      void fill_path(const xtd::drawing::brush& brush, const xtd::drawing::drawing2d::graphics_path& path);
      
      void fill_pie(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle);
      void fill_pie(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle);
      void fill_pie(const xtd::drawing::brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle);
      void fill_pie(const xtd::drawing::brush& brush, float x, float y, float width, float height, float start_angle, float sweep_angle);
      
      void fill_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect);
      void fill_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect);
      void fill_rectangle(const xtd::drawing::brush& brush, int32_t x, int32_t y, int32_t width, int32_t height);
      void fill_rectangle(const xtd::drawing::brush& brush, float x, float y, float width, float height);

      void fill_region(const xtd::drawing::brush& brush, const xtd::drawing::region& region);

      void fill_rounded_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect, int32_t radius);
      void fill_rounded_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect, float radius);
      void fill_rounded_rectangle(const xtd::drawing::brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius);
      void fill_rounded_rectangle(const xtd::drawing::brush& brush, float x, float y, float width, float height, float radius);
      
      static graphics from_image(const xtd::drawing::image& image);
      
      size_f measure_string(const xtd::ustring& text, const xtd::drawing::font& font);
      
      void rotate_transform(float angle);
      
      void translate_clip(int32_t dx, int32_t dy);
      
      void translate_clip(float dx, float dy);
      
      xtd::ustring to_string() const noexcept override {return ustring::full_class_name(*this);}
      /// @}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::graphics& graphics) noexcept {
        return os << graphics.to_string();
      }
      /// @endcond
      
    private:
      float to_pixels(float value) const;
      float to_page_unit(float value) const;
      friend xtd::drawing::font;
      friend xtd::forms::control;
      friend xtd::forms::control_paint;
      friend xtd::forms::paint_event_args;
      friend xtd::forms::screen;
      
      explicit graphics(intptr_t handle) {data_->handle = handle;}
      void draw_image_disabled(const xtd::drawing::image& image, float x, float y, float brightness);
      
      struct data {
        xtd::drawing::region clip;
        intptr_t handle = 0;
        xtd::drawing::drawing2d::interpolation_mode interpolation_mode = xtd::drawing::drawing2d::interpolation_mode::default_value;
        float page_scale = 1.0f;
        xtd::drawing::graphics_unit page_unit = xtd::drawing::graphics_unit::pixel;
        xtd::drawing::drawing2d::pixel_offset_mode pixel_offset_mode = xtd::drawing::drawing2d::pixel_offset_mode::default_value;
        xtd::drawing::drawing2d::smoothing_mode smoothing_mode = xtd::drawing::drawing2d::smoothing_mode::default_value;
        int text_contrast = 4;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}

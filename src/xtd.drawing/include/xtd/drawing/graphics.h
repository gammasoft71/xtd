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
#include "copy_pixel_operation.h"
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
#include "drawing2d/compositing_mode.h"
#include "drawing2d/compositing_quality.h"
#include "drawing2d/interpolation_mode.h"
#include "drawing2d/graphics_path.h"
#include "drawing2d/pixel_offset_mode.h"
#include "drawing2d/smoothing_mode.h"
#include "text/text_rendering_hint.h"


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
    /// @code
    /// class drawing_export_ graphics : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::graphics
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ graphics : public xtd::object {
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
      
      /// @brief Gets a value that specifies how composited images are drawn to this xtd::drawing::graphics.
      /// @return This property specifies a member of the xtd::drawing::drawing2d::compositing_mode enumeration. The default is xtd::drawing::drawing2d::compositing_mode::source_over.
      /// @remarks The compositing mode determines whether pixels from a source image overwrite or are combined with background pixels.
      /// @note You should not use a xtd::drawing::graphics::compositing_mode property value of xtd::drawing::graphics::source_copy when the xtd::drawing::graphics::text_rendering_hint property is set to xtd::drawing::graphics::text_rendering_hint::clear_type_grid_fit. An exception could occur or the image may not render correctly.
      xtd::drawing::drawing2d::compositing_mode compositing_mode() const;
      /// @brief Sets a value that specifies how composited images are drawn to this xtd::drawing::graphics.
      /// @param value This property specifies a member of the CompositingMode enumeration. The default is SourceOver.
      /// @return This current instance.
      /// @remarks The compositing mode determines whether pixels from a source image overwrite or are combined with background pixels.
      /// @note You should not use a xtd::drawing::graphics::compositing_mode property value of xtd::drawing::graphics::source_copy when the xtd::drawing::graphics::text_rendering_hint property is set to xtd::drawing::graphics::text_rendering_hint::clear_type_grid_fit. An exception could occur or the image may not render correctly.
      graphics& compositing_mode(xtd::drawing::drawing2d::compositing_mode value);
      
      /// @brief Gets the rendering quality of composited images drawn to this xtd::drawing::graphics.
      /// @return This property specifies a member of the xtd::drawing::drawing2d::compositing_quality enumeration. The xtd::drawing::drawing2d::compositing_quality::default_value is Default.
      /// @remarks The compositing quality determines the rendering quality level of composited images.
      xtd::drawing::drawing2d::compositing_quality compositing_quality() const;
      /// @brief Sets the rendering quality of composited images drawn to this xtd::drawing::graphics.
      /// @param value This property specifies a member of the xtd::drawing::drawing2d::compositing_quality enumeration. The xtd::drawing::drawing2d::compositing_quality::default_value is Default.
      /// @return This current instance.
      /// @remarks The compositing quality determines the rendering quality level of composited images.
      graphics& compositing_quality(xtd::drawing::drawing2d::compositing_quality value);
      
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
      
      /// @brief Gets the gamma correction value for rendering text.
      /// @return The gamma correction value used for rendering antialiased and ClearType text.
      /// @remarks The gamma correction value must be between 0 and 12. The default value is 4.
      int text_contrast() const;
      /// @brief Sets the gamma correction value for rendering text.
      /// @param value The gamma correction value used for rendering antialiased and ClearType text.
      /// @return This current instance.
      /// @remarks The gamma correction value must be between 0 and 12. The default value is 4.
      graphics& text_contrast(int value);
      
      /// @brief Gets the rendering mode for text associated with this xtd::drawing::graphics.
      /// @return One of the xtd::drawing::graphics::text_rendering_hint values.
      /// @remarks The text rendering hint specifies whether text renders with antialiasing.
      /// @note You should not use a xtd::drawing::graphics::compositing_mode property value of xtd::drawing::graphics::source_copy when the xtd::drawing::graphics::text_rendering_hint property is set to xtd::drawing::graphics::text_rendering_hint::clear_type_grid_fit. An exception could occur or the image may not render correctly.
      xtd::drawing::text::text_rendering_hint text_rendering_hint() const;
      /// @brief Sets the rendering mode for text associated with this xtd::drawing::graphics.
      /// @param value One of the xtd::drawing::graphics::text_rendering_hint values.
      /// @return This current instance.
      /// @remarks The text rendering hint specifies whether text renders with antialiasing.
      /// @note You should not use a xtd::drawing::graphics::compositing_mode property value of xtd::drawing::graphics::source_copy when the xtd::drawing::graphics::text_rendering_hint property is set to xtd::drawing::graphics::text_rendering_hint::clear_type_grid_fit. An exception could occur or the image may not render correctly.
      graphics& text_rendering_hint(xtd::drawing::text::text_rendering_hint value);
      
      /// @brief Gets the bounding rectangle of the visible clipping region of this xtd::drawing::graphics.
      /// @return A xtd::drawing::rectangle_f structure that represents a bounding rectangle for the visible clipping region of this xtd::drawing::graphics.
      /// @remarks The unit for resulting rectangle is designated by the xtd::drawing::graphics::page_unit property. The default unit is pixels. A xtd::drawing::graphics is typically associated with a control and the origin of the rectangle will be relative to the client area of that control.
      /// @remarks The visible clipping region is the intersection of the clipping region of this xtd::drawing::graphics::graphics and the clipping region of the window.
      xtd::drawing::rectangle_f visible_clip_bounds() const noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Clears the entire drawing surface and fills it with the specified background color.
      /// @param color xtd::drawing::color structure that represents the background color of the drawing surface.
      void clear(const color& color);
      
      /// @brief Performs a bit-block transfer of color data, corresponding to a rectangle of pixels, from the screen to the drawing surface of the xtd::drawing::graphics.
      /// @param upper_left_source The point at the upper-left corner of the source rectangle.
      /// @param upper_left_destination The point at the upper-left corner of the destination rectangle.
      /// @param block_region_size The size of the area to be transferred.
      /// @remarks The xtd::drawing::graphics::copy_from_screen methods are useful for layering one image on top of another. To specify how the source and destination colors are blended, use one of the xtd::drawing::graphics::copy_from_screen methods that takes a xtd::drawing::graphics::copy_pixel_operation parameter.
      void copy_from_screen(const xtd::drawing::point& upper_left_source, const xtd::drawing::point& upper_left_destination, const xtd::drawing::size& block_region_size);
      /// @brief Performs a bit-block transfer of color data, corresponding to a rectangle of pixels, from the screen to the drawing surface of the xtd::drawing::graphics.
      /// @param upper_left_source The point at the upper-left corner of the source rectangle.
      /// @param upper_left_destination The point at the upper-left corner of the destination rectangle.
      /// @param block_region_size The size of the area to be transferred.
      /// @param copy_pixel_operation One of the xtd::drawing::graphics::copy_pixel_operation values.
      /// @remarks The xtd::drawing::graphics::copy_from_screen methods are useful for layering one image on top of another. The xtd::drawing::copy_pixel_operation parameter allows you to specify if and how the source colors should be blended with the colors in the destination area.
      void copy_from_screen(const xtd::drawing::point& upper_left_source, const xtd::drawing::point& upper_left_destination, const xtd::drawing::size& block_region_size, xtd::drawing::copy_pixel_operation copy_pixel_operation);
      /// @brief Performs a bit-block transfer of color data, corresponding to a rectangle of pixels, from the screen to the drawing surface of the xtd::drawing::graphics.
      /// @param source_x The x-coordinate of the point at the upper-left corner of the source rectangle.
      /// @param source_y The y-coordinate of the point at the upper-left corner of the source rectangle.
      /// @param destination_x The x-coordinate of the point at the upper-left corner of the destination rectangle.
      /// @param destination_y The y-coordinate of the point at the upper-left corner of the destination rectangle.
      /// @param block_region_size The size of the area to be transferred.
      /// @remarks The xtd::drawing::graphics::copy_from_screen methods are useful for layering one image on top of another. To specify how the source and destination colors are blended, use one of the xtd::drawing::graphics::copy_from_screen methods that takes a xtd::drawing::graphics::copy_pixel_operation parameter.
      void copy_from_screen(int32_t source_x, int32_t source_y, int32_t destination_x, int32_t destination_y, const xtd::drawing::size& block_region_size);
      /// @brief Performs a bit-block transfer of color data, corresponding to a rectangle of pixels, from the screen to the drawing surface of the xtd::drawing::graphics.
      /// @param source_x The x-coordinate of the point at the upper-left corner of the source rectangle.
      /// @param source_y The y-coordinate of the point at the upper-left corner of the source rectangle.
      /// @param destination_x The x-coordinate of the point at the upper-left corner of the destination rectangle.
      /// @param destination_y The y-coordinate of the point at the upper-left corner of the destination rectangle.
      /// @param block_region_size The size of the area to be transferred.
      /// @param copy_pixel_operation One of the xtd::drawing::graphics::copy_pixel_operation values.
      /// @remarks The xtd::drawing::graphics::copy_from_screen methods are useful for layering one image on top of another. The xtd::drawing::copy_pixel_operation parameter allows you to specify if and how the source colors should be blended with the colors in the destination area.
      void copy_from_screen(int32_t source_x, int32_t source_y, int32_t destination_x, int32_t destination_y, const xtd::drawing::size& block_region_size, xtd::drawing::copy_pixel_operation copy_pixel_operation);

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
      
      /// @brief Draws a series of Bézier splines from an array of xtd::drawing::point structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point structures that represent the points that determine the curve. The number of points in the array should be a multiple of 3 plus 1, such as 4, 7, or 10.
      /// @remarks The number of points in the array should be a multiple of 3 plus 1 because the first spline requires 4 points and any other splines require 3 points each. The first Bézier curve is drawn from the first point to the fourth point in the point array. The second and third points are control points that determine the shape of the curve. Each subsequent curve needs exactly three more points: two more control points and an ending point. The ending point of the previous curve is used as the starting point for each additional curve.
      void draw_beziers(const pen& pen, std::vector<xtd::drawing::point>& points);
      /// @brief Draws a series of Bézier splines from an array of xtd::drawing::point_f structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point_f structures that represent the points that determine the curve. The number of points in the array should be a multiple of 3 plus 1, such as 4, 7, or 10.
      /// @remarks The number of points in the array should be a multiple of 3 plus 1 because the first spline requires 4 points and any other splines require 3 points each. The first Bézier curve is drawn from the first point to the fourth point in the point array. The second and third points are control points that determine the shape of the curve. Each subsequent curve needs exactly three more points: two more control points and an ending point. The ending point of the previous curve is used as the starting point for each additional curve.
      void draw_beziers(const pen& pen, std::vector<xtd::drawing::point_f>& points);

      /// @brief Draws a closed cardinal spline defined by an array of xtd::drawing::point structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @remarks This method draws a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point structures.
      /// @remarks This method uses a default tension of 0.0.
      void draw_closed_curve(const pen& pen, std::vector<xtd::drawing::point>& points);
      /// @brief Draws a closed cardinal spline defined by an array of xtd::drawing::point_f structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @remarks This method draws a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point_f structures.
      /// @remarks This method uses a default tension of 0.0.
      void draw_closed_curve(const pen& pen, std::vector<xtd::drawing::point_f>& points);
      /// @brief Draws a closed cardinal spline defined by an array of xtd::drawing::point structures using a specified tension.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @param tension alue greater than or equal to 0.0F that specifies the tension of the curve.
      /// @remarks This method draws a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point structures.
      /// @remarks The tension parameter determines the shape of the spline. If the value of the tension parameter is 0.0F, this method draws straight line segments to connect the points. Usually, the tension parameter is less than or equal to 1.0F. Values over 1.0F produce unusual results.
      void draw_closed_curve(const pen& pen, std::vector<xtd::drawing::point>& points, float tension);
      /// @brief Draws a closed cardinal spline defined by an array of xtd::drawing::point_f structures using a specified tension.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @param tension alue greater than or equal to 0.0F that specifies the tension of the curve.
      /// @remarks This method draws a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point_f structures.
      /// @remarks The tension parameter determines the shape of the spline. If the value of the tension parameter is 0.0F, this method draws straight line segments to connect the points. Usually, the tension parameter is less than or equal to 1.0F. Values over 1.0F produce unusual results.
      void draw_closed_curve(const pen& pen, std::vector<xtd::drawing::point_f>& points, float tension);

      /// @brief Draws a cardinal spline through a specified array of xtd::drawing::point structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @remarks This method draws a cardinal spline that passes through each point in the array.
      /// @remarks The array of points must contain at least three PointF structures for a curve to be drawn.
      /// @remarks This method uses a default tension of 0.0.
      void draw_curve(const pen& pen, std::vector<xtd::drawing::point>& points);
      /// @brief Draws a cardinal spline through a specified array of xtd::drawing::point_f structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @remarks This method draws a cardinal spline that passes through each point in the array.
      /// @remarks The array of points must contain at least three PointF structures for a curve to be drawn.
      /// @remarks This method uses a default tension of 0.0.
      void draw_curve(const pen& pen, std::vector<xtd::drawing::point_f>& points);
      /// @brief Draws a cardinal spline through a specified array of xtd::drawing::point structures using a specified tension.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @param tension Value greater than or equal to 0.0F that specifies the tension of the curve.
      /// @remarks This method draws a cardinal spline that passes through each point in the array.
      /// @remarks The array of points must contain at least three xtd::drawing::point structures for a curve to be drawn.
      /// @remarks The tension parameter determines the shape of the spline. If the value of the tension parameter is 0.0F, this method draws straight line segments to connect the points. Usually, the tension parameter is less than or equal to 1.0F. Values over 1.0F produce unusual results.
      void draw_curve(const pen& pen, std::vector<xtd::drawing::point>& points, float tension);
      /// @brief Draws a cardinal spline through a specified array of xtd::drawing::point_f structures using a specified tension.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @param tension Value greater than or equal to 0.0F that specifies the tension of the curve.
      /// @remarks This method draws a cardinal spline that passes through each point in the array.
      /// @remarks The array of points must contain at least three xtd::drawing::point_f structures for a curve to be drawn.
      /// @remarks The tension parameter determines the shape of the spline. If the value of the tension parameter is 0.0F, this method draws straight line segments to connect the points. Usually, the tension parameter is less than or equal to 1.0F. Values over 1.0F produce unusual results.
      void draw_curve(const pen& pen, std::vector<xtd::drawing::point_f>& points, float tension);
      /// @brief Draws a cardinal spline through a specified array of xtd::drawing::point structures. The drawing begins offset from the beginning of the array.
      /// @brief Draws a cardinal spline through a specified array of xtd::drawing::point structures using a specified tension. The drawing begins offset from the beginning of the array.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @param offset Offset from the first element in the array of the points parameter to the starting point in the curve.
      /// @param number_of_segments Number of segments after the starting point to include in the curve.
      /// @remarks This method draws a cardinal spline that passes through each point in the array.
      /// @remarks The array of points must contain at least three xtd::drawing::point structures for curve to be drawn.
      /// @remarks The value of the offset parameter specifies the number of elements to skip in the array. The first element after the skipped elements represents the starting point of the curve.
      /// @remarks The value of the number_of_segments parameter specifies the number of segments, after the starting point, to draw in the curve. The value of the number_of_segments parameter must be at least 1. The value of the offset parameter plus the value of the number_of_segments parameter must be less than the number of elements in the array of the points parameter.
      /// @remarks This method uses a default tension of 0.0.
      void draw_curve(const pen& pen, std::vector<xtd::drawing::point>& points, size_t offset, size_t number_of_segments);
      /// @brief Draws a cardinal spline through a specified array of xtd::drawing::point_f structures. The drawing begins offset from the beginning of the array.
      /// @brief Draws a cardinal spline through a specified array of xtd::drawing::point structures using a specified tension. The drawing begins offset from the beginning of the array.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @param offset Offset from the first element in the array of the points parameter to the starting point in the curve.
      /// @param number_of_segments Number of segments after the starting point to include in the curve.
      /// @remarks This method draws a cardinal spline that passes through each point in the array.
      /// @remarks The array of points must contain at least three xtd::drawing::point_f structures for curve to be drawn.
      /// @remarks The value of the offset parameter specifies the number of elements to skip in the array. The first element after the skipped elements represents the starting point of the curve.
      /// @remarks The value of the number_of_segments parameter specifies the number of segments, after the starting point, to draw in the curve. The value of the number_of_segments parameter must be at least 1. The value of the offset parameter plus the value of the number_of_segments parameter must be less than the number of elements in the array of the points parameter.
      /// @remarks This method uses a default tension of 0.0.
      void draw_curve(const pen& pen, std::vector<xtd::drawing::point_f>& points, size_t offset, size_t number_of_segments);
      /// @brief Draws a cardinal spline through a specified array of xtd::drawing::point structures using a specified tension. The drawing begins offset from the beginning of the array.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @param offset Offset from the first element in the array of the points parameter to the starting point in the curve.
      /// @param number_of_segments Number of segments after the starting point to include in the curve.
      /// @param tension Value greater than or equal to 0.0F that specifies the tension of the curve.
      /// @remarks This method draws a cardinal spline that passes through each point in the array.
      /// @remarks The array of points must contain at least three xtd::drawing::point structures for curve to be drawn.
      /// @remarks The value of the offset parameter specifies the number of elements to skip in the array. The first element after the skipped elements represents the starting point of the curve.
      /// @remarks The value of the number_of_segments parameter specifies the number of segments, after the starting point, to draw in the curve. The value of the number_of_segments parameter must be at least 1. The value of the offset parameter plus the value of the number_of_segments parameter must be less than the number of elements in the array of the points parameter.
      /// @remarks The tension parameter determines the shape of the spline. If the value of the tension parameter is 0.0F, this method draws straight line segments to connect the points. Usually, the tension parameter is less than or equal to 1.0F. Values over 1.0F produce unusual results.
      void draw_curve(const pen& pen, std::vector<xtd::drawing::point>& points, size_t offset, size_t number_of_segments, float tension);
      /// @brief Draws a cardinal spline through a specified array of xtd::drawing::point_f structures using a specified tension. The drawing begins offset from the beginning of the array.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @param offset Offset from the first element in the array of the points parameter to the starting point in the curve.
      /// @param number_of_segments Number of segments after the starting point to include in the curve.
      /// @param tension Value greater than or equal to 0.0F that specifies the tension of the curve.
      /// @remarks This method draws a cardinal spline that passes through each point in the array.
      /// @remarks The array of points must contain at least three xtd::drawing::point_f structures for curve to be drawn.
      /// @remarks The value of the offset parameter specifies the number of elements to skip in the array. The first element after the skipped elements represents the starting point of the curve.
      /// @remarks The value of the number_of_segments parameter specifies the number of segments, after the starting point, to draw in the curve. The value of the number_of_segments parameter must be at least 1. The value of the offset parameter plus the value of the number_of_segments parameter must be less than the number of elements in the array of the points parameter.
      /// @remarks The tension parameter determines the shape of the spline. If the value of the tension parameter is 0.0F, this method draws straight line segments to connect the points. Usually, the tension parameter is less than or equal to 1.0F. Values over 1.0F produce unusual results.
      void draw_curve(const pen& pen, std::vector<xtd::drawing::point_f>& points, size_t offset, size_t number_of_segments, float tension);

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

      /// @brief Draws the specified xtd::drawing::image at the specified location and with the specified size.
      /// @param image xtd::drawing::image to draw.
      /// @param rect xtd::drawing::rectangle structure that specifies the location and size of the drawn image.
      /// @remarks The image represented by the image object is scaled to the dimensions of the rect rectangle.
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle& rect);
      /// @brief Draws the specified xtd::drawing::image at the specified location and with the specified size.
      /// @param image xtd::drawing::image to draw.
      /// @param rect xtd::drawing::rectangle_f structure that specifies the location and size of the drawn image.
      /// @remarks The image represented by the image object is scaled to the dimensions of the rect rectangle.
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle_f& rect);
      /// @brief Draws the specified xtd::drawing::image, using its original physical size, at the specified location.
      /// @param image xtd::drawing::image to draw.
      /// @param point xtd::drawing::point structure that represents the location of the upper-left corner of the drawn image.
      /// @remarks An xtd::drawing::image stores a value for pixel width and a value for horizontal resolution (dots per inch). The physical width, measured in inches, of an image is the pixel width divided by the horizontal resolution. For example, an image with a pixel width of 216 and a horizontal resolution of 72 dots per inch has a physical width of 3 inches. Similar remarks apply to pixel height and physical height.
      /// @remarks This method draws an image using its physical size, so the image will have its correct size in inches regardless of the resolution (dots per inch) of the display device. For example, suppose an image has a pixel width of 216 and a horizontal resolution of 72 dots per inch. If you call this method to draw that image on a device that has a resolution of 96 dots per inch, the pixel width of the rendered image will be (216/72)*96 = 288.
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::point& point);
      /// @brief Draws the specified xtd::drawing::image, using its original physical size, at the specified location.
      /// @param image xtd::drawing::image to draw.
      /// @param point xtd::drawing::point_f structure that represents the location of the upper-left corner of the drawn image.
      /// @remarks An xtd::drawing::image stores a value for pixel width and a value for horizontal resolution (dots per inch). The physical width, measured in inches, of an image is the pixel width divided by the horizontal resolution. For example, an image with a pixel width of 216 and a horizontal resolution of 72 dots per inch has a physical width of 3 inches. Similar remarks apply to pixel height and physical height.
      /// @remarks This method draws an image using its physical size, so the image will have its correct size in inches regardless of the resolution (dots per inch) of the display device. For example, suppose an image has a pixel width of 216 and a horizontal resolution of 72 dots per inch. If you call this method to draw that image on a device that has a resolution of 96 dots per inch, the pixel width of the rendered image will be (216/72)*96 = 288.
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::point_f& point);
      /// @brief Draws the specified xtd::drawing::image at the specified location and with the specified size.
      /// @param image xtd::drawing::image to draw.
      /// @param x The x-coordinate of the upper-left corner of the drawn image.
      /// @param y The y-coordinate of the upper-left corner of the drawn image.
      /// @param width Width of the drawn image.
      /// @param height Height of the drawn image.
      /// @remarks The rectangle defined by the x, y, width, and height parameters determines the position and size of the drawn image.
      void draw_image(const xtd::drawing::image& image, int32_t x, int32_t y, int32_t width, int32_t height);
      /// @brief Draws the specified xtd::drawing::image at the specified location and with the specified size.
      /// @param image xtd::drawing::image to draw.
      /// @param x The x-coordinate of the upper-left corner of the drawn image.
      /// @param y The y-coordinate of the upper-left corner of the drawn image.
      /// @param width Width of the drawn image.
      /// @param height Height of the drawn image.
      /// @remarks The rectangle defined by the x, y, width, and height parameters determines the position and size of the drawn image.
      void draw_image(const xtd::drawing::image& image, float x, float y, float width, float height);
      /// @brief Draws the specified xtd::drawing::image, using its original physical size, at the specified location.
      /// @param image xtd::drawing::image to draw.
      /// @param x The x-coordinate of the upper-left corner of the drawn image.
      /// @param y The y-coordinate of the upper-left corner of the drawn image.
      /// @remarks An xtd::drawing::image stores a value for pixel width and a value for horizontal resolution (dots per inch). The physical width, measured in inches, of an image is the pixel width divided by the horizontal resolution. For example, an image with a pixel width of 216 and a horizontal resolution of 72 dots per inch has a physical width of 3 inches. Similar remarks apply to pixel height and physical height.
      /// @remarks This method draws an image using its physical size, so the image will have its correct size in inches regardless of the resolution (dots per inch) of the display device. For example, suppose an image has a pixel width of 216 and a horizontal resolution of 72 dots per inch. If you call this method to draw that image on a device that has a resolution of 96 dots per inch, the pixel width of the rendered image will be (216/72)*96 = 288.
      void draw_image(const xtd::drawing::image& image, int32_t x, int32_t y);
      /// @brief Draws the specified xtd::drawing::image, using its original physical size, at the specified location.
      /// @param image xtd::drawing::image to draw.
      /// @param x The x-coordinate of the upper-left corner of the drawn image.
      /// @param y The y-coordinate of the upper-left corner of the drawn image.
      /// @remarks An xtd::drawing::image stores a value for pixel width and a value for horizontal resolution (dots per inch). The physical width, measured in inches, of an image is the pixel width divided by the horizontal resolution. For example, an image with a pixel width of 216 and a horizontal resolution of 72 dots per inch has a physical width of 3 inches. Similar remarks apply to pixel height and physical height.
      /// @remarks This method draws an image using its physical size, so the image will have its correct size in inches regardless of the resolution (dots per inch) of the display device. For example, suppose an image has a pixel width of 216 and a horizontal resolution of 72 dots per inch. If you call this method to draw that image on a device that has a resolution of 96 dots per inch, the pixel width of the rendered image will be (216/72)*96 = 288.
      void draw_image(const xtd::drawing::image& image, float x, float y);
      
      /// @brief Draws a specified image using its original physical size at a specified location.
      /// @param image xtd::drawing::image to draw.
      /// @param point xtd::drawing::point structure that specifies the upper-left corner of the drawn image.
      /// @remarks An xtd::drawing::image stores a value for pixel width and a value for horizontal resolution (dots per inch). The physical width, measured in inches, of an image is the pixel width divided by the horizontal resolution. For example, an image with a pixel width of 216 and a horizontal resolution of 72 dots per inch has a physical width of 3 inches. Similar remarks apply to pixel height and physical height.
      /// @remarks The xtd::drawing::graphics::draw_image_unscaled method draws an image using its physical size, so the image will have its correct size in inches regardless of the resolution (dots per inch) of the display device. For example, suppose an image has a pixel width of 216 and a horizontal resolution of 72 dots per inch. If you call xtd::drawing::graphics::draw_image_unscaled to draw that image on a device that has a resolution of 96 dots per inch, the pixel width of the rendered image will be (216/72)*96 = 288.
      void draw_image_unscaled(const xtd::drawing::image& image, const xtd::drawing::point& point);
      /// @brief Draws a specified image using its original physical size at a specified location.
      /// @param x The x-coordinate of the upper-left corner of the drawn image.
      /// @param y The y-coordinate of the upper-left corner of the drawn image.
      /// @param image xtd::drawing::image to draw.
      /// @remarks An xtd::drawing::image stores a value for pixel width and a value for horizontal resolution (dots per inch). The physical width, measured in inches, of an image is the pixel width divided by the horizontal resolution. For example, an image with a pixel width of 216 and a horizontal resolution of 72 dots per inch has a physical width of 3 inches. Similar remarks apply to pixel height and physical height.
      /// @remarks The xtd::drawing::graphics::draw_image_unscaled method draws an image using its physical size, so the image will have its correct size in inches regardless of the resolution (dots per inch) of the display device. For example, suppose an image has a pixel width of 216 and a horizontal resolution of 72 dots per inch. If you call xtd::drawing::graphics::draw_image_unscaled to draw that image on a device that has a resolution of 96 dots per inch, the pixel width of the rendered image will be (216/72)*96 = 288.
      void draw_image_unscaled(const xtd::drawing::image& image, int32_t x, int32_t y);
      /// @brief Draws a specified image using its original physical size at a specified location.
      /// @param image xtd::drawing::image to draw.
      /// @param rect Rectangle that specifies the upper-left corner of the drawn image. The xtd::drawing::rectangle::x and xtd::drawing::rectangle::y properties of the rectangle specify the upper-left corner. The xtd::drawing::rectangle::width and xtd::drawing::rectangle::height properties are ignored.
      /// @remarks An xtd::drawing::image stores a value for pixel width and a value for horizontal resolution (dots per inch). The physical width, measured in inches, of an image is the pixel width divided by the horizontal resolution. For example, an image with a pixel width of 216 and a horizontal resolution of 72 dots per inch has a physical width of 3 inches. Similar remarks apply to pixel height and physical height.
      /// @remarks The xtd::drawing::graphics::draw_image_unscaled method draws an image using its physical size, so the image will have its correct size in inches regardless of the resolution (dots per inch) of the display device. For example, suppose an image has a pixel width of 216 and a horizontal resolution of 72 dots per inch. If you call xtd::drawing::graphics::draw_image_unscaled to draw that image on a device that has a resolution of 96 dots per inch, the pixel width of the rendered image will be (216/72)*96 = 288.
      void draw_image_unscaled(const xtd::drawing::image& image, const xtd::drawing::rectangle& rect);
      /// @brief Draws a specified image using its original physical size at a specified location.
      /// @param image xtd::drawing::image to draw.
      /// @param x The x-coordinate of the upper-left corner of the drawn image.
      /// @param y The y-coordinate of the upper-left corner of the drawn image.
      /// @param width not used.
      /// @param height not used
      /// @remarks An xtd::drawing::image stores a value for pixel width and a value for horizontal resolution (dots per inch). The physical width, measured in inches, of an image is the pixel width divided by the horizontal resolution. For example, an image with a pixel width of 216 and a horizontal resolution of 72 dots per inch has a physical width of 3 inches. Similar remarks apply to pixel height and physical height.
      /// @remarks The xtd::drawing::graphics::draw_image_unscaled method draws an image using its physical size, so the image will have its correct size in inches regardless of the resolution (dots per inch) of the display device. For example, suppose an image has a pixel width of 216 and a horizontal resolution of 72 dots per inch. If you call xtd::drawing::graphics::draw_image_unscaled to draw that image on a device that has a resolution of 96 dots per inch, the pixel width of the rendered image will be (216/72)*96 = 288.
      void draw_image_unscaled(const xtd::drawing::image& image, int32_t x, int32_t y, int32_t width, int32_t height);

      /// @brief Draws the specified image without scaling and clips it, if necessary, to fit in the specified rectangle.
      /// @param image xtd::drawing::image to draw.
      /// @param rect The xtd::drawing::rectangle in which to draw the image.
      void draw_image_unscaled_and_clipped(const xtd::drawing::image& image, const xtd::drawing::rectangle& rect);

      /// @brief Draws a line connecting two xtd::drawing::point structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the line.
      /// @param pt1 xtd::drawing::point structure that represents the first point to connect.
      /// @param pt2 xtd::drawing::point structure that represents the second point to connect.
      void draw_line(const xtd::drawing::pen& pen, const xtd::drawing::point& pt1, const point& pt2);
      /// @brief Draws a line connecting two xtd::drawing::point_f structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the line.
      /// @param pt1 xtd::drawing::point_f structure that represents the first point to connect.
      /// @param pt2 xtd::drawing::point_f structure that represents the second point to connect.
      void draw_line(const xtd::drawing::pen& pen, const xtd::drawing::point_f& pt1, const point_f& pt2);
      /// @brief Draws a line connecting the two points specified by the coordinate pairs.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the line.
      /// @param x1 The x-coordinate of the first point.
      /// @param y1 The y-coordinate of the first point.
      /// @param x2 The x-coordinate of the second point.
      /// @param y2 The y-coordinate of the second point.
      /// @remarks This method draws a line connecting the two points specified by the x1, y1, x2, and y2 parameters.
      void draw_line(const xtd::drawing::pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2);
      /// @brief Draws a line connecting the two points specified by the coordinate pairs.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the line.
      /// @param x1 The x-coordinate of the first point.
      /// @param y1 The y-coordinate of the first point.
      /// @param x2 The x-coordinate of the second point.
      /// @param y2 The y-coordinate of the second point.
      /// @remarks This method draws a line connecting the two points specified by the x1, y1, x2, and y2 parameters.
      void draw_line(const xtd::drawing::pen& pen, float x1, float y1, float x2, float y2);

      /// @brief Draws a series of line segments that connect an array of xtd::drawing::point structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the line segments.
      /// @param points Array of xtd::drawing::point structures that represent the points to connect.
      /// @remarks This method draws a series of lines connecting an array of ending points. The first two points in the array specify the first line. Each additional point specifies the end of a line segment whose starting point is the ending point of the previous line segment.
      void draw_lines(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::point>& points);
      /// @brief Draws a series of line segments that connect an array of xtd::drawing::point_f structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the line segments.
      /// @param points Array of xtd::drawing::point_f structures that represent the points to connect.
      /// @remarks This method draws a series of lines connecting an array of ending points. The first two points in the array specify the first line. Each additional point specifies the end of a line segment whose starting point is the ending point of the previous line segment.
      void draw_lines(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::point_f>& points);

      /// @brief Draws a xtd::drawing::drawing2d::graphics_path.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the path.
      /// @param path xtd::drawing::drawing2d::graphics_path to draw.
      /// @remarks The current transformation in the graphic context is applied to the xtd::drawing::drawing2d::graphics_path before it is drawn.
      void draw_path(const xtd::drawing::pen& pen, const xtd::drawing::drawing2d::graphics_path& path);

      /// @brief Draws a pie shape defined by an ellipse specified by a xtd::drawing::rectangle structure and two radial lines.
      /// @param pen Pen that determines the color, width, and style of the pie shape.
      /// @param rect xtd::drawing::rectangle structure that represents the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param start_angle Angle measured in degrees clockwise from the x-axis to the first side of the pie shape.
      /// @param sweep_angle Angle measured in degrees clockwise from the startAngle parameter to the second side of the pie shape.
      /// @remarks This method draws a pie shape defined by an arc of an ellipse and the two radial lines that intersect with the endpoints of the arc. The ellipse is defined by the bounding rectangle. The pie shape consists of the two radial lines defined by the start_angle and sweep_angle parameters, and the arc between the intersections of those radial lines with the ellipse.
      /// @remarks If the sweep_angle parameter is greater than 360 degrees or less than -360 degrees, it is treated as if it were 360 degrees or -360 degrees, respectively.
      void draw_pie(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle);
      /// @brief Draws a pie shape defined by an ellipse specified by a xtd::drawing::rectangle_f structure and two radial lines.
      /// @param pen Pen that determines the color, width, and style of the pie shape.
      /// @param rect xtd::drawing::rectangle_f structure that represents the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param start_angle Angle measured in degrees clockwise from the x-axis to the first side of the pie shape.
      /// @param sweep_angle Angle measured in degrees clockwise from the startAngle parameter to the second side of the pie shape.
      /// @remarks This method draws a pie shape defined by an arc of an ellipse and the two radial lines that intersect with the endpoints of the arc. The ellipse is defined by the bounding rectangle. The pie shape consists of the two radial lines defined by the start_angle and sweep_angle parameters, and the arc between the intersections of those radial lines with the ellipse.
      /// @remarks If the sweep_angle parameter is greater than 360 degrees or less than -360 degrees, it is treated as if it were 360 degrees or -360 degrees, respectively.
      void draw_pie(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle);
      /// @brief Draws a pie shape defined by an ellipse specified by a coordinate pair, a width, a height, and two radial lines.
      /// @param pen Pen that determines the color, width, and style of the pie shape.
      /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param width Width of the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param heught Height of the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param start_angle Angle measured in degrees clockwise from the x-axis to the first side of the pie shape.
      /// @param sweep_angle Angle measured in degrees clockwise from the startAngle parameter to the second side of the pie shape.
      /// @remarks This method draws a pie shape defined by an arc of an ellipse and the two radial lines that intersect with the endpoints of the arc. The ellipse is defined by the bounding rectangle described by the x, y, width, and height parameters. The pie shape consists of the two radial lines defined by the start_angle and sweep_angle parameters, and the arc between the intersections of those radial lines with the ellipse.
      /// @remarks If the sweep_angle parameter is greater than 360 degrees or less than -360 degrees, it is treated as if it were 360 degrees or -360 degrees, respectively.
      void draw_pie(const xtd::drawing::pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle);
      /// @brief Draws a pie shape defined by an ellipse specified by a coordinate pair, a width, a height, and two radial lines.
      /// @param pen Pen that determines the color, width, and style of the pie shape.
      /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param width Width of the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param heught Height of the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param start_angle Angle measured in degrees clockwise from the x-axis to the first side of the pie shape.
      /// @param sweep_angle Angle measured in degrees clockwise from the startAngle parameter to the second side of the pie shape.
      /// @remarks This method draws a pie shape defined by an arc of an ellipse and the two radial lines that intersect with the endpoints of the arc. The ellipse is defined by the bounding rectangle described by the x, y, width, and height parameters. The pie shape consists of the two radial lines defined by the start_angle and sweep_angle parameters, and the arc between the intersections of those radial lines with the ellipse.
      /// @remarks If the sweep_angle parameter is greater than 360 degrees or less than -360 degrees, it is treated as if it were 360 degrees or -360 degrees, respectively.
      void draw_pie(const xtd::drawing::pen& pen, float x, float y, float width, float height, float start_angle, float sweep_angle);
      
      /// @brief Draws a polygon defined by an array of xtd::drawing::point structures.
      /// @param pen Pen that determines the color, width, and style of the polygon.
      /// @param points Array of xtd::drawing::point structures that represent the vertices of the polygon.
      /// @remarks Every pair of two consecutive points in the array specifies a side of the polygon. In addition, if the last point and the first of the array point do not coincide, they specify the last side of the polygon.
      void draw_polygon(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::point>& points);
      /// @brief Draws a polygon defined by an array of xtd::drawing::point_f structures.
      /// @param pen Pen that determines the color, width, and style of the polygon.
      /// @param points Array of xtd::drawing::point_f structures that represent the vertices of the polygon.
      /// @remarks Every pair of two consecutive points in the array specifies a side of the polygon. In addition, if the last point and the first of the array point do not coincide, they specify the last side of the polygon.
      void draw_polygon(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::point_f>& points);

      /// @brief Draws a point specified by the coordinate pairs.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the point.
      /// @param point xtd::drawing::point structure that represents the point.
      void draw_point(const xtd::drawing::pen& pen, const xtd::drawing::point& point);
      /// @brief Draws a point specified by the coordinate pairs.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the point.
      /// @param point xtd::drawing::point_f structure that represents the point.
      void draw_point(const xtd::drawing::pen& pen, const xtd::drawing::point_f& point);
      /// @brief Draws a point specified by the coordinate pairs.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the point.
      /// @param x1 The x-coordinate of the point.
      /// @param y1 The y-coordinate of the point.
      void draw_point(const xtd::drawing::pen& pen, int32_t x, int32_t y);
      /// @brief Draws a point specified by the coordinate pairs.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the point.
      /// @param x1 The x-coordinate of the point.
      /// @param y1 The y-coordinate of the point.
      void draw_point(const xtd::drawing::pen& pen, float x, float y);
      
      /// @brief Draws a rectangle specified by a xtd::drawing::rectangle structure.
      /// @param pen A xtd::drawing::pen that determines the color, width, and style of the rectangle.
      /// @param rect A xtd::drawing::rectangle structure that represents the rectangle to draw.
      void draw_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect);
      /// @brief Draws a rectangle specified by a xtd::drawing::rectangle_f structure.
      /// @param pen A xtd::drawing::pen that determines the color, width, and style of the rectangle.
      /// @param rect A xtd::drawing::rectangle_f structure that represents the rectangle to draw.
      void draw_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect);
      /// @brief Draws a rectangle specified by a coordinate pair, a width, and a height.
      /// @param pen A xtd::drawing::pen that determines the color, width, and style of the rectangle.
      /// @param x The x-coordinate of the upper-left corner of the rectangle to draw.
      /// @param y The y-coordinate of the upper-left corner of the rectangle to draw.
      /// @param width The width of the rectangle to draw.
      /// @param height The height of the rectangle to draw.
      void draw_rectangle(const xtd::drawing::pen& pen, int32_t x, int32_t y, int32_t width, int32_t height);
      /// @brief Draws a rectangle specified by a coordinate pair, a width, and a height.
      /// @param pen A xtd::drawing::pen that determines the color, width, and style of the rectangle.
      /// @param x The x-coordinate of the upper-left corner of the rectangle to draw.
      /// @param y The y-coordinate of the upper-left corner of the rectangle to draw.
      /// @param width The width of the rectangle to draw.
      /// @param height The height of the rectangle to draw.
      void draw_rectangle(const xtd::drawing::pen& pen, float x, float y, float width, float height);
  
      /// @brief Draws a series of rectangles specified by xtd::drawing::rectangle structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the outlines of the rectangles.
      /// @param rects Array of xtd::drawing::rectangle structures that represent the rectangles to draw.
      void draw_rectangles(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::rectangle>& rects);
      /// @brief Draws a series of rectangles specified by xtd::drawing::rectangle_f structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the outlines of the rectangles.
      /// @param rects Array of xtd::drawing::rectangle_f structures that represent the rectangles to draw.
      void draw_rectangles(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::rectangle_f>& rects);

      /// @brief Draws a rounded rectangle specified by a xtd::drawing::rectangle structure, and radius.
      /// @param pen A xtd::drawing::pen that determines the color, width, and style of the rounded rectangle.
      /// @param rect A xtd::drawing::rectangle structure that represents the rounded rectangle to draw.
      /// @param radius The radius of the rounded rectange angles.
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, int32_t radius);
      /// @brief Draws a rounded rectangle specified by a xtd::drawing::rectangle_f structure, and radius.
      /// @param pen A xtd::drawing::pen that determines the color, width, and style of the rounded rectangle.
      /// @param rect A xtd::drawing::rectangle_f structure that represents the rounded rectangle to draw.
      /// @param radius The radius of the rounded rectange angles.
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float radius);
      /// @brief Draws a rounded rectangle specified by a coordinate pair, a width, and a height, and radius.
      /// @param pen A xtd::drawing::pen that determines the color, width, and style of the rounded rectangle.
      /// @param x The x-coordinate of the upper-left corner of the rounded rectangle to draw.
      /// @param y The y-coordinate of the upper-left corner of the rounded rectangle to draw.
      /// @param width The width of the rounded rectangle to draw.
      /// @param height The height of the rounded rectangle to draw.
      /// @param radius The radius of the rounded rectange angles.
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius);
      /// @brief Draws a rounded rectangle specified by a coordinate pair, a width, a height, and radius.
      /// @param pen A xtd::drawing::pen that determines the color, width, and style of the rounded rectangle.
      /// @param x The x-coordinate of the upper-left corner of the rounded rectangle to draw.
      /// @param y The y-coordinate of the upper-left corner of the rounded rectangle to draw.
      /// @param width The width of the rounded rectangle to draw.
      /// @param height The height of the rounded rectangle to draw.
      /// @param radius The radius of the rounded rectange angles.
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, float x, float y, float width, float height, float radius);
      
      /// @brief Draws the specified text string at the specified rectangle with the specified xtd::drawing::brush and xtd::drawing::font objects using the formatting attributes of the specified xtd::drawing::string_format.
      /// @param s String to draw.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param brush xtd::drawing::brush that determines the color and texture of the drawn text.
      /// @param layout_rectangle xtd::drawing::rectangle_f structure that specifies the location of the drawn text.
      /// @param format xtd::drawing::string_format that specifies formatting attributes, such as line spacing and alignment, that are applied to the drawn text.
      /// @remarks The text represented by the s parameter is drawn inside the rectangle represented by the layout_rectangle parameter. If the text does not fit inside the rectangle, it is truncated at the nearest word, unless otherwise specified with the format parameter.
      void draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& layout_rectangle, const xtd::drawing::string_format& format);
      /// @brief Draws the specified text string at the specified rectangle with the specified xtd::drawing::brush and xtd::drawing::font objects.
      /// @param s String to draw.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param brush xtd::drawing::brush that determines the color and texture of the drawn text.
      /// @param layout_rectangle xtd::drawing::rectangle_f structure that specifies the location of the drawn text.
      /// @remarks The text represented by the s parameter is drawn inside the rectangle represented by the layout_rectangle parameter. If the text does not fit inside the rectangle, it is truncated at the nearest word. To further manipulate how the string is drawn inside the rectangle use the xtd::drawing::graphics::draw_string overload that takes a xtd::drawing::string_format.
      void draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& layout_rectangle);
      /// @brief Draws the specified text string at the specified location with the specified xtd::drawing::brush and xtd::drawing::font objects using the formatting attributes of the specified xtd::drawing::string_format.
      /// @param s String to draw.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param brush xtd::drawing::brush that determines the color and texture of the drawn text.
      /// @param point xtd::drawing::point_f structure that specifies the upper-left corner of the drawn text.
      /// @param format xtd::drawing::string_format that specifies formatting attributes, such as line spacing and alignment, that are applied to the drawn text.
      void draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point, const xtd::drawing::string_format& format);
      /// @brief Draws the specified text string at the specified location with the specified xtd::drawing::brush and xtd::drawing::font objects.
      /// @param s String to draw.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param brush xtd::drawing::brush that determines the color and texture of the drawn text.
      /// @param point xtd::drawing::point_f structure that specifies the upper-left corner of the drawn text.
      void draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point);
      /// @brief Draws the specified text string at the specified location with the specified xtd::drawing::brush and xtd::drawing::font objects using the formatting attributes of the specified xtd::drawing::string_format.
      /// @param s String to draw.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param brush xtd::drawing::brush that determines the color and texture of the drawn text.
      /// @param x The x-coordinate of the upper-left corner of the drawn text.
      /// @param y The y-coordinate of the upper-left corner of the drawn text.
      /// @param format xtd::drawing::string_format that specifies formatting attributes, such as line spacing and alignment, that are applied to the drawn text.
      void draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, float x, float y, const xtd::drawing::string_format& format);
      /// @brief Draws the specified text string at the specified location with the specified xtd::drawing::brush and xtd::drawing::font objects.
      /// @param s String to draw.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param brush xtd::drawing::brush that determines the color and texture of the drawn text.
      /// @param x The x-coordinate of the upper-left corner of the drawn text.
      /// @param y The y-coordinate of the upper-left corner of the drawn text.
      void draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, float x, float y);
      
      /// @brief Updates the clip region of this xtd::drawing::graphics to exclude the area specified by a xtd::drawing::region.
      /// @param region xtd::drawing::region that specifies the region to exclude from the clip region.
      /// @remarks This method excludes the area specified by the region parameter from the current clip region and assigns the resulting area to the xtd::drawing::graphics::clip property of this xtd::drawing::graphics.
      void exclude_clip(const xtd::drawing::region& region);
      /// @brief Updates the clip region of this xtd::drawing::graphics to exclude the area specified by a xtd::drawing::rectangle.
      /// @param rect xtd::drawing::rectangle that specifies the rectangle to exclude from the clip region.
      /// @remarks This method excludes the area specified by the rect parameter from the current clip region and assigns the resulting area to the xtd::drawing::graphics::clip property of this xtd::drawing::graphics.
      void exclude_clip(const xtd::drawing::rectangle& rect);
      
      /// @brief Fills the interior of a closed cardinal spline curve defined by an array of xtd::drawing::point structures.
      /// @param brush A xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @remarks This method fills the interior of a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point structures.
      /// @remarks This method uses a default tension of 0.0.
      void fill_closed_curve(const xtd::drawing::brush& brush, std::vector<xtd::drawing::point>& points);
      /// @brief Fills the interior of a closed cardinal spline curve defined by an array of xtd::drawing::point_f structures.
      /// @param brush A xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @remarks This method fills the interior of a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point_f structures.
      /// @remarks This method uses a default tension of 0.0.
      void fill_closed_curve(const xtd::drawing::brush& brush, std::vector<xtd::drawing::point_f>& points);
      /// @brief Fills the interior of a closed cardinal spline curve defined by an array of xtd::drawing::point structures using the specified fill mode.
      /// @param brush A xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @param fill_mode Member of the xtd::drawing::drawing2d::fill_mode enumeration that determines how the curve is filled.
      /// @remarks This method fills the interior of a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point structures.
      /// @remarks This method uses a default tension of 0.0.
      void fill_closed_curve(const xtd::drawing::brush& brush, std::vector<xtd::drawing::point>& points, xtd::drawing::drawing2d::fill_mode fill_mode);
      /// @brief Fills the interior of a closed cardinal spline curve defined by an array of xtd::drawing::point_f structures using the specified fill mode.
      /// @param brush A xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @param fill_mode Member of the xtd::drawing::drawing2d::fill_mode enumeration that determines how the curve is filled.
      /// @remarks This method fills the interior of a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point_f structures.
      /// @remarks This method uses a default tension of 0.0.
      void fill_closed_curve(const xtd::drawing::brush& brush, std::vector<xtd::drawing::point_f>& points, xtd::drawing::drawing2d::fill_mode fill_mode);
      /// @brief Fills the interior of a closed cardinal spline curve defined by an array of xtd::drawing::point structures using the specified fill mode and tension.
      /// @param brush A xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @param fill_mode Member of the xtd::drawing::drawing2d::fill_mode enumeration that determines how the curve is filled.
      /// @param tension Value greater than or equal to 0.0F that specifies the tension of the curve.
      /// @remarks This method fills the interior of a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point structures.
      /// @remarks The tension parameter determines the shape of the spline. If the value of the tension parameter is 0.0F, this method draws straight line segments to connect the points. Usually, the tension parameter is less than or equal to 1.0F. Values over 1.0F produce unusual results.
      void fill_closed_curve(const xtd::drawing::brush& brush, std::vector<xtd::drawing::point>& points, xtd::drawing::drawing2d::fill_mode fill_mode, float tension);
      /// @brief Fills the interior of a closed cardinal spline curve defined by an array of xtd::drawing::point_f structures using the specified fill mode and tension.
      /// @param brush A xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @param fill_mode Member of the xtd::drawing::drawing2d::fill_mode enumeration that determines how the curve is filled.
      /// @param tension Value greater than or equal to 0.0F that specifies the tension of the curve.
      /// @remarks This method fills the interior of a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point_f structures.
      /// @remarks The tension parameter determines the shape of the spline. If the value of the tension parameter is 0.0F, this method draws straight line segments to connect the points. Usually, the tension parameter is less than or equal to 1.0F. Values over 1.0F produce unusual results.
      void fill_closed_curve(const xtd::drawing::brush& brush, std::vector<xtd::drawing::point_f>& points, xtd::drawing::drawing2d::fill_mode fill_mode, float tension);

      /// @brief Fills the interior of an ellipse defined by a bounding rectangle specified by a xtd::drawing::rectangle structure.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param rect xtd::drawing::rectangle structure that represents the bounding rectangle that defines the ellipse.
      /// @remarks This method fills the interior of an ellipse with a xtd::drawing::brush. The ellipse is defined by the bounding rectangle represented by the rect parameter.
      void fill_ellipse(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect);
      /// @brief Fills the interior of an ellipse defined by a bounding rectangle specified by a xtd::drawing::rectangle_f structure.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param rect xtd::drawing::rectangle_f structure that represents the bounding rectangle that defines the ellipse.
      /// @remarks This method fills the interior of an ellipse with a xtd::drawing::brush. The ellipse is defined by the bounding rectangle represented by the rect parameter.
      void fill_ellipse(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect);
      /// @brief Fills the interior of an ellipse defined by a bounding rectangle specified by a pair of coordinates, a width, and a height.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
      /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
      /// @param width Width of the bounding rectangle that defines the ellipse.
      /// @param height Height of the bounding rectangle that defines the ellipse.
      /// @remarks This method fills the interior of an ellipse with a xtd::drawing::brush. The ellipse is defined by the bounding rectangle represented by the x, y, width, and height parameters.
      void fill_ellipse(const xtd::drawing::brush& brush, int32_t x, int32_t y, int32_t width, int32_t height);
      /// @brief Fills the interior of an ellipse defined by a bounding rectangle specified by a pair of coordinates, a width, and a height.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
      /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
      /// @param width Width of the bounding rectangle that defines the ellipse.
      /// @param height Height of the bounding rectangle that defines the ellipse.
      /// @remarks This method fills the interior of an ellipse with a xtd::drawing::brush. The ellipse is defined by the bounding rectangle represented by the x, y, width, and height parameters.
      void fill_ellipse(const xtd::drawing::brush& brush, float x, float y, float width, float height);
      
      /// @brief Fills the interior of a xtd::drawing::drawing2d::graphics_path.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param path xtd::drawing::drawing2d::graphics_path that represents the path to fill.
      /// @remarks A xtd::drawing::drawing2d::graphics_path consists of a series of line and curve segments. If the path represented by the path parameter is not closed, an additional segment is added from the last point to the first point to close the path.
      void fill_path(const xtd::drawing::brush& brush, const xtd::drawing::drawing2d::graphics_path& path);
      
      /// @brief Fills the interior of a pie section defined by an ellipse specified by a xtd::drawing::rectangle structure and two radial lines.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param rect xtd::drawing::rectangle structure that represents the bounding rectangle that defines the ellipse from which the pie section comes.
      /// @param start_angle Angle in degrees measured clockwise from the x-axis to the first side of the pie section.
      /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to the second side of the pie section.
      /// @remarks This method fills the interior of a pie section defined by an arc of an ellipse and the two radial lines that intersect with the endpoints of the arc. The ellipse is defined by the bounding rectangle. The pie section consists of the two radial lines defined by the start_angle and sweep_angle parameters, and the arc between the intersections of those radial lines with the ellipse.
      /// @remarks If the sweep_angle parameter is greater than 360 degrees or less than -360 degrees, it is treated as if it were 360 degrees or -360 degrees, respectively.
      void fill_pie(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle);
      /// @brief Fills the interior of a pie section defined by an ellipse specified by a xtd::drawing::rectangle_f structure and two radial lines.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param rect xtd::drawing::rectangle_f structure that represents the bounding rectangle that defines the ellipse from which the pie section comes.
      /// @param start_angle Angle in degrees measured clockwise from the x-axis to the first side of the pie section.
      /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to the second side of the pie section.
      /// @remarks This method fills the interior of a pie section defined by an arc of an ellipse and the two radial lines that intersect with the endpoints of the arc. The ellipse is defined by the bounding rectangle. The pie section consists of the two radial lines defined by the start_angle and sweep_angle parameters, and the arc between the intersections of those radial lines with the ellipse.
      /// @remarks If the sweep_angle parameter is greater than 360 degrees or less than -360 degrees, it is treated as if it were 360 degrees or -360 degrees, respectively.
      void fill_pie(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle);
      /// @brief Fills the interior of a pie section defined by an ellipse specified by a pair of coordinates, a width, a height, and two radial lines.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie section comes.
      /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie section comes.
      /// @param width Width of the bounding rectangle that defines the ellipse from which the pie section comes.
      /// @param height Height of the bounding rectangle that defines the ellipse from which the pie section comes.
      /// @param start_angle Angle in degrees measured clockwise from the x-axis to the first side of the pie section.
      /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to the second side of the pie section.
      /// @remarks This method fills the interior of a pie section defined by an arc of an ellipse and the two radial lines that intersect with the endpoints of the arc. The ellipse is defined by the bounding rectangle. The pie section consists of the two radial lines defined by the start_angle and sweep_angle parameters, and the arc between the intersections of those radial lines with the ellipse.
      /// @remarks If the sweep_angle parameter is greater than 360 degrees or less than -360 degrees, it is treated as if it were 360 degrees or -360 degrees, respectively.
      void fill_pie(const xtd::drawing::brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle);
      /// @brief Fills the interior of a pie section defined by an ellipse specified by a pair of coordinates, a width, a height, and two radial lines.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie section comes.
      /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie section comes.
      /// @param width Width of the bounding rectangle that defines the ellipse from which the pie section comes.
      /// @param height Height of the bounding rectangle that defines the ellipse from which the pie section comes.
      /// @param start_angle Angle in degrees measured clockwise from the x-axis to the first side of the pie section.
      /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to the second side of the pie section.
      /// @remarks This method fills the interior of a pie section defined by an arc of an ellipse and the two radial lines that intersect with the endpoints of the arc. The ellipse is defined by the bounding rectangle. The pie section consists of the two radial lines defined by the start_angle and sweep_angle parameters, and the arc between the intersections of those radial lines with the ellipse.
      /// @remarks If the sweep_angle parameter is greater than 360 degrees or less than -360 degrees, it is treated as if it were 360 degrees or -360 degrees, respectively.
      void fill_pie(const xtd::drawing::brush& brush, float x, float y, float width, float height, float start_angle, float sweep_angle);

      /// @brief Fills the interior of a polygon defined by an array of points specified by xtd::drawing::point structures.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point structures that represent the vertices of the polygon to fill.
      /// @remarks Every two consecutive points in the array specify a side of the polygon. In addition, if the last point and the first point do not coincide, they specify the closing side of the polygon.
      void fill_polygon(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point>& points);
      /// @brief Fills the interior of a polygon defined by an array of points specified by xtd::drawing::point_f structures.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point_f structures that represent the vertices of the polygon to fill.
      /// @remarks Every two consecutive points in the array specify a side of the polygon. In addition, if the last point and the first point do not coincide, they specify the closing side of the polygon.
      void fill_polygon(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point_f>& points);
      /// @brief Fills the interior of a polygon defined by an array of points specified by xtd::drawing::point structures using the specified fill mode.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point structures that represent the vertices of the polygon to fill.
      /// @param fill_mode Member of the xtd::drawing::drawing2d::fill_mode enumeration that determines the style of the fill.
      /// @remarks Every two consecutive points in the array specify a side of the polygon. In addition, if the last point and the first point do not coincide, they specify the closing side of the polygon.
      void fill_polygon(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point>& points, xtd::drawing::drawing2d::fill_mode fill_mode);
      /// @brief Fills the interior of a polygon defined by an array of points specified by xtd::drawing::point_f structures using the specified fill mode.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point_f structures that represent the vertices of the polygon to fill.
      /// @param fill_mode Member of the xtd::drawing::drawing2d::fill_mode enumeration that determines the style of the fill.
      /// @remarks Every two consecutive points in the array specify a side of the polygon. In addition, if the last point and the first point do not coincide, they specify the closing side of the polygon.
      void fill_polygon(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point_f>& points, xtd::drawing::drawing2d::fill_mode fill_mode);

      /// @brief Fills the interior of a rectangle specified by a xtd::drawing::rectangle structure.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param rect xtd::drawing::rectangle structure that represents the rectangle to fill.
      /// @remarks This method fills the interior of the rectangle defined by the rect parameter, including the specified upper-left corner and up to the calculated lower and bottom edges.
      void fill_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect);
      /// @brief Fills the interior of a rectangle specified by a xtd::drawing::rectangle_f structure.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param rect xtd::drawing::rectangle_f structure that represents the rectangle to fill.
      /// @remarks This method fills the interior of the rectangle defined by the rect parameter, including the specified upper-left corner and up to the calculated lower and bottom edges.
      void fill_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect);
      /// @brief Fills the interior of a rectangle specified by a pair of coordinates, a width, and a height.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param x The x-coordinate of the upper-left corner of the rectangle to fill.
      /// @param y The y-coordinate of the upper-left corner of the rectangle to fill.
      /// @param width Width of the rectangle to fill.
      /// @param height Height of the rectangle to fill.
      /// @remarks This method fills the interior of the rectangle defined by the x, y, width, and height parameters, including the specified upper-left corner and up to the calculated lower and bottom edges.
      void fill_rectangle(const xtd::drawing::brush& brush, int32_t x, int32_t y, int32_t width, int32_t height);
      /// @brief Fills the interior of a rectangle specified by a pair of coordinates, a width, and a height.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param x The x-coordinate of the upper-left corner of the rectangle to fill.
      /// @param y The y-coordinate of the upper-left corner of the rectangle to fill.
      /// @param width Width of the rectangle to fill.
      /// @param height Height of the rectangle to fill.
      /// @remarks This method fills the interior of the rectangle defined by the x, y, width, and height parameters, including the specified upper-left corner and up to the calculated lower and bottom edges.
      void fill_rectangle(const xtd::drawing::brush& brush, float x, float y, float width, float height);

      /// @brief Fills the interiors of a series of rectangles specified by xtd::drawing::rectangle structures.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param rects Array of xtd::drawing::rectangle structures that represent the rectangles to fill.
      void fill_rectangles(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::rectangle>& rects);
      /// @brief Fills the interiors of a series of rectangles specified by xtd::drawing::rectangle_f structures.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param rects Array of xtd::drawing::rectangle_f structures that represent the rectangles to fill.
      void fill_rectangles(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::rectangle_f>& rects);

      /// @brief Fills the interior of a xtd::drawing::region.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param region xtd::drawing::region that represents the area to fill.
      /// @remarks A xtd::drawing::region is composed of rectangles and paths. If the region is not closed, an additional segment is added from the last point to the first point to close it.
      void fill_region(const xtd::drawing::brush& brush, const xtd::drawing::region& region);

      /// @brief Fills the interior of a rounded rectangle specified by a xtd::drawing::rectangle structure.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param rect xtd::drawing::rectangle structure that represents the rounded rectangle to fill.
      /// @param radius The radius of the rounded rectange angles.
      /// @remarks This method fills the interior of the rounded rectangle defined by the rect, and radius parameters, including the specified upper-left corner and up to the calculated lower and bottom edges.
      void fill_rounded_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect, int32_t radius);
      /// @brief Fills the interior of a rounded rectangle specified by a xtd::drawing::rectangle_f structure.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param rect xtd::drawing::rectangle_f structure that represents the rounded rectangle to fill.
      /// @param radius The radius of the rounded rectange angles.
      /// @remarks This method fills the interior of the rounded rectangle defined by the rect, and radius parameters, including the specified upper-left corner and up to the calculated lower and bottom edges.
      void fill_rounded_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect, float radius);
      /// @brief Fills the interior of a rounded rectangle specified by a pair of coordinates, a width, a height, and a radius.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param x The x-coordinate of the upper-left corner of the rounded rectangle to fill.
      /// @param y The y-coordinate of the upper-left corner of the rounded rectangle to fill.
      /// @param width Width of the rounded rectangle to fill.
      /// @param height Height of the rounded rectangle to fill.
      /// @param radius The radius of the rounded rectange angles.
      /// @remarks This method fills the interior of the rounded rectangle defined by the x, y, width, height, and radius parameters, including the specified upper-left corner and up to the calculated lower and bottom edges.
      void fill_rounded_rectangle(const xtd::drawing::brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius);
      /// @brief Fills the interior of a rounded rectangle specified by a pair of coordinates, a width, a height, and a radius.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param x The x-coordinate of the upper-left corner of the rounded rectangle to fill.
      /// @param y The y-coordinate of the upper-left corner of the rounded rectangle to fill.
      /// @param width Width of the rounded rectangle to fill.
      /// @param height Height of the rounded rectangle to fill.
      /// @param radius The radius of the rounded rectange angles.
      /// @remarks This method fills the interior of the rounded rectangle defined by the x, y, width, height, and radius parameters, including the specified upper-left corner and up to the calculated lower and bottom edges.
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
      friend xtd::drawing::image;
      float to_page_unit(float value) const;
      static float to_page_unit(float value, xtd::drawing::graphics_unit page_unit, float page_scale, float dpi);
      float to_pixels(float value) const;
      static float to_pixels(float value, xtd::drawing::graphics_unit page_unit, float page_scale, float dpi);
      friend xtd::drawing::font;
      friend xtd::forms::control;
      friend xtd::forms::control_paint;
      friend xtd::forms::paint_event_args;
      friend xtd::forms::screen;
      
      explicit graphics(intptr_t handle) {data_->handle = handle;}
      void draw_image_disabled(const xtd::drawing::image& image, float x, float y, float brightness);
      
      struct data {
        xtd::drawing::region clip;
        xtd::drawing::drawing2d::compositing_mode compositing_mode = xtd::drawing::drawing2d::compositing_mode::source_over;
        xtd::drawing::drawing2d::compositing_quality compositing_quality = xtd::drawing::drawing2d::compositing_quality::default_value;
        intptr_t handle = 0;
        xtd::drawing::drawing2d::interpolation_mode interpolation_mode = xtd::drawing::drawing2d::interpolation_mode::default_value;
        float page_scale = 1.0f;
        xtd::drawing::graphics_unit page_unit = xtd::drawing::graphics_unit::pixel;
        xtd::drawing::drawing2d::pixel_offset_mode pixel_offset_mode = xtd::drawing::drawing2d::pixel_offset_mode::default_value;
        xtd::drawing::drawing2d::smoothing_mode smoothing_mode = xtd::drawing::drawing2d::smoothing_mode::default_value;
        xtd::drawing::text::text_rendering_hint text_rendering_hint = xtd::drawing::text::text_rendering_hint::system_default;
        int text_contrast = 4;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}

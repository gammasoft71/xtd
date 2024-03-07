/// @file
/// @brief Contains xtd::drawing::graphics class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "drawing_2d/compositing_mode.h"
#include "drawing_2d/compositing_quality.h"
#include "drawing_2d/flush_intention.h"
#include "drawing_2d/interpolation_mode.h"
#include "drawing_2d/graphics_path.h"
#include "drawing_2d/graphics_state.h"
#include "drawing_2d/matrix.h"
#include "drawing_2d/matrix_order.h"
#include "drawing_2d/pixel_offset_mode.h"
#include "drawing_2d/smoothing_mode.h"
#include "text/text_rendering_hint.h"
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
#include <xtd/object>
#include <xtd/ustring>
#include <cstdint>
#include <limits>
#include <ostream>


/// @cond
namespace xtd {
  namespace forms {
    class control;
    class control_paint;
    class paint_event_args;
    class region;
    class screen;
  }
}
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
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
      struct data;
      
    public:
      /// @cond
      graphics(const graphics& value);
      graphics& operator =(const graphics& value);
      ~graphics();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a xtd::drawing::region that limits the drawing region of this xtd::drawing::graphics.
      /// @return A xtd::drawing::region that limits the portion of this xtd::drawing::graphics that is currently available for drawing.
      /// @remarks Modifying the xtd::drawing::region object returned by the xtd::drawing::graphics::clip property does not affect subsequent drawing with the xtd::drawing::graphics object. To change the clip region, replace the xtd::drawing::graphics::clip property value with a new xtd::drawing::region object. To determine whether the clipping region is infinite, retrieve the xtd::drawing::graphics::clip property and call its xtd::drawing::region::is_infinite method.
      xtd::drawing::region clip() const noexcept;
      /// @brief Sets a xtd::drawing::region that limits the drawing region of this xtd::drawing::graphics.
      /// @param value A xtd::drawing::region that limits the portion of this xtd::drawing::graphics that is currently available for drawing.
      /// @return This current instance.
      /// @remarks Modifying the xtd::drawing::region object returned by the xtd::drawing::graphics::clip property does not affect subsequent drawing with the xtd::drawing::graphics object. To change the clip region, replace the xtd::drawing::graphics::clip property value with a new xtd::drawing::region object. To determine whether the clipping region is infinite, retrieve the xtd::drawing::graphics::clip property and call its xtd::drawing::region::is_infinite method.
      graphics& clip(const xtd::drawing::region value);
      
      /// @brief Gets a xtd::drawing::rectangle_f structure that bounds the clipping region of this xtd::drawing::graphics.
      /// @return A xtd::drawing::rectangle_f structure that represents a bounding rectangle for the clipping region of this xtd::drawing::graphics.
      /// @remarks The unit for resulting rectangle is designated by the xtd::drawing::graphics::page_unit property. The default unit is pixels. A xtd::drawing::graphics is typically associated with a control and the origin of the rectangle will be relative to the client area of that control.
      /// @remarks If the clipping region is infinite, the xtd::drawing::graphics::clip_bounds property returns a meaningless large rectangle. To determine whether the clipping region is infinite, retrieve the xtd::drawing::graphics::clip property and call its xtd::drawing::region::is_infinite method.
      xtd::drawing::rectangle_f clip_bounds() const noexcept;
      
      /// @brief Gets a value that specifies how composited images are drawn to this xtd::drawing::graphics.
      /// @return This property specifies a member of the xtd::drawing::drawing_2d::compositing_mode enumeration. The default is xtd::drawing::drawing_2d::compositing_mode::source_over.
      /// @remarks The compositing mode determines whether pixels from a source image overwrite or are combined with background pixels.
      /// @note You should not use a xtd::drawing::graphics::compositing_mode property value of xtd::drawing::graphics::source_copy when the xtd::drawing::graphics::text_rendering_hint property is set to xtd::drawing::graphics::text_rendering_hint::clear_type_grid_fit. An exception could occur or the image may not render correctly.
      xtd::drawing::drawing_2d::compositing_mode compositing_mode() const noexcept;
      /// @brief Sets a value that specifies how composited images are drawn to this xtd::drawing::graphics.
      /// @param value This property specifies a member of the CompositingMode enumeration. The default is SourceOver.
      /// @return This current instance.
      /// @remarks The compositing mode determines whether pixels from a source image overwrite or are combined with background pixels.
      /// @note You should not use a xtd::drawing::graphics::compositing_mode property value of xtd::drawing::graphics::source_copy when the xtd::drawing::graphics::text_rendering_hint property is set to xtd::drawing::graphics::text_rendering_hint::clear_type_grid_fit. An exception could occur or the image may not render correctly.
      graphics& compositing_mode(xtd::drawing::drawing_2d::compositing_mode value);
      
      /// @brief Gets the rendering quality of composited images drawn to this xtd::drawing::graphics.
      /// @return This property specifies a member of the xtd::drawing::drawing_2d::compositing_quality enumeration. The xtd::drawing::drawing_2d::compositing_quality::default_value is Default.
      /// @remarks The compositing quality determines the rendering quality level of composited images.
      xtd::drawing::drawing_2d::compositing_quality compositing_quality() const noexcept;
      /// @brief Sets the rendering quality of composited images drawn to this xtd::drawing::graphics.
      /// @param value This property specifies a member of the xtd::drawing::drawing_2d::compositing_quality enumeration. The xtd::drawing::drawing_2d::compositing_quality::default_value is Default.
      /// @return This current instance.
      /// @remarks The compositing quality determines the rendering quality level of composited images.
      graphics& compositing_quality(xtd::drawing::drawing_2d::compositing_quality value);
      
      /// @brief Gets the horizontal resolution of this xtd::drawing::graphics.
      /// @return The value, in dots per inch, for the horizontal resolution supported by this xtd::drawing::graphics.
      float dpi_x() const noexcept;
      
      /// @brief Gets the vertical resolution of this xtd::drawing::graphics.
      /// @return The value, in dots per inch, for the vertical resolution supported by this xtd::drawing::graphics.
      float dpi_y() const noexcept;
      
      /// @brief Gets the handle device context that the graphics is bound to.
      /// @return An intptr that contains the handle device context of the graphics.
      intptr handle() const noexcept;
      
      /// @brief Gets the interpolation mode associated with this xtd::drawing::graphics.
      /// @return One of the xtd::drawing::drawing_2d::interpolation_mode values.
      /// @remarks The interpolation mode determines how intermediate values between two endpoints are calculated.
      xtd::drawing::drawing_2d::interpolation_mode interpolation_mode() const noexcept;
      /// @brief Sets the interpolation mode associated with this xtd::drawing::graphics.
      /// @param value One of the xtd::drawing::drawing_2d::interpolation_mode values.
      /// @return This current instance.
      /// @remarks The interpolation mode determines how intermediate values between two endpoints are calculated.
      graphics& interpolation_mode(xtd::drawing::drawing_2d::interpolation_mode value) noexcept;
      
      /// @brief Gets the scaling between world units and page units for this xtd::drawing::graphics.
      /// @return This property specifies a value for the scaling between world units and page units for this xtd::drawing::graphics.
      float page_scale() const noexcept;
      /// @brief Sets the scaling between world units and page units for this xtd::drawing::graphics.
      /// @param value This property specifies a value for the scaling between world units and page units for this xtd::drawing::graphics.
      /// @return This current instance.
      graphics& page_scale(float value) noexcept;
      
      /// @brief Gets or sets the unit of measure used for page coordinates in this xtd::drawing::graphics.
      /// @return One of the xtd::drawing::graphics_unit values other than xtd::drawing::graphics_unit::world.
      /// @remarks The graphics unit is the unit of measure used for page coordinates in this xtd::drawing::graphics.
      xtd::drawing::graphics_unit page_unit() const noexcept;
      /// @brief Sets or sets the unit of measure used for page coordinates in this xtd::drawing::graphics.
      /// @param value One of the xtd::drawing::graphics_unit values other than xtd::drawing::graphics_unit::world.
      /// @return This current instance.
      /// @exception xtd::argument_exception xtd::drawing::graphics::page_unit is set to xtd::drawing::graphics_unit::world, which is not a physical unit.
      /// @remarks The graphics unit is the unit of measure used for page coordinates in this xtd::drawing::graphics.
      graphics& page_unit(xtd::drawing::graphics_unit value);
      
      /// @brief Gets a value specifying how pixels are offset during rendering of this xtd::drawing::graphics.
      /// @return This property specifies a member of the xtd::drawing::drawing_2d::pixel_offset_mode enumeration.
      /// @remarks Use this property to specify either higher quality, slower rendering, or lower quality, faster rendering of the contents of this xtd::drawing::graphics object.
      xtd::drawing::drawing_2d::pixel_offset_mode pixel_offset_mode() const noexcept;
      /// @brief Sets a value specifying how pixels are offset during rendering of this xtd::drawing::graphics.
      /// @param value This property specifies a member of the xtd::drawing::drawing_2d::pixel_offset_mode enumeration.
      /// @return This current instance.
      /// @remarks Use this property to specify either higher quality, slower rendering, or lower quality, faster rendering of the contents of this xtd::drawing::graphics object.
      graphics& pixel_offset_mode(xtd::drawing::drawing_2d::pixel_offset_mode value) noexcept;
      
      /// @brief Gets the rendering quality for this xtd::drawing::graphics.
      /// @return One of the xtd::drawing::drawing_2d::smoothing_mode values.
      /// @remarks The smoothing mode specifies whether lines, curves, and the edges of filled areas use smoothing (also called antialiasing). One exception is that path gradient brushes do not obey the smoothing mode. Areas filled using a xtd::drawing::drawing_2d::path_gradient_brush are rendered the same way (aliased) regardless of the xtd::drawing::graphics::smoothing_mode property.
      xtd::drawing::drawing_2d::smoothing_mode smoothing_mode() const noexcept;
      /// @brief Sets the rendering quality for this xtd::drawing::graphics.
      /// @param value One of the xtd::drawing::drawing_2d::smoothing_mode values.
      /// @return This current instance.
      /// @remarks The smoothing mode specifies whether lines, curves, and the edges of filled areas use smoothing (also called antialiasing). One exception is that path gradient brushes do not obey the smoothing mode. Areas filled using a xtd::drawing::drawing_2d::path_gradient_brush are rendered the same way (aliased) regardless of the xtd::drawing::graphics::smoothing_mode property.
      graphics& smoothing_mode(xtd::drawing::drawing_2d::smoothing_mode value) noexcept;
      
      /// @brief Gets the gamma correction value for rendering text.
      /// @return The gamma correction value used for rendering antialiased and ClearType text.
      /// @remarks The gamma correction value must be between 0 and 12. The default value is 4.
      int32 text_contrast() const noexcept;
      /// @brief Sets the gamma correction value for rendering text.
      /// @param value The gamma correction value used for rendering antialiased and ClearType text.
      /// @return This current instance.
      /// @remarks The gamma correction value must be between 0 and 12. The default value is 4.
      graphics& text_contrast(int32 value) noexcept;
      
      /// @brief Gets the rendering mode for text associated with this xtd::drawing::graphics.
      /// @return One of the xtd::drawing::graphics::text_rendering_hint values.
      /// @remarks The text rendering hint specifies whether text renders with antialiasing.
      /// @note You should not use a xtd::drawing::graphics::compositing_mode property value of xtd::drawing::graphics::source_copy when the xtd::drawing::graphics::text_rendering_hint property is set to xtd::drawing::graphics::text_rendering_hint::clear_type_grid_fit. An exception could occur or the image may not render correctly.
      xtd::drawing::text::text_rendering_hint text_rendering_hint() const noexcept;
      /// @brief Sets the rendering mode for text associated with this xtd::drawing::graphics.
      /// @param value One of the xtd::drawing::graphics::text_rendering_hint values.
      /// @return This current instance.
      /// @remarks The text rendering hint specifies whether text renders with antialiasing.
      /// @note You should not use a xtd::drawing::graphics::compositing_mode property value of xtd::drawing::graphics::source_copy when the xtd::drawing::graphics::text_rendering_hint property is set to xtd::drawing::graphics::text_rendering_hint::clear_type_grid_fit. An exception could occur or the image may not render correctly.
      graphics& text_rendering_hint(xtd::drawing::text::text_rendering_hint value);
      
      /// @brief Gets a copy of the geometric world transformation for this xtd::drawing::graphics.
      /// @return A copy of the xtd::drawing::drawing_2d::matrix that represents the geometric world transformation for this xtd::drawing::graphics.
      /// @remarks GDI+ uses three coordinate spaces: world, page, and device. World coordinates are the coordinates used to model a particular graphic world and are the coordinates you pass to methods in the .NET Framework. Page coordinates refer to the coordinate system used by a drawing surface, such as a form or a control. Device coordinates are the coordinates used by the physical device being drawn on, such as a screen or a printer. The xtd::drawing::graphics::transform property represents the world transformation, which maps world coordinates to page coordinates.
      /// @remarks Because the matrix returned and by the xtd::drawing::graphics::transform property is a copy of the geometric transform, you should dispose of the matrix when you no longer need it.
      xtd::drawing::drawing_2d::matrix transform() const noexcept;
      /// @brief Sets a copy of the geometric world transformation for this xtd::drawing::graphics.
      /// @param value A copy of the xtd::drawing::drawing_2d::matrix that represents the geometric world transformation for this xtd::drawing::graphics.
      /// @return This current instance.
      /// @remarks GDI+ uses three coordinate spaces: world, page, and device. World coordinates are the coordinates used to model a particular graphic world and are the coordinates you pass to methods in the .NET Framework. Page coordinates refer to the coordinate system used by a drawing surface, such as a form or a control. Device coordinates are the coordinates used by the physical device being drawn on, such as a screen or a printer. The xtd::drawing::graphics::transform property represents the world transformation, which maps world coordinates to page coordinates.
      /// @remarks Because the matrix returned and by the xtd::drawing::graphics::transform property is a copy of the geometric transform, you should dispose of the matrix when you no longer need it.
      graphics& transform(const xtd::drawing::drawing_2d::matrix& value) noexcept;
      
      /// @brief Gets the bounding rectangle of the visible clipping region of this xtd::drawing::graphics.
      /// @return A xtd::drawing::rectangle_f structure that represents a bounding rectangle for the visible clipping region of this xtd::drawing::graphics.
      /// @remarks The unit for resulting rectangle is designated by the xtd::drawing::graphics::page_unit property. The default unit is pixels. A xtd::drawing::graphics is typically associated with a control and the origin of the rectangle will be relative to the client area of that control.
      /// @remarks The visible clipping region is the intersection of the clipping region of this xtd::drawing::graphics::graphics and the clipping region of the window.
      xtd::drawing::rectangle_f visible_clip_bounds() const noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Clears the entire drawing surface and fills it with the specified background color.
      /// @param color xtd::drawing::color structure that represents the background color of the drawing surface.
      void clear(const color& color);
      
      /// @brief Performs a bit-block transfer of color data, corresponding to a rectangle of pixels, from the drawing surface of the xtd::drawing::graphics source to the drawing surface of the xtd::drawing::graphics.
      /// @param source The drawing surface of the xtd::drawing::graphics source.
      /// @param upper_left_source The point at the upper-left corner of the source rectangle.
      /// @param upper_left_destination The point at the upper-left corner of the destination rectangle.
      /// @param block_region_size The size of the area to be transferred.
      /// @remarks The xtd::drawing::graphics::copy_from_graphics methods are useful for layering one image on top of another. To specify how the source and destination colors are blended, use one of the xtd::drawing::graphics::copy_from_screen methods that takes a xtd::drawing::graphics::copy_pixel_operation parameter.
      void copy_from_graphics(const graphics& source, const xtd::drawing::point& upper_left_source, const xtd::drawing::point& upper_left_destination, const xtd::drawing::size& block_region_size);
      /// @brief Performs a bit-block transfer of color data, corresponding to a rectangle of pixels, from the xtd::drawing::graphics source to the drawing surface of the xtd::drawing::graphics.
      /// @param source The drawing surface of the xtd::drawing::graphics source.
      /// @param upper_left_source The point at the upper-left corner of the source rectangle.
      /// @param upper_left_destination The point at the upper-left corner of the destination rectangle.
      /// @param block_region_size The size of the area to be transferred.
      /// @param copy_pixel_operation One of the xtd::drawing::graphics::copy_pixel_operation values.
      /// @remarks The xtd::drawing::graphics::copy_from_graphics methods are useful for layering one image on top of another. The xtd::drawing::copy_pixel_operation parameter allows you to specify if and how the source colors should be blended with the colors in the destination area.
      void copy_from_graphics(const graphics& source, const xtd::drawing::point& upper_left_source, const xtd::drawing::point& upper_left_destination, const xtd::drawing::size& block_region_size, xtd::drawing::copy_pixel_operation copy_pixel_operation);
      /// @brief Performs a bit-block transfer of color data, corresponding to a rectangle of pixels, from the drawing surface of the xtd::drawing::graphics source to the drawing surface of the xtd::drawing::graphics.
      /// @param source The drawing surface of the xtd::drawing::graphics source.
      /// @param source_x The x-coordinate of the point at the upper-left corner of the source rectangle.
      /// @param source_y The y-coordinate of the point at the upper-left corner of the source rectangle.
      /// @param destination_x The x-coordinate of the point at the upper-left corner of the destination rectangle.
      /// @param destination_y The y-coordinate of the point at the upper-left corner of the destination rectangle.
      /// @param block_region_size The size of the area to be transferred.
      /// @remarks The xtd::drawing::graphics::copy_from_graphics methods are useful for layering one image on top of another. To specify how the source and destination colors are blended, use one of the xtd::drawing::graphics::copy_from_screen methods that takes a xtd::drawing::graphics::copy_pixel_operation parameter.
      void copy_from_graphics(const graphics& source, int32 source_x, int32 source_y, int32 destination_x, int32 destination_y, const xtd::drawing::size& block_region_size);
      /// @brief Performs a bit-block transfer of color data, corresponding to a rectangle of pixels, from the drawing surface of the xtd::drawing::graphics source to the drawing surface of the xtd::drawing::graphics.
      /// @param source The drawing surface of the xtd::drawing::graphics source.
      /// @param source_x The x-coordinate of the point at the upper-left corner of the source rectangle.
      /// @param source_y The y-coordinate of the point at the upper-left corner of the source rectangle.
      /// @param destination_x The x-coordinate of the point at the upper-left corner of the destination rectangle.
      /// @param destination_y The y-coordinate of the point at the upper-left corner of the destination rectangle.
      /// @param block_region_size The size of the area to be transferred.
      /// @param copy_pixel_operation One of the xtd::drawing::graphics::copy_pixel_operation values.
      /// @remarks The xtd::drawing::graphics::copy_from_graphics methods are useful for layering one image on top of another. The xtd::drawing::copy_pixel_operation parameter allows you to specify if and how the source colors should be blended with the colors in the destination area.
      void copy_from_graphics(const graphics& source, int32 source_x, int32 source_y, int32 destination_x, int32 destination_y, const xtd::drawing::size& block_region_size, xtd::drawing::copy_pixel_operation copy_pixel_operation);
      
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
      void copy_from_screen(int32 source_x, int32 source_y, int32 destination_x, int32 destination_y, const xtd::drawing::size& block_region_size);
      /// @brief Performs a bit-block transfer of color data, corresponding to a rectangle of pixels, from the screen to the drawing surface of the xtd::drawing::graphics.
      /// @param source_x The x-coordinate of the point at the upper-left corner of the source rectangle.
      /// @param source_y The y-coordinate of the point at the upper-left corner of the source rectangle.
      /// @param destination_x The x-coordinate of the point at the upper-left corner of the destination rectangle.
      /// @param destination_y The y-coordinate of the point at the upper-left corner of the destination rectangle.
      /// @param block_region_size The size of the area to be transferred.
      /// @param copy_pixel_operation One of the xtd::drawing::graphics::copy_pixel_operation values.
      /// @remarks The xtd::drawing::graphics::copy_from_screen methods are useful for layering one image on top of another. The xtd::drawing::copy_pixel_operation parameter allows you to specify if and how the source colors should be blended with the colors in the destination area.
      void copy_from_screen(int32 source_x, int32 source_y, int32 destination_x, int32 destination_y, const xtd::drawing::size& block_region_size, xtd::drawing::copy_pixel_operation copy_pixel_operation);
      
      /// @brief Draws an arc representing a portion of an ellipse specified by a xtd::drawing::rectangle structure.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the arc.
      /// @param rect xtd::drawing::rectangle structure that defines the boundaries of the ellipse.
      /// @param start_angle Angle in degrees measured clockwise from the x-axis to the starting point of the arc.
      /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to ending point of the arc.
      /// @remarks This method draws an arc that is a portion of the perimeter of an ellipse. The ellipse is defined by the boundaries of a rectangle. The arc is the portion of the perimeter of the ellipse between the start_angle parameter and the start_angle + sweep_angle parameters.
      void draw_arc(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle);
      /// @brief Draws an arc representing a portion of an ellipse specified by a xtd::drawing::rectangle structure.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the arc.
      /// @param rect xtd::drawing::rectangle_f structure that defines the boundaries of the ellipse.
      /// @param start_angle Angle in degrees measured clockwise from the x-axis to the starting point of the arc.
      /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to ending point of the arc.
      /// @remarks This method draws an arc that is a portion of the perimeter of an ellipse. The ellipse is defined by the boundaries of a rectangle. The arc is the portion of the perimeter of the ellipse between the start_angle parameter and the start_angle + sweep_angle parameters.
      void draw_arc(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle);
      /// @brief Draws an arc representing a portion of an ellipse specified by a pair of coordinates, a width, and a height.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the arc.
      /// @param x The x-coordinate of the upper-left corner of the rectangle that defines the ellipse.
      /// @param y The y-coordinate of the upper-left corner of the rectangle that defines the ellipse.
      /// @param width Width of the rectangle that defines the ellipse.
      /// @param height Height of the rectangle that defines the ellipse.
      /// @param start_angle Angle in degrees measured clockwise from the x-axis to the starting point of the arc.
      /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to ending point of the arc.
      /// @remarks This method draws an arc that is a portion of the perimeter of an ellipse. The ellipse is defined by the boundaries of a rectangle. The arc is the portion of the perimeter of the ellipse between the start_angle parameter and the start_angle + sweep_angle parameters.
      void draw_arc(const xtd::drawing::pen& pen, int32 x, int32 y, int32 width, int32 height, int32 start_angle, int32 sweep_angle);
      /// @brief Draws an arc representing a portion of an ellipse specified by a pair of coordinates, a width, and a height.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the arc.
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
      void draw_bezier(const pen& pen, int32 x1, int32 y1, int32 x2, int32 y2, int32 x3, int32 y3, int32 x4, int32 y4);
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
      void draw_beziers(const pen& pen, const std::vector<xtd::drawing::point>& points);
      /// @brief Draws a series of Bézier splines from an array of xtd::drawing::point_f structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point_f structures that represent the points that determine the curve. The number of points in the array should be a multiple of 3 plus 1, such as 4, 7, or 10.
      /// @remarks The number of points in the array should be a multiple of 3 plus 1 because the first spline requires 4 points and any other splines require 3 points each. The first Bézier curve is drawn from the first point to the fourth point in the point array. The second and third points are control points that determine the shape of the curve. Each subsequent curve needs exactly three more points: two more control points and an ending point. The ending point of the previous curve is used as the starting point for each additional curve.
      void draw_beziers(const pen& pen, const std::vector<xtd::drawing::point_f>& points);
      
      /// @brief Draws a closed cardinal spline defined by an array of xtd::drawing::point structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @remarks This method draws a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point structures.
      /// @remarks This method uses a default tension of 0.0.
      void draw_closed_curve(const pen& pen, const std::vector<xtd::drawing::point>& points);
      /// @brief Draws a closed cardinal spline defined by an array of xtd::drawing::point_f structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @remarks This method draws a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point_f structures.
      /// @remarks This method uses a default tension of 0.0.
      void draw_closed_curve(const pen& pen, const std::vector<xtd::drawing::point_f>& points);
      /// @brief Draws a closed cardinal spline defined by an array of xtd::drawing::point structures using a specified tension.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @param tension alue greater than or equal to 0.0F that specifies the tension of the curve.
      /// @remarks This method draws a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point structures.
      /// @remarks The tension parameter determines the shape of the spline. If the value of the tension parameter is 0.0F, this method draws straight line segments to connect the points. Usually, the tension parameter is less than or equal to 1.0F. Values over 1.0F produce unusual results.
      void draw_closed_curve(const pen& pen, const std::vector<xtd::drawing::point>& points, float tension);
      /// @brief Draws a closed cardinal spline defined by an array of xtd::drawing::point_f structures using a specified tension.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @param tension alue greater than or equal to 0.0F that specifies the tension of the curve.
      /// @remarks This method draws a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point_f structures.
      /// @remarks The tension parameter determines the shape of the spline. If the value of the tension parameter is 0.0F, this method draws straight line segments to connect the points. Usually, the tension parameter is less than or equal to 1.0F. Values over 1.0F produce unusual results.
      void draw_closed_curve(const pen& pen, const std::vector<xtd::drawing::point_f>& points, float tension);
      
      /// @brief Draws a cardinal spline through a specified array of xtd::drawing::point structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @remarks This method draws a cardinal spline that passes through each point in the array.
      /// @remarks The array of points must contain at least three PointF structures for a curve to be drawn.
      /// @remarks This method uses a default tension of 0.0.
      void draw_curve(const pen& pen, const std::vector<xtd::drawing::point>& points);
      /// @brief Draws a cardinal spline through a specified array of xtd::drawing::point_f structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @remarks This method draws a cardinal spline that passes through each point in the array.
      /// @remarks The array of points must contain at least three PointF structures for a curve to be drawn.
      /// @remarks This method uses a default tension of 0.0.
      void draw_curve(const pen& pen, const std::vector<xtd::drawing::point_f>& points);
      /// @brief Draws a cardinal spline through a specified array of xtd::drawing::point structures using a specified tension.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @param tension Value greater than or equal to 0.0F that specifies the tension of the curve.
      /// @remarks This method draws a cardinal spline that passes through each point in the array.
      /// @remarks The array of points must contain at least three xtd::drawing::point structures for a curve to be drawn.
      /// @remarks The tension parameter determines the shape of the spline. If the value of the tension parameter is 0.0F, this method draws straight line segments to connect the points. Usually, the tension parameter is less than or equal to 1.0F. Values over 1.0F produce unusual results.
      void draw_curve(const pen& pen, const std::vector<xtd::drawing::point>& points, float tension);
      /// @brief Draws a cardinal spline through a specified array of xtd::drawing::point_f structures using a specified tension.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the curve.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @param tension Value greater than or equal to 0.0F that specifies the tension of the curve.
      /// @remarks This method draws a cardinal spline that passes through each point in the array.
      /// @remarks The array of points must contain at least three xtd::drawing::point_f structures for a curve to be drawn.
      /// @remarks The tension parameter determines the shape of the spline. If the value of the tension parameter is 0.0F, this method draws straight line segments to connect the points. Usually, the tension parameter is less than or equal to 1.0F. Values over 1.0F produce unusual results.
      void draw_curve(const pen& pen, const std::vector<xtd::drawing::point_f>& points, float tension);
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
      void draw_curve(const pen& pen, const std::vector<xtd::drawing::point>& points, size_t offset, size_t number_of_segments);
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
      void draw_curve(const pen& pen, const std::vector<xtd::drawing::point_f>& points, size_t offset, size_t number_of_segments);
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
      void draw_curve(const pen& pen, const std::vector<xtd::drawing::point>& points, size_t offset, size_t number_of_segments, float tension);
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
      void draw_curve(const pen& pen, const std::vector<xtd::drawing::point_f>& points, size_t offset, size_t number_of_segments, float tension);
      
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
      void draw_ellipse(const xtd::drawing::pen& pen, int32 x, int32 y, int32 width, int32 height);
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
      void draw_icon(const xtd::drawing::icon& icon, int32 x, int32 y);
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
      void draw_image(const xtd::drawing::image& image, int32 x, int32 y, int32 width, int32 height);
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
      void draw_image(const xtd::drawing::image& image, int32 x, int32 y);
      /// @brief Draws the specified xtd::drawing::image, using its original physical size, at the specified location.
      /// @param image xtd::drawing::image to draw.
      /// @param x The x-coordinate of the upper-left corner of the drawn image.
      /// @param y The y-coordinate of the upper-left corner of the drawn image.
      /// @remarks An xtd::drawing::image stores a value for pixel width and a value for horizontal resolution (dots per inch). The physical width, measured in inches, of an image is the pixel width divided by the horizontal resolution. For example, an image with a pixel width of 216 and a horizontal resolution of 72 dots per inch has a physical width of 3 inches. Similar remarks apply to pixel height and physical height.
      /// @remarks This method draws an image using its physical size, so the image will have its correct size in inches regardless of the resolution (dots per inch) of the display device. For example, suppose an image has a pixel width of 216 and a horizontal resolution of 72 dots per inch. If you call this method to draw that image on a device that has a resolution of 96 dots per inch, the pixel width of the rendered image will be (216/72)*96 = 288.
      void draw_image(const xtd::drawing::image& image, float x, float y);
      
      /// @brief Draws the specified protion of the specified xtd::drawing::image at the specified location and with the specified size.
      /// @param image xtd::drawing::image to draw.
      /// @param rect xtd::drawing::rectangle structure that specifies the location and size of the drawn image.
      /// @remarks The image represented by the image object is scaled to the dimensions of the rect rectangle.
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle& dest_rect, const xtd::drawing::rectangle& src_rect);
      /// @brief Draws the specified protion of the specified xtd::drawing::image at the specified location and with the specified size.
      /// @param image xtd::drawing::image to draw.
      /// @param rect xtd::drawing::rectangle_f structure that specifies the location and size of the drawn image.
      /// @remarks The image represented by the image object is scaled to the dimensions of the rect rectangle.
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle_f& dest_rect, const xtd::drawing::rectangle_f& src_rect);
      /// @brief Draws the specified protion of the specified xtd::drawing::image, using its original physical size, at the specified location.
      /// @param image xtd::drawing::image to draw.
      /// @param point xtd::drawing::point structure that represents the location of the upper-left corner of the drawn image.
      /// @remarks An xtd::drawing::image stores a value for pixel width and a value for horizontal resolution (dots per inch). The physical width, measured in inches, of an image is the pixel width divided by the horizontal resolution. For example, an image with a pixel width of 216 and a horizontal resolution of 72 dots per inch has a physical width of 3 inches. Similar remarks apply to pixel height and physical height.
      /// @remarks This method draws an image using its physical size, so the image will have its correct size in inches regardless of the resolution (dots per inch) of the display device. For example, suppose an image has a pixel width of 216 and a horizontal resolution of 72 dots per inch. If you call this method to draw that image on a device that has a resolution of 96 dots per inch, the pixel width of the rendered image will be (216/72)*96 = 288.
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::point& dest_point, const xtd::drawing::rectangle& src_rect);
      /// @brief Draws the specified protion of the specified xtd::drawing::image, using its original physical size, at the specified location.
      /// @param image xtd::drawing::image to draw.
      /// @param point xtd::drawing::point_f structure that represents the location of the upper-left corner of the drawn image.
      /// @remarks An xtd::drawing::image stores a value for pixel width and a value for horizontal resolution (dots per inch). The physical width, measured in inches, of an image is the pixel width divided by the horizontal resolution. For example, an image with a pixel width of 216 and a horizontal resolution of 72 dots per inch has a physical width of 3 inches. Similar remarks apply to pixel height and physical height.
      /// @remarks This method draws an image using its physical size, so the image will have its correct size in inches regardless of the resolution (dots per inch) of the display device. For example, suppose an image has a pixel width of 216 and a horizontal resolution of 72 dots per inch. If you call this method to draw that image on a device that has a resolution of 96 dots per inch, the pixel width of the rendered image will be (216/72)*96 = 288.
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::point_f& dest_point, const xtd::drawing::rectangle_f& src_rect);
      /// @brief Draws the specified protion of the specified xtd::drawing::image at the specified location and with the specified size.
      /// @param image xtd::drawing::image to draw.
      /// @param rect xtd::drawing::rectangle structure that specifies the location and size of the drawn image.
      /// @remarks The image represented by the image object is scaled to the dimensions of the rect rectangle.
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle& dest_rect, int32 src_x, int32 src_y, int32 srd_width, int32 src_height);
      /// @brief Draws the specified protion of the specified xtd::drawing::image at the specified location and with the specified size.
      /// @param image xtd::drawing::image to draw.
      /// @param rect xtd::drawing::rectangle_f structure that specifies the location and size of the drawn image.
      /// @remarks The image represented by the image object is scaled to the dimensions of the rect rectangle.
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle_f& dest_rect, float src_x, float src_y, float srd_width, float src_height);
      /// @brief Draws the specified protion of the specified xtd::drawing::image, using its original physical size, at the specified location.
      /// @param image xtd::drawing::image to draw.
      /// @param point xtd::drawing::point structure that represents the location of the upper-left corner of the drawn image.
      /// @remarks An xtd::drawing::image stores a value for pixel width and a value for horizontal resolution (dots per inch). The physical width, measured in inches, of an image is the pixel width divided by the horizontal resolution. For example, an image with a pixel width of 216 and a horizontal resolution of 72 dots per inch has a physical width of 3 inches. Similar remarks apply to pixel height and physical height.
      /// @remarks This method draws an image using its physical size, so the image will have its correct size in inches regardless of the resolution (dots per inch) of the display device. For example, suppose an image has a pixel width of 216 and a horizontal resolution of 72 dots per inch. If you call this method to draw that image on a device that has a resolution of 96 dots per inch, the pixel width of the rendered image will be (216/72)*96 = 288.
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::point& dest_point, int32 src_x, int32 src_y, int32 srd_width, int32 src_height);
      /// @brief Draws the specified protion of the specified xtd::drawing::image, using its original physical size, at the specified location.
      /// @param image xtd::drawing::image to draw.
      /// @param point xtd::drawing::point_f structure that represents the location of the upper-left corner of the drawn image.
      /// @remarks An xtd::drawing::image stores a value for pixel width and a value for horizontal resolution (dots per inch). The physical width, measured in inches, of an image is the pixel width divided by the horizontal resolution. For example, an image with a pixel width of 216 and a horizontal resolution of 72 dots per inch has a physical width of 3 inches. Similar remarks apply to pixel height and physical height.
      /// @remarks This method draws an image using its physical size, so the image will have its correct size in inches regardless of the resolution (dots per inch) of the display device. For example, suppose an image has a pixel width of 216 and a horizontal resolution of 72 dots per inch. If you call this method to draw that image on a device that has a resolution of 96 dots per inch, the pixel width of the rendered image will be (216/72)*96 = 288.
      void draw_image(const xtd::drawing::image& image, const xtd::drawing::point_f& dest_point, float src_x, float src_y, float srd_width, float src_height);

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
      void draw_image_unscaled(const xtd::drawing::image& image, int32 x, int32 y);
      /// @brief Draws a specified image using its original physical size at a specified location.
      /// @param image xtd::drawing::image to draw.
      /// @param rect xtd::drawing::rectangle that specifies the upper-left corner of the drawn image. The xtd::drawing::rectangle::x and xtd::drawing::rectangle::y properties of the rectangle specify the upper-left corner. The xtd::drawing::rectangle::width and xtd::drawing::rectangle::height properties are ignored.
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
      void draw_image_unscaled(const xtd::drawing::image& image, int32 x, int32 y, int32 width, int32 height);
      
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
      void draw_line(const xtd::drawing::pen& pen, int32 x1, int32 y1, int32 x2, int32 y2);
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
      
      /// @brief Draws a xtd::drawing::drawing_2d::graphics_path.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the path.
      /// @param path xtd::drawing::drawing_2d::graphics_path to draw.
      /// @remarks The current transformation in the graphic context is applied to the xtd::drawing::drawing_2d::graphics_path before it is drawn.
      void draw_path(const xtd::drawing::pen& pen, const xtd::drawing::drawing_2d::graphics_path& path);
      
      /// @brief Draws a pie shape defined by an ellipse specified by a xtd::drawing::rectangle structure and two radial lines.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the pie shape.
      /// @param rect xtd::drawing::rectangle structure that represents the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param start_angle Angle measured in degrees clockwise from the x-axis to the first side of the pie shape.
      /// @param sweep_angle Angle measured in degrees clockwise from the startAngle parameter to the second side of the pie shape.
      /// @remarks This method draws a pie shape defined by an arc of an ellipse and the two radial lines that intersect with the endpoints of the arc. The ellipse is defined by the bounding rectangle. The pie shape consists of the two radial lines defined by the start_angle and sweep_angle parameters, and the arc between the intersections of those radial lines with the ellipse.
      /// @remarks If the sweep_angle parameter is greater than 360 degrees or less than -360 degrees, it is treated as if it were 360 degrees or -360 degrees, respectively.
      void draw_pie(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle);
      /// @brief Draws a pie shape defined by an ellipse specified by a xtd::drawing::rectangle_f structure and two radial lines.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the pie shape.
      /// @param rect xtd::drawing::rectangle_f structure that represents the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param start_angle Angle measured in degrees clockwise from the x-axis to the first side of the pie shape.
      /// @param sweep_angle Angle measured in degrees clockwise from the startAngle parameter to the second side of the pie shape.
      /// @remarks This method draws a pie shape defined by an arc of an ellipse and the two radial lines that intersect with the endpoints of the arc. The ellipse is defined by the bounding rectangle. The pie shape consists of the two radial lines defined by the start_angle and sweep_angle parameters, and the arc between the intersections of those radial lines with the ellipse.
      /// @remarks If the sweep_angle parameter is greater than 360 degrees or less than -360 degrees, it is treated as if it were 360 degrees or -360 degrees, respectively.
      void draw_pie(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle);
      /// @brief Draws a pie shape defined by an ellipse specified by a coordinate pair, a width, a height, and two radial lines.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the pie shape.
      /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param width Width of the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param heught Height of the bounding rectangle that defines the ellipse from which the pie shape comes.
      /// @param start_angle Angle measured in degrees clockwise from the x-axis to the first side of the pie shape.
      /// @param sweep_angle Angle measured in degrees clockwise from the startAngle parameter to the second side of the pie shape.
      /// @remarks This method draws a pie shape defined by an arc of an ellipse and the two radial lines that intersect with the endpoints of the arc. The ellipse is defined by the bounding rectangle described by the x, y, width, and height parameters. The pie shape consists of the two radial lines defined by the start_angle and sweep_angle parameters, and the arc between the intersections of those radial lines with the ellipse.
      /// @remarks If the sweep_angle parameter is greater than 360 degrees or less than -360 degrees, it is treated as if it were 360 degrees or -360 degrees, respectively.
      void draw_pie(const xtd::drawing::pen& pen, int32 x, int32 y, int32 width, int32 height, int32 start_angle, int32 sweep_angle);
      /// @brief Draws a pie shape defined by an ellipse specified by a coordinate pair, a width, a height, and two radial lines.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the pie shape.
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
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the polygon.
      /// @param points Array of xtd::drawing::point structures that represent the vertices of the polygon.
      /// @remarks Every pair of two consecutive points in the array specifies a side of the polygon. In addition, if the last point and the first of the array point do not coincide, they specify the last side of the polygon.
      void draw_polygon(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::point>& points);
      /// @brief Draws a polygon defined by an array of xtd::drawing::point_f structures.
      /// @param pen xtd::drawing::pen that determines the color, width, and style of the polygon.
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
      void draw_point(const xtd::drawing::pen& pen, int32 x, int32 y);
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
      void draw_rectangle(const xtd::drawing::pen& pen, int32 x, int32 y, int32 width, int32 height);
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
      
      /// @brief Draws the specified text string at the specified location with the specified xtd::drawing::brush, xtd::drawing::font objects and angle.
      /// @param s String to draw.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param brush xtd::drawing::brush that determines the color and texture of the drawn text.
      /// @param point xtd::drawing::point_f structure that specifies the upper-left corner of the drawn text.
      /// @param angle The angle, measured in degrees clockwise from the x-axis, of the text's orientation line.
      void draw_rotated_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point, float angle);
      /// @brief Draws the specified text string at the specified location with the specified xtd::drawing::brush, xtd::drawing::font objects and angle.
      /// @param s String to draw.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param brush xtd::drawing::brush that determines the color and texture of the drawn text.
      /// @param x The x-coordinate of the upper-left corner of the drawn text.
      /// @param y The y-coordinate of the upper-left corner of the drawn text.
      /// @param angle The angle, measured in degrees clockwise from the x-axis, of the text's orientation line.
      void draw_rotated_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, float x, float y, float angle);
      
      /// @brief Draws a rounded rectangle specified by a xtd::drawing::rectangle structure, and radius.
      /// @param pen A xtd::drawing::pen that determines the color, width, and style of the rounded rectangle.
      /// @param rect A xtd::drawing::rectangle structure that represents the rounded rectangle to draw.
      /// @param radius The radius of the rounded rectange angles.
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, int32 radius);
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
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, int32 x, int32 y, int32 width, int32 height, int32 radius);
      /// @brief Draws a rounded rectangle specified by a coordinate pair, a width, a height, and radius.
      /// @param pen A xtd::drawing::pen that determines the color, width, and style of the rounded rectangle.
      /// @param x The x-coordinate of the upper-left corner of the rounded rectangle to draw.
      /// @param y The y-coordinate of the upper-left corner of the rounded rectangle to draw.
      /// @param width The width of the rounded rectangle to draw.
      /// @param height The height of the rounded rectangle to draw.
      /// @param radius The radius of the rounded rectange angles.
      void draw_rounded_rectangle(const xtd::drawing::pen& pen, float x, float y, float width, float height, float radius);
      
      /// @brief Draws the specified text string at the specified rectangle with the specified xtd::drawing::brush and xtd::drawing::font objects.
      /// @param s String to draw.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param brush xtd::drawing::brush that determines the color and texture of the drawn text.
      /// @param layout_rectangle xtd::drawing::rectangle_f structure that specifies the location of the drawn text.
      /// @remarks The text represented by the s parameter is drawn inside the rectangle represented by the layout_rectangle parameter. If the text does not fit inside the rectangle, it is truncated at the nearest word. To further manipulate how the string is drawn inside the rectangle use the xtd::drawing::graphics::draw_string overload that takes a xtd::drawing::string_format.
      void draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& layout_rectangle);
      /// @brief Draws the specified text string at the specified rectangle with the specified xtd::drawing::brush and xtd::drawing::font objects using the formatting attributes of the specified xtd::drawing::string_format.
      /// @param s String to draw.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param brush xtd::drawing::brush that determines the color and texture of the drawn text.
      /// @param layout_rectangle xtd::drawing::rectangle_f structure that specifies the location of the drawn text.
      /// @param format xtd::drawing::string_format that specifies formatting attributes, such as line spacing and alignment, that are applied to the drawn text.
      /// @remarks The text represented by the s parameter is drawn inside the rectangle represented by the layout_rectangle parameter. If the text does not fit inside the rectangle, it is truncated at the nearest word, unless otherwise specified with the format parameter.
      void draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& layout_rectangle, const xtd::drawing::string_format& format);
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
      /// @param point xtd::drawing::point_f structure that specifies the upper-left corner of the drawn text.
      /// @param format xtd::drawing::string_format that specifies formatting attributes, such as line spacing and alignment, that are applied to the drawn text.
      void draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point, const xtd::drawing::string_format& format);
      /// @brief Draws the specified text string at the specified location with the specified xtd::drawing::brush and xtd::drawing::font objects.
      /// @param s String to draw.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param brush xtd::drawing::brush that determines the color and texture of the drawn text.
      /// @param x The x-coordinate of the upper-left corner of the drawn text.
      /// @param y The y-coordinate of the upper-left corner of the drawn text.
      void draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, float x, float y);
      /// @brief Draws the specified text string at the specified location with the specified xtd::drawing::brush and xtd::drawing::font objects using the formatting attributes of the specified xtd::drawing::string_format.
      /// @param s String to draw.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param brush xtd::drawing::brush that determines the color and texture of the drawn text.
      /// @param x The x-coordinate of the upper-left corner of the drawn text.
      /// @param y The y-coordinate of the upper-left corner of the drawn text.
      /// @param format xtd::drawing::string_format that specifies formatting attributes, such as line spacing and alignment, that are applied to the drawn text.
      void draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, float x, float y, const xtd::drawing::string_format& format);
      
      /// @brief Updates the clip region of this xtd::drawing::graphics to exclude the area specified by a xtd::drawing::region.
      /// @param region xtd::drawing::region that specifies the region to exclude from the clip region.
      /// @remarks This method excludes the area specified by the region parameter from the current clip region and assigns the resulting area to the xtd::drawing::graphics::clip property of this xtd::drawing::graphics.
      void exclude_clip(const xtd::drawing::region& region);
      /// @brief Updates the clip region of this xtd::drawing::graphics to exclude the area specified by a xtd::drawing::rectangle.
      /// @param rect xtd::drawing::rectangle that specifies the rectangle to exclude from the clip region.
      /// @remarks This method excludes the area specified by the rect parameter from the current clip region and assigns the resulting area to the xtd::drawing::graphics::clip property of this xtd::drawing::graphics.
      void exclude_clip(const xtd::drawing::rectangle& rect);
      /// @brief Updates the clip region of this xtd::drawing::graphics to exclude the area specified by a xtd::drawing::rectangle_f.
      /// @param rect xtd::drawing::rectangle_f that specifies the rectangle to exclude from the clip region.
      /// @remarks This method excludes the area specified by the rect parameter from the current clip region and assigns the resulting area to the xtd::drawing::graphics::clip property of this xtd::drawing::graphics.
      void exclude_clip(const xtd::drawing::rectangle_f& rect);
      
      /// @brief Fills the interior of a closed cardinal spline curve defined by an array of xtd::drawing::point structures.
      /// @param brush A xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @remarks This method fills the interior of a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point structures.
      /// @remarks This method uses a default tension of 0.0.
      void fill_closed_curve(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point>& points);
      /// @brief Fills the interior of a closed cardinal spline curve defined by an array of xtd::drawing::point_f structures.
      /// @param brush A xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @remarks This method fills the interior of a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point_f structures.
      /// @remarks This method uses a default tension of 0.0.
      void fill_closed_curve(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point_f>& points);
      /// @brief Fills the interior of a closed cardinal spline curve defined by an array of xtd::drawing::point structures using the specified fill mode.
      /// @param brush A xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @param fill_mode Member of the xtd::drawing::drawing_2d::fill_mode enumeration that determines how the curve is filled.
      /// @remarks This method fills the interior of a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point structures.
      /// @remarks This method uses a default tension of 0.0.
      void fill_closed_curve(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point>& points, xtd::drawing::drawing_2d::fill_mode fill_mode);
      /// @brief Fills the interior of a closed cardinal spline curve defined by an array of xtd::drawing::point_f structures using the specified fill mode.
      /// @param brush A xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @param fill_mode Member of the xtd::drawing::drawing_2d::fill_mode enumeration that determines how the curve is filled.
      /// @remarks This method fills the interior of a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point_f structures.
      /// @remarks This method uses a default tension of 0.0.
      void fill_closed_curve(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point_f>& points, xtd::drawing::drawing_2d::fill_mode fill_mode);
      /// @brief Fills the interior of a closed cardinal spline curve defined by an array of xtd::drawing::point structures using the specified fill mode and tension.
      /// @param brush A xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point structures that define the spline.
      /// @param fill_mode Member of the xtd::drawing::drawing_2d::fill_mode enumeration that determines how the curve is filled.
      /// @param tension Value greater than or equal to 0.0F that specifies the tension of the curve.
      /// @remarks This method fills the interior of a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point structures.
      /// @remarks The tension parameter determines the shape of the spline. If the value of the tension parameter is 0.0F, this method draws straight line segments to connect the points. Usually, the tension parameter is less than or equal to 1.0F. Values over 1.0F produce unusual results.
      void fill_closed_curve(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point>& points, xtd::drawing::drawing_2d::fill_mode fill_mode, float tension);
      /// @brief Fills the interior of a closed cardinal spline curve defined by an array of xtd::drawing::point_f structures using the specified fill mode and tension.
      /// @param brush A xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point_f structures that define the spline.
      /// @param fill_mode Member of the xtd::drawing::drawing_2d::fill_mode enumeration that determines how the curve is filled.
      /// @param tension Value greater than or equal to 0.0F that specifies the tension of the curve.
      /// @remarks This method fills the interior of a closed cardinal spline that passes through each point in the array. If the last point does not match the first point, an additional curve segment is added from the last point to the first point to close it.
      /// @remarks The array of points must contain at least four xtd::drawing::point_f structures.
      /// @remarks The tension parameter determines the shape of the spline. If the value of the tension parameter is 0.0F, this method draws straight line segments to connect the points. Usually, the tension parameter is less than or equal to 1.0F. Values over 1.0F produce unusual results.
      void fill_closed_curve(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point_f>& points, xtd::drawing::drawing_2d::fill_mode fill_mode, float tension);
      
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
      void fill_ellipse(const xtd::drawing::brush& brush, int32 x, int32 y, int32 width, int32 height);
      /// @brief Fills the interior of an ellipse defined by a bounding rectangle specified by a pair of coordinates, a width, and a height.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
      /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
      /// @param width Width of the bounding rectangle that defines the ellipse.
      /// @param height Height of the bounding rectangle that defines the ellipse.
      /// @remarks This method fills the interior of an ellipse with a xtd::drawing::brush. The ellipse is defined by the bounding rectangle represented by the x, y, width, and height parameters.
      void fill_ellipse(const xtd::drawing::brush& brush, float x, float y, float width, float height);
      
      /// @brief Fills the interior of a xtd::drawing::drawing_2d::graphics_path.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param path xtd::drawing::drawing_2d::graphics_path that represents the path to fill.
      /// @remarks A xtd::drawing::drawing_2d::graphics_path consists of a series of line and curve segments. If the path represented by the path parameter is not closed, an additional segment is added from the last point to the first point to close the path.
      void fill_path(const xtd::drawing::brush& brush, const xtd::drawing::drawing_2d::graphics_path& path);
      
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
      void fill_pie(const xtd::drawing::brush& brush, int32 x, int32 y, int32 width, int32 height, int32 start_angle, int32 sweep_angle);
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
      /// @param fill_mode Member of the xtd::drawing::drawing_2d::fill_mode enumeration that determines the style of the fill.
      /// @remarks Every two consecutive points in the array specify a side of the polygon. In addition, if the last point and the first point do not coincide, they specify the closing side of the polygon.
      void fill_polygon(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point>& points, xtd::drawing::drawing_2d::fill_mode fill_mode);
      /// @brief Fills the interior of a polygon defined by an array of points specified by xtd::drawing::point_f structures using the specified fill mode.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param points Array of xtd::drawing::point_f structures that represent the vertices of the polygon to fill.
      /// @param fill_mode Member of the xtd::drawing::drawing_2d::fill_mode enumeration that determines the style of the fill.
      /// @remarks Every two consecutive points in the array specify a side of the polygon. In addition, if the last point and the first point do not coincide, they specify the closing side of the polygon.
      void fill_polygon(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point_f>& points, xtd::drawing::drawing_2d::fill_mode fill_mode);
      
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
      void fill_rectangle(const xtd::drawing::brush& brush, int32 x, int32 y, int32 width, int32 height);
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
      void fill_rounded_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect, int32 radius);
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
      void fill_rounded_rectangle(const xtd::drawing::brush& brush, int32 x, int32 y, int32 width, int32 height, int32 radius);
      /// @brief Fills the interior of a rounded rectangle specified by a pair of coordinates, a width, a height, and a radius.
      /// @param brush xtd::drawing::brush that determines the characteristics of the fill.
      /// @param x The x-coordinate of the upper-left corner of the rounded rectangle to fill.
      /// @param y The y-coordinate of the upper-left corner of the rounded rectangle to fill.
      /// @param width Width of the rounded rectangle to fill.
      /// @param height Height of the rounded rectangle to fill.
      /// @param radius The radius of the rounded rectange angles.
      /// @remarks This method fills the interior of the rounded rectangle defined by the x, y, width, height, and radius parameters, including the specified upper-left corner and up to the calculated lower and bottom edges.
      void fill_rounded_rectangle(const xtd::drawing::brush& brush, float x, float y, float width, float height, float radius);
      
      /// @brief Forces execution of all pending graphics operations and returns immediately without waiting for the operations to finish.
      /// @remarks This method starts a flush and returns immediately without waiting for any currently executing graphics operation to finish.
      void flush();
      /// @brief Forces execution of all pending graphics operations with the method waiting or not waiting, as specified, to return before the operations finish.
      /// @param intention Member of the xtd::drawing::drawing_2d::flush_intention enumeration that specifies whether the method returns immediately or waits for any existing operations to finish.
      /// @remarks A value of xtd::drawing::graphics::flush for the intention parameter specifies that the method return immediately after beginning the flush, while a value of xtd::drawing::drawing_2d::flush_intention::sync specifies that the method wait before returning until any existing operations finish.
      void flush(xtd::drawing::drawing_2d::flush_intention intention);
      
      /// @brief Gets the handle to the device context associated with this xtd::drawing::graphics.
      /// @return Handle to the device context associated with this xtd::drawing::graphics.
      /// @remarks The device context is a Windows structure based on GDI that defines a set of graphical objects and their associated attributes, as well as the graphical modes that affect output. This method returns that device context with the exception of a font. Because a font is not selected, calls to the xtd::drawing::graphics::from_hdc method using a handle returned from the xtd::drawing::graphics::get_hdc method will fail.
      /// @remarks Calls to the xtd::drawing::graphics::get_hdc and xtd::drawing::graphics::release_hdc methods must appear in pairs. During the scope of a xtd::drawing::graphics::get_hdc and xtd::drawing::graphics::release_hdc method pair, you usually make only calls to GDI functions. Calls in that scope made to GDI+ methods of the xtd::drawing::graphics that produced the hdc parameter fail with an ObjectBusy error. Also, GDI+ ignores any state changes made to the xtd::drawing::graphics of the hdc parameter in subsequent operations.
      intptr get_hdc() const;
      
      /// @brief Gets the nearest color to the specified xtd::drawing::color structure.
      /// @param color xtd::drawing::color structure for which to find a match.
      /// @return A xtd::drawing::color structure that represents the nearest color to the one specified with the color parameter.
      xtd::drawing::color get_nearest_color(const xtd::drawing::color& color) const;
      
      /// @brief Updates the clip region of this xtd::drawing::graphics to the intersection of the current clip region and the specified xtd::drawing::region.
      /// @param region xtd::drawing::region to intersect with the current region.
      /// @remarks This method assigns to the xtd::drawing::graphics::clip property of this xtd::drawing::graphics the area represented by the intersection of the current clip region and the region specified by the region parameter.
      void intersect_clip(const xtd::drawing::region& region);
      /// @brief Updates the clip region of this xtd::drawing::graphics to the intersection of the current clip region and the specified xtd::drawing::rectangle structure.
      /// @param rect xtd::drawing::rectangle structure to intersect with the current clip region.
      /// @remarks This method assigns to the xtd::drawing::graphics::clip property of this xtd::drawing::graphics the area represented by the intersection of the current clip region and the rectangle specified by the rect parameter.
      void intersect_clip(const xtd::drawing::rectangle& rect);
      /// @brief Updates the clip region of this xtd::drawing::graphics to the intersection of the current clip region and the specified xtd::drawing::rectangle_f structure.
      /// @param rect xtd::drawing::rectangle_f structure to intersect with the current clip region.
      /// @remarks This method assigns to the xtd::drawing::graphics::clip property of this xtd::drawing::graphics the area represented by the intersection of the current clip region and the rectangle specified by the rect parameter.
      void intersect_clip(const xtd::drawing::rectangle_f& rect);
      
      /// @brief Indicates whether the rectangle specified by a xtd::drawing::rectangle structure is contained within the visible clip region of this xtd::drawing::graphics.
      /// @param rect xtd::drawing::rectangle structure to test for visibility.
      /// @return true if the rectangle specified by the rect parameter is contained within the visible clip region of this xtd::drawing::graphics; otherwise, false.
      bool is_visible(const xtd::drawing::rectangle& rect);
      /// @brief Indicates whether the rectangle specified by a xtd::drawing::rectangle_f structure is contained within the visible clip region of this xtd::drawing::graphics.
      /// @param rect xtd::drawing::rectangle_f structure to test for visibility.
      /// @return true if the rectangle specified by the rect parameter is contained within the visible clip region of this xtd::drawing::graphics; otherwise, false.
      bool is_visible(const xtd::drawing::rectangle_f& rect);
      /// @brief Indicates whether the rectangle specified by a pair of coordinates, a width, and a height is contained within the visible clip region of this xtd::drawing::graphics.
      /// @param x The x-coordinate of the upper-left corner of the rectangle to test for visibility.
      /// @param y The y-coordinate of the upper-left corner of the rectangle to test for visibility.
      /// @param width Width of the rectangle to test for visibility.
      /// @param height Height of the rectangle to test for visibility.
      /// @return true if the rectangle defined by the x, y, width, and height parameters is contained within the visible clip region of this xtd::drawing::graphics; otherwise, false.
      bool is_visible(int32 x, int32 y, int32 width, int32 height);
      /// @brief Indicates whether the rectangle specified by a pair of coordinates, a width, and a height is contained within the visible clip region of this xtd::drawing::graphics.
      /// @param x The x-coordinate of the upper-left corner of the rectangle to test for visibility.
      /// @param y The y-coordinate of the upper-left corner of the rectangle to test for visibility.
      /// @param width Width of the rectangle to test for visibility.
      /// @param height Height of the rectangle to test for visibility.
      /// @return true if the rectangle defined by the x, y, width, and height parameters is contained within the visible clip region of this xtd::drawing::graphics; otherwise, false.
      bool is_visible(float x, float y, float width, float height);
      /// @brief ndicates whether the specified xtd::drawing::point structure is contained within the visible clip region of this xtd::drawing::graphics.
      /// @param point xtd::drawing::point structure to test for visibility.
      /// @return true if the point specified by the point parameter is contained within the visible clip region of this xtd::drawing::graphics; otherwise, false.
      bool is_visible(const xtd::drawing::point& point);
      /// @brief ndicates whether the specified xtd::drawing::point_f structure is contained within the visible clip region of this xtd::drawing::graphics.
      /// @param point xtd::drawing::point_f structure to test for visibility.
      /// @return true if the point specified by the point parameter is contained within the visible clip region of this xtd::drawing::graphics; otherwise, false.
      bool is_visible(const xtd::drawing::point_f& point);
      /// @brief Indicates whether the point specified by a pair of coordinates is contained within the visible clip region of this xtd::drawing::graphics.
      /// @param x The x-coordinate of the point to test for visibility.
      /// @param y The y-coordinate of the point to test for visibility.
      /// @return true if the point defined by the x and y parameters is contained within the visible clip region of this xtd::drawing::graphics; otherwise, false.
      bool is_visible(int32 x, int32 y);
      /// @brief Indicates whether the point specified by a pair of coordinates is contained within the visible clip region of this xtd::drawing::graphics.
      /// @param x The x-coordinate of the point to test for visibility.
      /// @param y The y-coordinate of the point to test for visibility.
      /// @return true if the point defined by the x and y parameters is contained within the visible clip region of this xtd::drawing::graphics; otherwise, false.
      bool is_visible(float x, float y);
      
      /// @brief Measures the specified string when drawn with the specified xtd::drawing::font.
      /// @param text xtd::ustring to measure.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @remarks The xtd::drawing::graphics::measure_string method is designed for use with individual strings and includes a small amount of extra space before and after the string to allow for overhanging glyphs. Also, the xtd::drawing::graphics::draw_string method adjusts glyph points to optimize display quality and might display a string narrower than reported byxtd::drawing::graphics::measure_string. To obtain metrics suitable for adjacent strings in layout (for example, when implementing formatted text), use the xtd::drawing::graphics::measure_character_ranges method or one of the xtd::drawing::graphics::measure_string methods that takes a xtd::drawing::string_format, and pass xtd::drawing::string_format::generic_typographic. Also, ensure the xtd::drawing::text::text_rendering_hint for the xtd::drawing::graphics is xtd::drawing::text::text_rendering_hint::anti_alias.
      size_f measure_string(const xtd::ustring& text, const xtd::drawing::font& font);
      /// @brief Measures the specified string when drawn with the specified xtd::drawing::font within the specified layout area.
      /// @param text xtd::ustring to measure.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param layout_area xtd::drawing::size_f structure that specifies the maximum layout area for the text.
      /// @remarks The xtd::drawing::graphics::measure_string method is designed for use with individual strings and includes a small amount of extra space before and after the string to allow for overhanging glyphs. Also, the xtd::drawing::graphics::draw_string method adjusts glyph points to optimize display quality and might display a string narrower than reported byxtd::drawing::graphics::measure_string. To obtain metrics suitable for adjacent strings in layout (for example, when implementing formatted text), use the xtd::drawing::graphics::measure_character_ranges method or one of the xtd::drawing::graphics::measure_string methods that takes a xtd::drawing::string_format, and pass xtd::drawing::string_format::generic_typographic. Also, ensure the xtd::drawing::text::text_rendering_hint for the xtd::drawing::graphics is xtd::drawing::text::text_rendering_hint::anti_alias.
      size_f measure_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::size_f& layout_area);
      /// @brief Measures the specified string when drawn with the specified xtd::drawing::font.
      /// @param text xtd::ustring to measure.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param width Maximum width of the string in pixels.
      /// @remarks The xtd::drawing::graphics::measure_string method is designed for use with individual strings and includes a small amount of extra space before and after the string to allow for overhanging glyphs. Also, the xtd::drawing::graphics::draw_string method adjusts glyph points to optimize display quality and might display a string narrower than reported byxtd::drawing::graphics::measure_string. To obtain metrics suitable for adjacent strings in layout (for example, when implementing formatted text), use the xtd::drawing::graphics::measure_character_ranges method or one of the xtd::drawing::graphics::measure_string methods that takes a xtd::drawing::string_format, and pass xtd::drawing::string_format::generic_typographic. Also, ensure the xtd::drawing::text::text_rendering_hint for the xtd::drawing::graphics is xtd::drawing::text::text_rendering_hint::anti_alias.
      size_f measure_string(const xtd::ustring& text, const xtd::drawing::font& font, int32 width);
      /// @brief Measures the specified string when drawn with the specified xtd::drawing::font and formatted with the specified xtd::drawing::string_format.
      /// @param text xtd::ustring to measure.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param origin xtd::drawing::point_f structure that represents the upper-left corner of the string.
      /// @param format xtd::drawing::string_format that represents formatting information, such as line spacing, for the string.
      /// @remarks The xtd::drawing::graphics::measure_string method is designed for use with individual strings and includes a small amount of extra space before and after the string to allow for overhanging glyphs. Also, the xtd::drawing::graphics::draw_string method adjusts glyph points to optimize display quality and might display a string narrower than reported byxtd::drawing::graphics::measure_string. To obtain metrics suitable for adjacent strings in layout (for example, when implementing formatted text), use the xtd::drawing::graphics::measure_character_ranges method or one of the xtd::drawing::graphics::measure_string methods that takes a xtd::drawing::string_format, and pass xtd::drawing::string_format::generic_typographic. Also, ensure the xtd::drawing::text::text_rendering_hint for the xtd::drawing::graphics is xtd::drawing::text::text_rendering_hint::anti_alias.
      size_f measure_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::point_f& origin, const xtd::drawing::string_format& format);
      /// @brief Measures the specified string when drawn with the specified xtd::drawing::font and formatted with the specified xtd::drawing::string_format.
      /// @param text xtd::ustring to measure.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param layout_area xtd::drawing::size_f structure that specifies the maximum layout area for the text.
      /// @param format xtd::drawing::string_format that represents formatting information, such as line spacing, for the string.
      /// @remarks The xtd::drawing::graphics::measure_string method is designed for use with individual strings and includes a small amount of extra space before and after the string to allow for overhanging glyphs. Also, the xtd::drawing::graphics::draw_string method adjusts glyph points to optimize display quality and might display a string narrower than reported byxtd::drawing::graphics::measure_string. To obtain metrics suitable for adjacent strings in layout (for example, when implementing formatted text), use the xtd::drawing::graphics::measure_character_ranges method or one of the xtd::drawing::graphics::measure_string methods that takes a xtd::drawing::string_format, and pass xtd::drawing::string_format::generic_typographic. Also, ensure the xtd::drawing::text::text_rendering_hint for the xtd::drawing::graphics is xtd::drawing::text::text_rendering_hint::anti_alias.
      size_f measure_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::size_f& layout_area, const xtd::drawing::string_format& format);
      /// @brief Measures the specified string when drawn with the specified xtd::drawing::font and formatted with the specified xtd::drawing::string_format.
      /// @param text xtd::ustring to measure.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param width Maximum width of the string in pixels.
      /// @param format xtd::drawing::string_format that represents formatting information, such as line spacing, for the string.
      /// @remarks The xtd::drawing::graphics::measure_string method is designed for use with individual strings and includes a small amount of extra space before and after the string to allow for overhanging glyphs. Also, the xtd::drawing::graphics::draw_string method adjusts glyph points to optimize display quality and might display a string narrower than reported byxtd::drawing::graphics::measure_string. To obtain metrics suitable for adjacent strings in layout (for example, when implementing formatted text), use the xtd::drawing::graphics::measure_character_ranges method or one of the xtd::drawing::graphics::measure_string methods that takes a xtd::drawing::string_format, and pass xtd::drawing::string_format::generic_typographic. Also, ensure the xtd::drawing::text::text_rendering_hint for the xtd::drawing::graphics is xtd::drawing::text::text_rendering_hint::anti_alias.
      size_f measure_string(const xtd::ustring& text, const xtd::drawing::font& font, int32 width, const xtd::drawing::string_format& format);
      /// @brief Measures the specified string when drawn with the specified xtd::drawing::font and formatted with the specified xtd::drawing::string_format.
      /// @param text xtd::ustring to measure.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param layout_area xtd::drawing::size_f structure that specifies the maximum layout area for the text.
      /// @param format xtd::drawing::string_format that represents formatting information, such as line spacing, for the string.
      /// @param characters_fitted Number of characters in the string.
      /// @param lines_filled Number of text lines in the string.
      /// @remarks The xtd::drawing::graphics::measure_string method is designed for use with individual strings and includes a small amount of extra space before and after the string to allow for overhanging glyphs. Also, the xtd::drawing::graphics::draw_string method adjusts glyph points to optimize display quality and might display a string narrower than reported byxtd::drawing::graphics::measure_string. To obtain metrics suitable for adjacent strings in layout (for example, when implementing formatted text), use the xtd::drawing::graphics::measure_character_ranges method or one of the xtd::drawing::graphics::measure_string methods that takes a xtd::drawing::string_format, and pass xtd::drawing::string_format::generic_typographic. Also, ensure the xtd::drawing::text::text_rendering_hint for the xtd::drawing::graphics is xtd::drawing::text::text_rendering_hint::anti_alias.
      size_f measure_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::size_f& layout_area, const xtd::drawing::string_format& format, size_t characters_fitted, size_t lines_filled);
      
      /// @brief Multiplies the world transformation of this xtd::drawing::graphics and specified the xtd::drawing::drawing_2d::matrix.
      /// @param matrix 4x4 xtd::drawing::drawing_2d::matrix that multiplies the world transformation.
      /// @remarks This method prepends the matrix specified by the matrix parameter, so that the result is matrix x world transformation.
      void multiply_transform(const xtd::drawing::drawing_2d::matrix& matrix);
      /// @brief Multiplies the world transformation of this xtd::drawing::graphics and specified the xtd::drawing::drawing_2d::matrix with specified order.
      /// @param matrix 4x4 xtd::drawing::drawing_2d::matrix that multiplies the world transformation.
      /// @param order Member of the xtd::drawing::drawing_2d::matrix_order enumeration that determines the order of the multiplication.
      /// @remarks This method prepends the matrix specified by the matrix parameter, so that the result is matrix x world transformation.
      void multiply_transform(const xtd::drawing::drawing_2d::matrix& matrix, xtd::drawing::drawing_2d::matrix_order order);
      
      /// @brief Releases a device context handle obtained by a previous call to the xtd::drawing::graphics::get_hdc() method of this xtd::drawing::graphics.
      /// @param hdc Handle to a device context obtained by a previous call to the xtd::drawing::graphics::get_hdc() method of this xtd::drawing::graphics.
      /// @remarks The device context is a Windows structure based on GDI that defines a set of graphical objects and their associated attributes, as well as the graphical modes that affect output. This method returns that device context with the exception of a font. Because a font is not selected, calls to the xtd::drawing::graphics::from_hdc method using a handle returned from the xtd::drawing::graphics::get_hdc method will fail.
      /// @remarks Calls to the xtd::drawing::graphics::get_hdc and xtd::drawing::graphics::release_hdc methods must appear in pairs. During the scope of a xtd::drawing::graphics::get_hdc and xtd::drawing::graphics::release_hdc method pair, you usually make only calls to GDI functions. Calls in that scope made to GDI+ methods of the xtd::drawing::graphics that produced the hdc parameter fail with an ObjectBusy error. Also, GDI+ ignores any state changes made to the xtd::drawing::graphics of the hdc parameter in subsequent operations.
      void release_hdc(intptr hdc);
      
      /// @brief Resets the clip region of this xtd::drawing::graphics to an infinite region.
      /// @remarks When the clipping region of a xtd::drawing::graphics is infinite, items that this xtd::drawing::graphics draws are not clipped.
      void reset_clip();
      
      /// @brief Resets the world transformation matrix of this xtd::drawing::graphics to the identity matrix.
      /// @remarks The identity matrix represents a transformation with no scaling, rotation, or translation. Resetting the world transformation of this xtd::drawing::graphics to the identity matrix means that its world transformation does not change the geometry of transformed items.
      void reset_transform();
      
      /// @brief Restores the state of this xtd::drawing::graphics to the state represented by a xtd::drawing::drawing_2d::graphics_state.
      /// @param gstate xtd::drawing::drawing_2d::graphics_state that represents the state to which to restore this xtd::drawing::graphics.
      /// @remarks When you call the xtd::drawing::graphics::save method of a xtd::drawing::graphics, an information block that holds the state of the xtd::drawing::graphics is put on a stack. The xtd::drawing::graphics::save method returns a xtd::drawing::drawing_2d::graphics_state that identifies that information block. When you pass the identifying xtd::drawing::drawing_2d::graphics_state to the xtd::drawing::graphics::restore method, the information block is removed from the stack and is used to restore the xtd::drawing::graphics to the state it was in at the time of the xtd::drawing::graphics::save method call. Note that the xtd::drawing::drawing_2d::graphics_state returned by a given call to the Save method can be passed only once to the xtd::drawing::graphics::restore method.
      /// @remarks Calls to the xtd::drawing::graphics::save method can be nested; that is, you can call the xtd::drawing::graphics::save method several times before you call the xtd::drawing::graphics::restore method. Each time you call the xtd::drawing::graphics::save method, an information block is put on the stack, and you receive a xtd::drawing::drawing_2d::graphics_state for the information block. When you pass one of those objects to the xtd::drawing::graphics::restore method, the xtd::drawing::graphics is returned to the state it was in at the time of the xtd::drawing::graphics::save method call that returned that particular xtd::drawing::drawing_2d::graphics_state. The information block placed on the stack by thatxtd::drawing::graphics::sSave method call is removed from the stack, and all information blocks placed on that stack after that xtd::drawing::graphics::save method call are also removed.
      void restore(const xtd::drawing::drawing_2d::graphics_state& gstate);
      
      /// @brief Applies the specified rotation to the transformation matrix of this xtd::drawing::graphics.
      /// @param angle Angle of rotation in degrees.
      /// @remarks The rotation operation consists of multiplying the transformation matrix by a matrix whose elements are derived from the angle parameter. This method applies the rotation by prepending it to the transformation matrix.
      void rotate_transform(float angle);
      /// @brief Applies the specified rotation to the transformation matrix of this xtd::drawing::graphics in the specified order.
      /// @param angle Angle of rotation in degrees.
      /// @param order Member of the xtd::drawing::drawing_2d::matrix_order enumeration that specifies whether the rotation is prepended or appended to the transformation matrix.
      /// @remarks The rotation operation consists of multiplying the transformation matrix by a matrix whose elements are derived from the angle parameter. This method applies the rotation by prepending it to the transformation matrix.
      void rotate_transform(float angle, xtd::drawing::drawing_2d::matrix_order order);
      
      /// @brief Saves the current state of this xtd::drawing::graphics and identifies the saved state with a xtd::drawing::drawing_2d::graphics_state.
      /// @return This method returns a xtd::drawing::drawing_2d::graphics_state that represents the saved state of this xtd::drawing::graphics.
      /// @remarks When you call the xtd::drawing::graphics::save method of a xtd::drawing::graphics, an information block that holds the state of the xtd::drawing::graphics is put on a stack. The xtd::drawing::graphics::save method returns a xtd::drawing::drawing_2d::graphics_state that identifies that information block. When you pass the identifying xtd::drawing::drawing_2d::graphics_state to the xtd::drawing::graphics::restore method, the information block is removed from the stack and is used to restore the xtd::drawing::graphics to the state it was in at the time of the xtd::drawing::graphics::save method call. Note that the xtd::drawing::drawing_2d::graphics_state returned by a given call to the Save method can be passed only once to the xtd::drawing::graphics::restore method.
      /// @remarks Calls to the xtd::drawing::graphics::save method can be nested; that is, you can call the xtd::drawing::graphics::save method several times before you call the xtd::drawing::graphics::restore method. Each time you call the xtd::drawing::graphics::save method, an information block is put on the stack, and you receive a xtd::drawing::drawing_2d::graphics_state for the information block. When you pass one of those objects to the xtd::drawing::graphics::restore method, the xtd::drawing::graphics is returned to the state it was in at the time of the xtd::drawing::graphics::save method call that returned that particular xtd::drawing::drawing_2d::graphics_state. The information block placed on the stack by thatxtd::drawing::graphics::sSave method call is removed from the stack, and all information blocks placed on that stack after that xtd::drawing::graphics::save method call are also removed.
      xtd::drawing::drawing_2d::graphics_state save();
      
      /// @brief Applies the specified scaling operation to the transformation matrix of this xtd::drawing::graphics by prepending it to the object's transformation matrix.
      /// @param sx Scale factor in the x direction.
      /// @param sy Scale factor in the y direction.
      /// @remarks The scaling operation consists of multiplying the transformation matrix by a diagonal matrix whose elements are (sx, sy, 1). This method prepends the transformation matrix of the xtd::drawing::graphics by the scaling matrix.
      void scale_transform(float sx, float sy);
      /// @brief Applies the specified scaling operation to the transformation matrix of this xtd::drawing::graphics in the specified order.
      /// @param sx Scale factor in the x direction.
      /// @param sy Scale factor in the y direction.
      /// @param order Member of the xtd::drawing::drawing_2d::matrix_order enumeration that specifies whether the scaling operation is prepended or appended to the transformation matrix.
      /// @remarks The scaling operation consists of multiplying the transformation matrix by a diagonal matrix whose elements are (sx, sy, 1). This method prepends the transformation matrix of the xtd::drawing::graphics by the scaling matrix.
      void scale_transform(float sx, float sy, xtd::drawing::drawing_2d::matrix_order order);
      
      /// @brief Translates the clipping region of this xtd::drawing::graphics by specified amounts in the horizontal and vertical directions.
      /// @param dx The x-coordinate of the translation.
      /// @param dy The y-coordinate of the translation.
      void translate_clip(int32 dx, int32 dy);
      /// @brief Translates the clipping region of this xtd::drawing::graphics by specified amounts in the horizontal and vertical directions.
      /// @param dx The x-coordinate of the translation.
      /// @param dy The y-coordinate of the translation.
      void translate_clip(float dx, float dy);
      
      /// @brief Changes the origin of the coordinate system by prepending the specified translation to the transformation matrix of this xtd::drawing::graphics
      /// @param dx The x-coordinate of the translation.
      /// @param dy The y-coordinate of the translation.
      /// @remarks The translation operation consists of multiplying the transformation matrix by a matrix whose translation part is the dx and dy parameters. This method prepends or appends the transformation matrix of the xtd::drawing::graphics by the translation matrix according to the order parameter.
      void translate_transform(float dx, float dy);
      /// @brief Changes the origin of the coordinate system by prepending the specified translation to the transformation matrix of this xtd::drawing::graphics in the specified order.
      /// @param dx The x-coordinate of the translation.
      /// @param dy The y-coordinate of the translation.
      /// @param order Member of the xtd::drawing::drawing_2d::matrix_order enumeration that specifies whether the translation is prepended or appended to the transformation matrix.
      /// @remarks The translation operation consists of multiplying the transformation matrix by a matrix whose translation part is the dx and dy parameters. This method prepends or appends the transformation matrix of the xtd::drawing::graphics by the translation matrix according to the order parameter.
      void translate_transform(float dx, float dy, xtd::drawing::drawing_2d::matrix_order order);
      
      /// @brief Trims the specified string for a specified width with the specified xtd::drawing::font and with the specified xtd::drawing::string_trimming.
      /// @param text xtd::ustring to measure.
      /// @param font xtd::drawing::font that defines the text format of the string.
      /// @param width Specifies the maximum width for the text.
      /// @param trimming One of xtd::drawing::string_trimming values.
      xtd::ustring trim_string(const xtd::ustring& text, const xtd::drawing::font& font, float width, xtd::drawing::string_trimming trimming);
      
      xtd::ustring to_string() const noexcept override {return get_type().full_name();}
      /// @}

      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates a new xtd::drawing::graphics from the specified handle to a device context.
      /// @param hdc Handle to a device context.
      /// @return This method returns a new xtd::drawing::graphics for the specified device context.
      /// @remarks Even if the display device has an associated ICM color profile, GDI+ will not use that profile by default. To enable ICM for a xtd::drawing::graphics, construct the xtd::drawing::graphics from an HDC after you pass the HDC (and ICM_ON) to the SetICMMode function. Then any drawing done by the xtd::drawing::graphics will be adjusted according to the ICM profile associated with the display device. Enabling ICM will result in slower performance.
      /// @remarks The state of the device context (mapping mode, logical unit, and the like) at the time you call xtd::drawing::graphics::from_hdc can affect rendering done by the xtd::drawing::graphics.
      static graphics from_hdc(intptr hdc);
      /// @brief Creates a new xtd::drawing::graphics from the specified handle to a device contextand handle to a device.
      /// @param hdc Handle to a device context.
      /// @param hdevice Handle to a device.
      /// @return This method returns a new xtd::drawing::graphics for the specified device context and device.
      /// @remarks Even if the display device has an associated ICM color profile, GDI+ will not use that profile by default. To enable ICM for a xtd::drawing::graphics, construct the xtd::drawing::graphics from an HDC after you pass the HDC (and ICM_ON) to the SetICMMode function. Then any drawing done by the xtd::drawing::graphics will be adjusted according to the ICM profile associated with the display device. Enabling ICM will result in slower performance.
      /// @remarks The state of the device context (mapping mode, logical unit, and the like) at the time you call xtd::drawing::graphics::from_hdc can affect rendering done by the xtd::drawing::graphics.
      static graphics from_hdc(intptr hdc, intptr hdevice);
      
      /// @brief Creates a new xtd::drawing::graphics from the specified handle to a window.
      /// @param hwnd Handle to a window.
      /// @return This method returns a new xtd::drawing::graphics for the specified window handle.
      static graphics from_hwnd(intptr hwnd);
      
      /// @brief Creates a new xtd::drawing::graphics from the specified xtd::drawing::image.
      /// @param image xtd::drawing::image from which to create the new xtd::drawing::graphics.
      /// @return This method returns a new xtd::drawing::graphics for the specified Image.
      /// @remarks If the image has an indexed pixel format, this method throws an exception with the message, "A xtd::drawing::graphics object cannot be created from an image that has an indexed pixel format." The indexed pixel formats are shown in the following list.
      /// * xtd::drawing::imaging::pixel_format::format_1bpp_indexed
      /// * xtd::drawing::imaging::pixel_format::format_4bpp_indexed
      /// * xtd::drawing::imaging::pixel_format::format_8bpp_indexed
      /// @remarks You can save the indexed image as another format by using the xtd::drawing:image::save(xtd::ustring, xtd::drawing::imaging::image_format) method and then retrieve a xtd::drawing::graphics object for the new image.
      /// @remarks This method also throws an exception if the image has any of the following pixel formats.
      /// * xtd::drawing::imaging::pixel_format::undefined
      /// * xtd::drawing::imaging::pixel_format::dont_care
      /// * xtd::drawing::imaging::pixel_format::format_16bpp_argb1555
      /// * xtd::drawing::imaging::pixel_format::format_16bpp_gray_scale
      static graphics from_image(const xtd::drawing::image& image);
      /// @}

    private:
      friend xtd::drawing::image;
      friend xtd::drawing::region;
      float to_page_unit(float value) const;
      static float to_page_unit(float value, xtd::drawing::graphics_unit page_unit, float page_scale, float dpi);
      int32 to_pixels(int32 value) const;
      float to_pixels(float value) const;
      static float to_pixels(float value, xtd::drawing::graphics_unit page_unit, float page_scale, float dpi);
      friend xtd::forms::control;
      friend xtd::forms::control_paint;
      friend xtd::forms::paint_event_args;
      friend xtd::forms::screen;
      
      explicit graphics(intptr handle);
      graphics(intptr handle, const drawing::region& region);
      void draw_image_disabled(const xtd::drawing::image& image, float x, float y, float width, float height, float brightness);
      
      std::shared_ptr<data> data_;
    };
  }
}

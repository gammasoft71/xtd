#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <tuple>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing_native_export.h>
#include "hot_key_prefixes.h"
#include "path_fill_modes.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class graphics;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains graphics native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ graphics final static_ {
        friend xtd::drawing::graphics;
      protected:
        /// @name Protected methods
        
        /// @{
        /// @brief Performs a bit-block transfer of color data, corresponding to a rectangle of pixels, from the screen to the drawing surface of the graphics.
        /// @param handle The graphics handle.
        /// @param handle_source The source graphics handle.
        /// @param source_x The x-coordinate of the upper-left corner of the source rectangle.
        /// @param source_y The x-coordinate of the upper-left corner of the source rectangle.
        /// @param destination_x The x-coordinate of the upper-left corner of the destination rectangle.
        /// @param destination_y The y-coordinate of the upper-left corner of the destination rectangle.
        /// @param block_region_width The width of the source and destination rectangle.
        /// @param block_region_height The height of the source and destination rectangle.
        /// @param copy_pixel_operation The copy pixel operation values (see copy_pixel_operations.h for more information).
        /// @warning Internal use only
        static void copy_from_graphics(intptr handle, intptr handle_source, int32 source_x, int32 source_y, int32 destination_x, int32 destination_y, int32 block_region_width, int32 block_region_height, int32 copy_pixel_operation);
        /// @brief Clears the entire drawing surface and fills it with the specified background color.
        /// @param handle The graphics handle.
        /// @param a The alpha component of the background color of the drawing surface.
        /// @param r The red component of the background color of the drawing surface.
        /// @param g The green component of the background color of the drawing surface.
        /// @param b The blue component of the background color of the drawing surface.
        /// @warning Internal use only
        static void clear(intptr handle, xtd::byte a, xtd::byte r, xtd::byte g, xtd::byte b);
        
        /// @brief Sets a region handle that limits the drawing region of the graphics.
        /// @param handle The graphics handle.
        /// @param region A region handle that limits the portion of the graphics that is currently available for drawing.
        /// @warning Internal use only
        static void clip(intptr handle, intptr region);
        
        /// @brief Sets a value that specifies how composited images are drawn to the graphics.
        /// @param handle The graphics handle.
        /// @param compositing_mode This property specifies a compositing mode value (see compositing_modes.h for more information).
        /// @warning Internal use only
        static void compositing_mode(intptr handle, int32 compositing_mode);
        
        /// @brief Sets the rendering quality of composited images drawn to the graphics.
        /// @param handle The graphics handle.
        /// @param compositing_quality This property specifies a compositing quality value (see compositing_qualities.h for more information).
        /// @warning Internal use only
        static void compositing_quality(intptr handle, int32 compositing_quality);
        
        /// @brief Performs a bit-block transfer of color data, corresponding to a rectangle of pixels, from the screen to the drawing surface of the graphics.
        /// @param handle The graphics handle.
        /// @param source_x The x-coordinate of the upper-left corner of the source rectangle.
        /// @param source_y The y-coordinate of the upper-left corner of the source rectangle.
        /// @param destination_x The x-coordinate of the upper-left corner of the destination rectangle.
        /// @param destination_y The x-coordinate of the upper-left corner of the destination rectangle.
        /// @param block_region_width The width of the area to be transferred.
        /// @param block_region_height The height of the area to be transferred.
        /// @param copy_pixel_operation The copy pixel operation values (see copy_pixel_operations.h for more information).
        /// @warning Internal use only
        static void copy_from_screen(intptr handle, int32 source_x, int32 source_y, int32 destination_x, int32 destination_y, int32 block_region_width, int32 block_region_height, int32 copy_pixel_operation);
        
        /// @brief Destroys graphics_path.
        /// @param handle The graphics handle.
        /// @warning Internal use only
        static void destroy(intptr handle);
        
        /// @brief Draws an arc representing a portion of an ellipse specified by a pair of coordinates, a width, and a height.
        /// @param handle The graphics handle.
        /// @param pen A pen handle that determines the color, width, and style of the arc.
        /// @param x The x-coordinate of the upper-left corner of the rectangle that defines the ellipse.
        /// @param y The y-coordinate of the upper-left corner of the rectangle that defines the ellipse.
        /// @param width Width of the rectangle that defines the ellipse.
        /// @param height Height of the rectangle that defines the ellipse.
        /// @param start_angle Angle in degrees measured clockwise from the x-axis to the starting point of the arc.
        /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to ending point of the arc.
        /// @warning Internal use only
        static void draw_arc(intptr handle, intptr pen, float x, float y, float width, float height, float start_angle, float sweep_angle);
        
        /// @brief Draws a Bézier spline defined by four ordered pairs of coordinates that represent points.
        /// @param handle The graphics handle.
        /// @param pen A pen handle that determines the color, width, and style of the curve.
        /// @param x1 The x-coordinate of the starting point of the curve.
        /// @param y1 The y-coordinate of the starting point of the curve.
        /// @param x2 The x-coordinate of the first control point of the curve.
        /// @param y2 The y-coordinate of the first control point of the curve.
        /// @param x3 The x-coordinate of the second control point of the curve.
        /// @param y3 The y-coordinate of the second control point of the curve.
        /// @param x4 The x-coordinate of the ending point of the curve.
        /// @param y4 The y-coordinate of the ending point of the curve.
        /// @warning Internal use only
        static void draw_bezier(intptr handle, intptr pen, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
        
        /// @brief Draws a series of Bézier splines from an array of std::pair<float, float> structures.
        /// @param handle The graphics handle.
        /// @param pen A pen handle that determines the color, width, and style of the curve.
        /// @param points Array of std::pair<float, float> structures that represent the points that determine the curve. The number of points in the array should be a multiple of 3 plus 1, such as 4, 7, or 10.
        /// @warning Internal use only
        static void draw_beziers(intptr handle, intptr pen, const std::vector<std::pair<float, float>>& points);
        
        /// @brief Draws a closed cardinal spline defined by an array of std::pair<float, float> structures using a specified tension.
        /// @param handle The graphics handle.
        /// @param pen A pen handle that determines the color, width, and style of the curve.
        /// @param points Array of std::pair<float, float> structures that define the spline.
        /// @param tension alue greater than or equal to 0.0F that specifies the tension of the curve.
        /// @warning Internal use only
        static void draw_closed_curve(intptr handle, intptr pen, std::vector<std::pair<float, float>> points, float tension);
        
        /// @brief Draws a cardinal spline through a specified array of std::pair<float, float> structures using a specified tension. The drawing begins offset from the beginning of the array.
        /// @param handle The graphics handle.
        /// @param pen A pen handle that determines the color, width, and style of the curve.
        /// @param points Array of std::pair<float, float> structures that define the spline.
        /// @param offset Offset from the first element in the array of the points parameter to the starting point in the curve.
        /// @param number_of_segments Number of segments after the starting point to include in the curve.
        /// @param tension Value greater than or equal to 0.0F that specifies the tension of the curve.
        /// @warning Internal use only
        static void draw_curve(intptr handle, intptr pen, std::vector<std::pair<float, float>> points, float tension);
        
        /// @brief Draws an ellipse defined by a bounding rectangle specified by coordinates for the upper-left corner of the rectangle, a height, and a width.
        /// @param handle The graphics handle.
        /// @param pen A pen handle that determines the color, width, and style of the ellipse.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
        /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
        /// @param width Width of the bounding rectangle that defines the ellipse.
        /// @param height Height of the bounding rectangle that defines the ellipse.
        /// @warning Internal use only
        static void draw_ellipse(intptr handle, intptr pen, float x, float y, float width, float heigh);
        
        /// @brief Draws the specified image, using its original physical size, at the specified location, and size.
        /// @param handle The graphics handle.
        /// @param image An image handle to draw.
        /// @param x The x-coordinate of the upper-left corner of the drawn image.
        /// @param y The y-coordinate of the upper-left corner of the drawn image.
        /// @warning Internal use only
        static void draw_image(intptr handle, intptr image, float x, float y, float width, float height);
        
        /// @brief Draws the specified image, using its original physical size, at the specified location.
        /// @param handle The graphics handle.
        /// @param image An image handle to draw.
        /// @param x The x-coordinate of the upper-left corner of the drawn image.
        /// @param y The y-coordinate of the upper-left corner of the drawn image.
        /// @param width Width of the bounding rectangle that defines the image.
        /// @param height Height of the bounding rectangle that defines the image.
        /// @warning Internal use only
        static void draw_image(intptr handle, intptr image, float dest_x, float dest_y, float dest_width, float dest_height, float src_x, float src_y, float src_width, float src_height);

        /// @brief Draws the specified dosabled image at the specified location and size.
        /// @param handle The graphics handle.
        /// @param image An image handle to draw.
        /// @param x The x-coordinate of the upper-left corner of the drawn image.
        /// @param y The y-coordinate of the upper-left corner of the drawn image.
        /// @param width Width of the bounding rectangle that defines the image.
        /// @param height Height of the bounding rectangle that defines the image.
        /// @param brightness The image brightness from 0.0 to 1.0.
        /// @warning Internal use only
        static void draw_image_disabled(intptr handle, intptr image, float x, float y, float width, float height, float brightness);
        
        /// @brief Draws a line connecting the two points specified by the coordinate pairs.
        /// @param handle The graphics handle.
        /// @param pen A pen handle that determines the color, width, and style of the line.
        /// @param x1 The x-coordinate of the first point.
        /// @param y1 The y-coordinate of the first point.
        /// @param x2 The x-coordinate of the second point.
        /// @param y2 The y-coordinate of the second point.
        /// @warning Internal use only
        static void draw_line(intptr handle, intptr pen, float x1, float y1, float x2, float y2);
        
        /// @brief Draws a series of line segments that connect an array of std::pair<float, float> structures.
        /// @param handle The graphics handle.
        /// @param pen A pen handle that determines the color, width, and style of the line segments.
        /// @param points Array of std::pair<float, float> structures that represent the points to connect.
        /// @warning Internal use only
        static void draw_lines(intptr handle, intptr pen, const std::vector<std::pair<float, float>>& points);
        
        /// @brief Draws a graphics path.
        /// @param handle The graphics handle.
        /// @param pen A pen handle that determines the color, width, and style of the path.
        /// @param path A graphics path handle to draw.
        /// @warning Internal use only
        static void draw_path(intptr handle, intptr pen, intptr graphics_path);
        
        /// @brief Draws a pie shape defined by an ellipse specified by a coordinate pair, a width, a height, and two radial lines.
        /// @param handle The graphics handle.
        /// @param pen Pen that determines the color, width, and style of the pie shape.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie shape comes.
        /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie shape comes.
        /// @param width Width of the bounding rectangle that defines the ellipse from which the pie shape comes.
        /// @param heught Height of the bounding rectangle that defines the ellipse from which the pie shape comes.
        /// @param start_angle Angle measured in degrees clockwise from the x-axis to the first side of the pie shape.
        /// @param sweep_angle Angle measured in degrees clockwise from the startAngle parameter to the second side of the pie shape.
        /// @warning Internal use only
        static void draw_pie(intptr handle, intptr pen, float x, float y, float width, float height, float start_angle, float sweep_angle);
        
        /// @brief Draws a polygon defined by an array of std::pair<float, float> structures.
        /// @param handle The graphics handle.
        /// @param pen A pen handle that determines the color, width, and style of the polygon.
        /// @param points Array of std::pair<float, float> structures that represent the vertices of the polygon.
        /// @warning Internal use only
        static void draw_polygon(intptr handle, intptr pen, const std::vector<std::pair<float, float>>& points);
        
        /// @brief Draws a rectangle specified by a coordinate pair, a width, and a height.
        /// @param handle The graphics handle.
        /// @param pen A pen handle that determines the color, width, and style of the rectangle.
        /// @param x The x-coordinate of the upper-left corner of the rectangle to draw.
        /// @param y The y-coordinate of the upper-left corner of the rectangle to draw.
        /// @param width The width of the rectangle to draw.
        /// @param height The height of the rectangle to draw.
        /// @warning Internal use only
        static void draw_rectangle(intptr handle, intptr pen, float x, float y, float width, float height);
        
        /// @brief Draws a series of rectangles specified by std::tuple<float, float, float, float> structures.
        /// @param handle The graphics handle.
        /// @param pen A pen handle that determines the color, width, and style of the outlines of the rectangles.
        /// @param rects Array of std::tuple<float, float, float, float> structures that represent the rectangles to draw.
        /// @warning Internal use only
        static void draw_rectangles(intptr handle, intptr pen, std::vector<std::tuple<float, float, float, float>>& rects);
        
        /// @brief Draws the specified text string at the specified location with the specified brush, font and angle.
        /// @param handle The graphics handle.
        /// @param s String to draw.
        /// @param font A font handle that defines the text format of the string.
        /// @param brush A brush handle that determines the color and texture of the drawn text.
        /// @param x The x-coordinate of the upper-left corner of the drawn text.
        /// @param y The y-coordinate of the upper-left corner of the drawn text.
        /// @param angle The angle, measured in degrees clockwise from the x-axis, of the text's orientation line.
        /// @warning Internal use only
        static void draw_rotated_string(intptr handle, const xtd::ustring& text, intptr font, intptr brush, float x, float y, float angle);
        
        /// @brief Draws a rounded rectangle specified by a coordinate pair, a width, a height, and radius.
        /// @param handle The graphics handle.
        /// @param pen A pen handle that determines the color, width, and style of the rounded rectangle.
        /// @param x The x-coordinate of the upper-left corner of the rounded rectangle to draw.
        /// @param y The y-coordinate of the upper-left corner of the rounded rectangle to draw.
        /// @param width The width of the rounded rectangle to draw.
        /// @param height The height of the rounded rectangle to draw.
        /// @param radius The radius of the rounded rectange angles.
        /// @warning Internal use only
        static void draw_rounded_rectangle(intptr handle, intptr pen, float x, float y, float width, float height, float radius);
        
        /// @brief Draws the specified text string at the specified point with the specified brush and font handle using the formatting attributes of the format.
        /// @param handle The graphics handle.
        /// @param text String to draw.
        /// @param font A font handle that defines the text format of the string.
        /// @param brush A brush handle that determines the color and texture of the drawn text.
        /// @param x The x-coordinate of the upper-left corner of the string.
        /// @param y The y-coordinate of the upper left corner of the string.
        /// @param alignment The alignment of the text (see string_alignments.h for more information).
        /// @param line_alignment The alignment of the text (see string_alignments.h for more information).
        /// @param hot_key_prefix The hotkey prefix value (see hot_key_prefixes.h for more information).
        /// @param trimming The trimming value for the text (see string_trimmings.h for more information).
        /// @warning Internal use only
        static void draw_string(intptr handle, const xtd::ustring& text, intptr font, intptr brush, float x, float y, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming);
        /// @brief Draws the specified text string at the specified rectangle with the specified brush and font handle using the formatting attributes of the format.
        /// @param handle The graphics handle.
        /// @param text String to draw.
        /// @param font A font handle that defines the text format of the string.
        /// @param brush A brush handle that determines the color and texture of the drawn text.
        /// @param x The x-coordinate of the upper-left corner of the string.
        /// @param y The y-coordinate of the upper left corner of the string.
        /// @param width The width of the text.
        /// @param height The height of the text.
        /// @param alignment The alignment of the text (see string_alignments.h for more information).
        /// @param line_alignment The alignment of the text (see string_alignments.h for more information).
        /// @param hot_key_prefix The hotkey prefix value (see hot_key_prefixes.h for more information).
        /// @param trimming The trimming value for the text (see string_trimmings.h for more information).
        /// @param no_wrap True if the text wrapping between lines when formatting within a rectangle is disabled; otherwise false.
        /// @warning Internal use only
        static void draw_string(intptr handle, const xtd::ustring& text, intptr font, intptr brush, float x, float y, float width, float height, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming, int32 string_formats);
        
        /// @brief Fills the interior of a closed cardinal spline curve defined by an array of std::pair<float, float> structures.
        /// @param handle The graphics handle.
        /// @param brush A brush handle that determines the characteristics of the fill.
        /// @param points Array of std::pair<float, float> structures that define the spline.
        /// @param fill_mode A fill mode value that determines how the curve is filled (see fill_modes.h for more information).
        /// @param tension Value greater than or equal to 0.0F that specifies the tension of the curve.
        /// @warning Internal use only
        static void fill_closed_curve(intptr handle, intptr brush, std::vector<std::pair<float, float>> points, uint32 fill_mode, float tension);
        
        /// @brief Fills the interior of an ellipse defined by a bounding rectangle specified by a pair of coordinates, a width, and a height.
        /// @param handle The graphics handle.
        /// @param brush A brush handle that determines the characteristics of the fill.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
        /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
        /// @param width Width of the bounding rectangle that defines the ellipse.
        /// @param height Height of the bounding rectangle that defines the ellipse.
        /// @warning Internal use only
        static void fill_ellipse(intptr handle, intptr brush, float x, float y, float width, float heigh);
        
        /// @brief Fills the interior of a graphics path.
        /// @param handle The graphics handle.
        /// @param brush A brush handle that determines the characteristics of the fill.
        /// @param path A graphics path handle that represents the path to fill.
        /// @param mode A fill mode value that specifies how the interiors of shapes in the graphics path are filled (see fill_modes.h for more information).
        /// @warning Internal use only
        static void fill_path(intptr handle, intptr brush, intptr graphics_path, int32 mode);
        
        /// @brief Fills the interior of a pie section defined by an ellipse specified by a pair of coordinates, a width, a height, and two radial lines.
        /// @param handle The graphics handle.
        /// @param brush A brush handle that determines the characteristics of the fill.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie section comes.
        /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie section comes.
        /// @param width Width of the bounding rectangle that defines the ellipse from which the pie section comes.
        /// @param height Height of the bounding rectangle that defines the ellipse from which the pie section comes.
        /// @param start_angle Angle in degrees measured clockwise from the x-axis to the first side of the pie section.
        /// @param sweep_angle Angle in degrees measured clockwise from the start_angle parameter to the second side of the pie section.
        /// @warning Internal use only
        static void fill_pie(intptr handle, intptr brush, float x, float y, float width, float height, float start_angle, float sweep_angle);
        
        /// @brief Fills the interior of a polygon defined by an array of points specified by std::pair<float, float> structures using the specified fill mode.
        /// @param handle The graphics handle.
        /// @param brush A brush handle that determines the characteristics of the fill.
        /// @param points Array of std::pair<float, float> structures that represent the vertices of the polygon to fill.
        /// @param fill_mode Member of the fill mode value that determines the style of the fill (see fill_modes.h for more information).
        /// @warning Internal use only
        static void fill_polygon(intptr handle, intptr pen, const std::vector<std::pair<float, float>>& points, int32 fill_mode);
        
        /// @brief Fills the interior of a rectangle specified by a pair of coordinates, a width, and a height.
        /// @param handle The graphics handle.
        /// @param brush A brush handle that determines the characteristics of the fill.
        /// @param x The x-coordinate of the upper-left corner of the rectangle to fill.
        /// @param y The y-coordinate of the upper-left corner of the rectangle to fill.
        /// @param width Width of the rectangle to fill.
        /// @param height Height of the rectangle to fill.
        /// @warning Internal use only
        static void fill_rectangle(intptr handle, intptr brush, float x, float y, float width, float height);
        
        /// @brief Fills the interiors of a series of rectangles specified by std::tuple<float, float, float, float> structures.
        /// @param handle The graphics handle.
        /// @param brush A brush handle that determines the characteristics of the fill.
        /// @param rects Array of std::tuple<float, float, float, float> structures that represent the rectangles to fill.
        /// @warning Internal use only
        static void fill_rectangles(intptr handle, intptr brush, std::vector<std::tuple<float, float, float, float>>& rects);
        
        /// @brief Fills the interior of a region.
        /// @param handle The graphics handle.
        /// @param brush A brush handle that determines the characteristics of the fill.
        /// @param region A region handle that represents the area to fill.
        /// @warning Internal use only
        static void fill_region(intptr handle, intptr brush, intptr region);
        
        /// @brief Fills the interior of a rounded rectangle specified by a pair of coordinates, a width, a height, and a radius.
        /// @param handle The graphics handle.
        /// @param brush A brush handle that determines the characteristics of the fill.
        /// @param x The x-coordinate of the upper-left corner of the rounded rectangle to fill.
        /// @param y The y-coordinate of the upper-left corner of the rounded rectangle to fill.
        /// @param width Width of the rounded rectangle to fill.
        /// @param height Height of the rounded rectangle to fill.
        /// @param radius The radius of the rounded rectange angles.
        /// @warning Internal use only
        static void fill_rounded_rectangle(intptr handle, intptr brush, float x, float y, float width, float height, float radius);
        
        /// @brief Forces execution of all pending graphics operations with the method waiting or not waiting, as specified, to return before the operations finish.
        /// @param handle The graphics handle.
        /// @param intention A flush intention value that specifies whether the method returns immediately or waits for any existing operations to finish (see flush_intentions.h for more information).
        /// @warning Internal use only
        static void flush(intptr handle, int32 intention);
        
        /// @brief Creates a new graphics from the specified handle to a device context.
        /// @param hdc Handle to a device context.
        /// @return This method returns a new graphics handle for the specified device context.
        /// @warning Internal use only
        static intptr from_hdc(intptr hdc);
        /// @brief Creates a new graphics from the specified handle to a device contextand handle to a device.
        /// @param hdc Handle to a device context.
        /// @param hdevice Handle to a device.
        /// @return This method returns a new graphics handle for the specified device context and device.
        /// @warning Internal use only
        static intptr from_hdc(intptr hdc, intptr hdevice);
        
        /// @brief Creates a new graphics from the specified handle to a window.
        /// @param hwnd Handle to a window.
        /// @return This method returns a new graphics handle for the specified window handle.
        /// @warning Internal use only
        static intptr from_hwnd(intptr hwnd);
        
        /// @brief Creates a new graphics from the specified image.
        /// @param image image from which to create the new graphics.
        /// @return This method returns a new graphics handle for the specified Image.
        /// @warning Internal use only
        static intptr from_image(intptr image);
        
        /// @brief Gets the horizontal resolution of this graphics.
        /// @param handle The graphics handle.
        /// @return The value, in dots per inch, for the horizontal resolution supported by this graphics.
        /// @warning Internal use only
        static float get_dpi_x(intptr handle);
        
        /// @brief Gets the vertical resolution of this graphics.
        /// @param handle The graphics handle.
        /// @return The value, in dots per inch, for the vertical resolution supported by this graphics.
        /// @warning Internal use only
        static float get_dpi_y(intptr handle);
        
        /// @brief Gets the handle to the device context associated with this graphics.
        /// @param handle The graphics handle.
        /// @return Handle to the device context associated with this graphics.
        /// @warning Internal use only
        static intptr get_hdc(intptr handle);
        
        /// @brief Gets the nearest color to the specified color.
        /// @param handle The graphics handle.
        /// @param original_a The alpha component of color for which to find a match.
        /// @param original_r The red component of color for which to find a match.
        /// @param original_g The green component of color for which to find a match.
        /// @param original_b The blue component of color for which to find a match.
        /// @param nearest_a The alpha component of color that represents the nearest color to the one specified with the color parameter.
        /// @param nearest_r The red component of color that represents the nearest color to the one specified with the color parameter.
        /// @param nearest_g The green component of color that represents the nearest color to the one specified with the color parameter.
        /// @param nearest_b The blue component of color that represents the nearest color to the one specified with the color parameter.
        /// @warning Internal use only
        static void get_nearest_color(intptr handle, xtd::byte original_a, xtd::byte original_r, xtd::byte original_g, xtd::byte original_b, xtd::byte& nearest_a, xtd::byte& nearest_r, xtd::byte& nearest_g, xtd::byte& nearest_b);
        
        /// @brief Sets the interpolation mode associated with the graphics.
        /// @param handle The graphics handle.
        /// @param interpolation_mode An interpolation mode value (see interpolation_modes.h for more information).
        /// @warning Internal use only
        static void interpolation_mode(intptr handle, int32 interpolation_mode);
        
        /// @brief Sets a value specifying how pixels are offset during rendering of this graphics.
        /// @param handle The graphics handle.
        /// @param pixel_offst_mode This property specifies a pixel offset mode value (see pixel_offst_modes.h for more information).
        /// @warning Internal use only
        static void pixel_offset_mode(intptr handle, int32 pixel_offst_mode);
        
        /// @brief Measures the specified string when drawn with the specified font and formatted with the specified format.
        /// @param handle The graphics handle.
        /// @param text xtd::ustring to measure.
        /// @param font A font handle that defines the text format of the string.
        /// @param width The width of the text.
        /// @param height The height of the text.
        /// @param max_width The maximum width of the text.
        /// @param max_height The maximum height of the text.
        /// @param alignment The alignment of the text (see string_alignments.h for more information).
        /// @param line_alignment The alignment of the text (see string_alignments.h for more information).
        /// @param hot_key_prefix The hotkey prefix value (see hot_key_prefixes.h for more information).
        /// @param trimming The trimming value for the text (see string_trimmings.h for more information).
        /// @param characters_fitted Number of characters in the string.
        /// @param lines_filled Number of text lines in the string.
        /// @warning Internal use only
        static void measure_string(intptr handle, const xtd::ustring& text, intptr font, float& width, float& height, float max_width, float max_height, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming, size_t characters_fitted, size_t lines_filled, bool measure_trailing_spaces);
        
        /// @brief Releases a device context handle obtained by a previous call to the xtd::drawing::native::graphics::get_hdc() method of the graphics.
        /// @param handle The graphics handle.
        /// @param hdc Handle to a device context obtained by a previous call to the xtd::drawing::native::graphics::get_hdc() method of the graphics.
        /// @warning Internal use only
        static void release_hdc(intptr handle, intptr hdc);
        
        /// @brief Resets the world transformation matrix of the graphics to the identity matrix.
        /// @param handle The graphics handle.
        /// @warning Internal use only
        static void reset_transform(intptr handle);
        
        /// @brief Restores the state of the graphics to the state represented by a graphics state.
        /// @param handle The graphics handle.
        /// @param gstate A graphics state handle that represents the state to which to restore the graphics.
        /// @warning Internal use only
        static void restore(intptr handle, intptr& gstate);
        
        /// @brief Applies the specified rotation to the transformation matrix of the graphics in the specified order.
        /// @param handle The graphics handle.
        /// @param angle Angle of rotation in degrees.
        /// @param order A matrix order value that specifies whether the rotation is prepended or appended to the transformation matrix (see matrix_orders.h for more information).
        /// @warning Internal use only
        static void rotate_transform(intptr handle, float angle, int32 order);
        
        /// @brief Saves the current state of the graphics and identifies the saved state with a graphics state.
        /// @param handle The graphics handle.
        /// @return This method returns a graphics state handle that represents the saved state of the graphics.
        /// @warning Internal use only
        static intptr save(intptr handle);
        
        /// @brief Applies the specified scaling operation to the transformation matrix of the graphics in the specified order.
        /// @param handle The graphics handle.
        /// @param sx Scale factor in the x direction.
        /// @param sy Scale factor in the y direction.
        /// @param order A matrix order value that specifies whether the scaling operation is prepended or appended to the transformation matrix (see matrix_orders.h for more information).
        /// @warning Internal use only
        static void scale_transform(intptr handle, float sx, float sy, int32 order);
        
        /// @brief Sets the rendering quality for the graphics.
        /// @param handle The graphics handle.
        /// @param smoothing_mode A smoothing mode value (see smoothing_modes.h for more information).
        /// @warning Internal use only
        static void smoothing_mode(intptr handle, int32 smoothing_mode);
        
        /// @brief Sets the gamma correction value for rendering text.
        /// @param handle The graphics handle.
        /// @param text_contrast The gamma correction value used for rendering antialiased and ClearType text.
        /// @remarks The gamma correction value must be between 0 and 12. The default value is 4.
        /// @warning Internal use only
        static void text_contrast(intptr handle, int32 text_contrast);
        
        /// @brief Sets the rendering mode for text associated with the graphics.
        /// @param handle The graphics handle.
        /// @param text_rendering_hint A text rendering hint value (see text_rendering_hints.h for more information).
        /// @warning Internal use only
        static void text_rendering_hint(intptr handle, int32 text_rendering_hint);
        
        /// @brief Gets a copy of the geometric world transformation for the graphics.
        /// @param handle The graphics handle.
        /// @return A matrix handle that represents the geometric world transformation for the graphics.
        /// @warning Internal use only
        static intptr transform(intptr handle);
        /// @brief Sets a copy of the geometric world transformation for the graphics.
        /// @param handle The graphics handle.
        /// @param value A matrix handle that represents the geometric world transformation for the graphics.
        /// @warning Internal use only
        static void transform(intptr handle, intptr matrix);
        
        /// @brief Changes the origin of the coordinate system by prepending the specified translation to the transformation matrix of the graphics in the specified order.
        /// @param handle The graphics handle.
        /// @param dx The x-coordinate of the translation.
        /// @param dy The y-coordinate of the translation.
        /// @param order A matrix order value that specifies whether the translation is prepended or appended to the transformation matrix (see matrix_orders.h for more information).
        /// @warning Internal use only
        static void translate_transform(intptr handle, float dx, float dy, int32 order);
        
        /// @brief Trims the specified string for a specified width with the specified font and trimming.
        /// @param handle The graphics handle.
        /// @param text xtd::ustring to measure.
        /// @param font A font handle that defines the text format of the string.
        /// @param width The width of the text.
        /// @param trimming The trimming value for the text (see string_trimmings.h for more information).
        /// @warning Internal use only
        static xtd::ustring trim_string(intptr handle, const xtd::ustring& text, intptr font, float width, int32 trimming);
        
        /// @brief Gets the bounding rectangle of the visible clipping region of the graphics.
        /// @param handle The graphics handle.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle for the visible clipping region of the graphics.
        /// @param y The y-coordinate of the upper-left corner of the bounding rectangle for the visible clipping region of the graphics.
        /// @param width Width of the bounding rectangle for the visible clipping region of the graphics.
        /// @param height Height of the bounding rectangle for the visible clipping region of the graphics.
        /// @warning Internal use only
        static void visible_clip_bounds(intptr handle, float& x, float& y, float& width, float& height);
        /// @}
      };
    }
  }
}

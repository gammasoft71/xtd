#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <vector>
#include <utility>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    namespace drawing_2d {
      class graphics_path;
    }
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains graphics_path native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ graphics_path final static_ {
        friend xtd::drawing::drawing_2d::graphics_path;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Creates graphics_path.
        /// @return The created graphics_path handle.
        /// @warning Internal use only
        static intptr create();
        
        /// @brief Destroys graphics_path.
        /// @param handle The graphics_path handle.
        /// @warning Internal use only
        static void destroy(intptr handle);
        
        /// @brief Appends an elliptical arc to the current figure.
        /// @param handle The graphics_path handle.
        /// @param x The x-coordinate of the upper-left corner of the rectangular region that defines the ellipse from which the arc is drawn.
        /// @param y The y-coordinate of the upper-left corner of the rectangular region that defines the ellipse from which the arc is drawn.
        /// @param width The width of the rectangular region that defines the ellipse from which the arc is drawn.
        /// @param height The height of the rectangular region that defines the ellipse from which the arc is drawn.
        /// @param start_angle The starting angle of the arc, measured in degrees clockwise from the x-axis.
        /// @param sweep_angle The angle between start_angle and the end of the arc.
        /// @warning Internal use only
        static void add_arc(intptr handle, float x, float y, float width, float height, float start_angle, float sweep_angle);
        
        /// @brief Adds a cubic Bézier curve to the current figure.
        /// @param handle The graphics_path handle.
        /// @param x1 The x-coordinate of the starting point of the curve.
        /// @param y1 The y-coordinate of the starting point of the curve.
        /// @param x2 The x-coordinate of the first control point for the curve.
        /// @param y2 The y-coordinate of the first control point for the curve.
        /// @param x3 The x-coordinate of the second control point for the curve.
        /// @param y3 The y-coordinate of the second control point for the curve.
        /// @param x4 The x-coordinate of the endpoint of the curve.
        /// @param y4 The y-coordinate of the endpoint of the curve.
        /// @warning Internal use only
        static void add_bezier(intptr handle, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
        
        /// @brief Adds a sequence of connected cubic Bézier curves to the current figure.
        /// @param handle The graphics_path handle.
        /// @param points An array of std::pair<float, float> structures that represents the points that define the curves.
        /// @warning Internal use only
        static void add_beziers(intptr handle, std::vector<std::pair<float, float>> points);
        
        /// @brief Adds a closed curve to the path. A cardinal spline curve is used because the curve travels through each of the points in the array.
        /// @param handle The graphics_path handle.
        /// @param points An array of std::pair<float, float> structures that represents the points that define the curve.
        /// @param tension A value between from 0 through 1 that specifies the amount that the curve bends between points, with 0 being the smallest curve (sharpest corner) and 1 being the smoothest curve.
        /// @warning Internal use only
        static void add_closed_curve(intptr handle, std::vector<std::pair<float, float>> points, float tension);
        
        /// @brief Adds a spline curve to the current figure.
        /// @param handle The graphics_path handle.
        /// @param points An array of std::pair<float, float> structures that represents the points that define the curve.
        /// @param offset he index of the element in the points array that is used as the first point in the curve.
        /// @param number_of_segments The number of segments used to draw the curve. A segment can be thought of as a line connecting two points.
        /// @param tension A value that specifies the amount that the curve bends between control points. Values greater than 1 produce unpredictable results.
        /// @warning Internal use only
        static void add_curve(intptr handle, std::vector<std::pair<float, float>> points, size_t offset, size_t number_of_segments, float tension);
        
        /// @brief Adds an ellipse to the current path.
        /// @param handle The graphics_path handle.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse.
        /// @param y The y-coordinate of the upper left corner of the bounding rectangle that defines the ellipse.
        /// @param width The width of the bounding rectangle that defines the ellipse.
        /// @param height The height of the bounding rectangle that defines the ellipse.
        /// @warning Internal use only
        static void add_ellipse(intptr handle, float x, float y, float width, float height);
        
        /// @brief Appends a line segment to the graphics_path.
        /// @param handle The graphics_path handle.
        /// @param x1 The x-coordinate of the starting point of the line.
        /// @param y1 The y-coordinate of the starting point of the line.
        /// @param x2 The x-coordinate of the endpoint of the line.
        /// @param y2 The y-coordinate of the endpoint of the line.
        /// @warning Internal use only
        static void add_line(intptr handle, float x1, float y1, float x2, float y2);
        
        /// @brief Appends the specified graphics_path to the path.
        /// @param handle The graphics_path handle.
        /// @param adding_path The graphics path handle to add.
        /// @param connect A bool value that specifies whether the first figure in the added path is part of the last figure in the path. A value of true specifies that (if possible) the first figure in the added path is part of the last figure in the path. A value of false specifies that the first figure in the added path is separate from the last figure in the path.
        /// @warning Internal use only
        static void add_path(intptr handle, intptr path, bool connect);
        
        /// @brief Adds the outline of a pie shape to the path.
        /// @param handle The graphics_path handle.
        /// @param x The x-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie is drawn.
        /// @param y The y-coordinate of the upper-left corner of the bounding rectangle that defines the ellipse from which the pie is drawn.
        /// @param width The width of the bounding rectangle that defines the ellipse from which the pie is drawn.
        /// @param height The height of the bounding rectangle that defines the ellipse from which the pie is drawn.
        /// @param start_angle The starting angle for the pie section, measured in degrees clockwise from the x-axis.
        /// @param sweep_angle The angle between start_angle and the end of the pie section, measured in degrees clockwise from start_angle.
        /// @warning Internal use only
        static void add_pie(intptr handle, float x, float y, float width, float height, float start_angle, float sweep_angle);
        
        /// @brief Adds a rectangle to the path.
        /// @param handle The graphics_path handle.
        /// @param x The x-coordinate of the upper-left corner of the rectangle.
        /// @param y The y-coordinate of the upper left corner of the rectangle.
        /// @param width The width of the rectangle.
        /// @param height The height of the rectangle.
        /// @warning Internal use only
        static void add_rectangle(intptr handle, float x, float y, float width, float height);
        
        /// @brief Adds a rounded rectangle to the path.
        /// @param handle The graphics_path handle.
        /// @param x The x-coordinate of the upper-left corner of the rounded rectangle.
        /// @param y The y-coordinate of the upper left corner of the rounded rectangle.
        /// @param width The width of the rounded rectangle.
        /// @param height The height of the rounded rectangle.
        /// @param radius The radius of the rounded rectange angles.
        /// @warning Internal use only
        static void add_rounded_rectangle(intptr handle, float x, float y, float width, float height, float radius);
        
        /// @brief Adds a text string to the path.
        /// @param handle The graphics_path handle.
        /// @param s The xtd::ustring to add.
        /// @param font The font handle.
        /// @param x The x-coordinate of the upper-left corner of the string.
        /// @param y The y-coordinate of the upper left corner of the string.
        /// @param alignment The alignment of the text (see string_alignments.h for more information).
        /// @param line_alignment The alignment of the text (see string_alignments.h for more information).
        /// @param hot_key_prefix The hotkey prefix value (see hot_key_prefixes.h for more information).
        /// @param trimming The trimming value for the text (see string_trimmings.h for more information).
        /// @warning Internal use only
        static void add_string(intptr handle, const xtd::ustring& text, intptr font, float x, float y, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming);
        /// @brief Adds a text string to the path.
        /// @param handle The graphics_path handle.
        /// @param s The xtd::ustring to add.
        /// @param font The font handle.
        /// @param x The x-coordinate of the upper-left corner of the text.
        /// @param y The y-coordinate of the upper left corner of the text.
        /// @param width The width of the text.
        /// @param height The height of the text.
        /// @param alignment The alignment of the text (see string_alignments.h for more information).
        /// @param line_alignment The alignment of the text (see string_alignments.h for more information).
        /// @param hot_key_prefix The hotkey prefix value (see hot_key_prefixes.h for more information).
        /// @param trimming The trimming value for the text (see string_trimmings.h for more information).
        /// @warning Internal use only
        static void add_string(intptr handle, const xtd::ustring& text, intptr font, float x, float y, float w, float h, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming);
        
        /// @brief Closes all open figures in the path and starts a new figure. It closes each open figure by connecting a line from its endpoint to its starting point.
        /// @param handle The graphics_path handle.
        /// @warning Internal use only
        static void close_all_figures(intptr handle);
        
        /// @brief Closes the current figure and starts a new figure. If the current figure contains a sequence of connected lines and curves, the method closes the loop by connecting a line from the endpoint to the starting point.
        /// @param handle The graphics_path handle.
        /// @warning Internal use only
        static void close_figure(intptr handle);
        
        /// @brief Converts each curve in the path into a sequence of connected line segments.
        /// @param handle The graphics_path handle.
        /// @warning Internal use only
        static void flatten(intptr handle);
        
        /// @brief Returns a rectangle that bounds the graphics_path.
        /// @param handle The graphics_path handle.
        /// @param x The x-coordinate of the upper-left corner that represents a rectangle that bounds the graphics_path.
        /// @param y The y-coordinate of the upper-left corner that represents a rectangle that bounds the graphics_path.
        /// @param width The width that represents a rectangle that bounds the graphics_path.
        /// @param height The height that represents a rectangle that bounds the graphics_path.
        /// @warning Internal use only
        static void get_bounds(intptr handle, float& x, float& y, float& width, float& height);
        
        /// @brief Gets the last point of the graphics_path.
        /// @param handle The graphics_path handle.
        /// @param x The x-coordinate of the upper-left corner that represents the last point in the graphics_path.
        /// @param y The y-coordinate of the upper-left corner that represents the last point in the graphics_path.
        /// @warning Internal use only
        static void get_last_point(intptr handle, float& x, float& y);
        
        /// @brief Indicates whether the specified point is contained within the graphics_path.
        /// @param handle The graphics_path handle.
        /// @param x The x-coordinate of the point to test.
        /// @param y The y-coordinate of the point to test.
        /// @warning Internal use only
        static bool is_vsible(intptr handle, float x, float y);
        
        /// @brief Reverses the order of points of the graphics_path.
        /// @param handle The graphics_path handle.
        /// @warning Internal use only
        static void reverse(intptr handle);
        
        /// @brief Starts a new figure without closing the current figure. All subsequent points added to the path are added to this new figure.
        /// @param handle The graphics_path handle.
        /// @warning Internal use only
        static void start_figure(intptr handle);
        /// @}
      };
    }
  }
}

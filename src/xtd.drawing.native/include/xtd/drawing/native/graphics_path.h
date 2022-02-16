#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
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
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    namespace drawing2d {
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
        friend xtd::drawing::drawing2d::graphics_path;
      protected:
        /// @name Protected methods
        
        /// @{
        static intptr_t create();
        static void destroy(intptr_t handle);
        static void add_arc(intptr_t handle, float x, float y, float width, float height, float start_angle, float sweep_angle);
        static void add_bezier(intptr_t handle, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
        static void add_beziers(intptr_t handle, std::vector<std::pair<float, float>> points);
        static void add_closed_curve(intptr_t handle, std::vector<std::pair<float, float>> points, float tension);
        static void add_curve(intptr_t handle, std::vector<std::pair<float, float>> points, size_t offset, size_t number_of_segments, float tension);
        static void add_ellipse(intptr_t handle, float x, float y, float width, float height);
        static void add_line(intptr_t handle, float x1, float y1, float x2, float y2);
        static void add_path(intptr_t handle, intptr_t path, bool connect);
        static void add_pie(intptr_t handle, float x, float y, float width, float height, float start_angle, float sweep_angle);
        static void add_rectangle(intptr_t handle, float x, float y, float width, float height);
        static void add_rounded_rectangle(intptr_t handle, float x, float y, float width, float height, float radius);
        static void add_string(intptr_t handle, const xtd::ustring& text, intptr_t font, float x, float y);
        static void add_string(intptr_t handle, const xtd::ustring& text, intptr_t font, float x, float y, float w, float h);
        static void close_all_figures(intptr_t handle);
        static void close_figure(intptr_t handle);
        static void flatten(intptr_t handle);
        static void reverse(intptr_t handle);
        static void start_figure(intptr_t handle);
        static void get_bounds(intptr_t handle, float& x, float& y, float& width, float& height);
        static void get_last_point(intptr_t handle, float& x, float& y);
        /// @}
      };
    }
  }
}

#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
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
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
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
        static void clear(intptr_t handle, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
        static void clip(intptr_t handle, intptr_t region);
        static void compositing_mode(intptr_t handle, int32_t compositing_mode);
        static void compositing_quality(intptr_t handle, int32_t compositing_quality);
        static void copy_from_screen(intptr_t handle, int32_t source_x, int32_t source_y, int32_t destination_x, int32_t destination_y, int32_t block_region_width, int32_t block_region_height, int32_t copy_pixel_operation);
        static void destroy(intptr_t handle);
        static void draw_arc(intptr_t handle, intptr_t pen, float x, float y, float width, float height, float start_angle, float sweep_angle);
        static void draw_bezier(intptr_t handle, intptr_t pen, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
        static void draw_beziers(intptr_t handle, intptr_t pen, const std::vector<std::pair<float, float>>& points);
        static void draw_closed_curve(intptr_t handle, intptr_t pen, std::vector<std::pair<float, float>> points, float tension);
        static void draw_curve(intptr_t handle, intptr_t pen, std::vector<std::pair<float, float>> points, float tension);
        static void draw_ellipse(intptr_t handle, intptr_t pen, float x, float y, float width, float heigh);
        static void draw_image(intptr_t handle, intptr_t image, float x, float y);
        static void draw_image_disabled(intptr_t handle, intptr_t image, float x, float y, float brightness);
        static void draw_line(intptr_t handle, intptr_t pen, float x1, float y1, float x2, float y2);
        static void draw_lines(intptr_t handle, intptr_t pen, const std::vector<std::pair<float, float>>& points);
        static void draw_path(intptr_t handle, intptr_t pen, intptr_t graphics_path);
        static void draw_pie(intptr_t handle, intptr_t pen, float x, float y, float width, float height, float start_angle, float sweep_angle);
        static void draw_polygon(intptr_t handle, intptr_t pen, const std::vector<std::pair<float, float>>& points);
        static void draw_rectangle(intptr_t handle, intptr_t pen, float x, float y, float width, float height);
        static void draw_rectangles(intptr_t handle, intptr_t pen, std::vector<std::tuple<float, float, float, float>>& rects);
        static void draw_rotated_string(intptr_t handle, const xtd::ustring& text, intptr_t font, intptr_t brush, float x, float y, float angle);
        static void draw_rounded_rectangle(intptr_t handle, intptr_t pen, float x, float y, float width, float height, float radius);
        static void draw_string(intptr_t handle, const xtd::ustring& text, intptr_t font, intptr_t brush, float x, float y, int32_t alignment, int32_t line_alignment, int32_t hot_key_prefix, int32_t trimming);
        static void draw_string(intptr_t handle, const xtd::ustring& text, intptr_t font, intptr_t brush, float x, float y, float width, float height, int32_t alignment, int32_t line_alignment, int32_t hot_key_prefix, int32_t trimming);
        static void fill_closed_curve(intptr_t handle, intptr_t brush, std::vector<std::pair<float, float>> points, uint32_t fill_mode, float tension);
        static void fill_ellipse(intptr_t handle, intptr_t brush, float x, float y, float width, float heigh);
        static void fill_path(intptr_t handle, intptr_t brush, intptr_t graphics_path, int32_t mode);
        static void fill_pie(intptr_t handle, intptr_t brush, float x, float y, float width, float height, float start_angle, float sweep_angle);
        static void fill_polygon(intptr_t handle, intptr_t pen, const std::vector<std::pair<float, float>>& points, int32_t fill_mode);
        static void fill_region(intptr_t handle, intptr_t brush, intptr_t region);
        static void fill_rectangle(intptr_t handle, intptr_t brush, float x, float y, float width, float height);
        static void fill_rectangles(intptr_t handle, intptr_t brush, std::vector<std::tuple<float, float, float, float>>& rects);
        static void fill_rounded_rectangle(intptr_t handle, intptr_t brush, float x, float y, float width, float height, float radius);
        static void flush(intptr_t handle, int32_t intention);
        static intptr_t from_hdc(intptr_t hdc);
        static intptr_t from_hdc(intptr_t hdc, intptr_t hdevice);
        static intptr_t from_hwnd(intptr_t hwnd);
        static intptr_t from_image(intptr_t image);
        static void interpolation_mode(intptr_t handle, int32_t interpolation_mode);
        static float get_dpi_x(intptr_t handle);
        static float get_dpi_y(intptr_t handle);
        static intptr_t get_hdc(intptr_t handle);
        static void get_nearest_color(intptr_t handle, uint8_t original_a, uint8_t original_r, uint8_t original_g, uint8_t original_b, uint8_t& nearest_a, uint8_t& nearest_r, uint8_t& nearest_g, uint8_t& nearest_b);
        static void pixel_offset_mode(intptr_t handle, int32_t pixel_offst_mode);
        static void measure_string(intptr_t handle, const xtd::ustring& text, intptr_t font, float& width, float& height);
        static void release_hdc(intptr_t handle, intptr_t hdc);
        static void reset_transform(intptr_t handle);
        static void restore(intptr_t handle, intptr_t& gstate);
        static void rotate_transform(intptr_t handle, float angle, int32_t order);
        static intptr_t save(intptr_t handle);
        static void scale_transform(intptr_t handle, float sx, float sy, int32_t order);
        static void smoothing_mode(intptr_t handle, int32_t smoothing_mode);
        /// @remarks The gamma correction value must be between 0 and 12. The default value is 4.
        static void text_contrast(intptr_t handle, int32_t text_contrast);
        static void text_rendering_hint(intptr_t handle, int32_t text_rendering_hint);
        static intptr_t transform(intptr_t handle);
        static void transform(intptr_t handle, intptr_t matrix);
        static void translate_transform(intptr_t handle, float dx, float dy, int32_t order);
        static void visible_clip_bounds(intptr_t handle, float& x, float& y, float& width, float& height);
        /// @}
      };
    }
  }
}

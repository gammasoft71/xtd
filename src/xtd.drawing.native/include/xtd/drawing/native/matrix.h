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
      class matrix;
    }
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains matrix native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ matrix final static_ {
        friend xtd::drawing::drawing2d::matrix;
      protected:
        /// @name Protected methods
        
        /// @{
        static intptr_t create(float m11, float m12, float m21, float m22, float dx, float dy);
        static void destroy(intptr_t handle);
        static std::vector<float> elenents(intptr_t handle);
        static bool is_identity(intptr_t handle);
        static bool is_invertible(intptr_t handle);
        static void invert(intptr_t handle);
        static float offset_x(intptr_t handle);
        static float offset_y(intptr_t handle);
        static void multiply(intptr_t handle, intptr_t matrix, int32_t order);
        static void reset(intptr_t handle);
        static void rotate(intptr_t handle, float angle, int32_t order);
        static void rotate_at(intptr_t handle, float angle, float x, float y, int32_t order);
        static void scale(intptr_t handle, float scale_x, float scale_y, int32_t order);
        static void shear(intptr_t handle, float scale_x, float scale_y, int32_t order);
        static void transform_point(intptr_t handle, int32_t& x, int32_t& y);
        static void transform_point(intptr_t handle, float& x, float& y);
        static void transform_vectors(intptr_t handle, std::vector<std::pair<int32_t, int32_t>>& points);
        static void transform_vectors(intptr_t handle, std::vector<std::pair<float, float>>& points);
        static void translate(intptr_t handle, float offset_x, float offset_y, int32_t order);
        static void vector_transform_points(intptr_t handle, std::vector<std::pair<float, float>>& points);
        /// @}
      };
    }
  }
}

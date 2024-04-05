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
        friend xtd::drawing::drawing_2d::matrix;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Create a matrix with the specified elements.
        /// @param m11 The value in the first row and first column of the matrix.
        /// @param m12 The value in the first row and second column of the matrix.
        /// @param m21 The value in the second row and first column of the matrix.
        /// @param m22 The value in the second row and second column of the matrix.
        /// @param dx The value in the third row and first column of the matrix.
        /// @param dy The value in the third row and second column of the matrix.
        /// @return The created matrix handle.
        /// @warning Internal use only
        static intptr create(float m11, float m12, float m21, float m22, float dx, float dy);
        
        /// @brief Destroys the matrix.
        /// @param handle The matrix handle to destroy.
        /// @warning Internal use only
        static void destroy(intptr handle);
        
        /// @brief Gets an array of floating-point values that represents the elements of the matrix.
        /// @param handle The matrix handle.
        /// @return An array of floating-point values that represents the elements of the matrix.
        /// @warning Internal use only
        static std::vector<float> elenents(intptr handle);
        
        /// @brief Gets a value indicating whether the matrix is the identity matrix.
        /// @param handle The matrix handle.
        /// @return This property is true if the matrix is identity; otherwise, false.
        /// @warning Internal use only
        static bool is_identity(intptr handle);
        
        /// @brief Gets a value indicating whether the matrix is invertible.
        /// @param handle The matrix handle.
        /// @return This property is true if the matrix is invertible; otherwise, false.
        /// @warning Internal use only
        static bool is_invertible(intptr handle);
        
        /// @brief Inverts the matrix, if it is invertible.
        /// @param handle The matrix handle.
        /// @warning Internal use only
        static void invert(intptr handle);
        
        /// @brief Gets the x translation value (the dx value, or the element in the third row and first column) of the matrix.
        /// @param handle The matrix handle.
        /// @return The x translation value of the matrix.
        /// @warning Internal use only
        static float offset_x(intptr handle);
        
        /// @brief Gets the y translation value (the dx value, or the element in the third row and first column) of the matrix.
        /// @param handle The matrix handle.
        /// @return The y translation value of the matrix.
        /// @warning Internal use only
        static float offset_y(intptr handle);
        
        /// @brief Multiplies this xtd::drawing::drawing_2d::matrix by the matrix specified in the matrix parameter, and in the order specified in the order parameter.
        /// @param handle The matrix handle.
        /// @param matrix The matrix handle by which the matrix is to be multiplied.
        /// @param order The value that represents the order (see matrix_orders.h for more information).
        /// @warning Internal use only
        static void multiply(intptr handle, intptr matrix, int32 order);
        
        /// @brief Resets the matrix to have the elements of the identity matrix.
        /// @param handle The matrix handle.
        /// @warning Internal use only
        static void reset(intptr handle);
        
        /// @brief repend to the matrix a clockwise rotation, around the origin and by the specified angle.
        /// @param handle The matrix handle.
        /// @param angle The angle of the rotation, in degrees.
        /// @param order The value that represents the order (see matrix_orders.h for more information).
        /// @warning Internal use only
        static void rotate(intptr handle, float angle, int32 order);
        
        /// @brief Applies a clockwise rotation to the matrix around the point specified in the point parameter, and by prepending the rotation.
        /// @param handle The matrix handle.
        /// @param angle The angle (extent) of the rotation, in degrees.
        /// @param x The x-coordinate of the point that represents the center of the rotation.
        /// @param y The y-coordinate of the point that represents the center of the rotation.
        /// @param order The value that represents the order (see matrix_orders.h for more information).
        /// @warning Internal use only
        static void rotate_at(intptr handle, float angle, float x, float y, int32 order);
        
        /// @brief Applies the specified scale vector (scale_x and scale_y) to this xtd::drawing::drawing_2d::matrix using the specified order.
        /// @param handle The matrix handle.
        /// @param scale_x The value by which to scale this xtd::drawing::drawing_2d::matrix in the x-axis direction.
        /// @param scale_y The value by which to scale this xtd::drawing::drawing_2d::matrix in the y-axis direction.
        /// @param order A value that specifies the order (append or prepend) in which the scale vector is applied to the matrix (see matrix_orders.h for more information).
        /// @warning Internal use only
        static void scale(intptr handle, float scale_x, float scale_y, int32 order);
        
        /// @brief Applies the specified shear vector to the matrix in the specified order.
        /// @param handle The matrix handle.
        /// @param scale_x The horizontal shear factor.
        /// @param scale_y The vertical shear factor.
        /// @param order A xvalue that specifies the order (append or prepend) in which the shear is applied (see matrix_orders.h for more information).
        /// @warning Internal use only
        static void shear(intptr handle, float scale_x, float scale_y, int32 order);
        
        /// @brief Applies the geometric transform represented by the matrix to a specified array of points.
        /// @param handle The matrix handle.
        /// @param x The x-coordinate of the point that represents the point to transform.
        /// @param y The y-coordinate of the point that represents the point to transform.
        /// @warning Internal use only
        static void transform_point(intptr handle, int32& x, int32& y);
        /// @brief Applies the geometric transform represented by the matrix to a specified array of points.
        /// @param handle The matrix handle.
        /// @param x The x-coordinate of the point that represents the point to transform.
        /// @param y The y-coordinate of the point that represents the point to transform.
        /// @warning Internal use only
        static void transform_point(intptr handle, float& x, float& y);
        
        /// @brief Applies only the scale and rotate components of the matrix to the specified array of points.
        /// @param handle The matrix handle.
        /// @param x An array of std::pair<int32, int32>t structures that represents the points to transform.
        /// @warning Internal use only
        static void transform_vectors(intptr handle, std::vector<std::pair<int32, int32>>& points);
        /// @brief Applies only the scale and rotate components of the matrix to the specified array of points.
        /// @param handle The matrix handle.
        /// @param x An array of std::pair<int32, int32>t structures that represents the points to transform.
        /// @warning Internal use only
        static void transform_vectors(intptr handle, std::vector<std::pair<float, float>>& points);
        
        /// @brief Applies the specified translation vector (offset_x and offset_y) to the matrix in the specified order.
        /// @param handle The matrix handle.
        /// @param offset_x The x value by which to translate the matrix.
        /// @param offset_y The y value by which to translate the matrix.
        /// @param order A value that specifies the order (append or prepend) in which the translation is applied to the matrix.
        /// @warning Internal use only
        static void translate(intptr handle, float offset_x, float offset_y, int32 order);
        
        /// @brief Multiplies each vector in an array by the matrix. The translation elements of this matrix (third row) are ignored.
        /// @param handle The matrix handle.
        /// @param points An array of std::pair<int32, int32> structures that represents the points to transform.
        /// @warning Internal use only
        static void vector_transform_points(intptr handle, std::vector<std::pair<int32, int32>>& points);
        /// @}
      };
    }
  }
}

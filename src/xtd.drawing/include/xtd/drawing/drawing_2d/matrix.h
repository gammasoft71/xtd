/// @file
/// @brief Contains xtd::drawing::drawing_2d::matrix class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../../drawing_export.h"
#include "../point.h"
#include "../point_f.h"
#include "../rectangle.h"
#include "../rectangle_f.h"
#include "drawing2d.h"
#include "matrix_order.h"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/ustring>
#include <cstdint>
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class graphics;
    /// @endcond
    
    /// @brief The xtd::drawing::drawing_2d/ namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief Encapsulates a 3-by-3 affine matrix that represents a geometric transform. This class cannot be inherited.
      /// @code
      /// class drawing_export_ matrix final : public object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::drawing::drawing_2d::matrix
      /// @par Namespace
      /// xtd::drawing::drawing_2d/
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing drawing
      /// @remarks In GDI+ you can store an affine transformation in a xtd::drawing::drawing_2d::matrix object. Because the third column of a matrix that represents an affine transformation is always (0, 0, 1), you specify only the six numbers in the first two columns when you construct a xtd::drawing::drawing_2d::matrix object. The statement xtd::drawing::drawing_2d::matrix myMatrix = new xtd::drawing::drawing_2d::matrix(0, 1, -1, 0, 3, 4) constructs the matrix shown in the following figure.
      /// @image html matrix.png
      /// @par Composite Transformations
      /// A composite transformation is a sequence of transformations, one followed by the other. Consider the matrices and transformations in the following list:
      /// <table>
      ///   <tbody>
      ///     <tr>
      ///       <td>matrix A</td>
      ///       <td>Rotate 90 degrees</td>
      ///     </tr>
      ///     <tr>
      ///       <td>matrix B</td>
      ///       <td>Scale by a factor of 2 in the x direction</td>
      ///     </tr>
      ///     <tr>
      ///       <td>matrix C</td>
      ///       <td>Translate 3 units in the y direction</td>
      ///     </tr>
      ///   </tbody>
      /// </table>
      /// If we start with the point (2, 1) - represented by the matrix [2 1 1] - and multiply by A, then B, then C, the point (2, 1) will undergo the three transformations in the order listed.
      /// <br><br>[2 1 1]ABC = [-2 5 1]
      /// <br><br>Rather than store the three parts of the composite transformation in three separate matrices, you can multiply A, B, and C together to get a single 3×3 matrix that stores the entire composite transformation. Suppose ABC = D. Then a point multiplied by D gives the same result as a point multiplied by A, then B, then C.
      /// <br><br>[2 1 1]D = [-2 5 1]
      /// <br><br>The following illustration shows the matrices A, B, C, and D.
      /// @image html matrix2.png
      /// The fact that the matrix of a composite transformation can be formed by multiplying the individual transformation matrices means that any sequence of affine transformations can be stored in a single xtd::drawing::drawing_2d::matrix object.
      /// <b>Caution: The order of a composite transformation is important. In general, rotate, then scale, then translate is not the same as scale, then rotate, then translate. Similarly, the order of matrix multiplication is important. In general, ABC is not the same as BAC.</b>
      /// <br><br>The xtd::drawing::drawing_2d::matrix class provides several methods for building a composite transformation: xtd::drawing::drawing_2d::matrix::multiply, xtd::drawing::drawing_2d::matrix::rotate, xtd::drawing::drawing_2d::matrix::rotate_at, xtd::drawing::drawing_2d::matrix::scale, xtd::drawing::drawing_2d::matrix::shear, and xtd::drawing::drawing_2d::matrix::translate. The following example creates the matrix of a composite transformation that first rotates 30 degrees, then scales by a factor of 2 in the y direction, and then translates 5 units in the x direction:
      /// @code
      /// matrix my_matrix;
      /// my_matrix.rotate(30);
      /// my_matrix.scale(1, 2, matrix_order::append);
      /// my_matrix.translate(5, 0, matrix_order::append);
      /// @endcode
      class drawing_export_ matrix final : public object, public xtd::iequatable<matrix> {
        struct data;
        
      public:
        /// @name Constructors
        
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::matrix class as the identity matrix.
        matrix();
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::matrix class with the specified elements.
        /// @param m11 The value in the first row and first column of the new xtd::drawing::drawing_2d::matrix.
        /// @param m12 The value in the first row and second column of the new xtd::drawing::drawing_2d::matrix.
        /// @param m21 The value in the second row and first column of the new xtd::drawing::drawing_2d::matrix.
        /// @param m22 The value in the second row and second column of the new xtd::drawing::drawing_2d::matrix.
        /// @param dx The value in the third row and first column of the new xtd::drawing::drawing_2d::matrix.
        /// @param dy The value in the third row and second column of the new xtd::drawing::drawing_2d::matrix.
        matrix(float m11, float m12, float m21, float m22, float dx, float dy);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::matrix class to the geometric transform defined by the specified rectangle and array of points.
        /// @param rect A xtd::drawing::rectangle structure that represents the rectangle to be transformed.
        /// @param plgpts An array of three xtd::drawing::point structures that represents the points of a parallelogram to which the upper-left, upper-right, and lower-left corners of the rectangle is to be transformed. The lower-right corner of the parallelogram is implied by the first three corners.
        /// @remarks This method initializes the new xtd::drawing::drawing_2d::matrix such that it represents the geometric transform that maps the rectangle specified by the rect parameter to the parallelogram defined by the three points in the plgpts parameter. The upper-left corner of the rectangle is mapped to the first point in the plgpts array, the upper-right corner is mapped to the second point, and the lower-left corner is mapped to the third point. The lower-right point of the parallelogram is implied by the first three.
        matrix(const xtd::drawing::rectangle& rect, const std::vector<xtd::drawing::point>& plgpts);
        /// @brief Initializes a new instance of the xtd::drawing::drawing_2d::matrix class to the geometric transform defined by the specified rectangle and array of points.
        /// @param rect A xtd::drawing::rectangle_f structure that represents the rectangle to be transformed.
        /// @param plgpts An array of three xtd::drawing::point_f structures that represents the points of a parallelogram to which the upper-left, upper-right, and lower-left corners of the rectangle is to be transformed. The lower-right corner of the parallelogram is implied by the first three corners.
        /// @remarks This method initializes the new xtd::drawing::drawing_2d::matrix such that it represents the geometric transform that maps the rectangle specified by the rect parameter to the parallelogram defined by the three points in the plgpts parameter. The upper-left corner of the rectangle is mapped to the first point in the plgpts array, the upper-right corner is mapped to the second point, and the lower-left corner is mapped to the third point. The lower-right point of the parallelogram is implied by the first three.
        matrix(const xtd::drawing::rectangle_f& rect, const std::vector<xtd::drawing::point_f>& plgpts);
        /// @}
        
        /// @cond
        matrix(const xtd::drawing::drawing_2d::matrix& value);
        matrix& operator =(const xtd::drawing::drawing_2d::matrix& value);
        ~matrix();
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets an array of floating-point values that represents the elements of this xtd::drawing::drawing_2d::matrix.
        /// @return An array of floating-point values that represents the elements of this xtd::drawing::drawing_2d::matrix.
        /// @remarks The elements m11, m12, m21, m22, dx, and dy of the xtd::drawing::drawing_2d::matrix are represented by the values in the array in that order.
        std::vector<float> elements() const;
        
        /// @brief Gets the handle of the matrix.
        /// @return An intptr that contains the handle of the matrix.
        intptr handle() const noexcept;
        
        /// @brief Gets a value indicating whether this xtd::drawing::drawing_2d::matrix is the identity matrix.
        /// @return This property is true if this xtd::drawing::drawing_2d::matrix is identity; otherwise, false.
        bool is_identity() const;
        
        /// @brief Gets a value indicating whether this xtd::drawing::drawing_2d::matrix is invertible.
        /// @return This property is true if this xtd::drawing::drawing_2d::matrix is invertible; otherwise, false.
        bool is_invertible() const;
        
        /// @brief Gets the x translation value (the dx value, or the element in the third row and first column) of this xtd::drawing::drawing_2d::matrix.
        /// @return The x translation value of this xtd::drawing::drawing_2d::matrix.
        float offset_x() const;
        
        /// @brief Gets the y translation value (the dy value, or the element in the third row and second column) of this xtd::drawing::drawing_2d::matrix.
        /// @return The y translation value of this xtd::drawing::drawing_2d::matrix.
        float offset_y() const;
        /// @}
        
        /// @name Methods
        
        /// @{
        bool equals(const xtd::drawing::drawing_2d::matrix& value) const noexcept override;
        
        /// @brief Inverts this xtd::drawing::drawing_2d::matrix, if it is invertible.
        void invert();
        
        /// @brief Multiplies this xtd::drawing::drawing_2d::matrix by the matrix specified in the matrix parameter, by prepending the specified xtd::drawing::drawing_2d::matrix.
        /// @param matrix The xtd::drawing::drawing_2d::matrix by which this xtd::drawing::drawing_2d::matrix is to be multiplied.
        void multiply(const xtd::drawing::drawing_2d::matrix& matrix);
        /// @brief Multiplies this xtd::drawing::drawing_2d::matrix by the matrix specified in the matrix parameter, and in the order specified in the order parameter.
        /// @param matrix The xtd::drawing::drawing_2d::matrix by which this xtd::drawing::drawing_2d::matrix is to be multiplied.
        /// @param order The xtd::drawing::drawing_2d::matrix_order that represents the order of the multiplication.
        void multiply(const xtd::drawing::drawing_2d::matrix& matrix, xtd::drawing::drawing_2d::matrix_order order);
        
        /// @brief Resets this xtd::drawing::drawing_2d::matrix to have the elements of the identity matrix.
        /// @remarks The elements on the main diagonal of the identity matrix are 1. All other elements of the identity matrix are 0.
        void reset();
        
        /// @brief repend to this xtd::drawing::drawing_2d::matrix a clockwise rotation, around the origin and by the specified angle.
        /// @param angle The angle of the rotation, in degrees.
        void rotate(float angle);
        /// @brief Applies a clockwise rotation of an amount specified in the angle parameter, around the origin (zero x and y coordinates) for this xtd::drawing::drawing_2d::matrix.
        /// @param angle The angle (extent) of the rotation, in degrees.
        /// @param order A xtd::drawing::drawing_2d::matrix_order that specifies the order (append or prepend) in which the rotation is applied to this xtd::drawing::drawing_2d::matrix.
        void rotate(float angle, xtd::drawing::drawing_2d::matrix_order order);
        
        /// @brief Applies a clockwise rotation to this xtd::drawing::drawing_2d::matrix around the point specified in the point parameter, and by prepending the rotation.
        /// @param angle The angle (extent) of the rotation, in degrees.
        /// @param point A xtd::drawing::point_f that represents the center of the rotation.
        void rotate_at(float angle, const xtd::drawing::point_f& point);
        /// @brief Applies a clockwise rotation about the specified point to this xtd::drawing::drawing_2d::matrix in the specified order.
        /// @param angle The angle (extent) of the rotation, in degrees.
        /// @param point A xtd::drawing::point_f that represents the center of the rotation.
        /// @param order A xtd::drawing::drawing_2d::matrix_order that specifies the order (append or prepend) in which the rotation is applied.
        void rotate_at(float angle, const xtd::drawing::point_f& point, xtd::drawing::drawing_2d::matrix_order order);
        
        /// @brief Applies the specified scale vector to this xtd::drawing::drawing_2d::matrix by prepending the scale vector.
        /// @param scale_x The value by which to scale this xtd::drawing::drawing_2d::matrix in the x-axis direction.
        /// @param scale_y The value by which to scale this xtd::drawing::drawing_2d::matrix in the y-axis direction.
        void scale(float scale_x, float scale_y);
        /// @brief Applies the specified scale vector (scale_x and scale_y) to this xtd::drawing::drawing_2d::matrix using the specified order.
        /// @param scale_x The value by which to scale this xtd::drawing::drawing_2d::matrix in the x-axis direction.
        /// @param scale_y The value by which to scale this xtd::drawing::drawing_2d::matrix in the y-axis direction.
        /// @param order A xtd::drawing::drawing_2d::matrix_order that specifies the order (append or prepend) in which the scale vector is applied to this xtd::drawing::drawing_2d::matrix.
        void scale(float scale_x, float scale_y, xtd::drawing::drawing_2d::matrix_order order);
        
        /// @brief Applies the specified shear vector to this xtd::drawing::drawing_2d::matrix.
        /// @param scale_x The horizontal shear factor.
        /// @param scale_y The vertical shear factor.
        /// @remarks The transformation applied in this method is a pure shear only if one of the parameters is 0. Applied to a rectangle at the origin, when the shear_y factor is 0, the transformation moves the bottom edge horizontally by shear_x times the height of the rectangle. When the shearX factor is 0, it moves the right edge vertically by shearY times the width of the rectangle. Caution is in order when both parameters are nonzero, because the results are hard to predict. For example, if both factors are 1, the transformation is singular (hence noninvertible), squeezing the entire plane to a single line.
        void shear(float scale_x, float scale_y);
        /// @brief Applies the specified shear vector to this xtd::drawing::drawing_2d::matrix in the specified order.
        /// @param scale_x The horizontal shear factor.
        /// @param scale_y The vertical shear factor.
        /// @param order A xtd::drawing::drawing_2d::matrix_order that specifies the order (append or prepend) in which the shear is applied.
        /// @remarks The transformation applied in this method is a pure shear only if one of the parameters is 0. Applied to a rectangle at the origin, when the shear_y factor is 0, the transformation moves the bottom edge horizontally by shear_x times the height of the rectangle. When the shearX factor is 0, it moves the right edge vertically by shearY times the width of the rectangle. Caution is in order when both parameters are nonzero, because the results are hard to predict. For example, if both factors are 1, the transformation is singular (hence noninvertible), squeezing the entire plane to a single line.
        void shear(float scale_x, float scale_y, xtd::drawing::drawing_2d::matrix_order order);
        
        /// @brief Applies the geometric transform represented by this xtd::drawing::drawing_2d::matrix to a specified array of points.
        /// @param points An array of xtd::drawing::point structures that represents the points to transform.
        void transform_points(std::vector<xtd::drawing::point>& points);
        /// @brief Applies the geometric transform represented by this xtd::drawing::drawing_2d::matrix to a specified array of points.
        /// @param points An array of xtd::drawing::point_f structures that represents the points to transform.
        void transform_points(std::vector<xtd::drawing::point_f>& points);
        
        /// @brief Applies only the scale and rotate components of this xtd::drawing::drawing_2d::matrix to the specified array of points.
        /// @param points An array of xtd::drawing::point structures that represents the points to transform.
        void transform_vectors(std::vector<xtd::drawing::point>& points);
        /// @brief Applies only the scale and rotate components of this xtd::drawing::drawing_2d::matrix to the specified array of points.
        /// @param points An array of xtd::drawing::point_f structures that represents the points to transform.
        void transform_vectors(std::vector<xtd::drawing::point_f>& points);
        
        /// @brief Applies the specified translation vector (offset_x and offset_y) to this xtd::drawing::drawing_2d::matrix by prepending the translation vector.
        /// @param offset_x The x value by which to translate this xtd::drawing::drawing_2d::matrix.
        /// @param offset_y The y value by which to translate this xtd::drawing::drawing_2d::matrix.
        void translate(float offset_x, float offset_y);
        /// @brief Applies the specified translation vector (offset_x and offset_y) to this xtd::drawing::drawing_2d::matrix in the specified order.
        /// @param offset_x The x value by which to translate this xtd::drawing::drawing_2d::matrix.
        /// @param offset_y The y value by which to translate this xtd::drawing::drawing_2d::matrix.
        /// @param order A xtd::drawing::drawing_2d::matrix_order that specifies the order (append or prepend) in which the translation is applied to this xtd::drawing::drawing_2d::matrix.
        void translate(float offset_x, float offset_y, xtd::drawing::drawing_2d::matrix_order order);
        
        /// @brief Multiplies each vector in an array by the matrix. The translation elements of this matrix (third row) are ignored.
        /// @param points An array of xtd::drawing::point structures that represents the points to transform.
        void vector_transform_points(std::vector<xtd::drawing::point>& points);
        
        xtd::ustring to_string() const noexcept override;
        /// @}
        
      private:
        void init_from_rect_3points(const xtd::drawing::rectangle_f& rect, const xtd::drawing::point_f pt1, const xtd::drawing::point_f pt2, const xtd::drawing::point_f pt3);
        friend class xtd::drawing::graphics;
        explicit matrix(intptr handle);
        
        std::shared_ptr<data> data_;
      };
    }
  }
}

/// @file
/// @brief Contains xtd::drawing::matrix class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <ostream>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../../drawing_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Encapsulates a 3-by-3 affine matrix that represents a geometric transform. This class cannot be inherited.
      /// @code
      /// class drawing_export_ matrix final : public object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::drawing::drawing2d::matrix
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing drawing
      /// @remarks In GDI+ you can store an affine transformation in a Matrix object. Because the third column of a matrix that represents an affine transformation is always (0, 0, 1), you specify only the six numbers in the first two columns when you construct a Matrix object. The statement Matrix myMatrix = new Matrix(0, 1, -1, 0, 3, 4) constructs the matrix shown in the following figure.
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
      ///       <td>matrix Bc/td>
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
      /// The fact that the matrix of a composite transformation can be formed by multiplying the individual transformation matrices means that any sequence of affine transformations can be stored in a single xtd::drawing::drawing2d::matrix object.
      /// @warning The order of a composite transformation is important. In general, rotate, then scale, then translate is not the same as scale, then rotate, then translate. Similarly, the order of matrix multiplication is important. In general, ABC is not the same as BAC.
      /// <br><br>The xtd::drawing::drawing2d::matrix class provides several methods for building a composite transformation: xtd::drawing::drawing2d::matrix::multiply, xtd::drawing::drawing2d::matrix::rotate, xtd::drawing::drawing2d::matrix::rotate_at, xtd::drawing::drawing2d::matrix::scale, xtd::drawing::drawing2d::matrix::shear, and xtd::drawing::drawing2d::matrix::translate. The following example creates the matrix of a composite transformation that first rotates 30 degrees, then scales by a factor of 2 in the y direction, and then translates 5 units in the x direction:
      /// @code
      /// matrix my_matrix;
      /// my_matrix.rotate(30);
      /// my_matrix.scale(1, 2, matrix_order::append);
      /// my_matrix.translate(5, 0, matrix_order::append);
      /// @endcode
      class drawing_export_ matrix final : public object {
      public:
        /// @name Constructors
        
        /// @brief Initializes a new instance of the xtd::drawing::drawing2d::matrix class as the identity matrix.
        matrix();
        /// @}
        
        /// @cond
        matrix(const xtd::drawing::drawing2d::matrix& value);
        matrix& operator=(const xtd::drawing::drawing2d::matrix& value);
        ~matrix();
        bool operator==(const xtd::drawing::drawing2d::matrix& value) const;
        bool operator!=(const xtd::drawing::drawing2d::matrix& value) const;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the handle of the matrix.
        /// @return An intptr_t that contains the handle of the matrix.
        intptr_t handle() const noexcept;
        /// @}
   
        /// @name Methods
        
        /// @{

        xtd::ustring to_string() const noexcept override;
        /// @}
        
        /// @cond
        friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::drawing2d::matrix& matrix) noexcept {return os << matrix.to_string();}
        /// @endcond
        
      private:
        void recreate_handle();
        struct data {
          intptr_t handle = 0;
        };
        std::shared_ptr<data> data_ = std::make_shared<data>();
      };
    }
  }
}

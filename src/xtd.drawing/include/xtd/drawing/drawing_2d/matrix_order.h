/// @file
/// @brief Contains xtd::drawing::drawing_2d::matrix_order enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "drawing2d.h"
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing_2d/ namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief Specifies the order for matrix transform operations.
      /// @par Namespace
      /// xtd::drawing::drawing_2d/
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks Matrix transform operations are not necessarily commutative. The order in which they are applied is important.
      enum class matrix_order {
        /// @brief The new operation is applied before the old operation.
        prepend = 0,
        /// @brief The new operation is applied after the old operation.
        append = 1,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::drawing_2d::matrix_order> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::drawing_2d::matrix_order> {{xtd::drawing::drawing_2d::matrix_order::prepend, "prepend"}, {xtd::drawing::drawing_2d::matrix_order::append, "append"}};}
};
/// @endcond

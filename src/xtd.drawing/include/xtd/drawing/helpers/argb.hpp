/// @file
/// @brief Contains xtd::drawing::helpers::argb struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "alpha.hpp"
#include "rgb.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::helpers namespace contains helpers for xtd::drawing objects, sush as rgb, argb structs
    namespace helpers {
      /// @brief The argb struct.
      /// ```cpp
      /// struct argb : rgb;
      /// ```
      /// @par Namespace
      /// xtd::drawing::helpers
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      struct argb : alpha, rgb {
      };
    }
  }
}

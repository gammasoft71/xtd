/// @file
/// @brief Contains xtd::drawing::helpers::rgb struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <xtd/byte>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::helpers namespace contains helpers for xtd::drawing objects, sush as rgb, rbg structs
    namespace helpers {
      /// @brief The rgb struct.
      /// ```cpp
      /// struct rgb;
      /// ```
      /// @par Namespace
      /// xtd::drawing::helpers
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      struct rgb {
        /// @brief Gets or sets the red component value of this xtd::drawing::helpers::rgb struct.
        /// @param r byte The red component value of this xtd::drawing::helpers::rgb.
        xtd::byte r = 0;
        /// @brief Gets or sets the green component value of this xtd::drawing::helpers::rbg struct.
        /// @param r byte The green component value of this xtd::drawing::helpers::rgb.
        xtd::byte g = 0;
        /// @brief Gets or sets the blue component value of this xtd::drawing::helpers::rbg struct.
        /// @param r byte The blue component value of this xtd::drawing::helpers::rgb.
        xtd::byte b = 0;
      };
    }
  }
}

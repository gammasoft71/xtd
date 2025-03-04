/// @file
/// @brief Contains xtd::drawing::helpers::alpha struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <xtd/byte>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::helpers namespace contains helpers for xtd::drawing objects, sush as rgb, alpha structs
    namespace helpers {
      /// @brief The alpha struct.
      /// ```cpp
      /// struct alpha : rgb;
      /// ```
      /// @par Namespace
      /// xtd::drawing::helpers
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      struct alpha {
        /// @name Public Properties
        
        /// @{
        /// @brief Gets or sets the alpha component value of this xtd::drawing::helpers::alpha struct.
        /// @param a byte The alpha component value of this xtd::drawing::helpers::alpha.
        xtd::byte a = 255;
        /// @}
      };
    }
  }
}

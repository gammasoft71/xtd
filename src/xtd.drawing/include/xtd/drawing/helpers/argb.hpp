/// @file
/// @brief Contains xtd::drawing::helpers::argb struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <xtd/byte>

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
      struct argb {
        /// @name Public Properties
        
        /// @{
        /// @brief Gets or sets the alpha component value of this xtd::drawing::helpers::argb struct.
        /// @param a byte The alpha component value of this xtd::drawing::helpers::argb.
        xtd::byte a = 255;
        /// @brief Gets or sets the red component value of this xtd::drawing::helpers::argb struct.
        /// @param r byte The red component value of this xtd::drawing::helpers::argb.
        xtd::byte r = 0;
        /// @brief Gets or sets the green component value of this xtd::drawing::helpers::argb struct.
        /// @param r byte The green component value of this xtd::drawing::helpers::argb.
        xtd::byte g = 0;
        /// @brief Gets or sets the blue component value of this xtd::drawing::helpers::argb struct.
        /// @param r byte The blue component value of this xtd::drawing::helpers::argb.
        xtd::byte b = 0;
        /// @}

        /// @name Public Static Methods
        
        /// @{
        /// @brief Creates a xtd::helpers::argb struct from the specified unsigned integer value.
        /// @param value The unsigned integer value.
        /// @return an xtd::drawing::helper::argb value that contains decomposed unsigned integer value.
        static argb from_uint32(uint32 value) noexcept {
          return argb {
            .a = static_cast<xtd::byte>((value & 0xFF000000) >> 24),
            .r = static_cast<xtd::byte>((value & 0x00FF0000) >> 16),
            .g = static_cast<xtd::byte>((value & 0x0000FF00) >> 8),
            .b = static_cast<xtd::byte>(value & 0x000000FF)
          };
        }
        /// @}
      };
    }
  }
}

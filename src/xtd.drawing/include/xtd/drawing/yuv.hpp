/// @file
/// @brief Contains xtd::drawing::yuv struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <xtd/byte>
#include <xtd/string>
#include <xtd/uint32>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The yuv struct.
    /// ```cpp
    /// struct yuv;
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    struct yuv {
      /// @name Public Properties
      
      /// @{
      /// @brief Gets or sets the y component value of this xtd::drawing::yuv struct.
      /// @param a byte The y component value of this xtd::drawing::yuv.
      xtd::single y = .0f;
      /// @brief Gets or sets the u component value of this xtd::drawing::yuv struct.
      /// @param r byte The u component value of this xtd::drawing::yuv.
      xtd::single u = .0f;
      /// @brief Gets or sets the v component value of this xtd::drawing::yuv struct.
      /// @param r byte The v component value of this xtd::drawing::yuv.
      xtd::single v = .0f;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates a xtd::yuv struct from the specified y, u, and v single values.
      /// @param y The a single value.
      /// @param u The r single value.
      /// @param v The g single value.
      /// @return an xtd::drawing::yuv value that contains decomposed unsigned integer value.
      [[nodiscard]] static auto from_yuv(xtd::single y, xtd::single u, xtd::single v) noexcept -> xtd::drawing::yuv {
        return yuv {.y = y, .u = u, .v = v};
      }
      /// @brief Creates a xtd::yuv struct from the specified axtd::drawing::yuv value.
      /// @param value The yuv value.
      /// @return an xtd::drawing::yuv value that contains decomposed unsigned integer value.
      [[nodiscard]] static auto from_yuv(const yuv& value) noexcept -> xtd::drawing::yuv {
        return value;
      }
      /// @}
      
      /// @cond
      friend auto operator <<(std::ostream& os, const yuv& value) -> std::ostream& {
        return os << xtd::string::format("yuv [y = {}, u = {}, v = {}]", value.y, value.u, value.v);
      };
      /// @endcond
    };
  }
}

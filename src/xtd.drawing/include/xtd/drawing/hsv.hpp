/// @file
/// @brief Contains xtd::drawing::hsv struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <xtd/byte>
#include <xtd/string>
#include <xtd/uint32>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The hsv struct.
    /// ```cpp
    /// struct hsv;
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    struct hsv {
      /// @name Public Properties
      
      /// @{
      /// @brief Gets or sets the hue component value of this xtd::drawing::hsv struct.
      /// @param a byte The hue component value of this xtd::drawing::hsv.
      xtd::single hue = .0f;
      /// @brief Gets or sets the saturation component value of this xtd::drawing::hsv struct.
      /// @param r byte The saturation component value of this xtd::drawing::hsv.
      xtd::single saturation = .0f;
      /// @brief Gets or sets the value component value of this xtd::drawing::hsv struct.
      /// @param r byte The value component value of this xtd::drawing::hsv.
      xtd::single value = .0f;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates a xtd::hsv struct from the specified hue, saturation, and value single values.
      /// @param hue The a single value.
      /// @param saturation The r single value.
      /// @param value The g single value.
      /// @return an xtd::drawing::hsv value that contains decomposed unsigned integer value.
      [[nodiscard]] static auto from_hsv(xtd::single hue, xtd::single saturation, xtd::single value) noexcept -> xtd::drawing::hsv {
        return hsv {.hue = hue, .saturation = saturation, .value = value};
      }
      /// @brief Creates a xtd::hsv struct from the specified axtd::drawing::hsv value.
      /// @param value The hsv value.
      /// @return an xtd::drawing::hsv value that contains decomposed unsigned integer value.
      [[nodiscard]] static auto from_hsv(const hsv& value) noexcept -> xtd::drawing::hsv {
        return value;
      }
      /// @}
      
      /// @cond
      friend auto operator <<(std::ostream& os, const hsv& value) -> std::ostream& {
        return os << xtd::string::format("hsv [hue = {}, saturation = {}, value = {}]", value.hue, value.saturation, value.value);
      };
      /// @endcond
    };
  }
}

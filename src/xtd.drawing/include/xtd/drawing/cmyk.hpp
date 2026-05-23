/// @file
/// @brief Contains xtd::drawing::cmyk struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <xtd/byte>
#include <xtd/string>
#include <xtd/uint32>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The cmyk struct.
    /// ```cpp
    /// struct cmyk;
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    struct cmyk {
      /// @name Public Properties
      
      /// @{
      /// @brief Gets or sets the cyan component value of this xtd::drawing::cmyk struct.
      /// @param a byte The cyan component value of this xtd::drawing::cmyk.
      xtd::single cyan = .0f;
      /// @brief Gets or sets the magenta component value of this xtd::drawing::cmyk struct.
      /// @param r byte The magenta component value of this xtd::drawing::cmyk.
      xtd::single magenta = .0f;
      /// @brief Gets or sets the yellow component value of this xtd::drawing::cmyk struct.
      /// @param r byte The yellow component value of this xtd::drawing::cmyk.
      xtd::single yellow = .0f;
      /// @brief Gets or sets the black component value of this xtd::drawing::cmyk struct.
      /// @param r byte The black component value of this xtd::drawing::cmyk.
      xtd::single black = .0f;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates a xtd::cmyk struct from the specified cyan, magenta, and yellow single values.
      /// @param cyan The a single value.
      /// @param magenta The r single value.
      /// @param yellow The g single value.
      /// @return an xtd::drawing::cmyk value that contains decomposed unsigned integer value.
      [[nodiscard]] static auto from_cmyk(xtd::single cyan, xtd::single magenta, xtd::single yellow, xtd::single black) noexcept -> xtd::drawing::cmyk {
        return cmyk {.cyan = cyan, .magenta = magenta, .yellow = yellow, .black = black};
      }
      /// @brief Creates a xtd::cmyk struct from the specified axtd::drawing::cmyk value.
      /// @param value The cmyk value.
      /// @return an xtd::drawing::cmyk value that contains decomposed unsigned integer value.
      [[nodiscard]] static auto from_cmyk(const cmyk& value) noexcept -> xtd::drawing::cmyk {
        return value;
      }
      /// @}
      
      /// @cond
      friend auto operator <<(std::ostream& os, const cmyk& value) -> std::ostream& {
        return os << xtd::string::format("cmyk [cyan = {}, magenta = {}, yellow = {}, black = {}]", value.cyan, value.magenta, value.black);
      };
      /// @endcond
    };
  }
}

/// @file
/// @brief Contains xtd::drawing::argb struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <xtd/byte>
#include <xtd/string>
#include <xtd/uint32>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The argb struct.
    /// ```cpp
    /// struct argb;
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    struct argb {
      /// @name Public Properties
      
      /// @{
      /// @brief Gets or sets the alpha component value of this xtd::drawing::argb struct.
      /// @param a byte The alpha component value of this xtd::drawing::argb.
      xtd::byte a = 255;
      /// @brief Gets or sets the red component value of this xtd::drawing::argb struct.
      /// @param r byte The red component value of this xtd::drawing::argb.
      xtd::byte r = 0;
      /// @brief Gets or sets the green component value of this xtd::drawing::argb struct.
      /// @param r byte The green component value of this xtd::drawing::argb.
      xtd::byte g = 0;
      /// @brief Gets or sets the blue component value of this xtd::drawing::argb struct.
      /// @param r byte The blue component value of this xtd::drawing::argb.
      xtd::byte b = 0;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Gets the 32-bit ARGB value of this xtd::drawing::argb struct.
      /// @return The 32-bit ARGB value of this xtd::drawing::argb.
      [[nodiscard]] auto to_uint32() const noexcept -> xtd::uint32 {
        return (static_cast<xtd::uint32>(a) << 24) + (static_cast<xtd::uint32>(r) << 16) + (static_cast<xtd::uint32>(g) << 8) + static_cast<xtd::uint32>(b);
      }
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Gets the 32-bit ARGB value of this xtd::drawing::argb struct.
      /// @return The 32-bit ARGB value of this xtd::drawing::argb.
      [[nodiscard]] operator xtd::uint32() const noexcept {
        return to_uint32();
      }
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates a xtd::argb struct from the specified a, r, g, and b byte values.
      /// @param a The a byte value.
      /// @param r The r byte value.
      /// @param g The g byte value.
      /// @param b The b byte value.
      /// @return an xtd::drawing::argb value that contains decomposed unsigned integer value.
      [[nodiscard]] static auto from_argb(xtd::byte a, xtd::byte r, xtd::byte g, xtd::byte b) noexcept -> xtd::drawing::argb {
        return argb {.a = a, .r = r, .g = g, .b = b};
      }
      /// @brief Creates a xtd::argb struct from the specified axtd::drawing::argb value.
      /// @param value The argb value.
      /// @return an xtd::drawing::argb value that contains decomposed unsigned integer value.
      [[nodiscard]] static auto from_argb(const argb& value) noexcept -> xtd::drawing::argb {
        return value;
      }

      /// @brief Creates a xtd::argb struct from the specified unsigned integer value.
      /// @param value The unsigned integer value.
      /// @return an xtd::drawing::argb value that contains decomposed unsigned integer value.
      [[nodiscard]] static auto from_uint32(uint32 value) noexcept -> xtd::drawing::argb {
        return argb {.a = static_cast<xtd::byte>((value & 0xFF000000) >> 24), .r = static_cast<xtd::byte>((value & 0x00FF0000) >> 16), .g = static_cast<xtd::byte>((value & 0x0000FF00) >> 8), .b = static_cast<xtd::byte>(value & 0x000000FF)};
      }
      /// @}
      
      /// @cond
      friend auto operator <<(std::ostream& os, const argb& value) -> std::ostream& {
        return os << xtd::string::format("argb [a = {}, r = {}, g = {}, b = {}]", value.a, value.r, value.g, value.b);
      };
      /// @endcond
    };
  }
}

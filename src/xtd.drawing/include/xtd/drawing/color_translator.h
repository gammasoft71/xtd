/// @file
/// @brief Contains xtd::drawing::color_translator factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "color.h"
#include <xtd/static>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Translates colors to and from GDI+ Color structures. This class cannot be inherited.
    /// @code
    /// class drawing_export_ color_translator final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::color_translator
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing
    class drawing_export_ color_translator final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Translates the specified xtd::drawing::color structure to an HEX string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The string that represents the HEX color.
      /// @remarks This method translates a xtd::drawing::color structure to a string representation of an HEX color. This is the commonly used name of a color, such as "red", "blue", or "green", and not string representation of a numeric color value, such as "#ff6347".
      static xtd::ustring to_hex(const xtd::drawing::color& value) noexcept;
      /// @brief Translates the specified xtd::drawing::color structure to an HSL string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The string that represents the HSL color.
      /// @remarks This method translates a xtd::drawing::color structure to a string representation of an HSL color. This is the commonly used name of a color, such as "red", "blue", or "green", and not string representation of a numeric color value, such as "hsl(9, 100%, 64%)".
      static xtd::ustring to_hsl(const xtd::drawing::color& value) noexcept;
      /// @brief Translates the specified xtd::drawing::color structure to an HSLA string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The string that represents the HSL color.
      /// @remarks This method translates a xtd::drawing::color structure to a string representation of an HSLA color. This is the commonly used name of a color, such as "red", "blue", or "green", and not string representation of a numeric color value, such as "hsl(9, 100%, 64%, 0.6)".
      static xtd::ustring to_hsla(const xtd::drawing::color& value) noexcept;
      /// @brief Translates the specified xtd::drawing::color structure to an HTML string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The string that represents the HTML color.
      /// @remarks This method translates a xtd::drawing::color structure to a string representation of an HTML color. This is the commonly used name of a color, such as "red", "blue", or "green", and not string representation of a numeric color value, such as "#ff6347" or "rgba(255, 99, 71, 0.5)" if alpha less than 255.
      static xtd::ustring to_html(const xtd::drawing::color& value) noexcept;
      /// @brief Translates the specified xtd::drawing::color structure to an RGB string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The string that represents the RGB color.
      /// @remarks This method translates a xtd::drawing::color structure to a string representation of an RGB color. This is the commonly used name of a color, such as "red", "blue", or "green", and not string representation of a numeric color value, such as "rgb(255, 99, 71)".
      static xtd::ustring to_rgb(const xtd::drawing::color& value) noexcept;
      /// @brief Translates the specified xtd::drawing::color structure to an RGBA string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The string that represents the RGBA color.
      /// @remarks This method translates a xtd::drawing::color structure to a string representation of an RGBA color. This is the commonly used name of a color, such as "red", "blue", or "green", and not string representation of a numeric color value, such as "rgba(255, 99, 71, 0.5)".
      static xtd::ustring to_rgba(const xtd::drawing::color& value) noexcept;
      /// @brief Translates the specified xtd::drawing::color structure to a Windows color.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The Windows color value.
      static int32 to_win32(const xtd::drawing::color& value) noexcept;
      /// @}
    };
  }
}

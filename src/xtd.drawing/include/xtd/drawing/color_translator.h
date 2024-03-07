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
    /// @brief Translates colors to and from GDI+ xtd::drawing::color structures. This class cannot be inherited.
    /// @code
    /// class drawing_export_ color_translator final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::color_translator
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    class drawing_export_ color_translator final static_ {
    public:
      /// @name Static methods
      
      /// @{
      /// @brief Translates an HEX color representation to a GDI+ xtd::drawing::color structure.
      /// @param text The string representation of the HTMLS color to translate.
      /// @return The xtd::drawing::color structure that represents the translated HEX color or xtd::drawing::color::empty if text is empty ("").
      /// @exception xtd:format_exception text is not a valid HEX color name.
      static xtd::drawing::color from_hex(const xtd::ustring& text);
      
      /// @brief Translates an HSL color representation to a GDI+ xtd::drawing::color structure.
      /// @param text The string representation of the HSL color to translate.
      /// @return The xtd::drawing::color structure that represents the translated HSL color or xtd::drawing::color::empty if text is empty ("").
      /// @exception xtd:format_exception text is not a valid HSL color name.
      static xtd::drawing::color from_hsl(const xtd::ustring& text);
      
      /// @brief Translates an HSLA color representation to a GDI+ xtd::drawing::color structure.
      /// @param text The string representation of the HSLA color to translate.
      /// @return The xtd::drawing::color structure that represents the translated HSLA color or xtd::drawing::color::empty if text is empty ("").
      /// @exception xtd:format_exception text is not a valid HSLA color name.
      static xtd::drawing::color from_hsla(const xtd::ustring& text);
      
      /// @brief Translates an HSV color representation to a GDI+ xtd::drawing::color structure.
      /// @param text The string representation of the HSV color to translate.
      /// @return The xtd::drawing::color structure that represents the translated HSV color or xtd::drawing::color::empty if text is empty ("").
      /// @exception xtd:format_exception text is not a valid HSV color name.
      static xtd::drawing::color from_hsv(const xtd::ustring& text);
      
      /// @brief Translates an HSVVA color representation to a GDI+ xtd::drawing::color structure.
      /// @param text The string representation of the HTML color to translate.
      /// @return The xtd::drawing::color structure that represents the translated HSVA color or xtd::drawing::color::empty if text is empty ("").
      /// @exception xtd:format_exception text is not a valid HSVA color name.
      static xtd::drawing::color from_hsva(const xtd::ustring& text);

      /// @brief Translates an HTML color representation to a GDI+ xtd::drawing::color structure.
      /// @param text The string representation of the HTML color to translate.
      /// @return The xtd::drawing::color structure that represents the translated HTML color or xtd::drawing::color::empty if text is empty ("").
      /// @exception xtd:format_exception text is not a valid HTML color name.
      /// @remarks This method translates a string representation of an HTML color name, such as bBlue or red, to a GDI+ xtd::drawing::color structure.
      static xtd::drawing::color from_html(const xtd::ustring& text);

      /// @brief Translates an RGB color representation to a GDI+ xtd::drawing::color structure.
      /// @param text The string representation of the RGB color to translate.
      /// @return The xtd::drawing::color structure that represents the translated RGB color or xtd::drawing::color::empty if text is empty ("").
      /// @exception xtd:format_exception text is not a valid RGB color name.
      static xtd::drawing::color from_rgb(const xtd::ustring& text);
      
      /// @brief Translates an RGBA color representation to a GDI+ xtd::drawing::color structure.
      /// @param text The string representation of the RGBA color to translate.
      /// @return The xtd::drawing::color structure that represents the translated RGBA color or xtd::drawing::color::empty if text is empty ("").
      /// @exception xtd:format_exception text is not a valid RGBA color name.
      static xtd::drawing::color from_rgba(const xtd::ustring& text);
      
      /// @brief Translates a Win32 color representation to a GDI+ xtd::drawing::color structure.
      /// @param text The string representation of the Win32 color to translate.
      /// @return The xtd::drawing::color structure that represents the translated Win32 color or xtd::drawing::color::empty if text is empty ("").
      /// @exception xtd:format_exception text is not a valid Win32 color name.
      static xtd::drawing::color from_win32(int32 value);

      /// @brief Translates the specified xtd::drawing::color structure to an HEX string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The string that represents the HEX color.
      /// @remarks This method translates an xtd::drawing::color structure into a string representation of a HEX color (e.g. "#ff6347").
      static xtd::ustring to_hex(const xtd::drawing::color& value) noexcept;
      /// @brief Translates the specified xtd::drawing::color structure to an HEX string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The string that represents the HEX color.
      /// @remarks This method translates an xtd::drawing::color structure into a string representation of a HEX color (e.g. "#ff6347").
      static xtd::ustring to_hex(const xtd::drawing::color& value, bool auto_hexa) noexcept;

      /// @brief Translates the specified xtd::drawing::color structure to an HSL string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @param auto_alpha If true and alpha channel is not 100% shows alpha value; otherwise always not show alpha value.
      /// @return The string that represents the HSL color.
      /// @remarks This method translates an xtd::drawing::color structure into a string representation of a HSL color (e.g. "hsl(9, 100%, 64%)").
      static xtd::ustring to_hsl(const xtd::drawing::color& value) noexcept;
      /// @brief Translates the specified xtd::drawing::color structure to an HSL string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @param auto_hsla If true and alpha channel is not 100% use HSLA; otherwise always use HSL.
      /// @return The string that represents the HSL color.
      /// @remarks This method translates an xtd::drawing::color structure into a string representation of a HSL color (e.g. "hsl(9, 100%, 64%)").
      static xtd::ustring to_hsl(const xtd::drawing::color& value, bool auto_alpha) noexcept;

      /// @brief Translates the specified xtd::drawing::color structure to an HSLA string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The string that represents the HSL color.
      /// @remarks This method translates an xtd::drawing::color structure into a string representation of a HSLA color (e.g. "hsla(9, 100%, 64%, 0.6)").
      static xtd::ustring to_hsla(const xtd::drawing::color& value) noexcept;

      /// @brief Translates the specified xtd::drawing::color structure to an HSV string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The string that represents the HSL color.
      /// @remarks This method translates an xtd::drawing::color structure into a string representation of a HSV color (e.g. "hsl(9, 100%, 64%)").
      static xtd::ustring to_hsv(const xtd::drawing::color& value) noexcept;
      /// @brief Translates the specified xtd::drawing::color structure to an HSV string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @param auto_hsva If true and alpha channel is not 100% use HSLA; otherwise always use HSL.
      /// @return The string that represents the HSL color.
      /// @remarks This method translates an xtd::drawing::color structure into a string representation of a HSV color (e.g. "hsl(9, 100%, 64%)").
      static xtd::ustring to_hsv(const xtd::drawing::color& value, bool auto_hsva) noexcept;

      /// @brief Translates the specified xtd::drawing::color structure to an HSVA string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The string that represents the HSL color.
      /// @remarks This method translates an xtd::drawing::color structure into a string representation of a HSVA color (e.g. "hsva(9, 100%, 64%, 0.6)").
      static xtd::ustring to_hsva(const xtd::drawing::color& value) noexcept;

      /// @brief Translates the specified xtd::drawing::color structure to an HTML string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The string that represents the HTML color.
      /// @remarks This method translates a xtd::drawing::color structure to a string representation of an HTML color. This is the commonly used name of a color, such as "red", "blue", or "green", and not string representation of a numeric color value, such as "#ff6347" or "rgba(255, 99, 71, 0.5)" if alpha less than 255.
      static xtd::ustring to_html(const xtd::drawing::color& value) noexcept;

      /// @brief Translates the specified xtd::drawing::color structure to an RGB string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The string that represents the RGB color.
      /// @remarks This method translates an xtd::drawing::color structure into a string representation of a RGB color (e.g."rgb(255, 99, 71)").
      static xtd::ustring to_rgb(const xtd::drawing::color& value) noexcept;
      /// @brief Translates the specified xtd::drawing::color structure to an RGB string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @param auto_rgba If true and alpha channel is not 100% use RGB; otherwise always use RGB.
      /// @return The string that represents the RGB color.
      /// @remarks This method translates an xtd::drawing::color structure into a string representation of a RGB color (e.g."rgb(255, 99, 71)").
      static xtd::ustring to_rgb(const xtd::drawing::color& value, bool auto_rgba) noexcept;

      /// @brief Translates the specified xtd::drawing::color structure to an RGBA string color representation.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The string that represents the RGBA color.
      /// @remarks This method translates an xtd::drawing::color structure into a string representation of a RGBA color (e.g."rgba(255, 99, 71, 0.5)").
      static xtd::ustring to_rgba(const xtd::drawing::color& value) noexcept;

      /// @brief Translates the specified xtd::drawing::color structure to a Windows color.
      /// @param value The xtd::drawing::color structure to translate.
      /// @return The Windows color value.
      static int32 to_win32(const xtd::drawing::color& value) noexcept;
      
    private:
      inline static constexpr int32 win32_red_shift = 0;
      inline static constexpr int32 win32_green_shift = 8;
      inline static constexpr int32 win32_blue_shift = 16;
      static xtd::ustring from_name(const xtd::drawing::color& value);
      static bool try_parse_hex_color(const xtd::ustring& text, xtd::drawing::color& result) noexcept;
      static bool try_parse_hsl_color(const xtd::ustring& text, xtd::drawing::color& result) noexcept;
      static bool try_parse_hsla_color(const xtd::ustring& text, xtd::drawing::color& result) noexcept;
      static bool try_parse_hsv_color(const xtd::ustring& text, xtd::drawing::color& result) noexcept;
      static bool try_parse_hsva_color(const xtd::ustring& text, xtd::drawing::color& result) noexcept;
      static bool try_parse_html_color(const xtd::ustring& text, xtd::drawing::color& result) noexcept;
      static bool try_parse_named_color(const xtd::ustring& text, xtd::drawing::color& result) noexcept;
      static bool try_parse_rgb_color(const xtd::ustring& text, xtd::drawing::color& result) noexcept;
      static bool try_parse_rgba_color(const xtd::ustring& text, xtd::drawing::color& result) noexcept;
      /// @}
    };
  }
}

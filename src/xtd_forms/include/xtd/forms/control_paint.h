#pragma once
#include <optional>
#include <string>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/graphics.h>
#include <xtd/drawing/image.h>
#include <xtd/drawing/rectangle.h>
#include <xtd/drawing/string_format.h>
#include <xtd/drawing/system_fonts.h>
#include "text_format_flags.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides methods used to paint common Windows controls and their elements. This class cannot be inherited.
    class control_paint static_ {
    public:
      /// @brief Returns the weighted average color between the two given colors.
      /// @param color1 The first color.
      /// @param color2 The second color.
      /// @param weight The weighting factor
      /// @param average_alpha if true alpha was comptute to; otheerwise the alpha result is the alpha of color1
      /// @return The average color.
      /// @remarks The alpha, red, green and blue values are averages using the following formula:
      /// @code
      /// color = color1 * (1 - weight) + color2 * weight;
      /// @endcode
      /// @remarks Thus, a weight value of 1.0 will return the first color, while a value of 0.0 will return the second color.
      static xtd::drawing::color average(const xtd::drawing::color& color1, const xtd::drawing::color& color2, double weight, bool average_alpha) {return xtd::drawing::color::from_argb(average_alpha ? static_cast<uint8_t>(color1.a() * (1 - weight) + color2.a() * weight) : static_cast<uint8_t>(color1.a()), static_cast<uint8_t>(color1.r() * (1 - weight) + color2.r() * weight), static_cast<uint8_t>(color1.g() * (1 - weight) + color2.g() * weight), static_cast<uint8_t>(color1.b() * (1 - weight) + color2.b() * weight));}

      /// @brief Returns the weighted average color between the two given colors.
      /// @param color1 The first color.
      /// @param color2 The second color.
      /// @param weight The weighting factor
      /// @return The average color.
      /// @remarks The red, green and blue values are averages using the following formula:
      /// @code
      /// color = color1 * (1 - weight) + color2 * 1 - weight;
      /// @endcode
      /// @remarks Thus, a weight value of 1.0 will return the second color, while a value of 0.0 will return the first color.
      //static xtd::drawing::color average(const xtd::drawing::color& color1, const xtd::drawing::color& color2, double weight) {return xtd::drawing::color::from_argb(static_cast<uint8_t>(color1.a() * weight + color2.a() * (1 - weight)), static_cast<uint8_t>(color1.r() * weight + color2.r() * (1 - weight)), static_cast<uint8_t>(color1.g() * weight + color2.g() * (1 - weight)), static_cast<uint8_t>(color1.b() * weight + color2.b() * (1 - weight)));}
      static xtd::drawing::color average(const xtd::drawing::color& color1, const xtd::drawing::color& color2, double weight) {return average(color1, color2, weight, false);}

      /// @brief Creates a new dark color object for the control from the specified color.
      /// @param color The xtd::drawing::color to be darkened.
      /// @return A xtd::drawing::color that represents the dark color on the control.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_dark color; otherwise, the color's luminosity value is decreased.
      static xtd::drawing::color dark(const xtd::drawing::color& base_color) {return dark(base_color, 1.0/3);}
      /// @brief Creates a new dark color object for the control from the specified color and darkens it by the specified percentage.
      /// @param color The xtd::drawing::color to be darkened.
      /// @param perc_of_dark The percentage to darken the specified xtd::drawing::color.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_dark color; otherwise, the color's luminosity value is decreased.
      static xtd::drawing::color dark(const xtd::drawing::color& base_color, double perc_of_dark_dark) {return average(base_color, xtd::drawing::color::black, perc_of_dark_dark);}

      /// @brief Creates a new dark color object for the control from the specified color.
      /// @param color The xtd::drawing::color to be darkened.
      /// @return A xtd::drawing::color that represents the dark color on the control.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_dark_dark color; otherwise, the color's luminosity value is decreased.
      static xtd::drawing::color dark_dark(const xtd::drawing::color& base_color) {return dark(base_color, 1.0);}

      /// @brief Creates a new light color object for the control from the specified color.
      /// @param color The xtd::drawing::color to be lightened.
      /// @return A xtd::drawing::color that represents the light color on the control.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_light color; otherwise, the color's luminosity value is decreased.
      static xtd::drawing::color light(const xtd::drawing::color& base_color) {return light(base_color, 1.0/3);}
      /// @brief Creates a new light color object for the control from the specified color and lightens it by the specified percentage.
      /// @param color The xtd::drawing::color to be lightened.
      /// @param perc_of_lightt The percentage to lighten the specified xtd::drawing::color.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_light color; otherwise, the color's luminosity value is decreased.
      static xtd::drawing::color light(const xtd::drawing::color& base_color, double perc_of_light_light) {return average(base_color, xtd::drawing::color::white, perc_of_light_light);}
      
      /// @brief Creates a new light color object for the control from the specified color.
      /// @param color The xtd::drawing::color to be lightened.
      /// @return A xtd::drawing::color that represents the light color on the control.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_light_lightk color; otherwise, the color's luminosity value is decreased.
      static xtd::drawing::color light_light(const xtd::drawing::color& base_color) {return light(base_color, 1.0);}
      
      static xtd::drawing::string_format string_format(xtd::forms::text_format_flags flags) {
        xtd::drawing::string_format string_format;
        string_format.line_alignment(xtd::drawing::string_alignment::center);
        string_format.alignment(xtd::drawing::string_alignment::center);
        
        if ((flags & text_format_flags::horizontal_center) == text_format_flags::horizontal_center) string_format.alignment(xtd::drawing::string_alignment::center);
        else if ((flags & text_format_flags::rigth) == text_format_flags::rigth) string_format.alignment(xtd::drawing::string_alignment::far);
        else string_format.alignment(xtd::drawing::string_alignment::near);
        
        if ((flags & text_format_flags::vertical_center) == text_format_flags::vertical_center) string_format.line_alignment(xtd::drawing::string_alignment::center);
        else if ((flags & text_format_flags::bottom) == text_format_flags::bottom) string_format.line_alignment(xtd::drawing::string_alignment::far);
        else string_format.line_alignment(xtd::drawing::string_alignment::near);
        
        if ((flags & text_format_flags::no_prefix) == text_format_flags::no_prefix) string_format.hotkey_prefix(xtd::drawing::hotkey_prefix::none);
        else if ((flags & text_format_flags::hide_prefix) == text_format_flags::hide_prefix) string_format.hotkey_prefix(xtd::drawing::hotkey_prefix::hide);
        else string_format.hotkey_prefix(xtd::drawing::hotkey_prefix::show);
        
        return string_format;
      }

    };
  }
}

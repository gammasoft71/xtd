#pragma once
#include <optional>
#include <string>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/graphics.h>
#include <xtd/drawing/image.h>
#include <xtd/drawing/rectangle.h>
#include <xtd/drawing/system_fonts.h>

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
      /// @return The average color.
      /// @remarks The alpha, red, green and blue values are averages using the following formula:
      /// @code
      /// color = color1 * weight + color2 * (1 - weight);
      /// @endcode
      /// @remarks Thus, a weight value of 1.0 will return the first color, while a value of 0.0 will return the second color.
      static xtd::drawing::color average(const xtd::drawing::color& color1, const xtd::drawing::color& color2, float weight) {return xtd::drawing::color::from_argb(static_cast<uint8_t>(color1.a() * weight + color2.a() * (1 - weight)), static_cast<uint8_t>(color1.r() * weight + color2.r() * (1 - weight)), static_cast<uint8_t>(color1.g() * weight + color2.g() * (1 - weight)), static_cast<uint8_t>(color1.b() * weight + color2.b() * (1 - weight)));}

      /// @brief Creates a new dark color object for the control from the specified color.
      /// @param color The xtd::drawing::color to be darkened.
      /// @return A xtd::drawing::color that represents the dark color on the control.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_dark color; otherwise, the color's luminosity value is decreased.
      static xtd::drawing::color dark(const xtd::drawing::color& base_color) {return dark(base_color, 1.0/3);}
      /// @brief Creates a new dark color object for the control from the specified color and darkens it by the specified percentage.
      /// @param color The xtd::drawing::color to be darkened.
      /// @param perc_of_dark The percentage to darken the specified xtd::drawing::color.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_dark color; otherwise, the color's luminosity value is decreased.
      static xtd::drawing::color dark(const xtd::drawing::color& base_color, float perc_of_dark_dark) {return average(base_color, xtd::drawing::color::black, perc_of_dark_dark);}

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
      static xtd::drawing::color light(const xtd::drawing::color& base_color, float perc_of_light_light) {return average(base_color, xtd::drawing::color::white, perc_of_light_light);}
      
      /// @brief Creates a new light color object for the control from the specified color.
      /// @param color The xtd::drawing::color to be lightened.
      /// @return A xtd::drawing::color that represents the light color on the control.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_light_lightk color; otherwise, the color's luminosity value is decreased.
      static xtd::drawing::color light_light(const xtd::drawing::color& base_color) {return light(base_color, 1.0);}
    };
  }
}

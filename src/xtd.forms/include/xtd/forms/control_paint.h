/// @file
/// @brief Contains xtd::forms::control_paint class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
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
#include "../forms_export.h"
#include "button_state.h"
#include "image_layout.h"
#include "text_format_flags.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides methods used to paint common Windows controls and their elements. This class cannot be inherited.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms drawing
    class forms_export_ control_paint final static_ {
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
      static xtd::drawing::color average(const xtd::drawing::color& color1, const xtd::drawing::color& color2, double weight, bool average_alpha) {return xtd::drawing::color::average(color1, color2, weight, average_alpha);}

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
      static xtd::drawing::color dark(const xtd::drawing::color& base_color, double perc_of_dark_dark) {return xtd::drawing::color::dark(base_color, perc_of_dark_dark);}

      /// @brief Creates a new dark color object for the control from the specified color.
      /// @param color The xtd::drawing::color to be darkened.
      /// @return A xtd::drawing::color that represents the dark color on the control.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_dark_dark color; otherwise, the color's luminosity value is decreased.
      static xtd::drawing::color dark_dark(const xtd::drawing::color& base_color) {return dark(base_color, 1.0);}

      static void draw_button(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& rectangle, xtd::forms::button_state state) {draw_button(graphics, rectangle.x(), rectangle.y(), rectangle.width(), rectangle.height(), state);}
      static void draw_button(xtd::drawing::graphics& graphics, int32_t x, int32_t y, int32_t width, int32_t height, xtd::forms::button_state state);

      /// @brief Draws the specified image in a specified rectangle with specified layout.
      /// @param xtd::drawing::graphics The Graphics to draw on.
      /// @param image The xtd::drawing::image to draw.
      /// @param rectangle xtd::drawing::rectangle structure that defines the rectangle of the drawn image.
      /// @param image_layout One of the values of xtd::forms::image_layout (center , none, stretch, tile, or zoom).
      static void draw_image(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle, xtd::forms::image_layout image_layout) {draw_image(graphics, image, rectangle.x(), rectangle.y(), rectangle.width(), rectangle.height(), image_layout);}
      /// @brief Draws the specified image in a specified rectangle with specified layout.
      /// @param xtd::drawing::graphics The Graphics to draw on.
      /// @param image The xtd::drawing::image to draw.
      /// @param x The x-coordinate of the top left of the drawn image.
      /// @param y The y-coordinate of the top left of the drawn image.
      /// @param width The width of the drawn image.
      /// @param height The height of the drawn image.
      /// @param image_layout One of the values of xtd::forms::image_layout (center , none, stretch, tile, or zoom).
      static void draw_image(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, int32_t x, int32_t y, int32_t width, int32_t height, xtd::forms::image_layout image_layout);

      /// @brief Draws the specified image in a disabled state.
      /// @param xtd::drawing::graphics The Graphics to draw on.
      /// @param image The xtd::drawing::image to draw.
      /// @param x The x-coordinate of the top left of the border image.
      /// @param y The y-coordinate of the top left of the border image.
      /// @param brightness The brighness (between 0.0 and 1.0 for drawing image disabled.
      /// @remarks The background parameter is used to calculate the fill color of the disabled image so that it is always visible against the background
      static void draw_image_disabled(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, int32_t x, int32_t y, float brightness);
      /// @brief Draws the specified image in a disabled state.
      /// @param xtd::drawing::graphics The Graphics to draw on.
      /// @param image The xtd::drawing::image to draw.
      /// @param x The x-coordinate of the top left of the border image.
      /// @param y The y-coordinate of the top left of the border image.
      /// @param background The xtd::drawing::color of the background behind the image.
      /// @remarks The background parameter is used to calculate the fill color of the disabled image so that it is always visible against the background
      static void draw_image_disabled(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, int32_t x, int32_t y, const xtd::drawing::color& background) {draw_image_disabled(graphics, image, x, y, background.get_brightness());}
      /// @brief Draws the specified image in a disabled state.
      /// @param xtd::drawing::graphics The Graphics to draw on.
      /// @param image The xtd::drawing::image to draw.
      /// @param location The xtd::drawing::point of the top left of the border image.
      /// @param brightness The brighness (between 0.0 and 1.0 for drawing image disabled.
      /// @remarks The background parameter is used to calculate the fill color of the disabled image so that it is always visible against the background
      static void draw_image_disabled(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, const xtd::drawing::point& location, float brightness) {draw_image_disabled(graphics, image, location.x(), location.y(), brightness);}
      /// @brief Draws the specified image in a disabled state.
      /// @param xtd::drawing::graphics The Graphics to draw on.
      /// @param image The xtd::drawing::image to draw.
      /// @param location The xtd::drawing::point of the top left of the border image.
      /// @param background The xtd::drawing::color of the background behind the image.
      /// @remarks The background parameter is used to calculate the fill color of the disabled image so that it is always visible against the background
      static void draw_image_disabled(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, const xtd::drawing::point& location, const xtd::drawing::color& background) {draw_image_disabled(graphics, image, location.x(), location.y(), background.get_brightness());}

      /// @brief Creates a new light color object for the control from the specified color.
      /// @param color The xtd::drawing::color to be lightened.
      /// @return A xtd::drawing::color that represents the light color on the control.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_light color; otherwise, the color's luminosity value is decreased.
      static xtd::drawing::color light(const xtd::drawing::color& base_color) {return light(base_color, 1.0/3);}
      /// @brief Creates a new light color object for the control from the specified color and lightens it by the specified percentage.
      /// @param color The xtd::drawing::color to be lightened.
      /// @param perc_of_lightt The percentage to lighten the specified xtd::drawing::color.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_light color; otherwise, the color's luminosity value is decreased.
      static xtd::drawing::color light(const xtd::drawing::color& base_color, double perc_of_light_light) {return xtd::drawing::color::light(base_color, perc_of_light_light);}
      
      /// @brief Creates a new light color object for the control from the specified color.
      /// @param color The xtd::drawing::color to be lightened.
      /// @return A xtd::drawing::color that represents the light color on the control.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_light_lightk color; otherwise, the color's luminosity value is decreased.
      static xtd::drawing::color light_light(const xtd::drawing::color& base_color) {return light(base_color, 1.0);}
      
      /// @brief Convert xtd::forms::text_format_flags to xtd::drawing::string_format.
      /// @param flags a text_format_flags to convert.
      /// @return A string_format converted.
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

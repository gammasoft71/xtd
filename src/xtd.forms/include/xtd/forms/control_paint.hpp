/// @file
/// @brief Contains xtd::forms::control_paint class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.hpp"
#include "button_state.hpp"
#include "border_sides.hpp"
#include "border_style.hpp"
#include "image_layout.hpp"
#include "text_format_flags.hpp"
#include <xtd/optional>
#include <xtd/drawing/color>
#include <xtd/drawing/font>
#include <xtd/drawing/graphics>
#include <xtd/drawing/image>
#include <xtd/drawing/rectangle>
#include <xtd/drawing/string_format>
#include <xtd/drawing/system_fonts>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Provides methods used to paint common Windows controls and their elements. This class cannot be inherited.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/control_paint>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class forms_export_ control_paint final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Returns the weighted average color between the two given colors.
      /// @param color1 The first color.
      /// @param color2 The second color.
      /// @param weight The weighting factor
      /// @param average_alpha if `true` alpha was compute to; otherwise the alpha result is the alpha of color1
      /// @return The average color.
      /// @remarks The alpha, red, green and blue values are averages using the following formula:
      /// ```cpp
      /// color = color1 * (1 - weight) + color2 * weight;
      /// ```
      /// @remarks Thus, a weight value of 1.0 will return the first color, while a value of 0.0 will return the second color.
      [[nodiscard]] static auto average(const xtd::drawing::color& color1, const xtd::drawing::color& color2, double weight, bool average_alpha) -> xtd::drawing::color;
      
      /// @brief Returns the weighted average color between the two given colors.
      /// @param color1 The first color.
      /// @param color2 The second color.
      /// @param weight The weighting factor
      /// @return The average color.
      /// @remarks The red, green and blue values are averages using the following formula:
      /// ```cpp
      /// color = color1 * (1 - weight) + color2 * 1 - weight;
      /// ```
      /// @remarks Thus, a weight value of 1.0 will return the second color, while a value of 0.0 will return the first color.
      [[nodiscard]] static auto average(const xtd::drawing::color& color1, const xtd::drawing::color& color2, double weight) -> xtd::drawing::color;
      
      /// @brief Creates a new dark color object for the control from the specified color.
      /// @param color The xtd::drawing::color to be darkened.
      /// @return A xtd::drawing::color that represents the dark color on the control.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_dark color; otherwise, the color's luminosity value is decreased.
      [[nodiscard]] static auto dark(const xtd::drawing::color& base_color) -> xtd::drawing::color;
      /// @brief Creates a new dark color object for the control from the specified color and darkens it by the specified percentage.
      /// @param color The xtd::drawing::color to be darkened.
      /// @param perc_of_dark The percentage to darken the specified xtd::drawing::color.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_dark color; otherwise, the color's luminosity value is decreased.
      [[nodiscard]] static auto dark(const xtd::drawing::color& base_color, double perc_of_dark_dark) -> xtd::drawing::color;
      
      /// @brief Creates a new dark color object for the control from the specified color.
      /// @param color The xtd::drawing::color to be darkened.
      /// @return A xtd::drawing::color that represents the dark color on the control.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_dark_dark color; otherwise, the color's luminosity value is decreased.
      [[nodiscard]] static auto dark_dark(const xtd::drawing::color& base_color) -> xtd::drawing::color;
      
      /// @brief Draws button in a specified control and graohics with specified bounds and state.
      /// @param control The control that contains the button to draw.
      /// @param graphics The graphics used to draw the button.
      /// @param rectangle the button bounds.
      /// @param state The button xtd::forms::button_state values.
      static auto draw_button(const xtd::forms::control& control, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& rectangle, xtd::forms::button_state state) -> void;
      /// @brief Draws button in a specified control and graohics with specified bounds and state.
      /// @param control The control that contains the button to draw.
      /// @param graphics The graphics used to draw the button.
      /// @param x The button horizontal position.
      /// @param y The button verticaal position.
      /// @param width The button width.
      /// @param height The button height.
      /// @param state The button xtd::forms::button_state values.
      static auto draw_button(const xtd::forms::control& control, xtd::drawing::graphics& graphics, xtd::int32 x, xtd::int32 y, xtd::int32 width, xtd::int32 height, xtd::forms::button_state state) -> void;
      
      /// @brief Draws border in a specified control and graohics with specified style, sides, color and bounds.
      /// @param control The control that contains the border to draw.
      /// @param graphics The graphics used to draw the border.
      /// @param border One of xtd::forms::border_style values.
      /// @param side The xtd::forms::border_sidesvalues.
      /// @param color The xtd::drawing::color use to draw border.
      /// @param rect The border bounds.
      static auto draw_border(const xtd::forms::control& control, xtd::drawing::graphics& graphics, xtd::forms::border_style border, xtd::forms::border_sides sides, const xtd::drawing::color& color, const xtd::drawing::rectangle& rect) -> void;
      /// @brief Draws border in a specified control and graohics with specified style, sides, color and bounds.
      /// @param control The control that contains the border to draw.
      /// @param graphics The graphics used to draw the border.
      /// @param border One of xtd::forms::border_style values.
      /// @param side The xtd::forms::border_sidesvalues.
      /// @param color The xtd::drawing::color use to draw border.
      /// @param rect The border bounds.
      /// @param light `true` if the control is light; otherwise `false`.
      static auto draw_border(const xtd::forms::control& control, xtd::drawing::graphics& graphics, xtd::forms::border_style border, xtd::forms::border_sides sides, const xtd::drawing::color& color, const xtd::drawing::rectangle& rect, bool light) -> void;

      /// @brief Draws border in a specified control and graohics with specified style, sides, back color and bounds.
      /// @param control The control that contains the border to draw.
      /// @param graphics The graphics used to draw the border.
      /// @param border One of xtd::forms::border_style values.
      /// @param side The xtd::forms::border_sidesvalues.
      /// @param back_color The xtd::drawing::color use to automatically deduce the border color.
      /// @param rect The border bounds.
      /// @remarks The color of the border is automatically deduce from the specified background color.
      static auto draw_border_from_back_color(const xtd::forms::control& control, xtd::drawing::graphics& graphics, xtd::forms::border_style border, xtd::forms::border_sides sides, const xtd::drawing::color& back_color, const xtd::drawing::rectangle& rect) -> void;
      
      /// @brief Draws the specified image in a specified rectangle with specified layout.
      /// @param xtd::drawing::graphics The Graphics to draw on.
      /// @param image The xtd::drawing::image to draw.
      /// @param rectangle xtd::drawing::rectangle structure that defines the rectangle of the drawn image.
      /// @param image_layout One of the values of xtd::forms::image_layout (center , none, stretch, tile, or zoom).
      static auto draw_image(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle, xtd::forms::image_layout image_layout) -> void;
      /// @brief Draws the specified image in a specified rectangle with specified layout.
      /// @param xtd::drawing::graphics The Graphics to draw on.
      /// @param image The xtd::drawing::image to draw.
      /// @param x The x-coordinate of the top left of the drawn image.
      /// @param y The y-coordinate of the top left of the drawn image.
      /// @param width The width of the drawn image.
      /// @param height The height of the drawn image.
      /// @param image_layout One of the values of xtd::forms::image_layout (center , none, stretch, tile, or zoom).
      static auto draw_image(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, int32 x, int32 y, int32 width, int32 height, xtd::forms::image_layout image_layout) -> void;
      
      /// @brief Draws the specified image in a disabled state.
      /// @param xtd::drawing::graphics The Graphics to draw on.
      /// @param image The xtd::drawing::image to draw.
      /// @param x The x-coordinate of the top left of the border image.
      /// @param y The y-coordinate of the top left of the border image.
      /// @param brightness The brightness (between 0.0 and 1.0 for drawing image disabled.
      /// @remarks The background parameter is used to calculate the fill color of the disabled image so that it is always visible against the background
      static auto draw_image_disabled(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, int32 x, int32 y, float brightness) -> void;
      /// @brief Draws the specified image in a disabled state.
      /// @param xtd::drawing::graphics The Graphics to draw on.
      /// @param image The xtd::drawing::image to draw.
      /// @param x The x-coordinate of the top left of the border image.
      /// @param y The y-coordinate of the top left of the border image.
      /// @param background The xtd::drawing::color of the background behind the image.
      /// @remarks The background parameter is used to calculate the fill color of the disabled image so that it is always visible against the background
      static auto draw_image_disabled(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, int32 x, int32 y, const xtd::drawing::color& background) -> void;
      /// @brief Draws the specified image in a disabled state.
      /// @param xtd::drawing::graphics The Graphics to draw on.
      /// @param image The xtd::drawing::image to draw.
      /// @param location The xtd::drawing::point of the top left of the border image.
      /// @param brightness The brightness (between 0.0 and 1.0 for drawing image disabled.
      /// @remarks The background parameter is used to calculate the fill color of the disabled image so that it is always visible against the background
      static auto draw_image_disabled(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, const xtd::drawing::point& location, float brightness) -> void;
      /// @brief Draws the specified image in a disabled state.
      /// @param xtd::drawing::graphics The Graphics to draw on.
      /// @param image The xtd::drawing::image to draw.
      /// @param location The xtd::drawing::point of the top left of the border image.
      /// @param background The xtd::drawing::color of the background behind the image.
      /// @remarks The background parameter is used to calculate the fill color of the disabled image so that it is always visible against the background
      static auto draw_image_disabled(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, const xtd::drawing::point& location, const xtd::drawing::color& background) -> void;
      
      /// @brief Creates a new light color object for the control from the specified color.
      /// @param color The xtd::drawing::color to be lightened.
      /// @return A xtd::drawing::color that represents the light color on the control.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_light color; otherwise, the color's luminosity value is decreased.
      [[nodiscard]] static auto light(const xtd::drawing::color& base_color) -> xtd::drawing::color;
      /// @brief Creates a new light color object for the control from the specified color and lightens it by the specified percentage.
      /// @param color The xtd::drawing::color to be lightened.
      /// @param perc_of_light The percentage to lighten the specified xtd::drawing::color.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_light color; otherwise, the color's luminosity value is decreased.
      [[nodiscard]] static auto light(const xtd::drawing::color& base_color, double perc_of_light_light) -> xtd::drawing::color;
      
      /// @brief Creates a new light color object for the control from the specified color.
      /// @param color The xtd::drawing::color to be lightened.
      /// @return A xtd::drawing::color that represents the light color on the control.
      /// @remarks If the specified xtd::drawing::color is one of the xtd::drawing::system_color, the color is converted to a xtd::drawing::system_color.control_light_light color; otherwise, the color's luminosity value is decreased.
      [[nodiscard]] static auto light_light(const xtd::drawing::color& base_color) -> xtd::drawing::color;
      
      /// @brief Convert xtd::forms::text_format_flags to xtd::drawing::string_format.
      /// @param flags a text_format_flags to convert.
      /// @return A string_format converted.
      [[nodiscard]] static auto string_format(xtd::forms::text_format_flags flags) -> xtd::drawing::string_format;
      /// @}
    };
  }
}

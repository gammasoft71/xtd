/// @file
/// @brief Contains xtd::forms::style_sheets::button_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <vector>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/graphics.h>
#include <xtd/drawing/rectangle.h>
#include <xtd/forms/flat_style.h>
#include <xtd/forms/visual_styles/push_button_state.h>
#include "box_renderer.h"
#include "text_renderer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      class button_renderer static_ {
      public:
        static void draw_button(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::flat_style button_style, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags text_format, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state button_state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
          std::array<xtd::forms::style_sheets::border_data, 4> borders = {
            xtd::forms::style_sheets::border_data {std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::colors::light_pink()), xtd::forms::style_sheets::border_style::outset, 4, 5},
            xtd::forms::style_sheets::border_data {std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::colors::light_green()), xtd::forms::style_sheets::border_style::outset, 5, 5},
            xtd::forms::style_sheets::border_data {std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::colors::light_blue()), xtd::forms::style_sheets::border_style::outset, 2, 5},
            xtd::forms::style_sheets::border_data {std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::colors::light_yellow()), xtd::forms::style_sheets::border_style::outset, 3, 5},
          };
          box_data data(xtd::forms::padding(3, 5, 3, 0), borders, xtd::forms::padding(1), back_color.has_value() ? std::make_shared<xtd::drawing::solid_brush>(back_color.value()) : nullptr, std::nullopt, std::nullopt);
          
          box_renderer::draw_box(graphics, bounds, data);
          //xtd::forms::style_sheets::text_renderer::draw_text(graphics, text, font, xtd::drawing::color::white, rect, text_format);
        }
        
      private:
      };
    }
  }
}

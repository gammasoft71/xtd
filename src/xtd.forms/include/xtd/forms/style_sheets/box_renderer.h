/// @file
/// @brief Contains xtd::forms::style_sheets::box_renderer static class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "box_data.h"
#include "border_renderer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      class box_renderer static_ {
      public:
        static void draw_box(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::box_data& data) {
          auto border_rect = xtd::drawing::rectangle::offset(bounds, data.margin().left(), data.margin().top());
          border_rect = xtd::drawing::rectangle::inflate(border_rect, -data.margin().right() - data.margin().left(), -data.margin().bottom() - data.margin().top());
          xtd::forms::style_sheets::border_renderer::draw_border(graphics, border_rect, data.borders());
          auto color = data.background_color() ? data.background_color() : std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::colors::light_gray());
          auto background_rect = xtd::drawing::rectangle::offset(border_rect, data.borders()[3].width(), data.borders()[0].width());
          background_rect = xtd::drawing::rectangle::inflate(background_rect, -data.borders()[3].width() - data.borders()[1].width(), -data.borders()[0].width() - data.borders()[2].width());
          graphics.fill_rectangle(*color, background_rect);
        }
        
      private:
      };
    }
  }
}

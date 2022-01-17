/// @file
/// @brief Contains xtd::forms::style_sheets::border_renderer static class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "border_data.h"
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/graphics.h>
#include <xtd/drawing/rectangle.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      class border_renderer static_ {
      public:
        static void draw_border(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data) {
          draw_line_top(graphics, bounds, data);
          draw_line_left(graphics, bounds, data);
          draw_line_bottom(graphics, bounds, data);
          draw_line_right(graphics, bounds, data);
        }
        
      private:
        static void draw_line_top(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data) {
          auto pen_width = data[0].width();
          auto border_rect = xtd::drawing::rectangle::inflate(xtd::drawing::rectangle::offset(bounds, pen_width / 2, pen_width / 2), -pen_width, -pen_width);
          auto color = data[0].color() ? data[0].color() : std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::colors::black());
          // top
          graphics.draw_line(xtd::drawing::pen(*color, pen_width), border_rect.left() + data[0].radius(), border_rect.top(), border_rect.right() - data[1].radius(), border_rect.top());
          // top-left
          graphics.draw_arc(xtd::drawing::pen(*color, pen_width), border_rect.left(), border_rect.top(), data[0].radius() * 2, data[0].radius() * 2, 225, 45);
          // top-right
          graphics.draw_arc(xtd::drawing::pen(*color, pen_width), border_rect.right() - data[1].radius() * 2, border_rect.top(), data[1].radius() * 2, data[1].radius() * 2, 270, 45);
        }
        
        static void draw_line_left(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data) {
          auto pen_width = data[3].width();
          auto border_rect = xtd::drawing::rectangle::inflate(xtd::drawing::rectangle::offset(bounds, pen_width / 2, pen_width / 2), -pen_width, -pen_width);
          auto color = data[1].color() ? data[1].color() : std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::colors::black());
          // left
          graphics.draw_line(xtd::drawing::pen(*color, pen_width), border_rect.left(), border_rect.top() + data[0].radius(), border_rect.x(), border_rect.bottom() - data[3].radius());
          // left-top
          graphics.draw_arc(xtd::drawing::pen(*color, pen_width), border_rect.left(), border_rect.top(), data[0].radius() * 2, data[0].radius() * 2, 180, 45);
          // left-bottom
          graphics.draw_arc(xtd::drawing::pen(*color, pen_width), border_rect.left(), border_rect.bottom() - data[3].radius() * 2, data[3].radius() * 2, data[3].radius() * 2, 135, 45);
        }
        
        static void draw_line_bottom(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data) {
          auto pen_width = data[2].width();
          auto border_rect = xtd::drawing::rectangle::inflate(xtd::drawing::rectangle::offset(bounds, pen_width / 2, pen_width / 2), -pen_width, -pen_width);
          auto color = data[2].color() ? data[2].color() : std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::colors::black());
          // bottom
          graphics.draw_line(xtd::drawing::pen(*color, pen_width), border_rect.left() + data[3].radius(), border_rect.bottom(), border_rect.right() - data[2].radius(), border_rect.bottom());
          // bottom-left
          graphics.draw_arc(xtd::drawing::pen(*color, pen_width), border_rect.left(), border_rect.bottom() - data[3].radius() * 2, data[3].radius() * 2, data[3].radius() * 2, 90, 45);
          // bottom-right
          graphics.draw_arc(xtd::drawing::pen(*color, pen_width), border_rect.right() - data[2].radius() * 2, border_rect.bottom() - data[2].radius() * 2, data[2].radius() * 2, data[2].radius() * 2, 45, 45);
        }
        
        static void draw_line_right(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data) {
          auto pen_width = data[1].width();
          auto border_rect = xtd::drawing::rectangle::inflate(xtd::drawing::rectangle::offset(bounds, pen_width / 2, pen_width / 2), -pen_width, -pen_width);
          auto color = data[3].color() ? data[3].color() : std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::colors::black());
          // right
          graphics.draw_line(xtd::drawing::pen(*color, pen_width), border_rect.right(), border_rect.top() + data[1].radius(), border_rect.right(), border_rect.bottom() - data[1].radius());
          // right-top
          graphics.draw_arc(xtd::drawing::pen(*color, pen_width), border_rect.right() - data[2].radius() * 2, border_rect.top(), data[2].radius() * 2, data[2].radius() * 2, 315, 45);
          // right-bottom
          graphics.draw_arc(xtd::drawing::pen(*color, pen_width), border_rect.right() - data[2].radius() * 2, border_rect.bottom() - data[2].radius() * 2, data[2].radius() * 2, data[2].radius() * 2, 0, 45);
        }
      };
    }
  }
}

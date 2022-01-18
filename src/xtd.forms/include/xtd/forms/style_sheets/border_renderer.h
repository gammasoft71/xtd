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
        static constexpr size_t top_index = 0;
        static constexpr size_t right_index = 1;
        static constexpr size_t bottom_index = 2;
        static constexpr size_t left_index = 3;

        static constexpr size_t top_left_index = 0;
        static constexpr size_t top_right_index = 1;
        static constexpr size_t bottom_right_index = 2;
        static constexpr size_t bottom_left_index = 3;
        
      public:
        static void draw_border(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data) {
          draw_line_top(graphics, bounds, data);
          draw_line_left(graphics, bounds, data);
          draw_line_bottom(graphics, bounds, data);
          draw_line_right(graphics, bounds, data);
        }
        
      private:
        static void draw_line_top(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data) {
          auto pen_width1 = data[top_index].width();
          auto border_rect1 = xtd::drawing::rectangle::inflate(xtd::drawing::rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
          auto color1 = data[top_index].color() ? data[top_index].color() : std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::colors::black());
          
          if (is<xtd::drawing::solid_brush>(color1) && data[top_index].style() == xtd::forms::style_sheets::border_style::inset && as<xtd::drawing::solid_brush>(color1)->color().is_light())
            color1 = std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::color::dark(as<xtd::drawing::solid_brush>(color1)->color()));
          if (is<xtd::drawing::solid_brush>(color1) && data[top_index].style() == xtd::forms::style_sheets::border_style::outset && as<xtd::drawing::solid_brush>(color1)->color().is_dark())
            color1 = std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::color::light(as<xtd::drawing::solid_brush>(color1)->color()));

            auto pen1 = xtd::drawing::pen(*color1, pen_width1);
          pen1.dash_style(border_style_to_dash_style(data[top_index].style()));
          // top
          graphics.draw_line(pen1, border_rect1.left() + data[top_left_index].radius(), border_rect1.top(), border_rect1.right() - data[top_right_index].radius(), border_rect1.top());
          // top-left
          if ( data[top_left_index].radius()) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.top(), data[top_left_index].radius() * 2, data[top_left_index].radius() * 2, 225, 45);
          // top-right
          if ( data[top_right_index].radius()) graphics.draw_arc(pen1, border_rect1.right() - data[top_right_index].radius() * 2, border_rect1.top(), data[top_right_index].radius() * 2, data[top_right_index].radius() * 2, 270, 45);
        }

        static void draw_line_right(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data) {
          auto pen_width1 = data[right_index].width();
          auto border_rect1 = xtd::drawing::rectangle::inflate(xtd::drawing::rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
          auto color1 = data[right_index].color() ? data[right_index].color() : std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::colors::black());
          
          if (is<xtd::drawing::solid_brush>(color1) && data[right_index].style() == xtd::forms::style_sheets::border_style::inset && as<xtd::drawing::solid_brush>(color1)->color().is_dark())
            color1 = std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::color::light(as<xtd::drawing::solid_brush>(color1)->color()));
          if (is<xtd::drawing::solid_brush>(color1) && data[right_index].style() == xtd::forms::style_sheets::border_style::outset && as<xtd::drawing::solid_brush>(color1)->color().is_light())
            color1 = std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::color::dark(as<xtd::drawing::solid_brush>(color1)->color()));
          
          auto pen1 = xtd::drawing::pen(*color1, pen_width1);
          pen1.dash_style(border_style_to_dash_style(data[right_index].style()));
          // right
          graphics.draw_line(pen1, border_rect1.right(), border_rect1.top() + data[top_right_index].radius(), border_rect1.right(), border_rect1.bottom() - data[bottom_right_index].radius());
          // top-right
          if ( data[top_right_index].radius()) graphics.draw_arc(pen1, border_rect1.right() - data[top_right_index].radius() * 2, border_rect1.top(), data[top_right_index].radius() * 2, data[top_right_index].radius() * 2, 315, 45);
          // bottom-right
          if ( data[bottom_right_index].radius()) graphics.draw_arc(pen1, border_rect1.right() - data[bottom_right_index].radius() * 2, border_rect1.bottom() - data[bottom_right_index].radius() * 2, data[bottom_right_index].radius() * 2, data[bottom_right_index].radius() * 2, 0, 45);
        }

        static void draw_line_bottom(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data) {
          auto pen_width1 = data[bottom_index].width();
          auto border_rect1 = xtd::drawing::rectangle::inflate(xtd::drawing::rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
          auto color1 = data[bottom_index].color() ? data[bottom_index].color() : std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::colors::black());

          if (is<xtd::drawing::solid_brush>(color1) && data[bottom_index].style() == xtd::forms::style_sheets::border_style::inset && as<xtd::drawing::solid_brush>(color1)->color().is_dark())
            color1 = std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::color::light(as<xtd::drawing::solid_brush>(color1)->color()));
          if (is<xtd::drawing::solid_brush>(color1) && data[bottom_index].style() == xtd::forms::style_sheets::border_style::outset && as<xtd::drawing::solid_brush>(color1)->color().is_light())
            color1 = std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::color::dark(as<xtd::drawing::solid_brush>(color1)->color()));

          auto pen1 = xtd::drawing::pen(*color1, pen_width1);
          pen1.dash_style(border_style_to_dash_style(data[bottom_index].style()));
          // bottom
          graphics.draw_line(pen1, border_rect1.left() + data[bottom_left_index].radius(), border_rect1.bottom(), border_rect1.right() - data[bottom_right_index].radius(), border_rect1.bottom());
          // bottom-left
          if ( data[bottom_left_index].radius()) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.bottom() - data[bottom_left_index].radius() * 2, data[bottom_left_index].radius() * 2, data[bottom_left_index].radius() * 2, 90, 45);
          // bottom-right
          if ( data[bottom_right_index].radius()) graphics.draw_arc(pen1, border_rect1.right() - data[bottom_right_index].radius() * 2, border_rect1.bottom() - data[bottom_right_index].radius() * 2, data[bottom_right_index].radius() * 2, data[bottom_right_index].radius() * 2, 45, 45);
        }
        
        static void draw_line_left(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const std::array<xtd::forms::style_sheets::border_data, 4>& data) {
          auto pen_width1 = data[left_index].width();
          auto border_rect1 = xtd::drawing::rectangle::inflate(xtd::drawing::rectangle::offset(bounds, pen_width1 / 2, pen_width1 / 2), -pen_width1, -pen_width1);
          auto color1 = data[left_index].color() ? data[left_index].color() : std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::colors::black());
          
          if (is<xtd::drawing::solid_brush>(color1) && data[left_index].style() == xtd::forms::style_sheets::border_style::inset && as<xtd::drawing::solid_brush>(color1)->color().is_light())
            color1 = std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::color::dark(as<xtd::drawing::solid_brush>(color1)->color()));
          if (is<xtd::drawing::solid_brush>(color1) && data[left_index].style() == xtd::forms::style_sheets::border_style::outset && as<xtd::drawing::solid_brush>(color1)->color().is_dark())
            color1 = std::make_shared<xtd::drawing::solid_brush>(xtd::drawing::color::light(as<xtd::drawing::solid_brush>(color1)->color()));
          
          auto pen1 = xtd::drawing::pen(*color1, pen_width1);
          pen1.dash_style(border_style_to_dash_style(data[left_index].style()));
          // left
          graphics.draw_line(pen1, border_rect1.left(), border_rect1.top() + data[top_left_index].radius(), border_rect1.x(), border_rect1.bottom() - data[bottom_left_index].radius());
          // top-left
          if ( data[top_left_index].radius()) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.top(), data[top_left_index].radius() * 2, data[top_left_index].radius() * 2, 180, 45);
          // bottom-left
          if ( data[bottom_left_index].radius()) graphics.draw_arc(pen1, border_rect1.left(), border_rect1.bottom() - data[bottom_left_index].radius() * 2, data[bottom_left_index].radius() * 2, data[bottom_left_index].radius() * 2, 135, 45);
        }
        
      private:
        static xtd::drawing::dash_style border_style_to_dash_style(xtd::forms::style_sheets::border_style value) {
          if (value == xtd::forms::style_sheets::border_style::solid) return xtd::drawing::dash_style::solid;
          if (value == xtd::forms::style_sheets::border_style::dashed) return xtd::drawing::dash_style::dash;
          if (value == xtd::forms::style_sheets::border_style::dotted) return xtd::drawing::dash_style::dot;
          if (value == xtd::forms::style_sheets::border_style::dot_dash) return xtd::drawing::dash_style::dash_dot;
          if (value == xtd::forms::style_sheets::border_style::dot_dot_dash) return xtd::drawing::dash_style::dash_dot_dot;
          return xtd::drawing::dash_style::solid;
        }
      };
    }
  }
}

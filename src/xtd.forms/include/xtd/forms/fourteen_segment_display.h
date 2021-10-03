/// @file
/// @brief Contains xtd::forms::fourteen_segment_display control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "seven_segment_display.h"

namespace xtd {
  namespace forms {
    /// @brief Represents a nine segment display class.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of fourteen segment display control.
    /// @include fourteen_segment_display.cpp
    class fourteen_segment_display : public seven_segment_display {
    public:
      /// @brief Initialize a new instance of fourteen_segment_display class.
      fourteen_segment_display() = default;

      using seven_segment_display::thickness;
      /// @brief Sets thickness of segment.
      /// @param value A int32_t that represent the segment thickness.
      /// @return Current seven_segment_display.
      int32_t thickness() const override {return thickness_.value_or(size_.height() < 20 ? 1 : (size_.height() / 20 + ((size_.height() / 20) % 2 ? 0 : 1)));}

    protected:
      void on_paint(paint_event_args& e) override {
        seven_segment_display::on_paint(e);
        if ((value_ & forms::segments::g1) == forms::segments::g1) draw_segment_g1(e.graphics(), fore_color());
        if ((value_ & forms::segments::g2) == forms::segments::g2) draw_segment_g2(e.graphics(), fore_color());
        if ((value_ & forms::segments::h) == forms::segments::h) draw_segment_h(e.graphics(), fore_color());
        if ((value_ & forms::segments::i) == forms::segments::i) draw_segment_i(e.graphics(), fore_color());
        if ((value_ & forms::segments::j) == forms::segments::j) draw_segment_j(e.graphics(), fore_color());
        if ((value_ & forms::segments::k) == forms::segments::k) draw_segment_k(e.graphics(), fore_color());
        if ((value_ & forms::segments::l) == forms::segments::l) draw_segment_l(e.graphics(), fore_color());
        if ((value_ & forms::segments::m) == forms::segments::m) draw_segment_m(e.graphics(), fore_color());
      }
 
      void draw_back_digit(drawing::graphics& graphics) override {
        seven_segment_display::draw_back_digit(graphics);
        draw_segment_g1(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
        draw_segment_g2(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
        draw_segment_h(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
        draw_segment_i(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
        draw_segment_j(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
        draw_segment_k(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
        draw_segment_l(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
        draw_segment_m(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
      }

      /// @brief Draw segment g1 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_g1(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() / 2 + offset, size_.width() / 2 - 1 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + abs(2 * offset), size_.height() / 2 + offset, size_.width() / 2 - 1 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() / 2 + offset, size_.width() / 2 - 1 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() / 2 + offset, size_.width() /2 - 1 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() / 2 + offset, size_.width() /2 - 1 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), size_.height() / 2 + offset, size_.width() / 2 - 1 - abs(offset), size_.height() / 2 + offset);
        }
      }

      /// @brief Draw segment g2 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_g2(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 + abs(offset), size_.height() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 + abs(offset), size_.height() / 2 + offset, size_.width() - 3 - abs(2 * offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 + abs(offset), size_.height() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 + abs(offset), size_.height() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 + abs(offset), size_.height() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 + abs(offset), size_.height() / 2 + offset, size_.width() - 3 - thickness(), size_.height() / 2 + offset);
        }
      }

      /// @brief Draw segment h on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_h(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
          graphics.draw_line(drawing::pen(color), 2 + thickness() + abs(offset), 2 + thickness(), size_.width() / 2 - thickness() / 2 - 2, size_.height() / 2 - 2 - thickness() / 2 - abs(offset));
          graphics.draw_line(drawing::pen(color), 2 + thickness(), 2 + thickness() + abs(offset), size_.width() / 2 - 2 - thickness() / 2 - abs(offset), size_.height() / 2 - 2 - thickness() / 2);
        }
      }
      
      /// @brief Draw segment ion specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_i(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
          graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, 2 + thickness(), size_.width() / 2 - offset, size_.height() / 2 - 1 - abs(offset));
      }

      /// @brief Draw segment j on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_j(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
          graphics.draw_line(drawing::pen(color), size_.width() - 3 - thickness() - abs(offset), 2 + thickness(), size_.width()  /2 + 2 + thickness() / 2, size_.height() / 2 - 2 - thickness() / 2 - abs(offset));
          graphics.draw_line(drawing::pen(color), size_.width() - 3 - thickness(), 2 + thickness() + abs(offset), size_.width() /2 + 2 + thickness() / 2 + abs(offset), size_.height() / 2 - 2 - thickness() / 2);
        }
      }
      
      /// @brief Draw segment k on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_k(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
          graphics.draw_line(drawing::pen(color), size_.width() / 2 - 2 - thickness() / 2 - abs(offset), size_.height() / 2 + 2 + thickness() / 2, 2 + thickness(), size_.height() - 3 - thickness() - abs(offset));
          graphics.draw_line(drawing::pen(color), size_.width() / 2 - 2 - thickness() / 2, size_.height() / 2 + 2 + thickness() / 2 + abs(offset), 2 + thickness() + abs(offset), size_.height() - 3 - thickness());
        }
      }

      /// @brief Draw segment l on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_l(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
          graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size_.width() / 2 - offset, size_.height() - 3 - thickness());
      }
      
      /// @brief Draw segment m on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_m(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
          graphics.draw_line(drawing::pen(color), size_.width()  /2 + 2 + thickness() / 2 + abs(offset), size_.height() / 2 + 2 + thickness() / 2, size_.width() - 3 - thickness(), size_.height() - 3 - thickness() - abs(offset));
          graphics.draw_line(drawing::pen(color), size_.width()  /2 + 2 + thickness() / 2, size_.height() / 2 + 2 + thickness() / 2 + abs(offset), size_.width() - 3 - thickness() - abs(offset), size_.height() - 3 - thickness());
        }
      }

    protected:
      void draw_segment_g(drawing::graphics& graphics, const drawing::color& color) override {}
    };
  }
}

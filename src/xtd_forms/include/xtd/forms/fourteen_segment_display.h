#pragma once
#include "seven_segment_display.h"

namespace xtd {
  namespace forms {
    /// @brief represent a nine segment display class
    class fourteen_segment_display : public seven_segment_display {
    public:
      fourteen_segment_display() = default;

      using seven_segment_display::thickness;
      int32_t thickness() const override {return thickness_.value_or(size_.height() < 20 ? 1 : (size_.height() / 20 + ((size_.height() / 20) % 2 ? 0 : 1)));}

    protected:
      void on_paint(paint_event_args& e) override {
        seven_segment_display::on_paint(e);
        drawing::graphics graphics = e.graphics();
        if ((value_ & forms::segments::g1) == forms::segments::g1) draw_segment_g1(graphics, fore_color());
        if ((value_ & forms::segments::g2) == forms::segments::g2) draw_segment_g2(graphics, fore_color());
        if ((value_ & forms::segments::h) == forms::segments::h) draw_segment_h(graphics, fore_color());
        if ((value_ & forms::segments::i) == forms::segments::i) draw_segment_i(graphics, fore_color());
        if ((value_ & forms::segments::j) == forms::segments::j) draw_segment_j(graphics, fore_color());
        if ((value_ & forms::segments::k) == forms::segments::k) draw_segment_k(graphics, fore_color());
        if ((value_ & forms::segments::l) == forms::segments::l) draw_segment_l(graphics, fore_color());
        if ((value_ & forms::segments::m) == forms::segments::m) draw_segment_m(graphics, fore_color());
      }
 
      void draw_background_digit(drawing::graphics& graphics) override {
        seven_segment_display::draw_background_digit(graphics);
        draw_segment_g1(graphics, background_segment_color());
        draw_segment_g2(graphics, background_segment_color());
        draw_segment_h(graphics, background_segment_color());
        draw_segment_i(graphics, background_segment_color());
        draw_segment_j(graphics, background_segment_color());
        draw_segment_k(graphics, background_segment_color());
        draw_segment_l(graphics, background_segment_color());
        draw_segment_m(graphics, background_segment_color());
      }

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

      virtual void draw_segment_h(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
          graphics.draw_line(drawing::pen(color), 2 + thickness() + abs(offset), 2 + thickness(), size_.width() / 2 - thickness() / 2 - 2, size_.height() / 2 - 2 - thickness() / 2 - abs(offset));
          graphics.draw_line(drawing::pen(color), 2 + thickness(), 2 + thickness() + abs(offset), size_.width() / 2 - 2 - thickness() / 2 - abs(offset), size_.height() / 2 - 2 - thickness() / 2);
        }
      }
      
      virtual void draw_segment_i(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
          graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, 2 + thickness(), size_.width() / 2 - offset, size_.height() / 2 - 1 - abs(offset));
      }

      virtual void draw_segment_j(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
          graphics.draw_line(drawing::pen(color), size_.width() - 3 - thickness() - abs(offset), 2 + thickness(), size_.width()  /2 + 2 + thickness() / 2, size_.height() / 2 - 2 - thickness() / 2 - abs(offset));
          graphics.draw_line(drawing::pen(color), size_.width() - 3 - thickness(), 2 + thickness() + abs(offset), size_.width() /2 + 2 + thickness() / 2 + abs(offset), size_.height() / 2 - 2 - thickness() / 2);
        }
      }
      
      virtual void draw_segment_k(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
          graphics.draw_line(drawing::pen(color), size_.width() / 2 - 2 - thickness() / 2 - abs(offset), size_.height() / 2 + 2 + thickness() / 2, 2 + thickness(), size_.height() - 3 - thickness() - abs(offset));
          graphics.draw_line(drawing::pen(color), size_.width() / 2 - 2 - thickness() / 2, size_.height() / 2 + 2 + thickness() / 2 + abs(offset), 2 + thickness() + abs(offset), size_.height() - 3 - thickness());
        }
      }

      virtual void draw_segment_l(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
          graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size_.width() / 2 - offset, size_.height() - 3 - thickness());
      }
      
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

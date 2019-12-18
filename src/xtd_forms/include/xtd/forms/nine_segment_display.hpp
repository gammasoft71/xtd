#pragma once
#include "seven_segment_display.hpp"

namespace xtd {
  namespace forms {
    /// @brief represent a seven segment display class
    class nine_segment_display : public seven_segment_display {
    public:
      nine_segment_display() = default;
      
    protected:
      void on_paint(paint_event_args& e) override {
        drawing::graphics graphics = e.graphics();
        drawing::size lcd_digit_size((height() - 3) / 2 + 2, height());
        int32_t thickness = lcd_digit_size.height() / 12;
        thickness -= thickness % 2 ? 0 : 1;
        
        seven_segment_display::on_paint(e);
        if ((value_ & forms::segments::h) == forms::segments::h) draw_segment_h(graphics, fore_color(), lcd_digit_size, thickness);
        if ((value_ & forms::segments::i) == forms::segments::i) draw_segment_i(graphics, fore_color(), lcd_digit_size, thickness);
      }
           
      virtual void draw_segment_h(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
        for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++) {
          graphics.draw_line(drawing::pen(color), size.width() - 3 - thickness - abs(offset), 2 + thickness, 2 + thickness, size.height() / 2 - 2 - thickness / 2 - abs(offset));
          graphics.draw_line(drawing::pen(color), size.width() - 3 - thickness, 2 + thickness + abs(offset), 2 + thickness + abs(offset), size.height() / 2 - 2 - thickness / 2);
        }
      }
      
      virtual void draw_segment_i(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
        for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++) {
          graphics.draw_line(drawing::pen(color), size.width() - 3 - thickness - abs(offset), size.height() / 2 + 2 + thickness / 2, 2 + thickness, size.height() - 3 - thickness - abs(offset));
          graphics.draw_line(drawing::pen(color), size.width() - 3 - thickness, size.height() / 2 + 2 + thickness / 2 + abs(offset), 2 + thickness + abs(offset), size.height() - 3 - thickness);
        }
      }
    };
  }
}

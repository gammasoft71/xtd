/// @file
/// @brief Contains xtd::forms::nine_segment_display control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "seven_segment_display.h"

namespace xtd {
  namespace forms {
    /// @brief represent a nine segment display class
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Example
    /// The following code example demonstrate the use of nine segment display control.
    /// @include nine_segment_display.cpp
    /// @par Windows
    /// @image html nine_segment_display_w.png
    /// <br>
    /// @image html nine_segment_display_wd.png
    /// @par macOS
    /// @image html nine_segment_display_m.png
    /// <br>
    /// @image html nine_segment_display_md.png
    /// @par Gnome
    /// @image html nine_segment_display_g.png
    /// <br>
    /// @image html nine_segment_display_gd.png
class nine_segment_display : public seven_segment_display {
    public:
      nine_segment_display() = default;

      using seven_segment_display::thickness;
      int32_t thickness() const override {return thickness_.value_or(size_.height() < 20 ? 1 : (size_.height() / 20 + ((size_.height() / 20) % 2 ? 0 : 1)));}

    protected:
      void on_paint(paint_event_args& e) override {
        seven_segment_display::on_paint(e);
        drawing::graphics graphics = e.graphics();
        if ((value_ & forms::segments::h) == forms::segments::h) draw_segment_h(graphics, fore_color());
        if ((value_ & forms::segments::i) == forms::segments::i) draw_segment_i(graphics, fore_color());
      }
 
      void draw_background_digit(drawing::graphics& graphics) override {
        seven_segment_display::draw_background_digit(graphics);
        draw_segment_h(graphics, background_segment_color());
        draw_segment_i(graphics, background_segment_color());
      }

      virtual void draw_segment_h(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
          graphics.draw_line(drawing::pen(color), size_.width() - 3 - thickness() - abs(offset), 2 + thickness(), 2 + thickness(), size_.height() / 2 - 2 - thickness() / 2 - abs(offset));
          graphics.draw_line(drawing::pen(color), size_.width() - 3 - thickness(), 2 + thickness() + abs(offset), 2 + thickness() + abs(offset), size_.height() / 2 - 2 - thickness() / 2);
        }
      }
      
      virtual void draw_segment_i(drawing::graphics& graphics, const drawing::color& color) {
        for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
          graphics.draw_line(drawing::pen(color), size_.width() - 3 - thickness() - abs(offset), size_.height() / 2 + 2 + thickness() / 2, 2 + thickness(), size_.height() - 3 - thickness() - abs(offset));
          graphics.draw_line(drawing::pen(color), size_.width() - 3 - thickness(), size_.height() / 2 + 2 + thickness() / 2 + abs(offset), 2 + thickness() + abs(offset), size_.height() - 3 - thickness());
        }
      }
    };
  }
}

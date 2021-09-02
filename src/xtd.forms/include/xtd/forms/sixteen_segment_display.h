/// @file
/// @brief Contains xtd::forms::sixteen_segment_display control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "fourteen_segment_display.h"

namespace xtd {
  namespace forms {
    /// @brief represent a nine segment display class
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of sixteen segment display control.
    /// @include sixteen_segment_display.cpp
    /// @par Windows
    /// @image html sixteen_segment_display_w.png
    /// <br>
    /// @image html sixteen_segment_display_wd.png
    /// @par macOS
    /// @image html sixteen_segment_display_m.png
    /// <br>
    /// @image html sixteen_segment_display_md.png
    /// @par Gnome
    /// @image html sixteen_segment_display_g.png
    /// <br>
    /// @image html sixteen_segment_display_gd.png
    class sixteen_segment_display : public fourteen_segment_display {
    public:
      /// @brief Initialize a new instance of nine_segment_display class.
      sixteen_segment_display() = default;

      using fourteen_segment_display::thickness;
      /// @brief Sets thickness of segment.
      /// @param value A int32_t that represent the segment tickness.
      /// @return Current seven_segment_display.
      int32_t thickness() const override {return thickness_.value_or(size_.height() < 20 ? 1 : (size_.height() / 20 + ((size_.height() / 20) % 2 ? 0 : 1)));}

    protected:
      void on_paint(paint_event_args& e) override {
        fourteen_segment_display::on_paint(e);
        if ((value_ & forms::segments::a1) == forms::segments::a1) draw_segment_a1(e.graphics(), fore_color());
        if ((value_ & forms::segments::a2) == forms::segments::a2) draw_segment_a2(e.graphics(), fore_color());
        if ((value_ & forms::segments::d1) == forms::segments::d1) draw_segment_d1(e.graphics(), fore_color());
        if ((value_ & forms::segments::d2) == forms::segments::d2) draw_segment_d2(e.graphics(), fore_color());
      }
 
      void draw_back_digit(drawing::graphics& graphics) override {
        fourteen_segment_display::draw_back_digit(graphics);
        draw_segment_a1(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
        draw_segment_a2(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
        draw_segment_d1(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
        draw_segment_d2(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
      }

      /// @brief Draw segment a1 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      virtual void draw_segment_a1(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size_.width() / 2 - 1 - abs(offset), 1 + thickness() / 2 + offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size_.width() / 2 - 1 - abs(offset / 2), 1 + offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset + thickness() / 2, 1 + thickness() / 2 + offset, size_.width() / 2 - 1 - abs(offset), 1 + thickness() / 2 + offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size_.width() / 2 + thickness() / 2 - 1 - (offset > thickness() / 2 ? offset : thickness() / 2), 1 + offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), 1 + offset, size_.width() / 2 + thickness() / 2 - 1 - (offset > thickness() / 2 ? offset : thickness() / 2), 1 + offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), 1 + offset, size_.width() / 2 - 1, 1 + offset);
        }
      }
      
      /// @brief Draw segment a2 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      virtual void draw_segment_a2(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 + abs(offset), 1 + thickness() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), 1 + thickness() / 2 + offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 + abs(offset / 2), 1 + offset, size_.width() - 3 - offset, 1 + offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 + abs(offset), 1 + thickness() / 2 + offset, size_.width() - 3 - thickness() / 2 - offset, 1 + thickness() / 2 + offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 - thickness() / 2 + (offset > thickness() / 2 ? offset : thickness() / 2), 1 + offset, size_.width() - 3 - offset, 1 + offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 - thickness() / 2 + (offset > thickness() / 2 ? offset : thickness() / 2), 1 + offset, size_.width() - 3 - thickness(), 1 + offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1, 1 + offset, size_.width() - 3 - thickness(), 1 + offset);
        }
      }
      
      /// @brief Draw segment d1 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      virtual void draw_segment_d1(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() - 2 - thickness() / 2 - offset, size_.width() / 2 - 1 - abs(offset), size_.height() - 2 - thickness() / 2 - offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, size_.height() - 2 - offset, size_.width() / 2 - 1 - abs(offset / 2), size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + offset, size_.height() - 2 - thickness() / 2 - offset, size_.width() / 2 - 1 - abs(offset), size_.height() - 2 - thickness() / 2 - offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, size_.height() - 2 - offset, size_.width() / 2 + thickness() / 2 - 1 - (offset > thickness() / 2 ? offset : thickness() / 2), size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), size_.height() - 2 - offset, size_.width() / 2 + thickness() / 2 - 1 - (offset > thickness() / 2 ? offset : thickness() / 2), size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), size_.height() - 2 - offset, size_.width() / 2 - 1, size_.height() - 2 - offset);
        }
      }
      
      /// @brief Draw segment d2 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      virtual void draw_segment_d2(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 + abs(offset), size_.height() - 2 - thickness() / 2 - offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() - 2 - thickness() / 2 - offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 + abs(offset / 2), size_.height() - 2 - offset, size_.width() - 3 - offset, size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 + abs(offset), size_.height() - 2 - thickness() / 2 - offset, size_.width() - 3 - thickness() / 2 - offset, size_.height() - 2 - thickness() / 2 - offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 - thickness() / 2 + (offset > thickness() / 2 ? offset : thickness() / 2), size_.height() - 2 - offset, size_.width() - 3 - offset, size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1 - thickness() / 2 + (offset > thickness() / 2 ? offset : thickness() / 2), size_.height() - 2 - offset, size_.width() - 3 - thickness(), size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 + 1, size_.height() - 2 - offset, size_.width() - 3 - thickness(), size_.height() - 2 - offset);
        }
      }
      
      /// @brief Draw segment i on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      void draw_segment_i(drawing::graphics& graphics, const drawing::color& color) override {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, 2 + thickness() / 2 + abs(offset), size_.width() / 2 - offset, size_.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, 2 + abs(2 * offset), size_.width() / 2 - offset, size_.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, 2 + thickness() / 2 + abs(offset), size_.width() / 2 - offset, size_.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, 2 + thickness() / 2 + abs(offset), size_.width() / 2 - offset, size_.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, 2 + thickness() / 2 + abs(offset), size_.width() / 2 - offset, size_.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, 2 + thickness(), size_.width() / 2 - offset, size_.height() / 2 - 1 - abs(offset));
        }
      }
  
      /// @brief Draw segment l on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segemnt.
      void draw_segment_l(drawing::graphics& graphics, const drawing::color& color) override {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size_.width() / 2 - offset, size_.height() - 3 - thickness() / 2 - abs(offset));
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size_.width() / 2 - offset, size_.height() - 3 - abs(2 * offset));
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size_.width() / 2 - offset, size_.height() - 3 - thickness() / 2 - abs(offset));
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size_.width() / 2 - offset, size_.height() - 3 - thickness() / 2 - abs(offset));
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size_.width() / 2 - offset, size_.height() - 3 - thickness() / 2 - abs(offset));
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size_.width() / 2 - offset, size_.height() - 3 - thickness());
        }
      }

    protected:
      void draw_segment_a(drawing::graphics& graphics, const drawing::color& color) override {}
      void draw_segment_d(drawing::graphics& graphics, const drawing::color& color) override {}
    };
  }
}

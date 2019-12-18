#pragma once
#include "control.hpp"
#include "segments.hpp"
#include "segment_style.hpp"

namespace xtd {
  namespace forms {
    /// @brief represent a seven segment display class
    class seven_segment_display : public control {
    public:
      seven_segment_display() {
        size_ = default_size();
      }
      
      virtual double background_digit_transparency() const {return background_digit_transparency_;}
      virtual seven_segment_display& background_digit_transparency(double value) {
        if (background_digit_transparency_ != value) {
          background_digit_transparency_ = value;
          invalidate();
        }
        return *this;
      }
      
      virtual bool show_background_digit() const {return show_background_digit_;}
      virtual seven_segment_display& show_background_digit(bool value) {
        if (show_background_digit_ != value) {
          show_background_digit_ = value;
          invalidate();
        }
        return *this;
      }
      
      virtual forms::segments value() const {return value_;}
      virtual seven_segment_display& value(forms::segments segments) {
        if (value_ != segments) {
          value_ = segments;
          invalidate();
        }
        return *this;
      }
      
      virtual forms::segment_style segment_style() const {return segment_style_;}
      virtual seven_segment_display& segment_style(forms::segment_style value) {
        if (segment_style_ != value) {
          segment_style_ = value;
          invalidate();
        }
        return *this;
      }

      virtual bool get_segments(forms::segments segment) const {return (value_ & segment) == segment;}
      virtual void set_segments(forms::segments segment, bool value) { value_ = value ? (value_ | segment) : (value_ & ~segment); }

    protected:
      drawing::size default_size() const override {return {13, 25};}
      

      void on_paint(paint_event_args& e) override {
        drawing::graphics graphics = e.graphics();
        drawing::size lcd_digit_size((height() - 3) / 2 + 2, height());
        int32_t thickness = lcd_digit_size.height() / 12;
        thickness -= thickness % 2 ? 0 : 1;
        if (show_background_digit_ && value_ != forms::segments::dp && value_ != forms::segments::pc) draw_background_digit(graphics, lcd_digit_size, thickness);
        if ((value_ & forms::segments::dp) == forms::segments::dp) draw_dp(graphics, fore_color(), lcd_digit_size, thickness);
        if ((value_ & forms::segments::pc) == forms::segments::pc) draw_pc(graphics, fore_color(), lcd_digit_size, thickness);
        if ((value_ & forms::segments::a) == forms::segments::a) draw_segment_a(graphics, fore_color(), lcd_digit_size, thickness);
        if ((value_ & forms::segments::b) == forms::segments::b) draw_segment_b(graphics, fore_color(), lcd_digit_size, thickness);
        if ((value_ & forms::segments::c) == forms::segments::c) draw_segment_c(graphics, fore_color(), lcd_digit_size, thickness);
        if ((value_ & forms::segments::d) == forms::segments::d) draw_segment_d(graphics, fore_color(), lcd_digit_size, thickness);
        if ((value_ & forms::segments::e) == forms::segments::e) draw_segment_e(graphics, fore_color(), lcd_digit_size, thickness);
        if ((value_ & forms::segments::f) == forms::segments::f) draw_segment_f(graphics, fore_color(), lcd_digit_size, thickness);
        if ((value_ & forms::segments::g) == forms::segments::g) draw_segment_g(graphics, fore_color(), lcd_digit_size, thickness);
      }
      
      drawing::size measure_control() const override {
        return drawing::size((height() - 3) / 2 + 2, height());
      }
    
      void set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) override {
        if ((specified & bounds_specified::width) == forms::bounds_specified::width && (specified & bounds_specified::height) != forms::bounds_specified::height) {
          height = (width - 2) * 2 + 3;
          specified |= bounds_specified::height;
        }
        if ((specified & bounds_specified::height) == forms::bounds_specified::height) {
          width = (height - 3) / 2 + 2;
          specified |= bounds_specified::width;
        }
        control::set_bounds_core(x, y, width, height, specified);
      }
            
      void set_client_size_core(int32_t width, int32_t height) override {
        if (client_size_.height() != height)
          width = (height - 3) / 2 + 2;
        if (client_size_.width() != width)
          height = (width - 2) * 2 + 3;
        control::set_client_size_core(width, height);
      }

      virtual void draw_background_digit(drawing::graphics& graphics, const drawing::size& size, int32_t thickness) {
        drawing::color background_digit_color;
        background_digit_color = drawing::color::average(fore_color(), back_color(), background_digit_transparency_);
        draw_segment_a(graphics, background_digit_color, size, thickness);
        draw_segment_b(graphics, background_digit_color, size, thickness);
        draw_segment_c(graphics, background_digit_color, size, thickness);
        draw_segment_d(graphics, background_digit_color, size, thickness);
        draw_segment_e(graphics, background_digit_color, size, thickness);
        draw_segment_f(graphics, background_digit_color, size, thickness);
        draw_segment_g(graphics, background_digit_color, size, thickness);
      }

      virtual void draw_segment_a(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness / 2 + abs(offset), 1 + thickness / 2 + offset, size.width() - 3 - thickness / 2 - abs(offset), 1 + thickness / 2 + offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size.width() - 3 - offset, 1 + offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size.width() - 3 - offset, 1 + offset);
        } else if (segment_style_ == segment_style::expand) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size.width() - 3 - offset, 1 + offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness, 1 + offset, size.width() - 3 - thickness, 1 + offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness, 1 + offset, size.width() - 3 - thickness, 1 + offset);
        }
      }
      
      virtual void draw_segment_b(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), size.width() - 2 - thickness / 2 - offset, 2 + thickness / 2 + abs(offset), size.width() - 2 - thickness / 2 - offset, size.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), size.width() - 2 - offset, 2 + offset, size.width() - 2 - offset, size.height() / 2 - 1 - offset / 2);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), size.width() - 2 - thickness / 2 - offset, 2 + offset + thickness / 2, size.width() - 2 - thickness / 2 - offset, size.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::expand) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), size.width() - 2 - thickness / 2 - offset, 2 + offset + thickness / 2, size.width() - 2 - thickness / 2 - offset, size.height() / 2 - 1 - (offset > 0 ? offset : 0));
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), size.width() - 2 - thickness / 2 - offset, 1, size.width() - 2 - thickness / 2 - offset, size.height() / 2 - 1 - (offset > 0 ? offset : 0));
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), size.width() - 2 - thickness / 2 - offset, 1, size.width() - 2 - thickness / 2 - offset, size.height() / 2 - 1);
        }
      }
      
      virtual void draw_segment_c(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), size.width() - 2 - thickness / 2 - offset, size.height() / 2 + 1 - thickness / 2 + thickness / 2 + abs(offset), size.width() - 2 - thickness / 2 - offset, size.height() - 3 - thickness / 2 - abs(offset));
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), size.width() - 2 - offset, size.height() / 2 + 1 + offset / 2,  size.width() - 2 - offset, size.height() - 3 - offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), size.width() - 2 - thickness / 2 - offset, size.height() / 2 + 1 - thickness / 2 + thickness / 2 + abs(offset), size.width() - 2 - thickness / 2 - offset, size.height() - 3 - thickness / 2 - offset);
        } else if (segment_style_ == segment_style::expand) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), size.width() - 2 - thickness / 2 - offset, size.height() / 2 + 1 - thickness / 2 + thickness / 2 + (offset > 0 ? offset : 0), size.width() - 2 - thickness / 2 - offset, size.height() - 3 - thickness / 2 - offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), size.width() - 2 - thickness / 2 - offset, size.height() / 2 + 1 - thickness / 2 + thickness / 2 + (offset > 0 ? offset : 0), size.width() - 2 - thickness / 2 - offset, size.height() - 2);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), size.width() - 2 - thickness / 2 - offset, size.height() / 2 + 1, size.width() - 2 - thickness / 2 - offset, size.height() - 2);
        }
      }
      
      virtual void draw_segment_d(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness / 2 + abs(offset), size.height() - 2 - thickness / 2 - offset, size.width() - 3 - thickness / 2 - abs(offset), size.height() - 2 - thickness / 2 - offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, size.height() - 2 - offset, size.width() - 3 - offset, size.height() - 2 - offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, size.height() - 2 - offset, size.width() - 3 - offset, size.height() - 2 - offset);
        } else if (segment_style_ == segment_style::expand) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, size.height() - 2 - offset, size.width() - 3 - offset, size.height() - 2 - offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness, size.height() - 2 - offset, size.width() - 3 - thickness, size.height() - 2 - offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness, size.height() - 2 - offset, size.width() - 3 - thickness, size.height() - 2 - offset);
        }
      }

      virtual void draw_segment_e(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness / 2 + offset, size.height() / 2 + 1 - thickness / 2 + thickness / 2 + abs(offset), 1 + thickness / 2 + offset, size.height() - 3 - thickness / 2 - abs(offset));
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), 1 + offset, size.height() / 2 + 1 + offset / 2, 1 + offset, size.height() - 3 - offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness / 2 + offset, size.height() / 2 + 1 - thickness / 2 + thickness / 2 + abs(offset), 1 + thickness / 2 + offset, size.height() - 3 - thickness / 2 - offset);
        } else if (segment_style_ == segment_style::expand) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness / 2 + offset, size.height() / 2 + 1 - thickness / 2 + thickness / 2 + (offset > 0 ? offset : 0), 1 + thickness / 2 + offset, size.height() - 3 - thickness / 2 - offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness / 2 + offset, size.height() / 2 + 1 - thickness / 2 + thickness / 2 + (offset > 0 ? offset : 0), 1 + thickness / 2 + offset, size.height() - 2);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness / 2 + offset, size.height() / 2 + 1, 1 + thickness / 2 + offset, size.height() - 2);
        }
      }

      virtual void draw_segment_f(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness / 2 + offset, 2 + thickness / 2 + abs(offset), 1 + thickness / 2 + offset, size.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), 1 + offset, 2 + offset, 1 + offset, size.height() / 2 - 1 - offset / 2);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness / 2 + offset, 2 + thickness / 2 + offset, 1 + thickness / 2 + offset, size.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::expand) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness / 2 + offset, 2 + thickness / 2 + offset, 1 + thickness / 2 + offset, size.height() / 2 - 1 - (offset > 0 ? offset : 0));
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness / 2 + offset, 1, 1 + thickness / 2 + offset, size.height() / 2 - 1 - (offset > 0 ? offset : 0));
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness / 2 + offset, 1, 1 + thickness / 2 + offset, size.height() / 2 - 1);
        }
      }

      virtual void draw_segment_g(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness / 2 + abs(offset), size.height() / 2 + offset, size.width() - 3 - thickness / 2 - abs(offset), size.height() / 2 + offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + abs(2 * offset), size.height() / 2 + offset, size.width() - 3 - abs(2 * offset), size.height() / 2 + offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness / 2 + abs(offset), size.height() / 2 + offset, size.width() - 3 - thickness / 2 - abs(offset), size.height() / 2 + offset);
        } else if (segment_style_ == segment_style::expand) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness / 2 + abs(offset), size.height() / 2 + offset, size.width() - 3 - thickness / 2 - abs(offset), size.height() / 2 + offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness / 2 + abs(offset), size.height() / 2 + offset, size.width() - 3 - thickness / 2 - abs(offset), size.height() / 2 + offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness, size.height() / 2 + offset, size.width() - 3 - thickness, size.height() / 2 + offset);
        }
      }

      virtual void draw_dp(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
        if (segment_style_ == segment_style::standard) {
          graphics.fill_ellipse(drawing::solid_brush(color), size.width() / 2 - thickness / 2, size.height() - 1 - thickness, thickness, thickness);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), size.width() / 2 - thickness / 2, size.height() - 2 - offset, size.width() / 2 + thickness / 2, size.height() - 2 - offset);
        } else if (segment_style_ == segment_style::mixed) {
          graphics.fill_ellipse(drawing::solid_brush(color), size.width() / 2 - thickness / 2, size.height() - 1 - thickness, thickness, thickness);
        } else if (segment_style_ == segment_style::expand) {
          graphics.fill_ellipse(drawing::solid_brush(color), size.width() / 2 - thickness / 2, size.height() - 1 - thickness, thickness, thickness);
        } else if (segment_style_ == segment_style::design) {
          graphics.fill_ellipse(drawing::solid_brush(color), size.width() / 2 - thickness / 2, size.height() - 1 - thickness, thickness, thickness);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), size.width() / 2 - thickness / 2, size.height() - 2 - offset, size.width() / 2 + thickness / 2, size.height() - 2 - offset);
        }
      }
      
      virtual void draw_pc(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
        if (segment_style_ == segment_style::standard) {
          graphics.fill_ellipse(drawing::solid_brush(color), size.width() / 2 - thickness / 2, size.height() / 3 - thickness / 2, thickness, thickness);
          graphics.fill_ellipse(drawing::solid_brush(color), size.width() / 2 - thickness / 2, size.height() / 3 * 2 - thickness / 2, thickness, thickness);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness; offset++) {
            graphics.draw_line(drawing::pen(color), size.width() / 2 - thickness / 2, size.height() / 3 - thickness / 2 + offset, size.width() / 2 + thickness / 2, size.height() / 3 - thickness / 2 + offset);
            graphics.draw_line(drawing::pen(color), size.width() / 2 - thickness / 2, size.height() /3 * 2 - thickness / 2 + offset, size.width() / 2 + thickness / 2, size.height() / 3 * 2 - thickness / 2 + offset);
          }
        } else if (segment_style_ == segment_style::mixed) {
          graphics.fill_ellipse(drawing::solid_brush(color), size.width() / 2 - thickness / 2, size.height() / 3 - thickness / 2, thickness, thickness);
          graphics.fill_ellipse(drawing::solid_brush(color), size.width() / 2 - thickness / 2, size.height() / 3 * 2 - thickness / 2, thickness, thickness);
        } else if (segment_style_ == segment_style::expand) {
          graphics.fill_ellipse(drawing::solid_brush(color), size.width() / 2 - thickness / 2, size.height() / 3 - thickness / 2, thickness, thickness);
          graphics.fill_ellipse(drawing::solid_brush(color), size.width() / 2 - thickness / 2, size.height() / 3 * 2 - thickness / 2, thickness, thickness);
        } else if (segment_style_ == segment_style::design) {
          graphics.fill_ellipse(drawing::solid_brush(color), size.width() / 2 - thickness / 2, size.height() / 3 - thickness / 2, thickness, thickness);
          graphics.fill_ellipse(drawing::solid_brush(color), size.width() / 2 - thickness / 2, size.height() / 3 * 2 - thickness / 2, thickness, thickness);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness; offset++) {
            graphics.draw_line(drawing::pen(color), size.width() / 2 - thickness / 2, size.height() / 3 - thickness / 2 + offset, size.width() / 2 + thickness / 2, size.height() / 3 - thickness / 2 + offset);
            graphics.draw_line(drawing::pen(color), size.width() / 2 - thickness / 2, size.height() /3 * 2 - thickness / 2 + offset, size.width() / 2 + thickness / 2, size.height() / 3 * 2 - thickness / 2 + offset);
          }
        }
      }

      /// @cond
      forms::segments value_ = forms::segments::none;
      bool show_background_digit_ = true;
      double background_digit_transparency_ = 0.1;
      forms::segment_style segment_style_ = forms::segment_style::standard;
      /// @endcond
    };
  }
}

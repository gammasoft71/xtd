/// @file
/// @brief Contains xtd::forms::seven_segment_display control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "segments.h"
#include "segment_style.h"

namespace xtd {
  namespace forms {
    /// @brief represent a seven segment display class
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Example
    /// The following code example demonstrate the use of seven segment display control.
    /// @include seven_segment_display.cpp
    /// @par Windows
    /// @image html seven_segment_display_w.png
    /// <br>
    /// @image html seven_segment_display_wd.png
    /// @par macOS
    /// @image html seven_segment_display_m.png
    /// <br>
    /// @image html seven_segment_display_md.png
    /// @par Gnome
    /// @image html seven_segment_display_g.png
    /// <br>
    /// @image html seven_segment_display_gd.png
    class seven_segment_display : public control {
    public:
      /// @brief Initialize a new instance of seven_segment_display class.
      seven_segment_display() {
        double_buffered(true);
        size_ = default_size();
      }

      virtual drawing::color back_segment_color() {return back_segment_color_.value_or(fore_color());}
      virtual seven_segment_display& back_segment_color(const drawing::color& value) {
        if (!back_segment_color_.has_value() || back_segment_color_.value() != value) {
          back_segment_color_ = value;
          invalidate();
        }
        return *this;
      }

      virtual double back_segment_transparency() const {return back_segment_transparency_;}
      virtual seven_segment_display& back_segment_transparency(double value) {
        if (back_segment_transparency_ != value) {
          back_segment_transparency_ = value;
          invalidate();
        }
        return *this;
      }
      
      virtual bool show_back_segment() const {return show_back_segment_;}
      virtual seven_segment_display& show_back_segment(bool value) {
        if (show_back_segment_ != value) {
          show_back_segment_ = value;
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
      
      virtual int32_t thickness() const {return thickness_.value_or(size_.height() < 10 ? 1 : (size_.height() / 10 + ((size_.height() / 10) % 2 ? 0 : 1)));}
      virtual seven_segment_display& thickness(int32_t value) {
        if (!thickness_.has_value() || thickness_.value() != value) {
          thickness_ = value;
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
        graphics.clear(back_color());
        if (show_back_segment_) draw_back_digit(graphics);
        if ((value_ & forms::segments::dp) == forms::segments::dp) draw_dp(graphics, fore_color());
        if ((value_ & forms::segments::pc) == forms::segments::pc) draw_pc(graphics, fore_color());
        if ((value_ & forms::segments::a) == forms::segments::a) draw_segment_a(graphics, fore_color());
        if ((value_ & forms::segments::b) == forms::segments::b) draw_segment_b(graphics, fore_color());
        if ((value_ & forms::segments::c) == forms::segments::c) draw_segment_c(graphics, fore_color());
        if ((value_ & forms::segments::d) == forms::segments::d) draw_segment_d(graphics, fore_color());
        if ((value_ & forms::segments::e) == forms::segments::e) draw_segment_e(graphics, fore_color());
        if ((value_ & forms::segments::f) == forms::segments::f) draw_segment_f(graphics, fore_color());
        if ((value_ & forms::segments::g) == forms::segments::g) draw_segment_g(graphics, fore_color());
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

      virtual void draw_back_digit(drawing::graphics& graphics) {
        draw_segment_a(graphics, drawing::color::average(back_color(), back_segment_color(), back_segment_transparency()));
        draw_segment_b(graphics, drawing::color::average(back_color(), back_segment_color(), back_segment_transparency()));
        draw_segment_c(graphics, drawing::color::average(back_color(), back_segment_color(), back_segment_transparency()));
        draw_segment_d(graphics, drawing::color::average(back_color(), back_segment_color(), back_segment_transparency()));
        draw_segment_e(graphics, drawing::color::average(back_color(), back_segment_color(), back_segment_transparency()));
        draw_segment_f(graphics, drawing::color::average(back_color(), back_segment_color(), back_segment_transparency()));
        draw_segment_g(graphics, drawing::color::average(back_color(), back_segment_color(), back_segment_transparency()));
      }

      virtual void draw_segment_a(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), 1 + thickness() / 2 + offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size_.width() - 3 - offset, 1 + offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size_.width() - 3 - offset, 1 + offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size_.width() - 3 - offset, 1 + offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), 1 + offset, size_.width() - 3 - thickness(), 1 + offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), 1 + offset, size_.width() - 3 - thickness(), 1 + offset);
        }
      }
      
      virtual void draw_segment_b(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, 2 + thickness() / 2 + abs(offset), size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - offset, 2 + offset, size_.width() - 2 - offset, size_.height() / 2 - 1 - offset / 2);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, 2 + offset + thickness() / 2, size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, 2 + offset + thickness() / 2, size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 - 1 - (offset > 0 ? offset : 0));
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, 1, size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 - 1 - (offset > 0 ? offset : 0));
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, 1, size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 - 1);
        }
      }
      
      virtual void draw_segment_c(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size_.width() - 2 - thickness() / 2 - offset, size_.height() - 3 - thickness() / 2 - abs(offset));
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - offset, size_.height() / 2 + 1 + offset / 2,  size_.width() - 2 - offset, size_.height() - 3 - offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size_.width() - 2 - thickness() / 2 - offset, size_.height() - 3 - thickness() / 2 - offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + (offset > 0 ? offset : 0), size_.width() - 2 - thickness() / 2 - offset, size_.height() - 3 - thickness() / 2 - offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + (offset > 0 ? offset : 0), size_.width() - 2 - thickness() / 2 - offset, size_.height() - 2);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), size_.width() - 2 - thickness() / 2 - offset, size_.height() / 2 + 1, size_.width() - 2 - thickness() / 2 - offset, size_.height() - 2);
        }
      }
      
      virtual void draw_segment_d(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() - 2 - thickness() / 2 - offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() - 2 - thickness() / 2 - offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, size_.height() - 2 - offset, size_.width() - 3 - offset, size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, size_.height() - 2 - offset, size_.width() - 3 - offset, size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + offset, size_.height() - 2 - offset, size_.width() - 3 - offset, size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), size_.height() - 2 - offset, size_.width() - 3 - thickness(), size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), size_.height() - 2 - offset, size_.width() - 3 - thickness(), size_.height() - 2 - offset);
        }
      }

      virtual void draw_segment_e(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size_.height() - 3 - thickness() / 2 - abs(offset));
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 1 + offset, size_.height() / 2 + 1 + offset / 2, 1 + offset, size_.height() - 3 - offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size_.height() - 3 - thickness() / 2 - offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + (offset > 0 ? offset : 0), 1 + thickness() / 2 + offset, size_.height() - 3 - thickness() / 2 - offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size_.height() / 2 + 1 - thickness() / 2 + thickness() / 2 + (offset > 0 ? offset : 0), 1 + thickness() / 2 + offset, size_.height() - 2);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size_.height() / 2 + 1, 1 + thickness() / 2 + offset, size_.height() - 2);
        }
      }

      virtual void draw_segment_f(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size_.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), 1 + offset, 2 + offset, 1 + offset, size_.height() / 2 - 1 - offset / 2);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 2 + thickness() / 2 + offset, 1 + thickness() / 2 + offset, size_.height() / 2 - 1 - abs(offset));
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 2 + thickness() / 2 + offset, 1 + thickness() / 2 + offset, size_.height() / 2 - 1 - (offset > 0 ? offset : 0));
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 1, 1 + thickness() / 2 + offset, size_.height() / 2 - 1 - (offset > 0 ? offset : 0));
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 1, 1 + thickness() / 2 + offset, size_.height() / 2 - 1);
        }
      }

      virtual void draw_segment_g(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + abs(2 * offset), size_.height() / 2 + offset, size_.width() - 3 - abs(2 * offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::mixed) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::expanded) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::design) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size_.height() / 2 + offset, size_.width() - 3 - thickness() / 2 - abs(offset), size_.height() / 2 + offset);
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
            graphics.draw_line(drawing::pen(color), 2 + thickness(), size_.height() / 2 + offset, size_.width() - 3 - thickness(), size_.height() / 2 + offset);
        }
      }

      virtual void draw_dp(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() - 1 - thickness(), thickness(), thickness());
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - thickness() / 2, size_.height() - 2 - offset, size_.width() / 2 + thickness() / 2, size_.height() - 2 - offset);
        } else if (segment_style_ == segment_style::mixed) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() - 1 - thickness(), thickness(), thickness());
        } else if (segment_style_ == segment_style::expanded) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() - 1 - thickness(), thickness(), thickness());
        } else if (segment_style_ == segment_style::design) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() - 1 - thickness(), thickness(), thickness());
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++)
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - thickness() / 2, size_.height() - 2 - offset, size_.width() / 2 + thickness() / 2, size_.height() - 2 - offset);
        }
      }
      
      virtual void draw_pc(drawing::graphics& graphics, const drawing::color& color) {
        if (segment_style_ == segment_style::standard) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 - thickness() / 2, thickness(), thickness());
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 * 2 - thickness() / 2, thickness(), thickness());
        } else if (segment_style_ == segment_style::modern) {
          for (int32_t offset = 0; offset < thickness(); offset++) {
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 - thickness() / 2 + offset, size_.width() / 2 + thickness() / 2, size_.height() / 3 - thickness() / 2 + offset);
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - thickness() / 2, size_.height() /3 * 2 - thickness() / 2 + offset, size_.width() / 2 + thickness() / 2, size_.height() / 3 * 2 - thickness() / 2 + offset);
          }
        } else if (segment_style_ == segment_style::mixed) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 - thickness() / 2, thickness(), thickness());
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 * 2 - thickness() / 2, thickness(), thickness());
        } else if (segment_style_ == segment_style::expanded) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 - thickness() / 2, thickness(), thickness());
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 * 2 - thickness() / 2, thickness(), thickness());
        } else if (segment_style_ == segment_style::design) {
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 - thickness() / 2, thickness(), thickness());
          graphics.fill_ellipse(drawing::solid_brush(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 * 2 - thickness() / 2, thickness(), thickness());
        } else if (segment_style_ == segment_style::stick) {
          for (int32_t offset = 0; offset < thickness(); offset++) {
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - thickness() / 2, size_.height() / 3 - thickness() / 2 + offset, size_.width() / 2 + thickness() / 2, size_.height() / 3 - thickness() / 2 + offset);
            graphics.draw_line(drawing::pen(color), size_.width() / 2 - thickness() / 2, size_.height() /3 * 2 - thickness() / 2 + offset, size_.width() / 2 + thickness() / 2, size_.height() / 3 * 2 - thickness() / 2 + offset);
          }
        }
      }

      /// @cond
      forms::segments value_ = forms::segments::none;
      bool show_back_segment_ = true;
      std::optional<drawing::color> back_segment_color_;
      double back_segment_transparency_ = 0.05;
      forms::segment_style segment_style_ = forms::segment_style::standard;
      std::optional<int32_t> thickness_;
      /// @endcond
    };
  }
}

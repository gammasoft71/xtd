#include "control.hpp"
#include "lcd_style.hpp"

namespace xtd {
  namespace forms {
    class lcd_label : public control {
      class digit : public control {
      public:
        digit() {
          size_ = default_size();
        }
        
        uint8_t background_digit_transparency() const {return background_digit_transparency_;}
        digit& background_digit_transparency(uint8_t value) {
          if (background_digit_transparency_ != value) {
            background_digit_transparency_ = value;
            invalidate();
          }
          return *this;
        }
        
        bool show_background_digit() const {return show_background_digit_;}
        digit& show_background_digit(bool value) {
          if (show_background_digit_ != value) {
            show_background_digit_ = value;
            invalidate();
          }
          return *this;
        }

        char character() const {return character_;}
        digit& character(char value) {
          static ustring valid_characters = " -.,:0123456789aAbBcCdDeEfFgGhHijJIlLoOpPqQrRtTuUyY";
          if (character_ != value) {
            if (strings::index_of(valid_characters, character_) == -1) throw std::invalid_argument(strings::format("Only characters : \"{}\" are valid", valid_characters));
            character_ = value;
            on_layout(event_args::empty);
            invalidate();
          }
          return *this;
        }
        
        using control::height;
        control& height(int value) override {
          if (size_.height() != value) {
            control::size({(value - 3) / 2 + 2, value});
          }
          return *this;
        }
        
        lcd_style style() const {return style_;}
        digit& style(lcd_style value) {
          if (style_ != value) {
            style_ = value;
            invalidate();
          }
          return *this;
        }

      protected:
        drawing::size default_size() const override {return {13, 25};}

        void on_paint(paint_event_args& e) override {
          //e.graphics().clear(back_color());
          drawing::size lcd_digit_size((height() - 3) / 2 + 2, height());
          int32_t thickness = lcd_digit_size.height() / 8;
          thickness -= thickness % 2 ? 0 : 1;
          if (show_background_digit_ && character_ != '.' && character_ != ':') draw_background_digit(e, lcd_digit_size, thickness);
          switch(character_) {
            case ' ' : draw_space(e, lcd_digit_size, thickness); break;
            case '-' : draw_minus(e, lcd_digit_size, thickness); break;
            case '.' : case ',': draw_point(e, lcd_digit_size, thickness); break;
            case ':' : draw_colon(e, lcd_digit_size, thickness); break;
            case '0' : draw_zero(e, lcd_digit_size, thickness); break;
            case '1' : draw_one(e, lcd_digit_size, thickness); break;
            case '2' : draw_two(e, lcd_digit_size, thickness); break;
            case '3' : draw_three(e, lcd_digit_size, thickness); break;
            case '4' : draw_four(e, lcd_digit_size, thickness); break;
            case '5' : draw_five(e, lcd_digit_size, thickness); break;
            case '6' : draw_six(e, lcd_digit_size, thickness); break;
            case '7' : draw_seven(e, lcd_digit_size, thickness); break;
            case '8' : draw_eight(e, lcd_digit_size, thickness); break;
            case '9' : draw_nine(e, lcd_digit_size, thickness); break;
            case 'a' : case 'A' : draw_shift_a(e, lcd_digit_size, thickness); break;
            case 'b' : case 'B' : draw_b(e, lcd_digit_size, thickness); break;
            case 'c' : draw_c(e, lcd_digit_size, thickness); break;
            case 'C' : draw_shift_c(e, lcd_digit_size, thickness); break;
            case 'd' : case 'D' : draw_d(e, lcd_digit_size, thickness); break;
            case 'e' : draw_e(e, lcd_digit_size, thickness); break;
            case 'E' : draw_shift_e(e, lcd_digit_size, thickness); break;
            case 'f' : case 'F' : draw_shift_f(e, lcd_digit_size, thickness); break;
            case 'g' : case 'G' : draw_shift_g(e, lcd_digit_size, thickness); break;
            case 'h' : draw_h(e, lcd_digit_size, thickness); break;
            case 'H' : draw_shift_h(e, lcd_digit_size, thickness); break;
            case 'i' : case 'I' : draw_i(e, lcd_digit_size, thickness); break;
            case 'j' : case 'J' : draw_shift_j(e, lcd_digit_size, thickness); break;
            case 'l' : case 'L' : draw_shift_l(e, lcd_digit_size, thickness); break;
            case 'o' : case 'O' : draw_o(e, lcd_digit_size, thickness); break;
            case 'p' : case 'P' : draw_shift_p(e, lcd_digit_size, thickness); break;
            case 'q' : case 'Q' : draw_q(e, lcd_digit_size, thickness); break;
            case 'r' : case 'R' : draw_r(e, lcd_digit_size, thickness); break;
            case 't' : case 'T' : draw_t(e, lcd_digit_size, thickness); break;
            case 'u' : draw_u(e, lcd_digit_size, thickness); break;
            case 'U' : draw_shift_u(e, lcd_digit_size, thickness); break;
            case 'y' : case 'Y' : draw_shift_y(e, lcd_digit_size, thickness); break;
            default: break;
          }
        }
        
        drawing::size measure_control() const override {
          return drawing::size((height() - 3) / 2 + 2, height());
        }
        
      private:
        //using control::size;
        //using control::client_size;
        void draw_background_digit(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          drawing::color background_digit_color;
          if (environment::os_version().is_osx_platform())
            background_digit_color = drawing::color::from_argb(background_digit_transparency_, fore_color());
          else
            background_digit_color = drawing::color::average(fore_color(), back_color(), (double)background_digit_transparency_ / 255);
          draw_segment_top(graphics, background_digit_color, size, thickness);
          draw_segment_left_top(graphics, background_digit_color, size, thickness);
          draw_segment_right_top(graphics, background_digit_color, size, thickness);
          draw_segment_middle(graphics, background_digit_color, size, thickness);
          draw_segment_left_bottom(graphics, background_digit_color, size, thickness);
          draw_segment_right_bottom(graphics, background_digit_color, size, thickness);
          draw_segment_bottom(graphics, background_digit_color, size, thickness);
        }
        
        void draw_space(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
        }
        
        void draw_minus(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_middle(graphics, fore_color(), size, thickness);
        }
        
        void draw_point(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          if (style_ == lcd_style::standard) {
            for (int32_t offset = 0; offset < thickness; offset++)
              graphics.draw_line(drawing::pen(fore_color()), size.width() / 2 - thickness / 2, size.height() - 2 - offset, size.width() / 2 + thickness / 2, size.height() - 2 - offset);
          } else if (style_ == lcd_style::seven_segments) {
            graphics.fill_ellipse(drawing::solid_brush(fore_color()), size.width() / 2 - thickness / 2, size.height() - 1 - thickness, thickness, thickness);
          }
        }
        
        void draw_colon(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          if (style_ == lcd_style::standard) {
            for (int32_t offset = 0; offset < thickness; offset++) {
              graphics.draw_line(drawing::pen(fore_color()), size.width() / 2 - thickness / 2, size.height() / 3 - thickness / 2 + offset, size.width() / 2 + thickness / 2, size.height() / 3 - thickness / 2 + offset);
              graphics.draw_line(drawing::pen(fore_color()), size.width() / 2 - thickness / 2, size.height() /3 * 2 - thickness / 2 + offset, size.width() / 2 + thickness / 2, size.height() / 3 * 2 - thickness / 2 + offset);
            }
          } else if (style_ == lcd_style::seven_segments) {
            graphics.fill_ellipse(drawing::solid_brush(fore_color()), size.width() / 2 - thickness / 2, size.height() / 3 - thickness / 2, thickness, thickness);
            graphics.fill_ellipse(drawing::solid_brush(fore_color()), size.width() / 2 - thickness / 2, size.height() / 3 * 2 - thickness / 2, thickness, thickness);
          }
        }
        
        void draw_zero(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_one(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_two(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_three(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_four(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_five(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_six(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_seven(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_eight(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_nine(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_shift_a(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_b(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_c(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_shift_c(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_d(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_e(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_shift_e(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_shift_f(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_shift_g(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_h(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_shift_h(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_i(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_shift_j(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_shift_l(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_o(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_shift_p(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_q(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_r(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_shift_s(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_top(graphics, fore_color(), size, thickness);
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_t(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_u(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_shift_u(paint_event_args& e, const drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_left_bottom(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_shift_y(paint_event_args& e, drawing::size& size, int32_t thickness) {
          drawing::graphics graphics = e.graphics();
          draw_segment_left_top(graphics, fore_color(), size, thickness);
          draw_segment_right_top(graphics, fore_color(), size, thickness);
          draw_segment_middle(graphics, fore_color(), size, thickness);
          draw_segment_right_bottom(graphics, fore_color(), size, thickness);
          draw_segment_bottom(graphics, fore_color(), size, thickness);
        }
        
        void draw_segment_top(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
          if (style_ == lcd_style::standard) {
            for (int32_t offset = 0; offset < thickness; offset++)
              graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size.width() - 3 - offset, 1 + offset);
          } else if (style_ == lcd_style::seven_segments) {
            for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
              graphics.draw_line(drawing::pen(color), 2 + thickness / 2 + abs(offset), 1 + thickness / 2 + offset, size.width() - 3 - thickness / 2 - abs(offset), 1 + thickness / 2 + offset);
          }
        }
        
        void draw_segment_left_top(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
          if (style_ == lcd_style::standard) {
            for (int32_t offset = 0; offset < thickness; offset++)
              graphics.draw_line(drawing::pen(color), 1 + offset, 2 + offset, 1 + offset, size.height() / 2 - 1 - offset);
          } else if (style_ == lcd_style::seven_segments) {
            for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
              graphics.draw_line(drawing::pen(color), 1 + thickness / 2 + offset, 2 + thickness / 2 + abs(offset), 1 + thickness / 2 + offset, size.height() / 2 - 1 - abs(offset));
          }
        }
        
        void draw_segment_right_top(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
          if (style_ == lcd_style::standard) {
            for (int32_t offset = 0; offset < thickness; offset++)
              graphics.draw_line(drawing::pen(color), size.width() - 2 - offset, 2 + offset, size.width() - 2 - offset, size.height() / 2 - 1 - offset);
          } else if (style_ == lcd_style::seven_segments) {
            for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
              graphics.draw_line(drawing::pen(color), size.width() - 2 - thickness / 2 - offset, 2 + thickness / 2 + abs(offset), size.width() - 2 - thickness / 2 - offset, size.height() / 2 - 1 - abs(offset));
          }
        }
        
        void draw_segment_middle(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
          if (style_ == lcd_style::standard) {
            for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
              graphics.draw_line(drawing::pen(color), 2 + abs(offset), size.height() / 2 + offset, size.width() - 3 - abs(offset), size.height() / 2 + offset);
          } else if (style_ == lcd_style::seven_segments) {
            for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
              graphics.draw_line(drawing::pen(color), 2 + thickness / 2 + abs(offset), size.height() / 2 + offset, size.width() - 3 - thickness / 2 - abs(offset), size.height() / 2 + offset);
          }
        }
        
        void draw_segment_left_bottom(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
          if (style_ == lcd_style::standard) {
            for (int32_t offset = 0; offset < thickness; offset++)
              graphics.draw_line(drawing::pen(color), 1 + offset, size.height() / 2 + 1 + offset, 1 + offset, size.height() - 3 - offset);
          } else if (style_ == lcd_style::seven_segments) {
            for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
              graphics.draw_line(drawing::pen(color), 1 + thickness / 2 + offset, size.height() / 2 + 1 - thickness / 2 + thickness / 2 + abs(offset), 1 + thickness / 2 + offset, size.height() - 3 - thickness / 2 - abs(offset));
          }
        }
        
        void draw_segment_right_bottom(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
          if (style_ == lcd_style::standard) {
            for (int32_t offset = 0; offset < thickness; offset++)
              graphics.draw_line(drawing::pen(color), size.width() - 2 - offset, size.height() / 2 + 1 + offset,  size.width() - 2 - offset, size.height() - 3 - offset);
          } else if (style_ == lcd_style::seven_segments) {
            for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
              graphics.draw_line(drawing::pen(color), size.width() - 2 - thickness / 2 - offset, size.height() / 2 + 1 - thickness / 2 + thickness / 2 + abs(offset), size.width() - 2 - thickness / 2 - offset, size.height() - 3 - thickness / 2 - abs(offset));
          }
        }
        
        void draw_segment_bottom(drawing::graphics& graphics, const drawing::color& color, const drawing::size& size, int32_t thickness) {
          if (style_ == lcd_style::standard) {
            for (int32_t offset = 0; offset < thickness; offset++)
              graphics.draw_line(drawing::pen(color), 2 + offset, size.height() - 2 - offset, size.width() - 3 - offset, size.height() - 2 - offset);
          } else if (style_ == lcd_style::seven_segments) {
            for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
              graphics.draw_line(drawing::pen(color), 2 + thickness / 2 + abs(offset), size.height() - 2 - thickness / 2 - offset, size.width() - 3 - thickness / 2 - abs(offset), size.height() - 2 - thickness / 2 - offset);
          }
        }

      private:
        char character_ = ' ';
        bool show_background_digit_ = true;
        uint8_t background_digit_transparency_ = 32;
        lcd_style style_ = lcd_style::standard;
      };

    public:
      lcd_label() {
        auto_size_mode_ = forms::auto_size_mode::grow_and_shrink;
        size_ = default_size();
      }
      
      uint8_t background_digit_transparency() const {return background_digit_transparency_;}
      lcd_label& background_digit_transparency(uint8_t value) {
        if (background_digit_transparency_ != value) {
          background_digit_transparency_ = value;
          set_digits_params();
        }
        return *this;
      }
      
      bool show_background_digit() const {return show_background_digit_;}
      lcd_label& show_background_digit(bool value) {
        if (show_background_digit_ != value) {
          show_background_digit_ = value;
          set_digits_params();
        }
        return *this;
      }

      uint32_t digit_spacing() const {return digit_spacing_;}
      lcd_label& digit_spacing(uint32_t value) {
        if (digit_spacing_ != value) {
          digit_spacing_ = value;
          set_digits_params();
        }
        return *this;
      }
      
      lcd_style style() const {return style_;}
      lcd_label& style(lcd_style value) {
        if (style_ != value) {
          style_ = value;
          for (auto& digit : digits_)
            digit->style(value);
        }
        return *this;
      }
      
      using control::text;
      control& text(const ustring& value) override {
        if (text_ != value) {
          if (value.size() < digits_.size())
            digits_.erase(digits_.begin() + value.size(), digits_.end());
          if (value.size() > digits_.size())
            for (size_t index = digits_.size(); index < value.size(); index++)
              digits_.push_back(control::create<digit>(*this));
          for (size_t index = 0; index < value.size(); index++)
            digits_[index]->character(value[index]);
          set_digits_params();
          control::text(value);
        }
        return *this;
      }
      
    protected:
      drawing::size default_size() const override {return {100, 25};}

      void set_digits_params() {
        int32_t offset_left = 0;
        for (auto& digit : digits_) {
          digit->background_digit_transparency(background_digit_transparency_);
          digit->show_background_digit(show_background_digit_);
          digit->style(style_);
          digit->height(size_.height());
          digit->left(offset_left);
          offset_left += digit->width() - 2 + digit_spacing_;
        }
      }
      
      void on_handle_created(const event_args& e) override {
        control::on_handle_created(e);
        set_digits_params();
      }
      
      void on_size_changed(const event_args& e) override {
        set_digits_params();
        control::on_size_changed(e);
      }
      
      void on_resize(const event_args& e) override {
        set_digits_params();
        control::on_resize(e);
      }

      drawing::size measure_control() const override {
        if (digits_.size() == 0) return {0, size_.height()};
        return drawing::size((digits_[0]->width() - 2 + digit_spacing_) * digits_.size() - digit_spacing_ + 2, size_.height());
      }

    private:
      bool show_background_digit_ = true;
      uint8_t background_digit_transparency_ = 32;
      uint32_t digit_spacing_ = 4;
      lcd_style style_ = lcd_style::standard;
      std::vector<std::shared_ptr<digit>> digits_;
    };
  }
}

#include "control.hpp"
#include "lcd_style.hpp"

namespace xtd {
  namespace forms {
    class lcd_label : public control {
    public:
      lcd_label() {
        size_ = default_size();
      }
      
      uint8_t background_digit_transparency() const {return background_digit_transparency_;}
      lcd_label& background_digit_transparency(uint8_t value) {
        if (background_digit_transparency_ != value) {
          background_digit_transparency_ = value;
          invalidate();
        }
        return *this;
      }
      
      bool show_background_digit() const {return show_background_digit_;}
      lcd_label& show_background_digit(bool value) {
        if (show_background_digit_ != value) {
          show_background_digit_ = value;
          invalidate();
        }
        return *this;
      }
      uint32_t digit_spacing() const {return digit_spacing_;}
      lcd_label& digit_spacing(uint32_t value) {
        if (digit_spacing_ != value) {
          digit_spacing_ = value;
          invalidate();
        }
        return *this;
      }
      
      lcd_style style() const {return style_;}
      lcd_label& style(lcd_style value) {
        if (style_ != value) {
          style_ = value;
          invalidate();
        }
        return *this;
      }
      
      using control::text;
      control& text(const ustring& value) override {
        static ustring valid_characters = " -.:0123456789aAbBcCdDeEfFgGhHijJIlLoOpPqQrRtTuUyY";
        static ustring previous_text;
        if (text_ != value) {
          //control::text(value);
          text_ = value;
          this->on_text_changed(event_args::empty);
          for (int index = 0; index < text_.size(); index++) {
            if (strings::index_of(valid_characters, text_[index]) == -1) throw std::invalid_argument(strings::format("Only characters : \"{}\" are valid", valid_characters));
            if (previous_text.size() <= index || previous_text[index] != text_[index]) {
              invalidate(drawing::rectangle(((height() - 3) / 2 + digit_spacing_) * index, 0, ((height() - 3) / 2 + digit_spacing_) * (index + 1), height()));
            }
          }
          previous_text = text_;
        }
        return *this;
      }
      
    protected:
      drawing::size default_size() const override {return {100, 25};}
      void on_paint(paint_event_args& e) override {
        drawing::point offset_location;
        drawing::size lcd_digit_size((height() - 3) / 2 + 2, height());
        int32_t thickness = lcd_digit_size.height() / 8;
        thickness -= thickness % 2 ? 0 : 1;
        for(char value: text()) {
          if (show_background_digit_ && value != '.' && value != ':') draw_background_digit(e, offset_location, lcd_digit_size, thickness);
          switch(value) {
            case ' ' : draw_space(e, offset_location, lcd_digit_size, thickness); break;
            case '-' : draw_minus(e, offset_location, lcd_digit_size, thickness); break;
            case '.' : draw_point(e, offset_location, lcd_digit_size, thickness); break;
            case ':' : draw_colon(e, offset_location, lcd_digit_size, thickness); break;
            case '0' : draw_zero(e, offset_location, lcd_digit_size, thickness); break;
            case '1' : draw_one(e, offset_location, lcd_digit_size, thickness); break;
            case '2' : draw_two(e, offset_location, lcd_digit_size, thickness); break;
            case '3' : draw_three(e, offset_location, lcd_digit_size, thickness); break;
            case '4' : draw_four(e, offset_location, lcd_digit_size, thickness); break;
            case '5' : draw_five(e, offset_location, lcd_digit_size, thickness); break;
            case '6' : draw_six(e, offset_location, lcd_digit_size, thickness); break;
            case '7' : draw_seven(e, offset_location, lcd_digit_size, thickness); break;
            case '8' : draw_eight(e, offset_location, lcd_digit_size, thickness); break;
            case '9' : draw_nine(e, offset_location, lcd_digit_size, thickness); break;
            case 'a' :
            case 'A' : draw_shift_a(e, offset_location, lcd_digit_size, thickness); break;
            case 'b' :
            case 'B' : draw_b(e, offset_location, lcd_digit_size, thickness); break;
            case 'c' : draw_c(e, offset_location, lcd_digit_size, thickness); break;
            case 'C' : draw_shift_c(e, offset_location, lcd_digit_size, thickness); break;
            case 'd' :
            case 'D' : draw_d(e, offset_location, lcd_digit_size, thickness); break;
            case 'e' : draw_e(e, offset_location, lcd_digit_size, thickness); break;
            case 'E' : draw_shift_e(e, offset_location, lcd_digit_size, thickness); break;
            case 'f' :
            case 'F' : draw_shift_f(e, offset_location, lcd_digit_size, thickness); break;
            case 'g' :
            case 'G' : draw_shift_g(e, offset_location, lcd_digit_size, thickness); break;
            case 'h' : draw_h(e, offset_location, lcd_digit_size, thickness); break;
            case 'H' : draw_shift_h(e, offset_location, lcd_digit_size, thickness); break;
            case 'i' :
            case 'I' : draw_i(e, offset_location, lcd_digit_size, thickness); break;
            case 'j' :
            case 'J' : draw_shift_j(e, offset_location, lcd_digit_size, thickness); break;
            case 'l' :
            case 'L' : draw_shift_l(e, offset_location, lcd_digit_size, thickness); break;
            case 'o' :
            case 'O' : draw_o(e, offset_location, lcd_digit_size, thickness); break;
            case 'p' :
            case 'P' : draw_shift_p(e, offset_location, lcd_digit_size, thickness); break;
            case 'q' :
            case 'Q' : draw_q(e, offset_location, lcd_digit_size, thickness); break;
            case 'r' :
            case 'R' : draw_r(e, offset_location, lcd_digit_size, thickness); break;
            case 't' :
            case 'T' : draw_t(e, offset_location, lcd_digit_size, thickness); break;
            case 'u' : draw_u(e, offset_location, lcd_digit_size, thickness); break;
            case 'U' : draw_shift_u(e, offset_location, lcd_digit_size, thickness); break;
            case 'y' :
            case 'Y' : draw_shift_y(e, offset_location, lcd_digit_size, thickness); break;
            default: break;
          }
          offset_location += drawing::size(lcd_digit_size.width() - 2 + digit_spacing_, 0);
        }
      }

      drawing::size measure_control() const override {
        return drawing::size(((height() - 3) / 2 + digit_spacing_) * static_cast<int32_t>(text_.size()), height());
      }

    private:
      void draw_background_digit(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        drawing::color background_digit_color;
        if (environment::os_version().is_osx_platform())
          background_digit_color = drawing::color::from_argb(background_digit_transparency_, fore_color());
        else
          background_digit_color = drawing::color::average(fore_color(), back_color(), (double)background_digit_transparency_ / 255);
        draw_segment_top(graphics, background_digit_color, location, size, thickness);
        draw_segment_left_top(graphics, background_digit_color, location, size, thickness);
        draw_segment_right_top(graphics, background_digit_color, location, size, thickness);
        draw_segment_middle(graphics, background_digit_color, location, size, thickness);
        draw_segment_left_bottom(graphics, background_digit_color, location, size, thickness);
        draw_segment_right_bottom(graphics, background_digit_color, location, size, thickness);
        draw_segment_bottom(graphics, background_digit_color, location, size, thickness);
      }
      
      void draw_space(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
      }
      
      void draw_minus(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_point(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        if (style_ == lcd_style::standard) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(fore_color()), location.x() + size.width() / 2 - thickness / 2, location.y() + size.height() - 2 - offset, location.x() + size.width() / 2 + thickness / 2, location.y() + size.height() - 2 - offset);
        } else if (style_ == lcd_style::seven_segments) {
          graphics.fill_ellipse(drawing::solid_brush(fore_color()), location.x() + size.width() / 2 - thickness / 2, location.y() + size.height() - 1 - thickness, thickness, thickness);
        }
      }
      
      void draw_colon(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        if (style_ == lcd_style::standard) {
          for (int32_t offset = 0; offset < thickness; offset++) {
            graphics.draw_line(drawing::pen(fore_color()), location.x() + size.width() / 2 - thickness / 2, location.y() + size.height() / 3 - thickness / 2 + offset, location.x() + size.width() / 2 + thickness / 2, location.y() + size.height() / 3 - thickness / 2 + offset);
            graphics.draw_line(drawing::pen(fore_color()), location.x() + size.width() / 2 - thickness / 2, location.y() + size.height() /3 * 2 - thickness / 2 + offset, location.x() + size.width() / 2 + thickness / 2, location.y() + size.height() / 3 * 2 - thickness / 2 + offset);
          }
        } else if (style_ == lcd_style::seven_segments) {
          graphics.fill_ellipse(drawing::solid_brush(fore_color()), location.x() + size.width() / 2 - thickness / 2, location.y() + size.height() / 3 - thickness / 2, thickness, thickness);
          graphics.fill_ellipse(drawing::solid_brush(fore_color()), location.x() + size.width() / 2 - thickness / 2, location.y() + size.height() / 3 * 2 - thickness / 2, thickness, thickness);
        }
      }

      void draw_zero(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_one(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_two(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_three(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_four(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_five(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_six(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_seven(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_eight(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_nine(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_shift_a(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_b(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_c(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_shift_c(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_d(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_e(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_shift_e(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_shift_f(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_shift_g(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_h(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_shift_h(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_i(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_shift_j(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_shift_l(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_o(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_shift_p(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_q(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_r(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_shift_s(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_t(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_u(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_shift_u(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_shift_y(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_right_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_right_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }
      
      void draw_segment_top(drawing::graphics& graphics, const drawing::color& color, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        if (style_ == lcd_style::standard) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), location.x() + 2 + offset, location.y() + 1 + offset, location.x() + size.width() - 3 - offset, location.y() + 1 + offset);
        } else if (style_ == lcd_style::seven_segments) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), location.x() + 2 + thickness / 2 + abs(offset), location.y() + 1 + thickness / 2 + offset, location.x() + size.width() - 3 - thickness / 2 - abs(offset), location.y() + 1 + thickness / 2 + offset);
        }
      }
      
      void draw_segment_left_top(drawing::graphics& graphics, const drawing::color& color, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        if (style_ == lcd_style::standard) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), location.x() + 1 + offset, location.y() + 2 + offset, location.x() + 1 + offset, location.y() + size.height() / 2 - 1 - offset);
        } else if (style_ == lcd_style::seven_segments) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), location.x() + 1 + thickness / 2 + offset, location.y() + 2 + thickness / 2 + abs(offset), location.x() + 1 + thickness / 2 + offset, location.y() + size.height() / 2 - 1 - abs(offset));
        }
      }
      
      void draw_segment_right_top(drawing::graphics& graphics, const drawing::color& color, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        if (style_ == lcd_style::standard) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), location.x() + size.width() - 2 - offset, location.y() + 2 + offset, location.x() + size.width() - 2 - offset, location.y() + size.height() / 2 - 1 - offset);
        } else if (style_ == lcd_style::seven_segments) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), location.x() + size.width() - 2 - thickness / 2 - offset, location.y() + 2 + thickness / 2 + abs(offset), location.x() + size.width() - 2 - thickness / 2 - offset, location.y() + size.height() / 2 - 1 - abs(offset));
        }
      }
      
      void draw_segment_middle(drawing::graphics& graphics, const drawing::color& color, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        if (style_ == lcd_style::standard) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), location.x() + 2 + abs(offset), location.y() + size.height() / 2 + offset, location.x() + size.width() - 3 - abs(offset), location.y() + size.height() / 2 + offset);
        } else if (style_ == lcd_style::seven_segments) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), location.x() + 2 + thickness / 2 + abs(offset), location.y() + size.height() / 2 + offset, location.x() + size.width() - 3 - thickness / 2 - abs(offset), location.y() + size.height() / 2 + offset);
        }
      }
      
      void draw_segment_left_bottom(drawing::graphics& graphics, const drawing::color& color, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        if (style_ == lcd_style::standard) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), location.x() + 1 + offset, location.y() + size.height() / 2 + 1 + offset, location.x() + 1 + offset, location.y() + size.height() - 3 - offset);
        } else if (style_ == lcd_style::seven_segments) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), location.x() + 1 + thickness / 2 + offset, location.y() + size.height() / 2 + 1 - thickness / 2 + thickness / 2 + abs(offset), location.x() + 1 + thickness / 2 + offset, location.y()  + size.height() - 3 - thickness / 2 - abs(offset));
        }
      }
      
      void draw_segment_right_bottom(drawing::graphics& graphics, const drawing::color& color, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        if (style_ == lcd_style::standard) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), location.x() + size.width() - 2 - offset, location.y() + size.height() / 2 + 1 + offset,  location.x() + size.width() - 2 - offset, location.y() + size.height() - 3 - offset);
        } else if (style_ == lcd_style::seven_segments) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), location.x() + size.width() - 2 - thickness / 2 - offset, location.y() + size.height() / 2 + 1 - thickness / 2 + thickness / 2 + abs(offset), location.x() + size.width() - 2 - thickness / 2 - offset, location.y()  + size.height() - 3 - thickness / 2 - abs(offset));
        }
      }
      
      void draw_segment_bottom(drawing::graphics& graphics, const drawing::color& color, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        if (style_ == lcd_style::standard) {
          for (int32_t offset = 0; offset < thickness; offset++)
            graphics.draw_line(drawing::pen(color), location.x() + 2 + offset, location.y() + size.height() - 2 - offset, location.x() + size.width() - 3 - offset, location.y() + size.height() - 2 - offset);
        } else if (style_ == lcd_style::seven_segments) {
          for (int32_t offset = -thickness / 2; offset < thickness - thickness / 2; offset++)
            graphics.draw_line(drawing::pen(color), location.x() + 2 + thickness / 2 + abs(offset), location.y() + size.height() - 2 - thickness / 2 - offset, location.x() + size.width() - 3 - thickness / 2 - abs(offset), location.y() + size.height() - 2 - thickness / 2 - offset);
        }
      }
      
      bool show_background_digit_ = true;
      uint8_t background_digit_transparency_ = 32;
      uint32_t digit_spacing_ = 4;
      lcd_style style_ = lcd_style::standard;
    };
  }
}

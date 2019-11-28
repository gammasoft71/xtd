#include <xtd/xtd.forms>
#include <xtd/forms/native/wxwidgets/wx_list_box.hpp>
#include "address_book_new_32x32.xpm"
#include "appointment_new_32x32.xpm"
#include "gammasoft_32x32.xpm"

namespace xtd {
  namespace forms {
    enum class lcd_style {
      standard,
      seven_segments,
    };
  
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
        static ustring valid_characters = " -.0123456789aAbBcCdDeEfF";
        if (text_ != value) {
          for(const auto& c : value)
            if (strings::index_of(valid_characters, c) == -1) throw std::invalid_argument(strings::format("Only characters : \"{}\" are valid", valid_characters));
          control::text(value);
          invalidate();
        }
        return *this;
      }
      
    protected:
      drawing::size default_size() const override {return {100, 25};}
      void on_paint(paint_event_args& e) override {
        drawing::point offset_location;
        drawing::size lcd_digit_size((height() - 3) / 2 + 2, height());
        int32_t thickness = lcd_digit_size.width() / 5;
        for(char value: text()) {
          if (show_background_digit_) draw_background_digit(e, offset_location, lcd_digit_size, thickness);
          switch(value) {
            case ' ' : draw_space(e, offset_location, lcd_digit_size, thickness); break;
            case '-' : draw_minus(e, offset_location, lcd_digit_size, thickness); break;
            case '.' : draw_point(e, offset_location, lcd_digit_size, thickness); break;
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
            case 'A' : draw_a(e, offset_location, lcd_digit_size, thickness); break;
            case 'b' :
            case 'B' : draw_b(e, offset_location, lcd_digit_size, thickness); break;
            case 'c' :
            case 'C' : draw_c(e, offset_location, lcd_digit_size, thickness); break;
            case 'd' :
            case 'D' : draw_d(e, offset_location, lcd_digit_size, thickness); break;
            case 'e' :
            case 'E' : draw_e(e, offset_location, lcd_digit_size, thickness); break;
            case 'f' :
            case 'F' : draw_f(e, offset_location, lcd_digit_size, thickness); break;
            default: break;
          }
          offset_location += drawing::size(lcd_digit_size.width() - 2 + digit_spacing_, 0);
        }
      }
      
    private:
      void draw_background_digit(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, drawing::color::from_argb(background_digit_transparency_, fore_color()), location, size, thickness);
        draw_segment_left_top(graphics, drawing::color::from_argb(background_digit_transparency_, fore_color()), location, size, thickness);
        draw_segment_right_top(graphics, drawing::color::from_argb(background_digit_transparency_, fore_color()), location, size, thickness);
        draw_segment_middle(graphics, drawing::color::from_argb(background_digit_transparency_, fore_color()), location, size, thickness);
        draw_segment_left_bottom(graphics, drawing::color::from_argb(background_digit_transparency_, fore_color()), location, size, thickness);
        draw_segment_right_bottom(graphics, drawing::color::from_argb(background_digit_transparency_, fore_color()), location, size, thickness);
        draw_segment_bottom(graphics, drawing::color::from_argb(background_digit_transparency_, fore_color()), location, size, thickness);
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
        for (int32_t offset = 0; offset < thickness; offset++)
          graphics.draw_line(drawing::pen(fore_color()), location.x() + size.width() / 2 - thickness / 2, location.y() + size.height() - 2 - offset, location.x() + size.width() / 2 + thickness / 2, location.y() + size.height() - 2 - offset);
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

      void draw_a(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
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
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
        draw_segment_bottom(graphics, fore_color(), location, size, thickness);
      }

      void draw_f(paint_event_args& e, const drawing::point& location, const drawing::size& size, int32_t thickness) {
        drawing::graphics graphics = e.graphics();
        draw_segment_top(graphics, fore_color(), location, size, thickness);
        draw_segment_left_top(graphics, fore_color(), location, size, thickness);
        draw_segment_middle(graphics, fore_color(), location, size, thickness);
        draw_segment_left_bottom(graphics, fore_color(), location, size, thickness);
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

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form_main;
  form_main.text("Manual tests");
  form_main.start_position(form_start_position::manual);
  form_main.location({300, 200});
  form_main.client_size({985, 100});

  lcd_label label;
  label.parent(form_main);
  label.location({10, 10});
  label.dock(dock_style::fill);
  label.text("1234567890ABCDEF -.");
  label.style(lcd_style::seven_segments);
  //label.show_background_digit(false);
  //label.back_color(color::black);
  label.back_color(color::from_argb(16, color::lime));
  label.fore_color(color::lime);

  application::run(form_main);
}

#include <xtd/xtd.forms>
#include <xtd/forms/native/wxwidgets/wx_list_box.hpp>
#include "address_book_new_32x32.xpm"
#include "appointment_new_32x32.xpm"
#include "gammasoft_32x32.xpm"

namespace xtd {
  namespace forms {
    class lcd_label : public user_control {
    public:
      lcd_label() {
        
      }
  
    protected:
      void on_paint(paint_event_args& e) override {
        drawing::point offset_location;
        drawing::size lcd_digit_size(15, 25);
        //drawing::size lcd_digit_size(30, 52);
        for(char value: text()) {
          switch(value) {
            case ' ' : break;
            case '0' : draw_zero(e, offset_location, lcd_digit_size); break;
          default: std::invalid_argument("invalid character only [0-9], [A-F], [.]");
          }
        }
      }
      
    private:
      void draw_space(paint_event_args& e, const drawing::point& location, const drawing::size& size) {
        
      }

      void draw_zero(paint_event_args& e, const drawing::point& location, const drawing::size& size) {
        e.graphics().fill_rectangle(drawing::solid_brush(drawing::color::black), location.x(), location.y(), size.width(), size.height());
        // Top
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 2, location.y() + 1, location.x() + size.width() - 3, location.y() + 1);
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 3, location.y() + 2, location.x() + size.width() - 4, location.y() + 2);
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 4, location.y() + 3, location.x() + size.width() - 5, location.y() + 3);
        
        // Left up
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 1, location.y() + 2, location.x() + 1, location.y() + size.height() / 2 - 1);
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 2, location.y() + 3,  location.x() + 2, location.y() + size.height() / 2 - 2);
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 3, location.y() + 4,  location.x() + 3, location.y() + size.height() / 2 - 3);
        
        // Right up
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + size.width() - 4, location.y() + 4, location.x() + size.width() - 4, location.y() + size.height() / 2 - 3);
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + size.width() - 3, location.y() + 3,  location.x() + size.width() - 3, location.y() + size.height() / 2 - 2);
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + size.width() - 2, location.y() + 2,  location.x() + size.width() - 2, location.y() + size.height() / 2 - 1);

        // Middle
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 3, location.y() + size.height() / 2 - 1, location.x() + size.width() - 4, location.y() + size.height() / 2 - 1);
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 2, location.y() + size.height() / 2, location.x() + size.width() - 3, location.y() + size.height() / 2);
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 3, location.y() + size.height() / 2 + 1, location.x() + size.width() - 4, location.y() + size.height() / 2 + 1);

        // Left down
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 1, location.y() + size.height() / 2 + 1, location.x() + 1, location.y() + size.height() - 3);
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 2, location.y() + size.height() / 2 + 2,  location.x() + 2, location.y() + size.height() - 4);
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 3, location.y() + size.height() / 2 + 3,  location.x() + 3, location.y() + size.height() - 5);

        // Right down
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + size.width() - 4, location.y() + size.height() / 2 + 3, location.x() + size.width() - 4, location.y() + size.height() - 5);
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + size.width() - 3, location.y() + size.height() / 2 + 2,  location.x() + size.width() - 3, location.y() + size.height() - 4);
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + size.width() - 2, location.y() + size.height() / 2 + 1,  location.x() + size.width() - 2, location.y() + size.height() - 3);

        // Bottom
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 4, location.y() + size.height() - 4, location.x() + size.width() - 5, location.y() + size.height() - 4);
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 3, location.y() + size.height() - 3, location.x() + size.width() - 4, location.y() + size.height() - 3);
        e.graphics().draw_line(drawing::pen(fore_color()), location.x() + 2, location.y() + size.height() - 2, location.x() + size.width() - 3, location.y() + size.height() - 2);
      }
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
  form_main.location({400, 300});
  form_main.auto_size_mode(forms::auto_size_mode::grow_and_shrink);
  form_main.auto_size(true);

  lcd_label label;
  label.parent(form_main);
  label.size({260, 100});
  label.text("0");
  label.back_color(color::yellow);
  label.fore_color(color::green);
  label.invalidate();

  application::run(form_main);
}


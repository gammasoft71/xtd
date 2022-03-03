#include <xtd/xtd.forms.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;

class strings_form : public form {
public:
  static void main() {
    application::run(strings_form());
  }
  
  strings_form() {
    text("Strings tests");
    padding(5);
    client_size({800, 600});

    tab_control.parent(*this);
    tab_control.dock(dock_style::fill);
    
    tab_page_color.parent(tab_control);
    tab_page_color.text("Color");
    tab_page_color.paint += {*this, &strings_form::draw_strings_with_color};
  }
  
private:
  forms::tab_control tab_control;
  forms::tab_page tab_page_color;
  
  void draw_grid(const rectangle& rect, drawing::graphics& graphics, const drawing::size& grid_size = drawing::size(5, 5)) {
    auto color1 = back_color().is_dark() ? color::light(back_color()) : color::dark(back_color());
    auto color2 = fore_color().is_dark() ? color::light(fore_color()) : color::dark(fore_color());
    for (auto x = rect.left(); x < rect.right(); x += grid_size.width())
      graphics.draw_line(pen(color1, 1), point(x, rect.top()), point(x, rect.bottom()));
    for (auto y = rect.top(); y < rect.bottom(); y += grid_size.height())
      graphics.draw_line(pen(color1, 1), point(rect.left(), y), point(rect.right(), y));
    for (auto x = rect.left(); x < rect.right(); x += grid_size.width() * 10)
      graphics.draw_line(pen(color2, 1), point(x, rect.top()), point(x, rect.bottom()));
    for (auto y = rect.top(); y < rect.bottom(); y += grid_size.height() * 10)
      graphics.draw_line(pen(color2, 1), point(rect.left(), y), point(rect.right(), y));
  }
  
  void draw_strings_with_color(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());

    xtd::drawing::font font = xtd::drawing::font(system_fonts::default_font(), 32, font_style::regular);
    e.graphics().draw_string(u8"xtd.forms \U0001F428", font, solid_brush(color::red), point(50, 50));
  }
};

startup_(strings_form);


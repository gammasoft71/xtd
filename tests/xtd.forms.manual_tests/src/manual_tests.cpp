#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form_main;
  form_main.text("Manual tests");
  form_main.start_position(form_start_position::manual);
  form_main.location({300, 200});
  form_main.client_size({985, 100});
  form_main.back_color(color::black);
  
  lcd_label label;
  label.parent(form_main);
  label.location({10, 10});
  label.dock(dock_style::fill);
  label.text("1234567890ABCDEF -.");
  //label.style(lcd_style::seven_segments);
  //label.show_background_digit(false);
  //label.back_color(color::black);
  label.back_color(color::from_argb(16, color::lime));
  label.fore_color(color::lime);
  
  application::run(form_main);
}

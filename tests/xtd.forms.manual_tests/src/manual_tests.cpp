#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form_main;
  form_main.text("Manual tests");
  form_main.start_position(form_start_position::manual);
  form_main.location({300, 200});
  form_main.client_size({500, 200});
  form_main.back_color(color::black);
  
  lcd_label label;
  label.parent(form_main);
  label.location({10, 10});
  label.dock(dock_style::fill);
  //label.text("1234567890.:");
  label.style(lcd_style::seven_segments);
  //label.show_background_digit(false);
  label.back_color(color::average(color::lime, color::black, (double)16 / 255));
  label.fore_color(color::lime);

  //label.back_color(color::white);
  //label.fore_color(color::blue);

  int counter = 0;
  timer timer;
  timer.tick += [&] {
    label.text(strings::format("{:F1}", double(counter++) / 10));
  };
  timer.interval(100);
  timer.enabled(true);
  
  application::run(form_main);
}

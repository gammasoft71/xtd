#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  int counter = 0;
  
  timer timer;
  timer.interval(100);
  
  form form_main;
  form_main.text("Lcd label example 2");
  form_main.start_position(form_start_position::center_screen);
  form_main.auto_size_mode(forms::auto_size_mode::grow_and_shrink);
  form_main.auto_size(true);
  
  lcd_label label;
  label.parent(form_main);
  label.height(503);
  label.auto_size(true);
  label.style(lcd_style::seven_segments);
  label.fore_color(color::blue);
  label.back_color(color::average(label.fore_color(), color::black, 0.05));
  label.text("  0.0");

  timer.tick += [&] {
    label.text(strings::format("{,5:F1}", counter++ / 10.0));
  };

  label.mouse_down += [&] {
    if (control::mouse_buttons() == mouse_buttons::left)
      timer.enabled(!timer.enabled());
    else {
      counter = 0;
      label.text("  0.0");
    }
  };

  application::run(form_main);
}

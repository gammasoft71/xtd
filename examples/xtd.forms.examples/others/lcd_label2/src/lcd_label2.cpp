#include <xtd/xtd>

using namespace std::literals;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  auto counter = 0;
  
  timer timer;
  timer.interval(100ms);
  
  form form_main;
  form_main.text("Lcd label example 2");
  form_main.start_position(form_start_position::center_screen);
  form_main.auto_size_mode(forms::auto_size_mode::grow_and_shrink);
  form_main.client_size({1456, 503});

  lcd_label label;
  label.parent(form_main);
  label.dock(dock_style::fill);
  label.fore_color(color::blue);
  label.back_color(color::average(color::black, label.fore_color(), 0.05));
  label.text("  0.0");

  timer.tick += [&] {
    label.text(ustring::format("{,5:F1}", counter++ / 10.0));
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

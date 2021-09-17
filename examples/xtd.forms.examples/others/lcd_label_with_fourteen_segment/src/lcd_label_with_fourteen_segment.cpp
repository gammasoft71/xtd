#include <xtd/xtd>

using namespace std::literals;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  auto index = 1U;

  form form_main;
  form_main.text("Lcd label with fourteen segment example");
   form_main.client_size({202, 403});

  lcd_label label;
  label.parent(form_main);
  label.dock(dock_style::fill);
  label.fore_color(color::yellow);
  label.back_color(color::average(color::black, label.fore_color(), 0.05));
  label.lcd_style(forms::lcd_style::fourteen_segment_display);
  label.text(ustring::format("{}", label.valid_characters()[index]));

  timer timer;
  timer.interval(300ms);
  timer.enabled(!timer.enabled());
  timer.tick += [&] {
    if (++index >= label.valid_characters().size()) index = 0;
    label.text(ustring::format("{}", label.valid_characters()[index]));
  };

  application::run(form_main);
}

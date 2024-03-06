#include <xtd/drawing/color_converter>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/lcd_label>
#include <xtd/forms/timer>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

auto main()->int {
  auto index = 0_sz;
  
  form form_main;
  form_main.text("Lcd label with fourteen segment example");
  form_main.client_size({202, 403});
  
  lcd_label label;
  label.parent(form_main);
  label.dock(dock_style::fill);
  label.fore_color(color::yellow);
  label.back_color(color_converter::average(color::black, label.fore_color(), 0.05));
  label.lcd_style(forms::lcd_style::fourteen_segment_display);
  label.text(ustring::format("{}", label.valid_characters()[index]));
  
  timer timer;
  timer.interval(300_ms);
  timer.enabled(!timer.enabled());
  timer.tick += [&] {
    if (++index >= label.valid_characters().size()) index = 0;
    label.text(ustring::format("{}", label.valid_characters()[index]));
  };
  
  application::run(form_main);
}

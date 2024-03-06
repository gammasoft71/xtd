#include <xtd/drawing/color_converter>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/lcd_label>
#include <xtd/forms/timer>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

auto main()->int {
  auto show_seconds = true;
  
  auto clock_timer = timer {};
  clock_timer.interval(100_ms);
  clock_timer.enabled(true);
  
  auto form_main = form {};
  form_main.text("Clock");
  form_main.start_position(form_start_position::center_screen);
  form_main.auto_size_mode(forms::auto_size_mode::grow_and_shrink);
  form_main.auto_size(true);
  
  auto label = lcd_label {};
  label.parent(form_main);
  label.height(403);
  label.digit_spacing(4);
  label.auto_size(true);
  
  label.fore_color(color::lime);
  label.back_color(color_converter::average(color::black, label.fore_color(), 0.20));
  label.segment_style(segment_style::modern);
  label.show_back_digit(false);
  label.text(date_time::now().to_long_time_string());
  
  clock_timer.tick += [&] {
    auto now = date_time::now();
    label.text(show_seconds ? now.to_long_time_string() : now.to_short_time_string().replace(':', now.second() % 2 ? ' ' : ':'));
    form_main.center_to_screen();
  };
  
  label.click += [&] {show_seconds = !show_seconds;};

  application::run(form_main);
}

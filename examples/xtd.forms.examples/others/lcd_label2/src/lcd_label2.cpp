#define DEBUG
#include <xtd/diagnostics/debug>
#include <xtd/diagnostics/stopwatch>
#include <xtd/drawing/color_converter>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/lcd_label>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms;

auto main()->int {
  timer timer;
  timer.interval(100_ms);
  stopwatch chrono;
  
  form form_main;
  form_main.double_buffered(true);
  form_main.text("Lcd label example 2");
  form_main.start_position(form_start_position::center_screen);
  form_main.auto_size_mode(forms::auto_size_mode::grow_and_shrink);
  form_main.client_size({1456, 503});
  
  lcd_label label;
  label.double_buffered(true);
  label.parent(form_main);
  label.dock(dock_style::fill);
  label.fore_color(color::blue);
  label.back_color(color_converter::average(color::black, label.fore_color(), 0.05));
  label.text("  0.0");
  
  timer.tick += [&] {
    label.text(ustring::format("{,5:F1}", chrono.elapsed_milliseconds() / 1000.0));
    debug::write_line(ustring::format("{,5:F1}", chrono.elapsed_milliseconds() / 1000.0));
  };
  
  label.mouse_down += [&] {
    if (control::mouse_buttons() == mouse_buttons::left) {
      timer.enabled(!timer.enabled());
      if (timer.enabled()) chrono.start();
      else chrono.stop();
    } else {
      if (timer.enabled()) chrono.restart();
      else chrono.reset();
      label.text("  0.0");
    }
  };
  
  application::run(form_main);
}

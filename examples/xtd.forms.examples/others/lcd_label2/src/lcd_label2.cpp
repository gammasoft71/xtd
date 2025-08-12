#include <xtd/xtd>

auto main() -> int {
  auto timer = forms::timer::create(100_ms);
  auto chrono = diagnostics::stopwatch {};
  
  auto form_main = form::create("Lcd label example 2");
  form_main.double_buffered(true);
  form_main.start_position(form_start_position::center_screen);
  form_main.client_size({1456, 503});
  
  auto label = lcd_label::create(form_main, "  0.0");
  label.double_buffered(true);
  label.dock(dock_style::fill);
  label.fore_color(color::blue);
  label.back_color(color_converter::average(color::black, label.fore_color(), 0.05));
  
  timer.tick += delegate_ {
    label.text(string::format("{,5:F1}", chrono.elapsed_milliseconds() / 1000.0));
    diagnostics::debug::write_line(label.text());
  };
  
  label.mouse_down += delegate_ {
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

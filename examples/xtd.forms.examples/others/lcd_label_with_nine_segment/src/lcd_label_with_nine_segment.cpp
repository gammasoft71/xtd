#include <xtd/xtd>

auto main() -> int {
  auto index = 0_z;
  
  form form_main;
  form_main.text("Lcd label with nine segment example");
  form_main.client_size({202, 403});
  
  lcd_label label;
  label.parent(form_main);
  label.dock(dock_style::fill);
  label.fore_color(color::yellow);
  label.back_color(color_converter::average(color::black, label.fore_color(), 0.05));
  label.lcd_style(forms::lcd_style::nine_segment_display);
  label.text(string::format("{}", label.valid_characters()[index]));
  
  forms::timer timer;
  timer.interval(300_ms);
  timer.enabled(!timer.enabled());
  timer.tick += delegate_ {
    if (++index >= label.valid_characters().length()) index = 0;
    label.text(string::format("{}", label.valid_characters()[index]));
  };
  
  application::run(form_main);
}

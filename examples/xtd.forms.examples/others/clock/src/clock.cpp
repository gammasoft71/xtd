#include <ctime>
#include <xtd/xtd>

using namespace std::literals;
using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  auto show_seconds = true;
  auto center_to_screen_next_time = false;
  
  timer timer;
  timer.interval(100ms);
  timer.enabled(true);

  form form_main;
  form_main.text("Clock");
  form_main.start_position(form_start_position::center_screen);
  form_main.auto_size_mode(forms::auto_size_mode::grow_and_shrink);
  form_main.auto_size(true);
  
  lcd_label label;
  label.parent(form_main);
  label.height(403);
  label.digit_spacing(4);
  label.auto_size(true);
  
  label.fore_color(color::lime);
  label.back_color(color::average(color::black, label.fore_color(), 0.20));
  label.segment_style(segment_style::modern);
  label.show_back_digit(false);
  label.text(ustring::format("{:t}", std::chrono::system_clock::now()));
  
  timer.tick += [&] {
    auto time_str = ustring::format(show_seconds ? "{:t}" : "{:v}", std::chrono::system_clock::now());
    auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    if (!show_seconds && std::localtime(&time)->tm_sec % 2) time_str = time_str.replace(':', ' ');
    label.text(time_str);
    if (center_to_screen_next_time) form_main.center_to_screen();
    center_to_screen_next_time = false;
  };
  
  label.click += [&] {
    show_seconds = !show_seconds;
    center_to_screen_next_time = true;
  };

  application::run(form_main);
}

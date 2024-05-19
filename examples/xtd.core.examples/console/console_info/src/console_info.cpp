#include <xtd/console>

using namespace xtd;

auto main() -> int {
  console::write_line("background_color = {}", console::background_color());
  console::write_line("foreground_color = {}", console::foreground_color());
  console::write_line("buffer_height = {}", console::buffer_height());
  console::write_line("buffer_width = {}", console::buffer_width());
  console::write_line("caps_lock = {}", console::caps_lock());
  console::write_line("cursor_left = {}", console::cursor_left());
  console::write_line("cursor_size = {}", console::cursor_size());
  console::write_line("cursor_top = {}", console::cursor_top());
  console::write_line("cursor_visible = {}", console::cursor_visible());
  console::write_line("foreground_color = {}", console::foreground_color());
  console::write_line("is_rrror_redirected = {}", console::is_error_redirected());
  console::write_line("is_input_redirected = {}", console::is_input_redirected());
  console::write_line("is_output_redirected = {}", console::is_output_redirected());
  console::write_line("key_available = {}", console::key_available());
  console::write_line("largest_window_height = {}", console::largest_window_height());
  console::write_line("largest_window_width = {}", console::largest_window_width());
  console::write_line("title = {}", console::title());
  console::write_line("treat_control_c_as_input = {}", console::treat_control_c_as_input());
  console::write_line("window_height = {}", console::window_height());
  console::write_line("window_left = {}", console::window_left());
  console::write_line("window_top = {}", console::window_top());
  console::write_line("window_width = {}", console::window_width());
}

// This code can produce the following output:
//
// background_color = black
// foreground_color = white
// buffer_height = 24
// buffer_width = 80
// caps_lock = false
// cursor_left = 0
// cursor_size = 100
// cursor_top = 0
// cursor_visible = true
// foreground_color = white
// is_rrror_redirected = false
// is_input_redirected = false
// is_output_redirected = false
// key_available = false
// largest_window_height = 1000
// largest_window_width = 1000
// title =
// treat_control_c_as_input = false
// window_height = 24
// window_left = 0
// window_top = 0
// window_width = 80

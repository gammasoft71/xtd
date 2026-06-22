#include <xtd/xtd>

auto main() -> int {
  console::write_line("Streams:");
  console::write_line("  Is error redirected = {}", console::is_error_redirected());
  console::write_line("  Is input redirected = {}", console::is_input_redirected());
  console::write_line("  Is output redirected = {}", console::is_output_redirected());
  console::write_line();
  console::write_line("Input:");
  console::write_line("  Key available = {}", console::key_available());
  console::write_line("  Caps lock = {}", console::caps_lock());
  console::write_line("  Number lock = {}", console::number_lock());
  console::write_line("  Treat control-c as input = {}", console::treat_control_c_as_input());
  console::write_line("  Input code page = {}", console::input_code_page());
  console::write_line();
  console::write_line("Output:");
  console::write_line("  Background color = {}", console::background_color());
  console::write_line("  Foreground color = {}", console::foreground_color());
  console::write_line("  Cursor left = {}", console::cursor_left());
  console::write_line("  Cursor top = {}", console::cursor_top());
  console::write_line("  Cursor size = {}%", console::cursor_size());
  console::write_line("  Cursor visible = {}", console::cursor_visible());
  console::write_line("  Auto flush out = {}", console::auto_flush_out());
  console::write_line("  Autput code page = {}", console::output_code_page());
  console::write_line();
  console::write_line("Window:");
  console::write_line("  Title = {}", console::title());
  console::write_line("  Window left = {}", console::window_left());
  console::write_line("  Window top = {}", console::window_top());
  console::write_line("  Window width = {}", console::window_width());
  console::write_line("  Window height = {}", console::window_height());
  console::write_line("  Largest window width = {}", console::largest_window_width());
  console::write_line("  Largest window height = {}", console::largest_window_height());
  console::write_line("  Buffer width = {}", console::buffer_width());
  console::write_line("  Buffer height = {}", console::buffer_height());
}

// This code can produce the following output :
//
// Streams:
//   Is error redirected = false
//   Is input redirected = false
//   Is output redirected = false
//
// Input:
//   Key available = false
//   Caps lock = false
//   Number lock = true
//   Treat control-c as input = false
//   Input code page = 65001
//
// Output:
//   Background color = default_color
//   Foreground color = default_color
//   Cursor left = 0
//   Cursor top = 18
//   Cursor size = 100%
//   Cursor visible = true
//   Auto flush out = true
//   Output code page = 65001
//
// Window:
//   Title =
//   Window left = 0
//   Window top = 0
//   Window width = 120
//   Window height = 30
//   Largest window width = 1000
//   Largest window height = 1000
//   Buffer width = 120
//   Buffer height = 30

#include <xtd/console>

using namespace xtd;

auto main() -> int {
  auto orig_width = 0, width = 0;
  auto orig_height = 0, height = 0;
  auto m1 = "The current window width is {0}, and the current window height is {1}.";
  auto m2 = "The new window width is {0}, and the new window height is {1}.";
  auto m4 = "  (Press any key to continue...)";
  //
  // Step 1: Get the current window dimensions.
  //
  orig_width  = console::window_width();
  orig_height = console::window_height();
  console::write_line(m1, console::window_width(), console::window_height());
  console::write_line(m4);
  console::read_key(true);
  //
  // Step 2: Cut the window to 1/4 its original size.
  //
  width  = orig_width / 2;
  height = orig_height / 2;
  console::set_window_size(width, height);
  console::write_line(m2, console::window_width(), console::window_height());
  console::write_line(m4);
  console::read_key(true);
  //
  // Step 3: Restore the window to its original size.
  //
  console::set_window_size(orig_width, orig_height);
  console::write_line(m1, console::window_width(), console::window_height());}

// This code produces the following output:
//
// The current window width is 100, and the current window height is 60.
//   (Press any key to continue...)
// The new window width is 50, and the new window height is 30.
//   (Press any key to continue...)
// The current window width is 100, and the current window height is 60.

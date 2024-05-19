#include <xtd/console>

using namespace xtd;

auto main() -> int {
  auto m0 = "This example increments the cursor size from 1% to 100%:\n";
  auto m1 = "Cursor size = {0}%. (Press any key to continue...)";
  auto sizes = { 1, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

  auto save_cursor_size = console::cursor_size();
  console::write_line(m0);
  for (auto size : sizes) {
    console::cursor_size(size);
    console::write_line(m1, size);
    console::read_key();
  }
  console::cursor_size(save_cursor_size);
}

// This code produces the following output:
//
// This example increments the cursor size from 1% to 100%:
//
// Cursor size = 1%. (Press any key to continue...)
// Cursor size = 10%. (Press any key to continue...)
// Cursor size = 20%. (Press any key to continue...)
// Cursor size = 30%. (Press any key to continue...)
// Cursor size = 40%. (Press any key to continue...)
// Cursor size = 50%. (Press any key to continue...)
// Cursor size = 60%. (Press any key to continue...)
// Cursor size = 70%. (Press any key to continue...)
// Cursor size = 80%. (Press any key to continue...)
// Cursor size = 90%. (Press any key to continue...)
// Cursor size = 100%. (Press any key to continue...)

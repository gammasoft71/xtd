#include <xtd/console>

using namespace xtd;

// The main entry point for the application.
int main() {
  console::foreground_color(console_color::blue);
  console::write_line("Hello, World!");
  console::reset_color();
}

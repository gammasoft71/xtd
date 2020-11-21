#include <xtd/xtd>

using namespace xtd;

int main() {
  console::write_line("The current buffer height is {} rows.", console::buffer_height());
  console::write_line("The current buffer width is {} columns.", console::buffer_width());
}

// This code produces the following output:
//
// The current buffer height is 300 rows.
// The current buffer width is 85 columns.

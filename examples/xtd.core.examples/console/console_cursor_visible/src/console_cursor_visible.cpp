#include <xtd/console>

using namespace xtd;

auto main() -> int {
  auto m1 = "\nThe cursor is {0}.\nType any text then press Enter. "
  "Type '+' in the first column to show \n"
  "the cursor, '-' to hide the cursor, "
  "or lowercase 'x' to quit:"_s;
  auto s = ustring::empty_string;

  auto save_cursor_visibile = console::cursor_visible();
  auto save_cursor_size = console::cursor_size();
  console::cursor_visible(true); // Initialize the cursor to visible.
  console::cursor_size(100);     // Emphasize the cursor.
  
  while (true) {
    console::write_line(m1, ((console::cursor_visible() == true) ? "VISIBLE" : "HIDDEN"));
    s = console::read_line();
    if (ustring::is_empty(s) == false) {
      if (s[0] == '+')
        console::cursor_visible(true);
      else if (s[0] == '-')
        console::cursor_visible(false);
      else if (s[0] == 'x')
        break;
    }
  }
  console::cursor_visible(save_cursor_visibile);
  console::cursor_size(save_cursor_size);
}

// This code produces the following output. Note that these results
// cannot depict cursor visibility. You must run the example to see the
// cursor behavior:
//
// The cursor is VISIBLE.
// Type any text then press Enter. Type '+' in the first column to show
// the cursor, '-' to hide the cursor, or lowercase 'x' to quit:
// The quick brown fox
//
// The cursor is VISIBLE.
// Type any text then press Enter. Type '+' in the first column to show
// the cursor, '-' to hide the cursor, or lowercase 'x' to quit:
// -
//
// The cursor is HIDDEN.
// Type any text then press Enter. Type '+' in the first column to show
// the cursor, '-' to hide the cursor, or lowercase 'x' to quit:
// jumps over
//
// The cursor is HIDDEN.
// Type any text then press Enter. Type '+' in the first column to show
// the cursor, '-' to hide the cursor, or lowercase 'x' to quit:
// +
//
// The cursor is VISIBLE.
// Type any text then press Enter. Type '+' in the first column to show
// the cursor, '-' to hide the cursor, or lowercase 'x' to quit:
// the lazy dog.
//
// The cursor is VISIBLE.
// Type any text then press Enter. Type '+' in the first column to show
// the cursor, '-' to hide the cursor, or lowercase 'x' to quit:
// x

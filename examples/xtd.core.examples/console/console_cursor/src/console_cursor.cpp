#include <xtd/xtd>

using namespace xtd;

int orig_row = 0;
int orig_col = 0;

void write_at(const ustring& s, int x, int y) {
  console::set_cursor_position(orig_col + x, orig_row + y);
  console::write(s);
}

int main() {
  // Clear the screen, then save the top and left coordinates.
  console::clear();
  orig_row = console::cursor_top();
  orig_col = console::cursor_left();
  
  // Draw the left side of a 5x5 rectangle, from top to bottom.
  write_at("+", 0, 0);
  write_at("|", 0, 1);
  write_at("|", 0, 2);
  write_at("|", 0, 3);
  write_at("+", 0, 4);
  
  // Draw the bottom side, from left to right.
  write_at("-", 1, 4); // shortcut: write_at("---", 1, 4)
  write_at("-", 2, 4); // ...
  write_at("-", 3, 4); // ...
  write_at("+", 4, 4);
  
  // Draw the right side, from bottom to top.
  write_at("|", 4, 3);
  write_at("|", 4, 2);
  write_at("|", 4, 1);
  write_at("+", 4, 0);
  
  // Draw the top side, from right to left.
  write_at("-", 3, 0); // shortcut: write_at("---", 1, 0)
  write_at("-", 2, 0); // ...
  write_at("-", 1, 0); // ...
  //
  write_at("All done!", 0, 6);
  console::write_line();
}

// This code produces the following output:
//
// +---+
// |   |
// |   |
// |   |
// +---+
//
// All done!

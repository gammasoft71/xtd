#include <xtd/xtd.core>

using namespace std;
using namespace xtd;

int main() {
  // Get an array with the values of ConsoleColor enumeration members.
  vector colors = {console_color::black, console_color::dark_blue, console_color::dark_green, console_color::dark_cyan, console_color::dark_red, console_color::dark_magenta, console_color::dark_yellow, console_color::gray, console_color::dark_gray, console_color::blue, console_color::green, console_color::cyan, console_color::red, console_color::magenta, console_color::yellow, console_color::white};
  
  // Save the current background and foreground colors.
  console_color current_background = console::background_color();
  console_color current_foreground = console::foreground_color();
  
  // Display all foreground colors except the one that matches the background.
  console::write_line("All the foreground colors except {}, the background color:", current_background);
  for (auto color : colors) {
    if (color == current_background) continue;
    
    console::foreground_color(color);
    console::write_line("   The foreground color is {}.", color);
  }
  console::write_line();
  // Restore the foreground color.
  console::foreground_color(current_foreground);
  
  // Display each background color except the one that matches the current foreground color.
  console::write_line("All the background colors except {}, the foreground color:", current_foreground);
  for (auto color : colors) {
    if (color == current_foreground) continue;
    
    console::background_color(color);
    console::write_line("   The background color is {}.", color);
  }
  
  // Restore the original console colors.
  console::reset_color();
  console::write_line("\nOriginal colors restored...");
}

// This code produces the following output with colors:
//
// All the foreground colors except black, the background color:
//    The foreground color is dark_blue.
//    The foreground color is dark_green.
//    The foreground color is dark_cyan.
//    The foreground color is dark_red.
//    The foreground color is dark_magenta.
//    The foreground color is dark_yellow.
//    The foreground color is gray.
//    The foreground color is dark_gray.
//    The foreground color is blue.
//    The foreground color is green.
//    The foreground color is cyan.
//    The foreground color is red.
//    The foreground color is magenta.
//    The foreground color is yellow.
//    The foreground color is white.
//
// All the background colors except white, the foreground color:
//    The background color is black.
//    The background color is dark_blue.
//    The background color is dark_green.
//    The background color is dark_cyan.
//    The background color is dark_red.
//    The background color is dark_magenta.
//    The background color is dark_yellow.
//    The background color is gray.
//    The background color is dark_gray.
//    The background color is blue.
//    The background color is green.
//    The background color is cyan.
//    The background color is red.
//    The background color is magenta.
//    The background color is yellow.

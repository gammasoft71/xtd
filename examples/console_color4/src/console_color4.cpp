#include <xtd/xtd.console>
#include <map>
#include <vector>

using namespace std;
using namespace xtd;

string to_string(console_color color) noexcept {
  static map<console_color, string> colors = {{console_color::black, "black"}, {console_color::dark_blue, "dark_blue"}, {console_color::dark_green, "dark_green"}, {console_color::dark_cyan, "dark_cyan"}, {console_color::dark_red, "dark_red"}, {console_color::dark_magenta, "dark_magenta"}, {console_color::dark_yellow, "dark_yellow"}, {console_color::gray, "gray"}, {console_color::dark_gray, "dark_gray"}, {console_color::blue, "blue"}, {console_color::green, "green"}, {console_color::cyan, "cyan"}, {console_color::red, "red"}, {console_color::magenta, "magenta"}, {console_color::yellow, "yellow"}, {console_color::white, "white"}};
  if (colors.find(color) == colors.end()) return to_string(static_cast<int>(color));
  return colors[color];
}

// The main entry point for the application.
int main() {
  // Get an array with the values of ConsoleColor enumeration members.
  vector<console_color> colors = {console_color::black, console_color::dark_blue, console_color::dark_green, console_color::dark_cyan, console_color::dark_red, console_color::dark_magenta, console_color::dark_yellow, console_color::gray, console_color::dark_gray, console_color::blue, console_color::green, console_color::cyan, console_color::red, console_color::magenta, console_color::yellow, console_color::white};
  
  // Save the current background and foreground colors.
  console_color current_background = console::background_color();
  console_color current_foreground = console::foreground_color();
  
  // Display all foreground colors except the one that matches the background.
  console::write_line("All the foreground colors except {}, the background color:", to_string(current_background));
  for (auto color : colors) {
    if (color == current_background) continue;
    
    console::foreground_color(color);
    console::write_line("   The foreground color is {}.", to_string(color));
  }
  console::write_line();
  // Restore the foreground color.
  console::foreground_color(current_foreground);
  
  // Display each background color except the one that matches the current foreground color.
  console::write_line("All the background colors except {}, the foreground color:", to_string(current_foreground));
  for (auto color : colors) {
    if (color == current_foreground) continue;
    
    console::background_color(color);
    console::write_line("   The background color is {}.", to_string(color));
  }

  // Restore the original console colors.
  console::reset_color();
  console::write_line("\nOriginal colors restored...");
}

// This code produces the following output with colors:
//
// All the foreground colors except DarkCyan, the background color:
//    The foreground color is Black.
//    The foreground color is DarkBlue.
//    The foreground color is DarkGreen.
//    The foreground color is DarkRed.
//    The foreground color is DarkMagenta.
//    The foreground color is DarkYellow.
//    The foreground color is Gray.
//    The foreground color is DarkGray.
//    The foreground color is Blue.
//    The foreground color is Green.
//    The foreground color is Cyan.
//    The foreground color is Red.
//    The foreground color is Magenta.
//    The foreground color is Yellow.
//    The foreground color is White.
//
// All the background colors except White, the foreground color:
//    The background color is Black.
//    The background color is DarkBlue.
//    The background color is DarkGreen.
//    The background color is DarkCyan.
//    The background color is DarkRed.
//    The background color is DarkMagenta.
//    The background color is DarkYellow.
//    The background color is Gray.
//    The background color is DarkGray.
//    The background color is Blue.
//    The background color is Green.
//    The background color is Cyan.
//    The background color is Red.
//    The background color is Magenta.
//    The background color is Yellow.
//
// Original colors restored...

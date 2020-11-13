#include <xtd/xtd.core>

using namespace xtd;

// The main entry point for the application.
int main(int argc, char* argv[]) {
  int x = 0;
  //
  if ((argc == 2) && (x = atoi(argv[1])) && ((x >= 1) && (x <= 9))) {
    for (int i = 1; i <= x; i++) {
      console::write_line("Beep number {}.", i);
      console::beep();
    }
  } else
    console::write_line("Usage: Enter the number of times (between 1 and 9) to beep.");
}

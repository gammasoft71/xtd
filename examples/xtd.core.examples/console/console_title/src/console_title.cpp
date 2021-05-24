#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  console::write_line("The current console title is: \"{0}\"", console::title());
  console::write_line("  (Press any key to change the console title.)");
  console::read_key(true);
  console::title("The title has changed!");
  console::write_line("Note that the new console title is \"{0}\"\n"
                      "  (Press any key to quit.)", console::title());
  console::read_key(true);
}

// This code produces the following output:
//
// The current console title is: "Command Prompt - console_title"
// (Press any key to change the console title.)
// Note that the new console title is "The title has changed!"
// (Press any key to quit.)

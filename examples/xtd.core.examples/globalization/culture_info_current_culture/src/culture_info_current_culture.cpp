#include <xtd/xtd>

using namespace xtd::globalization;

auto main() -> int {
  // Display the name of the current culture.
  console::write_line("The current culture is {}.", culture_info::current_culture().name());
  
  // Change the current culture to th-TH.
  culture_info::current_culture(culture_info {"th-TH"});
  console::write_line("The current culture is now {}.", culture_info::current_culture().name());
}

// This code produces the following output :
//
// The current culture is en-US.
// The current culture is now th-TH.


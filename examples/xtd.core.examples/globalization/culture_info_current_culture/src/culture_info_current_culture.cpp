#include <xtd/xtd>

using namespace xtd::globalization;

auto main() -> int {
  // Display the name of the current culture.
  console::write_line("The current culture is {}.", culture_info::current_culture().name());
  console::write_line("The current locale is {}.", std::locale {}.name());
  console::write_line();

  // Change the current culture to ar-MA.
  culture_info::current_culture(culture_info {"ar-MA"});
  console::write_line("The current culture is now {}.", culture_info::current_culture().name());
  console::write_line("The current locale is now {}.", std::locale {}.name());
  console::write_line();

  // Change the current locale to fr_FR.UTF-8.
  std::locale::global(std::locale {"fr_FR.UTF-8"});
  console::write_line("The current culture is now {}.", culture_info::current_culture().name());
  console::write_line("The current locale is now {}.", std::locale {}.name());
}

// This code produces the following output :
//
// The current culture is en-US.
// The current locale is C.
//
// The current culture is now ar-MA.
// The current locale is now ar_MA.UTF-8.
//
// The current culture is now fr-FR.
// The current locale is now fr_FR.UTF-8.

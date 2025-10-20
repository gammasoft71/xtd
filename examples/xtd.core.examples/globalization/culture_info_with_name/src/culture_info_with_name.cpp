#include <xtd/xtd>

using namespace xtd::globalization;

auto main() -> int {
  auto current = culture_info::current_culture();
  console::write_line("The current culture is {}", current.name());
  auto new_culture = culture_info {};
  if (current.name().equals("fr-FR"))
    new_culture = culture_info {"fr-LU"};
  else
    new_culture = culture_info {"fr-FR"};
  
  culture_info::current_culture(new_culture);
  console::write_line("The current culture is now {}", culture_info::current_culture().name());
}

// This code produces the following output :
//
// The current culture is en-US
// The current culture is now fr-FR


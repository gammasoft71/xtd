#include <xtd/xtd>

using namespace globalization;

auto main() -> int {
  // Get and enumerate all cultures.
  auto all_cultures = culture_info::get_cultures(culture_types::all_cultures);
  for (auto ci : all_cultures) {
    // Display the name of each culture.
    console::write("{} ({}): ", ci.english_name(), ci.name());
    // Indicate the culture type.
    if (enum_object {ci.culture_types()}.has_flag(culture_types::neutral_cultures))
      console::write(" neutral_culture");
    if (enum_object {ci.culture_types()}.has_flag(culture_types::specific_cultures))
      console::write(" spsecific_culture");
    console::write_line();
  }
}

// This code produces the following output :
//
// The current culture is en-US
// The current culture is now fr-FR


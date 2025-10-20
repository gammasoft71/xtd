#include <xtd/xtd>

using namespace xtd::globalization;

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
// Invariant Language (Invariant Country) ():  spsecific_culture
// Afrikaans (af):  neutral_culture
// Afrikaans (Namibia) (af-NA):  spsecific_culture
// ...
// Chinese, Traditional (Taiwan) (zh-Hant-TW):  spsecific_culture
// Zulu (zu):  neutral_culture
// Zulu (South Africa) (zu-ZA):  spsecific_culture

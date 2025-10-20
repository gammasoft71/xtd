#include <xtd/xtd>

using namespace xtd::globalization;

auto main() -> int {
  // Displays several properties of the neutral cultures.
  console::write_line("CULTURE     ISO ISO WIN DISPLAYNAME                              ENGLISHNAME");
  for (auto ci : culture_info::get_cultures(culture_types::neutral_cultures)) {
    console::write("{,-11}", ci.name());
    console::write(" {,-3}", ci.two_letter_iso_language_name());
    console::write(" {,-3}", ci.three_letter_iso_language_name());
    console::write(" {,-3}", ci.three_letter_windows_language_name());
    console::write(" {,-40}", ci.display_name());
    console::write_line(" {,-40}", ci.english_name());
  }
}

// This code produces the following output :
//
// CULTURE     ISO ISO WIN DISPLAYNAME                              ENGLISHNAME
// af          af  afr AFK Afrikaans                                Afrikaans
// agq         agq agq ZZZ Aghem                                    Aghem
// ain         ain ain ZZZ Ainu                                     Ainu
// ak          ak  aka ZZZ Akan                                     Akan
// ...
// zh          zh  zho CHS Chinese                                  Chinese
// zh-Hans     zh  zho CHS Chinese, Simplified                      Chinese, Simplified
// zh-Hant     zh  zho ZHH Chinese, Traditional                     Chinese, Traditional
// zu          zu  zul ZUL Zulu                                     Zulu

#include <xtd/xtd>

using namespace xtd::globalization;

auto main() -> int {
  // Creates and initializes the culture_info.
  auto my_ci = culture_info {3082};
  
  // Displays the properties of the culture.
  console::write_line("{,-35}{,-47}", "PROPERTY", "VALUE");
  console::write_line("{,-35}{,-47}", "display_name", my_ci.display_name());
  console::write_line("{,-35}{,-47}", "english_name", my_ci.english_name());
  console::write_line("{,-35}{,-47}", "is_neutral_culture", my_ci.is_neutral_culture());
  console::write_line("{,-35}{,-47}", "is_read_only", my_ci.is_read_only());
  console::write_line("{,-35}{,-47}", "lcid", my_ci.lcid());
  console::write_line("{,-35}{,-47}", "locale", my_ci.locale().name());
  console::write_line("{,-35}{,-47}", "name", my_ci.name());
  console::write_line("{,-35}{,-47}", "native_name", my_ci.native_name());
  console::write_line("{,-35}{,-47}", "parent", my_ci.parent());
  console::write_line("{,-35}{,-47}", "three_letter_iso_language_name", my_ci.three_letter_iso_language_name());
  console::write_line("{,-35}{,-47}", "three_letter_windows_language_name", my_ci.three_letter_windows_language_name());
  console::write_line("{,-35}{,-47}", "two_letter_iso_language_name", my_ci.two_letter_iso_language_name());
  console::write_line();
}

// This code produces the following output :
//
// PROPERTY                           VALUE
// display_name                       Spanish (Spain)
// english_name                       Spanish (Spain)
// is_neutral_culture                 false
// is_read_only                       false
// lcid                               3082
// name                               es-ES
// locale                             es_ES.UTF-8
// native_name                        español (España)
// parent                             es
// three_letter_iso_language_name     spa
// three_letter_windows_language_name ESN
// two_letter_iso_language_name       es

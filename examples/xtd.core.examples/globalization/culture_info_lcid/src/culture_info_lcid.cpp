#include <xtd/xtd>

using namespace xtd::globalization;

auto main() -> int {
  // Creates and initializes the culture_info.
  auto my_ci = culture_info {3082};
  
  // Displays the properties of each culture.
  console::write_line("{,-35}{,-47}", "PROPERTY", "VALUE");
  console::write_line("{,-35}{,-47}", "display_name", my_ci.display_name());
  console::write_line("{,-35}{,-47}", "english_name", my_ci.english_name());
  console::write_line("{,-35}{,-47}", "is_neutral_culture", my_ci.is_neutral_culture());
  console::write_line("{,-35}{,-47}", "is_read_only", my_ci.is_read_only());
  console::write_line("{,-35}{,-47}", "lcid", my_ci.lcid());
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
// zh          Chinese                                 : neutral
// zh-Hans     Chinese, Simplified                     : neutral
// zh-Hans-CN  Chinese, Simplified (China mainland)    : specific
// zh-Hans-HK  Chinese, Simplified (Hong Kong)         : specific
// zh-Hans-JP  Chinese, Simplified (Japan)             : specific
// zh-Hans-MO  Chinese, Simplified (Macao)             : specific
// zh-Hans-MY  Chinese, Simplified (Malaysia)          : specific
// zh-Hans-SG  Chinese, Simplified (Singapore)         : specific
// zh-Hant     Chinese, Traditional                    : neutral
// zh-Hant-CN  Chinese, Traditional (China mainland)   : specific
// zh-Hant-HK  Chinese, Traditional (Hong Kong)        : specific
// zh-Hant-JP  Chinese, Traditional (Japan)            : specific
// zh-Hant-MO  Chinese, Traditional (Macao)            : specific
// zh-Hant-MY  Chinese, Traditional (Malaysia)         : specific
// zh-Hant-TW  Chinese, Traditional (Taiwan)           : specific

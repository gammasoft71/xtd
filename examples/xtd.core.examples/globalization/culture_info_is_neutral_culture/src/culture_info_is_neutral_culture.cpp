#include <xtd/xtd>

using namespace xtd::globalization;

auto main() -> int {
  // Lists the cultures that use the Chinese language and determines if each is a neutral culture.
  for (auto ci : culture_info::get_cultures(culture_types::all_cultures)) {
    if (ci.two_letter_iso_language_name() == "zh") {
      console::write("{,-11} {,-40}", ci.name(), ci.english_name());
      if (ci.is_neutral_culture())
        console::write_line(": neutral");
      else
        console::write_line(": specific");
    }
  }
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

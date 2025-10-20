#include <xtd/xtd>

using namespace xtd::globalization;

auto main() -> int {
  /// Determines the specific cultures that use the Chinese language, and displays the parent culture.
  for (auto ci : culture_info::get_cultures(culture_types::specific_cultures)) {
    if (ci.two_letter_iso_language_name() == "zh") {
      console::write("0x{:X4} {} {,-40}", ci.lcid(), ci.name(), ci.english_name());
      console::write_line("0x{:X4} {} {}", ci.parent().lcid(), ci.parent().name(), ci.parent().english_name());
    }
  }
}

// This code produces the following output :
//
// 0x1000 zh-Hans-CN Chinese, Simplified (China mainland)    0x0004 zh-Hans Chinese, Simplified
// 0x1000 zh-Hans-HK Chinese, Simplified (Hong Kong)         0x0004 zh-Hans Chinese, Simplified
// 0x1000 zh-Hans-JP Chinese, Simplified (Japan)             0x0004 zh-Hans Chinese, Simplified
// 0x1000 zh-Hans-MO Chinese, Simplified (Macao)             0x0004 zh-Hans Chinese, Simplified
// 0x1000 zh-Hans-MY Chinese, Simplified (Malaysia)          0x0004 zh-Hans Chinese, Simplified
// 0x1000 zh-Hans-SG Chinese, Simplified (Singapore)         0x0004 zh-Hans Chinese, Simplified
// 0x1000 zh-Hant-CN Chinese, Traditional (China mainland)   0x7C04 zh-Hant Chinese, Traditional
// 0x1000 zh-Hant-HK Chinese, Traditional (Hong Kong)        0x7C04 zh-Hant Chinese, Traditional
// 0x1000 zh-Hant-JP Chinese, Traditional (Japan)            0x7C04 zh-Hant Chinese, Traditional
// 0x1000 zh-Hant-MO Chinese, Traditional (Macao)            0x7C04 zh-Hant Chinese, Traditional
// 0x1000 zh-Hant-MY Chinese, Traditional (Malaysia)         0x7C04 zh-Hant Chinese, Traditional
// 0x1000 zh-Hant-TW Chinese, Traditional (Taiwan)           0x7C04 zh-Hant Chinese, Traditional

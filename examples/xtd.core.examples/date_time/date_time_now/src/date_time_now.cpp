#include <xtd/xtd>

using namespace xtd::globalization;

class program {
public:
  static auto main() {
    auto local_date = date_time::now();
    auto utc_date = date_time::utc_now();
    auto culture_names = array {"en-US", "en-GB", "fr-FR", "de-DE", "ru-RU"};
    
    for (auto culture_name : culture_names) {
      culture_info::current_culture(culture_info {culture_name});
      console::write_line("{}:", culture_name);
      console::write_line("   Local date and time: {:f}, {}", local_date, local_date.kind());
      console::write_line("   UTC date and time: {:f}, {}\n", utc_date, utc_date.kind());
    }
  }
};

startup_(program::main);

// This code can produce the following output :
//
// en-US:
//    Local date and time: Tuesday, October 14, 2025 10:04, local
//    UTC date and time: Tuesday, October 14, 2025 08:04, utc
//
// en-GB:
//    Local date and time: Tuesday, October 14, 2025 10:04, local
//    UTC date and time: Tuesday, October 14, 2025 08:04, utc
//
// fr-FR:
//    Local date and time: mardi, octobre 14, 2025 10:04, local
//    UTC date and time: mardi, octobre 14, 2025 08:04, utc
//
// de-DE:
//    Local date and time: Dienstag, Oktober 14, 2025 10:04, local
//    UTC date and time: Dienstag, Oktober 14, 2025 08:04, utc
//
// ru-RU:
//    Local date and time: вторник, октября 14, 2025 10:04, local
//    UTC date and time: вторник, октября 14, 2025 08:04, utc

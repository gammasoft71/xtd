#include <xtd/xtd>

using namespace xtd::globalization;

class program {
public:
  static auto main() {
    auto local_date = date_time::now();
    auto utc_date = date_time::utc_now();
    auto culture_names = array {"en-US", "en-GB", "fr-FR", "de-DE", "ru-RU"};
    
    for (auto culture_name : culture_names) {
      auto culture = culture_info {culture_name};
      console::write_line("{}:", culture.native_name());
      console::write_line("   Local date and time: {}, {}", local_date.to_string(culture), local_date.kind());
      console::write_line("   UTC date and time: {}, {}\n", utc_date.to_string(culture), utc_date.kind());
    }
  }
};

startup_(program::main);

// This code can produce the following output :
//
// English (United States):
//    Local date and time: 10/23/2025 0:59:10 AM, local
//    UTC date and time: 10/22/2025 10:59:10 PM, utc
//
// English (United Kingdom):
//    Local date and time: 23/10/2025 00:59:10, local
//    UTC date and time: 22/10/2025 22:59:10, utc
//
// français (France):
//    Local date and time: 23/10/2025 00:59:10, local
//    UTC date and time: 22/10/2025 22:59:10, utc
//
// Deutsch (Deutschland):
//    Local date and time: 23.10.2025 00:59:10, local
//    UTC date and time: 22.10.2025 22:59:10, utc
//
// русский (Россия):
//    Local date and time: 23.10.2025 00:59:10, local
//    UTC date and time: 22.10.2025 22:59:10, utc

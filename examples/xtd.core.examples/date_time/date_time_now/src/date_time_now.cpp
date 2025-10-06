#include <xtd/xtd>

using namespace globalization;

class program {
public:
  static auto main() {
    auto local_date = date_time::now();
    auto utc_date = date_time::utc_now();
    auto culture_names = array {"en-US", "en-GB", "fr-FR", "de-DE", "ru-RU"};
    
    for (auto culture_name : culture_names) {
      try {
        culture_info::current_culture(culture_info {culture_name});
        console::write_line("{}:", culture_name);
        console::write_line("   Local date and time: {:f}, {}", local_date, local_date.kind());
        console::write_line("   UTC date and time: {:f}, {}\n", utc_date, utc_date.kind());
      } catch (const std::exception& e) {
        console::write_line("Make sure {} locale is installed on your system :\n\n{}\n", culture_name, e);
      }
    }
  }
};

startup_(program::main);

// This code can produce the following output :
//
// en_US:
//    Local date and time: Monday, October 6, 2025 19:03, local
//    UTC date and time: Monday, October 6, 2025 17:03, utc
//
// en_GB:
//    Local date and time: Monday, October 6, 2025 19:03, local
//    UTC date and time: Monday, October 6, 2025 17:03, utc
//
// fr_FR:
//    Local date and time: lundi, octobre 6, 2025 19:03, local
//    UTC date and time: lundi, octobre 6, 2025 17:03, utc
//
// de_DE:
//    Local date and time: Montag, Oktober 6, 2025 19:03, local
//    UTC date and time: Montag, Oktober 6, 2025 17:03, utc
//
// ru_RU:
//    Local date and time: понедельник, октября 6, 2025 19:03, local
//    UTC date and time: понедельник, октября 6, 2025 17:03, utc

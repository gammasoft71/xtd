#include <xtd/xtd>

using namespace xtd::globalization;

class program {
public:
  static auto main() {
    auto local_date = date_time::now();
    auto culture_names = array {"en-US", "en-GB", "fr-FR", "de-DE", "ru-RU"};
    
    for (auto culture_name : culture_names) {
      auto culture = culture_info {culture_name};
      console::write_line("{}: {}", culture_name, local_date.to_string(culture));
    }
  }
};

startup_(program::main);

// This code can produce the following output :
//
// en-US: 10/23/2025 1:02:39 AM
// en-GB: 23/10/2025 01:02:39
// fr-FR: 23/10/2025 01:02:39
// de-DE: 23.10.2025 01:02:39
// ru-RU: 23.10.2025 01:02:39

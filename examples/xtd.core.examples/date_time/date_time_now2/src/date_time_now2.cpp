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
// en-US: 10/14/2025 10:16:33
// en-GB: 10/14/2025 10:16:33
// fr-FR: 10/14/2025 10:16:33
// de-DE: 10/14/2025 10:16:33
// ru-RU: 10/14/2025 10:16:33

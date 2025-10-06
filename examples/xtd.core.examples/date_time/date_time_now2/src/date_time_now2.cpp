#include <xtd/xtd>

using namespace globalization;

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
// en_US: 01/02/2022 10:59:07
// en_GB: 02/01/2022 10:59:07
// fr_FR: 02.01.2022 10:59:07
// de_DE: 02.01.2022 10:59:07
// ru_RU: 02.01.2022 10:59:07

#include <xtd/collections/generic/list>
#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::collections::generic;

class program {
public:
  static auto main() {
    auto local_date = date_time::now();
    auto locale_names = list {"en_US", "en_GB", "fr_FR", "de_DE", "ru_RU"};
    
    for (auto locale_name : locale_names) {
      try {
        std::locale::global(std::locale {locale_name + ".utf-8"_s});
        console::write_line("{}: {}", locale_name, date_time::sprintf("%x %T", local_date));
      } catch (const std::exception& e) {
        console::write_line("Make sure {} locale is installed on your system :\n\n{}\n", locale_name, e);
      }
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

#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

using namespace std;
using namespace xtd;

class program {
public:
  static auto main() {
    auto local_date = date_time::now();
    auto locale_names = vector {"en_US", "en_GB", "fr_FR", "de_DE", "ru_RU"};
    
    for (auto locale_name : locale_names) {
      try {
        locale::global(locale {locale_name + ".utf-8"_s});
        console::write_line("{}: {}", locale_name, date_time::sprintf("%x %T", local_date));
      } catch (const exception& e) {
        console::write_line(ustring::format("Make sure {} locale is installed on your system :\n\n{}\n", locale_name, e.what()), "Exception");
      }
    }
  }
};

startup_(program::main);

// This code can produces the following output:
//
// en_US: 01/02/2022 10:59:07
// en_GB: 02/01/2022 10:59:07
// fr_FR: 02.01.2022 10:59:07
// de_DE: 02.01.2022 10:59:07
// ru_RU: 02.01.2022 10:59:07

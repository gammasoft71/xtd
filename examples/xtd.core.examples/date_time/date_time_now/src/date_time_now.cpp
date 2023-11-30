#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>
#include <vector>

using namespace std;
using namespace xtd;

class program {
public:
  static auto main() {
    auto local_date = date_time::now();
    auto utc_date = date_time::utc_now();
    auto locale_names = vector {"en_US", "en_GB", "fr_FR", "de_DE", "ru_RU"};
    
    for (auto locale_name : locale_names) {
      try {
        locale::global(locale {locale_name + ".utf-8"_s});
        console::write_line("{}:", locale_name);
        console::write_line("   Local date and time: {}, {}", local_date.to_string(), local_date.kind());
        console::write_line("   UTC date and time: {}, {}\n", utc_date.to_string(), utc_date.kind());
      } catch (const exception& e) {
        console::write_line(ustring::format("Make sure {} locale is installed on your system :\n\n{}\n", locale_name, e.what()), "Exception");
      }
    }
  }
};

startup_(program::main);

// This code can produces the following output:
//
// en_US
//    Local date and time: Sun Jan  2 09:50:36 2022, local
//    UTC date and time: Sun Jan  2 08:50:36 2022, utc
//
// en_GB
//    Local date and time: Sun  2 Jan 09:50:36 2022, local
//    UTC date and time: Sun  2 Jan 08:50:36 2022, utc
//
// fr_FR
//    Local date and time: Dim  2 jan 09:50:36 2022, local
//    UTC date and time: Dim  2 jan 08:50:36 2022, utc
//
// de_DE
//    Local date and time: So  2 Jan 09:50:36 2022, local
//    UTC date and time: So  2 Jan 08:50:36 2022, utc
//
// ru_RU
//    Local date and time: воскресенье,  2 января 2022 г. 09:50:36, local
//    UTC date and time: воскресенье,  2 января 2022 г. 08:50:36, utc

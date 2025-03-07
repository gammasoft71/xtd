#include <xtd/collections/generic/list>
#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::collections::generic;

class program {
public:
  static auto main() {
    auto dates = list {date_time::now(), date_time {2013, 9, 14, 9, 28, 0}, date_time {2011, 5, 28, 10, 35, 0}, date_time {1979, 12, 25, 14, 30, 0}};
    for (auto date : dates) {
      console::write_line("Day: {0:d} Time: {1:g}", date.date(), date.time_of_day());
      console::write_line("Day: {0:d} Time: {0:t}\n", date);
    }
  }
};

startup_(program::main);

// This code can produce the following output :
//
// Day: 01/12/2022 Time: 12:51:49
// Day: 01/12/2022 Time: 12:51:49
//
// Day: 09/14/2013 Time: 9:28:00
// Day: 09/14/2013 Time: 09:28:00
//
// Day: 05/28/2011 Time: 10:35:00
// Day: 05/28/2011 Time: 10:35:00
//
// Day: 12/25/1979 Time: 14:30:00
// Day: 12/25/1979 Time: 14:30:00

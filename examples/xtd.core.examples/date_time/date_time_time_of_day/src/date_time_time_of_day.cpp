#include <xtd/xtd>

class program {
public:
  static auto main() {
    auto dates = array {date_time::now(), date_time {2013, 9, 14, 9, 28, 0}, date_time {2011, 5, 28, 10, 35, 0}, date_time {1979, 12, 25, 14, 30, 0}};
    for (auto date : dates) {
      console::write_line("Day: {0:d} Time: {1:g}", date.date(), date.time_of_day());
      console::write_line("Day: {0:d} Time: {0:t}\n", date);
    }
  }
};

startup_(program::main);

// This code can produce the following output :
//
// Day: 11/6/2025 Time: 10:07:20
// Day: 11/6/2025 Time: 10:07 AM
//
// Day: 9/14/2013 Time: 9:28:00
// Day: 9/14/2013 Time: 9:28 AM
//
// Day: 5/28/2011 Time: 10:35:00
// Day: 5/28/2011 Time: 10:35 AM
//
// Day: 12/25/1979 Time: 14:30:00
// Day: 12/25/1979 Time: 2:30 PM
//

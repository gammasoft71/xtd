#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

using namespace xtd;

class program {
public:
  static auto main() {
    // Instead of using the implicit, default "G" date and time format string, we
    // use a custom format string that aligns the results and inserts leading zeroes.
    auto format = "{0}) The {1} date and time is {2:k}/{2:i}/{2:L} {2:t}";
    
    // Create a DateTime for the maximum date and time using ticks.
    auto dt1 = date_time {date_time::max_value.ticks()};
    
    // Create a DateTime for the minimum date and time using ticks.
    auto dt2 = date_time {date_time::min_value.ticks()};
    
    // Create a custom DateTime for 1/5/1971 at 21:10:30 using ticks
    auto ticks = date_time {1971, 1, 5, 21, 10, 30}.ticks();
    auto dt3 = date_time {ticks};
    
    console::write_line(format, 1, "maximum", dt1);
    console::write_line(format, 2, "minimum", dt2);
    console::write_line(format, 3, "custom ", dt3);
    console::write_line("\nThe custom date and time is created from {0} ticks.", ticks);
  }
};

startup_(program::main);

// This code can produces the following output:
//
// 1) The maximum date and time is 12/31/9999 23:59:59
// 2) The minimum date and time is 01/01/0001 00:00:00
// 3) The custom  date and time is 01/05/1971 21:10:30
//
// The custom date and time is created from 621675546300000000 ticks.

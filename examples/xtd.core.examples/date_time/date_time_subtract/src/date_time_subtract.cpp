#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

class program {
public:
  static auto main() {
    auto date1 = xtd::date_time {1996, 6, 3, 22, 15, 0};
    xtd::console::write_line("date1 = {:u}", date1);
    auto date2 = xtd::date_time {1996, 12, 6, 13, 2, 0};
    xtd::console::write_line("date2 = {:u}", date2);
    auto date3 = xtd::date_time {1996, 10, 12, 8, 42, 0};
    xtd::console::write_line("date3 = {:u}", date3);
    
    // diff1 gets 185 days, 14 hours, and 47 minutes.
    auto diff1 = date2.subtract(date1);
    xtd::console::write_line("diff1 = {}", diff1);
    
    // date4 gets 4/9/1996 5:55:00 PM.
    auto date4 = date3.subtract(diff1);
    xtd::console::write_line("date4 = {:u}", date4);
    
    // diff2 gets 55 days 4 hours and 20 minutes.
    auto diff2 = date2 - date3;
    xtd::console::write_line("diff2 = {}", diff2);
    
    // date5 gets 4/9/1996 5:55:00 PM.
    auto date5 = date1 - diff2;
    xtd::console::write_line("date5 = {:u}", date5);
  }
};

startup_(program::main);

// This code produces the following output :
//
// date1 = 1996-06-03 20:15:00Z
// date2 = 1996-12-06 12:02:00Z
// date3 = 1996-10-12 06:42:00Z
// diff1 = 185.14:47:00
// date4 = 1996-04-09 15:55:00Z
// diff2 = 55.04:20:00
// date5 = 1996-04-09 15:55:00Z

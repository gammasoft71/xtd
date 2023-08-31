#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

class program {
public:
  static auto main() {
    auto days_in_july = xtd::date_time::days_in_month(2001, xtd::month_of_year::july);
    xtd::console::write_line(days_in_july);
    
    // days_in_feb gets 28 because the year 1998 was not a leap year.
    auto days_in_feb = xtd::date_time::days_in_month(1998, xtd::month_of_year::february);
    xtd::console::write_line(days_in_feb);
    
    // days_in_feb_leap gets 29 because the year 1996 was a leap year.
    auto days_in_feb_leap = xtd::date_time::days_in_month(1996, xtd::month_of_year::february);
    xtd::console::write_line(days_in_feb_leap);
  }
};

startup_(program::main);

// This code can produces the following output:
//
// 31
// 28
// 29

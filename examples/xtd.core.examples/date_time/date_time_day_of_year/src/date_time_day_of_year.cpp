#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

using namespace xtd;

class program {
public:
  static auto main() {
    auto dec31 = date_time {2010, 12, 31};
    for (auto ctr = 0u; ctr <= 10u; ctr++) {
      auto date_to_display = dec31.add_years(ctr);
      console::write_line("{0:d}: day {1} of {2} {3}", date_to_display, date_to_display.day_of_year(), date_to_display.year(), date_time::is_leap_year(date_to_display.year()) ? "(Leap Year)" : "");
    }
  }
};

startup_(program::main);

// This code can produces the following output:
//
// 12/31/2010: day 365 of 2010
// 12/31/2011: day 365 of 2011
// 12/31/2012: day 366 of 2012 (Leap Year)
// 12/31/2013: day 365 of 2013
// 12/31/2014: day 365 of 2014
// 12/31/2015: day 365 of 2015
// 12/31/2016: day 366 of 2016 (Leap Year)
// 12/31/2017: day 365 of 2017
// 12/31/2018: day 365 of 2018
// 12/31/2019: day 365 of 2019
// 12/31/2020: day 366 of 2020 (Leap Year)

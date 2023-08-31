#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>
#include <xtd/ustring>

using namespace xtd;

class program {
public:
  static auto main() {
    auto date_format = "{0:d}/{0:t}.{0:c}"_s;
    auto date1 = date_time {2014, 9, 8, 16, 0, 0};
    console::write_line("Original date: {0} ({1:N0} ticks)\n", ustring::format(date_format, date1), date1.ticks());
    
    auto date2 = date1.add_seconds(30);
    console::write_line("Second date:   {0} ({1:N0} ticks)", ustring::format(date_format, date2), date2.ticks());
    console::write_line("Difference between dates: {0} ({1:N0} ticks)\n", date2 - date1, date2.ticks() - date1.ticks());
    
    // Add 1 day's worth of seconds (60 secs. * 60 mins * 24 hrs.r
    auto date3 = date1.add_seconds(60 * 60 * 24);
    console::write_line("Third date:    {0} ({1:N0} ticks)", ustring::format(date_format, date3), date3.ticks());
    console::write_line("Difference between dates: {0} ({1:N0} ticks)", date3 - date1, date3.ticks() - date1.ticks());
  }
};

startup_(program::main);

// This code can produces the following output:
//
// Original date: 09/08/2014/16:00:00.0000000 (635457888000000000 ticks)
//
// Second date:   09/08/2014/16:00:30.0000000 (635457888300000000 ticks)
// Difference between dates: 00:00:30 (300000000 ticks)
//
// Third date:    09/09/2014/16:00:00.0000000 (635458752000000000 ticks)
// Difference between dates: 1.00:00:00 (864000000000 ticks)

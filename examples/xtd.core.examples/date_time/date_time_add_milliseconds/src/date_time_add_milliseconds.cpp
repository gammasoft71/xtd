#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>
#include <xtd/string>

using namespace xtd;

class program {
public:
  static auto main() {
    auto date_format = "{0:d}/{0:t}.{0:c}"_s;
    auto date1 = date_time {2010, 9, 8, 16, 0, 0};
    console::write_line("Original date: {0} ({1:N0} ticks)\n", string::format(date_format, date1), date1.ticks());
    
    auto date2 = date1.add_milliseconds(1);
    console::write_line("Second date:   {0} ({1:N0} ticks)", string::format(date_format, date2), date2.ticks());
    console::write_line("Difference between dates: {0} ({1:N0} ticks)\n", date2 - date1, date2.ticks() - date1.ticks());
    
    auto date3 = date1.add_milliseconds(1.5);
    console::write_line("Third date:    {0} ({1:N0} ticks)", string::format(date_format, date3), date3.ticks());
    console::write_line("Difference between dates: {0} ({1:N0} ticks)", date3 - date1, date3.ticks() - date1.ticks());
  }
};

startup_(program::main);

// This code produces the following output :
//
// Original date: 09/08/2010/16:00:00.0000000 (634195584000000000 ticks)
//
// Second date:   09/08/2010/16:00:00.0000000 (634195584000009984 ticks)
// Difference between dates: 00:00:00.0010000 (10000 ticks)
//
// Third date:    09/08/2010/16:00:00.0005000 (634195584000014976 ticks)
// Difference between dates: 00:00:00.0015000 (15000 ticks)

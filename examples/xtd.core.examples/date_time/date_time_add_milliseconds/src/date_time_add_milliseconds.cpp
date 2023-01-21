#include <xtd/xtd>

using namespace std;
using namespace xtd;

class program {
public:
  static auto main() {
    ustring date_format = "{0:d}/{0:t}.{0:c}";
    date_time date1(2010, 9, 8, 16, 0, 0);
    console::write_line("Original date: {0} ({1:N0} ticks)\n", ustring::format(date_format, date1), date1.ticks().count());
    
    date_time date2 = date1.add_milliseconds(1);
    console::write_line("Second date:   {0} ({1:N0} ticks)", ustring::format(date_format, date2), date2.ticks().count());
    console::write_line("Difference between dates: {0} ({1:N0} ticks)\n", date2 - date1, (date2.ticks() - date1.ticks()).count());
    
    date_time date3 = date1.add_milliseconds(1.5);
    console::write_line("Third date:    {0} ({1:N0} ticks)", ustring::format(date_format, date3), date3.ticks().count());
    console::write_line("Difference between dates: {0} ({1:N0} ticks)", date3 - date1, (date3.ticks() - date1.ticks()).count());
  }
};

startup_(program);

// This code can produces the following output:
//
// Original date: 09/08/2010/16:00:00.0000000 (634195584000000000 ticks)
//
// Second date:   09/08/2010/16:00:00.0000000 (634195584000010000 ticks)
// Difference between dates: Mon Jan  1 00:00:00 0001 (10000 ticks)
//
// Third date:    09/08/2010/16:00:00.0005000 (634195584000015000 ticks)
// Difference between dates: Mon Jan  1 00:00:00 0001 (15000 ticks)

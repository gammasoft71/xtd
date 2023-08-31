#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

using namespace xtd;

class program {
public:
  static auto main() {
    auto date1 = date_time {2008, 6, 1, 7, 47, 0};
    console::write_line(date1.to_string());
    
    // Get date-only portion of date, without its time.
    auto date_only = date1.date();
    // Display date using short date string.
    console::write_line(date_only.to_string("d"));
    // Display date using 24-hour clock.
    console::write_line(date_only.to_string("g"));
    console::write_line(date_only.to_string("u"));
  }
};

startup_(program::main);

// This code can produces the following output:
// Sun Jun  1 07:47:00 2008
// 06/01/2008
// Sun Jun  1 00:00:00 2008
// 2008-06-01 00:00:00

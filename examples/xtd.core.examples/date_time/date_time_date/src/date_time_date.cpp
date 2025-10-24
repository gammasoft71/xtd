#include <xtd/xtd>

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
    console::write_line(date_only.to_string("MM/dd/yyyy HH:mm"));
  }
};

startup_(program::main);

// This code produces the following output :
//
// 6/1/2008 7:47:00 AM
// 6/1/2008
// 6/1/2008 0:00 AM
// 06/01/2008 00:00

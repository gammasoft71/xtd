#include <xtd/xtd>

class program {
public:
  static auto main() {
    auto hours = list {.08333, .16667, .25, .33333, .5, .66667, 1.0, 2.0, 29.0, 30.0, 31.0, 90.0, 365.0};
    auto date_value = date_time {2009, 3, 1, 12, 0, 0};
    
    for (auto hour : hours)
      console::write_line("{0} + {1} hour(s) = {2}", date_value, hour, date_value.add_hours(hour));
  }
};

startup_(program::main);

// This code produces the following output :
//
// 3/1/2009 12:00:00 PM + 0.08333 hour(s) = 3/1/2009 12:04:59 PM
// 3/1/2009 12:00:00 PM + 0.16667 hour(s) = 3/1/2009 12:10:00 PM
// 3/1/2009 12:00:00 PM + 0.25 hour(s) = 3/1/2009 12:15:00 PM
// 3/1/2009 12:00:00 PM + 0.33333 hour(s) = 3/1/2009 12:19:59 PM
// 3/1/2009 12:00:00 PM + 0.5 hour(s) = 3/1/2009 12:30:00 PM
// 3/1/2009 12:00:00 PM + 0.66667 hour(s) = 3/1/2009 12:40:00 PM
// 3/1/2009 12:00:00 PM + 1 hour(s) = 3/1/2009 1:00:00 PM
// 3/1/2009 12:00:00 PM + 2 hour(s) = 3/1/2009 2:00:00 PM
// 3/1/2009 12:00:00 PM + 29 hour(s) = 3/2/2009 5:00:00 PM
// 3/1/2009 12:00:00 PM + 30 hour(s) = 3/2/2009 6:00:00 PM
// 3/1/2009 12:00:00 PM + 31 hour(s) = 3/2/2009 7:00:00 PM
// 3/1/2009 12:00:00 PM + 90 hour(s) = 3/5/2009 6:00:00 AM
// 3/1/2009 12:00:00 PM + 365 hour(s) = 3/16/2009 5:00:00 PM

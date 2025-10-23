#include <xtd/xtd>

class program {
public:
  static auto main() {
    auto date_value = date_time {2013, 9, 15, 12, 0, 0};
    auto minutes = list {.01667, .08333, .16667, .25, .33333, .5, .66667, 1.0, 2.0, 15.0, 30.0, 17.0, 45.0, 60.0, 180.0, 60.0 * 24.0};
    
    for (auto minute : minutes)
      console::write_line("{0} + {1} minute(s) = {2}", date_value, minute, date_value.add_minutes(minute));
  }
};

startup_(program::main);

// This code produces the following output :
//
// 9/15/2013 12:00:00 PM + 0.01667 minute(s) = 9/15/2013 12:00:01 PM
// 9/15/2013 12:00:00 PM + 0.08333 minute(s) = 9/15/2013 12:00:04 PM
// 9/15/2013 12:00:00 PM + 0.16667 minute(s) = 9/15/2013 12:00:10 PM
// 9/15/2013 12:00:00 PM + 0.25 minute(s) = 9/15/2013 12:00:15 PM
// 9/15/2013 12:00:00 PM + 0.33333 minute(s) = 9/15/2013 12:00:19 PM
// 9/15/2013 12:00:00 PM + 0.5 minute(s) = 9/15/2013 12:00:30 PM
// 9/15/2013 12:00:00 PM + 0.66667 minute(s) = 9/15/2013 12:00:40 PM
// 9/15/2013 12:00:00 PM + 1 minute(s) = 9/15/2013 12:01:00 PM
// 9/15/2013 12:00:00 PM + 2 minute(s) = 9/15/2013 12:02:00 PM
// 9/15/2013 12:00:00 PM + 15 minute(s) = 9/15/2013 12:15:00 PM
// 9/15/2013 12:00:00 PM + 30 minute(s) = 9/15/2013 12:30:00 PM
// 9/15/2013 12:00:00 PM + 17 minute(s) = 9/15/2013 12:17:00 PM
// 9/15/2013 12:00:00 PM + 45 minute(s) = 9/15/2013 12:45:00 PM
// 9/15/2013 12:00:00 PM + 60 minute(s) = 9/15/2013 1:00:00 PM
// 9/15/2013 12:00:00 PM + 180 minute(s) = 9/15/2013 3:00:00 PM
// 9/15/2013 12:00:00 PM + 1440 minute(s) = 9/16/2013 12:00:00 PM

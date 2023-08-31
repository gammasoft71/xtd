#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>
#include <vector>

using namespace std;
using namespace xtd;

class program {
public:
  static auto main() {
    auto date_value = date_time {2013, 9, 15, 12, 0, 0};
    auto minutes = vector {.01667, .08333, .16667, .25, .33333, .5, .66667, 1.0, 2.0, 15.0, 30.0, 17.0, 45.0, 60.0, 180.0, 60.0 * 24.0};
    
    for (auto minute : minutes)
      console::write_line("{0:u} + {1} minute(s) = {2:u}", date_value, minute, date_value.add_minutes(minute));
  }
};

startup_(program::main);

// This code can produces the following output:
//
// 2013-09-15 12:00:00 + 0.01667 minute(s) = 2013-09-15 12:00:01
// 2013-09-15 12:00:00 + 0.08333 minute(s) = 2013-09-15 12:00:04
// 2013-09-15 12:00:00 + 0.16667 minute(s) = 2013-09-15 12:00:10
// 2013-09-15 12:00:00 + 0.25 minute(s) = 2013-09-15 12:00:15
// 2013-09-15 12:00:00 + 0.33333 minute(s) = 2013-09-15 12:00:19
// 2013-09-15 12:00:00 + 0.5 minute(s) = 2013-09-15 12:00:30
// 2013-09-15 12:00:00 + 0.66667 minute(s) = 2013-09-15 12:00:40
// 2013-09-15 12:00:00 + 1 minute(s) = 2013-09-15 12:01:00
// 2013-09-15 12:00:00 + 2 minute(s) = 2013-09-15 12:02:00
// 2013-09-15 12:00:00 + 15 minute(s) = 2013-09-15 12:15:00
// 2013-09-15 12:00:00 + 30 minute(s) = 2013-09-15 12:30:00
// 2013-09-15 12:00:00 + 17 minute(s) = 2013-09-15 12:17:00
// 2013-09-15 12:00:00 + 45 minute(s) = 2013-09-15 12:45:00
// 2013-09-15 12:00:00 + 60 minute(s) = 2013-09-15 13:00:00
// 2013-09-15 12:00:00 + 180 minute(s) = 2013-09-15 15:00:00
// 2013-09-15 12:00:00 + 1440 minute(s) = 2013-09-16 12:00:00

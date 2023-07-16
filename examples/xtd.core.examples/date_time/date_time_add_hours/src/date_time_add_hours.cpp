#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>
#include <vector>

using namespace std;
using namespace xtd;

class program {
public:
  static auto main() {
    auto hours = vector {.08333, .16667, .25, .33333, .5, .66667, 1.0, 2.0, 29.0, 30.0, 31.0, 90.0, 365.0};
    auto date_value = date_time {2009, 3, 1, 12, 0, 0};
    
    for (auto hour : hours)
      console::write_line("{0:u} + {1} hour(s) = {2:u}", date_value, hour, date_value.add_hours(hour));
  }
};

startup_(program);

// This code can produces the following output:
//
// 2009-03-01 12:00:00 + 0.08333 hour(s) = 2009-03-01 12:04:59
// 2009-03-01 12:00:00 + 0.16667 hour(s) = 2009-03-01 12:10:00
// 2009-03-01 12:00:00 + 0.25 hour(s) = 2009-03-01 12:15:00
// 2009-03-01 12:00:00 + 0.33333 hour(s) = 2009-03-01 12:19:59
// 2009-03-01 12:00:00 + 0.5 hour(s) = 2009-03-01 12:30:00
// 2009-03-01 12:00:00 + 0.66667 hour(s) = 2009-03-01 12:40:00
// 2009-03-01 12:00:00 + 1 hour(s) = 2009-03-01 13:00:00
// 2009-03-01 12:00:00 + 2 hour(s) = 2009-03-01 14:00:00
// 2009-03-01 12:00:00 + 29 hour(s) = 2009-03-02 17:00:00
// 2009-03-01 12:00:00 + 30 hour(s) = 2009-03-02 18:00:00
// 2009-03-01 12:00:00 + 31 hour(s) = 2009-03-02 19:00:00
// 2009-03-01 12:00:00 + 90 hour(s) = 2009-03-05 06:00:00
// 2009-03-01 12:00:00 + 365 hour(s) = 2009-03-16 17:00:00

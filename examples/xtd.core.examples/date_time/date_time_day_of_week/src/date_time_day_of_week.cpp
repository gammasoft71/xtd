#include <xtd/xtd>

using namespace xtd;

class program {
public:
  static auto main() {
    // Create a DateTime for the first of May, 2003.
    date_time dt(2003, 5, 1);
    console::write_line("Is Thursday the day of the week for {0:d}?: {1}", dt, dt.day_of_week() == day_of_week::thursday);
    console::write_line("The day of the week for {0:d} is {1}.", dt, dt.day_of_week());
  }
};

startup_(program);

// This code can produces the following output:
//
// Is Thursday the day of the week for 05/01/2003?: true
// The day of the week for 05/01/2003 is thursday.

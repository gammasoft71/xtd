#include <xtd/xtd>

using namespace std::chrono;
using namespace xtd;

class program {
public:
  static auto main() {
    // Attempt to assign an out-of-range value to a date_time constructor.
    ticks number_of_ticks = ticks::max();
    date_time valid_date;
    
    // Validate the value.
    if (number_of_ticks >= date_time::min_value.ticks() && number_of_ticks <= date_time::max_value.ticks()) {
      valid_date = date_time(number_of_ticks);
      console::write_line("{0} is valid.", valid_date.ticks().count());
    } else if (number_of_ticks < date_time::min_value.ticks())
      console::write_line("{0} is less than {1} ticks.", number_of_ticks.count(), date_time::min_value.ticks().count());
    else
      console::write_line("{0} is greater than {1} ticks.", number_of_ticks.count(), date_time::max_value.ticks().count());
  }
};

startup_(program);

// This code can produces the following output:
//
// 9223372036854775807 is greater than 3155378975999999999 ticks.

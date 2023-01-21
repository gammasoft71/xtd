#include <xtd/xtd>

class program {
public:
  static auto main() {
    // Calculate what day of the week is 36 days from this instant.
    xtd::date_time today = xtd::date_time::now();
    xtd::date_time answer = today.add_days(36);
    xtd::console::write_line("{0}", today);
    xtd::console::write_line("{0}", answer);
  }
};

startup_(program);

// This code can produces the following output:
//
// Wed Jan 12 14:06:34 2022
// Thu Feb 17 14:06:34 2022

#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

using namespace xtd;

class program {
public:
  static auto main() {
    // Get the current date.
    auto this_day = date_time::today();
    // Display the date in the default (general) format.
    console::write_line(this_day.to_string());
    console::write_line();
    // Display the date in a variety of formats.
    console::write_line(this_day.to_string("d"));
    console::write_line(this_day.to_string("D"));
    console::write_line(this_day.to_string("g"));
  }
};

startup_(program::main);

// This code can produces the following output:
//
// Wed Jan 12 00:00:00 2022
//
// 01/12/2022
// 1/12/2022
// Wed Jan 12 00:00:00 2022

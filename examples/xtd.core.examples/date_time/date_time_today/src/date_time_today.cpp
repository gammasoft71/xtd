#include <xtd/xtd>

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

// This code can produce the following output :
//
// 11/5/2025 0:00:00 AM
//
// 11/5/2025
// Wednesday, November 5, 2025
// 11/5/2025 0:00 AM

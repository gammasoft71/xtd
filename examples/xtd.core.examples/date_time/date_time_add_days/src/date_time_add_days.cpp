#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

class program {
public:
  static auto main() {
    // Calculate what day of the week is 36 days from this instant.
    auto today = xtd::date_time::now();
    auto answer = today.add_days(36);
    xtd::console::write_line("{0}", today);
    xtd::console::write_line("{0}", answer);
  }
};

startup_(program::main);

// This code can produce the following output :
//
// 10/23/2025 1:06:35 AM
// 11/28/2025 1:06:35 AM

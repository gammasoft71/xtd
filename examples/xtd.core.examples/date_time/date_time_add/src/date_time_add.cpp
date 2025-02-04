#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>
#include <chrono>

class program {
public:
  static auto main() {
    // Calculate what day of the week is 36 days from this instant.
    auto today = xtd::date_time::now();
    auto duration = std::chrono::days {36};
    auto answer = today.add(duration);
    xtd::console::write_line("{0}", today);
    xtd::console::write_line("{0}", answer);
  }
};

startup_(program::main);

// This code can produce the following output :
//
// 2025-02-04 21:53:13
// 2025-03-12 21:53:13

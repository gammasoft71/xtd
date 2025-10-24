#include <xtd/xtd>

class program {
public:
  static auto main() {
    // Define an uninitialized date.
    auto date1 = date_time {};
    console::write(date1);
    if (date1.equals(date_time::min_value))
      console::write_line("  (equals date_time::min_value)");
  }
};

startup_(program::main);

// This code produces the following output :
//
// 1/1/0001 0:00:00 AM  (equals date_time::min_value)

#include <xtd/xtd>

class program {
public:
  static auto main() {
    // Define an uninitialized date.
    auto date1 = date_time {};
    console::write("{:u}", date1);
    if (date1.equals(date_time::min_value))
      console::write_line("  (Equals date_time.min_value)");
  }
};

startup_(program::main);

// This code produces the following output :
//
// 01/01/0001 00:00:00  (Equals date_time.min_value)

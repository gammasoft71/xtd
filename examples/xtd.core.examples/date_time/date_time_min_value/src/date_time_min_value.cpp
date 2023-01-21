#include <xtd/xtd>

using namespace std::chrono;
using namespace xtd;

class program {
public:
  static auto main() {
    // Define an uninitialized date.
    date_time date1;
    console::write("{:u}", date1);
    if (date1.equals(date_time::min_value))
      console::write_line("  (Equals date_time.min_value)");
  }
};

startup_(program);

// This code can produces the following output:
//
// 01/01/0001 00:00:00  (Equals date_time.min_value)

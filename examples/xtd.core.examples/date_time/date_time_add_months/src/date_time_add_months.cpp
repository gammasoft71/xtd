#include <xtd/xtd>

class program {
public:
  static auto main() {
    auto date = date_time {2015, 12, 31};
    for (auto ctr = 0; ctr <= 15; ctr++)
      console::write_line(date.add_months(ctr).to_string("d"));
  }
};

startup_(program::main);

// This code produces the following output :
//
// 12/31/2015
// 1/31/2016
// 2/29/2016
// 3/31/2016
// 4/30/2016
// 5/31/2016
// 6/30/2016
// 7/31/2016
// 8/31/2016
// 9/30/2016
// 10/31/2016
// 11/30/2016
// 12/31/2016
// 1/31/2017
// 2/28/2017
// 3/31/2017

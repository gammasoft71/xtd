#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

using namespace xtd;

class program {
public:
  static auto main() {
    auto dat = date_time {2015, 12, 31};
    for (auto ctr = 0; ctr <= 15; ctr++)
      console::write_line(dat.add_months(ctr).to_string("d"));
  }
};

startup_(program);

// This code can produces the following output:
//
// 12/31/2015
// 01/31/2016
// 02/29/2016
// 03/31/2016
// 04/30/2016
// 05/31/2016
// 06/30/2016
// 07/31/2016
// 08/31/2016
// 09/30/2016
// 10/31/2016
// 11/30/2016
// 12/31/2016
// 01/31/2017
// 02/28/2017
// 03/31/2017

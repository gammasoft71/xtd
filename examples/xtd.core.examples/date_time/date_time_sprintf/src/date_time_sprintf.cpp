#include <xtd/console>
#include <xtd/date_time>
#include <xtd/startup>

using namespace xtd;

class program {
public:
  static auto main() {
    auto date1 = date_time {2008, 4, 1, 18, 7, 5, 16};
    console::write_line(date_time::sprintf("%a", date1));  // Tue
    console::write_line(date_time::sprintf("%A", date1));  // Tuesday
    console::write_line(date_time::sprintf("%b", date1));  // Apr
    console::write_line(date_time::sprintf("%B", date1));  // April
    console::write_line(date_time::sprintf("%c", date1));  // Tue Apr  1 18:07:05 2008
    console::write_line(date_time::sprintf("%C", date1));  // 20
    console::write_line(date_time::sprintf("%d", date1));  // 01
    console::write_line(date_time::sprintf("%D", date1));  // 04/01/08
    console::write_line(date_time::sprintf("%e", date1));  //  1
    console::write_line(date_time::sprintf("%Ec", date1)); // Tue Apr  1 18:07:05 2008
    console::write_line(date_time::sprintf("%EC", date1)); // 20
    console::write_line(date_time::sprintf("%Ex", date1)); // 04/01/08
    console::write_line(date_time::sprintf("%EX", date1)); // 18:07:05
    console::write_line(date_time::sprintf("%Ey", date1)); // 08
    console::write_line(date_time::sprintf("%EY", date1)); // 2008
    console::write_line(date_time::sprintf("%F", date1));  // 2008-04-01
    console::write_line(date_time::sprintf("%g", date1));  // 08
    console::write_line(date_time::sprintf("%G", date1));  // 2008
    console::write_line(date_time::sprintf("%h", date1));  // Apr
    console::write_line(date_time::sprintf("%H", date1));  // 18
    console::write_line(date_time::sprintf("%I", date1));  // 06
    console::write_line(date_time::sprintf("%j", date1));  // 093
    console::write_line(date_time::sprintf("%m", date1));  // 04
    console::write_line(date_time::sprintf("%M", date1));  // 07
    console::write_line(date_time::sprintf("%p", date1));  // PM
    console::write_line(date_time::sprintf("%r", date1));  // 06:07:05 PM
    console::write_line(date_time::sprintf("%R", date1));  // 18:07
    console::write_line(date_time::sprintf("%S", date1));  // 05
    console::write_line(date_time::sprintf("%T", date1));  // 18:07:05
    console::write_line(date_time::sprintf("%u", date1));  // 2
    console::write_line(date_time::sprintf("%U", date1));  // 13
    console::write_line(date_time::sprintf("%V", date1));  // 14
    console::write_line(date_time::sprintf("%w", date1));  // 2
    console::write_line(date_time::sprintf("%W", date1));  // 14
    console::write_line(date_time::sprintf("%x", date1));  // 04/01/08
    console::write_line(date_time::sprintf("%X", date1));  // 18:07:05
    console::write_line(date_time::sprintf("%y", date1));  // 08
    console::write_line(date_time::sprintf("%Y", date1));  // 2008
    console::write_line(date_time::sprintf("%z", date1));  // +0100
    console::write_line(date_time::sprintf("%Z", date1));  // CET
    console::write_line(date_time::sprintf("%Od", date1)); // 01
    console::write_line(date_time::sprintf("%Oe", date1)); //  1
    console::write_line(date_time::sprintf("%OH", date1)); // 18
    console::write_line(date_time::sprintf("%OI", date1)); // 06
    console::write_line(date_time::sprintf("%Om", date1)); // 04
    console::write_line(date_time::sprintf("%OM", date1)); // 07
    console::write_line(date_time::sprintf("%OS", date1)); // 05
    console::write_line(date_time::sprintf("%Ou", date1)); // 2
    console::write_line(date_time::sprintf("%OU", date1)); // 13
    console::write_line(date_time::sprintf("%OV", date1)); // 14
    console::write_line(date_time::sprintf("%Ow", date1)); // 2
    console::write_line(date_time::sprintf("%OW", date1)); // 14
    console::write_line(date_time::sprintf("%Oy", date1)); // 08
  }
};

startup_(program::main);

// This code can produces the following output:
//
// Tue
// Tuesday
// Apr
// April
// Tue Apr  1 18:07:05 2008
// 20
// 01
// 04/01/08
//  1
// Tue Apr  1 18:07:05 2008
// 20
// 04/01/08
// 18:07:05
// 08
// 2008
// 2008-04-01
// 08
// 2008
// Apr
// 18
// 06
// 093
// 04
// 07
// PM
// 06:07:05 PM
// 18:07
// 05
// 18:07:05
// 2
// 13
// 14
// 2
// 14
// 04/01/08
// 18:07:05
// 08
// 2008
// +0100
// CET
// 01
//  1
// 18
// 06
// 04
// 07
// 05
// 2
// 13
// 14
// 2
// 14
// 08

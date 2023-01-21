#include <xtd/xtd>

using namespace xtd;

class program {
public:
  static auto main() {
    date_time date1(2008, 4, 1, 18, 7, 5, 16);
    console::write_line(date1.sprintf("%a"));  // Tue
    console::write_line(date1.sprintf("%A"));  // Tuesday
    console::write_line(date1.sprintf("%b"));  // Apr
    console::write_line(date1.sprintf("%B"));  // April
    console::write_line(date1.sprintf("%c"));  // Tue Apr  1 18:07:05 2008
    console::write_line(date1.sprintf("%C"));  // 20
    console::write_line(date1.sprintf("%d"));  // 01
    console::write_line(date1.sprintf("%D"));  // 04/01/08
    console::write_line(date1.sprintf("%e"));  //  1
    console::write_line(date1.sprintf("%Ec")); // Tue Apr  1 18:07:05 2008
    console::write_line(date1.sprintf("%EC")); // 20
    console::write_line(date1.sprintf("%Ex")); // 04/01/08
    console::write_line(date1.sprintf("%EX")); // 18:07:05
    console::write_line(date1.sprintf("%Ey")); // 08
    console::write_line(date1.sprintf("%EY")); // 2008
    console::write_line(date1.sprintf("%F"));  // 2008-04-01
    console::write_line(date1.sprintf("%g"));  // 08
    console::write_line(date1.sprintf("%G"));  // 2008
    console::write_line(date1.sprintf("%h"));  // Apr
    console::write_line(date1.sprintf("%H"));  // 18
    console::write_line(date1.sprintf("%I"));  // 06
    console::write_line(date1.sprintf("%j"));  // 093
    console::write_line(date1.sprintf("%m"));  // 04
    console::write_line(date1.sprintf("%M"));  // 07
    console::write_line(date1.sprintf("%p"));  // PM
    console::write_line(date1.sprintf("%r"));  // 06:07:05 PM
    console::write_line(date1.sprintf("%R"));  // 18:07
    console::write_line(date1.sprintf("%S"));  // 05
    console::write_line(date1.sprintf("%T"));  // 18:07:05
    console::write_line(date1.sprintf("%u"));  // 2
    console::write_line(date1.sprintf("%U"));  // 13
    console::write_line(date1.sprintf("%V"));  // 14
    console::write_line(date1.sprintf("%w"));  // 2
    console::write_line(date1.sprintf("%W"));  // 14
    console::write_line(date1.sprintf("%x"));  // 04/01/08
    console::write_line(date1.sprintf("%X"));  // 18:07:05
    console::write_line(date1.sprintf("%y"));  // 08
    console::write_line(date1.sprintf("%Y"));  // 2008
    console::write_line(date1.sprintf("%z"));  // +0100
    console::write_line(date1.sprintf("%Z"));  // CET
    console::write_line(date1.sprintf("%Od")); // 01
    console::write_line(date1.sprintf("%Oe")); //  1
    console::write_line(date1.sprintf("%OH")); // 18
    console::write_line(date1.sprintf("%OI")); // 06
    console::write_line(date1.sprintf("%Om")); // 04
    console::write_line(date1.sprintf("%OM")); // 07
    console::write_line(date1.sprintf("%OS")); // 05
    console::write_line(date1.sprintf("%Ou")); // 2
    console::write_line(date1.sprintf("%OU")); // 13
    console::write_line(date1.sprintf("%OV")); // 14
    console::write_line(date1.sprintf("%Ow")); // 2
    console::write_line(date1.sprintf("%OW")); // 14
    console::write_line(date1.sprintf("%Oy")); // 08
  }
};

startup_(program);

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

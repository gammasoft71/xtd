#include <xtd/xtd>

class program {
public:
  static auto main() {
    auto date_value = date_time {2008, 6, 15, 21, 15, 07};

    // Create an array of standard format strings.
    auto standard_fmts = {"%a", "%A", "%b", "%B", "%c", "%C", "%d", "%D", "%e", "%Ec", "%EC", "%Ex", "%EX", "%Ey",
      "%EY", "%F", "%g", "%G", "%h", "%H", "%I", "%j", "%m", "%M", "%p", "%r", "%R", "%S", "%T", "%u", "%U", "%V",
      "%w", "%W", "%x", "%X", "%y", "%Y", "%z", "%Z", "%Od", "%Oe", "%OH", "%OI", "%Om", "%OM", "%OS", "%Ou",
      "%OU", "%OV", "%Ow", "%OW", "%Oy"};
    // Output date and time using each standard format string.
    for (auto standard_fmt : standard_fmts)
      console::write_line("{}: {}", standard_fmt, date_time::sprintf(standard_fmt, date_value));
    console::write_line();

    // Create an array of some custom format strings.
    auto custom_fmts = {"%I:%M:%S %p", "%e %b %G", "%H:%M:%S", "%e %b %H:%M:%S", "%%Month: %m", "%H:%M:%S%z"};
    // Output date and time using each custom format string.
    for (auto custom_fmt : custom_fmts)
      console::write_line("'{0}': {1}", custom_fmt, date_time::sprintf(custom_fmt, date_value));
  }
};

startup_(program::main);

// This code produces the following output :
//
// %a: Sun
// %A: Sunday
// %b: Jun
// %B: June
// %c: Sun Jun 15 21:15:07 2008
// %C: 20
// %d: 15
// %D: 06/15/08
// %e: 15
// %Ec: Sun Jun 15 21:15:07 2008
// %EC: 20
// %Ex: 06/15/08
// %EX: 21:15:07
// %Ey: 08
// %EY: 2008
// %F: 2008-06-15
// %g: 08
// %G: 2008
// %h: Jun
// %H: 21
// %I: 09
// %j: 168
// %m: 06
// %M: 15
// %p: PM
// %r: 09:15:07 PM
// %R: 21:15
// %S: 07
// %T: 21:15:07
// %u: 7
// %U: 24
// %V: 24
// %w: 0
// %W: 24
// %x: 06/15/08
// %X: 21:15:07
// %y: 08
// %Y: 2008
// %z: +0100
// %Z: CET
// %Od: 15
// %Oe: 15
// %OH: 21
// %OI: 09
// %Om: 06
// %OM: 15
// %OS: 07
// %Ou: 7
// %OU: 24
// %OV: 24
// %Ow: 0
// %OW: 24
// %Oy: 08
//
// '%I:%M:%S %p': 09:15:07 PM
// '%e %b %G': 15 Jun 2008
// '%H:%M:%S': 21:15:07
// '%e %b %H:%M:%S': 15 Jun 21:15:07
// '%%Month: %m': %Month: 06
// '%H:%M:%S%z': 21:15:07+0100

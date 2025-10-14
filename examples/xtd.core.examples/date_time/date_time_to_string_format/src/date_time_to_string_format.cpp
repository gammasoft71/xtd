#include <xtd/xtd>

class program {
public:
  static auto main() {
    auto date_value = date_time {2008, 6, 15, 21, 15, 07};
    // Create an array of standard format strings.
    auto standard_fmts = {"d", "D", "f", "F", "g", "G", "m", "o", "R", "s", "t", "T", "u", "U", "y"};
    // Output date and time using each standard format string.
    for (auto standard_fmt : standard_fmts)
      console::write_line("{}: {}", standard_fmt, date_value.to_string(standard_fmt));
    console::write_line();
    
    // Create an array of some custom format strings.
    auto custom_fmts = {"h:mm:ss.ff t", "d MMM yyyy", "HH:mm:ss.f", "dd MMM HH:mm:ss", "\\Mon\\t\\h\\: M", "HH:mm:ss.ffffzzz"};
    // Output date and time using each custom format string.
    for (auto custom_fmt : custom_fmts)
      console::write_line("'{0}': {1}", custom_fmt, date_value.to_string(custom_fmt));
    console::write_line();

    // Create an array of some put time format strings.
    auto put_time_fmts = {"%I:%M:%S %p", "%e %b %G", "%H:%M:%S", "%e %b %H:%M:%S", "%%Month: %m", "%H:%M:%S%z"};
    // Output date and time using each custom format string.
    for (auto put_time_fmt : put_time_fmts)
      console::write_line("'{0}': {1}", put_time_fmt, date_value.to_string(put_time_fmt));
  }
};

startup_(program::main);

// This code produces the following output :
//
// d: 6/15/2008
// D: Sunday, June 15, 2008
// f: Sunday, June 15, 2008 21:15
// F: Sunday, June 15, 2008 21:15:07
// g: 6/15/2008 21:15
// G: 6/15/2008 21:15:07
// m: June 15
// o: 2008-06-15T21:15:07.0000000Z
// R: Sun, 15 Jun 2008 21:15:07 GMT
// s: 2008-06-15T21:15:07
// t: 21:15
// T: 21:15:07
// u: 2008-06-15 21:15:07Z
// U: Sunday, June 15, 2008 21:15:07
// y: June 2008
//
// 'h:mm:ss.ff t': 9:15:07.00 P
// 'd MMM yyyy': 15 Jun 2008
// 'HH:mm:ss.f': 21:15:07.0
// 'dd MMM HH:mm:ss': 15 Jun 21:15:07
// '\Mon\t\h\: M': Month: 6
// 'HH:mm:ss.ffffzzz': 21:15:07.0000+02:00
//
// '%I:%M:%S %p': 09:15:07 PM
// '%e %b %G': 15 Jun 2008
// '%H:%M:%S': 21:15:07
// '%e %b %H:%M:%S': 15 Jun 21:15:07
// '%%Month: %m': %Month: 06
// '%H:%M:%S%z': 21:15:07+0100

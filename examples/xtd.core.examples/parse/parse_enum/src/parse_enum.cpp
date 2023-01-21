#include <xtd/xtd>

using namespace std;
using namespace xtd;

enum_(, week_day,
  monday,
  tuesday,
  wednesday,
  thursday,
  friday,
  saturday,
  sunday
);

auto main()->int {
  week_day wd1 = parse<week_day>("wednesday");
  console::write_line(wd1);
  week_day wd2 = enum_object<>::parse<week_day>("WEDNESDAY", true);
  console::write_line(wd2);
  week_day wd3 = parse<week_day>("2");
  console::write_line(wd3);
  try {
    week_day wd4 = parse<week_day>("january");
    console::write_line(wd4);
  } catch (const exception& e) {
    console::write_line("Exception : {}", e.what());
  }
}

// This code produces the following output :
//
// wednesday
// wednesday
// wednesday
// Exception : invalid character found

#include <xtd/console>
#include <xtd/enum_struct>
#include <xtd/parse>

using namespace xtd;

enum_struct_(, week_day,
  monday,
  tuesday,
  wednesday,
  thursday,
  friday,
  saturday,
  sunday
);

auto main() -> int {
  auto wd1 = parse<week_day>("wednesday");
  console::write_line(wd1);
  auto wd2 = enum_object<>::parse<week_day>("WEDNESDAY", true);
  console::write_line(wd2);
  auto wd3 = parse<week_day>("2");
  console::write_line(wd3);
  try {
    auto wd4 = parse<week_day>("january");
    console::write_line(wd4);
  } catch (const system_exception& e) {
    console::write_line("Exception : {}", e.message());
  }
}

// This code produces the following output :
//
// wednesday
// wednesday
// wednesday
// Exception : invalid character found

#include <xtd/xtd>

using namespace std;
using namespace xtd;

enum class week_day {
  monday,
  tuesday,
  wednesday,
  thursday,
  friday,
  saturday,
  sunday
};

// Only this operator is needed for week_day enum to be recognized by ustring::format().
template<> struct xtd::enum_register<week_day> {
  explicit operator auto() const noexcept {return xtd::enum_collection<week_day> {{week_day::monday, "monday"}, {week_day::tuesday, "tuesday"}, {week_day::wednesday, "wednesday"}, {week_day::thursday, "thursday"}, {week_day::friday, "friday"}, {week_day::saturday, "saturday"}, {week_day::sunday, "sunday"}};}
};

int main() {
  week_day wd1 = parse<week_day>("wednesday");
  console::write_line(wd1);
  week_day wd2 = enum_object<>::parse<week_day>("WEDNESDAY", true);
  console::write_line(wd2);
  week_day wd3 = parse<week_day>("2");
  console::write_line(wd3);
  try {
    week_day wd4 = parse<week_day>("january");
    console::write_line(wd4);
  } catch(const exception& e) {
    console::write_line("Exception : {}", e.what());
  }
}

// This code produces the following output :
//
// wednesday
// wednesday
// wednesday
// Exception : invalid character found

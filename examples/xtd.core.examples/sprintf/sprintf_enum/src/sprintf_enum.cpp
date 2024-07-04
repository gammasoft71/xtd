#include <xtd/xtd>

using namespace std;
using namespace xtd;

enum week_day {
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
  cout << enum_object {week_day::saturday}.to_string("") << endl;
  cout << enum_object {week_day::saturday}.to_string("b") << endl;
  cout << enum_object {week_day::saturday}.to_string("B8") << endl;
  cout << enum_object {week_day::saturday}.to_string("d") << endl;
  cout << enum_object {week_day::saturday}.to_string("D2") << endl;
  cout << enum_object {week_day::saturday}.to_string("g") << endl;
  cout << enum_object {week_day::saturday}.to_string("G") << endl;
  cout << enum_object {week_day::saturday}.to_string("o") << endl;
  cout << enum_object {week_day::saturday}.to_string("O2") << endl;
  cout << enum_object {week_day::saturday}.to_string("x") << endl;
  cout << enum_object {week_day::saturday}.to_string("X2") << endl;
}

// This code produces the following output :
//
// saturday
// 101
// 00000101
// 5
// 05
// saturday
// saturday
// 5
// 05
// 5
// 05

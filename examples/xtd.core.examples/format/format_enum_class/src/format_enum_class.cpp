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

// Only this operator is needed for week_day enum class to be recognized by format()
inline ostream& operator<<(ostream& os, week_day value) {
  return os << to_string(value, {{week_day::monday, "monday"}, {week_day::tuesday, "tuesday"}, {week_day::wednesday, "wednesday"}, {week_day::thursday, "thursday"}, {week_day::friday, "friday"}, {week_day::saturday, "saturday"}, {week_day::sunday, "sunday"}});
}


int main() {
  cout << format("{} night fever", week_day::saturday) << endl;
}

// This code produces the following output with colors :
//
// saturday night fever

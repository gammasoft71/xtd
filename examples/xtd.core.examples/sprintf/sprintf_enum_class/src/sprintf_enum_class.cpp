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

template<> struct xtd::enum_register<week_day> {
  explicit operator auto() const noexcept {return xtd::enum_collection<week_day> {{week_day::monday, "monday"}, {week_day::tuesday, "tuesday"}, {week_day::wednesday, "wednesday"}, {week_day::thursday, "thursday"}, {week_day::friday, "friday"}, {week_day::saturday, "saturday"}, {week_day::sunday, "sunday"}};}
};

int main() {
  cout << ustring::sprintf("%s", enum_object {week_day::saturday}.to_string("")) << endl;
  cout << ustring::sprintf("0b%s", enum_object {week_day::saturday}.to_string("b")) << endl;
  cout << ustring::sprintf("0b%s", enum_object {week_day::saturday}.to_string("B")) << endl;
  cout << ustring::sprintf("0b%s", enum_object {week_day::saturday}.to_string("d")) << endl;
  cout << ustring::sprintf("%s", enum_object {week_day::saturday}.to_string("D")) << endl;
  cout << ustring::sprintf("%s", enum_object {week_day::saturday}.to_string("g")) << endl;
  cout << ustring::sprintf("%s", enum_object {week_day::saturday}.to_string("G")) << endl;
  cout << ustring::sprintf("0%s", enum_object {week_day::saturday}.to_string("o")) << endl;
  cout << ustring::sprintf("0%s", enum_object {week_day::saturday}.to_string("O")) << endl;
  cout << ustring::sprintf("0x%s", enum_object {week_day::saturday}.to_string("x")) << endl;
  cout << ustring::sprintf("0x%s", enum_object {week_day::saturday}.to_string("X")) << endl;
}

// This code produces the following output :
//
// saturday
// 0b101
// 0b101
// 0b5
// 5
// saturday
// saturday
// 05
// 05
// 0x5
// 0x5

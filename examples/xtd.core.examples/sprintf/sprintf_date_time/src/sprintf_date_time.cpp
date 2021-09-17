#include <ctime>
#include <xtd/xtd>

using namespace std;
using namespace xtd;

ustring date_time_to_string(const ustring& format, const tm& tm) {
  string result(255, 0);
  strftime(result.data(), result.size(), ("%" + format).c_str(), &tm);
  result.shrink_to_fit();
  return result;
}

ustring date_time_to_string(const ustring& format, const time_t& time) {
  auto tm = localtime(&time);
  return date_time_to_string(format, *tm);
}

ustring date_time_to_string(const ustring& format, const chrono::system_clock::time_point& tp) {
  auto time = std::chrono::system_clock::to_time_t(tp);
  return date_time_to_string(format, time);
}

ustring date_time_to_string(const tm& tm) {
  return date_time_to_string("c", tm);
}

ustring date_time_to_string(const time_t& time) {
  auto tm = localtime(&time);
  return date_time_to_string(*tm);
}

ustring date_time_to_string(const chrono::system_clock::time_point& tp) {
  auto time = chrono::system_clock::to_time_t(tp);
  return date_time_to_string(time);
}

int main() {
  auto date_time = std::chrono::system_clock::now();
  // Instead previous line you can use following line :
  // auto date_time = std::time(nullptr);
  // Or following lines :
  // auto t = std::time(nullptr);
  // auto date_time = *std::localtime(&t);

  cout << ustring::sprintf("%s", date_time_to_string(date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("Y", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("EY", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("y", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("0y", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("Ey", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("C", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("EC", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("G", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("g", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("b", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("h", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("B", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("m", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("0m", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("U", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("0U", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("W", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("0W", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("V", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("0V", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("j", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("d", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("0d", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("e", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("0e", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("a", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("A", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("w", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("0w", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("u", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("0u", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("H", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("0h", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("I", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("0I", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("M", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("0M", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("S", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("0S", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("c", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("Ec", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("x", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("Ex", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("X", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("EX", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("D", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("F", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("r", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("R", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("T", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("p", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("z", date_time)) << endl;
  cout << ustring::sprintf("%s", date_time_to_string("Z", date_time)) << endl;
}

// This code can be produce the following output :
//
// Sat Jan  2 03:04:05 2021
// 2021
// 2021
// 21
// 21
// 21
// 20
// 20
// 2020
// 20
// Jan
// Jan
// January
// 01
// 01
// 00
// 00
// 00
// 00
// 53
// 53
// 002
// 02
// 02
// 2
// 02
// Sat
// Saturday
// 6
// 6
// 6
// 6
// 03
// Jan
// 03
// 03
// 04
// 04
// 05
// 05
// Sat Jan  2 03:04:05 2021
// Sat Jan  2 03:04:05 2021
// 01/02/21
// 01/02/21
// 03:04:05
// 03:04:05
// 01/02/21
// 2021-01-02
// 03:04:05 AM
// 03:04
// 03:04:05
// AM
// +0100
// CET

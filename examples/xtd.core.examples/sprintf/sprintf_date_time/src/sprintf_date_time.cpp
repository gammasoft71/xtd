#include <xtd/date_time>
#include <xtd/ustring>

using namespace std;
using namespace xtd;

auto main() -> int {
  auto now = xtd::date_time::now();
  cout << now << endl;
  cout << date_time::sprintf("%Y", now) << endl;
  cout << date_time::sprintf("%EY", now) << endl;
  cout << date_time::sprintf("%y", now) << endl;
  cout << date_time::sprintf("%0y", now) << endl;
  cout << date_time::sprintf("%Ey", now) << endl;
  cout << date_time::sprintf("%C", now) << endl;
  cout << date_time::sprintf("%EC", now) << endl;
  cout << date_time::sprintf("%G", now) << endl;
  cout << date_time::sprintf("%g", now) << endl;
  cout << date_time::sprintf("%b", now) << endl;
  cout << date_time::sprintf("%h", now) << endl;
  cout << date_time::sprintf("%B", now) << endl;
  cout << date_time::sprintf("%m", now) << endl;
  cout << date_time::sprintf("%0m", now) << endl;
  cout << date_time::sprintf("%U", now) << endl;
  cout << date_time::sprintf("%0U", now) << endl;
  cout << date_time::sprintf("%W", now) << endl;
  cout << date_time::sprintf("%0W", now) << endl;
  cout << date_time::sprintf("%V", now) << endl;
  cout << date_time::sprintf("%0V", now) << endl;
  cout << date_time::sprintf("%j", now) << endl;
  cout << date_time::sprintf("%d", now) << endl;
  cout << date_time::sprintf("%0d", now) << endl;
  cout << date_time::sprintf("%e", now) << endl;
  cout << date_time::sprintf("%0e", now) << endl;
  cout << date_time::sprintf("%a", now) << endl;
  cout << date_time::sprintf("%A", now) << endl;
  cout << date_time::sprintf("%w", now) << endl;
  cout << date_time::sprintf("%0w", now) << endl;
  cout << date_time::sprintf("%u", now) << endl;
  cout << date_time::sprintf("%0u", now) << endl;
  cout << date_time::sprintf("%H", now) << endl;
  cout << date_time::sprintf("%0h", now) << endl;
  cout << date_time::sprintf("%I", now) << endl;
  cout << date_time::sprintf("%0I", now) << endl;
  cout << date_time::sprintf("%M", now) << endl;
  cout << date_time::sprintf("%0M", now) << endl;
  cout << date_time::sprintf("%S", now) << endl;
  cout << date_time::sprintf("%0S", now) << endl;
  cout << date_time::sprintf("%c", now) << endl;
  cout << date_time::sprintf("%Ec", now) << endl;
  cout << date_time::sprintf("%x", now) << endl;
  cout << date_time::sprintf("%Ex", now) << endl;
  cout << date_time::sprintf("%X", now) << endl;
  cout << date_time::sprintf("%EX", now) << endl;
  cout << date_time::sprintf("%D", now) << endl;
  cout << date_time::sprintf("%F", now) << endl;
  cout << date_time::sprintf("%r", now) << endl;
  cout << date_time::sprintf("%R", now) << endl;
  cout << date_time::sprintf("%T", now) << endl;
  cout << date_time::sprintf("%p", now) << endl;
  cout << date_time::sprintf("%z", now) << endl;
  cout << date_time::sprintf("%Z", now) << endl;
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

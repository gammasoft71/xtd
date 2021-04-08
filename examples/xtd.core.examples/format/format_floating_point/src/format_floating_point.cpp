#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  locale::global(locale("en_US.UTF-8")); // change to us for currency
  cout << strings::format("{}", 12.345) << endl;
  cout << strings::format("{:c}", 12.345) << endl;
  cout << strings::format("{:C}", 12.345) << endl;
  cout << strings::format("{:e}", 12.345) << endl;
  cout << strings::format("{:E}", 12.345) << endl;
  cout << strings::format("{:f}", 12.345) << endl;
  cout << strings::format("{:F}", 12.345) << endl;
  cout << strings::format("{:g}", 12.345) << endl;
  cout << strings::format("{:G}", 12.345) << endl;
  cout << strings::format("{:n}", 12.345) << endl;
  cout << strings::format("{:N}", 12.345) << endl;
  cout << strings::format("{:p}", .0012345) << endl;
  cout << strings::format("{:P}", .0012345) << endl;
  cout << strings::format("{}", std::numeric_limits<double>::infinity()) << endl;
  cout << strings::format("{}", std::numeric_limits<double>::quiet_NaN()) << endl;
  cout << strings::format("{}", std::numeric_limits<double>::signaling_NaN()) << endl;
}

// This code produces the following output :
//
// 12.345
// $12.35
// $12.35
// 1.234500e+01
// 1.234500E+01
// 12.35
// 12.35
// 12.345
// 12.345
// 12.35
// 12.35
// 0.12 %
// 0.12 %
// inf
// nan
// nan

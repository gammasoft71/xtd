#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  locale::global(locale("en_US.UTF-8")); // change to us for currency
  cout << format("{}", 12.345) << endl;
  cout << format("{:c}", 12.345) << endl;
  cout << format("{:C}", 12.345) << endl;
  cout << format("{:e}", 12.345) << endl;
  cout << format("{:E}", 12.345) << endl;
  cout << format("{:f}", 12.345) << endl;
  cout << format("{:F}", 12.345) << endl;
  cout << format("{:g}", 12.345) << endl;
  cout << format("{:G}", 12.345) << endl;
  cout << format("{:n}", 12.345) << endl;
  cout << format("{:N}", 12.345) << endl;
  cout << format("{:p}", .0012345) << endl;
  cout << format("{:P}", .0012345) << endl;
  cout << format("{}", std::numeric_limits<double>::infinity()) << endl;
  cout << format("{}", std::numeric_limits<double>::quiet_NaN()) << endl;
  cout << format("{}", std::numeric_limits<double>::signaling_NaN()) << endl;
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

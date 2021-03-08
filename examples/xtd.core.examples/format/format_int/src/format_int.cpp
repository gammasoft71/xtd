#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  locale::global(locale("en_US.UTF-8")); // change to us for currency
  cout << format("{}", 12.345) << endl;
  cout << format("{:C}", 12.345) << endl;
  cout << format("{:E}", 12.345) << endl;
  cout << format("{:F4}", 12.345) << endl;
  cout << format("{:G}", 12.345) << endl;
  cout << format("{:N}", 12.345) << endl;
  cout << format("{}", std::numeric_limits<double>::infinity()) << endl;
  cout << format("{}", std::numeric_limits<double>::quiet_NaN()) << endl;

}

// This code produces the following output with colors :
//
// 12.345
// $12.35
// 1.234500E+01
// 12.3450
// 12.345
// 12.35
// INF
// NAN

#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  locale::global(locale("en_US.UTF-8")); // change to us for currency
  cout << ustring::format("{}", 12.345) << endl;
  cout << ustring::format("{:c}", 12.345) << endl;
  cout << ustring::format("{:C}", 12.345) << endl;
  cout << ustring::format("{:e}", 12.345) << endl;
  cout << ustring::format("{:E}", 12.345) << endl;
  cout << ustring::format("{:f}", 12.345) << endl;
  cout << ustring::format("{:F}", 12.345) << endl;
  cout << ustring::format("{:g}", 12.345) << endl;
  cout << ustring::format("{:G}", 12.345) << endl;
  cout << ustring::format("{:n}", 12.345) << endl;
  cout << ustring::format("{:N}", 12.345) << endl;
  cout << ustring::format("{:p}", .0012345) << endl;
  cout << ustring::format("{:P}", .0012345) << endl;
  cout << ustring::format("{}", std::numeric_limits<double>::infinity()) << endl;
  cout << ustring::format("{}", std::numeric_limits<double>::quiet_NaN()) << endl;
  cout << ustring::format("{}", std::numeric_limits<double>::signaling_NaN()) << endl;
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

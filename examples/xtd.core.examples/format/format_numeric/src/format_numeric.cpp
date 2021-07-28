#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  locale::global(locale("en_US.UTF-8")); // change to us for currency
  cout << ustring::format("{}", 42) << endl;
  cout << ustring::format("0b{:b8}", 42) << endl;
  cout << ustring::format("0b{:B8}", 42) << endl;
  cout << ustring::format("{:c}", 42) << endl;
  cout << ustring::format("{:C}", 42) << endl;
  cout << ustring::format("{:d}", 42) << endl;
  cout << ustring::format("{:D}", 42) << endl;
  cout << ustring::format("{:e}", 42) << endl;
  cout << ustring::format("{:E}", 42) << endl;
  cout << ustring::format("{:f}", 42) << endl;
  cout << ustring::format("{:F}", 42) << endl;
  cout << ustring::format("{:g}", 42) << endl;
  cout << ustring::format("{:G}", 42) << endl;
  cout << ustring::format("0{:o}", 42) << endl;
  cout << ustring::format("0{:O}", 42) << endl;
  cout << ustring::format("{:n}", 42) << endl;
  cout << ustring::format("{:N}", 42) << endl;
  cout << ustring::format("{:p}", 42) << endl;
  cout << ustring::format("{:P}", 42) << endl;
  cout << ustring::format("0x{:x4}", 42) << endl;
  cout << ustring::format("0x{:X4}", 42) << endl;
}

// This code produces the following output :
//
// 42
// 0b00101010
// 0b00101010
// $42.00
// $42.00
// 42
// 42
// 4.200000e+01
// 4.200000E+01
// 42.00
// 42.00
// 42
// 42
// 052
// 052
// 42.00
// 42.00
// 4200.00 %
// 4200.00 %
// 0x002a
// 0x002A

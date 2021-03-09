#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  locale::global(locale("en_US.UTF-8")); // change to us for currency
  cout << format("{}", 42) << endl;
  cout << format("0b{:b8}", 42) << endl;
  cout << format("0b{:B8}", 42) << endl;
  cout << format("{:c}", 42) << endl;
  cout << format("{:C}", 42) << endl;
  cout << format("{:d}", 42) << endl;
  cout << format("{:D}", 42) << endl;
  cout << format("{:e}", 42) << endl;
  cout << format("{:E}", 42) << endl;
  cout << format("{:f}", 42) << endl;
  cout << format("{:F}", 42) << endl;
  cout << format("{:g}", 42) << endl;
  cout << format("{:G}", 42) << endl;
  cout << format("0{:o}", 42) << endl;
  cout << format("0{:O}", 42) << endl;
  cout << format("{:n}", 42) << endl;
  cout << format("{:N}", 42) << endl;
  cout << format("{:p}", 42) << endl;
  cout << format("{:P}", 42) << endl;
  cout << format("0x{:x4}", 42) << endl;
  cout << format("0x{:X4}", 42) << endl;
}

// This code produces the following output with colors :
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

#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << format("{}", 42) << endl;
  cout << format("{:D}", 42) << endl;
  cout << format("0x{:X4}", 42) << endl;
  cout << format("0b{:b8}", 42) << endl;
  cout << format("0{:o}", 42) << endl;
}

// This code produces the following output with colors :
//
//     string literal 042 a

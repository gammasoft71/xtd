#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;

int main() {
  auto duration = 26h + 3min + 32s + 24ms + 500ns;
  cout << format("{}", duration) << endl;
  cout << format("{:c}", duration) << endl;
  cout << format("{:d}", duration) << endl;
  cout << format("{:D}", duration) << endl;
  cout << format("{:f}", duration) << endl;
  cout << format("{:F}", duration) << endl;
  cout << format("{:g}", duration) << endl;
  cout << format("{:G}", duration) << endl;
  cout << format("{:h}", duration) << endl;
  cout << format("{:H}", duration) << endl;
  cout << format("{:m}", duration) << endl;
  cout << format("{:M}", duration) << endl;
  cout << format("{:n}", duration) << endl;
  cout << format("{:N}", duration) << endl;
  cout << format("{:s}", duration) << endl;
  cout << format("{:S}", duration) << endl;
}

// This code produces the following output :
//
// 1.02:03:32:024000500
// 1.02:03:32:024000500
// 1
// 01
// 1:2:03:32:024000500
// 1:02:03:32:024000500
// 1.2:03:32:024000500
// 1.02:03:32:024000500
// 2
// 02
// 3
// 03
// 24000500
// 024000500
// 32
// 32

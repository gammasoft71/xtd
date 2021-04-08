#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;

int main() {
  auto duration = 26h + 3min + 32s + 24ms + 500ns;
  cout << strings::format("{}", duration) << endl;
  cout << strings::format("{:c}", duration) << endl;
  cout << strings::format("{:d}", duration) << endl;
  cout << strings::format("{:D}", duration) << endl;
  cout << strings::format("{:f}", duration) << endl;
  cout << strings::format("{:F}", duration) << endl;
  cout << strings::format("{:g}", duration) << endl;
  cout << strings::format("{:G}", duration) << endl;
  cout << strings::format("{:h}", duration) << endl;
  cout << strings::format("{:H}", duration) << endl;
  cout << strings::format("{:m}", duration) << endl;
  cout << strings::format("{:M}", duration) << endl;
  cout << strings::format("{:n}", duration) << endl;
  cout << strings::format("{:N}", duration) << endl;
  cout << strings::format("{:s}", duration) << endl;
  cout << strings::format("{:S}", duration) << endl;
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

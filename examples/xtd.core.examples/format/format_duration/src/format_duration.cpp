#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;

int main() {
  auto duration = 26h + 3min + 32s + 24ms + 500ns;
  cout << ustring::format("{}", duration) << endl;
  cout << ustring::format("{:c}", duration) << endl;
  cout << ustring::format("{:d}", duration) << endl;
  cout << ustring::format("{:D}", duration) << endl;
  cout << ustring::format("{:f}", duration) << endl;
  cout << ustring::format("{:F}", duration) << endl;
  cout << ustring::format("{:g}", duration) << endl;
  cout << ustring::format("{:G}", duration) << endl;
  cout << ustring::format("{:h}", duration) << endl;
  cout << ustring::format("{:H}", duration) << endl;
  cout << ustring::format("{:m}", duration) << endl;
  cout << ustring::format("{:M}", duration) << endl;
  cout << ustring::format("{:n}", duration) << endl;
  cout << ustring::format("{:N}", duration) << endl;
  cout << ustring::format("{:s}", duration) << endl;
  cout << ustring::format("{:S}", duration) << endl;
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

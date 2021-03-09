#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;

int main() {
  cout << format("{}", 26h + 3min + 32s + 24ms + 500ns) << endl;
  cout << format("{:G}", 26h + 3min + 32s + 24ms + 500ns) << endl;
  cout << format("{:F}", 2h + 3min + 32s + 24ms + 500ns) << endl;
  cout << format("{0:H}:{0:M}", 2h + 3min + 32s + 24ms + 500ns) << endl;
  cout << format("{0:H}:{0:M}:{0:S}:{0:N}", 2h + 3min + 32s + 24ms + 500ns) << endl;
  cout << format("{0:h}:{0:m}:{0:s}.{0:n}", 2h + 3min + 32s + 24ms + 500ns + 24ms + 500ns) << endl;
}

// This code produces the following output :
//
// 1.02:03:32:024000500
// 1.02:03:32:024000500
// 0:02:03:32:024000500
// 02:03
// 02:03:32:024000500
// 2:3:32.48001000

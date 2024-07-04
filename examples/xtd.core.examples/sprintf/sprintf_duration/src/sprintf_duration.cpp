#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;

int main() {
  cout << (26_h + 3_min + 32_s + 24_ms + 500_ns).to_string("") << endl;
  cout << (26_h + 3_min + 32_s + 24_ms + 500_ns).to_string("G") << endl;
  cout << (2_h + 3_min + 32_s + 24_ms + 500_ns).to_string("F") << endl;
}

// This code produces the following output :
//
// 1.02:03:32:024000500
// 1.02:03:32:024000500
// 0:02:03:32:024000500

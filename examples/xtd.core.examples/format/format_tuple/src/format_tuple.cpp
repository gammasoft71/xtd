#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << ustring::format("{}", make_tuple(1, "one", .42)) << endl;
}

// This code produces the following output :
//
// (1, one, 0.42)

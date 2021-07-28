#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << ustring::format("{}", make_pair(1, "one")) << endl;
}

// This code produces the following output :
//
// (1, one)

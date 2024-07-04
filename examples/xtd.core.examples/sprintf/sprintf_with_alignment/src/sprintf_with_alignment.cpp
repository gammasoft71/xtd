#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << ustring::sprintf("[%10d]", 42) << endl;
  cout << ustring::sprintf("[%-10d]", 42) << endl;
  cout << ustring::sprintf("[%010d]", 42) << endl;
}

// This code produces the following output :
//
// [        42]
// [42        ]
// [0000000042]

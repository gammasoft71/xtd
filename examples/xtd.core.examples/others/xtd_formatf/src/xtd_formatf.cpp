#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << formatf("%10s %s %3d %c", "string", "literal"_s, 42, 'a') << endl;
}

// This code produces the following output with colors :
//
//     string literal 042 a

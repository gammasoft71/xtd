#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << formatf("%s %s %d %c", "string", "literal"_s, 42, 'a') << endl;
}

// This code produces the following output :
//
// string literal 42 a

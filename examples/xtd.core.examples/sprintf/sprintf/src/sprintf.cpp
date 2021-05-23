#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;

int main() {
  cout << strings::sprintf("%s %s %d %c", "string", "literal"s, 42, 'a') << endl;
}

// This code produces the following output :
//
// string literal 42 a

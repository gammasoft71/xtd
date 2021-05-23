#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << format("{0,10} {1} {2:D3} {3}", "string", "literal"_s, 42, 'a') << endl;
}

// This code produces the following output :
//
//     string literal 042 a

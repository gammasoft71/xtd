#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << format("{,10} {} {:D3} {}", "string", "literal"_s, 42, 'a') << endl;
}

// This code produces the following output with colors :
//
//     string literal 042 a

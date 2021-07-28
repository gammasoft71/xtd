#include <xtd/xtd>
#include <iostream>

using namespace std;
using namespace std::literals;
using namespace xtd;

int main() {
  cout << ustring::format("{0,10} {1} {2:D3} {3}", "string", "literal"_is, 42, 'a') << endl;
}

// This code produces the following output:
//
//     string literal 042 a

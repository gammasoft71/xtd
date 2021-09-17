#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;

int main() {
  cout << ustring::format("{} {} {} {}", "string", "literal"s, 42, 'a') << endl;
}

// This code produces the following output :
//
// string literal 42 a

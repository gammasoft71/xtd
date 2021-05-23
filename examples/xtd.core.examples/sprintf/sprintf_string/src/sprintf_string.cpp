#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << format("{}", "string") << endl;
  cout << format("{:anything}", "string") << endl;
}

// This code produces the following output :
//
// string
// string

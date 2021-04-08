#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << strings::format("{}", initializer_list<int> {1, 2, 3, 4}) << endl;
  cout << strings::format("{}", array<int, 4> {1, 2, 3, 4}) << endl;
  cout << strings::format("{}", forward_list<int> {1, 2, 3, 4}) << endl;
  cout << strings::format("{}", list<int> {1, 2, 3, 4}) << endl;
  cout << strings::format("{}", deque<int> {1, 2, 3, 4}) << endl;
  cout << strings::format("{}", vector<int> {1, 2, 3, 4}) << endl;
}

// This code produces the following output :
//
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]

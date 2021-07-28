#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << ustring::format("{}", initializer_list<int> {1, 2, 3, 4}) << endl;
  cout << ustring::format("{}", array<int, 4> {1, 2, 3, 4}) << endl;
  cout << ustring::format("{}", forward_list<int> {1, 2, 3, 4}) << endl;
  cout << ustring::format("{}", list<int> {1, 2, 3, 4}) << endl;
  cout << ustring::format("{}", deque<int> {1, 2, 3, 4}) << endl;
  cout << ustring::format("{}", vector<int> {1, 2, 3, 4}) << endl;
}

// This code produces the following output :
//
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]

#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << strings::format("{}", set<int> {1, 2, 3, 4}) << endl;
  cout << strings::format("{}", multiset<int> {1, 2, 3, 4}) << endl;
  cout << strings::format("{}", map<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}}) << endl;
  cout << strings::format("{}", multimap<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}}) << endl;
}

// This code produces the following output :
//
// {1, 2, 3, 4}
// {1, 2, 3, 4}
// {(1, one), (2, two), (3, three), (4, four)}
// {(1, one), (2, two), (3, three), (4, four)}

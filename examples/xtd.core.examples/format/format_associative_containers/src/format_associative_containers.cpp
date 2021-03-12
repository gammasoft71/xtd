#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << format("{}", set<int> {1, 2, 3, 4}) << endl;
  cout << format("{}", multiset<int> {1, 2, 3, 4}) << endl;
  cout << format("{}", map<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}}) << endl;
  cout << format("{}", multimap<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}}) << endl;
}

// This code produces the following output :
//
// {1, 2, 3, 4}
// {1, 2, 3, 4}
// {(1, one), (2, two), (3, three), (4, four)}
// {(1, one), (2, two), (3, three), (4, four)}

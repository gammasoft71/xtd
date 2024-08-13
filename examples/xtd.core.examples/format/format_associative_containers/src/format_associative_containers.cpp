#include <xtd/ustring>

using namespace xtd;

auto main() -> int {
  std::cout << ustring::format("{}", std::set<int> {1, 2, 3, 4}) << std::endl;
  std::cout << ustring::format("{}", std::multiset<int> {1, 2, 3, 4}) << std::endl;
  std::cout << ustring::format("{}", std::map<int, ustring> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}}) << std::endl;
  std::cout << ustring::format("{}", std::multimap<int, ustring> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}}) << std::endl;
}

// This code produces the following output :
//
// {1, 2, 3, 4}
// {1, 2, 3, 4}
// {(1, one), (2, two), (3, three), (4, four)}
// {(1, one), (2, two), (3, three), (4, four)}

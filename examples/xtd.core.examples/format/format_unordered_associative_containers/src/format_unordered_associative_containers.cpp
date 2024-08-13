#include <xtd/ustring>

using namespace xtd;

auto main() -> int {
  std::cout << ustring::format("{}", std::unordered_set<int> {1, 2, 3, 4}) << std::endl;
  std::cout << ustring::format("{}", std::unordered_multiset<int> {1, 2, 3, 4}) << std::endl;
  std::cout << ustring::format("{}", std::unordered_map<int, ustring> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}}) << std::endl;
  std::cout << ustring::format("{}", std::unordered_multimap<int, ustring> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}}) << std::endl;
}

// This code produces the following output :
//
// {1, 2, 3, 4}
// {1, 2, 3, 4}
// {(1, one), (2, two), (3, three), (4, four)}
// {(1, one), (2, two), (3, three), (4, four)}

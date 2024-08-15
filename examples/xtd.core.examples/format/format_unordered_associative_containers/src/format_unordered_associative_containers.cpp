#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  console::out << ustring::format("{}", std::unordered_set<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << ustring::format("{}", std::unordered_multiset<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << ustring::format("{}", std::unordered_map<int, ustring> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}}) << environment::new_line;
  console::out << ustring::format("{}", std::unordered_multimap<int, ustring> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}}) << environment::new_line;
}

// This code produces the following output :
//
// {1, 2, 3, 4}
// {1, 2, 3, 4}
// {(1, one), (2, two), (3, three), (4, four)}
// {(1, one), (2, two), (3, three), (4, four)}

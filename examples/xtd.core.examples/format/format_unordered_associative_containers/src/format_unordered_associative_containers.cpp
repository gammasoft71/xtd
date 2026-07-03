#include <xtd/xtd>

auto main() -> int {
  console::out << string::format("{}", hash_set<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", dictionary<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}}) << environment::new_line;
  console::out << environment::new_line;
  console::out << string::format("{}", std::unordered_set<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", std::unordered_multiset<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", std::unordered_map<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}}) << environment::new_line;
  console::out << string::format("{}", std::unordered_multimap<int, string> {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}}) << environment::new_line;
}

// This code produces the following output :
//
// {4, 3, 2, 1}
// {(4, four), (3, three), (2, two), (1, one)}
//
// {4, 3, 2, 1}
// {4, 3, 2, 1}
// {(4, four), (3, three), (2, two), (1, one)}
// {(4, four), (3, three), (2, two), (1, one)}

#include <xtd/xtd>
#include <array>
#include <deque>
#include <forward_list>
#include <initializer_list>
#include <list>
#include <queue>
#include <stack>
#include <vector>

auto main() -> int {
  console::out << string::format("{}", array<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", array<int, 2> {{1, 2, 3, 4}, {5, 6, 7, 8}}) << environment::new_line;
  console::out << string::format("{}", fixed_array<int, 4> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", linked_list<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", list<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", collections::array_list {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", queue<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", stack<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << environment::new_line;
  console::out << string::format("{}", std::initializer_list<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", std::array<int, 4> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", std::forward_list<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", std::list<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", std::vector<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", std::deque<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", std::queue<int> {std::deque<int> {1, 2, 3, 4}}) << environment::new_line;
  console::out << string::format("{}", std::stack<int> {std::deque<int> {1, 2, 3, 4}}) << environment::new_line;
}

// This code produces the following output :
//
// [1, 2, 3, 4]
// [[1, 2, 3, 4], [5, 6, 7, 8]]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [4, 3, 2, 1]
//
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [4, 3, 2, 1]

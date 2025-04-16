#include <xtd/collections/array_list>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/fixed_array>
#include <xtd/string>

using namespace xtd;
using namespace xtd::collections;
using namespace xtd::collections::generic;

auto main() -> int {
  console::out << string::format("{}", array<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", fixed_array<int, 4> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", list<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", array_list {1, 2, 3, 4}) << environment::new_line;
  console::out << environment::new_line;
  console::out << string::format("{}", std::initializer_list<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", std::array<int, 4> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", std::forward_list<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", std::list<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", std::deque<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << string::format("{}", std::vector<int> {1, 2, 3, 4}) << environment::new_line;
}

// This code produces the following output :
//
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
//
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]

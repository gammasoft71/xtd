#include <xtd/collections/array_list>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;
using namespace xtd::collections;

auto main() -> int {
  console::out << ustring::format("{}", generic::list<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << environment::new_line;
  console::out << ustring::format("{}", std::initializer_list<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << ustring::format("{}", std::array<int, 4> {1, 2, 3, 4}) << environment::new_line;
  console::out << ustring::format("{}", std::forward_list<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << ustring::format("{}", std::list<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << ustring::format("{}", std::deque<int> {1, 2, 3, 4}) << environment::new_line;
  console::out << ustring::format("{}", std::vector<int> {1, 2, 3, 4}) << environment::new_line;
}

// This code produces the following output :
//
// [1, 2, 3, 4]
//
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]
// [1, 2, 3, 4]

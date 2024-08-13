#include <xtd/collections/array_list>
#include <xtd/ustring>

using namespace xtd;
using namespace xtd::collections;

auto main() -> int {
  std::cout << ustring::format("{}", generic::list<int> {1, 2, 3, 4}) << std::endl;
  std::cout << std::endl;
  std::cout << ustring::format("{}", std::initializer_list<int> {1, 2, 3, 4}) << std::endl;
  std::cout << ustring::format("{}", std::array<int, 4> {1, 2, 3, 4}) << std::endl;
  std::cout << ustring::format("{}", std::forward_list<int> {1, 2, 3, 4}) << std::endl;
  std::cout << ustring::format("{}", std::list<int> {1, 2, 3, 4}) << std::endl;
  std::cout << ustring::format("{}", std::deque<int> {1, 2, 3, 4}) << std::endl;
  std::cout << ustring::format("{}", std::vector<int> {1, 2, 3, 4}) << std::endl;
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

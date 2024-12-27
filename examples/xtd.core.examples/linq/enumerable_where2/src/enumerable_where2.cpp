#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

auto main() -> int {
  array<int> numbers = {0, 30, 20, 15, 90, 85, 40, 75};
  
  const ienumerable<int>& query = numbers.where([](int number, size_t index) {
    return number <= int(index * 10);
  });
  
  for (const auto& number : query)
    console::write_line(number);
}

// This code produces the following output :
//
// 0
// 20
// 15
// 40

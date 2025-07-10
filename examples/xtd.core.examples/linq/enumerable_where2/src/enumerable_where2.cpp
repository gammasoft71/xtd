#include <xtd/xtd>

using namespace xtd;

auto main() -> int {
  auto numbers = array {0, 30, 20, 15, 90, 85, 40, 75};
  
  auto query = numbers.where([](int number, size index) {
    return number <= as<int>(index * 10);
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

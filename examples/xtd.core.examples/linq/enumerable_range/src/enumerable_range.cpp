#include <xtd/linq/enumerable>
#include <xtd/console>

using namespace xtd;
using namespace xtd::linq;

auto main() -> int {
  const auto& squares = enumerable::range(1, 10).select([](int x) {return x * x;});
  
  for (auto num : squares)
    console::write_line(num);
}

// This code produces the following output :
//
// 1
// 4
// 9
// 16
// 25
// 36
// 49
// 64
// 81
// 100

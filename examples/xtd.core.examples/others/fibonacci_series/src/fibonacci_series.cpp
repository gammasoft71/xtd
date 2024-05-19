#include <xtd/console>

using namespace std;
using namespace xtd;

auto fibonacci_series(int n) noexcept {
  auto numbers = vector {0};
  auto a = 1, b = 1;
  while (a < n) {
    numbers.emplace_back(a);
    swap(a, b);
    b += a;
  }
  return numbers;
}

auto main() -> int {
  console::write_line(ustring::join(", ", fibonacci_series(1000)));
}

// This code produces the following output:
//
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987

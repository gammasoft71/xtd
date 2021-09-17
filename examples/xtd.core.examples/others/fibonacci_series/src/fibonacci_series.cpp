#include <xtd/xtd>

using namespace std;
using namespace xtd;

vector<int> fibonacci_series(int n) noexcept {
  vector numbers = {0};
  auto a = 1, b = 1;
  while (a < n) {
    numbers.emplace_back(a);
    swap(a, b);
    b += a;
  }
  return numbers;
}

int main() {
  console::write_line(ustring::join(", ", fibonacci_series(1000)));
}

// This code produces the following output:
//
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987

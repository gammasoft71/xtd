#include <xtd/xtd>

auto get_max(const comparable auto& a, const comparable auto& b) {return a > b ? a : b;}
auto get_min(const comparable auto& a, const comparable auto& b) {return a < b ? a : b;}

auto main() -> int {
  println("max = {}", get_max(42, 21));
  println("max = {}", get_max(34.5, 62.8));
  println("min = {}", get_min(version {1, 2, 4}, version {1, 2, 3}));
  println("min = {}", get_min(4_s + 122_ms, 12_s + 234_ms));
}

// This code produces the following output :
//
// max = 42
// max = 62.8
// min = 1.2.3
// min = 00:00:04.1220000

#include <xtd/xtd>

[[nodiscard]] auto odd_numbers_generator(int count = 100, int min_value = 0, int max_value = 100) -> enumerable_generator<int> {
  auto rnd = xtd::random {};
  for (auto _ : range(count))
    co_yield rnd.next(min_value, max_value) | 1;
}

auto main() -> int {
  println("Odd numbers : ");
  for (auto number : odd_numbers_generator().where(_ % 5 == 0).distinct().order_by(_))
    println("{,4}", number);
  println("Done!");
}

// This code can produce the following output :
//
// Odd numbers :
//    5
//   25
//   45
//   55
//   65
//   75
//   85
//   95
// Done!

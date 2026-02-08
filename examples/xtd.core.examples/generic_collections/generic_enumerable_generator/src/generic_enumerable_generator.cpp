#include <xtd/xtd>

[[nodiscard]] auto odd_numbers_generator(int count = 100, int min_value = 0, int max_value = 100) -> enumerable_generator<int> {
  auto rnd = xtd::random();
  for (auto index = 0; index <= count; ++index)
    co_yield rnd.next(min_value, max_value) | 1;
}

auto main() -> int {
  println("Odd numbers : ");
  for (auto number : odd_numbers_generator().where([](auto n) {return n % 5 == 0;}).distinct())
    println("{,4}", number);
  println("Done!");
}

// This code can produce the following output :
//
// Odd numbers :
//   55
//   75
//   65
//   25
//    5
//   15
//   85
//   45
//   95
// Done!

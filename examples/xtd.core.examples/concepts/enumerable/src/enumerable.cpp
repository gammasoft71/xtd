#include <xtd/xtd>

auto int_generator() -> enumerable_generator<int> {
  co_yield 15;
  co_yield 11;
  co_yield 13;
  co_yield 14;
  co_yield 12;
}

template <collections::generic::enumerable enumerable_t>
[[nodiscard]] auto enumerate(enumerable_t&& enumerable) -> enumerable_generator<enumerable_value_type<enumerable_t>> {
  for (const auto& item : enumerable)
    co_yield item;
}

auto main() -> int {
  for (auto item : enumerate(array {5, 1, 3, 4, 2}).select([](auto v) {return v * 2;}).order())
    println("{,2}", item);
  for (auto item : enumerate(list {10, 6, 8, 9, 7}).select([](auto v) {return v * 3;}).order())
    println("{,2}", item);
  for (auto item : enumerate(int_generator()).select([](auto v) {return v * 4;}).order())
    println("{,2}", item);
}

// This code produces the following output :
//
//  2
//  4
//  6
//  8
// 10
// 18
// 21
// 24
// 27
// 30
// 44
// 48
// 52
// 56
// 60

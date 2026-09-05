#include <xtd/xtd>

auto main() -> int {
  // auto expr1 = [](auto&& _) {return _ <=> 10;};
  auto expr1 = _ <=> 10;
  println("expr1 = {}", expr1(42));
  auto expr2 = expression::compare_three_way(_, 10);
  println("expr2 = {}", expr2(42));
  println();
  // auto expr3 = [](auto&& _1, auto&& _2) {return _1 <=> _2;};
  auto expr3 = _1 <=> _2;
  println("expr3 = {}", expr3(42, 42));
  auto expr4 = expression::compare_three_way(_1, _2);
  println("expr4 = {}", expr4(42, 42));
}

// This code produces the following output :
//
// expr1 = greater
// expr2 = greater
//
// expr3 = equivalent
// expr4 = equivalent

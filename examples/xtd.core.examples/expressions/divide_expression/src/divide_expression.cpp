#include <xtd/xtd>

auto main() -> int {
  // auto expr1 = [](auto&& _) {return _ / 10;};
  auto expr1 = _ / 10;
  println("expr1 = {}", expr1(50));
  auto expr2 = expression::divide(_, 10);
  println("expr2 = {}", expr2(50));
  println();
  // auto expr3 = [](auto&& _1, auto&& _2) {return _1 / _2;};
  auto expr3 = _1 / _2;
  println("expr3 = {}", expr3(60, 15));
  auto expr4 = expression::divide(_1, _2);
  println("expr4 = {}", expr4(60, 15));
}

// This code produces the following output :
//
// expr1 = 5
// expr2 = 5
//
// expr3 = 4
// expr4 = 4

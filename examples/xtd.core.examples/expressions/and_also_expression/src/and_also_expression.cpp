#include <xtd/xtd>

auto main() -> int {
  auto value = true;
  // auto expr1 = [value](auto&& _) {return _ && value;};
  auto expr1 = _ && value;
  println("expr1 = {}", expr1(42 % 2 == 0));
  auto expr2 = expression::and_also(_, value);
  println("expr2 = {}", expr2(42 % 2 == 0));
  println();
  // auto expr3 = [](auto&& _1, auto&& _2) {return _1 && _2;};
  auto expr3 = _1 && _2;
  println("expr3 = {}", expr3(42 % 2 == 0, 42 % 8 == 0));
  auto expr4 = expression::and_also(_1, _2);
  println("expr4 = {}", expr4(42 % 2 == 0, 42 % 8 == 0));
}

// This code produces the following output :
//
// expr1 = true
// expr2 = true
//
// expr3 = false
// expr4 = false

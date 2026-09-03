#include <xtd/xtd>

auto main() -> int {
  // auto expr1 = [](auto&& _) {return _ + 10;};
  auto expr1 = _ + 10;
  println("expr1 = {}", expr1(40));
  auto expr2 = expression::add(_, 10);
  println("expr2 = {}", expr2(40));
  println();
  // auto expr3 = [](auto&& _1, auto&& _2) {return _1 + _2;};
  auto expr3 = _1 + _2;
  println("expr3 = {}", expr3(40, 20));
  auto expr4 = expression::add(_1, _2);
  println("expr4 = {}", expr4(40, 20));
}

// This code produces the following output :
//
// expr1 = 50
// expr2 = 50
//
// expr3 = 60
// expr4 = 60

#include <xtd/xtd>

auto main() -> int {
  // auto expr1 = [](auto&& _) {return _ & 0x0F;};
  auto expr1 = _ & 0x0F;
  println("expr1 = {:B}", expr1(42));
  auto expr2 = expression::and_(_, 0x0F);
  println("expr2 = {:B}", expr2(42));
  println();
  // auto expr3 = [](auto&& _1, auto&& _2) {return _1 & _2;};
  auto expr3 = _1 & _2;
  println("expr3 = {:B}", expr3(42, 0xF0));
  auto expr4 = expression::and_(_1, _2);
  println("expr4 = {:B}", expr4(42, 0xF0));
}

// This code produces the following output :
//
// expr1 = 1010
// expr2 = 1010
//
// expr3 = 100000
// expr4 = 100000

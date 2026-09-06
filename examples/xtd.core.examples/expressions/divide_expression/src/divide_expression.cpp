#include <xtd/xtd>

struct foo {
  int value;
  
  friend auto operator <<(std::ostream& os, const foo& f) -> std::ostream& {return os << f.value;}
  friend auto operator /(const foo& a, const foo& b) -> foo {return foo {a.value / b.value};}
};

auto main() -> int {
  // auto expr1 = [](auto&& a) {return a / 2;}
  auto expr1 = _ / 2;
  println("expr1 = {}", expr1(84));
  println();

  // auto expr2 = [](auto&& a, auto&& b) {return a / b;}
  auto expr2 = _1 / _2;
  println("expr2 = {}", expr2(84, 2));
  println("expr2 = {}", expr2(foo {84}, foo {2}));
  println();

  // auto expr3 = [](auto&& a, auto&& b, auto&& c) {return a / 2 / b / c;}
  auto expr3 = _1 / 2 / _2  / _3;

  println("expr3 = {}", expr3(84, 7, 3));
  println();
}

// This code produces the following output :
//
// expr1 = 42
//
// expr2 = 42
// expr2 = 42
//
// expr3 = 2
//

#include <xtd/xtd>

struct foo {
  int value;
  
  friend auto operator <<(std::ostream& os, const foo& f) -> std::ostream& {return os << f.value;}
  friend auto operator /(const foo& a, const foo& b) -> foo {return foo {a.value / b.value};}
};

auto main() -> int {
  // auto div1 = [](auto a) {return a / 2;}
  auto div1 = _ / 2;

  println("div1 resul => {}", div1(84));
  println();

  // auto div2 = [](auto a, auto b) {return a / b;}
  auto div2 = _1 / _2;

  println("div2 resul => {}", div2(84, 2));
  println("div2 resul => {}", div2(foo {84}, foo {2}));
  println();

  // auto div3 = [](auto a, auto b, auto, c) {return a / 2 / b / c;}
  auto div3 = _1 / 2 / _2  / _3;

  println("div3 resul => {}", div3(84, 7, 3));
  println();
}

// This code produces the following output :
//
// div1 resul => 42
//
// div2 resul => 42
// div2 resul => 42
//
// div3 resul => 2
//

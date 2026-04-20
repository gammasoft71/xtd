#include <xtd/xtd>

struct foo {
  int value;
  
  friend auto operator <<(std::ostream& os, const foo& f) -> std::ostream& {return os << f.value;}
  friend auto operator +(const foo& a, const foo& b) -> foo {return foo {a.value + b.value};}
};

auto main() -> int {
  // auto add1 = [](auto a) {return a + 10;}
  auto add1 = _ + 10;

  println("add1 resul => {}", add1(42));
  println();

  // auto add2 = [](auto a, auto b) {return a + b;}
  auto add2 = _1 + _2;

  println("add2 resul => {}", add2(42, 10));
  println("add2 resul => {}", add2("Hello, "_s, "world!"));
  println("add2 resul => {}", add2(date_time {2026, 4, 20, 21, 12, 36}, 7_min + 24_s));
  println("add2 resul => {}", add2(foo {42}, foo {10}));
  println();

  // auto add3 = [](auto a, auto b, auto, c) {return a + 10 + b + c;}
  auto add3 = _1 + 10 + _2  + _3;

  println("add3 resul => {}", add3(22, 18, 2));
  println();
}

// This code produces the following output :
//
// add1 resul => 52
//
// add2 resul => 52
// add2 resul => Hello, world!
// add2 resul => 4/20/2026 9:20:00 PM
// add2 resul => 52
//
// add3 resul => 52
//

#include <xtd/xtd>

auto main() -> int {
  // auto add1 = [](auto&& _) {return _ + 10;};
  auto add1 = _ + 10;
  println("add1 result => {}", add1(40));
  auto add2 = expression::add(_, 10);
  println("add2 result => {}", add2(40));
  println();
  // auto add3 = [](auto&& _1, auto&& _2) {return _1 + _2;};
  auto add3 = _1 + _2;
  println("add3 result => {}", add3(40, 20));
  auto add4 = expression::add(_1, _2);
  println("add4 result => {}", add4(40, 20));
}

// This code produces the following output :
//
// add1 result => 50
// add2 result => 50
//
// add3 result => 60
// add4 result => 60

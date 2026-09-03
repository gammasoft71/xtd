#include <xtd/xtd>

auto main() -> int {
  // auto and1 = [](auto&& _) {return _ & 0x0F;};
  auto and1 = _ & 0x0F;
  println("and1 result => {:B}", and1(42));
  auto and2 = expression::and_(_, 0x0F);
  println("and2 result => {:B}", and2(42));
  println();
  // auto and3 = [](auto&& _1, auto&& _2) {return _1 & _2;};
  auto and3 = _1 & _2;
  println("and3 result => {:B}", and3(42, 0xF0));
  auto and4 = expression::and_(_1, _2);
  println("and4 result => {:B}", and4(42, 0xF0));
}

// This code produces the following output :
//
// and1 result => 1010
// and2 result => 1010
//
// and3 result => 100000
// and4 result => 100000

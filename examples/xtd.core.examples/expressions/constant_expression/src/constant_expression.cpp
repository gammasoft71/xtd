#include <xtd/xtd>

auto main() -> int {
  // auto constant1 = [] {return 10;};
  auto constant1 =  constant<10> {};
  println("constant1 = {}", constant1());
  auto constant2 =  expression::constant<10>();
  println("constant2 = {}", constant2());
  constexpr auto value = 30;
  //auto constant3 = [value] {return value;};
  auto constant3 =  constant<value> {};
  println("constant3 = {}", constant3());
  auto constant4 =  expression::constant<value>();
  println("constant4 = {}", constant4());
  println();
  //auto expr1 = [value] {return 20 + value;};
  auto expr1 = constant<20> {} + expression::constant<value>();
  println("expr1 = {}", expr1());
}

// This code produces the following output :
//
// constant1 = 10
// constant2 = 10
// constant3 = 30
// constant4 = 30
//
// expr1 = 50

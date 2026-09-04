#include <xtd/xtd>

auto main() -> int {
  auto value = 30;
  // auto expr1 = [value](auto&& _1, auto&& _2) {return (_1 + _2);};
  auto expr1 = (_1 + _2) * value;
  println("expr1 = {}", expr1(10, 20));
  println("expr1 => {}", expr1);
  println("type_of(expr1) => {}", type_of(expr1));
  
  println();
  // auto expr2 = [value](auto&& _1, auto&& _2) {return (_1 + _2) * value;};
  auto expr2 = expression::multiply(expression::add(_1, _2), value);
  println("expr2 = {}", expr2(10, 20));
  println("expr2 => {}", expr2);
  println("type_of(expr2) => {}", type_of(expr2));
}

// This code produces the following output :
//
// expr1 = 900
// expr1 => (_1 + _2) * 30
// type_of(expr1) => xtd::expressions::multiply<xtd::expressions::add<xtd::expressions::argument<1ul>, xtd::expressions::argument<2ul>>, xtd::expressions::value<int>>
//
// expr2 = 900
// expr2 => (_1 + _2) * 30
// type_of(expr2) => xtd::expressions::multiply<xtd::expressions::add<xtd::expressions::argument<1ul>, xtd::expressions::argument<2ul>>, xtd::expressions::value<int>>

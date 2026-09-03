#include <xtd/xtd>

auto main() -> int {
  // auto arg1 = [](auto&& _1) {return _1;};
  auto arg1_1 = expression::arg<1>;
  println("arg1_1 = {}", arg1_1(10));
  // For argument 1 to 10, a second method is possible because the _N are aliases on xtd::expressionq::expression::arg<N>.
  auto arg1_2 = _1; // The _N are aliases on xtd::expressions::expression::arg<N>.
  println("arg1_2 = {}", arg1_2(10));
  // For argument 1, a third method is possible because the _ is an alias on xtd::expressionq::expression::arg<1>.
  auto arg1_3 = _; // The _ is an alias on xtd::expressions::expression::arg<1>.
  println("arg1_3 = {}", arg1_3(10));
  
  println();
  // auto expr = [](auto&& arg1, auto&& arg2, auto&& arg3) {return arg1 + arg2 + arg3;};
  auto expr1 = expression::arg<1> + expression::arg<2> + expression::arg<3>;
  println("expr1 = {}", expr1(10, 20, 30));
  auto expr2 = _1 + _2 + _3; // The _N are aliases on xtd::expressions::expression::arg<N>.
  println("expr2 = {}", expr2(10, 20, 30));
  auto expr3 = _ + _2 + _3;  // The _ is an alias on xtd::expressions::expression::arg<1>.
  println("expr3 = {}", expr3(10, 20, 30));
}

// This code produces the following output :
//
// arg1_1 = 10
// arg1_2 = 10
// arg1_3 = 10
//
// expr1 = 60
// expr2 = 60
// expr3 = 60


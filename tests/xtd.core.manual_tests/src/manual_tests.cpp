#include <xtd/xtd>

auto main() -> int {
  println("Hello, World!");
  auto expr = (_1 + _2 + _3) * (_1 + _2 + _3);
  println("expr = {}", expr(10, 20, 30));
  println("expr => {}", expr);
  println("type_of(expr) => {}", type_of(expr));
}

// This code produces the following output :
//
// Hello, World!

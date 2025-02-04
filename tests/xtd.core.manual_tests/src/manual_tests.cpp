#include <xtd/xtd>

using namespace xtd::collections;

auto main() -> int {
  auto items = dictionary<string, int> {};
  items << key_value_pair<>::create("one"_s, 1) << key_value_pair<>::create("two"_s, 2);
  println("std::pair = {}", std::make_pair("one", 1));
  println("key_value_pair = {}", key_value_pair<>::create("one", 1));
  println("items = {{{}}}", xtd::string::join(", ", items));
}

// This code can produces the following output:
//
// Hello, World!

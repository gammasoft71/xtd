#include <xtd/xtd>

auto main() -> int {
  auto fruits = array {"apple", "banana", "mango", "orange", "passionfruit", "grape"};
  
  auto query = fruits.take_while([](auto&& fruit) {return string::compare("orange", fruit, true) != 0;}).to_array();
  
  for (auto fruit : query)
    println(fruit);
}

// This code produces the following output :
//
// apple
// banana
// mango

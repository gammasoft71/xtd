#include <xtd/xtd>

auto main() -> int {
  auto fruits = array {"apple"_s, "passionfruit"_s, "banana"_s, "mango"_s, "orange"_s, "blueberry"_s, "grape"_s, "strawberry"_s};
  
  auto query = fruits.where(_*method(&string::length) < 6);
  
  for (const auto& fruit : query)
    console::write_line(fruit);
}

// This code produces the following output :
//
// apple
// mango
// grape

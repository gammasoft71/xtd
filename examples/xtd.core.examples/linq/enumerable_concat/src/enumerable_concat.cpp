#include <xtd/xtd>

struct pet {
  string name;
  int age;
};

auto get_cats() -> array<pet> {
  return {
    {"Barley", 8},
    {"Boots", 4},
    {"Whiskers", 1}
  };
}

auto get_dogs() -> array<pet> {
  return {
    {"Bounder", 3},
    {"Snoopy", 14},
    {"Fido", 9}
  };
}

auto main() -> int {
  auto cats = get_cats();
  auto dogs = get_dogs();
  
  auto query = cats.select<string>(_*member(&pet::name)).concat(dogs.select<string>(_*member(&pet::name)));
  
  for (const auto& name : query)
    console::write_line(name);
}

// This code produces the following output :
//
// Barley
// Boots
// Whiskers
// Bounder
// Snoopy
// Fido

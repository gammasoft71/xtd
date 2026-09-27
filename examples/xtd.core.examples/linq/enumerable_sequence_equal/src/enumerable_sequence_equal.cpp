#include <xtd/xtd>

struct pet {
  string name;
  int age;

  auto operator ==(const pet& p) const noexcept -> bool = default;
};

auto main() -> int {
  auto pet1 = pet {.name = "Turbo", .age = 2};
  auto pet2 = pet {.name = "Peanut", .age = 8};
  
  // Create two lists of pets.
  auto pets1 = list {pet1, pet2};
  auto pets2 = list {pet1, pet2};
  
  bool equal = pets1.sequence_equal(pets2);

  println("The lists {} equal.", equal ? "are" : "are not");
}

// This code produces the following output :
//
// The lists are equal.

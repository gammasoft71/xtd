#include <xtd/xtd>

using namespace xtd;

struct pet {
  string name;
  int age = 0;
  
  friend bool operator==(const pet& lhs, const pet& rhs) noexcept {
    return lhs.name == rhs.name && lhs.age == rhs.age;
  }
};

auto main() -> int {
  auto pets1 = array<pet> {
    {.name = "Barley", .age = 8},
    {.name = "Boots", .age = 4},
    {.name = "Whiskers", .age = 1}
  };
  for (const auto& [name, age] : pets1.default_if_empty())
    console::write_line("pet {{name={}, age={}}}", name, age);
  console::write_line();
  
  auto pets2 = array<pet> {};
  for (const auto& [name, age] : pets2.default_if_empty())
    console::write_line("pet {{name={}, age={}}}", name, age);
  console::write_line();
}

// This code produces the following output :
//
// pet {name=Barley, age=8}
// pet {name=Boots, age=4}
// pet {name=Whiskers, age=1}
//
// pet {name=, age=0}
//

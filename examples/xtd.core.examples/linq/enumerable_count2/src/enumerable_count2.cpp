#include <xtd/xtd>

struct pet {
  string name;
  bool vaccinated = false;
};

auto main() -> int {
  auto pets = array {
    pet {.name = "Barley", .vaccinated = true},
    pet {.name = "Boots", .vaccinated = false},
    pet {.name = "Whiskers", .vaccinated = false}
  };
  
  auto number_unvaccinated = pets.count(_*member(&pet::vaccinated) == false);
  console::write_line("There are {} unvaccinated animals.", number_unvaccinated);
}

// This code produces the following output :
//
// There are 2 unvaccinated animals.

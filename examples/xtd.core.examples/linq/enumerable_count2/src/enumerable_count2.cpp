#include <xtd/xtd>

using namespace xtd;

struct pet {
  string name;
  bool vaccinated = false;
  
  friend bool operator ==(const pet& lhs, const pet& rhs) noexcept {
    return lhs.name == rhs.name && lhs.vaccinated == rhs.vaccinated;
  }
};

auto main() -> int {
  auto pets = array {
    pet {.name = "Barley", .vaccinated = true},
    pet {.name = "Boots", .vaccinated = false},
    pet {.name = "Whiskers", .vaccinated = false}
  };
  
  auto number_unvaccinated = pets.count([](const pet& pet) {return !pet.vaccinated;});
  console::write_line("There are {} unvaccinated animals.", number_unvaccinated);
}

// This code produces the following output :
//
// There are 2 unvaccinated animals.

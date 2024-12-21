#include <xtd/linq/enumerable>
#include <xtd/console>

using namespace xtd;
using namespace xtd::linq;

auto main() -> int {
  struct pet : public object {
    pet() = default;
    pet(const string& name, int age, bool vaccinated) : name {name}, age {age}, vaccinated {vaccinated} {}
    
    string name;
    int age = 0;
    bool vaccinated = false;
  };
  
  // Create an array of pets.
  auto pets = array {
    pet {"Barley", 8, true},
    pet {"Boots", 4, false},
    pet {"Whiskers", 1, false}
  };
  
  // Determine whether all pet names in the array start with 'B'.
  bool unvaccinated = enumerable::any<pet>(pets.begin(), pets.end(), [](const pet& pet) {
    return pet.age > 1 && !pet.vaccinated;
  });
  
  console::write_line("There {} unvaccinated animals over age one.", unvaccinated ? "are" : "are not any");
}

// This code produces the following output :
//
// There are unvaccinated animals over age one.

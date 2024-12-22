#include <xtd/array>
#include <xtd/console>

using namespace xtd;

auto main() -> int {
  struct pet : public object {
    pet() = default;
    pet(const string& name, int age) : name {name}, age {age} {}
    
    string name;
    int age = 0;
  };
  
  // Create an array of pets.
  auto pets = array {
    pet {"Barley", 10},
    pet {"Boots", 4},
    pet {"Whiskers", 6}
  };
  
  // Determine whether all pet names in the array start with 'B'.
  bool all_start_with_b = pets.all([](const pet& pet) {
    return pet.name.starts_with("B");
  });
  
  console::write_line("{} pet names start with 'B'.", all_start_with_b ? "All" : "Not all");
}

// This code produces the following output :
//
// Not all pet names start with 'B'.

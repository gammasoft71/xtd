#include <xtd/console>
#include <xtd/random>

using namespace std;
using namespace xtd;

auto main() -> int {
  auto rnd = xtd::random {};
  auto male_pet_names = vector {"Rufus", "Bear", "Dakota", "Fido", "Vanya", "Samuel", "Koani", "Volodya", "Prince", "Yiska"};
  auto female_pet_names = vector {"Maggie", "Penny", "Saya", "Princess", "Abby", "Laila", "Sadie", "Olivia", "Starlight", "Talla"};
  
  // Generate random indexes for pet names.
  auto male_index = rnd.next(male_pet_names.size());
  auto female_index = rnd.next(female_pet_names.size());
  
  // Display the result.
  console::write_line("Suggested pet name of the day: ");
  console::write_line("   For a male:     {0}", male_pet_names[male_index]);
  console::write_line("   For a female:   {0}", female_pet_names[female_index]);
}

// This code can produces the following output:
//
// Suggested pet name of the day:
//    For a male:     Prince
//    For a female:   Talla

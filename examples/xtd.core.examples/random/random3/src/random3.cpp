#include <xtd/xtd>

auto main() -> int {
  auto rnd = xtd::random {};
  auto male_pet_names = array {"Rufus", "Bear", "Dakota", "Fido", "Vanya", "Samuel", "Koani", "Volodya", "Prince", "Yiska"};
  auto female_pet_names = array {"Maggie", "Penny", "Saya", "Princess", "Abby", "Laila", "Sadie", "Olivia", "Starlight", "Talla"};
  
  // Generate random indexes for pet names.
  auto male_index = rnd.next(male_pet_names.length());
  auto female_index = rnd.next(female_pet_names.length());
  
  // Display the result.
  console::write_line("Suggested pet name of the day: ");
  console::write_line("   For a male:     {0}", male_pet_names[male_index]);
  console::write_line("   For a female:   {0}", female_pet_names[female_index]);
}

// This code can produce the following output :
//
// Suggested pet name of the day:
//    For a male:     Prince
//    For a female:   Talla

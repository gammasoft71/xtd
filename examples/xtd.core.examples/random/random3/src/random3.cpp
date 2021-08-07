#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  xtd::random rnd;
  vector<ustring> male_pet_names = {"Rufus", "Bear", "Dakota", "Fido", "Vanya", "Samuel", "Koani", "Volodya", "Prince", "Yiska"};
  vector<ustring> female_pet_names = {"Maggie", "Penny", "Saya", "Princess", "Abby", "Laila", "Sadie", "Olivia", "Starlight", "Talla"};
  
  // Generate random indexes for pet names.
  size_t male_index = rnd.next(male_pet_names.size());
  size_t female_index = rnd.next(female_pet_names.size());
  
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

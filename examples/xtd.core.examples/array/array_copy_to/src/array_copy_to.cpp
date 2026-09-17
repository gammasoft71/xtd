#include <xtd/xtd>

auto print_values(const auto& my_array, const auto& separator) -> void {
  auto enumerator = my_array.get_enumerator();
  auto index = 0_z;
  auto cols = my_array.get_length(my_array.rank() - 1);
  while (enumerator.move_next()) {
    if (index < cols) ++index;
    else {
      console::write_line();
      index = 1;
    }
    console::write("{}{}", separator, enumerator.current());
  }
  console::write_line();
}

auto main() -> int {
  // Creates and initializes two new arrays.
  auto my_source_array = array<string> {6_z};
  my_source_array.set_value("three", 0);
  my_source_array.set_value("napping", 1);
  my_source_array.set_value("cats", 2);
  my_source_array.set_value("in", 3);
  my_source_array.set_value("the", 4);
  my_source_array.set_value("barn", 5);
  
  auto my_target_array = array<string> {15_z};
  my_target_array.set_value("The", 0);
  my_target_array.set_value("quick", 1);
  my_target_array.set_value("brown", 2);
  my_target_array.set_value("fox", 3);
  my_target_array.set_value("jumps", 4);
  my_target_array.set_value("over", 5);
  my_target_array.set_value("the", 6);
  my_target_array.set_value("lazy", 7);
  my_target_array.set_value("dog", 8);
 
  // Displays the values of the Array.
  console::write_line("The target array contains the following (before and after copying):");
  print_values(my_target_array, ' ');
  
  // Copies the source Array to the target Array, starting at index 6.
  my_source_array.copy_to(my_target_array, 6);
  
  // Displays the values of the Array.
  print_values(my_target_array, ' ');
}

// This code produces the following output :
//
// The target array contains the following (before and after copying):
//  The quick brown fox jumps over the lazy dog
//  The quick brown fox jumps over three napping cats in the barn

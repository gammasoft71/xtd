#include <xtd/xtd>

auto print_values(const array<int>& my_arr) -> void {
  for (auto i : my_arr)
    console::write("\t{}", i);
  console::write_line();
}

auto print_values(const array<any_object>& my_arr) -> void {
  for (auto o : my_arr)
    console::write("\t{}", o);
  console::write_line();
}

auto main() -> int {
  // Creates and initializes a new integer array and a new Object array.
  auto my_int_array = array<int> {1, 2, 3, 4, 5};
  auto my_obj_array = array<any_object> {26, 27, 28, 29, 30};
  
  // Prints the initial values of both arrays.
  console::write_line("Initially,");
  console::write("integer array:");
  print_values(my_int_array);
  console::write("Object array: ");
  print_values(my_obj_array);
  
  // Copies the first two elements from the integer array to the Object array.
  array<>::copy(my_int_array, my_obj_array, 2);
  
  // Prints the values of the modified arrays.
  console::write_line("\nAfter copying the first two elements of the integer array to the Object array,");
  console::write("integer array:");
  print_values(my_int_array);
  console::write("Object array: ");
  print_values(my_obj_array);
  
  // Copies the last two elements from the object array to the integer array.
  xtd::array<>::copy(my_obj_array, my_obj_array.get_upper_bound(0) - 1, my_int_array, my_int_array.get_upper_bound(0) - 1, 2);
  
  // Prints the values of the modified arrays.
  console::write_line("\nAfter copying the last two elements of the Object array to the integer array,");
  console::write("integer array:");
  print_values(my_int_array);
  console::write("Object array: ");
  print_values(my_obj_array);
}

// This code produces the following output :
//
// Initially,
// integer array:  1  2  3  4  5
// Object array:   26  27  28  29  30
//
// After copying the first two elements of the integer array to the Object array,
// integer array:  1  2  3  4  5
// Object array:   1  2  28  29  30
//
// After copying the last two elements of the Object array to the integer array,
// integer array:  1  2  3  29  30
// Object array:   1  2  28  29  30

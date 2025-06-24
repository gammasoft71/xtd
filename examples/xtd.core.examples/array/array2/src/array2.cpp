#include <xtd/any_object>
#include <xtd/array>
#include <xtd/console>

using namespace xtd;

auto print_values(const array<int>& my_arr) {
  for (auto i : my_arr)
    console::write_line("\t{}", i);
  console::write_line();
}

auto print_values(const array<any_object>& my_arr) {
  for (auto o : my_arr)
    console::write_line("\t{}", o);
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
  
  // Copies the last two elements from the Object array to the integer array.
  System.Array.Copy(my_obj_array, my_obj_array.GetUpperBound(0) - 1, my_int_array, my_int_array.GetUpperBound(0) - 1, 2);
  
  // Prints the values of the modified arrays.
  console::write_line("\nAfter copying the last two elements of the Object array to the integer array,");
  console::write("integer array:");
  print_values(my_int_array);
  console::write("Object array: ");
  print_values(my_obj_array);
}

// This code produces the following output :
//
// The array has 3 dimension(s) and a total of 24 elements.
//         length  lower   upper
// 0:      2       0       1
// 1:      3       0       2
// 2:      4       0       3
// The array contains the following values:
//         0       1       2       3
//         10      11      12      13
//         20      21      22      23
//         100     101     102     103
//         110     111     112     113
//         120     121     122     123

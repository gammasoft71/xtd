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
  // Creates and initializes a new three-dimensional array of type int.
  auto my_arr = array<int, 3>(2, 3, 4);
  for (auto i = my_arr.get_lower_bound(0); i <= my_arr.get_upper_bound(0); ++i) {
    for (auto j = my_arr.get_lower_bound(1); j <= my_arr.get_upper_bound(1); ++j) {
      for (auto k = my_arr.get_lower_bound(2); k <= my_arr.get_upper_bound(2); ++k)
        my_arr.set_value(as<int>((i * 100) + (j * 10) + k), {i, j, k});
    }
  }
  
  // Displays the properties of the array.
  console::write_line("The array has {} dimension(s) and a total of {} elements.", my_arr.rank(), my_arr.length());
  console::write_line("\tlength\tlower\tupper");
  for (auto i = 0_z; i < my_arr.rank(); ++i) {
    console::write("{}:\t{}", i, my_arr.get_length(i));
    console::write_line("\t{}\t{}", my_arr.get_lower_bound(i), my_arr.get_upper_bound(i));
  }
  
  // Displays the contents of the Array.
  console::write_line("The array contains the following values:");
  print_values(my_arr, '\t');
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

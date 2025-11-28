#include <xtd/xtd>

auto main() -> int {
  // make a single dimension array
  auto my_array1 = array<int>(5_z);
  
  // make a 3 dimensional array
  auto my_array2 = array<int, 3>(5_z, 3_z, 2_z);
  
  // make an array from native array
  int my_native_array[] = {10, 20, 30, 40, 50, 60, 70};
  auto my_array3 = array(my_native_array);
  
  // make an array with initialiser list
  auto my_array4 = array {100, 200, 300, 400, 500, 600, 700};
  
  console::write_line("my_array1 length: {}", my_array1.length());
  console::write_line("my_array2 lengths: {}, {}, {}", my_array2.get_length(0), my_array2.get_length(1), my_array2.get_length(2));

  // show the my_array4 values
  console::write_line("The my_array3 contains the following values: {}", my_array3);
  
  auto index = 0;
  // show the my_array4 values
  console::write_line("The my_array4 contains the following values:");
  for (auto value : my_array4)
    console::write_line("[{}] {}", index++,  value);
}

// This code produces the following output :
//
// my_array1 length: 5
// my_array2 lengths: 5, 3, 2
// The my_array3 contains the following values: [10, 20, 30, 40, 50, 60, 70]
// The my_array4 contains the following values:
// [0] 100
// [1] 200
// [2] 300
// [3] 400
// [4] 500
// [5] 600
// [6] 700

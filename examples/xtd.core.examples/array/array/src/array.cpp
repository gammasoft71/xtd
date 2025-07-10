#include <xtd/xtd>

auto main() -> int {
  // make a single dimension array
  auto my_array1 = array<int>(5);
  
  // make a 3 dimensional array
  auto my_array2 = array<int, 3>(5, 3, 2);
  
  // make an array from native array
  int my_native_array[] = {10, 20, 30, 40, 50, 60, 70};
  auto my_array3 = array<int>(my_native_array);
  
  // make an array with initialiser list
  auto my_array4 = array {100, 200, 300, 400, 500, 600, 700};
  
  auto index = 0;
  // show the array values
  console::write_line("The array contains the following values:");
  for (auto value : my_array3)
    console::write_line("[{0}] {1}", index++,  value);
}

// This code produces the following output :
//
// The array contains the following values:
// [0] 10
// [1] 20
// [2] 30
// [3] 40
// [4] 50
// [5] 60
// [6] 70

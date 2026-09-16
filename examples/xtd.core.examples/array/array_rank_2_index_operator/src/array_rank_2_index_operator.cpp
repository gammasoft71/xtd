#include <xtd/xtd>

auto main() -> int {
  // make a 2 dimensions array
  auto items = array {
    {11, 12, 13, 14, 15},
    {21, 22, 23, 24, 25}
  };

  println("Read with [,] operator:");
  for (auto index1 = 0_z; index1 < items.get_length(0); ++index1)
    for (auto index2 = 0_z; index2 < items.get_length(1); ++index2)
      println("  items[{}, {}] = {}", index1, index2, items[index1, index2]); // Work only with C++23
  
  println("\nRead with (,) operator:");
  for (auto index1 = 0_z; index1 < items.get_length(0); ++index1)
    for (auto index2 = 0_z; index2 < items.get_length(1); ++index2)
      println("  items({}, {}) = {}", index1, index2, items(index1, index2));
  
  println("\nWrite with [,] operator:");
  for (auto index1 = 0_z; index1 < items.get_length(0); ++index1)
    for (auto index2 = 0_z; index2 < items.get_length(1); ++index2)
      items[index1, index2] = as<int>(index1 + 1) * 100 + as<int>(index2 + 1) * 10; // Work only with C++23
  println("  items = {}", items);
  
  println("\nWrite with (,) operator:");
  for (auto index1 = 0_z; index1 < items.get_length(0); ++index1)
    for (auto index2 = 0_z; index2 < items.get_length(1); ++index2)
      items(index1, index2) = as<int>(index1 + 1) * 1000 + as<int>(index2 + 1) * 100;
  println("  items = {}", items);
}

// This code produces the following output :
//
// Read with [,] operator:
//   items[0, 0] = 11
//   items[0, 1] = 12
//   items[0, 2] = 13
//   items[0, 3] = 14
//   items[0, 4] = 15
//   items[1, 0] = 21
//   items[1, 1] = 22
//   items[1, 2] = 23
//   items[1, 3] = 24
//   items[1, 4] = 25
//
// Read with (,) operator:
//   items(0, 0) = 11
//   items(0, 1) = 12
//   items(0, 2) = 13
//   items(0, 3) = 14
//   items(0, 4) = 15
//   items(1, 0) = 21
//   items(1, 1) = 22
//   items(1, 2) = 23
//   items(1, 3) = 24
//   items(1, 4) = 25
//
// Write with [,] operator:
//   items = [[110, 120, 130, 140, 150], [210, 220, 230, 240, 250]]
//
// Write with (,) operator:
//   items = [[1100, 1200, 1300, 1400, 1500], [2100, 2200, 2300, 2400, 2500]]

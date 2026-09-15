#include <xtd/xtd>

auto main() -> int {
  auto items = array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  println("Read with [] operator:");
  for (auto index = 0_z; index < items.length(); ++index)
    println("  items[{}] = {}", index, items[index]);

  println("\nRead with () operator:");
  for (auto index = 0_z; index < items.length(); ++index)
    println("  items({}) = {}", index, items(index));

  println("\nWrite with [] operator:");
  for (auto index = 0_z; index < items.length(); ++index)
    items[index] = as<int>(index + 1) * 10;
  println("  items = {}", items);

  println("\nWrite with () operator:");
  for (auto index = 0_z; index < items.length(); ++index)
    items(index) = as<int>(index + 1) * 100;
  println("  items = {}", items);
}

// This code produces the following output :
//
// Read with [] operator:
//   items[0] = 1
//   items[1] = 2
//   items[2] = 3
//   items[3] = 4
//   items[4] = 5
//   items[5] = 6
//   items[6] = 7
//   items[7] = 8
//   items[8] = 9
//   items[9] = 10
//
// Read with () operator:
//   items(0) = 1
//   items(1) = 2
//   items(2) = 3
//   items(3) = 4
//   items(4) = 5
//   items(5) = 6
//   items(6) = 7
//   items(7) = 8
//   items(8) = 9
//   items(9) = 10
//
// Write with [] operator:
//   items = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
//
// Write with () operator:
//   items = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]

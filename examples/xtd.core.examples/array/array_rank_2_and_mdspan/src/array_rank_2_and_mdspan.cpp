#include <xtd/xtd>
#include <mdspan>

auto main() -> int {
  // make a 2 dimensions array
  auto items = array {
    {11, 12, 13, 14, 15},
    {21, 22, 23, 24, 25}
  };

  // Work only with C++23
  println("Read with std::mdspan:");
  auto view1 = std::mdspan(items.data(), items.get_length(0), items.get_length(1));
  for (auto index1 = 0_z; index1 < view1.extent(0); ++index1)
    for (auto index2 = 0_z; index2 < view1.extent(1); ++index2)
      println("  view1[{}, {}] = {}", index1, index2, view1[index1, index2]); // Work only with C++23
}

// This code produces the following output :
//
// Read with std::mdspan:
//   view1[0, 0] = 11
//   view1[0, 1] = 12
//   view1[0, 2] = 13
//   view1[0, 3] = 14
//   view1[0, 4] = 15
//   view1[1, 0] = 21
//   view1[1, 1] = 22
//   view1[1, 2] = 23
//   view1[1, 3] = 24
//   view1[1, 4] = 25

#include <xtd/xtd>

auto main() -> int {
  // make a 2 dimensions array
  auto items = array {{11, 12, 13, 14, 15}, {21, 22, 23, 24, 25}};
  println("items = {}", items);

#if __cpp_multidimensional_subscript
  println("\nRead with xtd::array [,] :");
  for (auto index1 = 0_z; index1 < items.get_length(0); ++index1)
    for (auto index2 = 0_z; index2 < items.get_length(1); ++index2)
      println("  items[{}, {}] = {}", index1, index2, items[index1, index2]);
#endif

#if __cpp_lib_mdspan
  auto view = std::mdspan(items.data(), items.get_length(0), items.get_length(1));
  println("\nview = {}", view);
  
  println("\nRead with std::mdspan [,] :");
  for (auto index1 = 0_z; index1 < view.extent(0); ++index1)
    for (auto index2 = 0_z; index2 < view.extent(1); ++index2)
      println("  view[{}, {}] = {}", index1, index2, view[index1, index2]);
#endif
}

// This code produces the following output :
//
// items = [[11, 12, 13, 14, 15], [21, 22, 23, 24, 25]]
//
// Read with xtd::array [,] :
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
// view = [[11, 12, 13, 14, 15], [21, 22, 23, 24, 25]]
//
// Read with std::mdspan [,] :
//   view[0, 0] = 11
//   view[0, 1] = 12
//   view[0, 2] = 13
//   view[0, 3] = 14
//   view[0, 4] = 15
//   view[1, 0] = 21
//   view[1, 1] = 22
//   view[1, 2] = 23
//   view[1, 3] = 24
//   view[1, 4] = 25

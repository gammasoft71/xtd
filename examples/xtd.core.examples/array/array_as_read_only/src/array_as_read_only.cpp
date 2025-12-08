#include <xtd/xtd>

auto print_index_and_values(const array<string>& my_arr) -> void  {
  for (auto i = 0_z; i < my_arr.length(); ++i)
    console::write_line("   [{0}] : {1}", i, my_arr[i]);
  console::write_line();
}

auto print_index_and_values(const ilist<string>& my_list) -> void  {
  for (auto i = 0_z; i < my_list.count(); ++i)
    console::write_line( "   [{0}] : {1}", i, my_list[i]);
  console::write_line();
}

auto main() -> int {
  // Create and initialize a new string array.
  auto my_arr = array<string> {"The", "quick", "brown", "fox"};
  
  // Display the values of the array.
  console::write_line("The string array initially contains the following values:");
  print_index_and_values(my_arr);
  
  // Create a read-only ilist wrapper around the array.
  auto my_list = array<>::as_read_only(my_arr);
  
  // Display the values of the read-only ilist.
  console::write_line("The read-only ilist contains the following values:");
  print_index_and_values(my_list);
  
  // Attempt to change a value through the wrapper.
  try {
    my_list[3] = "CAT";
  } catch (const not_supported_exception& e) {
    console::write_line("{} - {}", e.get_type(), e.message());
    console::write_line();
  }
  
  // Change a value in the original array.
  my_arr[2] = "RED";
  
  // Display the values of the array.
  console::write_line("After changing the third element, the string array contains the following values:");
  print_index_and_values( my_arr );
  
  // Display the values of the read-only ilist.
  console::write_line("After changing the third element, the read-only ilist contains the following values:");
  print_index_and_values(my_list);
}

// This code produces the following output :
//
// The string array initially contains the following values:
//    [0] : The
//    [1] : quick
//    [2] : brown
//    [3] : fox
//
// The read-only ilist contains the following values:
//    [0] : The
//    [1] : quick
//    [2] : brown
//    [3] : fox
//
// xtd::not_supported_exception - Collection is read-only.
//
// After changing the third element, the string array contains the following values:
//    [0] : The
//    [1] : quick
//    [2] : RED
//    [3] : fox
//
// After changing the third element, the read-only ilist contains the following values:
//    [0] : The
//    [1] : quick
//    [2] : RED
//    [3] : fox
//

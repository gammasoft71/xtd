#include <xtd/xtd>

template<typename collection_t>
auto print_values(const collection_t& my_list) -> void {
  for (auto obj : my_list)
    console::write("   {0}", obj);
  console::write_line();
}

auto main() -> int {
  // Creates and initializes a new vector_list.
  auto my_vl = collections::array_list {};
  my_vl.add("Hello");
  my_vl.add("World");
  my_vl.add("!");
  
  // Displays the properties and values of the vector_list.
  console::write_line("my_vl");
  console::write_line("    size:    {0}", my_vl.count());
  console::write_line("    Capacity: {0}", my_vl.capacity());
  console::write("    Values:");
  print_values(my_vl);
}

// This code produces the following output :
//
// my_vl
//     size:    3
//     Capacity: 4
//     Values:   Hello   World   !

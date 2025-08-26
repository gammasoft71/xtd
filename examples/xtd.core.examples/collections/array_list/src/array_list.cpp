#include <xtd/xtd>

template<typename collection_t>
void print_values(const collection_t& my_list) {
  for (auto obj : my_list)
    console::write("   {0}", obj);
  console::write_line();
}

auto main() -> int {
  // Creates and initializes a new vector_list.
  auto my_vl = collections::array_list {};
  my_vl.emplace_back("Hello");
  my_vl.emplace_back("World");
  my_vl.emplace_back("!");
  
  // Displays the properties and values of the vector_list.
  console::write_line("my_vl");
  console::write_line("    size:    {0}", my_vl.size());
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

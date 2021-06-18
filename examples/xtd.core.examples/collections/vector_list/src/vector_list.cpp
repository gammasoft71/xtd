#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;
using namespace xtd::collections;

template<typename collection_t>
void print_values(const collection_t& my_list) {
  for (any obj : my_list)
    if (is<string>(obj)) console::write("   {0}",  any_cast<string>(obj));
  console::write_line();
}

int main() {
  // Creates and initializes a new vector_list.
  vector_list my_vl;
  my_vl.emplace_back("Hello"s);
  my_vl.emplace_back("World"s);
  my_vl.emplace_back("!"s);
  
  // Displays the properties and values of the vector_list.
  console::write_line("my_vl");
  console::write_line("    size:    {0}", my_vl.size());
  console::write_line("    Capacity: {0}", my_vl.capacity());
  console::write("    Values:");
  print_values(my_vl);
}

// This code can produces the following output :
//
// my_vl
//     size:    3
//     Capacity: 4
//     Values:   Hello   World   !

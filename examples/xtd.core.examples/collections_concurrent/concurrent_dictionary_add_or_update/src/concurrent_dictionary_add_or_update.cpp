#include <xtd/xtd>

using namespace xtd::collections::concurrent;

class example {
public:
  // Demonstrates:
  //      concurrent_dictionary<key_t, value_t>::add_or_update()
  //      concurrent_dictionary<key_t, value_t>.get_or_add()
  //      concurrent_dictionary<key_t, value_t>[]
  static auto main() {
    // Construct a concurrent_dictionary
    auto cd = concurrent_dictionary<int, int> {};
    
    // Bombard the concurrent_dictionary with 10000 competing add_or_updates
    parallel::for_(0, 10000, [&cd](auto i) {
      // Initial call will set cd[1] = 1.
      // Ensuing calls will set cd[1] = cd[1] + 1
      cd.add_or_update(1, 1, _2 + 1); // same as : cd.add_or_update(1, 1, [](auto key, auto value) {return value + 1;});
    });
    
    console::write_line("After 10000 add_or_updates, cd[1] = {}, should be 10000", cd[1]);
    
    // Should return 100, as key 2 is not yet in the dictionary
    auto value = cd.get_or_add(2, expression::value(100)); //same as : auto value = cd.get_or_add(2, [](auto key) {return 100;});
    console::write_line("After initial get_or_add, cd[2] = {} (should be 100)", value);
    
    // Should return 100, as key 2 is already set to that value
    value = cd.get_or_add(2, 10000);
    console::write_line("After second get_or_add, cd[2] = {} (should be 100)", value);
  }
};

startup_(example::main);

// This code produces the following output :
//
// After 10000 add_or_updates, cd[1] = 10000, should be 10000
// After initial get_or_add, cd[2] = 100 (should be 100)
// After second get_or_add, cd[2] = 100 (should be 100)

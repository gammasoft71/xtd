#include <xtd/xtd>

using namespace xtd::collections::concurrent;

class example {
public:
  // Demonstrates:
  //      concurrent_dictionary<key_t, value_t> ctor(concurrency_level, initial_capacity)
  //      concurrent_dictionary<key_t, value_t>[key_t]
  static auto main() {
    // We know how many items we want to insert into the concurrent_dictionary.
    // So set the initial capacity to some prime number above that, to ensure that
    // the concurrent_dictionary does not need to be resized while initializing it.
    auto HIGHNUMBER = 64;
    auto initial_capacity = 101_z;
    
    // The higher the concurrencyLevel, the higher the theoretical number of operations
    // that could be performed concurrently on the concurrent_dictionary. However, global
    // operations like resizing the dictionary take longer as the concurrencyLevel rises.
    // For the purposes of this example, we'll compromise at num_procs * 2.
    auto num_procs = environment::processor_count();
    auto concurrency_level = num_procs * 2;
    
    // Construct the dictionary with the desired concurrencyLevel and initial_capacity
    auto cd = concurrent_dictionary<int, int>(concurrency_level, initial_capacity);
    
    // Initialize the dictionary
    for (auto i = 1; i <= HIGHNUMBER; ++i)
      cd[i] = i * i;
    
    console::write_line("The square of 23 is {} (should be {})", cd[23], 23 * 23);
    
    // Now iterate through, adding one to the end of the list. Existing items should be updated to be divided by their
    // key  and a new item will be added that is the square of its key.
    for (auto i = 1; i <= HIGHNUMBER + 1; ++i)
      cd.add_or_update(i, i * i, _2 / i);
    
    console::write_line("The square root of 529 is {} (should be {})", cd[23], 529 / 23);
    console::write_line("The square of 65 is {} (should be {})", cd[HIGHNUMBER + 1], ((HIGHNUMBER + 1) * (HIGHNUMBER + 1)));
  }
};

startup_(example::main);

// This code produces the following output :
//
// The square of 23 is 529 (should be 529)
// The square root of 529 is 23 (should be 23)
// The square of 65 is 4225 (should be 4225)

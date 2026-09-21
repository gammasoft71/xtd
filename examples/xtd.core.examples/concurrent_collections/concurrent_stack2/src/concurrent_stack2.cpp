#include <xtd/xtd>

using namespace xtd::collections::concurrent;

class example {
public:
  // Demonstrates:
  //      concurrent_stack<type_t>::push_range();
  //      concurrent_stack<type_t>::try_pop_range();
  static auto main() async_ {
    auto num_paralle_tasks = 4;
    constexpr auto num_items = 1000;
    auto stack = concurrent_stack<int>();
    
    // Push a range of values onto the stack concurrently
    co_await task<>::when_all(enumerable::range(0, num_paralle_tasks).select([&stack](auto i) {
      return task<>::factory().start_new([&stack](auto state) {
        // state = i * num_items
        auto index = as<int>(state);
        auto array = xtd::array<int>(as<usize>(num_items));
        for (auto j = 0; j < num_items; ++j)
          array[j] = index + j;
        
        console::write_line("Pushing an array of ints from {} to {}", array[0], array[num_items - 1]);
        stack.push_range(array);
      }, i * num_items);
    }).to_array());
    
    auto num_total_elements = 4 * num_items;
    auto result_buffer = xtd::array<int>(as<usize>(num_total_elements));
    co_await task<>::when_all(enumerable::range(0, num_paralle_tasks).select([&num_items, &stack, &result_buffer](auto i) {
      return task<>::factory().start_new([&num_items, &stack, &result_buffer](auto obj) {
        auto index = as<int>(obj);
        auto result = stack.try_pop_range(result_buffer, index, as<usize>(num_items));
        
        console::write_line("Try pop range expected {}, got {}.", num_items, result);
      }, i * num_items);
    }).to_array());
    
    for (auto i = 0; i < num_paralle_tasks; ++i) {
      // Create a sequence we expect to see from the stack taking the last number of the range we inserted
      auto expected = enumerable::range(result_buffer[i * num_items + num_items - 1], num_items).to_array();
      
      // Take the range we inserted, reverse it, and compare to the expected sequence
      auto are_equal = expected.sequence_equal(result_buffer.skip(i * num_items).take(num_items).reverse());
      if (are_equal)
        console::write_line("Expected a range of {} to {}. Got {} to {}", expected.first(), expected.last(), result_buffer[i * num_items + num_items - 1], result_buffer[i * num_items]);
      else
        console::write_line("Unexpected consecutive ranges.");
    }
  }
};

startup_(example::main);

// This code produces the following output :
//
// Pushing an array of ints from 0 to 999
// Pushing an array of ints from 2000 to 2999
// Pushing an array of ints from 3000 to 3999
// Pushing an array of ints from 1000 to 1999
// Try pop range expected 1000, got 1000.
// Try pop range expected 1000, got 1000.
// Try pop range expected 1000, got 1000.
// Try pop range expected 1000, got 1000.
// Expected a range of 3000 to 3999. Got 3000 to 3999
// Expected a range of 1000 to 1999. Got 1000 to 1999
// Expected a range of 0 to 999. Got 0 to 999
// Expected a range of 2000 to 2999. Got 2000 to 2999

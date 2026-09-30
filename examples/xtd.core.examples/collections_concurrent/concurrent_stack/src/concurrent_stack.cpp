#include <xtd/xtd>

using namespace xtd::collections::concurrent;

class example {
public:
  // Demonstrates:
  //      concurrent_stack<type_t>::push();
  //      concurrent_stack<type_t>::try_peek();
  //      concurrent_stack<type_t>::try_pop();
  //      concurrent_stack<type_t>::clear();
  //      concurrent_stack<type_t>::is_empty();
  static auto main() async_ {
    constexpr auto items = 10000;
    
    auto stack = concurrent_stack<int>();
    
    // Create an action to push items onto the stack
    auto pusher = [&stack] {
      for (auto i = 0; i < items; ++i)
        stack.push(i);
    };
    
    // Run the action once
    pusher();
    
    auto result= 0;
    if (stack.try_peek(result))
      console::write_line("try_peek() saw {} on top of the stack.", result);
    else
      console::write_line("Could not peek most recently added number.");
    
    // Empty the stack
    stack.clear();
    
    if (stack.is_empty())
      console::write_line("Cleared the stack.");
    
    // Create an action to push and pop items
    auto push_and_pop = [&stack] {
      console::write_line("Task started on {}", task<>::current_id());
      
      auto item = 0;
      for (auto i = 0; i < items; i++)
        stack.push(i);
      for (auto i = 0; i < items; i++)
        stack.try_pop(item);
      
      console::write_line("Task ended on {}", task<>::current_id());
    };
    
    // Spin up five concurrent tasks of the action
    auto tasks = array<task<>> {5_z};
    for (auto i = 0_z; i < tasks.length(); ++i)
      tasks[i] = task<>::factory().start_new(push_and_pop);
    
    // Wait for all the tasks to finish up
    co_await task<>::when_all(tasks);
    
    if (!stack.is_empty())
      console::write_line("Did not take all the items off the stack");
  }
};

startup_(example::main);

// This code produces the following output :
//
// try_peek() saw 9999 on top of the stack.
// Cleared the stack.
// Task started on 6
// Task started on 7
// Task started on 8
// Task started on 9
// Task started on 10
// Task ended on 9
// Task ended on 10
// Task ended on 6
// Task ended on 7
// Task ended on 8

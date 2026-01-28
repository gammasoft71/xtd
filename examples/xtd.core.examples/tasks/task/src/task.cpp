#include <xtd/xtd>

class example {
public:
  static auto main() {
    // Create a counter task
    auto counter_task = task<>::run(delegate_ {
      for (auto counter = 1; counter <= 5; counter++)
        console::write_line("counter = {}", counter);
    });
    
    // Create a string result task
    auto string_result_task = task<string>::run(delegate_ {
      return "This is a string result";
    });
    
    // Wait the two tasks
    task<>::wait_all(counter_task, string_result_task);
    
    // Write on console the result of the second task
    console::write_line(string_result_task.result());
    
    // Create action
    auto parallel_action = delegate_ {
      console::write_line("[task {0}] Run this action in parallel!", task<>::current_id());
    };
    
    // Run 6 actions in parallel.
    parallel::invoke(parallel_action, parallel_action, parallel_action, parallel_action, parallel_action, parallel_action);
  }
};

startup_(example::main);

// This code produces the following output :
//
// counter = 1
// counter = 2
// counter = 3
// counter = 4
// counter = 5
// This is a string result
// [task (3)] Run this action in parallel!
// [task (4)] Run this action in parallel!
// [task (5)] Run this action in parallel!
// [task (6)] Run this action in parallel!
// [task (7)] Run this action in parallel!
// [task (8)] Run this action in parallel!

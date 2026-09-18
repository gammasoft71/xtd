#include <xtd/xtd>

using namespace xtd::collections::concurrent;

class example {
public:
  // Demonstrates:
  // concurrent_queue<type_t>::enqueue()
  // concurrent_queue<type_t>::try_peek()
  // concurrent_queue<type_t>::try_dequeue()
  static auto main() {
    // Construct a concurrent_queue.
    auto cq = concurrent_queue<int> {};

    // Populate the queue.
    for (auto i = 0; i < 10000; ++i)
      cq.enqueue(i);
    
    // Peek at the first element.
    auto result = 0;
    if (!cq.try_peek(result))
      console::write_line("CQ: try_peek failed when it should have succeeded");
    else if (result != 0)
      console::write_line("CQ: Expected try_peek result of 0, got {0}", result);
    
    auto outer_sum = 0;
    // An action to consume the concurrent_queue.
    auto action = [&cq, &outer_sum] {
      auto local_sum = 0;
      auto local_value = 0;
      while (cq.try_dequeue(local_value)) local_sum += local_value;
      interlocked::add(outer_sum, local_sum);
    };
    
    // Start 4 concurrent consuming actions.
    parallel::invoke(action, action, action, action);
    
    console::write_line("outer_sum = {0}, should be 49995000", outer_sum);
  }
};

startup_(example::main);

// This code produces the following output :
//
// outer_sum = 49995000, should be 49995000

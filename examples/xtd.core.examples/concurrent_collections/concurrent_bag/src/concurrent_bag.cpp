#include <xtd/xtd>

using namespace xtd::collections::concurrent;

class example {
public:
  // Demonstrates:
  //      concurrent_bag<type_t>::add()
  //      concurrent_bag<type_t>::is_empty()
  //      concurrent_bag<type_t>::try_take()
  //      concurrent_bag<type_t>::try_peek()
  static auto main() {
    // Add to concurrent_bag concurrently
    auto cb = concurrent_bag<int>();
    auto bag_add_tasks = list<task<>>();
    for (auto i = 0; i < 500; ++i) {
      auto number_to_add = i;
      bag_add_tasks.add(task<>::run([&cb, number_to_add] {cb.add(number_to_add);}));
    }
    
    // Wait for all tasks to complete
    task<>::wait_all(bag_add_tasks);
    
    // Consume the items in the bag
    auto bag_consume_tasks = list<task<>>();
    auto items_in_bag = 0;
    for (auto i = 0; i < 8; ++i) {
      bag_consume_tasks.add(task<>::run([&cb, &items_in_bag] {
        auto item = 0;
        while (cb.try_take(item)) {
          console::write_line(item);
          interlocked::increment(items_in_bag);
        }
      }));
    }
    task<>::wait_all(bag_consume_tasks);
    
    console::write_line("There were {} items in the bag", items_in_bag);
    
    // Checks the bag for an item
    // The bag should be empty and this should not print anything
    auto unexpected_item = 0;
    if (cb.try_peek(unexpected_item))
      console::write_line("Found an item in the bag when it should be empty");
  }
};

startup_(example::main);

// This code produces the following output :
//
// 276
// 265
// ...
// 420
// 423
// There were 500 items in the bag

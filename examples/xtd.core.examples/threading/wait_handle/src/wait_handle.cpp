#include <xtd/threading/auto_reset_event>
#include <xtd/threading/thread_pool>
#include <xtd/console>
#include <xtd/date_time>
#include <xtd/random>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

namespace wait_handle_example {
  class program {
  public:
    static void main() {
      // Queue up two tasks on two different threads;
      // wait until all tasks are completed.
      auto dt = date_time::now();
      console::write_line("Main thread is waiting for BOTH tasks to complete.");
      thread_pool::queue_user_work_item(do_task, event1);
      thread_pool::queue_user_work_item(do_task, event2);
      wait_handle::wait_all({event1, event2});
      // The time shown below should match the longest task.
      console::write_line("Both tasks are completed (time waited={0})",
                          date_time::now() - dt);
      
      // Queue up two tasks on two different threads;
      // wait until any task is completed.
      dt = date_time::now();
      console::write_line();
      console::write_line("The main thread is waiting for either task to complete.");
      thread_pool::queue_user_work_item(do_task, event1);
      thread_pool::queue_user_work_item(do_task, event2);
      auto index = wait_handle::wait_any({event1, event2});
      // The time shown below should match the shortest task.
      console::write_line("Task {0} finished first (time waited={1}).",
                          index + 1, date_time::now() - dt);
    }
    
    static void do_task(std::any state) {
      auto are = as<auto_reset_event>(state);
      auto time = 1000 * r.next(2, 10);
      console::write_line("Performing a task for {0} milliseconds.", time);
      thread::sleep(time);
      are.set();
    }
    
  private:
    // Define two auto_reset_event.
    inline static auto_reset_event event1 {false};
    inline static auto_reset_event event2 {false};
    
    // Define a random number generator for testing.
    inline static xtd::random r;
  };
}

startup_(wait_handle_example::program::main);

// This example produces output similar to the following:
//
// Main thread is waiting for BOTH tasks to complete.
// Performing a task for 4000 milliseconds.
// Performing a task for 9000 milliseconds.
// Both tasks are completed (time waited=00:00:09:011011000)
//
// The main thread is waiting for either task to complete.
// Performing a task for 7000 milliseconds.
// Performing a task for 4000 milliseconds.
// Task 2 finished first (time waited=00:00:04:011925000).

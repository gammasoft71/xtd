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
      // Queue the task.
      thread_pool::queue_user_work_item({thread_proc});
      console::write_line("Main thread does some work, then sleeps.");
      thread::sleep(1000);
      
      console::write_line("Main thread exits.");
    }
   
  private:
    // This thread procedure performs the task.
    static void thread_proc(std::any state_info) {
      // No state object was passed to queue_user_work_item, so state_info has no value.
      console::write_line("Hello from the thread pool.");
    }
  };
}

startup_(wait_handle_example::program::main);

// This example produces output similar to the following:
//
// Main thread does some work, then sleeps.
// Hello from the thread pool.
// Main thread exits.

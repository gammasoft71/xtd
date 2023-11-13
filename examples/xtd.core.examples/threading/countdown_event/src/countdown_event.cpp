#include <xtd/threading/countdown_event>
#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

namespace monitor_lock_example {
  class program {
  public:
    static void main() {
      auto countdown_event = threading::countdown_event {5};
      auto thread_proc = [&] {
        console::write_line("Thread {} signals countdown_event", thread::current_thread().managed_thread_id());
        countdown_event.signal();
      };
      
      for (auto i = 0; i < 5; ++i)
        thread::start_new(thread_proc);
      
      countdown_event.wait();
      console::write_line("All threads have signaled countdown_event");
    }
  };
}

startup_(monitor_lock_example::program::main);

// This example produces output similar to the following:
//
// Thread 2 signals countdown_event
// Thread 3 signals countdown_event
// Thread 4 signals countdown_event
// Thread 6 signals countdown_event
// Thread 5 signals countdown_event
// All threads have signaled countdown_event

#include <xtd/threading/barrier>
#include <xtd/threading/thread_pool>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

namespace barrier_example {
  class program {
  public:
    static void main() {
      for (auto index = 0; index < task_count; ++index)
        thread_pool::queue_user_work_item(perform_phase);
    }

  private:
    static void perform_phase() {
      console::write_line("Thread {} is performing its work", thread::current_thread().managed_thread_id());
      
      barrier.signal_and_wait(1000);
              
      console::write_line("Thread {} compelted the phase", thread::current_thread().managed_thread_id());
    }
    
    static constexpr int task_count = 3;
    inline static threading::barrier barrier {task_count};
  };
}

startup_(barrier_example::program::main);

// This example produces output similar to the following:
//
// Thread 9 is performing its work
// Thread 11 is performing its work
// Thread 8 is performing its work
// Thread 11 compelted the phase
// Thread 8 compelted the phase
// Thread 9 compelted the phase

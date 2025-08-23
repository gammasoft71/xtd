#include <xtd/threading/auto_reset_event>
#include <xtd/threading/interlocked>
#include <xtd/threading/thread>
#include <xtd/threading/thread_pool>
#include <xtd/console>
#include <xtd/lock>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

namespace monitor_lock_example {
  class sync_resource : public object {
  public:
    // Use a monitor to enforce synchronization.
    void access() {
      lock_(*this) {
        console::write_line("Starting synchronized resource access on thread #{0}",
                            thread::current_thread().managed_thread_id());
        if (thread::current_thread().managed_thread_id() % 2 == 0)
          thread::sleep(2000);
        
        thread::sleep(200);
        console::write_line("Stopping synchronized resource access on thread #{0}",
                            thread::current_thread().managed_thread_id());
      }
    }
  };
  
  class un_sync_resource : public object {
  public:
    // Do not enforce synchronization.
    void access() {
      console::write_line("Starting unsynchronized resource access on Thread #{0}",
                          thread::current_thread().managed_thread_id());
      if (thread::current_thread().managed_thread_id() % 2 == 0)
        thread::sleep(2000);
      
      thread::sleep(200);
      console::write_line("Stopping unsynchronized resource access on thread #{0}",
                          thread::current_thread().managed_thread_id());
    }
  };
  
  class app {
  private:
    inline static int num_ops = 0;
    inline static auto_reset_event ops_are_done {false};
    inline static sync_resource sync_res;
    inline static un_sync_resource un_sync_res;

  public:
    static void main() {
      // Set the number of synchronized calls.
      num_ops = 5;
      for (int ctr = 0; ctr <= 4; ++ctr)
        thread_pool::queue_user_work_item(sync_update_resource);
      
      // Wait until this WaitHandle is signaled.
      ops_are_done.wait_one();
      console::write_line("\t\nAll synchronized operations have completed.\n");
      
      // Reset the count for unsynchronized calls.
      num_ops = 5;
      for (int ctr = 0; ctr <= 4; ctr++)
        thread_pool::queue_user_work_item(un_sync_update_resource);
      
      // Wait until this WaitHandle is signaled.
      ops_are_done.wait_one();
      console::write_line("\t\nAll unsynchronized thread operations have completed.\n");
    }
    
    static void sync_update_resource(std::any state) {
      // Call the internal synchronized method.
      sync_res.access();
      
      // Ensure that only one thread can decrement the counter at a time.
      if (interlocked::decrement(num_ops) == 0)
        // Announce to Main that in fact all thread calls are done.
        ops_are_done.set();
    }
    
    static void un_sync_update_resource(std::any state) {
      // Call the unsynchronized method.
      un_sync_res.access();
      
      // Ensure that only one thread can decrement the counter at a time.
      if (interlocked::decrement(num_ops) == 0)
        // Announce to Main that in fact all thread calls are done.
        ops_are_done.set();
    }
  };
}

startup_(monitor_lock_example::app::main);

// This example produces output similar to the following:
//
// Starting synchronized resource access on thread #6
// Stopping synchronized resource access on thread #6
// Starting synchronized resource access on thread #9
// Stopping synchronized resource access on thread #9
// Starting synchronized resource access on thread #2
// Stopping synchronized resource access on thread #2
// Starting synchronized resource access on thread #3
// Stopping synchronized resource access on thread #3
// Starting synchronized resource access on thread #8
// Stopping synchronized resource access on thread #8
//
// All synchronized operations have completed.
//
// Starting unsynchronized resource access on Thread #9
// Starting unsynchronized resource access on Thread #2
// Starting unsynchronized resource access on Thread #11
// Starting unsynchronized resource access on Thread #6
// Starting unsynchronized resource access on Thread #4
// Stopping unsynchronized resource access on thread #9
// Stopping unsynchronized resource access on thread #11
// Stopping unsynchronized resource access on thread #6
// Stopping unsynchronized resource access on thread #2
// Stopping unsynchronized resource access on thread #4
//
// All unsynchronized thread operations have completed.
//

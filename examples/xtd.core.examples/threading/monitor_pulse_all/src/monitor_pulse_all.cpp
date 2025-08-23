#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/lock>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

namespace monitor_lock_example {
  class program {
  public:
    static void main() {
      auto t1 = thread::start_new(worker);
      auto t2 = thread::start_new(worker);
      
      thread::sleep(1000);
      
      lock_("lock") {
        monitor::pulse_all("lock");
      }
      
      thread::join_all({t1, t2});
    }
    
  private:
    static void worker() {
      lock_("lock") {
        console::write_line("    Thread {} wait...", thread::current_thread().managed_thread_id());
        monitor::wait("lock");
        console::write_line("    Thread {} ...continue.", thread::current_thread().managed_thread_id());
      }
    }
  };
}

startup_(monitor_lock_example::program::main);

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

#include <xtd/threading/monitor>
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
//     Thread 2 wait...
//     Thread 3 wait...
//     Thread 3 ...continue.
//     Thread 2 ...continue.

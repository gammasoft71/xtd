#include <xtd/threading/interlocked>
#include <xtd/threading/thread>
#include <xtd/threading/thread_interrupted_exception>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

namespace timeout_example {
  class stay_awake {
  public:
    stay_awake() = default;
    
    void sleep_switch(bool value) {
      sleep_switch_ = value;
    }
    
    void thread_method() {
      console::write_line("new_thread is executing thread_method.");
      while(!sleep_switch_) {
        // Use SpinWait instead of Sleep to demonstrate the
        // effect of calling Interrupt on a running thread.
        thread::spin_wait(10000000);
      }
      try {
        console::write_line("new_thread going to sleep.");
        
        // When new_thread goes to sleep, it is immediately
        // woken up by a ThreadInterruptedException.
        thread::sleep(timeout::infinite);
      } catch(const thread_interrupted_exception& e) {
        console::write_line("new_thread cannot go to sleep - "
                            "interrupted by main thread.");
      }
    }
    
  private:
    bool sleep_switch_ = false;
  };
  
  class thread_interrupt {
  public:
    static void main() {
      auto stay_awake = timeout_example::stay_awake {};
      auto new_thread = thread {thread_start {stay_awake, &timeout_example::stay_awake::thread_method}};
      new_thread.start();
      thread::sleep(10);
      
      // The following line causes an exception to be thrown
      // in thread_method if new_thread is currently blocked
      // or becomes blocked in the future.
      // This method only work on Windows Operating System.
      new_thread.interrupt();
      console::write_line("main thread calls interrupt on new_thread.");
      
      // Tell new_thread to go to sleep.
      stay_awake.sleep_switch(true);
      
      // Wait for new_thread to end.
      new_thread.join();
    }
  };
}

startup_(timeout_example::thread_interrupt);

// This example produces output similar to the following on Windows Operating System only:
//
// new_thread is executing thread_method.
// main thread calls interrupt on new_thread.
// new_thread going to sleep.
// new_thread cannot go to sleep - interrupted by main thread.

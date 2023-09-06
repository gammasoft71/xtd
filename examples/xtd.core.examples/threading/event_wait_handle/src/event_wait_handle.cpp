#include <xtd/threading/event_wait_handle>
#include <xtd/threading/interlocked>
#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

class example {
private:
  // The event_wait_handle used to demonstrate the difference
  // between auto_reset and manual_reset synchronization events.
  //
  inline static event_wait_handle ewh;
  
  // A counter to make sure all threads are started and
  // blocked before any are released. A Long is used to show
  // the use of the 64-bit Interlocked methods.
  //
  inline static int64 thread_count = 0;
  
  // An auto_reset event that allows the main thread to block
  // until an exiting thread has decremented the count.
  //
  inline static event_wait_handle clear_count {false, event_reset_mode::auto_reset};
  
public:
  static void main() {
    // Create an auto_reset event_wait_handle.
    //
    ewh = event_wait_handle {false, event_reset_mode::auto_reset};
    
    // Create and start five numbered threads. Use the
    // ParameterizedThreadStart delegate, so the thread
    // number can be passed as an argument to the Start
    // method.
    for (auto i = 0; i <= 4; i++) {
      threads_[i] = thread {thread_proc};
      threads_[i].start(i);
    }
    
    // Wait until all the threads have started and blocked.
    // When multiple threads use a 64-bit value on a 32-bit
    // system, you must access the value through the
    // Interlocked class to guarantee thread safety.
    //
    while (interlocked::read(thread_count) < 5) {
      thread::sleep(500);
    }
    
    // Release one thread each time the user presses ENTER,
    // until all threads have been released.
    //
    while (interlocked::read(thread_count) > 0) {
      console::write_line("Press ENTER to release a waiting thread.");
      console::read_line();
      
      // SignalAndWait signals the event_wait_handle, which
      // releases exactly one thread before resetting,
      // because it was created with auto_reset mode.
      // SignalAndWait then blocks on clear_count, to
      // allow the signaled thread to decrement the count
      // before looping again.
      //
      wait_handle::signal_and_wait(ewh, clear_count);
    }
    console::write_line();
    
    // Create a manual_reset event_wait_handle.
    //
    ewh = event_wait_handle(false, event_reset_mode::manual_reset);
    
    // Create and start five more numbered threads.
    //
    for(auto i = 0; i <= 4; i++) {
      threads_[i] = thread {thread_proc};
      threads_[i].start(i);
    }
    
    // Wait until all the threads have started and blocked.
    //
    while (interlocked::read(thread_count) < 5) {
      thread::sleep(500);
    }
    
    // Because the event_wait_handle was created with
    // manual_reset mode, signaling it releases all the
    // waiting threads.
    //
    console::write_line("Press ENTER to release the waiting threads.");
    console::read_line();
    ewh.set();
    
    thread::join_all(threads_);
  }
  
private:
  static void thread_proc(std::any data) {
    console::write_line("Thread {0} blocks.", as<int>(data));
    // Increment the count of blocked threads.
    interlocked::increment(thread_count);
    
    // Wait on the event_wait_handle.
    ewh.wait_one();
    
    console::write_line("Thread {0} exits.", as<int>(data));
    // Decrement the count of blocked threads.
    interlocked::decrement(thread_count);
    
    // After signaling ewh, the main thread blocks on
    // clear_count until the signaled thread has
    // decremented the count. Signal it now.
    //
    clear_count.set();
  }
  
  inline static std::array<thread, 5> threads_;
};

startup_(example::main);

// This example produces output similar to the following:
//
// Thread 2 blocks.
// Thread 4 blocks.
// Thread 0 blocks.
// Thread 1 blocks.
// Thread 3 blocks.
// Press ENTER to release a waiting thread.
//
// Thread 4 exits.
// Press ENTER to release a waiting thread.
//
// Thread 2 exits.
// Press ENTER to release a waiting thread.
//
// Thread 0 exits.
// Press ENTER to release a waiting thread.
//
// Thread 1 exits.
// Press ENTER to release a waiting thread.
//
// Thread 3 exits.
//
// Thread 0 blocks.
// Thread 1 blocks.
// Thread 3 blocks.
// Thread 2 blocks.
// Thread 4 blocks.
// Press ENTER to release the waiting threads.
//
// Thread 2 exits.
// Thread 1 exits.
// Thread 4 exits.
// Thread 3 exits.
// Thread 0 exits.

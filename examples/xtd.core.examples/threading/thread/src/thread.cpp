#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

// Simple threading scenario:  Start a static method running
// on a second thread.
class thread_example {
public:
  // The thread_proc method is called when the thread starts.
  // It loops ten times, writing to the console and yielding
  // the rest of its time slice each time, and then ends.
  static void thread_proc() {
    for (auto i = 0; i < 10; ++i) {
      console::write_line("thread_proc: {0}", i);
      // Yield the rest of the time slice.
      thread::sleep(0);
    }
  }
  
  static void main() {
    console::write_line("Main thread: Start a second thread.");
    // The constructor for the thread class requires a thread_start
    // delegate that represents the method to be executed on the
    // thread.  xtd simplifies the creation of this delegate.
    auto t = thread {thread_proc};
    
    // Start thread_proc.  Note that on a uniprocessor, the new
    // thread does not get any processor time until the main thread
    // is preempted or yields.  Uncomment the thread::sleep that
    // follows t.start() to see the difference.
    t.start();
    //thread::sleep(0);
    
    for (auto i = 0; i < 4; ++i) {
      console::write_line("Main thread: Do some work.");
      thread::sleep(0);
    }
    
    console::write_line("Main thread: Call Join(), to wait until thread_proc ends.");
    t.join();
    console::write_line("Main thread: thread_proc.Join has returned.  Press Enter to end program.");
    console::read_line();
  }
};

startup_(thread_example::main);

// This code can produce the following output:
//
// Main thread: Start a second thread.
// Main thread: Do some work.
// Main thread: Do some work.
// thread_proc: 0
// Main thread: Do some work.
// thread_proc: 1
// Main thread: Do some work.
// thread_proc: 2
// Main thread: Call Join(), to wait until thread_proc ends.
// thread_proc: 3
// thread_proc: 4
// thread_proc: 5
// thread_proc: 6
// thread_proc: 7
// thread_proc: 8
// thread_proc: 9
// Main thread: thread_proc.Join has returned.  Press Enter to end program.

#include <xtd/threading/interlocked>
#include <xtd/threading/semaphore>
#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

namespace mutex_example {
  class program {
  public:
    static void main() {
      // Create a semaphore that can satisfy up to three
      // concurrent requests. Use an initial count of zero,
      // so that the entire semaphore count is initially
      // owned by the main program thread.
      //
      pool = semaphore {0, 3};
      
      // Create and start five numbered threads.
      //
      for(auto i = 1; i <= 5; ++i) {
        threads.emplace_back(worker);
        
        // Start the thread, passing the number.
        //
        threads.back().start(i);
      }
      
      // Wait for half a second, to allow all the
      // threads to start and to block on the semaphore.
      //
      thread::sleep(500);
      
      // The main thread starts out holding the entire
      // semaphore count. Calling Release(3) brings the
      // semaphore count back to its maximum value, and
      // allows the waiting threads to enter the semaphore,
      // up to three at a time.
      //
      console::write_line("Main thread calls Release(3).");
      pool.release(3);
      
      thread::sleep(100);
      console::write_line("Main thread exits.");
      
      // Join all threads with timeout because the pool
      // semaphore released only for 3 threads.
      thread::join_all(threads, 100);
    }
    
    static void worker(std::any num) {
      // Each worker thread begins by requesting the
      // semaphore.
      console::write_line("thread {0} begins "
                          "and waits for the semaphore.", num);
      pool.wait_one();
      
      // A padding interval to make the output more orderly.
      int padding = interlocked::add(padding, 100);
      
      console::write_line("thread {0} enters the semaphore.", num);
      
      // The thread's "work" consists of sleeping for
      // about a second. Each thread "works" a little
      // longer, just to make the output more orderly.
      //
      thread::sleep(1000 + padding);
      
      console::write_line("thread {0} releases the semaphore.", num);
      console::write_line("thread {0} previous semaphore count: {1}",
                          num, pool.release());
    }
    
  private:
    inline static std::vector<thread> threads = std::vector<thread>(5);

    // A semaphore that simulates a limited resource pool.
    //
    inline static semaphore pool;
    
    // A padding interval to make the output more orderly.
    inline static int padding;
    
  };
}

startup_(mutex_example::program::main);

// This example produces output similar to the following:
//
// thread 2 begins and waits for the semaphore.
// thread 5 begins and waits for the semaphore.
// thread 4 begins and waits for the semaphore.
// thread 1 begins and waits for the semaphore.
// thread 3 begins and waits for the semaphore.
// Main thread calls Release(3).
// thread 5 enters the semaphore.
// thread 2 enters the semaphore.
// thread 1 enters the semaphore.
// thread 5 releases the semaphore.
// thread 5 previous semaphore count: 0
// thread 4 enters the semaphore.
// thread 2 releases the semaphore.
// thread 2 previous semaphore count: 0
// thread 3 enters the semaphore.
// thread 1 releases the semaphore.
// thread 1 previous semaphore count: 0
// thread 4 releases the semaphore.
// thread 4 previous semaphore count: 1
// thread 3 releases the semaphore.
// thread 3 previous semaphore count: 2
// Main thread exits.

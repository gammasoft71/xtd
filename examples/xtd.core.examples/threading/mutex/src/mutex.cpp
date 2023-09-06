#include <xtd/threading/mutex>
#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

namespace mutex_example {
  class program {
  public:
    static void main() {
      // Create the threads that will use the protected resource.
      for (auto i = 0; i < num_threads; ++i) {
        threads.emplace_back(thread_proc);
        threads.back().name(ustring::format("thread_{0}", i + 1));
        threads.back().start();
      }
      
      thread::join_all(threads);
    }
    
    static void thread_proc() {
      for(auto i = 0; i < num_iterations; ++i)
        Use_resource();
    }
    
  private:
    // This method represents a resource that must be synchronized
    // so that only one thread at a time can enter.
    static void Use_resource() {
      // Wait until it is safe to enter.
      console::write_line("{0} is requesting the mutex",
                        thread::current_thread().name());
      mut.wait_one();
      
      console::write_line("{0} has entered the protected area",
                          thread::current_thread().name());
      
      // Place code to access non-reentrant resources here.
      
      // Simulate some work.
      thread::sleep(500);
      
      console::write_line("{0} is leaving the protected area",
                          thread::current_thread().name());
      
      // Release the mutex.
      mut.release_mutex();
      console::write_line("{0} has released the mutex",
                          thread::current_thread().name());
    }

    inline static std::vector<thread> threads;
    // Create a new mutex. The creating thread does not own the mutex.
    inline static mutex mut;
    inline static constexpr int num_iterations = 1;
    inline static constexpr int num_threads = 3;
  };
}

startup_(mutex_example::program::main);

// This example produces output similar to the following:
//
// thread_1 is requesting the mutex
// thread_1 has entered the protected area
// thread_2 is requesting the mutex
// thread_3 is requesting the mutex
// thread_1 is leaving the protected area
// thread_1 has released the mutex
// thread_2 has entered the protected area
// thread_2 is leaving the protected area
// thread_2 has released the mutex
// thread_3 has entered the protected area
// thread_3 is leaving the protected area
// thread_3 has released the mutex

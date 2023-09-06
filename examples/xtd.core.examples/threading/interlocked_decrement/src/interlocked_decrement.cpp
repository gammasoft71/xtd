#include <xtd/threading/interlocked>
#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/startup>
#include <vector>

using namespace xtd;
using namespace xtd::threading;

namespace interlocked_decrement_example {
  class my_interlocked_decrement_class {
  private:
    class count_class {
    public:
      inline static int unsafe_instance_count = 0;
      inline static int safe_instance_count = 0;
      
      count_class() {
        unsafe_instance_count++;
        interlocked::increment(safe_instance_count);
      }
      
      ~count_class() {
        unsafe_instance_count--;
        interlocked::decrement(safe_instance_count);
      }
    };
    
  public:
    static auto main() {
      auto thread1 = thread {thread_method};
      auto thread2 = thread {thread_method};
      thread1.start();
      thread2.start();
      thread1.join();
      thread2.join();

      console::write_line("unsafe_instance_count: {}\nsafe_instance_count: {}", count_class::unsafe_instance_count, count_class::safe_instance_count);
    }
    
  private:
    static void thread_method() {
      auto cc = count_class {};
      
      // Create 100000 instances of count_class.
      for (auto i = 0; i < 100000; ++i)
        cc = count_class {};
    }
  };
}

startup_(interlocked_decrement_example::my_interlocked_decrement_class::main);

// This code produces the following output:
//
// unsafe_instance_count: 253
// safe_instance_count: 0

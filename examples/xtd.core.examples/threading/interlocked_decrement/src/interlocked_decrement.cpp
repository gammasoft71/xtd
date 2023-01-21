#include <vector>
#include <thread>
#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::threading;

namespace examples {
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
      thread thread1(thread_method);
      thread thread2(thread_method);
      thread1.join();
      thread2.join();
      
      console::write_line("unsafe_instance_count: {}\nsafe_instance_count: {}", count_class::unsafe_instance_count, count_class::safe_instance_count);
    }
    
  private:
    static void thread_method() {
      unique_ptr<count_class> cc;
      
      // Create 100000 instances of count_class.
      for (int i = 0; i < 100000; ++i)
        cc = make_unique<count_class>();
    }
  };
}

startup_(examples::my_interlocked_decrement_class);

// This code produces the following output:
//
// unsafe_instance_count: 27401
// safe_instance_count: 0

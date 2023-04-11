#include <vector>
#include <thread>
#include <xtd/xtd>

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace xtd::threading;

namespace interlocked_example {
  struct my_thread {
    std::thread thread;
    ustring name;
  };
  class my_interlocked_exchange_class {
  private:
    //0 for False, 1 for True.
    inline static int using_resource = 0;
    
    static const int num_thread_iterations = 5;
    static const int num_threads = 10;
    
  public:
    // The main entry point for the application.
    static auto main() {
      vector<my_thread> my_threads(num_threads);
      xtd::random rnd;
      
      for (int i = 0; i < num_threads; ++i) {
        my_threads[i].name = ustring::format("Thread{0}", i + 1);
        
        //Wait a random amount of time before starting next thread.
        this_thread::sleep_for(milliseconds(rnd.next(0, 1000)));
        my_threads[i].thread = thread(my_thread_proc, my_threads[i].name);
      }
      
      for (int i = 0; i < num_threads; ++i)
        my_threads[i].thread.join();
    }
    
    static void my_thread_proc(const ustring& name) {
      for (int i = 0; i < num_thread_iterations; i++) {
        use_resource(name);
        
        //Wait 1 second before next attempt.
        this_thread::sleep_for(milliseconds(1000));
      }
    }
    
    //A simple method that denies reentrancy.
    static bool use_resource(const ustring& name) {
      //0 indicates that the method is not in use.
      if (0 == interlocked::exchange(using_resource, 1)) {
        console::write_line("{0} acquired the lock", name);
        
        //Code to access a resource that is not thread safe would go here.
        
        //Simulate some work
        this_thread::sleep_for(milliseconds(500));
        
        console::write_line("{0} exiting lock", name);
        
        //Release the lock
        interlocked::exchange(using_resource, 0);
        return true;
      } else {
        console::write_line("   {0} was denied the lock", name);
        return false;
      }
    }
  };
}

startup_(interlocked_example::my_interlocked_exchange_class);

#include <xtd/threading/interlocked>
#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/random>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

namespace interlocked_example {
  struct my_thread {
    threading::thread thread;
    ustring name;
  };
  
  class my_interlocked_exchange_class {
  private:
    //0 for False, 1 for True.
    inline static int using_resource = 0;
    
    static constexpr int num_thread_iterations = 5;
    
  public:
    // The main entry point for the application.
    static auto main() {
      auto my_threads = std::array<my_thread, 10> {};
      auto rnd = xtd::random {};
      
      for (auto index = 0ul; index < my_threads.size(); ++index) {
        my_threads[index].name = ustring::format("Thread{}", index + 1);
        
        //Wait a random amount of time before starting next thread.
        thread::sleep(rnd.next(0, 1000));
        my_threads[index].thread = thread {my_thread_proc};
        my_threads[index].thread.start(my_threads[index].name);
      }
      
      for (auto index = 0ul; index < my_threads.size(); ++index)
        my_threads[index].thread.join();
    }
    
    static void my_thread_proc(std::any name) {
      for (auto index = 0; index < num_thread_iterations; ++index) {
        use_resource(as<ustring>(name));
        
        //Wait 1 second before next attempt.
        thread::sleep(1000);
      }
    }
    
    //A simple method that denies reentrancy.
    static auto use_resource(const ustring& name)->bool {
      //0 indicates that the method is not in use.
      if (0 == interlocked::exchange(using_resource, 1)) {
        console::write_line("{} acquired the lock", name);
        
        //Code to access a resource that is not thread safe would go here.
        
        //Simulate some work
        thread::sleep(500);
        
        console::write_line("{} exiting lock", name);
        
        //Release the lock
        interlocked::exchange(using_resource, 0);
        return true;
      } else {
        console::write_line("   {} was denied the lock", name);
        return false;
      }
    }
  };
}

startup_(interlocked_example::my_interlocked_exchange_class::main);

// This example produces output similar to the following:
//
// Thread1 acquired the lock
// Thread1 exiting lock
// Thread2 acquired the lock
//    Thread3 was denied the lock
// Thread2 exiting lock
// Thread1 acquired the lock
//    Thread4 was denied the lock
//    Thread5 was denied the lock
// Thread1 exiting lock
// Thread6 acquired the lock
//    Thread3 was denied the lock
//    Thread2 was denied the lock
//    Thread7 was denied the lock
// Thread6 exiting lock
// Thread4 acquired the lock
//    Thread5 was denied the lock
//    Thread1 was denied the lock
// Thread4 exiting lock
// Thread8 acquired the lock
//    Thread3 was denied the lock
//    Thread2 was denied the lock
//    Thread7 was denied the lock
//    Thread6 was denied the lock
//    Thread9 was denied the lock
// Thread8 exiting lock
// Thread5 acquired the lock
//    Thread1 was denied the lock
//    Thread4 was denied the lock
//    Thread3 was denied the lock
//    Thread10 was denied the lock
//    Thread2 was denied the lock
//    Thread7 was denied the lock
// Thread5 exiting lock
// Thread6 acquired the lock
//    Thread9 was denied the lock
//    Thread8 was denied the lock
//    Thread1 was denied the lock
// Thread6 exiting lock
// Thread4 acquired the lock
//    Thread3 was denied the lock
//    Thread10 was denied the lock
//    Thread2 was denied the lock
//    Thread7 was denied the lock
//    Thread5 was denied the lock
// Thread4 exiting lock
// Thread9 acquired the lock
//    Thread8 was denied the lock
//    Thread6 was denied the lock
// Thread9 exiting lock
// Thread10 acquired the lock
//    Thread7 was denied the lock
//    Thread5 was denied the lock
//    Thread4 was denied the lock
//    Thread8 was denied the lock
// Thread10 exiting lock
// Thread6 acquired the lock
//    Thread9 was denied the lock
// Thread6 exiting lock
// Thread8 acquired the lock
//    Thread10 was denied the lock
//    Thread9 was denied the lock
// Thread8 exiting lock
// Thread10 acquired the lock
// Thread10 exiting lock

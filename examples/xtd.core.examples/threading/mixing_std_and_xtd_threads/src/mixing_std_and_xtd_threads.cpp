#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/startup>
#include <thread>

using namespace xtd;
using namespace xtd::threading;

namespace mixing_std_and_xtd_threads_example {
  class mixing_std_and_xtd_threads_class {
  private:
    static ustring to_string(const thread& thread) {
      return ustring::format("  thread={{name={}, managed_thread_id={}, priority={}, thread_id=0x{:x}, state={}}}", thread.name(), thread.managed_thread_id(), thread.priority(), thread.thread_id(), thread.thread_state());
    }
    
  public:
    static auto main() {
      console::write_line("threads {");
      thread::current_thread().name("main");
      console::write_line(to_string(thread::current_thread()));
      
      threading::thread t1 {[&] {
        thread::sleep(20_ms);
        console::write_line(to_string(t1));
      }};
      t1.name("xtd_thread_1");
      t1.priority(thread_priority::below_normal);
      t1.start();
      
      std::thread t2 {[] {
        thread::current_thread().name("std_thread_2");
        thread::current_thread().priority(thread_priority::highest);
        console::write_line(to_string(thread::current_thread()));
      }};
      
      threading::thread t3 {[] {
        console::write_line(to_string(thread::current_thread()));
      }};
      t3.name("xtd_thread_3");
      t3.is_background(true);
      t3.start();
      
      std::thread t4 {[] {
        thread::sleep(10_ms);
        thread::current_thread().name("std_thread_4");
        thread::current_thread().priority(thread_priority::highest);
        console::write_line(to_string(thread::current_thread()));
      }};
      
      if (t1.joinable()) t1.join();
      if (t2.joinable()) t2.join();
      if (t3.joinable()) t3.join();
      if (t4.joinable()) t4.join();
      console::write_line("}");
    }
  };
}

startup_(mixing_std_and_xtd_threads_example::mixing_std_and_xtd_threads_class::main);

// This code produces the following output:
//
// threads {
//   thread={name=main, managed_thread_id=1, priority=normal, thread_id=0x20245e080, state=running}
//   thread={name=xtd_thread_3, managed_thread_id=3, priority=normal, thread_id=0x16ff9f000, state=background}
//   thread={name=std_thread_2, managed_thread_id=0, priority=highest, thread_id=0x16ff13000, state=background}
//   thread={name=std_thread_4, managed_thread_id=0, priority=highest, thread_id=0x16ff13000, state=background}
//   thread={name=xtd_thread_1, managed_thread_id=2, priority=below_normal, thread_id=0x16fe87000, state=running}
// }

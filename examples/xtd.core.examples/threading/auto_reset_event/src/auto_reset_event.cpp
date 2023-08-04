#include <xtd/threading/auto_reset_event>
#include <xtd/console>
#include <xtd/startup>
#include <thread>

using namespace std;
using namespace xtd;
using namespace xtd::threading;

namespace auto_reset_event_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      console::write_line("Press Enter to create three threads and start them.\r\n"
                          "The threads wait on auto_reset_event #1, which was created\r\n"
                          "in the signaled state, so the first thread is released.\r\n"
                          "This puts auto_reset_event #1 into the unsignaled state.");
      console::read_line();
      
      for (auto index = 1; index < 4; ++index) {
        auto t = std::thread {thread_proc};
        t.detach();
        //t.name("Thread_" + index);
      }
      this_thread::sleep_for(250_ms);
      
      for (auto index = 0; index < 2; ++index) {
        console::write_line("Press Enter to release another thread.");
        console::read_line();
        event_1.set();
        this_thread::sleep_for(250_ms);
      }
      
      console::write_line("\r\nAll threads are now waiting on auto_reset_event #2.");
      for (int i = 0; i < 3; i++) {
        console::write_line("Press Enter to release a thread.");
        console::read_line();
        event_2.set();
        this_thread::sleep_for(250_ms);
      }
    }
    
    static void thread_proc() {
      ustring name = ustring::format("thread_{}", this_thread::get_id()); //thread::current_thread::name();
      
      console::write_line("{0} waits on auto_reset_event #1.", name);
      event_1.wait_one();
      console::write_line("{0} is released from auto_reset_event #1.", name);
      
      console::write_line("{0} waits on auto_reset_event #2.", name);
      event_2.wait_one();
      console::write_line("{0} is released from auto_reset_event #2.", name);
      
      console::write_line("{0} ends.", name);
    }

  private:
    inline static auto_reset_event event_1 {true};
    inline static auto_reset_event event_2 {false};
  };
}

startup_(auto_reset_event_example::program);

// This example produces output similar to the following:
//
// Press Enter to create three threads and start them.
// The threads wait on auto_reset_event #1, which was created
// in the signaled state, so the first thread is released.
// This puts auto_reset_event #1 into the unsignaled state.
//
// thread_0x16fe87000 waits on auto_reset_event #1.
// thread_0x16fe87000 is released from auto_reset_event #1.
// thread_0x16fe87000 waits on auto_reset_event #2.
// thread_0x16ff13000 waits on auto_reset_event #1.
// thread_0x16ff9f000 waits on auto_reset_event #1.
// Press Enter to release another thread.
//
// thread_0x16ff9f000 is released from auto_reset_event #1.
// thread_0x16ff9f000 waits on auto_reset_event #2.
// Press Enter to release another thread.
//
// thread_0x16ff13000 is released from auto_reset_event #1.
// thread_0x16ff13000 waits on auto_reset_event #2.
//
// All threads are now waiting on auto_reset_event #2.
// Press Enter to release a thread.
//
// thread_0x16ff9f000 is released from auto_reset_event #2.
// thread_0x16ff9f000 ends.
// Press Enter to release a thread.
//
// thread_0x16fe87000 is released from auto_reset_event #2.
// thread_0x16fe87000 ends.
// Press Enter to release a thread.
//
// thread_0x16ff13000 is released from auto_reset_event #2.
// thread_0x16ff13000 ends.

#include <xtd/threading/auto_reset_event>
#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/startup>

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
        threads.emplace_back(thread_proc);
        threads.back().name(ustring::format("Thread_{}", index));
        threads.back().start();
      }
      thread::sleep(250_ms);
      
      for (auto index = 0; index < 2; ++index) {
        console::write_line("Press Enter to release another thread.");
        console::read_line();
        event_1.set();
        thread::sleep(250_ms);
      }
      
      console::write_line("\r\nAll threads are now waiting on auto_reset_event #2.");
      for (int i = 0; i < 3; i++) {
        console::write_line("Press Enter to release a thread.");
        console::read_line();
        event_2.set();
        thread::sleep(250_ms);
      }
    }
    
    static void thread_proc() {
      ustring name = thread::current_thread().name();
      
      console::write_line("{0} waits on auto_reset_event #1.", name);
      event_1.wait_one();
      console::write_line("{0} is released from auto_reset_event #1.", name);
      
      console::write_line("{0} waits on auto_reset_event #2.", name);
      event_2.wait_one();
      console::write_line("{0} is released from auto_reset_event #2.", name);
      
      console::write_line("{0} ends.", name);
    }

  private:
    inline static std::vector<thread> threads = std::vector<thread>(4);
    inline static auto_reset_event event_1 {true};
    inline static auto_reset_event event_2 {false};
  };
}

startup_(auto_reset_event_example::program::main);

// This example produces output similar to the following:
//
// Press Enter to create three threads and start them.
// The threads wait on auto_reset_event #1, which was created
// in the signaled state, so the first thread is released.
// This puts auto_reset_event #1 into the unsignaled state.
//
// Thread_1 waits on auto_reset_event #1.
// Thread_1 is released from auto_reset_event #1.
// Thread_1 waits on auto_reset_event #2.
// Thread_2 waits on auto_reset_event #1.
// Thread_3 waits on auto_reset_event #1.
// Press Enter to release another thread.
//
// Thread_3 is released from auto_reset_event #1.
// Thread_3 waits on auto_reset_event #2.
// Press Enter to release another thread.
//
// Thread_2 is released from auto_reset_event #1.
// Thread_2 waits on auto_reset_event #2.
//
// All threads are now waiting on auto_reset_event #2.
// Press Enter to release a thread.
//
// Thread_1 is released from auto_reset_event #2.
// Thread_1 ends.
// Press Enter to release a thread.
//
// Thread_3 is released from auto_reset_event #2.
// Thread_3 ends.
// Press Enter to release a thread.
//
// Thread_2 is released from auto_reset_event #2.
// Thread_2 ends.

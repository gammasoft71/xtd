#include <xtd/threading/spin_lock>
#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

class core_manual_test {
public:
  static auto entry_point() {
    ::spin_lock spin_lock;
    auto thread1 = thread::start_new([&] {
      auto lock_taken = false;
      spin_lock.enter(lock_taken);
      console::write_line("Thread 1 locked.");
      thread::sleep(1000);
      spin_lock.exit();
    });

    auto thread2 = thread::start_new([&] {
      thread::sleep(500);
      auto lock_taken = false;
      spin_lock.enter(lock_taken);
      console::write_line("Thread 2 locked.");
      spin_lock.exit();
    });

    thread1.join();
    thread2.join();
  }
};

auto main()->int {
  startup::safe_run(core_manual_test::entry_point);
}

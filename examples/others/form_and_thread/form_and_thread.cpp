#include <thread>
#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  bool closed = false;
  form form_main;
  form_main.text("Form and thread example");
  form_main.form_closed += [&] {
    closed = true;
  };
  
  list_box list_box;
  list_box.parent(form_main);
  list_box.dock(dock_style::fill);
  
  std::vector<std::thread> threads(environment::processor_count());
  for (int index = 0; index < threads.size(); index++) {
    threads[index] = std::thread([&] {
      int counter = 0;
      int user_thread_id = index;
      while (!closed) {
        list_box.invoke([&] {
          list_box.items().push_back(strings::format("thread: {}, counter: {}", user_thread_id, ++counter));
        });
        std::this_thread::yield();
      }
    });
    threads[index].detach();
  }
  
  application::run(form_main);
}

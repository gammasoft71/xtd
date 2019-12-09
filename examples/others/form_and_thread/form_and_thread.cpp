#include <thread>
#include <xtd/xtd.forms>

using namespace std::literals;
using namespace xtd;
using namespace xtd::forms;

int main() {
  form form_main;
  form_main.text("Form and thread example");

  list_box list_box;
  list_box.parent(form_main);
  list_box.dock(dock_style::fill);
  
  std::vector<std::thread> threads(environment::processor_count());
  for (int index = 0; index < threads.size(); index++) {
    threads[index] = std::thread([&](int user_thread_id) {
      int counter = 0;
      while (true) {
        /// simulate work...
        std::this_thread::sleep_for(500ms);
        /// call invoke method to update ui in the main thread.
        list_box.invoke([&] {
          list_box.items().push_back(strings::format("thread: {}, counter: {}", user_thread_id, ++counter));
          list_box.selected_index(list_box.items().size() - 1);
        });
      }
    }, index);
    threads[index].detach();
  }
  
  application::run(form_main);
}

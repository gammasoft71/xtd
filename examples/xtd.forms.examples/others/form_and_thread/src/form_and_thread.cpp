#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/list_box>
#include <xtd/threading/thread>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::threading;

class form_thread : public form {
public:
  form_thread() {
    text("Form and thread example");
    form_closed += [&] {
      closed = true;
      for (auto index = 0_sz; index < threads.size(); ++index)
        threads[index].join();
    };
    
    messages.parent(*this);
    messages.dock(dock_style::fill);
    
    for (auto index = 0_sz; index < threads.size(); ++index) {
      threads[index] = thread {[&](auto user_thread_id) {
        auto counter = 0u;
        while (!closed) {
          /// simulate work...
          thread::sleep(50_ms);
          ++counter;
          /// call invoke method to update UI in the main thread.
          messages.begin_invoke([&, counter, user_thread_id] {
            messages.items().push_back(ustring::format("thread {}: counter: {}", user_thread_id, counter));
            messages.selected_index(messages.items().size() - 1);
          });
        }
      }};
      threads[index].start(index);
    }
  }
  
private:
  list_box messages;
  bool closed = false;
  std::vector<thread> threads = std::vector<thread>(environment::processor_count() - 1);
};

auto main()->int {
  application::run(form_thread());
}

#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;
using namespace xtd::forms;

class form_thread : public form {
public:
  form_thread() {
    text("Form and thread example");
    form_closed += [&] {
      closed = true;
      for (auto index = 0U; index < threads.size(); ++index)
        threads[index].join();
    };
    
    messages.parent(*this);
    messages.dock(dock_style::fill);
    
    for (auto index = 0U; index < threads.size(); ++index) {
      threads[index] = thread([&](auto user_thread_id) {
        auto counter = 0U;
        while (!closed) {
          /// simulate work...
          this_thread::sleep_for(50ms);
          ++counter;
          /// call invoke method to update UI in the main thread.
          messages.begin_invoke([&, counter, user_thread_id] {
            messages.items().push_back(ustring::format("thread: {}, counter: {}", user_thread_id, counter));
            messages.selected_index(messages.items().size() - 1);
          });
        }
      }, index);
    }
  }
  
private:
  list_box messages;
  bool closed = false;
  vector<thread> threads {environment::processor_count() - 1};
};

auto main()->int {
  application::run(form_thread());
}

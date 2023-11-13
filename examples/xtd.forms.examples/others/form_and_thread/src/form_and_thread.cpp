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
    };
    
    messages.parent(*this);
    messages.dock(dock_style::fill);
    
    for (auto index = 0_sz; index < environment::processor_count() - 1; ++index) {
      thread::start_new([&] {
        auto counter = 0u;
        auto thread_name = ustring::format("thread {}", thread::current_thread().managed_thread_id());
        thread::current_thread().name(thread_name);
        while (!closed) {
          /// simulate work...
          thread::sleep(50_ms);
          ++counter;
          /// call invoke method to update UI in the main thread.
          messages.begin_invoke([&, counter, thread_name] {
            messages.items().push_back(ustring::format("{}: counter: {}", thread_name, counter));
            messages.selected_index(messages.items().size() - 1);
          });
        }
      });
    }
  }
  
private:
  list_box messages;
  bool closed = false;
};

auto main()->int {
  application::run(form_thread());
}

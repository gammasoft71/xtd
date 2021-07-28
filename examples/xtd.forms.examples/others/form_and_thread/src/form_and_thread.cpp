#include <xtd/xtd>

using namespace std::literals;
using namespace xtd::forms;

class form_thread : public form {
public:
  form_thread() {
    text("Form and thread example");
    form_closed += [&] {
      closed = true;
      for (auto index = 0U; index < threads.size(); index++)
        threads[index].join();
    };

    messages.parent(*this);
    messages.dock(dock_style::fill);
    
    for (auto index = 0U; index < threads.size(); index++) {
      threads[index] = std::thread([&](int user_thread_id) {
        auto counter = 0;
        while (!closed) {
          /// simulate work...
          std::this_thread::sleep_for(50ms);
          counter++;
          /// call invoke method to update ui in the main thread.
          messages.begin_invoke([&] {
            messages.items().push_back(xtd::ustring::format("thread: {}, counter: {}", user_thread_id, counter));
            messages.selected_index(messages.items().size() - 1);
          });
        }
      }, index);
    }
  }

private:
  xtd::forms::list_box messages;
  bool closed = false;
  std::vector<std::thread> threads {std::thread::hardware_concurrency()};
};

int main() {
  application::run(form_thread());
}

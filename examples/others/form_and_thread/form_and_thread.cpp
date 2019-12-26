#include <xtd/xtd.forms>

using namespace std::literals;
using namespace xtd::forms;

class form_thread : public form {
public:
  form_thread() {
    text("Form and thread example");
    form_closed += [this] {
      closed = true;
      for (int index = 0; index < threads.size(); index++)
        threads[index].join();
    };

    list_box.parent(*this);
    list_box.dock(dock_style::fill);
    
    for (int index = 0; index < threads.size(); index++) {
      threads[index] = std::thread([&](int user_thread_id) {
        int counter = 0;
        while (!closed) {
          /// simulate work...
          std::this_thread::sleep_for(20ms);
          counter++;
          /// call invoke method to update ui in the main thread.
          list_box.invoke([=] {
            list_box.items().push_back(xtd::strings::format("thread: {}, counter: {:d}", user_thread_id, counter));
            list_box.selected_index(list_box.items().size() - 1);
          });
        }
      }, index);
    }
  }

private:
  xtd::forms::list_box list_box;
  bool closed = false;
  //std::vector<std::thread> threads {std::thread::hardware_concurrency()};
  std::vector<std::thread> threads {1};
};

int main() {
  application::run(form_thread());
}

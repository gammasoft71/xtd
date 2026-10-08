#include <xtd/xtd>

class form_thread : public form {
public:
  form_thread() {
    text("Form and task example");
    form_closed += delegate_ {closed = true;};
    messages.parent(*this).dock(dock_style::fill);
    
    for (auto _ : enumerable::range(environment::processor_count() - 1))
      task_run_async().start();
  }
  
private:
  auto task_run_async() async_ {
    auto counter = 0;
    auto task_name = string::format("task {}", interlocked::increment(unique_id));
    
    while (!closed) {
      /// simulate work...
      co_await task<>::delay(50_ms);
      thread::sleep(50_ms);
      ++counter;
      
      /// call invoke method to update UI in the main thread.
      messages.begin_invoke(delegate_ {
        messages.items().add(string::format("{}: counter: {}", task_name, counter));
        messages.selected_index(messages.items().count() - 1);
      });
    }
  }
  
  int32 unique_id = 0;
  list_box messages;
  bool closed = false;
};

auto main() -> int {
  application::run(form_thread());
}

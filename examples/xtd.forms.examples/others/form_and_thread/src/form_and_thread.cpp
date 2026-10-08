#include <xtd/xtd>

class form_thread : public form {
public:
  form_thread() {
    text("Form and thread example");
    form_closed += delegate_ {closed = true;};
    messages.parent(*this).dock(dock_style::fill);
    
    for (auto _ : enumerable::range(environment::processor_count() - 1))
      thread::start_new({self_, &form_thread::thread_proc});
  }
  
private:
  auto thread_proc() -> void {
    auto counter = 0;
    auto thread_name = string::format("thread {}", interlocked::increment(unique_id));
    
    while (!closed) {
      /// simulate work...
      thread::sleep(50_ms);
      ++counter;
      
      /// call invoke method to update UI in the main thread.
      messages.begin_invoke(delegate_ {
        messages.items().add(string::format("{}: counter: {}", thread_name, counter));
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

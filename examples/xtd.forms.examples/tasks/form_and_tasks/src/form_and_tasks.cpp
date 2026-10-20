#include <xtd/xtd>

class form_and_tasks : public form {
public:
  form_and_tasks() {
    text("Form and tasks");
    form_closed += delegate_ {closed = true;};
    messages.parent(self_).dock(dock_style::fill);
    
    for (auto id : enumerable::range(1_z, environment::processor_count() - 1_z))
      task_runner_async(id);
  }
  
private:
  auto task_runner_async(auto id) async_ {
    return task<>::factory().start_new([&, id] {
      auto counter = 0;
      auto task_name = string::format("task {}", id);
      
      while (!closed) {
        /// simulate work...
        thread::sleep(50_ms);
        ++counter;
        
        /// call xtd::foms::control::begin_invoke method to update UI in the main thread.
        begin_invoke(delegate_ {
          messages.items().add(string::format("{}: counter: {}", task_name, counter));
          messages.selected_index(messages.items().count() - 1);
        });
      }
    });
  }
  
  list_box messages;
  bool closed = false;
};

auto main() -> int {
  application::run(form_and_tasks());
}

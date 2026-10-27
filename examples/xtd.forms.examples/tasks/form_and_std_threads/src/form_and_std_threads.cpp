#include <xtd/xtd>
#include <atomic>
#include <thread>

class form_and_threads : public form {
public:
  form_and_threads() {
    text("Form and threads (std::thread)");
    form_closed += delegate_ {closed = true;};
    messages.parent(self_).dock(dock_style::fill);
   
    form_closed += [this] {
      for (auto& thread : threads)
        if (thread.joinable()) thread.join();
    };
    
    for (auto id : enumerable::range(1_z, environment::processor_count() - 1))
      threads.add(thread_runner(id));
  }
  
private:
  auto thread_runner(auto id) -> std::thread {
    return std::thread {[&, id] {
      using namespace std::literals;
      auto counter = 0;
      auto thread_name = string::format("thread {}", id);
      
      while (!closed) {
        /// simulate work...
        std::this_thread::sleep_for(50ms);
        ++counter;
        
        /// call xtd::foms::control::begin_invoke method to update UI in the main thread.
        begin_invoke(delegate_ {
          messages.items().add(string::format("{}: counter: {}", thread_name, counter));
          messages.selected_index(messages.items().count() - 1);
        });
      }
    }};
  }
    
  list_box messages;
  std::atomic<bool> closed = false;
  list<std::thread> threads;
};

auto main() -> int {
  application::run(form_and_threads {});
}

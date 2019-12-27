#include <thread>
#include <xtd/xtd.forms>

using namespace std;
using namespace std::literals;
using namespace xtd;
using namespace xtd::forms;

class something_ready_notifier {
public:
  something_ready_notifier() = default;
  
  /// @brief Event raised when something is ready. The event is always raised in the message loop of the thread where this object was created.
  event<something_ready_notifier, event_handler<const something_ready_notifier&>> something_ready;
  
  void on_something_ready() {
    something_ready.invoke(*this, event_args::empty);
  }
  
  /// @brief Causes the something_ready event to be raised on the message loop of the thread which created this object.
  /// @remarks Can safely be called from any thread. Always returns immediately without waiting for the event to be handled.
  void notify_something_ready() {
    synchronizer.begin_invoke({*this, &something_ready_notifier::on_something_ready});
  }
  
protected:
  form synchronizer;
};

class form1 : public form {
public:
  form1() {
    text("Send messages to form");
    location({100, 100});
    client_size({300, 300});
    controls().push_back_range({button, list_box});
    
    notifier.something_ready += [&] {
      static int counter = 0;
      list_box.items().push_back(strings::format("Something ready notified {} times", ++counter));
      list_box.selected_index(list_box.items().size() - 1);
    };
    
    button.auto_size(true);
    button.location({10, 10});
    button.text("Send async notify something ready");
    button.click += [this] {
      thread async_thread([this] {
        this_thread::sleep_for(2s);
        notifier.notify_something_ready();
      });
      async_thread.detach();
    };
    
    list_box.location({10, 50});
    list_box.size({280, 240});
  }
  
protected:
  forms::button button;
  forms::list_box list_box;
  something_ready_notifier notifier;
};

int main() {
  application::run(form1());
}

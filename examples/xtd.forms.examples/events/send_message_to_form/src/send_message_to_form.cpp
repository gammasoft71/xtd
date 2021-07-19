#include <thread>
#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;
using namespace xtd::forms;

class something_ready_notifier : public object{
public:
  something_ready_notifier() = default;
  
  /// @brief Event raised when something is ready. The event is always raised in the message loop of the thread where this object was created.
  event<something_ready_notifier, event_handler> something_ready;
  
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
    controls().push_back_range({button_send, list_box_messages});
    
    notifier.something_ready += [&] {
      static auto counter = 0;
      list_box_messages.items().push_back(strings::format("Something ready notified {} times", ++counter));
      list_box_messages.selected_index(list_box_messages.items().size() - 1);
    };
    
    button_send.auto_size(true);
    button_send.location({10, 10});
    button_send.text("Send async notify something ready");
    button_send.click += [&] {
      thread async_thread([&] {
        this_thread::sleep_for(2s);
        notifier.notify_something_ready();
      });
      async_thread.detach();
    };
    
    list_box_messages.location({10, 50});
    list_box_messages.size({280, 240});
  }
  
protected:
  button button_send;
  list_box list_box_messages;
  something_ready_notifier notifier;
};

int main() {
  application::run(form1());
}

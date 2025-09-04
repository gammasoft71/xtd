#include <xtd/xtd>

class something_ready_notifier : public object {
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
  static void main() {
    application::run(form1 {});
  }

  form1() {
    text("Send messages to form");
    location({100, 100});
    client_size({300, 300});
    controls().add_range({button_send, list_box_messages});
    
    notifier.something_ready += delegate_ {
      static auto counter = 0;
      list_box_messages.items().add(string::format("Something ready notified {} times", ++counter));
      list_box_messages.selected_index(list_box_messages.items().count() - 1);
    };
    
    button_send.auto_size(true);
    button_send.location({10, 10});
    button_send.text("Send async notify something ready");
    button_send.click += delegate_ {
      thread_pool::queue_user_work_item([&] {
        thread::sleep(2_s);
        notifier.notify_something_ready();
      });
    };
    
    list_box_messages.location({10, 50});
    list_box_messages.size({280, 240});
  }
  
protected:
  button button_send;
  list_box list_box_messages;
  something_ready_notifier notifier;
};

startup_(form1::main);

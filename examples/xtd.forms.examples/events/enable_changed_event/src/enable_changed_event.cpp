#include <xtd/xtd>

namespace enable_changed_event_example {
  class form1 : public form {
  public:
    form1() {
      radio_button1.location({0, 0});
      radio_button1.name("radio_button1");
      radio_button1.size({100, 17});
      radio_button1.text("button1");
      radio_button1.enabled_changed += event_handler {self_, &form1::radio_button1_enabled_changed};
      
      radio_button2.location({0, 39});
      radio_button2.name("radio_button2");
      radio_button2.size({150, 17});
      radio_button2.text("Disable button1");
      radio_button2.checked_changed += event_handler {self_, &form1::radio_button2_checked_changed};
      
      client_size({292, 273});
      controls().add_range({radio_button1, radio_button2});
      name("Form1");
    }
    
  private:
    auto radio_button1_enabled_changed(object& sender, const event_args& e) -> void {
      message_box::show("This button has been disabled.");
    }
    
    auto radio_button2_checked_changed(object& sender, const event_args& e) -> void {
      radio_button1.enabled(false);
    }
    
    radio_button radio_button1;
    radio_button radio_button2;
  };
}

auto main() -> int {
  application::run(enable_changed_event_example::form1 {});
}

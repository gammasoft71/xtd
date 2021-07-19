#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      radio_button1.location({0, 0});
      radio_button1.name("radio_button1");
      radio_button1.size({100, 17});
      radio_button1.text("button1");
      radio_button1.enabled_changed += event_handler(*this, &form1::radio_button1_enabled_changed);

      radio_button2.location({0, 39});
      radio_button2.name("radio_button2");
      radio_button2.size({150, 17});
      radio_button2.text("Disable button1");
      radio_button2.checked_changed += event_handler(*this, &form1::radio_button2_checked_changed);

      client_size({292, 273});
      controls().push_back_range({radio_button1, radio_button2});
      name("Form1");
    }
    
  private:
    void radio_button1_enabled_changed(object& sender, const event_args& e) {
      message_box::show("This button has been disabled.");
    }

    void radio_button2_checked_changed(object& sender, const event_args& e) {
      radio_button1.enabled(false);
    }
    
    radio_button radio_button1;
    radio_button radio_button2;
  };
}

int main() {
  application::run(examples::form1());
}

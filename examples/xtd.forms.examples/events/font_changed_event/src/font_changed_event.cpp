#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      radio_button1.location({0, 0});
      radio_button1.name("radio_button1");
      radio_button1.size({150, 25});
      radio_button1.text("button1");
      radio_button1.font_changed += {*this, &form1::radio_button1_font_changed};

      radio_button2.location({0, 39});
      radio_button2.name("radio_button2");
      radio_button2.size({150, 17});
      radio_button2.text("Change button1 font");
      radio_button2.checked_changed += {*this, &form1::radio_button2_checked_changed};

      client_size({292, 273});
      controls().push_back_range({radio_button1, radio_button2});
      name("Form1");
    }
    
  private:
    void radio_button1_font_changed(object& sender, const event_args& e) {
      message_box::show("The font has been chenged.");
    }

    void radio_button2_checked_changed(object& sender, const event_args& e) {
      radio_button1.font({radio_button1.font().font_family(), 15.0f, drawing::font_style::bold|drawing::font_style::italic, drawing::graphics_unit::point, 0});
    }
    
    radio_button radio_button1;
    radio_button radio_button2;
  };
}

int main() {
  application::run(examples::form1());
}

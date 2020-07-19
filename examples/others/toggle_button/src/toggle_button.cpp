#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({280, 180});
    controls().push_back_range({button_red, button_green, button_blue, panel_color});
    text("Toggle button example");

    button_red.location({20, 20});
    button_red.appearance(forms::appearance::button);
    button_red.text("Red");
    button_red.checked_changed += {*this, &form1::update_color};

    button_green.location({20, 70});
    button_green.appearance(forms::appearance::button);
    button_green.text("Green");
    button_green.checked_changed += {*this, &form1::update_color};

    button_blue.location({20, 120});
    button_blue.appearance(forms::appearance::button);
    button_blue.text("Blue");
    button_blue.checked_changed += {*this, &form1::update_color};

    panel_color.border_style(forms::border_style::fixed_3d);
    panel_color.location({150, 20});
    panel_color.size({110, 110});
    
    update_color(*this, event_args::empty);
  }
  
private:
  void update_color(control& sender, const event_args& e) {
    panel_color.back_color(color::from_argb(button_red.checked() ? 255 : 0, button_green.checked() ? 255 : 0, button_blue.checked() ? 255 : 0));
  }

  check_box button_red;
  check_box button_green;
  check_box button_blue;
  panel panel_color;
};

int main() {
  application::run(form1());
}

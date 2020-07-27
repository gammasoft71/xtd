#include <xtd/xtd.forms>

namespace tutorial {
  class panel_right : public xtd::forms::panel {
  public:
    panel_right() {
      border_style(xtd::forms::border_style::fixed_3d);
      controls().push_back(label);
      dock(xtd::forms::dock_style::fill);
      size({150, 100});

      label.location({65, 45});
      label.text("0");
    }
    
    xtd::forms::label label;
  };

  class panel_left : public xtd::forms::panel {
  public:
    panel_left() {
      border_style(xtd::forms::border_style::fixed_3d);
      controls().push_back_range({button_plus, button_minus});
      dock(xtd::forms::dock_style::left);
      size({150, 100});
      
      button_plus.auto_repeat(true);
      button_plus.location({30, 10});
      button_plus.text("+");
      button_plus.click += [&] {
        count++;
        control& form = parent().value().get();
        static_cast<panel_right&>(form.controls()[0].get()).label.text(xtd::strings::format("{}", count));
      };

      button_minus.auto_repeat(true);
      button_minus.location({30, 60});
      button_minus.text("-");
      button_minus.click += [&] {
        count--;
        control& form = parent().value().get();
        static_cast<panel_right&>(form.controls()[0].get()).label.text(xtd::strings::format("{}", count));
      };
    }

    xtd::forms::button button_plus;
    xtd::forms::button button_minus;
    int count = 0;
  };

  class communicate : public xtd::forms::form {
  public:
    communicate() {
      client_size({300, 100});
      controls().push_back_range({panel_right, panel_left});
      text("communicate");
    }

    static void main() {
      xtd::forms::application::run(communicate());
    }
    
    panel_left panel_left;
    panel_right panel_right;
  };
}

startup_(tutorial::communicate);

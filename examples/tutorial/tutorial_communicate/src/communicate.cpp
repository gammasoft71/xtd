#include <xtd/xtd.forms>

namespace tutorial {
  class panel_right : public xtd::forms::panel {
  public:
    panel_right() {
      border_style(xtd::forms::border_style::fixed_3d);
      controls().push_back(label_);
      dock(xtd::forms::dock_style::fill);
      size({150, 100});

      label_.location({65, 45});
      label_.text("0");
    }
    
    xtd::forms::label label_;
  };

  class panel_left : public xtd::forms::panel {
  public:
    panel_left() {
      border_style(xtd::forms::border_style::fixed_3d);
      controls().push_back_range({button_plus_, button_minus_});
      dock(xtd::forms::dock_style::left);
      size({150, 100});
      
      button_plus_.auto_repeat(true);
      button_plus_.location({30, 10});
      button_plus_.text("+");
      button_plus_.click += [&] {
        count++;
        control& form = parent().value().get();
        static_cast<panel_right&>(form.controls()[0].get()).label_.text(xtd::strings::format("{}", count));
      };

      button_minus_.auto_repeat(true);
      button_minus_.location({30, 60});
      button_minus_.text("-");
      button_minus_.click += [&] {
        count--;
        control& form = parent().value().get();
        static_cast<panel_right&>(form.controls()[0].get()).label_.text(xtd::strings::format("{}", count));
      };
    }

    xtd::forms::button button_plus_;
    xtd::forms::button button_minus_;
    int count = 0;
  };

  class communicate : public xtd::forms::form {
  public:
    communicate() {
      client_size({300, 100});
      controls().push_back_range({panel_right_, panel_left_});
      text("communicate");
    }

    static void main() {
      xtd::forms::application::run(communicate());
    }
    
    panel_left panel_left_;
    panel_right panel_right_;
  };
}

startup_(tutorial::communicate);

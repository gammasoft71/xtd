#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::windows::forms;

class form_main : public form {
public:
  static void main() {
    application::run(form_main());
  }

  form_main() {
    auto_size(true);
    auto_size_mode(forms::auto_size_mode::grow_and_shrink);
    close_box(false);
    maximize_box(false);
    minimize_box(false);
    control_box(false);
    form_border_style(forms::form_border_style::none);
    opacity(0.5);

    label1.parent(*this);
    label1.fore_color(color::lime);
    label1.height(50);
    label1.auto_size(true);
    label1.lcd_style(lcd_style::dot_matrix_display);
    label1.text("LCD DISPLAY");
    label1.mouse_down += [&](object& sender, const mouse_event_args& e) {
      mouse_location = e.location();
      label1.cursor(cursors::no_move_2d());
    };
    label1.mouse_up += [&](object& sender, const mouse_event_args& e) {
      mouse_location = point::empty;
      label1.cursor(cursors::default_cursor());
    };
    label1.mouse_move += [&](object& sender, const mouse_event_args& e) {
      if (mouse_location != point::empty) this->location(this->location() + e.location() - mouse_location);
    };
  }

private:
  lcd_label label1;
  point mouse_location = point::empty;
};

startup_(form_main);

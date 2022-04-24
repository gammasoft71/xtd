#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;

class form_main : public form {
public:
  static void main() {
    application::run(form_main());
  }
  
  form_main() {
    close_box(false);
    maximize_box(false);
    minimize_box(false);
    control_box(false);
    form_border_style(forms::form_border_style::none);
    client_size({300, 300});
    graphics_path path;
    path.add_ellipse(client_rectangle());
    region(drawing::region(path));
    
    paint += [&](object& sender, paint_event_args& e) {
      e.graphics().fill_rectangle(linear_gradient_brush(e.clip_rectangle(), {color::blue, color::black, color::blue}, 45), e.clip_rectangle());
    };
    
    mouse_down += [&](object & sender, const mouse_event_args & e) {
      mouse_location = e.location();
      cursor(cursors::no_move_2d());
    };
    mouse_up += [&](object & sender, const mouse_event_args & e) {
      mouse_location = point::empty;
      cursor(cursors::default_cursor());
    };
    mouse_move += [&](object & sender, const mouse_event_args & e) {
      if (mouse_location != point::empty) this->location(this->location() + e.location() - mouse_location);
    };
    
    close_button.parent(*this);
    close_button.location({client_size().width() / 2 - close_button.width() / 2, client_size().height() / 2 - close_button.height() / 2});
    close_button.fore_color(color::red);
    close_button.text("close");
    close_button.click += [&] {
      application::exit();
    };
  }
  
private:
  button close_button;
  panel custom_panel;
  point mouse_location = point::empty;
};

startup_(form_main);

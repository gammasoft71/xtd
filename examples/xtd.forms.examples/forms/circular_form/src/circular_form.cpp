#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;

class form_main : public form {
public:
  static auto main() {
    application::run(form_main());
  }
  
  form_main() {
    form_border_style(forms::form_border_style::none);
    client_size({300, 300});
    
    // Create a circular region for the form
    graphics_path path;
    path.add_ellipse(client_rectangle());
    region(drawing::region(path));
    
    paint += [&](object& sender, paint_event_args& e) {
      e.graphics().fill_rectangle(linear_gradient_brush(e.clip_rectangle(), {color::black, color::blue, color::black}, 90), e.clip_rectangle());
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
      if (mouse_location != point::empty) location(location() + e.location() - mouse_location);
    };
    
    close_button.parent(*this);
    close_button.location({client_size().width() / 2 - close_button.width() / 2, client_size().height() / 2 - close_button.height() / 2});
    close_button.back_color(color::from_argb(32, color::white));
    close_button.fore_color(color::dark_blue);
    close_button.text("close");
    close_button.click += [&] {
      close();
    };
  }
  
private:
  button close_button;
  point mouse_location = point::empty;
};

startup_(form_main);

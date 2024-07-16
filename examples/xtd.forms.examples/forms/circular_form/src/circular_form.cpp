#include <xtd/drawing/drawing_2d/radial_gradient_brush>
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;

class form_main : public form {
public:
  static auto main() {
    application::run(form_main());
  }
  
  form_main() {
    form_border_style(forms::form_border_style::none);
    start_position(form_start_position::manual);
    client_size({200, 200});
    double_buffered(true);
    location({screen::from_control(*this).working_area().left() + screen::from_control(*this).working_area().width() / 2 - client_size().width() / 2, screen::from_control(*this).working_area().bottom() - client_size().height()});
    top_most(true);
    
    // Create a circular region for the form
    graphics_path path;
    path.add_ellipse(client_rectangle());
    region(drawing::region(path));
    
    paint += [&](object& sender, paint_event_args& e) {
      auto gradient_color1 = color::from_argb(0xBC, 0, 0);
      auto gradient_color2 = color::from_argb(0xFF, 0xAA, 0x7E);
      e.graphics().fill_rectangle(radial_gradient_brush {point {80, 70}, {gradient_color2, gradient_color1}, 110}, e.clip_rectangle());
    };
    
    mouse_down += [&](object& sender, const mouse_event_args& e) {
      mouse_location = e.location();
      cursor(cursors::hand());
    };
    
    mouse_up += [&](object& sender, const mouse_event_args& e) {
      mouse_location = point::empty;
      cursor(cursors::default_cursor());
    };
    
    mouse_move += [&](object& sender, const mouse_event_args& e) {
      if (mouse_location == point::empty) return;
      auto working_area = screen::from_control(*this).working_area();
      auto new_bounds = bounds();
      new_bounds.location(new_bounds.location() + e.location() - mouse_location);
      if (new_bounds.left() < working_area.left()) new_bounds.location({working_area.left(), new_bounds.top()});
      if (new_bounds.top() < working_area.top()) new_bounds.location({new_bounds.left(), working_area.top()});
      if (new_bounds.left() + new_bounds.width() > working_area.right()) new_bounds.location({working_area.right() - new_bounds.width(), new_bounds.top()});
      if (new_bounds.top() + new_bounds.height() > working_area.bottom()) new_bounds.location({new_bounds.left(), working_area.bottom() - new_bounds.height()});
      bounds(new_bounds);
    };
  }
  
private:
  point mouse_location = point::empty;
};

startup_(form_main::main);

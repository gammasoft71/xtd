#include <xtd/xtd.forms.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;

class lines_form : public form {
public:
  static void main() {
    application::run(lines_form());
  }
  
  lines_form() {
    text("Lines tests");
    padding(5);
    client_size({800, 450});

    tab_control.parent(*this);
    tab_control.dock(dock_style::fill);
    
    tab_page_color.parent(tab_control);
    tab_page_color.text("Color");
    tab_page_color.paint += {*this, &lines_form::draw_pens_with_color};
    
    tab_page_brush.parent(tab_control);
    tab_page_brush.text("Brush");
    tab_page_brush.paint += {*this, &lines_form::draw_pens_with_brush};
    
    tab_page_dash.parent(tab_control);
    tab_page_dash.text("Dash");
    tab_page_dash.paint += {*this, &lines_form::draw_pens_with_dash};

    tab_page_cap.parent(tab_control);
    tab_page_cap.text("Cap");
    tab_page_cap.paint += {*this, &lines_form::draw_pens_with_cap};

    tab_page_alignment.parent(tab_control);
    tab_page_alignment.text("Alignment");
    tab_page_alignment.paint += {*this, &lines_form::draw_pens_with_alignment};
  }
  
private:
  forms::tab_control tab_control;
  forms::tab_page tab_page_color;
  forms::tab_page tab_page_brush;
  forms::tab_page tab_page_dash;
  forms::tab_page tab_page_cap;
  forms::tab_page tab_page_alignment;
  void draw_grid(const rectangle& rect, drawing::graphics& graphics, const drawing::size& grid_size = drawing::size(5, 5)) {
    auto color1 = back_color().is_dark() ? color::light(back_color()) : color::dark(back_color());
    auto color2 = color1.is_dark() ? color::light(color1) : color::dark(color1);
    for (auto x = rect.left(); x < rect.right(); x += grid_size.width())
      graphics.draw_line(pen(color1, 1), point(x, rect.top()), point(x, rect.bottom()));
    for (auto y = rect.top(); y < rect.bottom(); y += grid_size.height())
      graphics.draw_line(pen(color1, 1), point(rect.left(), y), point(rect.right(), y));
    for (auto x = rect.left(); x < rect.right(); x += grid_size.width() * 10)
      graphics.draw_line(pen(color2, 1), point(x, rect.top()), point(x, rect.bottom()));
    for (auto y = rect.top(); y < rect.bottom(); y += grid_size.height() * 10)
      graphics.draw_line(pen(color2, 1), point(rect.left(), y), point(rect.right(), y));
  }
  
  void draw_pens_with_color(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());

    e.graphics().draw_line(pen(color::red, 1), point(50, 25), point(250, 25));
    e.graphics().draw_line(pen(color::green, 2), point(50, 50), point(250, 50));
    e.graphics().draw_line(pen(color::blue, 5), point(50, 75), point(250, 75));
    e.graphics().draw_line(pen(color::yellow, 10), point(50, 100), point(250, 100));

    e.graphics().draw_line(pen(color::red, 1), point(50, 150), point(50, 350));
    e.graphics().draw_line(pen(color::green, 2), point(75, 150), point(75, 350));
    e.graphics().draw_line(pen(color::blue, 5), point(100, 150), point(100, 350));
    e.graphics().draw_line(pen(color::yellow, 10), point(125, 150), point(125, 350));
  }
  
  void draw_pens_with_brush(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    e.graphics().draw_line(pen(solid_brush(color::red), 10), point(50, 25), point(250, 25));
    e.graphics().draw_line(pen(hatch_brush(xtd::drawing::drawing2d::hatch_style::cross, color::red, color::blue), 10), point(50, 50), point(250, 50));
  }
  
  void draw_pens_with_dash(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    auto pen1 = pen(color::red, 4);
    pen1.dash_style(drawing::dash_style::dot);
    e.graphics().draw_line(pen1, point(50, 25), point(250, 25));
    
    auto pen2 = pen(color::red, 4);
    pen2.dash_style(drawing::dash_style::dash);
    e.graphics().draw_line(pen2, point(50, 50), point(250, 50));
    
    auto pen3 = pen(color::red, 4);
    pen3.dash_style(drawing::dash_style::dash_dot);
    e.graphics().draw_line(pen3, point(50, 75), point(250, 75));
    
    auto pen4 = pen(color::red, 4);
    pen4.dash_style(drawing::dash_style::dash_dot_dot);
    e.graphics().draw_line(pen4, point(50, 100), point(250, 100));
  }
  
  void draw_pens_with_cap(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    e.graphics().draw_line(pen(solid_brush(color::red), 10), point(50, 25), point(250, 25));
  }
  
  void draw_pens_with_alignment(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    auto pen1 = pen(color::red, 10);
    pen1.alignment(xtd::drawing::drawing2d::pen_alignment::center);
    e.graphics().draw_line(pen1, point(50, 50), point(250, 50));
    
    auto pen2 = pen(color::red, 10);
    pen1.alignment(xtd::drawing::drawing2d::pen_alignment::inset);
    e.graphics().draw_line(pen2, point(50, 100), point(250, 100));
  }

};

startup_(lines_form);


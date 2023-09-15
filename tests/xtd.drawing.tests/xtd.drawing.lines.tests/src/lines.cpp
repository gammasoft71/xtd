#include <xtd/drawing/drawing_2d/conical_gradient_brush>
#include <xtd/drawing/drawing_2d/hatch_brush>
#include <xtd/drawing/drawing_2d/linear_gradient_brush>
#include <xtd/drawing/drawing_2d/radial_gradient_brush>
#include <xtd/drawing/pens>
#include <xtd/drawing/texture_brush>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/tab_control>
#include <xtd/forms/tab_page>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;

class lines_form : public form {
public:
  static auto main() {
    application::run(lines_form());
  }
  
  lines_form() {
    text("Lines tests");
    padding(5);
    client_size({800, 600});
    
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
    auto color2 = fore_color().is_dark() ? color::light(fore_color()) : color::dark(fore_color());
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
    
    e.graphics().draw_line(pen(color::red, 1), point(50, 50), point(250, 50));
    e.graphics().draw_line(pen(color::green, 2), point(50, 100), point(250, 100));
    e.graphics().draw_line(pen(color::blue, 5), point(50, 150), point(250, 150));
    e.graphics().draw_line(pen(color::yellow, 10), point(50, 200), point(250, 200));
    
    e.graphics().draw_line(pen(color::red, 1), point(350, 50), point(350, 250));
    e.graphics().draw_line(pen(color::green, 2), point(400, 50), point(400, 250));
    e.graphics().draw_line(pen(color::blue, 5), point(450, 50), point(450, 250));
    e.graphics().draw_line(pen(color::yellow, 10), point(500, 50), point(500, 250));
  }
  
  void draw_pens_with_brush(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    e.graphics().draw_line(pen(solid_brush(color::yellow), 20), point(50, 50), point(250, 50));
    e.graphics().draw_line(pen(hatch_brush(xtd::drawing::drawing_2d::hatch_style::solid_diamond, color::blue, color::yellow), 20), point(50, 100), point(250, 100));
    e.graphics().draw_line(pen(conical_gradient_brush(point(150, 150), {color::blue, color::yellow}, 0), 20), point(50, 150), point(250, 150));
    e.graphics().draw_line(pen(linear_gradient_brush(rectangle(50, 200, 250, 10), {color::blue, color::yellow}, 0), 20), point(50, 200), point(250, 200));
    e.graphics().draw_line(pen(radial_gradient_brush(point(150, 250), {color::blue, color::yellow}, 20), 20), point(50, 250), point(250, 250));
    e.graphics().draw_line(pen(texture_brush(create_circle_texture_image(color::blue, color::yellow)), 20), point(50, 300), point(250, 300));
  }
  
  void draw_pens_with_dash(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    e.graphics().draw_line(pen(color::red, 10).dash_style(drawing::dash_style::dot), point(50, 50), point(250, 50));
    e.graphics().draw_line(pen(color::red, 10).dash_style(drawing::dash_style::dash), point(50, 100), point(250, 100));
    e.graphics().draw_line(pen(color::red, 10).dash_style(drawing::dash_style::dash_dot), point(50, 150), point(250, 150));
    e.graphics().draw_line(pen(color::red, 10).dash_style(drawing::dash_style::dash_dot_dot), point(50, 200), point(250, 200));
  }
  
  void draw_pens_with_cap(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    e.graphics().draw_line(pen(solid_brush(color::red), 10), point(50, 50), point(250, 50));
    e.graphics().draw_line(pen(solid_brush(color::red), 10).start_cap(xtd::drawing::drawing_2d::line_cap::square).end_cap(xtd::drawing::drawing_2d::line_cap::square), point(50, 100), point(250, 100));
    e.graphics().draw_line(pen(solid_brush(color::red), 10).start_cap(xtd::drawing::drawing_2d::line_cap::round).end_cap(xtd::drawing::drawing_2d::line_cap::round), point(50, 150), point(250, 150));
  }
  
  void draw_pens_with_alignment(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    e.graphics().draw_line(pen(color::red, 10).alignment(xtd::drawing::drawing_2d::pen_alignment::center), point(50, 50), point(250, 50));
    e.graphics().draw_line(pen(color::red, 10).alignment(xtd::drawing::drawing_2d::pen_alignment::inset), point(50, 100), point(250, 100));
  }
  
  static image create_circle_texture_image(const color& foreground_color, const color& background_color) {
    static auto texture = bitmap(16, 16);
    auto graphics = texture.create_graphics();
    graphics.fill_rectangle(solid_brush(background_color), 0, 0, texture.width(), texture.height());
    graphics.draw_ellipse(pens::black(), 0, 0, texture.width() - 1, texture.height() - 1);
    graphics.fill_ellipse(solid_brush(foreground_color), 1, 1, texture.width() - 2, texture.height() - 2);
    return texture;
  }
  
};

startup_(lines_form::main);

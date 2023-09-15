#include <xtd/drawing/drawing_2d/conical_gradient_brush>
#include <xtd/drawing/drawing_2d/hatch_brush>
#include <xtd/drawing/drawing_2d/linear_gradient_brush>
#include <xtd/drawing/drawing_2d/radial_gradient_brush>
#include <xtd/drawing/pens>
#include <xtd/drawing/system_images>
#include <xtd/drawing/texture_brush>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/tab_control>
#include <xtd/forms/tab_page>
#include <xtd/startup>

using namespace std;
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
    text("Rectangle tests");
    padding(5);
    client_size({900, 650});
    
    tab_control.parent(*this);
    tab_control.dock(dock_style::fill);
    
    tab_page_draw_color.parent(tab_control);
    tab_page_draw_color.text("Draw color");
    tab_page_draw_color.paint += {*this, &lines_form::draw_rectangle_with_color};
    
    tab_page_draw_dash.parent(tab_control);
    tab_page_draw_dash.text("Draw dash");
    tab_page_draw_dash.paint += {*this, &lines_form::draw_rectangle_with_dash};
    
    tab_page_fill_color.parent(tab_control);
    tab_page_fill_color.text("Fill color");
    tab_page_fill_color.paint += {*this, &lines_form::fill_rectangle_with_color};
    
    tab_page_fill_conical_gradient.parent(tab_control);
    tab_page_fill_conical_gradient.text("Fill conical gradient");
    tab_page_fill_conical_gradient.paint += {*this, &lines_form::fill_rectangle_with_conical_gradient};
    
    tab_page_fill_linear_gradient.parent(tab_control);
    tab_page_fill_linear_gradient.text("Fill linear gradient");
    tab_page_fill_linear_gradient.paint += {*this, &lines_form::fill_rectangle_with_linear_gradient};
    
    tab_page_fill_radial_gradient.parent(tab_control);
    tab_page_fill_radial_gradient.text("Fill radial gradient");
    tab_page_fill_radial_gradient.paint += {*this, &lines_form::fill_rectangle_with_radial_gradient};
    
    tab_page_fill_pattern.parent(tab_control);
    tab_page_fill_pattern.text("Fill pattern");
    tab_page_fill_pattern.paint += {*this, &lines_form::fill_rectangle_with_pattern};
    
    tab_page_fill_texture.parent(tab_control);
    tab_page_fill_texture.text("Fill texture");
    tab_page_fill_texture.paint += {*this, &lines_form::fill_rectangle_with_texture};
  }
  
private:
  forms::tab_control tab_control;
  forms::tab_page tab_page_draw_color;
  forms::tab_page tab_page_draw_dash;
  forms::tab_page tab_page_fill_color;
  forms::tab_page tab_page_fill_conical_gradient;
  forms::tab_page tab_page_fill_linear_gradient;
  forms::tab_page tab_page_fill_radial_gradient;
  forms::tab_page tab_page_fill_pattern;
  forms::tab_page tab_page_fill_texture;
  
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
  
  void draw_rectangle_with_color(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    e.graphics().draw_rectangle(pen(color::transparent, 1), rectangle(50, 50, 150, 100));
    e.graphics().draw_rectangle(pen(color::black, 1), rectangle(250, 50, 150, 100));
    e.graphics().draw_rectangle(pen(color::white, 1), rectangle(450, 50, 150, 100));
    e.graphics().draw_rectangle(pen(application::style_sheet().system_colors().control_text(), 1), rectangle(650, 50, 150, 100));
    
    e.graphics().draw_rectangle(pen(color::red, 4), rectangle(50, 200, 150, 100));
    e.graphics().draw_rectangle(pen(color::green, 4), rectangle(250, 200, 150, 100));
    e.graphics().draw_rectangle(pen(color::blue, 4), rectangle(450, 200, 150, 100));
    e.graphics().draw_rectangle(pen(color::yellow, 4), rectangle(650, 200, 150, 100));
    
    e.graphics().draw_rectangle(pen(color::from_argb(128, color::red), 10), rectangle(50, 350, 150, 100));
    e.graphics().draw_rectangle(pen(color::from_argb(128, color::green), 10), rectangle(250, 350, 150, 100));
    e.graphics().draw_rectangle(pen(color::from_argb(128, color::blue), 10), rectangle(450, 350, 150, 100));
    e.graphics().draw_rectangle(pen(color::from_argb(128, color::yellow), 10), rectangle(650, 350, 150, 100));
  }
  
  void draw_rectangle_with_dash(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    static const auto fereground_color = color::red;
    
    static auto pen_dot = pen(fereground_color, 5);
    pen_dot.dash_style(drawing::dash_style::dot);
    e.graphics().draw_rectangle(pen_dot, rectangle(50, 50, 150, 100));
    
    static auto pen_dash = pen(fereground_color, 5);
    pen_dash.dash_style(drawing::dash_style::dash);
    e.graphics().draw_rectangle(pen_dash, rectangle(250, 50, 150, 100));
    
    static auto pen_dash_dot = pen(fereground_color, 5);
    pen_dash_dot.dash_style(drawing::dash_style::dash_dot);
    e.graphics().draw_rectangle(pen_dash_dot, rectangle(450, 50, 150, 100));
    
    static auto pen_dash_dot_dot = pen(fereground_color, 5);
    pen_dash_dot_dot.dash_style(drawing::dash_style::dash_dot_dot);
    e.graphics().draw_rectangle(pen_dash_dot_dot, rectangle(650, 50, 150, 100));
    
    static auto pen_custom = pen(fereground_color, 5);
    pen_custom.dash_style(drawing::dash_style::custom);
    pen_custom.dash_pattern({6, 2, 4, 2, 4, 2});
    e.graphics().draw_rectangle(pen_custom, rectangle(50, 200, 150, 100));
  }
  
  void fill_rectangle_with_color(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    e.graphics().fill_rectangle(solid_brush(color::transparent), rectangle(50, 50, 150, 100));
    e.graphics().fill_rectangle(solid_brush(color::black), rectangle(250, 50, 150, 100));
    e.graphics().fill_rectangle(solid_brush(color::white), rectangle(450, 50, 150, 100));
    e.graphics().fill_rectangle(solid_brush(application::style_sheet().system_colors().control_text()), rectangle(650, 50, 150, 100));
    
    e.graphics().fill_rectangle(solid_brush(color::red), rectangle(50, 200, 150, 100));
    e.graphics().fill_rectangle(solid_brush(color::green), rectangle(250, 200, 150, 100));
    e.graphics().fill_rectangle(solid_brush(color::blue), rectangle(450, 200, 150, 100));
    e.graphics().fill_rectangle(solid_brush(color::yellow), rectangle(650, 200, 150, 100));
    
    e.graphics().fill_rectangle(solid_brush(color::from_argb(128, color::red)), rectangle(50, 350, 150, 100));
    e.graphics().fill_rectangle(solid_brush(color::from_argb(128, color::green)), rectangle(250, 350, 150, 100));
    e.graphics().fill_rectangle(solid_brush(color::from_argb(128, color::blue)), rectangle(450, 350, 150, 100));
    e.graphics().fill_rectangle(solid_brush(color::from_argb(128, color::yellow)), rectangle(650, 350, 150, 100));
  }
  
  void fill_rectangle_with_conical_gradient(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    static const auto color1 = color::red;
    static const auto color2 = color::green;
    static const auto color3 = color::blue;
    static const auto color4 = color::yellow;
    
    e.graphics().fill_rectangle(conical_gradient_brush(point(150, 150), {color1, color2, color3, color4}, 0), rectangle(50, 50, 200, 200));
    e.graphics().fill_rectangle(conical_gradient_brush(point(400, 150), {color1, color2, color3, color4}, 90), rectangle(300, 50, 200, 200));
    e.graphics().fill_rectangle(conical_gradient_brush(point(600, 100), {color1, color2, color3, color4}, 0), rectangle(550, 50, 200, 200));
    
    e.graphics().fill_rectangle(conical_gradient_brush(point(150, 400), {color::from_argb(128, color1), color::from_argb(128, color2), color::from_argb(128, color3), color::from_argb(128, color4)}, 0), rectangle(50, 300, 200, 200));
    e.graphics().fill_rectangle(conical_gradient_brush(point(400, 400), {color::from_argb(128, color1), color::from_argb(128, color2), color::from_argb(128, color3), color::from_argb(128, color4)}, 90), rectangle(300, 300, 200, 200));
    e.graphics().fill_rectangle(conical_gradient_brush(point(600, 350), {color::from_argb(128, color1), color::from_argb(128, color2), color::from_argb(128, color3), color::from_argb(128, color4)}, 0), rectangle(550, 300, 200, 200));
  }
  
  void fill_rectangle_with_linear_gradient(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    static const auto color1 = color::red;
    static const auto color2 = color::green;
    static const auto color3 = color::blue;
    static const auto color4 = color::yellow;
    
    e.graphics().fill_rectangle(linear_gradient_brush(rectangle(50, 50, 150, 100), {color1, color2, color3, color4}, 0), rectangle(50, 50, 150, 100));
    e.graphics().fill_rectangle(linear_gradient_brush(rectangle(250, 50, 150, 100), {color1, color2, color3, color4}, 45), rectangle(250, 50, 150, 100));
    e.graphics().fill_rectangle(linear_gradient_brush(rectangle(450, 50, 150, 100), {color1, color2, color3, color4}, 90), rectangle(450, 50, 150, 100));
    e.graphics().fill_rectangle(linear_gradient_brush(rectangle(650, 50, 150, 100), {color1, color2, color3, color4}, 135), rectangle(650, 50, 150, 100));
    
    e.graphics().fill_rectangle(linear_gradient_brush(rectangle(50, 200, 150, 100), {color1, color2, color3, color4}, 180), rectangle(50, 200, 150, 100));
    e.graphics().fill_rectangle(linear_gradient_brush(rectangle(250, 200, 150, 100), {color1, color2, color3, color4}, 225), rectangle(250, 200, 150, 100));
    e.graphics().fill_rectangle(linear_gradient_brush(rectangle(450, 200, 150, 100), {color1, color2, color3, color4}, 270), rectangle(450, 200, 150, 100));
    e.graphics().fill_rectangle(linear_gradient_brush(rectangle(650, 200, 150, 100), {color1, color2, color3, color4}, 315), rectangle(650, 200, 150, 100));
    
    e.graphics().fill_rectangle(linear_gradient_brush(rectangle(50, 400, 150, 100), {color::from_argb(128, color1), color::from_argb(128, color2), color::from_argb(128, color3), color::from_argb(128, color4)}, xtd::drawing::drawing_2d::linear_gradient_mode::horizontal), rectangle(50, 400, 150, 100));
    e.graphics().fill_rectangle(linear_gradient_brush(rectangle(250, 400, 150, 100), {color::from_argb(128, color1), color::from_argb(128, color2), color::from_argb(128, color3), color::from_argb(128, color4)}, xtd::drawing::drawing_2d::linear_gradient_mode::vertical), rectangle(250, 400, 150, 100));
    e.graphics().fill_rectangle(linear_gradient_brush(rectangle(450, 400, 150, 100), {color::from_argb(128, color1), color::from_argb(128, color2), color::from_argb(128, color3), color::from_argb(128, color4)}, xtd::drawing::drawing_2d::linear_gradient_mode::forward_diagonal), rectangle(450, 400, 150, 100));
    e.graphics().fill_rectangle(linear_gradient_brush(rectangle(650, 400, 150, 100), {color::from_argb(128, color1), color::from_argb(128, color2), color::from_argb(128, color3), color::from_argb(128, color4)}, xtd::drawing::drawing_2d::linear_gradient_mode::backward_diagonal), rectangle(650, 400, 150, 100));
  }
  
  void fill_rectangle_with_radial_gradient(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    static const auto color1 = color::red;
    static const auto color2 = color::green;
    static const auto color3 = color::blue;
    static const auto color4 = color::yellow;
    
    e.graphics().fill_rectangle(radial_gradient_brush(point(150, 150), {color1, color2, color3, color4}, 100), rectangle(50, 50, 200, 200));
    
    radial_gradient_brush brush1(point(400, 150), {color1, color2, color3, color4}, 100);
    brush1.focal_point(point(350, 100));
    e.graphics().fill_rectangle(brush1, rectangle(300, 50, 200, 200));
    
    e.graphics().fill_rectangle(radial_gradient_brush(point(150, 400), {color::from_argb(128, color1), color::from_argb(128, color2), color::from_argb(128, color3), color::from_argb(128, color4)}, 100), rectangle(50, 300, 200, 200));
    
    radial_gradient_brush brush2(point(400, 400), {color::from_argb(128, color1), color::from_argb(128, color2), color::from_argb(128, color3), color::from_argb(128, color4)}, 100);
    brush2.focal_point(point(350, 350));
    e.graphics().fill_rectangle(brush2, rectangle(300, 300, 200, 200));
  }
  
  void fill_rectangle_with_pattern(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    static const auto background_color = color::yellow;
    static const auto forground_color = color::blue;
    static const vector patterns = {hatch_style::horizontal, hatch_style::vertical, hatch_style::forward_diagonal, hatch_style::backward_diagonal, hatch_style::cross, hatch_style::diagonal_cross, hatch_style::percent_05, hatch_style::percent_10, hatch_style::percent_20, hatch_style::percent_25, hatch_style::percent_30, hatch_style::percent_40, hatch_style::percent_50, hatch_style::percent_60, hatch_style::percent_70, hatch_style::percent_75, hatch_style::percent_80, hatch_style::percent_90, hatch_style::light_downward_diagonal, hatch_style::light_upward_diagonal, hatch_style::dark_downward_diagonal, hatch_style::dark_upward_diagonal, hatch_style::wide_downward_diagonal, hatch_style::wide_upward_diagonal, hatch_style::light_vertical, hatch_style::light_horizontal, hatch_style::narrow_vertical, hatch_style::narrow_horizontal, hatch_style::dark_vertical, hatch_style::dark_horizontal, hatch_style::dashed_downward_diagonal, hatch_style::dashed_upward_diagonal, hatch_style::dashed_horizontal, hatch_style::dashed_vertical, hatch_style::small_confetti, hatch_style::large_confetti, hatch_style::zig_zag, hatch_style::wave, hatch_style::diagonal_brick, hatch_style::horizontal_brick, hatch_style::weave, hatch_style::plaid, hatch_style::divot, hatch_style::dotted_grid, hatch_style::dotted_diamond, hatch_style::shingle, hatch_style::trellis, hatch_style::sphere, hatch_style::small_grid, hatch_style::small_checker_board, hatch_style::large_checker_board, hatch_style::outlined_diamond, hatch_style::solid_diamond, hatch_style::wide_checker_board};
    
    auto gap = 10;
    auto left = gap, top = gap, width = 130, height = 50;
    for (auto pattern : patterns) {
      e.graphics().fill_rectangle(hatch_brush(pattern, forground_color, background_color), rectangle(left, top, width, height));
      if (left + width + width + gap < e.clip_rectangle().width()) left += width + gap;
      else {
        top += height + gap;
        left = gap;
      }
    }
  }
  
  void fill_rectangle_with_texture(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    static const auto background_color = color::yellow;
    static const auto forground_color = color::blue;
    
    e.graphics().fill_rectangle(texture_brush(create_circle_texture_image(forground_color, background_color)), rectangle(50, 50, 400, 200));
    e.graphics().fill_rectangle(texture_brush(system_images::from_name("gammasoft", drawing::size(96, 96))), rectangle(50, 300, 400, 250));
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


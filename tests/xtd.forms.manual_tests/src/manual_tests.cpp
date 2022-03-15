#include <xtd/xtd.forms.h>
#include <xtd/forms/style_sheets/style_sheet.h>
#include <xtd/forms/button_renderer.h>
#include <xtd/forms/text_renderer.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;

class form1 : public form {
public:
  static void fill_box(xtd::drawing::graphics& graphics, const xtd::drawing::brush& brush, const xtd::drawing::rectangle& fill_rect, int radius_top_left, int radius_top_right, int radius_bottom_right, int radius_bottom_left) {
    /*
     graphics_path path;
     if (radius_top_left != 0) path.add_arc(fill_rect.left(), fill_rect.top(), radius_top_left, radius_top_left, 180, 90);
     path.add_line(fill_rect.left() + radius_top_left / 2, fill_rect.top(), fill_rect.right() - radius_top_right / 2, fill_rect.top());
     if (radius_top_right != 0) path.add_arc(fill_rect.right() - radius_top_right, fill_rect.top(), radius_top_right, radius_top_right, 270, 90);
     path.add_line(fill_rect.right(), fill_rect.top() + radius_top_right / 2, fill_rect.right(), fill_rect.bottom() - radius_bottom_right / 2);
     if (radius_bottom_right != 0) path.add_arc(fill_rect.right() - radius_bottom_right, fill_rect.bottom() - radius_bottom_right, radius_bottom_right, radius_bottom_right, 0, 90);
     path.add_line(fill_rect.right() - radius_bottom_right  /2, fill_rect.bottom(), fill_rect.left() + radius_bottom_left / 2, fill_rect.bottom());
     if (radius_bottom_left != 0) path.add_arc(fill_rect.left(), fill_rect.bottom() - radius_bottom_left, radius_bottom_left, radius_bottom_left, 90, 90);
     path.add_line(fill_rect.left(), fill_rect.bottom() - radius_bottom_left  /2, fill_rect.left(), fill_rect.top() + radius_top_left / 2);
     path.close_all_figures();
     graphics.fill_path(brush, path);
     */

    xtd::drawing::region region;
    region.make_empty();

    radius_top_left *= 2;
    radius_top_right *= 2;
    radius_bottom_right *= 2;
    radius_bottom_left *= 2;

    if (radius_top_left != 0) {
      xtd::drawing::drawing2d::graphics_path path;
      path.add_pie(fill_rect.left(), fill_rect.top(), radius_top_left, radius_top_left, 180, 90);
      if (path.get_bounds().width() > 0 && path.get_bounds().height() > 0) region.make_union(path);
    }
    if (radius_top_right != 0) {
      xtd::drawing::drawing2d::graphics_path path;
      path.add_pie(fill_rect.right() - radius_top_right, fill_rect.top(), radius_top_right, radius_top_right, 270, 90);
      if (path.get_bounds().width() > 0 && path.get_bounds().height() > 0) region.make_union(path);
    }
    if (radius_bottom_right != 0) {
      xtd::drawing::drawing2d::graphics_path path;
      path.add_pie(fill_rect.right() - radius_bottom_right, fill_rect.bottom() - radius_bottom_right, radius_bottom_right, radius_bottom_right, 0, 90);
      if (path.get_bounds().width() > 0 && path.get_bounds().height() > 0) region.make_union(path);
    }
    if (radius_bottom_left != 0) {
      xtd::drawing::drawing2d::graphics_path path;
      path.add_pie(fill_rect.left(), fill_rect.bottom() - radius_bottom_left, radius_bottom_left, radius_bottom_left, 90, 90);
      if (path.get_bounds().width() > 0 && path.get_bounds().height() > 0) region.make_union(path);
    }
    region.make_union(rectangle(fill_rect.left() + radius_top_left / 2, fill_rect.top() + xtd::math::max(radius_top_left, radius_top_right) / 2, fill_rect.width() - radius_top_left / 2 - radius_top_right / 2, fill_rect.height() - xtd::math::max(radius_top_left, radius_top_right) / 2 - xtd::math::max(radius_bottom_left, radius_bottom_right) / 2));
    
    region.make_union(rectangle(fill_rect.left() + radius_top_left / 2, fill_rect.top(), fill_rect.width() - radius_top_left / 2 - radius_top_right / 2, xtd::math::max(radius_top_left, radius_top_right) / 2));
    region.make_union(rectangle(fill_rect.left() + radius_bottom_left / 2, fill_rect.bottom() - 1, fill_rect.width() - radius_bottom_left / 2 - radius_bottom_right / 2, -math::max(radius_bottom_left, radius_bottom_right) / 2 - 1));
    
    region.make_union(rectangle(fill_rect.left(), fill_rect.top() + radius_top_left / 2, xtd::math::max(radius_top_left, radius_bottom_left) / 2, fill_rect.height() - radius_top_left / 2 - radius_bottom_left / 2));
    region.make_union(rectangle(fill_rect.right() - 1 - xtd::math::max(radius_top_right, radius_bottom_right) / 2, fill_rect.top() + radius_top_right / 2, xtd::math::max(radius_top_right - 1, radius_bottom_right) / 2, fill_rect.height() - radius_top_right / 2 - radius_bottom_right / 2));
    graphics.fill_region(brush, region);
  }
  
  form1() {
    text("form1");
    client_size({800, 450});
    
    paint += [&](object & sender, paint_event_args & e) {
      draw_grid(e.clip_rectangle(), e.graphics());

      auto fill_rect = rectangle(50, 50, 200, 100);

      int radius_top_left = 100;
      int radius_top_right = 100;
      int radius_bottom_right = 0;
      int radius_bottom_left = 0;
       
      fill_box(e.graphics(), brushes::green(), fill_rect, radius_top_left, radius_top_right, radius_bottom_right, radius_bottom_left);
    };
  }
  
private:
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
};

int main() {
  application::run(form1());
}


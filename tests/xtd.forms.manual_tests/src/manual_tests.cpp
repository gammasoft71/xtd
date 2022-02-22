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
  form1() {
    text("form1");
    client_size({800, 450});
    
    paint += [&](object& sender, paint_event_args& e) {
      auto back_color = color::navy;
      auto fore_color = color::white;
      
      e.graphics().fill_rectangle(solid_brush(color::transparent), rectangle(10, 10, 150, 150));
      e.graphics().draw_rectangle(pen(fore_color, 4), rectangle(10, 10, 150, 150));
      
      e.graphics().fill_rectangle(solid_brush(back_color), rectangle(180, 10, 150, 150));
      e.graphics().draw_rectangle(pen(fore_color, 4), rectangle(180, 10, 150, 150));
      
      e.graphics().fill_rectangle(texture_brush(create_circle_texture(fore_color, back_color)), rectangle(350, 10, 150, 150));
      e.graphics().draw_rectangle(pen(fore_color, 4), rectangle(350, 10, 150, 150));
      
      e.graphics().fill_rectangle(hatch_brush(xtd::drawing::drawing2d::hatch_style::diagonal_brick, color::white, back_color), rectangle(520, 10, 150, 150));
      e.graphics().draw_rectangle(pen(color::white, 4), rectangle(520, 10, 150, 150));
      
      e.graphics().fill_rectangle(conical_gradient_brush(point(85, 255), back_color, fore_color, 0), rectangle(10, 180, 150, 150));
      e.graphics().draw_rectangle(pen(color::white, 4), rectangle(10, 180, 150, 150));
      
      e.graphics().fill_rectangle(linear_gradient_brush(rectangle(180, 180, 150, 150), back_color, fore_color, 315), rectangle(180, 180, 150, 150));
      e.graphics().draw_rectangle(pen(color::white, 4), rectangle(180, 180, 150, 150));
      
      e.graphics().fill_rectangle(radial_gradient_brush(point(425, 255), fore_color, back_color, 73), rectangle(350, 180, 150, 150));
      e.graphics().draw_rectangle(pen(color::white, 4), rectangle(350, 180, 150, 150));
    };
  }
    
private:
  image create_circle_texture(const color& fore_color, const color& back_color) {
    auto texture = bitmap(16, 16);
    auto graphics = texture.create_graphics();
    graphics.fill_ellipse(solid_brush(back_color), 2, 2, texture.width() - 4, texture.height() - 4);
    graphics.draw_ellipse(pen(fore_color, 4), 2, 2, texture.width() - 4, texture.height() - 4);
    return texture;
  }
};

int main() {
  application::run(form1());
}


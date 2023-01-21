#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Fill rounded rectangle example");
      client_size({680, 340});
    }
    
  protected:
    void on_paint(paint_event_args& e) override {
      form::on_paint(e);
      
      auto back_color = color::navy;
      auto fore_color = color::white;
      
      e.graphics().fill_rounded_rectangle(solid_brush(color::transparent), rectangle(10, 10, 150, 150), 20);
      e.graphics().draw_rounded_rectangle(pen(fore_color, 4), rectangle(10, 10, 150, 150), 20);
      
      e.graphics().fill_rounded_rectangle(solid_brush(back_color), rectangle(180, 10, 150, 150), 20);
      e.graphics().draw_rounded_rectangle(pen(fore_color, 4), rectangle(180, 10, 150, 150), 20);
      
      e.graphics().fill_rounded_rectangle(texture_brush(create_circle_texture(fore_color, back_color)), rectangle(350, 10, 150, 150), 20);
      e.graphics().draw_rounded_rectangle(pen(fore_color, 4), rectangle(350, 10, 150, 150), 20);
      
      e.graphics().fill_rounded_rectangle(hatch_brush(xtd::drawing::drawing2d::hatch_style::diagonal_brick, color::white, back_color), rectangle(520, 10, 150, 150), 20);
      e.graphics().draw_rounded_rectangle(pen(color::white, 4), rectangle(520, 10, 150, 150), 20);
      
      e.graphics().fill_rounded_rectangle(conical_gradient_brush(point(85, 255), back_color, fore_color, 0), rectangle(10, 180, 150, 150), 20);
      e.graphics().draw_rounded_rectangle(pen(color::white, 4), rectangle(10, 180, 150, 150), 20);
      
      e.graphics().fill_rounded_rectangle(linear_gradient_brush(rectangle(180, 180, 150, 150), back_color, fore_color, 315), rectangle(180, 180, 150, 150), 20);
      e.graphics().draw_rounded_rectangle(pen(color::white, 4), rectangle(180, 180, 150, 150), 20);
      
      e.graphics().fill_rounded_rectangle(radial_gradient_brush(point(425, 255), fore_color, back_color, 73), rectangle(350, 180, 150, 150), 20);
      e.graphics().draw_rounded_rectangle(pen(color::white, 4), rectangle(350, 180, 150, 150), 20);
    }
    
  private:
    image create_circle_texture(const color& fore_color, const color& back_color) {
      auto texture = bitmap(16, 16);
      auto graphics = texture.create_graphics();
      graphics.fill_ellipse(solid_brush(back_color), 1, 1, texture.width() - 2, texture.height() - 2);
      graphics.draw_ellipse(pen(fore_color, 2), 1, 1, texture.width() - 2, texture.height() - 2);
      return texture;
    }
  };
}

auto main()->int {
  application::run(examples::form1 {});
}

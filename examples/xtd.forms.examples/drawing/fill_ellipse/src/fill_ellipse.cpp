#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Fill ellipse example");
      client_size({340, 230});
    }
    
  protected:
    void on_paint(paint_event_args& e) override {
      e.graphics().fill_ellipse(brushes::transparent(), 10, 10, 100, 100);
      e.graphics().fill_ellipse(solid_brush(color::red), 120, 10, 100, 100);
      e.graphics().fill_ellipse(linear_gradient_brush(rectangle(230, 10, 100, 100), color::green, color::white, linear_gradient_mode::vertical), 230, 10, 100, 100);
      e.graphics().fill_ellipse(hatch_brush(hatch_style::diagonal_cross, color::blue, color::white), 10, 120, 100, 100);
      e.graphics().fill_ellipse(texture_brush(create_circle_texture(color::yellow)), 120, 120, 100, 100);
      form::on_paint(e);
    }
    
  private:
    image create_circle_texture(const color& color) {
      auto texture = bitmap(16, 16);
      auto graphics = texture.create_graphics();
      graphics.fill_rectangle(solid_brush(color), 0, 0, texture.width() - 1, texture.height() - 1);
      graphics.draw_rectangle(pens::black(), 0, 0, texture.width() - 1, texture.height() - 1);
      return texture;
    }
  };
}

int main() {
  application::run(examples::form1());
}

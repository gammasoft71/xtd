#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Fill rectangle example");
      client_size({340, 230});
    }
    
    void on_paint(paint_event_args& e) override {
      auto solid_transparent_brush = solid_brush(color::transparent);
      e.graphics().fill_rectangle(solid_transparent_brush, 10, 10, 100, 100);
      
      auto solid_red_brush = solid_brush(color::red);
      e.graphics().fill_rectangle(solid_red_brush, 120, 10, 100, 100);

      auto gradient_horizontal_brush = linear_gradient_brush(drawing::rectangle(230, 10, 100, 100), color::green, back_color(), linear_gradient_mode::horizontal);
      e.graphics().fill_rectangle(gradient_horizontal_brush, 230, 10, 100, 100);
      
      auto hatch_cross_brush = solid_brush(color::white);
      e.graphics().fill_rectangle(hatch_cross_brush, 10, 120, 100, 100);
      
      auto texture_circle_brush = texture_brush(create_circle_brush_image(color::yellow));
      e.graphics().fill_rectangle(texture_circle_brush, 120, 120, 100, 100);

      form::on_paint(e);
    }
    
  private:
    image create_circle_brush_image(const color& color) {
      auto bitmap = drawing::bitmap(16, 16);
      auto graphics = drawing::graphics::from_image(bitmap);
      graphics.fill_ellipse(solid_brush(color), 0, 0, bitmap.width(), bitmap.height());
      graphics.draw_ellipse(pens::black(), 0, 0, bitmap.width() - 1, bitmap.height() - 1);
      return bitmap;
    }
  };
}

int main() {
  application::run(examples::form1());
}

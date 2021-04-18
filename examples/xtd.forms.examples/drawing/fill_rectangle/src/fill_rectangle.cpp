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
      
      auto gradient_vertical_brush = linear_gradient_brush(drawing::rectangle(10, 120, 100, 100), color::blue, back_color(), linear_gradient_mode::vertical);
      e.graphics().fill_rectangle(gradient_vertical_brush, 10, 120, 100, 100);
      
      auto gradient_forward_diagonal_brush = linear_gradient_brush(drawing::rectangle(120, 120, 100, 100), color::yellow, back_color(), linear_gradient_mode::forward_diagonal);
      e.graphics().fill_rectangle(gradient_forward_diagonal_brush, 120, 120, 100, 100);
      
      auto gradient_backward_diagonal_brush = linear_gradient_brush(drawing::rectangle(230, 120, 100, 100), color::cyan, back_color(), linear_gradient_mode::backward_diagonal);
      e.graphics().fill_rectangle(gradient_backward_diagonal_brush, 230, 120, 100, 100);

      form::on_paint(e);
    }
  };
}

int main() {
  application::run(examples::form1());
}

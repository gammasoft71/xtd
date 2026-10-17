#include <xtd/xtd>

namespace fill_rounded_rectangle_example {
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
      auto outline_pen = pen {fore_color, 4.0f};

      e.graphics().fill_rounded_rectangle(solid_brush {color::transparent}, rectangle_f {10.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
      e.graphics().draw_rounded_rectangle(outline_pen, rectangle_f {10.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
      
      e.graphics().fill_rounded_rectangle(solid_brush {back_color}, rectangle_f {180.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
      e.graphics().draw_rounded_rectangle(outline_pen, rectangle_f {180.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
      
      e.graphics().fill_rounded_rectangle(texture_brush {create_circle_texture(fore_color, back_color)}, rectangle_f {350.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
      e.graphics().draw_rounded_rectangle(outline_pen, rectangle_f {350.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
      
      e.graphics().fill_rounded_rectangle(drawing_2d::hatch_brush {drawing_2d::hatch_style::diagonal_brick, color::white, back_color}, rectangle_f {520.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
      e.graphics().draw_rounded_rectangle(outline_pen, rectangle_f {520.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
      
      e.graphics().fill_rounded_rectangle(drawing_2d::conical_gradient_brush {point_f {85.0f, 255.0f}, back_color, fore_color, 0.0f}, rectangle_f {10.0f, 180.0f, 150.0f, 150.0f}, 20.0f);
      e.graphics().draw_rounded_rectangle(outline_pen, rectangle_f {10.0f, 180.0f, 150.0f, 150.0f}, 20.0f);
      
      e.graphics().fill_rounded_rectangle(drawing_2d::linear_gradient_brush {rectangle_f {180.0f, 180.0f, 150.0f, 150.0f}, back_color, fore_color, 315.0f}, rectangle_f {180.0f, 180.0f, 150.0f, 150.0f}, 20.0f);
      e.graphics().draw_rounded_rectangle(pen {color::white, 4}, rectangle_f {180.0f, 180.0f, 150.0f, 150.0f}, 20.0f);
      
      e.graphics().fill_rounded_rectangle(drawing_2d::radial_gradient_brush {point_f {425.0f, 255.0f}, fore_color, back_color, 73.0f}, rectangle_f {350.0f, 180.0f, 150.0f, 150.0f}, 20.0f);
      e.graphics().draw_rounded_rectangle(pen {color::white, 4}, rectangle_f {350.0f, 180.0f, 150.0f, 150.0f}, 20.0f);
    }
    
  private:
    auto create_circle_texture(const color& fore_color, const color& back_color)->image {
      auto texture = bitmap {16, 16};
      auto graphics = texture.create_graphics();
      graphics.fill_ellipse(solid_brush {back_color}, 1, 1, texture.width() - 2, texture.height() - 2);
      graphics.draw_ellipse(pen {fore_color, 2}, 1, 1, texture.width() - 2, texture.height() - 2);
      return texture;
    }
  };
}

auto main() -> int {
  application::run(fill_rounded_rectangle_example::form1 {});
}

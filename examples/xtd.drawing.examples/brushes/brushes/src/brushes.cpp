#include <xtd/xtd>

using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

auto create_circle_texture(auto&& fore_color, auto&& back_color) {
  auto texture = bitmap {16, 16};
  auto graphics = texture.create_graphics();
  graphics.fill_ellipse(solid_brush {back_color}, 1, 1, texture.width() - 2, texture.height() - 2);
  graphics.draw_ellipse(pen {fore_color, 2}, 1, 1, texture.width() - 2, texture.height() - 2);
  return texture;
}

auto main() -> int {
  auto drawing_bitmap = bitmap {680, 340};
  auto graphics = graphics::from_image(drawing_bitmap);
  
  auto back_color = color::navy;
  auto fore_color = color::white;
  auto outline_pen = pen {fore_color, 4.0f};
  
  graphics.fill_rounded_rectangle(solid_brush {color::transparent}, rectangle_f {10.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
  graphics.draw_rounded_rectangle(outline_pen, rectangle_f {10.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
  
  graphics.fill_rounded_rectangle(solid_brush {back_color}, rectangle_f {180.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
  graphics.draw_rounded_rectangle(outline_pen, rectangle_f {180.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
  
  graphics.fill_rounded_rectangle(texture_brush {create_circle_texture(fore_color, back_color)}, rectangle_f {350.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
  graphics.draw_rounded_rectangle(outline_pen, rectangle_f {350.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
  
  graphics.fill_rounded_rectangle(drawing_2d::hatch_brush {drawing_2d::hatch_style::diagonal_brick, color::white, back_color}, rectangle_f {520.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
  graphics.draw_rounded_rectangle(outline_pen, rectangle_f {520.0f, 10.0f, 150.0f, 150.0f}, 20.0f);
  
  graphics.fill_rounded_rectangle(drawing_2d::conical_gradient_brush {point_f {85.0f, 255.0f}, back_color, fore_color, 0.0f}, rectangle_f {10.0f, 180.0f, 150.0f, 150.0f}, 20.0f);
  graphics.draw_rounded_rectangle(outline_pen, rectangle_f {10.0f, 180.0f, 150.0f, 150.0f}, 20.0f);
  
  graphics.fill_rounded_rectangle(drawing_2d::linear_gradient_brush {rectangle_f {180.0f, 180.0f, 150.0f, 150.0f}, back_color, fore_color, 315.0f}, rectangle_f {180.0f, 180.0f, 150.0f, 150.0f}, 20.0f);
  graphics.draw_rounded_rectangle(outline_pen, rectangle_f {180.0f, 180.0f, 150.0f, 150.0f}, 20.0f);
  
  graphics.fill_rounded_rectangle(drawing_2d::radial_gradient_brush {point_f {425.0f, 255.0f}, fore_color, back_color, 73.0f}, rectangle_f {350.0f, 180.0f, 150.0f, 150.0f}, 20.0f);
  graphics.draw_rounded_rectangle(outline_pen, rectangle_f {350.0f, 180.0f, 150.0f, 150.0f}, 20.0f);

  drawing_bitmap.save(path::combine(path::get_temp_path(), "brushes.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "brushes.png")}.use_shell_execute(true)).wait_for_exit();
}

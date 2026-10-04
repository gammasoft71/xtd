#include <xtd/xtd>

using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

auto main() -> int {
  auto drawing_bitmap = bitmap {640, 480};
  auto graphics = graphics::from_image(drawing_bitmap);
  
  graphics.draw_ellipse(pens::red(20), rectangle {120, 40, 220, 220});
  graphics.draw_ellipse(pens::dodger_blue(20), rectangle {300, 220, 220, 220});

  drawing_bitmap.save(path::combine(path::get_temp_path(), "graphics_draw_ellipse.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "graphics_draw_ellipse.png")}.use_shell_execute(true)).wait_for_exit();
}

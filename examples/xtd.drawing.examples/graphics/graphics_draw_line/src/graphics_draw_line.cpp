#include <xtd/xtd>

using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

auto main() -> int {
  auto drawing_bitmap = bitmap {640, 480};
  auto graphics = graphics::from_image(drawing_bitmap);
  
  graphics.draw_line(pens::red(20), point {310, 20}, point {310, 460});
  graphics.draw_line(pens::dodger_blue(20), point {110, 230}, point {530, 230});

  drawing_bitmap.save(path::combine(path::get_temp_path(), "graphics_draw_line.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "graphics_draw_line.png")}.use_shell_execute(true)).wait_for_exit();
}

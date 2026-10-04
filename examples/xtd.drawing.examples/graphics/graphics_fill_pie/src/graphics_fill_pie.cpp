#include <xtd/xtd>

using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

auto main() -> int {
  auto drawing_bitmap = bitmap {640, 480};
  auto graphics = graphics::from_image(drawing_bitmap);
  
  graphics.fill_pie(brushes::dodger_blue(), rectangle {120, 40, 400, 400}, 0, 90);
  graphics.fill_pie(brushes::red(), rectangle {120, 40, 400, 400}, 180, 90);

  drawing_bitmap.save(path::combine(path::get_temp_path(), "graphics_fill_pie.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "graphics_fill_pie.png")}.use_shell_execute(true)).wait_for_exit();
}

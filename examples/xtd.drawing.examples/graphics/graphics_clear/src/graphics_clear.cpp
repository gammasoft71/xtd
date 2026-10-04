#include <xtd/xtd>

using namespace xtd::drawing;

auto main() -> int {
  auto drawing_bitmap = bitmap {640, 480};
  auto graphics = graphics::from_image(drawing_bitmap);
  
  graphics.clear(color::dodger_blue);
  
  drawing_bitmap.save(path::combine(path::get_temp_path(), "graphics_clear.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "graphics_clear.png")}.use_shell_execute(true)).wait_for_exit();
}

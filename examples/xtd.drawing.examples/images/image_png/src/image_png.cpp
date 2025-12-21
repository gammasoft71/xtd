#include <xtd/xtd>
#include "../properties/resources.hpp"

auto main() -> int {
  auto bmp = image_png::properties::resources::gammasoft_png();
  bmp.save(path::combine(path::get_temp_path(), "image_png.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "image_png.png")}.use_shell_execute(true)).wait_for_exit();
}

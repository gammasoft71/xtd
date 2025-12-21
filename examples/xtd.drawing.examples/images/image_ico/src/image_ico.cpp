#include <xtd/xtd>
#include "../properties/resources.hpp"

auto main() -> int {
  auto bmp = image_ico::properties::resources::gammasoft_ico().to_bitmap();
  bmp.save(path::combine(path::get_temp_path(), "image_ico.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "image_ico.png")}.use_shell_execute(true)).wait_for_exit();
}

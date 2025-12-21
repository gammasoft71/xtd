#include <xtd/xtd>
#include "../properties/resources.hpp"

auto main() -> int {
  auto bmp = image_bmp::properties::resources::gammasoft_bmp();
  bmp.save(path::combine(path::get_temp_path(), "image_bmp.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "image_bmp.png")}.use_shell_execute(true)).wait_for_exit();
}

#include <xtd/xtd>
#include "../properties/resources.hpp"

auto main() -> int {
  auto bmp = image_pcx::properties::resources::gammasoft_pcx();
  bmp.save(path::combine(path::get_temp_path(), "image_pcx.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "image_pcx.png")}.use_shell_execute(true)).wait_for_exit();
}

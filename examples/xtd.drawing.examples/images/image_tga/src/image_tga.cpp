#include <xtd/xtd>
#include "../properties/resources.hpp"

auto main() -> int {
  auto bmp = image_tga::properties::resources::gammasoft_tga();
  bmp.save(path::combine(path::get_temp_path(), "image_tga.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "image_tga.png")}.use_shell_execute(true)).wait_for_exit();
}

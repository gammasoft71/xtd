#include <xtd/xtd>
#include "../properties/resources.hpp"

auto main() -> int {
  auto bmp = image_icns::properties::resources::gammasoft_icns().to_bitmap();
  bmp.save(path::combine(path::get_temp_path(), "image_icns.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "image_icns.png")}.use_shell_execute(true)).wait_for_exit();
}

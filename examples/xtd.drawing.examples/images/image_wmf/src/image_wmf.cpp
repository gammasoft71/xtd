#include <xtd/xtd>
#include "../properties/resources.hpp"

auto main() -> int {
  auto bmp = image_wmf::properties::resources::gammasoft_wmf();
  bmp.save(path::combine(path::get_temp_path(), "image_wmf.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "image_wmf.png")}.use_shell_execute(true)).wait_for_exit();
}

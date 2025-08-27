#include <xtd/xtd>
#include "../properties/resources.hpp"

auto main() -> int {
  auto bmp = image_iif::properties::resources::gammasoft_iif();
  bmp.save(path::combine(path::get_temp_path(), "image_iif.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "image_iif.png")}.use_shell_execute(true));
}

#include <xtd/xtd>
#include "../properties/resources.hpp"

auto main() -> int {
  auto bmp = image_gif::properties::resources::gammasoft_gif();
  bmp.save(path::combine(path::get_temp_path(), "image_gif.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "image_gif.png")}.use_shell_execute(true)).wait_for_exit();
}

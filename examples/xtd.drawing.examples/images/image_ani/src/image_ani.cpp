#include <xtd/xtd>
#include "../properties/resources.hpp"

auto main() -> int {
  auto img = image_ani::properties::resources::gammasoft_ani();
  img.save(path::combine(path::get_temp_path(), "image_ani.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "image_ani.png")}.use_shell_execute(true)).wait_for_exit();
}

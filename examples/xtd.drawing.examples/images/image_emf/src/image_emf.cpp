#include <xtd/xtd>
#include "../properties/resources.hpp"

auto main() -> int {
  auto bmp = image_emf::properties::resources::gammasoft_emf();
  bmp.save(path::combine(path::get_temp_path(), "image_emf.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "image_emf.png")}.use_shell_execute(true)).wait_for_exit();
}

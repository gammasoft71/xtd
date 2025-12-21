#include <xtd/xtd>
#include "../properties/resources.hpp"

auto main() -> int {
  auto bmp = image_cur::properties::resources::gammasoft_cur();
  bmp.save(path::combine(path::get_temp_path(), "image_cur.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "image_cur.png")}.use_shell_execute(true)).wait_for_exit();
}

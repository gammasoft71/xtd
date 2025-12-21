#include <xtd/xtd>
#include "../resources/gammasoft.xpm"

auto main() -> int {
  auto bmp = drawing::image::from_xpm_data(gammasoft_xpm);
  bmp.save(path::combine(path::get_temp_path(), "image_xpm.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "image_xpm.png")}.use_shell_execute(true)).wait_for_exit();
}

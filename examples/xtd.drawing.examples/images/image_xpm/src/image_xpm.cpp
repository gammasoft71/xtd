#include <xtd/diagnostics/process>
#include <xtd/drawing/bitmap>
#include <xtd/io/path>
#include "../resources/gammasoft.xpm"

using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::io;

auto main() -> int {
  auto bmp = image::from_xpm_data(gammasoft_xpm);
  bmp.save(path::combine(path::get_temp_path(), "image_xpm.png"));
  process::start(process_start_info {path::combine(path::get_temp_path(), "image_xpm.png")}.use_shell_execute(true));
}

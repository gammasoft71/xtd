#include <xtd/diagnostics/process>
#include <xtd/drawing/bitmap>
#include <xtd/io/path>
#include "../properties/resources.hpp"

using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::io;

auto main() -> int {
  auto bmp = image_bmp::properties::resources::gammasoft_bmp();
  bmp.save(path::combine(path::get_temp_path(), "image_bmp.png"));
  process::start(process_start_info {path::combine(path::get_temp_path(), "image_bmp.png")}.use_shell_execute(true));
}

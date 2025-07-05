#include <xtd/diagnostics/process>
#include <xtd/drawing/bitmap>
#include <xtd/io/path>
#include "../properties/resources.hpp"

using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::io;

auto main() -> int {
  auto bmp = image_ico::properties::resources::gammasoft_ico().to_bitmap();
  bmp.save(path::combine(path::get_temp_path(), "image_ico.png"));
  process::start(process_start_info {path::combine(path::get_temp_path(), "image_ico.png")}.use_shell_execute(true));
}

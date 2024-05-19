#include <xtd/diagnostics/process>
#include <xtd/drawing/bitmap>
#include <xtd/io/path>
#include "../properties/resources.h"

using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::io;

auto main() -> int {
  auto bmp = image_wmf::properties::resources::gammasoft_wmf();
  bmp.save(path::combine(path::get_temp_path(), "image_wmf.png"));
  process::start(path::combine(path::get_temp_path(), "image_wmf.png"));
}

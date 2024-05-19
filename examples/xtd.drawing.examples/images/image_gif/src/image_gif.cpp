#include <xtd/diagnostics/process>
#include <xtd/drawing/bitmap>
#include <xtd/io/path>
#include "../properties/resources.h"

using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::io;

auto main() -> int {
  auto bmp = image_gif::properties::resources::gammasoft_gif();
  bmp.save(path::combine(path::get_temp_path(), "image_gif.png"));
  process::start(path::combine(path::get_temp_path(), "image_gif.png"));
}

#include <xtd/diagnostics/process>
#include <xtd/drawing/bitmap>
#include <xtd/io/path>
#include "../properties/resources.hpp"

using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::io;

auto main() -> int {
  auto bmp = image_iif::properties::resources::gammasoft_iif();
  bmp.save(path::combine(path::get_temp_path(), "image_iif.png"));
  process::start(path::combine(path::get_temp_path(), "image_iif.png"));
}

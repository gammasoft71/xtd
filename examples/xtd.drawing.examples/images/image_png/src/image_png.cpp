#include <iostream>
#include <xtd/xtd>
#include "../properties/resources.h"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::io;

auto main()->int {
  bitmap img = bitmap(image_png::properties::resources::gammasoft_png());
  img.save(path::combine(path::get_temp_path(), "gammasoft_png.png"));
  process::start(path::combine(path::get_temp_path(), "gammasoft_png.png"));
}

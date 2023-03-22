#include <iostream>
#include <xtd/xtd>
#include "../properties/resources.h"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::io;

auto main()->int {
  bitmap img = image_icns::properties::resources::gammasoft_icns().to_bitmap();
  img.save(path::combine(path::get_temp_path(), "image_icns.png"));
  process::start(path::combine(path::get_temp_path(), "image_icns.png"));
}

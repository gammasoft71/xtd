#include <iostream>
#include <xtd/xtd>
#include "../properties/resources.h"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::io;

auto main()->int {
  bitmap img = image_ico::properties::resources::gammasoft_ico().to_bitmap();
  img.save(path::combine(path::get_temp_path(), "image_ico.png"));
  process::start(path::combine(path::get_temp_path(), "image_ico.png"));
}

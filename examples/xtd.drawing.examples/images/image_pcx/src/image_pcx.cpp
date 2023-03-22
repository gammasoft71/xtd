#include <iostream>
#include <xtd/xtd>
#include "../properties/resources.h"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::io;

auto main()->int {
  bitmap img = bitmap(image_pcx::properties::resources::gammasoft_pcx());
  img.save(path::combine(path::get_temp_path(), "image_pcx.png"));
  process::start(path::combine(path::get_temp_path(), "image_pcx.png"));
}

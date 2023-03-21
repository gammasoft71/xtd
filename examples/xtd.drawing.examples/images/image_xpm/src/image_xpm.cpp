#include <iostream>
#include <xtd/xtd>
#include "../resources/gammasoft.xpm"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::io;

auto main()->int {
  bitmap img = bitmap(gammasoft_xpm);
  img.save(path::combine(path::get_temp_path(), "image_xpm.png"));
  process::start(path::combine(path::get_temp_path(), "image_xpm.png"));
}

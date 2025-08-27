#include <xtd/xtd>
#include "../properties/resources.hpp"

auto main() -> int {
  auto bmp = image_tiff::properties::resources::gammasoft_tiff();
  bmp.save(path::combine(path::get_temp_path(), "image_tiff.png"));
  diagnostics::process::start(diagnostics::process_start_info {path::combine(path::get_temp_path(), "image_tiff.png")}.use_shell_execute(true));
}

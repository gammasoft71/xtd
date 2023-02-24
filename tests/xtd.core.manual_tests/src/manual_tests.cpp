#include <xtd/xtd.core>
#include <xtd/xtd.drawing>

using namespace xtd;

auto main()->int {
  int min = as<int>(single_object::min_value);
  int max = as<int>(single_object::max_value);
  console::write_line("main = {}; max= {}", min, max);
  console::write_line("main = {}; max= {}", int32_object::min_value, int32_object::max_value);
}

#include <xtd/xtd>

using namespace xtd;

auto main()->int {
  for (auto item : enum_object<>::get_values<environment::special_folder>()) {
    console::write_line("{}={}", item, environment::get_folder_path(item));
  }
}

// This code can produces the following output:
//
// false
// false
// true
// false
// true
// false
// false
// true
// true
// true


#include <xtd/drawing/point>
#include <xtd/drawing/size>
#include <xtd/console>

using namespace xtd;
using namespace xtd::drawing;

auto main() -> int {
  auto location = point {10, 235};
  console::write_line("location = {}", location);
  
  location.x(location.x() + 20);
  location.y(location.y() - 15);
  console::write_line("location = {}", location);
  
  location = point {10, 10} + drawing::size {20, 50};
  console::write_line("location = {}", location);
  
  location.offset({70, 140});
  console::write_line("location = {}", location);
}

// This code produces the following output:
//
// location = {x=10, y=235}
// location = {x=30, y=220}
// location = {x=30, y=60}
// location = {x=100, y=200}

#include <xtd/drawing/color>
#include <xtd/console>

using namespace xtd;
using namespace xtd::drawing;

auto main() -> int {
  console::write_line("color::black = {}", color::black);
  console::write_line("color::withe = {}", color::white);
  console::write_line("color::blue = {}", color::blue);
  console::write_line("Color::light_green = {}", color::light_green);
  console::write_line("Color::from_argb(255, 253, 2, 0) = {}", color::from_argb(255, 253, 2, 0));
  console::write_line("color::from_name(\"dodger_blue\") = {}", color::from_name("dodger_blue"));
  console::write_line("color::from_name(\"dodger blue\") = {}", color::from_name("dodger blue"));
  console::write_line("color::from_name(\"dodgerblue\") = {}", color::from_name("dodgerblue"));
}

// This code produces the following output:
//
// color::black = color [black]
// color::withe = color [white]
// color::blue = color [blue]
// Color::light_green = color [light_green]
// Color::from_argb(255, 253, 2, 0) = color [a=255, r=253, g=2, b=0]
// color::from_name("dodger_blue") = color [dodger_blue]
// color::from_name("dodger blue") = color [dodger_blue]
// color::from_name("dodgerblue") = color [dodger_blue]

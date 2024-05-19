#include <xtd/console>
#include <xtd/parse>

using namespace xtd;

auto main() -> int {
  auto b1 = xtd::parse<bool>("true");
  console::write_line(b1);
  auto b2 = xtd::parse<bool>("false");
  console::write_line(b2);
  auto b3 = xtd::parse<bool>("TRUE");
  console::write_line(b3);
  auto b4 = xtd::parse<bool>("FALSE");
  console::write_line(b4);
  auto b5 = xtd::parse<bool>("1");
  console::write_line(b5);
  auto b6 = xtd::parse<bool>("0");
  console::write_line(b6);
  auto b7 = xtd::parse<bool>("  TrUe   ");
  console::write_line(b7);
  auto b8 = xtd::parse<bool>("   fAlSe  ");
  console::write_line(b8);
  try {
    auto b9 = xtd::parse<bool>("None");
    console::write_line(b9);
  } catch (const system_exception& e) {
    console::write_line("Exception : {}", e.message());
  }
}

// This code produces the following output :
//
// true
// false
// true
// false
// true
// false
// true
// false
// Exception : Invalid string format

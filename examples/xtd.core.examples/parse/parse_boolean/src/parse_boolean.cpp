#include <xtd/xtd>

using namespace std;
using namespace xtd;

auto main()->int {
  bool b1 = xtd::parse<bool>("true");
  console::write_line(b1);
  bool b2 = xtd::parse<bool>("false");
  console::write_line(b2);
  bool b3 = xtd::parse<bool>("TRUE");
  console::write_line(b3);
  bool b4 = xtd::parse<bool>("FALSE");
  console::write_line(b4);
  bool b5 = xtd::parse<bool>("1");
  console::write_line(b5);
  bool b6 = xtd::parse<bool>("0");
  console::write_line(b6);
  bool b7 = xtd::parse<bool>("  TrUe   ");
  console::write_line(b7);
  bool b8 = xtd::parse<bool>("   fAlSe  ");
  console::write_line(b8);
  try {
    bool b9 = xtd::parse<bool>("None");
    console::write_line(b9);
  } catch (const exception& e) {
    console::write_line("Exception : {}", e.what());
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

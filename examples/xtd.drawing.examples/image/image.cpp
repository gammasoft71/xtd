#include <iostream>
#include <xtd/xtd>
#include "logo.xpm"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

int main() {
  bitmap img = bitmap(logo_xpm);

  cout << ustring::format("handle = 0x{:X}", img.handle()) << endl;
  cout << ustring::format("horizontal resolution = {}", img.horizontal_resolution()) << endl;
  cout << ustring::format("physical dimension = {}", img.physical_dimension()) << endl;
  cout << ustring::format("raw format = {}", img.raw_format()) << endl;
  cout << ustring::format("vertcal resolution = {}", img.vertical_resolution()) << endl;
  cout << ustring::format("size = {}", img.size()) << endl;
  cout << ustring::format("pixel[50][100] = {}", img.get_pixel(50, 100)) << endl;
}

// This code produces the following output:
//
// handle = 0x101E61F10
// horizontal resolution = 96
// physical dimension = {width=256.000000, height=256.000000}
// raw format = [image_format: b96b3cc0-0728-11d3-9d7b-0000f81ef32e]
// vertcal resolution = 96
// size = {width=256, height=256}
// pixel[50][100] = color [a=255, r=0, g=64, b=128]

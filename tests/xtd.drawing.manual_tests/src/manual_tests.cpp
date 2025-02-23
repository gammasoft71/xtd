#include <xtd/xtd>

using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

namespace xtd::drawing::tests {
  class program static_ {
  public:
    static auto main() {
       auto bmp = bitmap(4, 3);
       bmp.set_pixel(0, 0, color::red);
       bmp.set_pixel(1, 0, color::lime);
       bmp.set_pixel(2, 0, color::blue);
       bmp.set_pixel(3, 0, color::white);
       bmp.set_pixel(0, 1, color::aqua);
       bmp.set_pixel(1, 1, color::fuchsia);
       bmp.set_pixel(2, 1, color::yellow);
       bmp.set_pixel(3, 1, color::silver);
       bmp.set_pixel(0, 2, color::dark_red);
       bmp.set_pixel(1, 2, color::green);
       bmp.set_pixel(2, 2, color::navy);
       bmp.set_pixel(3, 2, color::gray);
      
      println("bitmap {} x {} : ", bmp.width(), bmp.height());
      for (auto y = 0; y < bmp.height(); ++y) {
        for (auto x = 0; x < bmp.width(); ++x)
          print("  0x{:X8}", bmp.get_pixel(x, y).to_argb());
        println();
      }
    }
  };
}

startup_(tests::program::main);

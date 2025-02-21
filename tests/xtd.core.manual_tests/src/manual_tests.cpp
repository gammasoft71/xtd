#include <xtd/xtd>

using namespace xtd::drawing;

namespace manual_tests {
  class program static_ {
  public:
    static bitmap create_image(const xtd::drawing::size& size) {
      if (size.height < 0 || size.height > 4) throw argument_exception {};
      if (size.width < 0 || size.width > 4) throw argument_exception {};
      auto [w, h] = size;
      auto bmp = bitmap {w, h};
      
      if (w >= 1 && h >= 1) bmp.set_pixel(0, 0, color::red);
      if (w >= 2 && h >= 1) bmp.set_pixel(1, 0, color::lime);
      if (w >= 3 && h >= 1) bmp.set_pixel(2, 0, color::blue);
      if (w >= 4 && h >= 1) bmp.set_pixel(3, 0, color::white);
      if (w >= 1 && h >= 2) bmp.set_pixel(0, 1, color::aqua);
      if (w >= 2 && h >= 2) bmp.set_pixel(1, 1, color::fuchsia);
      if (w >= 3 && h >= 2) bmp.set_pixel(2, 1, color::yellow);
      if (w >= 4 && h >= 2) bmp.set_pixel(3, 1, color::silver);
      if (w >= 1 && h >= 3) bmp.set_pixel(0, 2, color::dark_red);
      if (w >= 2 && h >= 3) bmp.set_pixel(1, 2, color::green);
      if (w >= 3 && h >= 3) bmp.set_pixel(2, 2, color::navy);
      if (w >= 4 && h >= 3) bmp.set_pixel(3, 2, color::gray);
      if (w >= 1 && h >= 4) bmp.set_pixel(0, 3, color::teal);
      if (w >= 2 && h >= 4) bmp.set_pixel(1, 3, color::purple);
      if (w >= 3 && h >= 4) bmp.set_pixel(2, 3, color::olive);
      if (w >= 4 && h >= 4) bmp.set_pixel(3, 3, color::black);
      
      return bmp;
    }

    static auto main(const auto& args) {
      //console::write_line("Hello, world!");

      /*
      for (auto w = 1; w <= 4; ++w) {
        for (auto h = 1; h <= 4; ++h) {
          auto bmp = create_image({w, h});
          
          println("bitmap {} x {} : ", w, h);
          for (auto y = 0; y < bmp.height(); ++y) {
            for (auto x = 0; x < bmp.width(); ++x)
              print("0x{:X8}  ", bmp.get_pixel(x, y).to_argb());
            println();
          }
          println();
          foreach_(auto extension, {"bmp", "gif", "exif", "jpg", "png", "tiff"})
          bmp.save(path::combine(environment::get_folder_path(environment::special_folder::desktop), "images", string::format("bitmap_{}_{}.{}", w, h, extension)));
        }
      }
       */

      auto bmp = bitmap("/Users/yves/Projects/xtd/build/tests/xtd.drawing.unit_tests/Debug/resources/bitmap_3_2.bmp");
      println("flags = {}", bmp.flags());
      
    }
  };
}

startup_(manual_tests::program::main);

// This code can produces the following output:
//
// Hello, World!

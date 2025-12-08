#include <xtd/console_color>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(console_color_tests) {
    auto test_method_(default_color) {
      assert::are_equal(-1, enum_object<>::to_int32(console_color::default_color));
      assert::are_equal("default_color", enum_object<>::to_string(console_color::default_color));
      assert::are_equal(console_color::default_color, enum_object<>::parse<console_color>("default_color"));
    }
    
    auto test_method_(black) {
      assert::are_equal(0, enum_object<>::to_int32(console_color::black));
      assert::are_equal("black", enum_object<>::to_string(console_color::black));
      assert::are_equal(console_color::black, enum_object<>::parse<console_color>("black"));
    }
    
    auto test_method_(dark_blue) {
      assert::are_equal(1, enum_object<>::to_int32(console_color::dark_blue));
      assert::are_equal("dark_blue", enum_object<>::to_string(console_color::dark_blue));
      assert::are_equal(console_color::dark_blue, enum_object<>::parse<console_color>("dark_blue"));
    }
    
    auto test_method_(dark_green) {
      assert::are_equal(2, enum_object<>::to_int32(console_color::dark_green));
      assert::are_equal("dark_green", enum_object<>::to_string(console_color::dark_green));
      assert::are_equal(console_color::dark_green, enum_object<>::parse<console_color>("dark_green"));
    }
    
    auto test_method_(dark_cyan) {
      assert::are_equal(3, enum_object<>::to_int32(console_color::dark_cyan));
      assert::are_equal("dark_cyan", enum_object<>::to_string(console_color::dark_cyan));
      assert::are_equal(console_color::dark_cyan, enum_object<>::parse<console_color>("dark_cyan"));
    }
    
    auto test_method_(dark_red) {
      assert::are_equal(4, enum_object<>::to_int32(console_color::dark_red));
      assert::are_equal("dark_red", enum_object<>::to_string(console_color::dark_red));
      assert::are_equal(console_color::dark_red, enum_object<>::parse<console_color>("dark_red"));
    }
    
    auto test_method_(dark_magenta) {
      assert::are_equal(5, enum_object<>::to_int32(console_color::dark_magenta));
      assert::are_equal("dark_magenta", enum_object<>::to_string(console_color::dark_magenta));
      assert::are_equal(console_color::dark_magenta, enum_object<>::parse<console_color>("dark_magenta"));
    }
    
    auto test_method_(dark_yellow) {
      assert::are_equal(6, enum_object<>::to_int32(console_color::dark_yellow));
      assert::are_equal("dark_yellow", enum_object<>::to_string(console_color::dark_yellow));
      assert::are_equal(console_color::dark_yellow, enum_object<>::parse<console_color>("dark_yellow"));
    }
    
    auto test_method_(gray) {
      assert::are_equal(7, enum_object<>::to_int32(console_color::gray));
      assert::are_equal("gray", enum_object<>::to_string(console_color::gray));
      assert::are_equal(console_color::gray, enum_object<>::parse<console_color>("gray"));
    }
    
    auto test_method_(dark_gray) {
      assert::are_equal(8, enum_object<>::to_int32(console_color::dark_gray));
      assert::are_equal("dark_gray", enum_object<>::to_string(console_color::dark_gray));
      assert::are_equal(console_color::dark_gray, enum_object<>::parse<console_color>("dark_gray"));
    }
    
    auto test_method_(blue) {
      assert::are_equal(9, enum_object<>::to_int32(console_color::blue));
      assert::are_equal("blue", enum_object<>::to_string(console_color::blue));
      assert::are_equal(console_color::blue, enum_object<>::parse<console_color>("blue"));
    }
    
    auto test_method_(green) {
      assert::are_equal(10, enum_object<>::to_int32(console_color::green));
      assert::are_equal("green", enum_object<>::to_string(console_color::green));
      assert::are_equal(console_color::green, enum_object<>::parse<console_color>("green"));
    }
    
    auto test_method_(cyan) {
      assert::are_equal(11, enum_object<>::to_int32(console_color::cyan));
      assert::are_equal("cyan", enum_object<>::to_string(console_color::cyan));
      assert::are_equal(console_color::cyan, enum_object<>::parse<console_color>("cyan"));
    }
    
    auto test_method_(red) {
      assert::are_equal(12, enum_object<>::to_int32(console_color::red));
      assert::are_equal("red", enum_object<>::to_string(console_color::red));
      assert::are_equal(console_color::red, enum_object<>::parse<console_color>("red"));
    }
    
    auto test_method_(magenta) {
      assert::are_equal(13, enum_object<>::to_int32(console_color::magenta));
      assert::are_equal("magenta", enum_object<>::to_string(console_color::magenta));
      assert::are_equal(console_color::magenta, enum_object<>::parse<console_color>("magenta"));
    }
    
    auto test_method_(yellow) {
      assert::are_equal(14, enum_object<>::to_int32(console_color::yellow));
      assert::are_equal("yellow", enum_object<>::to_string(console_color::yellow));
      assert::are_equal(console_color::yellow, enum_object<>::parse<console_color>("yellow"));
    }
    
    auto test_method_(white) {
      assert::are_equal(15, enum_object<>::to_int32(console_color::white));
      assert::are_equal("white", enum_object<>::to_string(console_color::white));
      assert::are_equal(console_color::white, enum_object<>::parse<console_color>("white"));
    }
  };
}


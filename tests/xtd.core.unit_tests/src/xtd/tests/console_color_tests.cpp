#include <xtd/console_color>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(console_color_tests) {
  public:
    void test_method_(black) {
      assert::are_equal(0, enum_object<>::to_int32(console_color::black), csf_);
      assert::are_equal("black", enum_object<>::to_string(console_color::black), csf_);
      assert::are_equal(console_color::black, enum_object<>::parse<console_color>("black"), csf_);
    }
    
    void test_method_(dark_blue) {
      assert::are_equal(1, enum_object<>::to_int32(console_color::dark_blue), csf_);
      assert::are_equal("dark_blue", enum_object<>::to_string(console_color::dark_blue), csf_);
      assert::are_equal(console_color::dark_blue, enum_object<>::parse<console_color>("dark_blue"), csf_);
    }
    
    void test_method_(dark_green) {
      assert::are_equal(2, enum_object<>::to_int32(console_color::dark_green), csf_);
      assert::are_equal("dark_green", enum_object<>::to_string(console_color::dark_green), csf_);
      assert::are_equal(console_color::dark_green, enum_object<>::parse<console_color>("dark_green"), csf_);
    }
    
    void test_method_(dark_cyan) {
      assert::are_equal(3, enum_object<>::to_int32(console_color::dark_cyan), csf_);
      assert::are_equal("dark_cyan", enum_object<>::to_string(console_color::dark_cyan), csf_);
      assert::are_equal(console_color::dark_cyan, enum_object<>::parse<console_color>("dark_cyan"), csf_);
    }
    
    void test_method_(dark_red) {
      assert::are_equal(4, enum_object<>::to_int32(console_color::dark_red), csf_);
      assert::are_equal("dark_red", enum_object<>::to_string(console_color::dark_red), csf_);
      assert::are_equal(console_color::dark_red, enum_object<>::parse<console_color>("dark_red"), csf_);
    }
    
    void test_method_(dark_magenta) {
      assert::are_equal(5, enum_object<>::to_int32(console_color::dark_magenta), csf_);
      assert::are_equal("dark_magenta", enum_object<>::to_string(console_color::dark_magenta), csf_);
      assert::are_equal(console_color::dark_magenta, enum_object<>::parse<console_color>("dark_magenta"), csf_);
    }
    
    void test_method_(dark_yellow) {
      assert::are_equal(6, enum_object<>::to_int32(console_color::dark_yellow), csf_);
      assert::are_equal("dark_yellow", enum_object<>::to_string(console_color::dark_yellow), csf_);
      assert::are_equal(console_color::dark_yellow, enum_object<>::parse<console_color>("dark_yellow"), csf_);
    }
    
    void test_method_(gray) {
      assert::are_equal(7, enum_object<>::to_int32(console_color::gray), csf_);
      assert::are_equal("gray", enum_object<>::to_string(console_color::gray), csf_);
      assert::are_equal(console_color::gray, enum_object<>::parse<console_color>("gray"), csf_);
    }
    
    void test_method_(dark_gray) {
      assert::are_equal(8, enum_object<>::to_int32(console_color::dark_gray), csf_);
      assert::are_equal("dark_gray", enum_object<>::to_string(console_color::dark_gray), csf_);
      assert::are_equal(console_color::dark_gray, enum_object<>::parse<console_color>("dark_gray"), csf_);
    }
    
    void test_method_(blue) {
      assert::are_equal(9, enum_object<>::to_int32(console_color::blue), csf_);
      assert::are_equal("blue", enum_object<>::to_string(console_color::blue), csf_);
      assert::are_equal(console_color::blue, enum_object<>::parse<console_color>("blue"), csf_);
    }
    
    void test_method_(green) {
      assert::are_equal(10, enum_object<>::to_int32(console_color::green), csf_);
      assert::are_equal("green", enum_object<>::to_string(console_color::green), csf_);
      assert::are_equal(console_color::green, enum_object<>::parse<console_color>("green"), csf_);
    }
    
    void test_method_(cyan) {
      assert::are_equal(11, enum_object<>::to_int32(console_color::cyan), csf_);
      assert::are_equal("cyan", enum_object<>::to_string(console_color::cyan), csf_);
      assert::are_equal(console_color::cyan, enum_object<>::parse<console_color>("cyan"), csf_);
    }
    
    void test_method_(red) {
      assert::are_equal(12, enum_object<>::to_int32(console_color::red), csf_);
      assert::are_equal("red", enum_object<>::to_string(console_color::red), csf_);
      assert::are_equal(console_color::red, enum_object<>::parse<console_color>("red"), csf_);
    }
    
    void test_method_(magenta) {
      assert::are_equal(13, enum_object<>::to_int32(console_color::magenta), csf_);
      assert::are_equal("magenta", enum_object<>::to_string(console_color::magenta), csf_);
      assert::are_equal(console_color::magenta, enum_object<>::parse<console_color>("magenta"), csf_);
    }
    
    void test_method_(yellow) {
      assert::are_equal(14, enum_object<>::to_int32(console_color::yellow), csf_);
      assert::are_equal("yellow", enum_object<>::to_string(console_color::yellow), csf_);
      assert::are_equal(console_color::yellow, enum_object<>::parse<console_color>("yellow"), csf_);
    }
    
    void test_method_(white) {
      assert::are_equal(15, enum_object<>::to_int32(console_color::white), csf_);
      assert::are_equal("white", enum_object<>::to_string(console_color::white), csf_);
      assert::are_equal(console_color::white, enum_object<>::parse<console_color>("white"), csf_);
    }
  };
}


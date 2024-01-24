#include <xtd/forms/bounds_specified.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(bounds_specified_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(bounds_specified::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(bounds_specified::none), csf_);
      assert::are_equal(bounds_specified::none, enum_object<>::parse<bounds_specified>("none"), csf_);
    }
    
    void test_method_(x) {
      assert::are_equal(1, enum_object<>::to_int32(bounds_specified::x), csf_);
      assert::are_equal("x", enum_object<>::to_string(bounds_specified::x), csf_);
      assert::are_equal(bounds_specified::x, enum_object<>::parse<bounds_specified>("x"), csf_);
    }
    
    void test_method_(y) {
      assert::are_equal(2, enum_object<>::to_int32(bounds_specified::y), csf_);
      assert::are_equal("y", enum_object<>::to_string(bounds_specified::y), csf_);
      assert::are_equal(bounds_specified::y, enum_object<>::parse<bounds_specified>("y"), csf_);
    }
    
    void test_method_(width) {
      assert::are_equal(4, enum_object<>::to_int32(bounds_specified::width), csf_);
      assert::are_equal("width", enum_object<>::to_string(bounds_specified::width), csf_);
      assert::are_equal(bounds_specified::width, enum_object<>::parse<bounds_specified>("width"), csf_);
    }
    
    void test_method_(height) {
      assert::are_equal(8, enum_object<>::to_int32(bounds_specified::height), csf_);
      assert::are_equal("height", enum_object<>::to_string(bounds_specified::height), csf_);
      assert::are_equal(bounds_specified::height, enum_object<>::parse<bounds_specified>("height"), csf_);
    }
  };
}


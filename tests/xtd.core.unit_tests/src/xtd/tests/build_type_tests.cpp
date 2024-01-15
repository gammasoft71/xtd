#include <xtd/build_type>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(build_type_tests) {
    void test_method_(debug) {
      assert::are_equal(0, enum_object<>::to_int32(build_type::debug), csf_);
      assert::are_equal("debug", enum_object<>::to_string(build_type::debug), csf_);
      assert::are_equal(build_type::debug, enum_object<>::parse<build_type>("debug"), csf_);
    }
    
    void test_method_(release) {
      assert::are_equal(1, enum_object<>::to_int32(build_type::release), csf_);
      assert::are_equal("release", enum_object<>::to_string(build_type::release), csf_);
      assert::are_equal(build_type::release, enum_object<>::parse<build_type>("release"), csf_);
    }
  };
}


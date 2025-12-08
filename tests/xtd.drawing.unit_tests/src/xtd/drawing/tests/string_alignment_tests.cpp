#include <xtd/drawing/string_alignment>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(string_alignment_tests) {
    auto test_method_(near) {
      assert::are_equal(0, enum_object<>::to_int32(string_alignment::near));
      assert::are_equal("near", enum_object<>::to_string(string_alignment::near));
      assert::are_equal(string_alignment::near, enum_object<>::parse<string_alignment>("near"));
    }
    
    auto test_method_(center) {
      assert::are_equal(1, enum_object<>::to_int32(string_alignment::center));
      assert::are_equal("center", enum_object<>::to_string(string_alignment::center));
      assert::are_equal(string_alignment::center, enum_object<>::parse<string_alignment>("center"));
    }
    
    auto test_method_(far) {
      assert::are_equal(2, enum_object<>::to_int32(string_alignment::far));
      assert::are_equal("far", enum_object<>::to_string(string_alignment::far));
      assert::are_equal(string_alignment::far, enum_object<>::parse<string_alignment>("far"));
    }
  };
}


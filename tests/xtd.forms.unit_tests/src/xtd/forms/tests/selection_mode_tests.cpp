#include <xtd/forms/selection_mode>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(selection_mode_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(selection_mode::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(selection_mode::none), csf_);
      assert::are_equal(selection_mode::none, enum_object<>::parse<selection_mode>("none"), csf_);
    }
    
    void test_method_(one) {
      assert::are_equal(1, enum_object<>::to_int32(selection_mode::one), csf_);
      assert::are_equal("one", enum_object<>::to_string(selection_mode::one), csf_);
      assert::are_equal(selection_mode::one, enum_object<>::parse<selection_mode>("one"), csf_);
    }
    
    void test_method_(multi_simple) {
      assert::are_equal(2, enum_object<>::to_int32(selection_mode::multi_simple), csf_);
      assert::are_equal("multi_simple", enum_object<>::to_string(selection_mode::multi_simple), csf_);
      assert::are_equal(selection_mode::multi_simple, enum_object<>::parse<selection_mode>("multi_simple"), csf_);
    }
    
    void test_method_(multi_extended) {
      assert::are_equal(3, enum_object<>::to_int32(selection_mode::multi_extended), csf_);
      assert::are_equal("multi_extended", enum_object<>::to_string(selection_mode::multi_extended), csf_);
      assert::are_equal(selection_mode::multi_extended, enum_object<>::parse<selection_mode>("multi_extended"), csf_);
    }
  };
}

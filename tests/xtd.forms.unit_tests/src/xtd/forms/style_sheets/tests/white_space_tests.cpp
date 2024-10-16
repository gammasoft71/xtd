#include <xtd/forms/style_sheets/white_space>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace xtd::forms::style_sheets::tests {
  class test_class_(white_space_tests) {
  public:
    void test_method_(normal) {
      assert::are_equal(0, enum_object<>::to_int32(white_space::normal));
      assert::are_equal("normal", enum_object<>::to_string(white_space::normal));
      assert::are_equal(white_space::normal, enum_object<>::parse<white_space>("normal"));
    }
    
    void test_method_(no_wrap) {
      assert::are_equal(1, enum_object<>::to_int32(white_space::no_wrap));
      assert::are_equal("no_wrap", enum_object<>::to_string(white_space::no_wrap));
      assert::are_equal(white_space::no_wrap, enum_object<>::parse<white_space>("no_wrap"));
    }
    
    void test_method_(pre) {
      assert::are_equal(2, enum_object<>::to_int32(white_space::pre));
      assert::are_equal("pre", enum_object<>::to_string(white_space::pre));
      assert::are_equal(white_space::pre, enum_object<>::parse<white_space>("pre"));
    }
    
    void test_method_(pre_line) {
      assert::are_equal(3, enum_object<>::to_int32(white_space::pre_line));
      assert::are_equal("pre_line", enum_object<>::to_string(white_space::pre_line));
      assert::are_equal(white_space::pre_line, enum_object<>::parse<white_space>("pre_line"));
    }
    
    void test_method_(pre_wrap) {
      assert::are_equal(4, enum_object<>::to_int32(white_space::pre_wrap));
      assert::are_equal("pre_wrap", enum_object<>::to_string(white_space::pre_wrap));
      assert::are_equal(white_space::pre_wrap, enum_object<>::parse<white_space>("pre_wrap"));
    }
  };
}

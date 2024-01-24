#include <xtd/forms/arrange_starting_position.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(arrange_starting_position_tests) {
  public:
    void test_method_(bottom_left) {
      assert::are_equal(0, enum_object<>::to_int32(arrange_starting_position::bottom_left), csf_);
      assert::are_equal("bottom_left", enum_object<>::to_string(arrange_starting_position::bottom_left), csf_);
      assert::are_equal(arrange_starting_position::bottom_left, enum_object<>::parse<arrange_starting_position>("bottom_left"), csf_);
    }
    
    void test_method_(bottom_right) {
      assert::are_equal(1, enum_object<>::to_int32(arrange_starting_position::bottom_right), csf_);
      assert::are_equal("bottom_right", enum_object<>::to_string(arrange_starting_position::bottom_right), csf_);
      assert::are_equal(arrange_starting_position::bottom_right, enum_object<>::parse<arrange_starting_position>("bottom_right"), csf_);
    }
    
    void test_method_(top_left) {
      assert::are_equal(2, enum_object<>::to_int32(arrange_starting_position::top_left), csf_);
      assert::are_equal("top_left", enum_object<>::to_string(arrange_starting_position::top_left), csf_);
      assert::are_equal(arrange_starting_position::top_left, enum_object<>::parse<arrange_starting_position>("top_left"), csf_);
    }
    
    void test_method_(top_right) {
      assert::are_equal(3, enum_object<>::to_int32(arrange_starting_position::top_right), csf_);
      assert::are_equal("top_right", enum_object<>::to_string(arrange_starting_position::top_right), csf_);
      assert::are_equal(arrange_starting_position::top_right, enum_object<>::parse<arrange_starting_position>("top_right"), csf_);
    }
    
    void test_method_(hide) {
      assert::are_equal(8, enum_object<>::to_int32(arrange_starting_position::hide), csf_);
      assert::are_equal("hide", enum_object<>::to_string(arrange_starting_position::hide), csf_);
      assert::are_equal(arrange_starting_position::hide, enum_object<>::parse<arrange_starting_position>("hide"), csf_);
    }
  };
}


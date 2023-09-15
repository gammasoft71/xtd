#include <xtd/drawing/drawing_2d/flush_intention>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing_2d;
using namespace xtd::tunit;

namespace xtd::drawing::drawing_2d::tests {
  class test_class_(flush_intention_tests) {
  public:
    void test_method_(flush) {
      assert::are_equal(0, enum_object<>::to_int32(flush_intention::flush), csf_);
      assert::are_equal("flush", enum_object<>::to_string(flush_intention::flush), csf_);
      assert::are_equal(flush_intention::flush, enum_object<>::parse<flush_intention>("flush"), csf_);
    }
    
    void test_method_(sync) {
      assert::are_equal(1, enum_object<>::to_int32(flush_intention::sync), csf_);
      assert::are_equal("sync", enum_object<>::to_string(flush_intention::sync), csf_);
      assert::are_equal(flush_intention::sync, enum_object<>::parse<flush_intention>("sync"), csf_);
    }
  };
}

#include <xtd/threading/thread_priority>
#include <xtd/tunit/assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(thread_priority_tests) {
    void test_method_(lowest) {
      assert::are_equal(0, enum_object<>::to_int32(thread_priority::lowest), csf_);
      assert::are_equal("lowest", enum_object<>::to_string(thread_priority::lowest), csf_);
      assert::are_equal(thread_priority::lowest, enum_object<>::parse<thread_priority>("lowest"), csf_);
    }
    
    void test_method_(below_normal) {
      assert::are_equal(1, enum_object<>::to_int32(thread_priority::below_normal), csf_);
      assert::are_equal("below_normal", enum_object<>::to_string(thread_priority::below_normal), csf_);
      assert::are_equal(thread_priority::below_normal, enum_object<>::parse<thread_priority>("below_normal"), csf_);
    }
    
    void test_method_(normal) {
      assert::are_equal(2, enum_object<>::to_int32(thread_priority::normal), csf_);
      assert::are_equal("normal", enum_object<>::to_string(thread_priority::normal), csf_);
      assert::are_equal(thread_priority::normal, enum_object<>::parse<thread_priority>("normal"), csf_);
    }
    
    void test_method_(above_normal) {
      assert::are_equal(3, enum_object<>::to_int32(thread_priority::above_normal), csf_);
      assert::are_equal("above_normal", enum_object<>::to_string(thread_priority::above_normal), csf_);
      assert::are_equal(thread_priority::above_normal, enum_object<>::parse<thread_priority>("above_normal"), csf_);
    }
    
    void test_method_(highest) {
      assert::are_equal(4, enum_object<>::to_int32(thread_priority::highest), csf_);
      assert::are_equal("highest", enum_object<>::to_string(thread_priority::highest), csf_);
      assert::are_equal(thread_priority::highest, enum_object<>::parse<thread_priority>("highest"), csf_);
    }
  };
}


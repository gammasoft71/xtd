#include <xtd/diagnostics/process_priority_class>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::diagnostics;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(process_priority_class_tests) {
    void test_method_(normal) {
      assert::are_equal(32, enum_object<>::to_int32(process_priority_class::normal));
      assert::are_equal("normal", enum_object<>::to_string(process_priority_class::normal));
      assert::are_equal(process_priority_class::normal, enum_object<>::parse<process_priority_class>("normal"));
    }
    
    void test_method_(idle) {
      assert::are_equal(64, enum_object<>::to_int32(process_priority_class::idle));
      assert::are_equal("idle", enum_object<>::to_string(process_priority_class::idle));
      assert::are_equal(process_priority_class::idle, enum_object<>::parse<process_priority_class>("idle"));
    }
    
    void test_method_(high) {
      assert::are_equal(128, enum_object<>::to_int32(process_priority_class::high));
      assert::are_equal("high", enum_object<>::to_string(process_priority_class::high));
      assert::are_equal(process_priority_class::high, enum_object<>::parse<process_priority_class>("high"));
    }
    
    void test_method_(real_time) {
      assert::are_equal(256, enum_object<>::to_int32(process_priority_class::real_time));
      assert::are_equal("real_time", enum_object<>::to_string(process_priority_class::real_time));
      assert::are_equal(process_priority_class::real_time, enum_object<>::parse<process_priority_class>("real_time"));
    }
    
    void test_method_(below_normal) {
      assert::are_equal(16384, enum_object<>::to_int32(process_priority_class::below_normal));
      assert::are_equal("below_normal", enum_object<>::to_string(process_priority_class::below_normal));
      assert::are_equal(process_priority_class::below_normal, enum_object<>::parse<process_priority_class>("below_normal"));
    }
    
    void test_method_(above_normal) {
      assert::are_equal(32768, enum_object<>::to_int32(process_priority_class::above_normal));
      assert::are_equal("above_normal", enum_object<>::to_string(process_priority_class::above_normal));
      assert::are_equal(process_priority_class::above_normal, enum_object<>::parse<process_priority_class>("above_normal"));
    }
  };
}

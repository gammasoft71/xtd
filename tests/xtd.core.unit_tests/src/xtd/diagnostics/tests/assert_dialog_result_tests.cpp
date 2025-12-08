#include <xtd/diagnostics/assert_dialog_result>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::diagnostics;
using namespace xtd::tunit;

namespace xtd::diagnostics::tests {
  class test_class_(assert_dialog_result_tests) {
    auto test_method_(abort) {
      assert::are_equal(3, enum_object<>::to_int32(assert_dialog_result::abort));
      assert::are_equal("abort", enum_object<>::to_string(assert_dialog_result::abort));
      assert::are_equal(assert_dialog_result::abort, enum_object<>::parse<assert_dialog_result>("abort"));
    }
    
    auto test_method_(retry) {
      assert::are_equal(4, enum_object<>::to_int32(assert_dialog_result::retry));
      assert::are_equal("retry", enum_object<>::to_string(assert_dialog_result::retry));
      assert::are_equal(assert_dialog_result::retry, enum_object<>::parse<assert_dialog_result>("retry"));
    }
    
    auto test_method_(ignore) {
      assert::are_equal(5, enum_object<>::to_int32(assert_dialog_result::ignore));
      assert::are_equal("ignore", enum_object<>::to_string(assert_dialog_result::ignore));
      assert::are_equal(assert_dialog_result::ignore, enum_object<>::parse<assert_dialog_result>("ignore"));
    }
  };
}

#include <xtd/forms/dialog_result>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(dialog_result_tests) {
  public:
    auto test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(dialog_result::none));
      assert::are_equal("none", enum_object<>::to_string(dialog_result::none));
      assert::are_equal(dialog_result::none, enum_object<>::parse<dialog_result>("none"));
    }
    
    auto test_method_(ok) {
      assert::are_equal(1, enum_object<>::to_int32(dialog_result::ok));
      assert::are_equal("ok", enum_object<>::to_string(dialog_result::ok));
      assert::are_equal(dialog_result::ok, enum_object<>::parse<dialog_result>("ok"));
    }
    
    auto test_method_(cancel) {
      assert::are_equal(2, enum_object<>::to_int32(dialog_result::cancel));
      assert::are_equal("cancel", enum_object<>::to_string(dialog_result::cancel));
      assert::are_equal(dialog_result::cancel, enum_object<>::parse<dialog_result>("cancel"));
    }
    
    auto test_method_(abort) {
      assert::are_equal(3, enum_object<>::to_int32(dialog_result::abort));
      assert::are_equal("abort", enum_object<>::to_string(dialog_result::abort));
      assert::are_equal(dialog_result::abort, enum_object<>::parse<dialog_result>("abort"));
    }
    
    auto test_method_(retry) {
      assert::are_equal(4, enum_object<>::to_int32(dialog_result::retry));
      assert::are_equal("retry", enum_object<>::to_string(dialog_result::retry));
      assert::are_equal(dialog_result::retry, enum_object<>::parse<dialog_result>("retry"));
    }
    
    auto test_method_(ignore) {
      assert::are_equal(5, enum_object<>::to_int32(dialog_result::ignore));
      assert::are_equal("ignore", enum_object<>::to_string(dialog_result::ignore));
      assert::are_equal(dialog_result::ignore, enum_object<>::parse<dialog_result>("ignore"));
    }
    
    auto test_method_(yes) {
      assert::are_equal(6, enum_object<>::to_int32(dialog_result::yes));
      assert::are_equal("yes", enum_object<>::to_string(dialog_result::yes));
      assert::are_equal(dialog_result::yes, enum_object<>::parse<dialog_result>("yes"));
    }
    
    auto test_method_(no) {
      assert::are_equal(7, enum_object<>::to_int32(dialog_result::no));
      assert::are_equal("no", enum_object<>::to_string(dialog_result::no));
      assert::are_equal(dialog_result::no, enum_object<>::parse<dialog_result>("no"));
    }
  };
}

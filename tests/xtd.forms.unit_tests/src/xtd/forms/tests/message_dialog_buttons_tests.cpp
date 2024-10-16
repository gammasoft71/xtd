#include <xtd/forms/message_dialog_buttons>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(message_dialog_buttons_tests) {
  public:
    void test_method_(ok) {
      assert::are_equal(0, enum_object<>::to_int32(message_dialog_buttons::ok));
      assert::are_equal("ok", enum_object<>::to_string(message_dialog_buttons::ok));
      assert::are_equal(message_dialog_buttons::ok, enum_object<>::parse<message_dialog_buttons>("ok"));
    }
    
    void test_method_(ok_cancel) {
      assert::are_equal(1, enum_object<>::to_int32(message_dialog_buttons::ok_cancel));
      assert::are_equal("ok_cancel", enum_object<>::to_string(message_dialog_buttons::ok_cancel));
      assert::are_equal(message_dialog_buttons::ok_cancel, enum_object<>::parse<message_dialog_buttons>("ok_cancel"));
    }
    
    void test_method_(abort_retry_ignore) {
      assert::are_equal(2, enum_object<>::to_int32(message_dialog_buttons::abort_retry_ignore));
      assert::are_equal("abort_retry_ignore", enum_object<>::to_string(message_dialog_buttons::abort_retry_ignore));
      assert::are_equal(message_dialog_buttons::abort_retry_ignore, enum_object<>::parse<message_dialog_buttons>("abort_retry_ignore"));
    }
    
    void test_method_(yes_no_cancel) {
      assert::are_equal(3, enum_object<>::to_int32(message_dialog_buttons::yes_no_cancel));
      assert::are_equal("yes_no_cancel", enum_object<>::to_string(message_dialog_buttons::yes_no_cancel));
      assert::are_equal(message_dialog_buttons::yes_no_cancel, enum_object<>::parse<message_dialog_buttons>("yes_no_cancel"));
    }
    
    void test_method_(yes_no) {
      assert::are_equal(4, enum_object<>::to_int32(message_dialog_buttons::yes_no));
      assert::are_equal("yes_no", enum_object<>::to_string(message_dialog_buttons::yes_no));
      assert::are_equal(message_dialog_buttons::yes_no, enum_object<>::parse<message_dialog_buttons>("yes_no"));
    }
    
    void test_method_(retry_cancel) {
      assert::are_equal(5, enum_object<>::to_int32(message_dialog_buttons::retry_cancel));
      assert::are_equal("retry_cancel", enum_object<>::to_string(message_dialog_buttons::retry_cancel));
      assert::are_equal(message_dialog_buttons::retry_cancel, enum_object<>::parse<message_dialog_buttons>("retry_cancel"));
    }
  };
}

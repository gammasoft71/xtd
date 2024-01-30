#include <xtd/forms/message_dialog_default_button>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(message_dialog_default_button_tests) {
  public:
    void test_method_(button1) {
      assert::are_equal(0, enum_object<>::to_int32(message_dialog_default_button::button1), csf_);
      assert::are_equal("button1", enum_object<>::to_string(message_dialog_default_button::button1), csf_);
      assert::are_equal(message_dialog_default_button::button1, enum_object<>::parse<message_dialog_default_button>("button1"), csf_);
    }
    
    void test_method_(button2) {
      assert::are_equal(256, enum_object<>::to_int32(message_dialog_default_button::button2), csf_);
      assert::are_equal("button2", enum_object<>::to_string(message_dialog_default_button::button2), csf_);
      assert::are_equal(message_dialog_default_button::button2, enum_object<>::parse<message_dialog_default_button>("button2"), csf_);
    }
    
    void test_method_(button3) {
      assert::are_equal(512, enum_object<>::to_int32(message_dialog_default_button::button3), csf_);
      assert::are_equal("button3", enum_object<>::to_string(message_dialog_default_button::button3), csf_);
      assert::are_equal(message_dialog_default_button::button3, enum_object<>::parse<message_dialog_default_button>("button3"), csf_);
    }
  };
}

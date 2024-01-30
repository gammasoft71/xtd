#include <xtd/forms/message_dialog_icon>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(message_dialog_icon_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(message_dialog_icon::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(message_dialog_icon::none), csf_);
      assert::are_equal(message_dialog_icon::none, enum_object<>::parse<message_dialog_icon>("none"), csf_);
    }
    
    void test_method_(hand) {
      assert::are_equal(16, enum_object<>::to_int32(message_dialog_icon::hand), csf_);
      assert::are_equal("hand", enum_object<>::to_string(message_dialog_icon::hand), csf_);
      assert::are_equal(message_dialog_icon::hand, enum_object<>::parse<message_dialog_icon>("hand"), csf_);
    }
    
    void test_method_(stop) {
      assert::are_equal(16, enum_object<>::to_int32(message_dialog_icon::stop), csf_);
      assert::are_equal("hand", enum_object<>::to_string(message_dialog_icon::stop), csf_);
      assert::are_equal(message_dialog_icon::stop, enum_object<>::parse<message_dialog_icon>("hand"), csf_);
    }
    
    void test_method_(error) {
      assert::are_equal(16, enum_object<>::to_int32(message_dialog_icon::error), csf_);
      assert::are_equal("hand", enum_object<>::to_string(message_dialog_icon::error), csf_);
      assert::are_equal(message_dialog_icon::error, enum_object<>::parse<message_dialog_icon>("hand"), csf_);
    }
    
    void test_method_(question) {
      assert::are_equal(32, enum_object<>::to_int32(message_dialog_icon::question), csf_);
      assert::are_equal("question", enum_object<>::to_string(message_dialog_icon::question), csf_);
      assert::are_equal(message_dialog_icon::question, enum_object<>::parse<message_dialog_icon>("question"), csf_);
    }
    
    void test_method_(exclamation) {
      assert::are_equal(48, enum_object<>::to_int32(message_dialog_icon::exclamation), csf_);
      assert::are_equal("exclamation", enum_object<>::to_string(message_dialog_icon::exclamation), csf_);
      assert::are_equal(message_dialog_icon::exclamation, enum_object<>::parse<message_dialog_icon>("exclamation"), csf_);
    }
    
    void test_method_(warning) {
      assert::are_equal(48, enum_object<>::to_int32(message_dialog_icon::warning), csf_);
      assert::are_equal("exclamation", enum_object<>::to_string(message_dialog_icon::warning), csf_);
      assert::are_equal(message_dialog_icon::warning, enum_object<>::parse<message_dialog_icon>("exclamation"), csf_);
    }
    
    void test_method_(asterisk) {
      assert::are_equal(64, enum_object<>::to_int32(message_dialog_icon::asterisk), csf_);
      assert::are_equal("asterisk", enum_object<>::to_string(message_dialog_icon::asterisk), csf_);
      assert::are_equal(message_dialog_icon::asterisk, enum_object<>::parse<message_dialog_icon>("asterisk"), csf_);
    }
    
    void test_method_(information) {
      assert::are_equal(64, enum_object<>::to_int32(message_dialog_icon::information), csf_);
      assert::are_equal("asterisk", enum_object<>::to_string(message_dialog_icon::information), csf_);
      assert::are_equal(message_dialog_icon::information, enum_object<>::parse<message_dialog_icon>("asterisk"), csf_);
    }
  };
}

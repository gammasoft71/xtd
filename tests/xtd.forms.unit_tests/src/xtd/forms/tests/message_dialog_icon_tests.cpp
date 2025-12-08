#include <xtd/forms/message_dialog_icon>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(message_dialog_icon_tests) {
  public:
    auto test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(message_dialog_icon::none));
      assert::are_equal("none", enum_object<>::to_string(message_dialog_icon::none));
      assert::are_equal(message_dialog_icon::none, enum_object<>::parse<message_dialog_icon>("none"));
    }
    
    auto test_method_(error) {
      assert::are_equal(16, enum_object<>::to_int32(message_dialog_icon::error));
      assert::are_equal("error", enum_object<>::to_string(message_dialog_icon::error));
      assert::are_equal(message_dialog_icon::error, enum_object<>::parse<message_dialog_icon>("error"));
    }
    
    auto test_method_(question) {
      assert::are_equal(32, enum_object<>::to_int32(message_dialog_icon::question));
      assert::are_equal("question", enum_object<>::to_string(message_dialog_icon::question));
      assert::are_equal(message_dialog_icon::question, enum_object<>::parse<message_dialog_icon>("question"));
    }
    
    auto test_method_(warning) {
      assert::are_equal(48, enum_object<>::to_int32(message_dialog_icon::warning));
      assert::are_equal("warning", enum_object<>::to_string(message_dialog_icon::warning));
      assert::are_equal(message_dialog_icon::warning, enum_object<>::parse<message_dialog_icon>("warning"));
    }
    
    auto test_method_(information) {
      assert::are_equal(64, enum_object<>::to_int32(message_dialog_icon::information));
      assert::are_equal("information", enum_object<>::to_string(message_dialog_icon::information));
      assert::are_equal(message_dialog_icon::information, enum_object<>::parse<message_dialog_icon>("information"));
    }
    
    auto test_method_(hand) {
      assert::are_equal(16, enum_object<>::to_int32(message_dialog_icon::hand));
      assert::are_equal("error", enum_object<>::to_string(message_dialog_icon::hand));
      assert::are_equal(message_dialog_icon::hand, enum_object<>::parse<message_dialog_icon>("error"));
    }
    
    auto test_method_(stop) {
      assert::are_equal(16, enum_object<>::to_int32(message_dialog_icon::stop));
      assert::are_equal("error", enum_object<>::to_string(message_dialog_icon::stop));
      assert::are_equal(message_dialog_icon::stop, enum_object<>::parse<message_dialog_icon>("error"));
    }
    
    auto test_method_(exclamation) {
      assert::are_equal(48, enum_object<>::to_int32(message_dialog_icon::exclamation));
      assert::are_equal("warning", enum_object<>::to_string(message_dialog_icon::exclamation));
      assert::are_equal(message_dialog_icon::exclamation, enum_object<>::parse<message_dialog_icon>("warning"));
    }
    
    auto test_method_(asterisk) {
      assert::are_equal(64, enum_object<>::to_int32(message_dialog_icon::asterisk));
      assert::are_equal("information", enum_object<>::to_string(message_dialog_icon::asterisk));
      assert::are_equal(message_dialog_icon::asterisk, enum_object<>::parse<message_dialog_icon>("information"));
    }
  };
}

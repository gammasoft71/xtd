#include <xtd/forms/message_dialog_options>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(message_dialog_options_tests) {
  public:
    void test_method_(default_desktop_only) {
      assert::are_equal(131072, enum_object<>::to_int32(message_dialog_options::default_desktop_only), csf_);
      assert::are_equal("default_desktop_only", enum_object<>::to_string(message_dialog_options::default_desktop_only), csf_);
      assert::are_equal(message_dialog_options::default_desktop_only, enum_object<>::parse<message_dialog_options>("default_desktop_only"), csf_);
    }
    
    void test_method_(right_align) {
      assert::are_equal(524288, enum_object<>::to_int32(message_dialog_options::right_align), csf_);
      assert::are_equal("right_align", enum_object<>::to_string(message_dialog_options::right_align), csf_);
      assert::are_equal(message_dialog_options::right_align, enum_object<>::parse<message_dialog_options>("right_align"), csf_);
    }
    
    void test_method_(rtl_reading) {
      assert::are_equal(1048576, enum_object<>::to_int32(message_dialog_options::rtl_reading), csf_);
      assert::are_equal("rtl_reading", enum_object<>::to_string(message_dialog_options::rtl_reading), csf_);
      assert::are_equal(message_dialog_options::rtl_reading, enum_object<>::parse<message_dialog_options>("rtl_reading"), csf_);
    }
    
    void test_method_(service_notification) {
      assert::are_equal(2097152, enum_object<>::to_int32(message_dialog_options::service_notification), csf_);
      assert::are_equal("service_notification", enum_object<>::to_string(message_dialog_options::service_notification), csf_);
      assert::are_equal(message_dialog_options::service_notification, enum_object<>::parse<message_dialog_options>("service_notification"), csf_);
    }
  };
}


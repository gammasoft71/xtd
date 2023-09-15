#include <xtd/target_id>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(target_id_tests) {
  public:
    void test_method_(unknown) {
      assert::are_equal(0, enum_object<>::to_int32(target_id::unknown), csf_);
      assert::are_equal("unknown", enum_object<>::to_string(target_id::unknown), csf_);
      assert::are_equal(target_id::unknown, enum_object<>::parse<target_id>("unknown"), csf_);
    }
    
    void test_method_(console_application) {
      assert::are_equal(1, enum_object<>::to_int32(target_id::console_application), csf_);
      assert::are_equal("console_application", enum_object<>::to_string(target_id::console_application), csf_);
      assert::are_equal(target_id::console_application, enum_object<>::parse<target_id>("console_application"), csf_);
    }
    
    void test_method_(gui_application) {
      assert::are_equal(2, enum_object<>::to_int32(target_id::gui_application), csf_);
      assert::are_equal("gui_application", enum_object<>::to_string(target_id::gui_application), csf_);
      assert::are_equal(target_id::gui_application, enum_object<>::parse<target_id>("gui_application"), csf_);
    }
    
    void test_method_(test_application) {
      assert::are_equal(3, enum_object<>::to_int32(target_id::test_application), csf_);
      assert::are_equal("test_application", enum_object<>::to_string(target_id::test_application), csf_);
      assert::are_equal(target_id::test_application, enum_object<>::parse<target_id>("test_application"), csf_);
    }
    
    void test_method_(interface_library) {
      assert::are_equal(4, enum_object<>::to_int32(target_id::interface_library), csf_);
      assert::are_equal("interface_library", enum_object<>::to_string(target_id::interface_library), csf_);
      assert::are_equal(target_id::interface_library, enum_object<>::parse<target_id>("interface_library"), csf_);
    }
    
    void test_method_(module_library) {
      assert::are_equal(5, enum_object<>::to_int32(target_id::module_library), csf_);
      assert::are_equal("module_library", enum_object<>::to_string(target_id::module_library), csf_);
      assert::are_equal(target_id::module_library, enum_object<>::parse<target_id>("module_library"), csf_);
    }
    
    void test_method_(shared_library) {
      assert::are_equal(6, enum_object<>::to_int32(target_id::shared_library), csf_);
      assert::are_equal("shared_library", enum_object<>::to_string(target_id::shared_library), csf_);
      assert::are_equal(target_id::shared_library, enum_object<>::parse<target_id>("shared_library"), csf_);
    }
    
    void test_method_(static_library) {
      assert::are_equal(7, enum_object<>::to_int32(target_id::static_library), csf_);
      assert::are_equal("static_library", enum_object<>::to_string(target_id::static_library), csf_);
      assert::are_equal(target_id::static_library, enum_object<>::parse<target_id>("static_library"), csf_);
    }
    
    void test_method_(custom_target) {
      assert::are_equal(8, enum_object<>::to_int32(target_id::custom_target), csf_);
      assert::are_equal("custom_target", enum_object<>::to_string(target_id::custom_target), csf_);
      assert::are_equal(target_id::custom_target, enum_object<>::parse<target_id>("custom_target"), csf_);
    }
  };
}

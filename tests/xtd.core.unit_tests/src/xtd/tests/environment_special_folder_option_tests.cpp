#include <xtd/environment>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(envvironment_special_folder_option_tests) {
    auto test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(environment::special_folder_option::none));
      assert::are_equal("none", enum_object<>::to_string(environment::special_folder_option::none));
      assert::are_equal(environment::special_folder_option::none, enum_object<>::parse<environment::special_folder_option>("none"));
    }
    
    auto test_method_(do_not_verify) {
      assert::are_equal(16384, enum_object<>::to_int32(environment::special_folder_option::do_not_verify));
      assert::are_equal("do_not_verify", enum_object<>::to_string(environment::special_folder_option::do_not_verify));
      assert::are_equal(environment::special_folder_option::do_not_verify, enum_object<>::parse<environment::special_folder_option>("do_not_verify"));
    }
    
    auto test_method_(create) {
      assert::are_equal(32768, enum_object<>::to_int32(environment::special_folder_option::create));
      assert::are_equal("create", enum_object<>::to_string(environment::special_folder_option::create));
      assert::are_equal(environment::special_folder_option::create, enum_object<>::parse<environment::special_folder_option>("create"));
    }
  };
}

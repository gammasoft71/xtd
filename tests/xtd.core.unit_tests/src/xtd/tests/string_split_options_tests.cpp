#include <xtd/string_split_options>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(string_split_options_tests) {
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(string_split_options::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(string_split_options::none), csf_);
      assert::are_equal(string_split_options::none, enum_object<>::parse<string_split_options>("none"), csf_);
    }
    
    void test_method_(remove_empty_entries) {
      assert::are_equal(1, enum_object<>::to_int32(string_split_options::remove_empty_entries), csf_);
      assert::are_equal("remove_empty_entries", enum_object<>::to_string(string_split_options::remove_empty_entries), csf_);
      assert::are_equal(string_split_options::remove_empty_entries, enum_object<>::parse<string_split_options>("remove_empty_entries"), csf_);
    }
  };
}

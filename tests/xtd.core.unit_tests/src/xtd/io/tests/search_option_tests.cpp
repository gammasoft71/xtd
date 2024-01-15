#include <xtd/io/search_option>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(search_option_tests) {
    void test_method_(top_directory_only) {
      assert::are_equal(0, enum_object<>::to_int32(search_option::top_directory_only), csf_);
      assert::are_equal("top_directory_only", enum_object<>::to_string(search_option::top_directory_only), csf_);
      assert::are_equal(search_option::top_directory_only, enum_object<>::parse<search_option>("top_directory_only"), csf_);
    }
    
    void test_method_(all_directories) {
      assert::are_equal(1, enum_object<>::to_int32(search_option::all_directories), csf_);
      assert::are_equal("all_directories", enum_object<>::to_string(search_option::all_directories), csf_);
      assert::are_equal(search_option::all_directories, enum_object<>::parse<search_option>("all_directories"), csf_);
    }
  };
}

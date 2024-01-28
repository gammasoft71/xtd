#include <xtd/forms/size_type>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(size_type_tests) {
  public:
    void test_method_(auto_size) {
      assert::are_equal(0, enum_object<>::to_int32(size_type::auto_size), csf_);
      assert::are_equal("auto_size", enum_object<>::to_string(size_type::auto_size), csf_);
      assert::are_equal(size_type::auto_size, enum_object<>::parse<size_type>("auto_size"), csf_);
    }
    
    void test_method_(absolute) {
      assert::are_equal(1, enum_object<>::to_int32(size_type::absolute), csf_);
      assert::are_equal("absolute", enum_object<>::to_string(size_type::absolute), csf_);
      assert::are_equal(size_type::absolute, enum_object<>::parse<size_type>("absolute"), csf_);
    }
    
    void test_method_(percent) {
      assert::are_equal(2, enum_object<>::to_int32(size_type::percent), csf_);
      assert::are_equal("percent", enum_object<>::to_string(size_type::percent), csf_);
      assert::are_equal(size_type::percent, enum_object<>::parse<size_type>("percent"), csf_);
    }
  };
}

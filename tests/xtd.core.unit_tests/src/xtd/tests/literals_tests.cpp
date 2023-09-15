#include <xtd/literals>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(lietarls_tests) {
  public:
    void test_method_(operator_s_on_char_ptr) {
      auto s = "string"_s;
      assert::is_instance_of<ustring>(s);
      assert::are_equal("string", s, csf_);
    }
    
    void test_method_(operator_s_on_char8_t_ptr) {
      auto s = u8"string"_s;
      assert::is_instance_of<ustring>(s);
      assert::are_equal("string", s, csf_);
    }
    
    void test_method_(operator_sd_on_unsigned_long_long) {
      auto s = 42_sd;
      assert::is_instance_of<std::string>(s);
      assert::are_equal("42", s, csf_);
    }
  };
}
